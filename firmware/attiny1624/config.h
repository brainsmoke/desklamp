#ifndef CONFIG_H
#define CONFIG_H

#define F_CPU 10000000UL
#define F_CPU_BITS (CLKCTRL_PEN_bm) /* has to match with the bits for F_CPU */

#define EEPROM_MAGIC (0x504d414c)

#define N_DIALS       3
#define DIAL_WHITE             0
#define DIAL_WARM_WHITE        1
#define DIAL_EXTRA_WARM_WHITE  2
#define NO_DIAL                3
#define STR_DIAL_RANGE        "dial{0,1,2}"


#define N_LEDS         9
#define STR_N_LEDS    "9"
#define STR_LED_RANGE "{0..8}"

#define STR_BRIGHTNESS_RANGE "0.00-100.00"

#define LED_ALL_OFF 0,0,0, 0,0,0, 0,0,0
#define LED_ALL_MAX 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff

#define LED_BLINK 0xffff, 0, 0, 0xffff, 0, 0, 0xffff, 0, 0

#define LED_ORDER DIAL_WHITE, DIAL_WARM_WHITE, DIAL_EXTRA_WARM_WHITE

#define LED_DIAL_MAP       LED_ORDER, LED_ORDER, LED_ORDER
#define LED_NO_DIAL_MAP NO_DIAL,NO_DIAL,NO_DIAL, NO_DIAL,NO_DIAL,NO_DIAL, NO_DIAL,NO_DIAL,NO_DIAL

#define LED_UART_RESHUFFLE 0,2,1,3,5,4,6,8,7

#define ANIMATION_QUEUE_SIZE 20

#define DIAL_MIN_DEFAULT 600
#define DIAL_MAX_DEFAULT 60000
#define DIAL_DEADZONE 400        /* full-on / full-off regions */

#define DEFAULT_MAX_BRIGHTNESS (65535)
#define DEFAULT_GAMMA_DEC (20) /* gamma = gamma_dec/10 */

#define ADC_PIN_0     3
#define ADC_PORT_0    PORTA
#define ADC_PINCTRL_0 PORTA.PIN3CTRL
#define ADC_AIN_0     3

#define ADC_PIN_1     4
#define ADC_PORT_1    PORTA
#define ADC_PINCTRL_1 PORTA.PIN4CTRL
#define ADC_AIN_1     4

#define ADC_PIN_2     5
#define ADC_PORT_2    PORTA
#define ADC_PINCTRL_2 PORTA.PIN5CTRL
#define ADC_AIN_2     5

#define USART0_BAUDRATE 38400
#define USART1_BAUDRATE 115200

#define USART0_RX_BUF_SZ (1)
#define USART1_RX_BUF_SZ (254)


#define USART0_PORTMUX PORTMUX_USART0_DEFAULT_gc // RX = PB3, TX = PB2
#define USART0_BAUD_REG ( (F_CPU*64 + 8ul*USART0_BAUDRATE)/(16ul*USART0_BAUDRATE) )

#define USART1_PORTMUX PORTMUX_USART1_DEFAULT_gc // RX = PA2, TX = PA1
#define USART1_BAUD_REG ( (F_CPU*64 + 8ul*USART1_BAUDRATE)/(16ul*USART1_BAUDRATE) )

#define USART0_RX_PIN 3
#define USART0_RX_PORT PORTB
#define USART0_RX_PINCTRL PORTB.PIN3CTRL

#define USART0_TX_PIN 2
#define USART0_TX_PORT PORTB
#define USART0_TX_PINCTRL PORTB.PIN2CTRL

#define USART1_RX_PIN 2
#define USART1_RX_PORT PORTA
#define USART1_RX_PINCTRL PORTA.PIN2CTRL

#define USART1_TX_PIN 1
#define USART1_TX_PORT PORTA
#define USART1_TX_PINCTRL PORTA.PIN1CTRL

#endif //CONFIG_H
