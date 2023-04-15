#ifndef ANI_H
#define ANI_H

#include <stdint.h>

#include "config.h"
#include "preset.h"

uint16_t ani_get_led(uint8_t i);

void ani_next(void);

void ani_add(const preset_t *p, uint16_t frames);

void ani_init(void);

void ani_blink(void);

void ani_get_preset_top(preset_t *p); /* last preset on the queue, to restor after a notification */

#endif //ANI_H
