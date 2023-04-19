#ifndef SETTINGS_H
#define SETTINGS_H

#include <stdint.h>

#include "config.h"
#include "dial.h"
#include "ani.h"

#define EEPROM_VERSION (1)

typedef struct __attribute__((packed))
{
	uint32_t magic;
	uint8_t version;
	uint8_t gamma_dec;
	uint16_t max_brightness;

	ledconfig_t presets[N_PRESETS];
	
	dial_limit_t limits[N_DIALS];

} settings_t;

uint8_t read_version(void);
void write_version(uint8_t version);

uint32_t read_magic(void);
void write_magic(uint32_t magic);

uint16_t read_max_brightness(void);
void write_max_brightness(uint16_t brightness);

uint8_t read_gamma_dec(void);
void write_gamma_dec(uint8_t gamma_dec);

void read_limits(uint8_t n, dial_limit_t* limit);
void write_limits(uint8_t n, const dial_limit_t* limit);

void factory_reset(void);
void settings_init(void);

void read_preset(uint8_t n, ledconfig_t *p);
void write_preset(uint8_t n, const ledconfig_t *p);

void debug_read_settings(settings_t *s);

#endif //SETTINGS_H
