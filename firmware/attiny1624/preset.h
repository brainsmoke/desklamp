#ifndef PRESET_H
#define PRESET_H

#include <stdint.h>

#include "config.h"

typedef struct
{
	uint16_t brightness[N_LEDS];
	uint8_t dial[N_LEDS];

} preset_t;

extern const preset_t preset_off;
extern const preset_t preset_blink_on;
extern const preset_t preset_default;

#endif //PRESET_H
