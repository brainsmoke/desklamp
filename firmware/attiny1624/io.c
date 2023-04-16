
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


static const uint32_t pow10[10] = { 1000000000, 100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1 };

void print_u32(uint32_t value)
{
	uint32_t v;
	uint8_t i;
	char c;
	for (i = 0; i < 9; i++)
		if (value >= pow10[i])
			break;

	for (; i < 10; i++)
	{
		c = '0';
		v = pow10[i];
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

	uint32_t v;
	uint8_t i;
	char c;
	for (i = 0; i < 9-decimals; i++)
		if (value >= pow10[i])
			break;

	for (; i < 10; i++)
	{
		if (decimals == 10-i)
			uart_putchar('.');

		c = '0';
		v = pow10[i];
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

void print(const char *s)
{
	for ( ; *s ; s++ )
		uart_putchar(*s);
}

void println(const char *s)
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
	{
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
	}

	if (x > 255)
		return NULL;

	*n = x;
	return s;
}

uint8_t *parse_u16_as_percentage(uint8_t *s, uint16_t *n)
{
	uint32_t x;
	uint8_t d;

	if ( (d = *s-'0') > 9 )
		return NULL;

	x = d;
	s++;

	if ( (d = *s-'0') <= 9 )
	{
		if (x == 0)
			return NULL;

		x = x*10 + d;
		s++;

		if ( (d = *s-'0') <= 9 )
		{
			x = x*10 + d;
			s++;
		}
	}

	x *= 100;

	if ( *s == '.' )
	{
		s++;

		if ( (d = *s-'0') <= 9 )
		{
			x = x + d * 10;
			s++;

			if ( (d = *s-'0') <= 9 )
			{
				x = x + d;
				s++;

				if ( (d = *s-'5') <= 9-5 )
					x++;

				while ( (d = *s-'0') <= 9 )
				{
					if (x == 10000 && d < 0)
						return NULL;

					s++;
				}
			}
		}
	}

	if (x > 10000)
		return NULL;

	*n = x;

	return s;
}

uint8_t *parse_brightness(uint8_t *s, uint16_t *n)
{
	s = parse_u16_as_percentage(s, n);
/*

inv = int(0xffffffff/10000)
for i in range(10001):
    i16 = (inv*i)>>16
    irev = (((i16)*10000 + 0xffff )>>16) 
    if i != irev:
        print(i, irev, i16)

*/

	if (s)
		*n = (((uint32_t)*n)*429496)>>16;
	return s;
}

void print_brightness(uint16_t value)
{
	uint32_t percentage = ((uint32_t)value*10000+0xffff)>>16;
	print_u32_fixed_point(percentage, 2);
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
			s = parse_brightness(s, &n);
		}
	}
	else
		s = parse_brightness(s, &n);

	if (s)
	{
		*dial = d;
		*value = n;
	}
	return s;
}

