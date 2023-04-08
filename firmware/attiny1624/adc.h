#ifndef ADC_H
#define ADC_H

#include <stdint.h>

void adc_init(void);

void adc_start(int in);
uint8_t adc_ready(void);

uint16_t adc_get(void);

#endif //ADC_H
