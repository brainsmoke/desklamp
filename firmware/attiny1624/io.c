
#include <stdlib.h>

#include "io.h"
#include "uart.h"

void print_u16(uint16_t value)
{
	const uint16_t a[5] = { 10000, 1000, 100, 10, 1 };
	uint16_t v;
	uint8_t i;
	char c;
	for (i = 0; i < 4; i++)
		if (value >= a[i])
			break;

	for (; i < 5; i++)
	{
		c = '0';
		v = a[i];
		while (value >= v)
		{
			c++;
			value -= v;
		}
		uart_putchar(c);
	}	
}


void print_u32(uint32_t value)
{
	const uint32_t a[10] = { 1000000000, 100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1 };
	uint32_t v;
	uint8_t i;
	char c;
	for (i = 0; i < 9; i++)
		if (value >= a[i])
			break;

	for (; i < 10; i++)
	{
		c = '0';
		v = a[i];
		while (value >= v)
		{
			c++;
			value -= v;
		}
		uart_putchar(c);
	}	
}

static const uint8_t *hex=(uint8_t *)"0123456789abcdef";

void print_hexbytes(uint8_t *bytes, int len)
{
	int i;
	uart_putchar('[');
	uart_putchar(' ');
	for (i=0; i<len; i++)
	{
		uart_putchar(hex[bytes[i]>>4]);
		uart_putchar(hex[bytes[i]&0xf]);
		uart_putchar(' ');
	}
	uart_putchar(']');
}

void print(char *s)
{
	for ( ; *s ; s++ )
		uart_putchar(*s);
}

void println(char *s)
{
	print(s);
	print("\r\n");
}

void flush(void)
{
	uart_tx_flush();
}


uint8_t *parse_u16(uint8_t *s, uint16_t *n)
{
	uint16_t x = 0;
	if (*s=='\0')
		return NULL;

	while ( *s >= '0' && *s <= '9' )
	{
		if (x > 6553 || ( x == 6553 && *s > '5' ) )
			return NULL;

		x *= 10;
		x += *s-'0';
		s++;
	}

	*n = x;

	return s;
}

