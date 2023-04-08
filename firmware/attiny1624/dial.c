
#include "config.h"

#include "dial.h"
#include "adc.h"

static uint16_t dial_acc[N_DIALS];
static uint16_t dial_min[N_DIALS];
static uint16_t dial_max[N_DIALS];
static uint32_t dial_inv[N_DIALS];

static uint32_t inverse(uint32_t v)
{
	return 0xffffffffUL/v;
}

static void dial_try_adjust(uint8_t i)
{
	if (dial_min[i] > dial_acc[i]+DIAL_DEADZONE)
	{
		dial_min[i] = dial_acc[i]+DIAL_DEADZONE;
		dial_inv[i] = inverse(dial_max[i]-dial_min[i]);
	}

	if (dial_max[i] < dial_acc[i]-DIAL_DEADZONE)
	{
		dial_max[i] = dial_acc[i]-DIAL_DEADZONE;
		dial_inv[i] = inverse(dial_max[i]-dial_min[i]);
	}
}

void dial_init(void)
{
	uint8_t i, j;
	for (i=0; i<N_DIALS; i++)
	{
		dial_limit_t lim = { .min = 0, .max = 65535 };
		dial_set_limits(i, &lim);

		uint16_t v=0;
		for (j=0; j<16; j++)
		{
			adc_start(i);
			v += adc_get();
		}
		dial_acc[i]=v;
		dial_try_adjust(i);
	}
}

void dial_poll(void)
{
	static uint8_t i = 0;

	adc_start(i);
	dial_acc[i] -= (dial_acc[i]>>4);
	dial_acc[i] += adc_get();
	dial_try_adjust(i);
	i++;
	if (i >= N_DIALS)
		i=0;
}

void dial_get_limits(uint8_t i, dial_limit_t *limit)
{
	if (i >= N_DIALS)
		return;

	limit->min = dial_min[i]-DIAL_DEADZONE;
	limit->max = dial_max[i]+DIAL_DEADZONE;
}

void dial_set_limits(uint8_t i, dial_limit_t *limit)
{
	if (i >= N_DIALS)
		return;

	dial_min[i] = limit->min+DIAL_DEADZONE;
	dial_max[i] = limit->max-DIAL_DEADZONE;
	dial_inv[i] = inverse(dial_max[i]-dial_min[i]);

	dial_try_adjust(i);
}

uint16_t dial_get(uint8_t i)
{
	if (i >= N_DIALS)
		return 0;

	uint16_t v = dial_acc[i];

	if (v > dial_max[i])
		v = dial_max[i];

	if (v < dial_min[i])
		v = 0;
	else
		v -= dial_min[i];

	return (v * dial_inv[i]) >> 16;
}

