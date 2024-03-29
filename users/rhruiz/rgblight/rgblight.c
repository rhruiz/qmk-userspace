#ifdef RGBLIGHT_ENABLE
#include "quantum.h"

void rhruiz_rgblight_reset(void) {
#ifndef RGBLIGHT_LAYERS
    rgblight_reload_from_eeprom();
#endif
}

void rhruiz_change_leds_to(uint16_t hue, uint8_t sat) {
    rgblight_config_t eeprom_config;
    eeprom_config.raw = eeconfig_read_rgblight();
    rgb_led_t *ledp;

#ifdef RGBLIGHT_LED_MAP
    rgb_led_t led0[RGBLIGHT_LED_COUNT];
    for (uint8_t i = 0; i < RGBLIGHT_LED_COUNT; i++) {
        led0[i] = led[pgm_read_byte(&led_map[i])];
    }
    ledp = led0;
#else
    ledp = led;
#endif

    for (uint8_t i = RGBLIGHT_LED_COUNT; i-- > 0;) {
        sethsv(hue, sat, eeprom_config.val, (rgb_led_t *)&ledp[i]);
    }

#ifdef RGBW
    ws2812_setleds_rgbw(ledp, RGBLIGHT_LED_COUNT);
#else
    ws2812_setleds(ledp, RGBLIGHT_LED_COUNT);
#endif
}
#endif
