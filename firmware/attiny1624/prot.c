
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

enum
{
	CMD_FACTORY_RESET,
	CMD_LOAD,
	CMD_RESET,
	CMD_SAVE,
	CMD_SET_LED_0,
	CMD_SET_LED_1,
	CMD_SET_LED_2,
	CMD_SET_MAX_BRIGHTNESS,
	CMD_UNKNOWN_COMMAND,
};

const struct
{
	char *name;
	uint8_t cmd;	
	uint8_t cmp_off;

} commands[] =
{
	{ .name = "FACTORT RESET",      .cmd = CMD_FACTORY_RESET,                   },
	{ .name = "LOAD",               .cmd = CMD_LOAD,                            },
	{ .name = "RESET",              .cmd = CMD_RESET,                           },
	{ .name = "SAVE",               .cmd = CMD_SAVE,                            },
	{ .name = "sET LED 0",          .cmd = CMD_SET_LED_0,          .cmp_off = 1 },
	{ .name = "set led 1",          .cmd = CMD_SET_LED_1,          .cmp_off = 8 },
	{ .name = "set led 2",          .cmd = CMD_SET_LED_2,          .cmp_off = 8 },
	{ .name = "set MAX BRIGHTNESS", .cmd = CMD_SET_MAX_BRIGHTNESS, .cmp_off = 4 },
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
			while ( commands[i].name[off] == toupper(cmd_line[off]) )
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
		case CMD_FACTORY_RESET:
			print ("factory reset\n");
			factory_reset();
			break;
		case CMD_LOAD:
			print ("loading eeprom\n");
			load();
			break;
		case CMD_RESET:
			print ("resetting\n");
			flush();
			reset();
			break;
		case CMD_SAVE:
			print ("saving eeprom\n");
			save();
			break;
		case CMD_SET_LED_0:
		case CMD_SET_LED_1:
		case CMD_SET_LED_2:
		{
			uint8_t led = cmd-CMD_SET_LED_0;
			uint16_t n;
			args = parse_u16(args, &n);
			if (args && *args == '\0')
			{
				print ("set led ");
				print_u16 (led);
				print (" ");
				print_u16 (n);
				print ("\n");
			}
			else
				print ("syntax error\n");
			break;
		}
		case CMD_SET_MAX_BRIGHTNESS:
		{
			uint16_t n;
			args = parse_u16(args, &n);
			gamma_set_max(n);
			if (args && *args == '\0')
			{
				gamma_set_max(n);
				n = gamma_get_max();
				print ("max brightness: ");
				print_u16 (n);
				print ("\n");
			}
			else
				print ("syntax error\n");

			break;
		}
		case CMD_UNKNOWN_COMMAND:
			print ("unknown command\n");
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
	int c;
	while ( (c = uart_getchar()) != -1)
	{
		if (c == '\r')
			continue;

		if (c == '\n')
		{
			line[ix] = '\0';
			process_cmd(line);
			write_prompt();
			ix = 0;
			break;
		}

		line[ix++] = c;
	}
}

void prot_init(void)
{
	print ("I am a lamp\n");
	write_prompt();
}

