#ifndef IO_H
#define IO_H

#include <stdint.h>

void print_u16(uint16_t value);
void print_hexbytes(uint8_t *bytes, int len);
void print(char *s);
void flush(void);

uint8_t *parse_u16(uint8_t *s, uint16_t *n);

#endif //IO_H

