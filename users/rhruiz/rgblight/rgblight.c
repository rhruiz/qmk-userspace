#ifdef RGBLIGHT_ENABLE
#include "quantum.h"

void rhruiz_rgblight_reset(void) {
#ifndef RGBLIGHT_LAYERS
    rgblight_reload_from_eeprom();
#endif
}

void rhruiz_change_leds_to(uint8_t hue, uint8_t sat) {
    rgblight_config_t eeprom_config;
    eeconfig_read_rgblight(&eeprom_config);

    rgblight_sethsv_range(hue, sat, eeprom_config.val, 0, RGBLIGHT_LED_COUNT - 1);
}
#endif
