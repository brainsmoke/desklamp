
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
#include "ani.h"
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
		read_limits(i, &lim);
		dial_set_limits(i, &lim);
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

void debug_print(void)
{
	print ("max brightness: ");
	print_u16(gamma_get_max());
	println("");

	print ("gamma: ");
	print_u32_fixed_point(gamma_get(), 1);
	println("");

	println ("");
	println ("dials:");
	uint8_t i;
	for (i=0; i<N_DIALS; i++)
	{
		dial_limit_t lim;
		dial_get_limits(i, &lim);
		print ("dial ");
		print_u16(i);
		print (": min= ");
		print_u16(lim.min);
		print (" max= ");
		print_u16(lim.max);
		print (" cur= ");
		print_u16(dial_get(i));
		print (" raw= ");
		print_u16(dial_get_raw(i));
//		print (" inv= ");
//		print_u32(dial_get_inv(i));
		println("");
	}

	for (i=0; i<N_LEDS; i++)
	{
		print ("led ");
		print_u16(i);
		print (": ");
		print_u16(ani_get_led(i));
		println("");
	}

	settings_t s;
	debug_read_settings(&s);
	print_hexbytes((uint8_t *)&s, sizeof(s));
	println("");
}

void rtc_tick(void)
{
	tick = 1;
}

void yield(void)
{
	dial_poll();
	uart_rx_poll();
}

int main(void)
{
	set_clock();
	settings_init();

	adc_init();
	dial_init();
	uart_init();

	load();

	ani_init();
	prot_init();

	sei();
	rtc_init();
	for (;;)
	{
		ani_next();

		while (!tick)
		{
			prot_poll();
			yield();
		}

		uint8_t i;
		for (i=0; i<N_LEDS; i++)
		{
			uint16_t v = gamma_translate(ani_get_led(i));
			yield();
			uart0_putchar(v&0xff);
			yield();
			uart0_putchar(v>>8);
		}

		tick=0;
	}
}

