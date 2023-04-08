
#include "config.h"

#include "settings.h"
#include "io.h"

#include <avr/eeprom.h>

EEMEM settings_t settings;

uint8_t read_version(void)
{
	return eeprom_read_byte(&settings.version);
}

void write_version(uint8_t version)
{
	eeprom_write_byte(&settings.version, version);
}

uint32_t read_magic(void)
{
	return eeprom_read_dword(&settings.magic);
}

void write_magic(uint32_t magic)
{
	eeprom_write_dword(&settings.magic, magic);
}

uint16_t read_max_brightness(void)
{
	return eeprom_read_word(&settings.max_brightness);
}

void write_max_brightness(uint16_t brightness)
{
	if (brightness != read_max_brightness())
		eeprom_write_word(&settings.max_brightness, brightness);
}

uint8_t read_gamma_dec(void)
{
	return eeprom_read_byte(&settings.gamma_dec);
}

void write_gamma_dec(uint8_t gamma_dec)
{
	eeprom_write_byte(&settings.gamma_dec, gamma_dec);
}

void read_limits(uint8_t n, dial_limit_t* limit)
{
	if (n >= N_DIALS)
		return;

	limit->min = eeprom_read_word(&settings.limits[n].min);
	limit->max = eeprom_read_word(&settings.limits[n].max);
}

void write_limits(uint8_t n, dial_limit_t* limit)
{
	if (n >= N_DIALS)
		return;

	if (limit->min != eeprom_read_word(&settings.limits[n].min))
		eeprom_write_word(&settings.limits[n].min, limit->min);

	if (limit->max != eeprom_read_word(&settings.limits[n].max))
		eeprom_write_word(&settings.limits[n].max, limit->max);
}

void settings_init(void)
{
	if ( read_magic() != EEPROM_MAGIC || read_version() < EEPROM_VERSION)
		factory_reset();
}

void debug_read_settings(settings_t *s)
{
	eeprom_read_block(s, &settings, sizeof(settings_t));
}
