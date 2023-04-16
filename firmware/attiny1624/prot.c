
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

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
	CMD_HELP,
	CMD_LOAD,
	CMD_OFF,
	CMD_ON,
	CMD_RESET,
	CMD_SAVE,
	CMD_SET_GAMMA,
	CMD_SET_LED,
	CMD_SET_LEDS,
	CMD_SET_MAX_BRIGHTNESS,
	CMD_UNKNOWN_COMMAND,
	CMD_SYNTAX_ERROR,
};

typedef struct
{
	uint8_t cmd;

	const char *name;
	uint8_t len;

	const char *arglist;

} cmd_t;

static const cmd_t commands[] =
{
	#define C(str, command, alist) { .name = str, .cmd = command, .len = sizeof(str)-1, .arglist = alist }
	/* commands are assumed to be in alphabetical order:    */
	C( "blink",              CMD_BLINK,               ""    ),
	C( "debug",              CMD_DEBUG,               ""    ),
	C( "factory reset",      CMD_FACTORY_RESET,       ""    ),
	C( "help",               CMD_HELP,                ""    ),
	C( "load",               CMD_LOAD,                ""    ),
	C( "off",                CMD_OFF,                 ""    ),
	C( "on",                 CMD_ON,                  ""    ),
	C( "reset",              CMD_RESET,               ""    ),
	C( "save",               CMD_SAVE,                ""    ),
	C( "set gamma",          CMD_SET_GAMMA,           "g"   ),
	C( "set led",            CMD_SET_LED,             "lc"  ),
	C( "set leds",           CMD_SET_LEDS,            "p"   ),
	C( "set max brightness", CMD_SET_MAX_BRIGHTNESS,  "n"   ),
	C( NULL,                 CMD_UNKNOWN_COMMAND,     NULL  ),
	#undef C
};

static const struct
{
	char x;
	const char *desc;
} args_help[] =
{
	{ 'n', " {0..65535}" },
	{ 'l', " " STR_LED_RANGE "" },
	{ 'c', " [" STR_DIAL_RANGE "][:]{0..65535}" },
	{ 'p', " [" STR_DIAL_RANGE "][:]{0..65535} ... x " STR_N_LEDS },
	{ 'g', " {1.0..5.5}" },
	{ '\0', "" },
};

const char *get_arg_help(char x)
{
	uint8_t i;
	for (i=0; args_help[i].x; i++)
		if (args_help[i].x == x)
			return args_help[i].desc;

	return "<error>";
}

static struct
{
	uint16_t led;
	uint16_t n;
	preset_t p;
	uint8_t gamma;
	uint8_t dial;

} args;

void help(void)
{
	println("commands:");
	println("");

	const cmd_t *cmd;
	for (cmd=&commands[0]; cmd->name; cmd++)
	{
		print(cmd->name);
		const char *a;
		for (a=cmd->arglist ; *a; a++)
			print(get_arg_help(*a));

		println("");
	}
	println("");
}

uint8_t parse_args(uint8_t cmd, uint8_t *s)
{
	const char *a;
	for (a=commands[cmd].arglist; *a; a++)
	{
		if (*s != ' ')
			return 0;

		while (*s == ' ')
			s++;

		switch (*a)
		{
			case 'n':
				s = parse_u16(s, &args.n);
				break;
			case 'l':
				s = parse_u16(s, &args.led);
				if (args.led >= N_LEDS)
					s=NULL;
				break;
			case 'c':
				s = parse_led_config(s, &args.dial, &args.n);
				break;
			case 'g':
				s = parse_u8_one_decimal(s, &args.gamma);
				break;
			case 'p':
			{
				uint8_t i;
				for (i=0; i<N_LEDS; i++)
				{
					s = parse_led_config(s, &args.p.config[i], &args.p.brightness[i]);
					if ( !s )
						break;

					if ( (i < N_LEDS-1) && (*s != ' ') )
					{
						s = NULL;
						break;
					}

					while ( *s == ' ' )
						s++;
				}
				break;
			}
		}

		if (!s)
			return 0;
	}

	while (*s == ' ')
		s++;

	return *s == '\0';
}

#define CMD_MAX (128)
static uint8_t line[CMD_MAX+1];

static void process_cmd(uint8_t *cmd_line)
{
	uint8_t i;
	uint8_t cmd=CMD_UNKNOWN_COMMAND;
	uint8_t *s=NULL;

	for (i=0; commands[i].name; i++)
	{
		int res = strncasecmp((char *)cmd_line, commands[i].name, commands[i].len);
		if (res > 0)
			continue;
		else if (res < 0)
			break;

		s = &cmd_line[commands[i].len];
		if (*s != '\0' && *s != ' ')
			continue;

		cmd = commands[i].cmd;

		if (!parse_args(cmd, s))
			cmd = CMD_SYNTAX_ERROR;

		break;
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
		case CMD_HELP:
			help();
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
			gamma_set(args.gamma);
			print ("gamma: ");
			print_u32_fixed_point(gamma_get(), 1);
			println ("");
			break;
		case CMD_SET_LED:
			ani_get_preset_top(&args.p);
			args.p.config[args.led] = args.dial;
			args.p.brightness[args.led] = args.n;
			ani_add(&args.p, 60);
			break;
		case CMD_SET_LEDS:
			ani_add(&args.p, 60);
			break;
		case CMD_SET_MAX_BRIGHTNESS:
			gamma_set_max(args.n);
			print ("max brightness: ");
			print_u16 (gamma_get_max());
			println ("");
			break;
		case CMD_OFF:
			ani_add(&preset_off, 120);
			break;
		case CMD_ON:
			ani_add(&preset_default, 120);
			break;
		case CMD_UNKNOWN_COMMAND:
			println ("unknown command");
			break;
		case CMD_SYNTAX_ERROR:
			println ("syntax error");
			break;
		default:
			println ("internal error");
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
		if (c == '\t')
			c = ' ';

		if ( (c == '\n') && ( last == '\r') )
			continue;

		if ( (c == '\r') || (c == '\n') )
		{
			println("");
			line[ix] = '\0';
			if (ix > 0)
				process_cmd(line);
			write_prompt();
			ix = 0;
		}
		else if (isprint(c) && !(last == ' ' && c == ' '))
		{
			uart_putchar(c);

			if (ix < CMD_MAX)
				line[ix++] = c;
		}
		else if ( (c == '\b' || c == '\x7f') && ix > 0)
		{
			ix--;
			print("\b \b");
		}

		last = c;
	}
}

void prot_init(void)
{
	println("");
	println ("I am a lamp");
	write_prompt();
}

