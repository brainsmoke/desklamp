#ifndef ANI_H
#define ANI_H

#include <stdint.h>

#include "config.h"

typedef struct
{
	uint16_t brightness[N_LEDS];
	uint8_t dial[N_LEDS];

} ledconfig_t;

uint16_t ani_get_led(uint8_t i);

void ani_next(void);

void ani_add(const ledconfig_t *p, uint16_t frames);

void ani_on(uint16_t frames);
void ani_off(uint16_t frames);

void ani_init(void);

void ani_blink(void);

void ani_get_frame_top(ledconfig_t *p); /* last frame on the queue, to restor after a notification */

extern const ledconfig_t preset_restore[N_PRESETS];
extern const ledconfig_t preset_off;

#endif //ANI_H
