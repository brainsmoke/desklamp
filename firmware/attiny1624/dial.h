#ifndef DIAL_H
#define DIAL_H

#include <stdint.h>

typedef struct
{
	uint16_t min;
	uint16_t max;

} dial_limit_t;

/* run after adc_init() */
void dial_init(void);

void dial_poll(void);
uint16_t dial_get(uint8_t i); /* does not do new ADC reads */
void dial_get_limits(uint8_t i, dial_limit_t *limit);
void dial_set_limits(uint8_t i, dial_limit_t *limit);

#endif //DIAL_H

