
#include "config.h"

#include <avr/io.h>

#include "uart.h"

#if USART0_RX_BUF_SZ > 255
#error "USART0_RX_BUF_SZ too big"
#endif

#if USART1_RX_BUF_SZ > 255
#error "USART1_RX_BUF_SZ too big"
#endif

static uint8_t usart0_rx[USART0_RX_BUF_SZ];
static uint8_t usart1_rx[USART1_RX_BUF_SZ];
static uint8_t usart0_rx_off, usart0_rx_len;
static uint8_t usart1_rx_off, usart1_rx_len;

void uart_init(void)
{
	PORTMUX.USARTROUTEA |= USART0_PORTMUX | USART1_PORTMUX;

	USART0_TX_PORT.OUTSET |= _BV(USART0_TX_PIN);
	USART0_TX_PORT.DIRSET |= _BV(USART0_TX_PIN);

	USART0.BAUD = USART0_BAUD_REG;
	USART0.CTRLC = USART_CMODE_ASYNCHRONOUS_gc | USART_PMODE_DISABLED_gc | USART_SBMODE_1BIT_gc | USART_CHSIZE_8BIT_gc;
	USART0.CTRLA = 0;
	USART0.CTRLB = USART_RXEN_bm | USART_TXEN_bm | USART_RXMODE_NORMAL_gc;
	usart0_rx_off = usart0_rx_len = 0;


	USART1_TX_PORT.OUTSET |= _BV(USART1_TX_PIN);
	USART1_TX_PORT.DIRSET |= _BV(USART1_TX_PIN);

	USART1.BAUD = USART1_BAUD_REG;
	USART1.CTRLC = USART_CMODE_ASYNCHRONOUS_gc | USART_PMODE_DISABLED_gc | USART_SBMODE_1BIT_gc | USART_CHSIZE_8BIT_gc;
	USART1.CTRLA = 0;
	USART1.CTRLB = USART_RXEN_bm | USART_TXEN_bm | USART_RXMODE_NORMAL_gc;
	usart1_rx_off = usart1_rx_len = 0;
}

void uart_rx_poll(void)
{
	if ( (USART0.STATUS & USART_RXCIF_bm) && (usart0_rx_len < USART0_RX_BUF_SZ) )
	{
		uint16_t off = usart0_rx_off + usart0_rx_len;

		if (off >= USART0_RX_BUF_SZ)
			off -= USART0_RX_BUF_SZ;

		usart0_rx[off] = USART0.RXDATAL;
		usart0_rx_len++;
	}

	if ( (USART1.STATUS & USART_RXCIF_bm) && (usart1_rx_len < USART1_RX_BUF_SZ) )
	{
		uint16_t off = usart1_rx_off + usart1_rx_len;

		if (off >= USART1_RX_BUF_SZ)
			off -= USART1_RX_BUF_SZ;

		usart1_rx[off] = USART1.RXDATAL;
		usart1_rx_len++;
	}
}

uint8_t uart0_tx_ready(void)
{
	return !!(USART0.STATUS & USART_DREIF_bm);
}

void uart0_tx_flush(void)
{
	while (! (USART0.STATUS & USART_TXCIF_bm) );
}

void uart0_putchar(int c)
{
	while (! (USART0.STATUS & USART_DREIF_bm) )
		uart_rx_poll();
	USART0.TXDATAL = c;
}

uint8_t uart0_rx_ready(void)
{
	uart_rx_poll();
	return !!usart0_rx_len;
}

int uart0_getchar(void)
{
	uart_rx_poll();
	if (!usart0_rx_len)
		return -1;

	uint8_t res = usart0_rx[usart0_rx_off++];

	if ( usart0_rx_off == USART0_RX_BUF_SZ)
		usart0_rx_off = 0;

	usart0_rx_len--;
	return res;
}

uint8_t uart1_tx_ready(void)
{
	return !!(USART1.STATUS & USART_DREIF_bm);
}

void uart1_tx_flush(void)
{
	while (! (USART1.STATUS & USART_TXCIF_bm) );
}

void uart1_putchar(int c)
{
	while (! (USART1.STATUS & USART_DREIF_bm) )
		uart_rx_poll();

	USART1.TXDATAL = c;
}

uint8_t uart1_rx_ready(void)
{
	uart_rx_poll();
	return !!usart1_rx_len;
}

int uart1_getchar(void)
{
	uart_rx_poll();
	if (!usart1_rx_len)
		return -1;

	uint8_t res = usart1_rx[usart1_rx_off++];

	if ( usart1_rx_off == USART1_RX_BUF_SZ)
		usart1_rx_off = 0;

	usart1_rx_len--;
	return res;
}

