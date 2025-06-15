#pragma once
#ifdef RGBLIGHT_ENABLE
/* underglow control */
void rhruiz_rgblight_reset(void);
void rhruiz_change_leds_to(uint8_t, uint8_t);
#    ifndef RGBLIGHT_LAYERS
typedef struct {
    uint8_t hue;
    uint8_t  sat;
} hue_sat_pair;
#    endif
#endif
