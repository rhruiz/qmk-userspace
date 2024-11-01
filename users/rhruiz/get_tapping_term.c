#include "quantum.h"
#include "rhruiz.h"

#define IS_MODT(mod, kc) (kc & MT(mod & 0x0F, KC_NO) & ~QK_MOD_TAP) >> 8 > 0

#ifdef HOME_ROW_MODS
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    uint8_t row = record->event.key.row;

    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            if ((row == HOME_ROW_NUMBER_RIGHT || row == HOME_ROW_NUMBER_LEFT) &&
                (IS_MODT(MOD_LCTL, keycode) || IS_MODT(MOD_LSFT, keycode))) {
                return TAPPING_TERM + 50;
            }
    }

    return TAPPING_TERM;
}
#endif
