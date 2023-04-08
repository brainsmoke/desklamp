#ifndef GAMMA_H
#define GAMMA_H

#include <stdint.h>

#define GAMMA_MIN (10)
#define GAMMA_DEFAULT (20)
#define GAMMA_MAX (55)

void gamma_set(uint8_t gamma_dec); /* gamma = gamma_dec/10 */
uint8_t gamma_get(void);

void gamma_set_max(uint16_t max);
uint16_t gamma_get_max(void);
uint16_t gamma_translate(uint16_t v);

#endif //GAMMA_H
