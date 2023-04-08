
#include "config.h"

#include <avr/io.h>
#include <util/delay.h>

#include "adc.h"



static const struct
{
	int pin;
	PORT_t *port;
	register8_t *pinctl;
	int ain;

} adc_inputs[] =
{
#ifdef ADC_PIN_0
	[0] = { .pin = ADC_PIN_0, .port = &ADC_PORT_0, .pinctl = &ADC_PINCTRL_0, .ain = ADC_AIN_0 },
#endif
#ifdef ADC_PIN_1
	[1] = { .pin = ADC_PIN_1, .port = &ADC_PORT_1, .pinctl = &ADC_PINCTRL_1, .ain = ADC_AIN_1 },
#endif
#ifdef ADC_PIN_2
	[2] = { .pin = ADC_PIN_2, .port = &ADC_PORT_2, .pinctl = &ADC_PINCTRL_2, .ain = ADC_AIN_2 },
#endif
#ifdef ADC_PIN_3
	[3] = { .pin = ADC_PIN_3, .port = &ADC_PORT_3, .pinctl = &ADC_PINCTRL_3, .ain = ADC_AIN_3 },
#endif
#ifdef ADC_PIN_4
	[4] = { .pin = ADC_PIN_4, .port = &ADC_PORT_4, .pinctl = &ADC_PINCTRL_4, .ain = ADC_AIN_4 },
#endif
#ifdef ADC_PIN_5
	[5] = { .pin = ADC_PIN_5, .port = &ADC_PORT_5, .pinctl = &ADC_PINCTRL_5, .ain = ADC_AIN_5 },
#endif
#ifdef ADC_PIN_6
	[6] = { .pin = ADC_PIN_6, .port = &ADC_PORT_6, .pinctl = &ADC_PINCTRL_6, .ain = ADC_AIN_6 },
#endif
#ifdef ADC_PIN_7
	[7] = { .pin = ADC_PIN_7, .port = &ADC_PORT_7, .pinctl = &ADC_PINCTRL_7, .ain = ADC_AIN_7 },
#endif
#ifdef ADC_PIN_8
	[8] = { .pin = ADC_PIN_8, .port = &ADC_PORT_8, .pinctl = &ADC_PINCTRL_8, .ain = ADC_AIN_8 },
#endif
#ifdef ADC_PIN_9
	[9] = { .pin = ADC_PIN_9, .port = &ADC_PORT_9, .pinctl = &ADC_PINCTRL_9, .ain = ADC_AIN_9 },
#endif
#ifdef ADC_PIN_10
	[10] = { .pin = ADC_PIN_10, .port = &ADC_PORT_10, .pinctl = &ADC_PINCTRL_10, .ain = ADC_AIN_10 },
#endif
#ifdef ADC_PIN_11
	[11] = { .pin = ADC_PIN_11, .port = &ADC_PORT_11, .pinctl = &ADC_PINCTRL_11, .ain = ADC_AIN_11 },
#endif
#ifdef ADC_PIN_12
	[12] = { .pin = ADC_PIN_12, .port = &ADC_PORT_12, .pinctl = &ADC_PINCTRL_12, .ain = ADC_AIN_12 },
#endif
#ifdef ADC_PIN_13
	[13] = { .pin = ADC_PIN_13, .port = &ADC_PORT_13, .pinctl = &ADC_PINCTRL_13, .ain = ADC_AIN_13 },
#endif
#ifdef ADC_PIN_14
	[14] = { .pin = ADC_PIN_14, .port = &ADC_PORT_14, .pinctl = &ADC_PINCTRL_14, .ain = ADC_AIN_14 },
#endif
#ifdef ADC_PIN_15
	[15] = { .pin = ADC_PIN_15, .port = &ADC_PORT_15, .pinctl = &ADC_PINCTRL_15, .ain = ADC_AIN_15 },
#endif
};
#define N_INPUTS (sizeof(adc_inputs)/sizeof(adc_inputs[0]))

void adc_init(void)
{
	VREF.CTRLB |= VREF_ADC0REFEN_bm;

	int i;
	for (i=0; i<N_INPUTS; i++)
	{
		*adc_inputs[i].pinctl &=~ PORT_ISC_gm;
		*adc_inputs[i].pinctl |=  PORT_ISC_INPUT_DISABLE_gc;
		*adc_inputs[i].pinctl &=~ PORT_PULLUPEN_bm;
	}

	ADC0.CTRLB = ADC_PRESC_DIV4_gc;
	ADC0.CTRLC = ADC_REFSEL_1024MV_gc;
	ADC0.CTRLF = ADC_SAMPNUM_NONE_gc;
	//ADC0.CTRLF = ADC_SAMPNUM_ACC4_gc;

	ADC0.MUXPOS =  adc_inputs[0].ain;

	ADC0.CTRLA = ADC_ENABLE_bm;
}

void adc_start(int in)
{
	if (in < N_INPUTS)
		ADC0.MUXPOS = adc_inputs[in].ain;

//	_delay_us(25);
	ADC0.COMMAND = ADC_MODE_SINGLE_12BIT_gc | ADC_START_IMMEDIATE_gc;
}

uint8_t adc_ready(void)
{
	return !!(ADC0.INTFLAGS & ADC_RESRDY_bm);
}

uint16_t adc_get(void)
{
	while (! (ADC0.INTFLAGS & ADC_RESRDY_bm) );
	return ADC0.RESULT;
}


