
#include <stdint.h>

#include "config.h"
#include "ani.h"
#include "dial.h"
#include "firmware.h"

static uint16_t ani_leds[N_LEDS];

static uint16_t ani_offset, ani_size;
static uint16_t ani_time;

static const uint16_t sigmoid_table[33] = {
/*
from math import cos, pi
print (', '.join( '{:d}'.format(int( (1-cos(i*pi/32)) * (0x8000+.5) )&0xffff) for i in range(33) ))
*/
0, 157, 629, 1411, 2494, 3869, 5522, 7438, 9597, 11980, 14563, 17321, 20228, 23256, 26375, 29556, 32768, 35980, 39161, 42280, 45308, 48215, 50973, 53556, 55939, 58098, 60014, 61667, 63042, 64125, 64907, 65379, 1
};

#include "io.h"
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

static const preset_t *ani_last = &preset_off;

typedef struct
{
	const preset_t *p;
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
	uint32_t v =  p->brightness[i];

	if ( p->config[i] != NO_DIAL )
	{
		v *= dial_get(p->config[i]);
		v += 1;
		v += (v>>16);
		v >>= 16;
	}

	return v;
}

void ani_next(void)
{
	if ( (ani_time >= ani_queue[ani_offset].t) && (ani_size > 1) )
	{
		ani_last = ani_queue[ani_offset].p;

		ani_time = 0;
		ani_offset ++;
		ani_size --;
		if (ani_offset >= ANIMATION_QUEUE_SIZE)
			ani_offset = 0;
	}

	uint32_t interp = sigmoid( ( ani_time * ani_queue[ani_offset].inv ) >> 16 );

	yield();

	uint8_t i;
	for (i=0; i<N_LEDS; i++)
	{
		uint16_t a = ani_preset_get_led(ani_last, i);
		uint32_t diff = ani_preset_get_led(ani_queue[ani_offset].p, i);
		diff -= a;
		diff *= interp;
		ani_leds[i] = a + (diff>>16);
		yield();
	}

	if (ani_time < ani_queue[ani_offset].t)
		ani_time++;
}

void ani_add(const preset_t *p, uint16_t frames)
{
	/* in case of an overflow, just overwrite the last */
	if (ani_size >= ANIMATION_QUEUE_SIZE)
		ani_size = ANIMATION_QUEUE_SIZE - 1;

	int i = ani_offset + ani_size;
	if (i >= ANIMATION_QUEUE_SIZE)
		i -= ANIMATION_QUEUE_SIZE;

	if (frames == 0)
		frames = 1;

	ani_queue[i] = (ani_queue_t)
	{
		.p = p,
		.t = frames,
		.inv = 0xffffffffUL/frames,
	};

	ani_size++;
}

const preset_t *ani_preset_top(void) /* last preset on the queue, to restor after a notification */
{
	int i = ani_offset + ani_size - 1;
	if (i >= ANIMATION_QUEUE_SIZE)
		i -= ANIMATION_QUEUE_SIZE;

	return ani_queue[i].p;
}

void ani_blink(void)
{
	const preset_t *p = ani_preset_top();
	ani_add(&preset_off, 30);
	ani_add(&preset_blink_on, 30);
	ani_add(&preset_off, 30);
	ani_add(&preset_blink_on, 30);
	ani_add(&preset_off, 30);
	ani_add(&preset_blink_on, 30);
	ani_add(&preset_off, 30);
	ani_add(p, 120);
}


void ani_init(void)
{
	ani_offset = ani_size = 0, ani_time = 0;
	ani_add(&preset_default, 120);
}

