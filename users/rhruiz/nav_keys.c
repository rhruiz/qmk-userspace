#include "quantum.h"
#include "rhruiz.h"

uint16_t copy_paste_timer;
uint8_t window_switcher_mod = 0;

const uint16_t nav_keys[][NUM_NAV_KEYS_OSES] PROGMEM = {
    [NV_NWIN - NV_START] = {LCMD(KC_GRV), LALT(KC_GRV)},
    [KC_CTAB - NV_START] = {LCMD(KC_TAB), LALT(KC_TAB)},
    [NV_SCTP - NV_START] = {LCMD(KC_UP), LGUI(KC_HOME)},
    [NV_SCBT - NV_START] = {LCMD(KC_DOWN), LGUI(KC_END)},
    [NV_EOL  - NV_START] = {LCMD(KC_RIGHT), KC_END},
    [NV_BOL  - NV_START] = {LCMD(KC_LEFT), KC_HOME},
    [NV_WLFT - NV_START] = {LOPT(KC_LEFT), LCTL(KC_LEFT)},
    [NV_WRGH - NV_START] = {LOPT(KC_RIGHT), LCTL(KC_RGHT)},
    [NV_BCK  - NV_START] = {LCMD(KC_LBRC), LALT(KC_LEFT)},
    [NV_FWD  - NV_START] = {LCMD(KC_RBRC), LALT(KC_RGHT)},
    [NV_TAN  - NV_START] = {LCMD(KC_RCBR), LCTL(KC_PGDN)},
    [NV_TAP  - NV_START] = {LCMD(KC_LCBR), LCTL(KC_PGUP)},
    [NV_MICT - NV_START] = {LCTL(KC_UP), LGUI(KC_TAB)},
    [NV_COPY - NV_START] = {LCMD(KC_C), LCTL(KC_C)},
    [NV_PSTE - NV_START] = {LCMD(KC_V), LCTL(KC_V)},
    [NV_SCSH - NV_START] = {SCMD(KC_3), LSFT(KC_PSCR)},
    [NV_WSCH - NV_START] = {SCMD(KC_4), KC_PSCR},
    [NV_1MOD - NV_START] = {KC_LGUI, KC_LCTL},
    [NV_2MOD - NV_START] = {KC_LCTL, KC_LGUI},
    [NV_DELW - NV_START] = {LOPT(KC_BSPC), LCTL(KC_BSPC)},
};

#ifdef HOME_ROW_MODS
const uint16_t os_enabled_homerowmods[2] PROGMEM = { NV_2MOD, NV_1MOD };
#endif

uint16_t get_nav_code(uint16_t keycode) {
    return pgm_read_word(&(nav_keys[keycode - NV_START][nav_keys_index()]));
}

void next_nav_keys(void) {
    set_nav_keys_index((nav_keys_index() + 1) % NUM_NAV_KEYS_OSES);
#ifdef BLINK_LED_PIN
    blink_led(100 + 50 * nav_keys_index(), 6 - nav_keys_index() * 4);
#endif
#ifdef SPLIT_KEYBOARD
    if (is_keyboard_master()) {
        set_needs_runtime_state_sync(true);
    }
#endif
}

void perform_copy_paste(keyrecord_t *record) {
    if (record->event.pressed) {
        copy_paste_timer = timer_read();
    } else {
        if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
            tap_code16(get_nav_code(NV_COPY));
        } else {
            tap_code16(get_nav_code(NV_PSTE));
        }
    }
}

void perform_nav_key(uint16_t keycode, keyrecord_t *record) {
    uint16_t nav_keycode = get_nav_code(keycode);

    void (*handler)(uint16_t) = record->event.pressed ? register_code16 : unregister_code16;
    handler(nav_keycode);
}

void window_switcher(uint16_t keycode, keyrecord_t *record) {
    void (*handler)(uint16_t) = record->event.pressed ? register_code16 : unregister_code16;

    if (record->event.pressed) {
        register_mods(window_switcher_mod = QK_MODS_GET_MODS(keycode));
    }

    handler(QK_MODS_GET_BASIC_KEYCODE(keycode));
}

layer_state_t default_layer_state_set_user_nav(layer_state_t state) {
    if (state < FIRST_NON_BASE_LAYER && window_switcher_mod != 0) {
        unregister_mods(window_switcher_mod);
        window_switcher_mod = 0;
    }

    return state;
}

bool process_record_os_enabled_homerowmod(uint16_t keycode, keyrecord_t *record) {
    if ((record->event.key.row != HOME_ROW_NUMBER_LEFT && record->event.key.row != HOME_ROW_NUMBER_RIGHT)
            || record->tap.count || !IS_QK_MOD_TAP(keycode)) {
        return true;
    }

    /* 5-bit packed modifiers
     *
     * Mod bits:    43210
     *   bit 0      ||||+- Control
     *   bit 1      |||+-- Shift
     *   bit 2      ||+--- Alt
     *   bit 3      |+---- Gui
     *   bit 4      +----- LR flag(Left:0, Right:1)
     */
    uint8_t mod = QK_MOD_TAP_GET_MODS(keycode);

    if (mod & 0b00110) {
        return true;
    }

    void (*handler)(uint16_t) = record->event.pressed ? register_code16 : unregister_code16;
    uint16_t mod_to_send = get_nav_code(pgm_read_word(&(os_enabled_homerowmods[(mod >> 3) & 1])));

    handler(mod_to_send | ((KC_LCMD ^ KC_RCMD) * ((mod >> 4) & 1)));
    return false;
}

bool process_record_nav(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_CTAB:
        case NV_NWIN:
            window_switcher(get_nav_code(keycode), record);
            break;

        case NV_START ... NV_END:
            perform_nav_key(keycode, record);
            break;

        case KC_CCCP:
            perform_copy_paste(record);
            break;

        case KC_NOS:
            if (record->event.pressed) {
                next_nav_keys();
            }
            break;

        default:
#ifdef HOME_ROW_MODS
            return process_record_os_enabled_homerowmod(keycode, record);
#else
            return true;
#endif
    }

    return false;
}
