
#include "preset.h"

const preset_t preset_off =
{
	.brightness = { LED_ALL_OFF },
	.dial = { LED_NO_DIAL_MAP },
};

const preset_t preset_blink_on =
{
	.brightness = { LED_BLINK },
	.dial = { LED_NO_DIAL_MAP },
};

const preset_t preset_default =
{
	.brightness = { LED_ALL_MAX },
	.dial = { LED_DIAL_MAP },
};

