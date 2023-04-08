
#include "config.h"

#include <avr/io.h>

#include <util/delay.h>

#include "system.h"

void set_clock(void)
{
	_PROTECTED_WRITE(CLKCTRL_MCLKCTRLB, F_CPU_BITS);
	_delay_ms(1);
}

void reset(void)
{
	_delay_ms(1);
	_PROTECTED_WRITE(RSTCTRL_SWRR, RSTCTRL_SWRE_bm);
}

