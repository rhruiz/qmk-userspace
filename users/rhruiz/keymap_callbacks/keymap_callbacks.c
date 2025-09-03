#include "quantum.h"
#include "keymap_callbacks.h"

__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) { return state; }

__attribute__((weak)) layer_state_t default_layer_state_set_keymap(layer_state_t state) { return state; }

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

__attribute__((weak)) void keyboard_post_init_keymap(void) {}

__attribute__((weak)) void housekeeping_task_keymap(void) {}

__attribute__((weak)) void matrix_scan_keymap(void) {}

__attribute__((weak)) void matrix_init_keymap(void) {}

__attribute__((weak)) void caps_word_set_keymap(bool active) {}

__attribute__((weak)) void suspend_power_down_keymap(void) {}

__attribute__((weak)) void suspend_wakeup_init_keymap(void) {}

__attribute__((weak)) bool shutdown_keymap(bool jump_to_bootloader) {
    return true;
}

#ifdef ENCODER_ENABLE
__attribute__((weak)) bool encoder_update_keymap(uint8_t index, bool clockwise) { return true; }
#endif

#ifdef OLED_ENABLE
__attribute__((weak)) bool oled_task_keymap(void) { return true; }
#endif

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_user(void) {
    if (!rgb_matrix_indicators_keymap()) {
        return false;
    }

    return true;
}

__attribute__((weak)) bool rgb_matrix_indicators_keymap(void) { return true; }
#endif
