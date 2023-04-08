#ifndef UART_H
#define UART_H

#include <stdint.h>

void uart_init(void);

uint8_t uart0_rx_ready(void);
uint8_t uart0_rx_get(void);
uint8_t uart0_tx_ready(void);
void uart0_tx_flush(void);
void uart0_putchar(int c);
int uart0_getchar(void);

uint8_t uart1_rx_ready(void);
uint8_t uart1_rx_get(void);
uint8_t uart1_tx_ready(void);
void uart1_tx_flush(void);
void uart1_putchar(int c);
int uart1_getchar(void);

void uart_rx_poll(void);

#define uart_rx_ready uart1_rx_ready
#define uart_rx_get uart1_rx_get
#define uart_tx_ready uart1_tx_ready
#define uart_tx_flush uart1_tx_flush
#define uart_putchar uart1_putchar
#define uart_getchar uart1_getchar

#endif //UART_H
