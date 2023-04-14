
#include "preset.h"

const preset_t preset_off =
{
	.brightness = { LED_ALL_OFF },
	.config = { LED_NO_DIAL_MAP },
};

const preset_t preset_blink_on =
{
	.brightness = { LED_BLINK },
	.config = { LED_NO_DIAL_MAP },
};

const preset_t preset_default =
{
	.brightness = { LED_ALL_MAX },
	.config = { LED_DIAL_MAP },
};

