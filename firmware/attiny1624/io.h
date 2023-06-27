#ifndef IO_H
#define IO_H

#include <stdint.h>

#include "ani.h"

void print_u16(uint16_t value);
void print_u32(uint32_t value);
void print_u32_fixed_point(uint32_t value, uint8_t decimals);
void print_hexbytes(uint8_t *bytes, int len);
void print(const char *s);
void println(const char *s);
void flush(void);

uint8_t *parse_u16(uint8_t *s, uint16_t *n);
uint8_t *parse_u8_one_decimal(uint8_t *s, uint8_t *n);

uint8_t *parse_u16_as_percentage(uint8_t *s, uint16_t *n); /* two decimals */

uint8_t *parse_u16_fixed_point(uint8_t *s, uint8_t decimals, uint16_t *n);

uint8_t *parse_timeout(uint8_t *s, uint16_t *n, uint16_t max);

uint8_t *parse_brightness(uint8_t *s, uint16_t *n);
void print_brightness(uint16_t value);

uint8_t *parse_single_led_config(uint8_t *s, uint8_t *dial, uint16_t *value);
void print_single_led_config(uint8_t dial, uint16_t value);

uint8_t *parse_led_config(uint8_t *s, ledconfig_t *config);
void print_led_config(ledconfig_t *config);

#endif //IO_H

