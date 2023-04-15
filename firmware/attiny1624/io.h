#ifndef IO_H
#define IO_H

#include <stdint.h>

void print_u16(uint16_t value);
void print_u32(uint32_t value);
void print_u32_fixed_point(uint32_t value, uint8_t decimals);
void print_hexbytes(uint8_t *bytes, int len);
void print(char *s);
void println(char *s);
void flush(void);

uint8_t *parse_u16(uint8_t *s, uint16_t *n);
uint8_t *parse_u8_one_decimal(uint8_t *s, uint8_t *n);

uint8_t *parse_led_config(uint8_t *s, uint8_t *dial, uint16_t *value);

#endif //IO_H

