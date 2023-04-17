
#include <stdint.h>

#include "config.h"
#include "ani.h"
#include "dial.h"
#include "firmware.h"

static const uint16_t sigmoid_table[33] = {
/*
from math import cos, pi
print (', '.join( '{:d}'.format(int( (1-cos(i*pi/32)) * (0x8000+.5) )&0xffff) for i in range(33) ))
*/
0, 157, 629, 1411, 2494, 3869, 5522, 7438, 9597, 11980, 14563, 17321, 20228, 23256, 26375, 29556, 32768, 35980, 39161, 42280, 45308, 48215, 50973, 53556, 55939, 58098, 60014, 61667, 63042, 64125, 64907, 65379, 1
};

uint32_t sigmoid(uint16_t v)
{
	uint8_t ix = v>>11;
	uint16_t diff = sigmoid_table[ix+1] - sigmoid_table[ix];
	uint32_t res = v&0x7ff;

	res *= diff;
	res >>= 11;
	res += sigmoid_table[ix];

	return res;
}

static uint16_t ani_leds[N_LEDS];

#if ANIMATION_QUEUE_SIZE > 255
#error "ANIMATION_QUEUE_SIZE too big"
#endif

static uint8_t ani_last, ani_cur, ani_size;
static uint16_t ani_time;

typedef struct
{
	preset_t p;
	uint16_t t;
	uint32_t inv;

} ani_queue_t;

static ani_queue_t ani_queue[ANIMATION_QUEUE_SIZE];

uint16_t ani_get_led(uint8_t i)
{
	if (i >= N_LEDS)	
		return 0;

	return ani_leds[i];
}

static uint16_t ani_preset_get_led(const preset_t *p, uint8_t i)
{
	// internal function, forgo bound check
	uint16_t b = p->brightness[i];

	if ( p->config[i] == NO_DIAL )
		return b;

	uint32_t v = dial_get(p->config[i]);
	v += 1;
	v *= b;
	return v>>16;
}

void ani_next(void)
{
	if ( (ani_time >= ani_queue[ani_cur].t) && (ani_size > 2) )
	{
		ani_last = ani_cur;
		if (ani_cur < ANIMATION_QUEUE_SIZE-1)
			ani_cur += 1;
		else
			ani_cur = 0;

		ani_time = 0;
		ani_size --;
	}

	uint32_t interp = sigmoid( ( ani_time * ani_queue[ani_cur].inv ) >> 16 );

	yield();

	uint8_t i;
	for (i=0; i<N_LEDS; i++)
	{
		uint16_t a = ani_preset_get_led(&ani_queue[ani_last].p, i);
		uint32_t diff = ani_preset_get_led(&ani_queue[ani_cur].p, i);
		diff -= a;
		diff *= interp;
		ani_leds[i] = a + (diff>>16);
		yield();
	}

	if (ani_time < ani_queue[ani_cur].t)
		ani_time++;
}

void ani_add(const preset_t *p, uint16_t frames)
{
	/* in case of an overflow, just overwrite the last */
	if (ani_size >= ANIMATION_QUEUE_SIZE)
		ani_size = ANIMATION_QUEUE_SIZE - 1;

	int i = ani_last + ani_size;
	if (i >= ANIMATION_QUEUE_SIZE)
		i -= ANIMATION_QUEUE_SIZE;

	if (frames == 0)
		frames = 1;

	ani_queue[i] = (ani_queue_t)
	{
		.p = *p,
		.t = frames,
		.inv = 0xffffffffUL/frames,
	};

	ani_size++;
}

void ani_get_preset_top(preset_t *p) /* last preset on the queue, to restor after a notification */
{
	int i = ani_last + ani_size - 1;
	if (i >= ANIMATION_QUEUE_SIZE)
		i -= ANIMATION_QUEUE_SIZE;

	*p = ani_queue[i].p;
}

void ani_blink(void)
{
	preset_t p;
	ani_get_preset_top(&p);
	ani_add(&preset_off, 30);
	ani_add(&preset_blink_on, 30);
	ani_add(&preset_off, 30);
	ani_add(&preset_blink_on, 30);
	ani_add(&preset_off, 30);
	ani_add(&preset_blink_on, 30);
	ani_add(&preset_off, 30);
	ani_add(&p, 120);
}


void ani_init(void)
{
	ani_last = 0, ani_cur = 1, ani_size = 0, ani_time = 0;
	ani_add(&preset_off, 1);
	ani_add(&preset_default, 120);
}

