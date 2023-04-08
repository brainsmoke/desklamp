
#include "config.h"

#include <avr/io.h>
#include <avr/interrupt.h>

#include "rtc.h"

#define LEAP_END (0)

/*
// perfect amortised 1000Hz interrupts synchonised to the RTC clock
// 1000Hz 125*33 == 4125, 125*33 - 29 == 4096 rtc ticks

#define LEAP_VAL   (32)
#define NORMAL_VAL (33)
#define PERIOD     (125)

const uint8_t leap_tick[] =
{
	0, 4, 8, 12, 17, 21, 25, 30, 34, 38, 43, 47, 51, 56, 60,
	64, 68, 73, 77, 81, 86, 90, 94, 99, 103, 107, 112, 116, 120,

	LEAP_END
};
*/

/*
// constant 1024Hz interrupt
//

#define LEAP_VAL   (32)
#define NORMAL_VAL (32)
#define PERIOD     (1)

const uint8_t leap_tick[] =
{
	0, LEAP_END
};
*/

#define LEAP_VAL   (546)
#define NORMAL_VAL (546)
#define PERIOD     (1)

const uint8_t leap_tick[] =
{
    0, LEAP_END
};

const uint8_t *cur_leap;
uint8_t cur_tick;

static void set_next_period(void)
{
	if ( *cur_leap == cur_tick )
	{
		RTC.PER = LEAP_VAL;
		cur_leap++;
	}
	else
	{
		RTC.PER = NORMAL_VAL;
	}
	cur_tick++;
	if ( cur_tick == PERIOD )
	{
		cur_tick = 0;
		cur_leap = leap_tick;
	}
}

void rtc_init(void)
{
	cur_tick = 0;
	cur_leap = leap_tick;
	set_next_period();

	/* configure clock */
//	_PROTECTED_WRITE(CLKCTRL_XOSC32KCTRLA, CLKCTRL_ENABLE_bm);
//	RTC.CLKSEL = RTC_CLKSEL_TOSC32K_gc;
	/* use internal 32 kHz clock instead (default) */

	/* configure RTC counter timer */
	RTC.INTCTRL = RTC_OVF_bm;
	RTC.CTRLA = RTC_PRESCALER_DIV1_gc | RTC_RTCEN_bm;

	/* configure programmable interrupt timer */
//	RTC.PITINTCTRL = RTC_PI_bm;
//	RTC.PITCTRLA = RTC_PERIOD_CYC256_gc | RTC_PITEN_bm; /* ~7.8ms intervals */
}

/* higher priority */
ISR(RTC_CNT_vect)
{
    rtc_tick();
	set_next_period();
    RTC.INTFLAGS |= RTC_OVF_bm;
}

/* lower priority */
//ISR(RTC_PIT_vect)
//{
//    pit_tick();
//	RTC.PITINTFLAGS |= RTC_PI_bm;
//}

