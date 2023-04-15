
#include <stdlib.h>
#include <string.h>

#include "config.h"

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

void print_u32_fixed_point(uint32_t value, uint8_t decimals)
{
	if (decimals > 9)
		println("error: print_u32_fixed_point, bad point");

	const uint32_t a[10] = { 1000000000, 100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1 };
	uint32_t v;
	uint8_t i;
	char c;
	for (i = 0; i < 9-decimals; i++)
		if (value >= a[i])
			break;

	for (; i < 10; i++)
	{
		if (decimals == 10-i)
			uart_putchar('.');

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
	if ( !( *s >= '0' && *s <= '9' ) )
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

uint8_t *parse_u8_one_decimal(uint8_t *s, uint8_t *n)
{
	uint16_t x;

	if ( !( *s >= '0' && *s <= '9' ) )
		return NULL;

	x = (*s - '0')*10;
	s++;

	if ( *s >= '0' && *s <= '9' )
	{
		x = (x + *s - '0' ) * 10;
		s++;
	}
	if ( *s >= '0' && *s <= '9' )
	{
		x = (x + *s - '0' ) * 10;
		s++;
	}
	if ( *s == '.' )
		s++;
	if ( *s >= '0' && *s <= '9' )
	{
		x = x + *s - '0';
		s++;
	}
	if ( *s >= '5' && *s <= '9' )
		x++;

	while ( *s >= '0' && *s <= '9' )
		s++;

	if (x > 255)
		return NULL;

	*n = x;
	return s;
}

uint8_t *parse_led_config(uint8_t *s, uint8_t *dial, uint16_t *value)
{
	uint8_t d = NO_DIAL;
	uint16_t n = 65535;
	if ( strncmp((char *)s, "dial", 4) == 0 )
	{
		s += 4;
		if (*s >= '0' && *s <= '2')
			d = *s - '0';
		else
			return NULL;

		s++;

		if (*s == ':' || *s == '*')
		{
			s++;
			s = parse_u16(s, &n);
		}
	}
	else
		s = parse_u16(s, &n);

	if (s)
	{
		*dial = d;
		*value = n;
	}
	return s;
}

