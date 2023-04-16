#include "io.h"

#include <stdio.h>

void uart_init(void);

uint8_t uart0_rx_ready(void) { return 0; }
uint8_t uart0_rx_get(void) { return 0; }
uint8_t uart0_tx_ready(void) { return 0; }
void uart0_tx_flush(void) {}
void uart0_putchar(int c) { putchar(c); }
int uart0_getchar(void) { return -1; }

uint8_t uart1_rx_ready(void) { return 0; }
uint8_t uart1_rx_get(void) { return 0; }
uint8_t uart1_tx_ready(void) { return 0; }
void uart1_tx_flush(void) {}
void uart1_putchar(int c) { putchar(c); }
int uart1_getchar(void) { return -1; }

void uart_rx_poll(void) {}

int main(int argc, char *argv[])
{
	uint8_t buf[100];
	uint32_t v;
	for (v=0; v<65536; v++)
	{
		sprintf((char *)buf, "%d.%02d", v/100, v%100);
		uint16_t n;
		if (parse_brightness(buf, &n))
		{
			printf("%s %d ", buf, n);
			print_brightness(n);
			printf("\n");
		}
		else
			printf("%s nope\n", buf);

		
	}
}

