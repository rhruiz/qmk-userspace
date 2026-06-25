#include "quantum.h"
#include "rhruiz.h"

uint16_t copy_paste_timer;
uint8_t window_switcher_mod = 0;

#define NAV_KEY(key, mac, lin_win) \
    [key - NV_START] = {mac, lin_win}

const uint16_t nav_keys[][NUM_NAV_KEYS_OSES] PROGMEM = {
    NAV_KEY(NV_NWIN,   LCMD(KC_GRV),   LALT(KC_GRV)),
    NAV_KEY(NV_NWIN,   LCMD(KC_GRV),   LALT(KC_GRV)),
    NAV_KEY(KC_CTAB,   LCMD(KC_TAB),   LALT(KC_TAB)),
    NAV_KEY(NV_SCTP,   LCMD(KC_UP),    LGUI(KC_HOME)),
    NAV_KEY(NV_SCBT,   LCMD(KC_DOWN),  LGUI(KC_END)),
    NAV_KEY(NV_EOL,    LCMD(KC_RIGHT), KC_END),
    NAV_KEY(NV_BOL,    LCMD(KC_LEFT),  KC_HOME),
    NAV_KEY(NV_WLFT,   LOPT(KC_LEFT),  LCTL(KC_LEFT)),
    NAV_KEY(NV_WRGH,   LOPT(KC_RIGHT), LCTL(KC_RGHT)),
    NAV_KEY(NV_BCK,    LCMD(KC_LBRC),  LALT(KC_LEFT)),
    NAV_KEY(NV_FWD,    LCMD(KC_RBRC),  LALT(KC_RGHT)),
    NAV_KEY(NV_TAN,    LCMD(KC_RCBR),  LCTL(KC_PGDN)),
    NAV_KEY(NV_TAP,    LCMD(KC_LCBR),  LCTL(KC_PGUP)),
    NAV_KEY(NV_MICT,   LCTL(KC_UP),    LGUI(KC_TAB)),
    NAV_KEY(NV_COPY,   LCMD(KC_C),     LCTL(KC_C)),
    NAV_KEY(NV_PSTE,   LCMD(KC_V),     LCTL(KC_V)),
    NAV_KEY(NV_SCSH,   SCMD(KC_3),     LSFT(KC_PSCR)),
    NAV_KEY(NV_WSCH,   SCMD(KC_4),     KC_PSCR),
    NAV_KEY(NV_1MOD,   KC_LGUI,        KC_LCTL),
    NAV_KEY(NV_2MOD,   KC_LCTL,        KC_LGUI),
    NAV_KEY(NV_DELW,   LOPT(KC_BSPC),  LCTL(KC_BSPC))
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
    if (get_highest_layer(state) < FIRST_NON_BASE_LAYER && window_switcher_mod != 0) {
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
