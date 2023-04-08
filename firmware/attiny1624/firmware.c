
#include "config.h"

#include <avr/io.h>
#include <avr/interrupt.h>

#include "uart.h"
#include "adc.h"
#include "dial.h"
#include "rtc.h"
#include "gamma.h"
#include "io.h"
#include "prot.h"
#include "system.h"
#include "settings.h"

volatile uint8_t tick=0;

void save(void)
{
	write_max_brightness(gamma_get_max());
	write_gamma_dec(gamma_get());

	uint8_t i;
	for (i=0; i<N_DIALS; i++)
	{
		dial_limit_t lim;
		dial_get_limits(i, &lim);
		write_limits(i, &lim);
	}
}


void load(void)
{
	gamma_set_max(read_max_brightness());
	gamma_set(read_gamma_dec());

	uint8_t i;
	for (i=0; i<N_DIALS; i++)
	{
		dial_limit_t lim;
		dial_get_limits(i, &lim);
		write_limits(i, &lim);
	}
}


void factory_reset(void)
{
	write_magic(EEPROM_MAGIC);
	write_version(EEPROM_VERSION);

	write_max_brightness(DEFAULT_MAX_BRIGHTNESS);
	write_gamma_dec(DEFAULT_GAMMA_DEC);

	dial_limit_t lim;
	lim.min = DIAL_MIN_DEFAULT+DIAL_DEADZONE;
	lim.max = DIAL_MAX_DEFAULT-DIAL_DEADZONE;

	uint8_t i;
	for (i=0; i<N_DIALS; i++)
		write_limits(i, &lim);

	flush();
	reset();
}


void rtc_tick(void)
{
	tick = 1;
}

int main(void)
{
	set_clock();
	settings_init();

	adc_init();
	dial_init();
	uart_init();
	rtc_init();

	load();

	for (;;)
	{
		prot_poll();
		dial_poll();
		if (tick)
		{
			tick=0;
			uint8_t i;
			for (i=0; i<N_LEDS; i++)
			{
				uint16_t v = gamma_translate(dial_get(i));
				uart0_putchar(v&0xff);
				uart0_putchar(v>>8);
			}
		}
	}
}

