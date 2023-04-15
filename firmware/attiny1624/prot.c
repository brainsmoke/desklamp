
#include <ctype.h>
#include <stdlib.h>

#include "config.h"

#include "prot.h"
#include "uart.h"
#include "dial.h"
#include "settings.h"
#include "system.h"
#include "gamma.h"
#include "io.h"
#include "firmware.h"
#include "ani.h"

enum
{
	CMD_BLINK,
	CMD_DEBUG,
	CMD_FACTORY_RESET,
	CMD_LOAD,
	CMD_RESET,
	CMD_SAVE,
	CMD_SET_GAMMA,
	CMD_SET_LED,
	CMD_SET_LEDS,
	CMD_SET_MAX_BRIGHTNESS,
	CMD_OFF,
	CMD_ON,
	CMD_UNKNOWN_COMMAND,
};

const struct
{
	char *name;
	uint8_t cmd;	
	uint8_t cmp_off;

} commands[] =
{
	{ .name = "BLINK",              .cmd = CMD_BLINK,                           },
	{ .name = "DEBUG",              .cmd = CMD_DEBUG,                           },
	{ .name = "FACTORY RESET",      .cmd = CMD_FACTORY_RESET,                   },
	{ .name = "LOAD",               .cmd = CMD_LOAD,                            },
	{ .name = "RESET",              .cmd = CMD_RESET,                           },
	{ .name = "SAVE",               .cmd = CMD_SAVE,                            },
	{ .name = "sET GAMMA",          .cmd = CMD_SET_GAMMA,          .cmp_off = 1 },
	{ .name = "set LED",            .cmd = CMD_SET_LED,            .cmp_off = 4 },
	{ .name = "set ledS",           .cmd = CMD_SET_LEDS,           .cmp_off = 7 },
	{ .name = "set MAX BRIGHTNESS", .cmd = CMD_SET_MAX_BRIGHTNESS, .cmp_off = 4 },
	{ .name = "OFF",                .cmd = CMD_OFF,                             },
	{ .name = "oN",                 .cmd = CMD_ON,                 .cmp_off = 1 },
	{ .name = NULL,                 .cmd = CMD_UNKNOWN_COMMAND,                 },
};

#define CMD_MAX (256)
static uint8_t line[CMD_MAX+1];

static void process_cmd(uint8_t *cmd_line)
{
	uint8_t i, off=0;
	uint8_t cmd=CMD_UNKNOWN_COMMAND;
	uint8_t *args=NULL;
	for (i=0; commands[i].cmd != CMD_UNKNOWN_COMMAND; i++)
	{
		if (commands[i].cmp_off < off)
			break;

		if (commands[i].cmp_off == off)
		{
			while ( commands[i].name[off] && commands[i].name[off] == toupper(cmd_line[off]) )
				off++;

			if (commands[i].name[off] == '\0')
			{
				if (cmd_line[off] == ' ')
					off++;
				else if (cmd_line[off] != '\0')
					continue;

				args = &cmd_line[off];
				cmd = commands[i].cmd;
				break;
			}
		}
	}

	switch (cmd)
	{
		case CMD_BLINK:
			ani_blink();
			break;
		case CMD_DEBUG:
			debug_print();
			break;
		case CMD_FACTORY_RESET:
			println ("factory reset");
			factory_reset();
			break;
		case CMD_LOAD:
			println ("loading eeprom");
			load();
			break;
		case CMD_RESET:
			println ("resetting");
			flush();
			reset();
			break;
		case CMD_SAVE:
			println ("saving eeprom");
			save();
			break;
		case CMD_SET_GAMMA:
		{
			uint8_t n;
			args = parse_u8_one_decimal(args, &n);
			if (args && *args == '\0')
			{
				gamma_set(n);
				print ("gamma: ");
				print_u32_fixed_point(gamma_get(), 1);
				println ("");
			}
			else
				println ("syntax error");

			break;
		}
		case CMD_SET_LED:
		{
			uint16_t led;
			args = parse_u16(args, &led);
			if ( args && led < N_LEDS )
			{
				while ( *args == ' ' )
					args++;

				preset_t p;
				ani_get_preset_top(&p);
				args = parse_led_config(args, &p.config[led], &p.brightness[led]);
				if (args && *args == '\0')
				{
					ani_add(&p, 60);
					break;
				}
			}
			println ("syntax error");
			break;
		}
		case CMD_SET_LEDS:
		{
			uint8_t i;
			preset_t p;
			for (i=0; i<N_LEDS; i++)
			{
				args = parse_led_config(args, &p.config[i], &p.brightness[i]);
				if ( !args )
					break;

				if ( (i < N_LEDS-1) && (*args != ' ') )
				{
					args = NULL;
					break;
				}

				while ( *args == ' ' )
					args++;
			}

			if (args && *args == '\0')
				ani_add(&p, 60);
			else
				println ("syntax error");
			break;
		}
		case CMD_SET_MAX_BRIGHTNESS:
		{
			uint16_t n;
			args = parse_u16(args, &n);
			if (args && *args == '\0')
			{
				gamma_set_max(n);
				print ("max brightness: ");
				print_u16 (gamma_get_max());
				println ("");
			}
			else
				println ("syntax error");

			break;
		}
		case CMD_OFF:
			ani_add(&preset_off, 120);
			break;
		case CMD_ON:
			ani_add(&preset_default, 120);
			break;
		case CMD_UNKNOWN_COMMAND:
			println ("unknown command");
			break;
	}
}

static void write_prompt(void)
{
	print("lampsh> ");
}

void prot_poll(void)
{
	static uint16_t ix=0;
	static uint8_t last = 0;
	int c;
	while ( (c = uart_getchar()) != -1)
	{
		last = c;

		if ( (c == '\n') && ( last == '\r') )
			continue;

		if ( (c == '\r') || (c == '\n') )
		{
			println("");
			line[ix] = '\0';
			process_cmd(line);
			write_prompt();
			ix = 0;
			break;
		}
		uart_putchar(c);

		line[ix++] = c;
	}
}

void prot_init(void)
{
	println("");
	println ("I am a lamp");
	write_prompt();
}

