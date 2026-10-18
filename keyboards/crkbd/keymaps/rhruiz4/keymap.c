#include QMK_KEYBOARD_H
#include "rhruiz.h"
#ifdef THUMBSTICK_ENABLE
#    include "thumbstick.h"
#endif

#define REVERSE_FIVE(K1, K2, K3, K4, K5) K5, K2, K3, K4, K1
#define REV5(...) REVERSE_FIVE(__VA_ARGS__)

// clang-format off
#define LAYOUT_base_wrapper(...) LAYOUT_base(__VA_ARGS__)
#define LAYOUT_split_3x6_3_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)
#define LAYOUT_split_3x6_3_ex2_wrapper(...) LAYOUT_split_3x6_3_ex2(__VA_ARGS__)

#define LAYOUT_base( \
    L01, L02, L03, L04, L05, R01, R02, R03, R04, R05, \
    L11, L12, L13, L14, L15, R11, R12, R13, R14, R15, \
    L21, L22, L23, L24, L25, R21, R22, R23, R24, R25  \
  ) \
  LAYOUT_split_3x6_3_ex2_wrapper( \
/*  ,-----------------------------------------------.   ,-----------------------------------------------.*/ \
      KC_TAB ,   L01  , L02, L03, L04, L05 , TG_NUML,     TG_NUM ,   R01  , R02, R03, R04, R05 , KC_BSPC, \
/*  |--------+--------+----+----+----+-----+--------|   |--------+--------+----+----+-----+----+--------|*/ \
      CT_ESC , HRL(L11, L12, L13, L14, L15), KC_ENT ,     KC_GLBE, HRR(R11, R12, R13, R14, R15), KC_QUOT, \
/*  |--------+--------+----+----+----+-----+--------'   `--------+--------+----+----+----+-----+--------|*/ \
      KC_LSFT,   L21  , L22, L23, L24, L25 ,                         R21  , R22, R23, R24, R25 , KC_RSFT, \
/*  `--------+-----------------------------|                     |-----------------------------+--------'*/ \
                  KC_LGUI, MO_LWR , CT_SPC ,                       ST_ENT , MO_RSE , KC_RALT              \
/*              `--------+--------+--------'                     `--------+--------+--------'            */ \
  )

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWER] = LAYOUT_base_wrapper(
      _______L_QWER_R2_______, _______R_QWER_R2_______,
      _______L_QWER_R3_______, _______R_QWER_R3_______,
      _______L_QWER_R4_______, _______R_QWER_R4_______
  ),

  [_CODH] = LAYOUT_base_wrapper(
      _______L_CODH_R2_______, _______R_COLE_R2_______,
      _______L_CODH_R3_______, _______R_COLE_R3_______,
      _______L_CODH_R4_______, _______R_COLE_R4_______
  ),

  [_GAME] = LAYOUT_split_3x6_3_wrapper(
//,-----------------------------------.  ,-----------------------------------.
    KC_TAB ,  _______L_QWER_R2_______ ,     _______R_QWER_R2_______ , KC_BSPC,
//|--------+--------------------------|  |--------------------------+--------|
    CT_ESC ,  _______L_QWER_R3_______ ,     _______R_QWER_R3_______ , KC_ENT ,
//|--------+--------------------------|  |--------------------------+--------|
    KC_LSFT,  _______L_QWER_R4_______ ,     _______R_QWER_R4_______ , KC_RSFT,
//`--------+--------------------------|  |--------------------------+--------'
              GT_BS ,OSL_GLWR, ST_SPC ,    ST_ENT , MO_RSE ,  AT_BS
//         `--------+--------+--------'  `--------+--------+--------'
    ),

  [_GAMELWR] = LAYOUT_split_3x6_3_wrapper(
//,-----------------------------------.  ,-----------------------------------------------------.
    KC_TAB ,  _____NUMBERS_LEFT_____  ,    _______, _______,  KC_UP , _______, _______, _______,
//|--------+--------------------------|  |--------------------------------------------+--------|
    S_LCTL ,  _____NUMBERS_RGHT_____  ,    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
//|--------+--------------------------|  |--------------------------------------------+--------|
    KC_LALT,  ____FUNCTIONS_LEFT____  ,    _______, _______,  KC_LT ,  KC_GT , KC_QUES, _______,
//`--------+--------------------------|  |--------------------------------------------+--------'
             _______, _______, KC_LSFT,    _______, _______, _______
//         `--------+--------+--------'  `--------+--------+--------'
    ),

  [_LWR] = LAYOUT_split_3x6_3_ex2_wrapper(
//,-----------------------------------.--------.   ,--------------------------------------------.
    KC_GRV ,  ________L_LWR_2________ , _______,     _______,  ________R_LWR_2________ , KC_DEL ,
//|--------+--------------------------|--------|   |--------+--------------------------+--------|
    KC_TILD,  ________L_LWR_3________ , KC_BSPC,     _______,  ________R_LWR_3________ , KC_DQUO,
//|--------+--------------------------|--------'   `--------+--------------------------+--------|
    _______,  ________L_LWR_4________ ,                        ________R_LWR_4________ , _______,
//`--------+--------------------------|                     |--------------------------+--------'
             _______, _______, _______,                       _______, _______, _______
//         `--------+--------+--------'                     `--------+--------+--------'
  ),

  [_RSE] = LAYOUT_split_3x6_3_wrapper(
//,-----------------------------------.  ,-----------------------------------.
    KC_GRV ,  ________L_RSE_2________ ,     ________R_RSE_2________ , KC_DEL ,
//|--------+--------------------------|  |--------------------------+--------|
    KC_TILD,  ________L_RSE_3________ ,     ________R_RSE_3________ , KC_DQUO,
//|--------+--------------------------|  |--------------------------+--------|
    _______,  ________L_RSE_4________ ,     ________R_RSE_4________ , _______,
//`--------+--------------------------|  |--------------------------+--------'
             _______, _______, _______,    _______, _______, _______
//         `--------+--------+--------'  `--------+--------+--------'
),

  [_AUG] = LAYOUT_split_3x6_3_wrapper(
//,-----------------------------------.  ,-----------------------------------.
    _______,  ________L_AUG_2________ ,     ________R_AUG_2________ , _______,
//|--------+--------------------------|  |--------------------------+--------|
    _______,  ________L_AUG_3________ ,     ________R_AUG_3________ , _______,
//|--------+--------------------------|  |--------------------------+--------|
    _______,  ________L_AUG_4________ ,     ________R_AUG_4________ , _______,
//`--------+--------------------------|  |--------------------------+--------'
             _______, _______, _______,    _______, _______, _______
//         `--------+--------+--------'  `--------+--------+--------'
),

  [_CFG] = LAYOUT_split_3x6_3_ex2_wrapper(
//,--------------------------------------------.   ,--------------------------------------------.
    _______,  ________L_CFG_2________ , RM_SPDU,      KC_NO ,  ________R_CFG_2________ , _______,
//|--------+--------------------------+--------|   |--------+--------------------------+--------|
    _______,  ________L_CFG_3________ , RM_SPDD,      KC_NO ,  ________R_CFG_3________ , _______,
//|--------+--------------------------+--------'   `--------+--------------------------+--------|
    _______,  ________L_CFG_4________ ,                        ________R_CFG_4________ , _______,
//`--------+--------------------------|                     |--------------------------+--------'
             _______, _______, _______,                       _______, _______, _______
//         `--------+--------+--------'                     `--------+--------+--------'
  ),

  [_NUM] = LAYOUT_split_3x6_3_ex2_wrapper(
//,--------------------------------------------.   ,--------------------------------------------.
    _______,  ________L_NUM_2________ ,  KC_NO ,     TG_NUM ,  ________R_NUM_1________ , _______,
//|--------+--------------------------+--------|   |--------+--------------------------+--------|
    _______,  ________L_NUM_3________ ,  KC_NO ,     KC_CCCP,  ________R_NUM_2________ , TG_NUM ,
//|--------+--------------------------+--------'   `--------+--------------------------+--------|
    _______,  ________L_NUM_4________ ,                        ________R_NUM_3________ , _______,
//`--------+--------------------------|                     |--------------------------+--------'
             MS_BTN2, _______, MS_BTN1,                       _______,LT_RSE_0, AT_TAB
//         `--------+--------+--------'                     `--------+--------+--------'
    ),

  [_NUML] = LAYOUT_split_3x6_3_ex2_wrapper(
//,--------------------------------------------------.   ,--------------------------------------------------.
    _______,  REV5(________R_NUM_1________) , _______,     _______,  REV5(________L_NUM_2________) , _______,
//|--------+--------------------------------+--------|   |--------+--------------------------------+--------|
    _______,  REV5(________R_NUM_2________) , _______,     _______,  REV5(________L_NUM_3________) , TG_NUM ,
//|--------+--------------------------------+--------'   `--------+--------------------------------+--------|
    _______,  REV5(________R_NUM_3________) ,                        REV5(________L_NUM_4________) , _______,
//`--------+--------------------------------|                     |--------------------------------+--------'
                    GT_BS ,LT_LWR_0, _______,                       MS_BTN1, _______, MS_BTN2
//               `--------+--------+--------'                     `--------+--------+--------'
    ),

  [_FUNC] = LAYOUT_split_3x6_3_wrapper(
//,-----------------------------------.  ,-----------------------------------.
    _______,  ________L_FUN_2________ ,     ________R_FUN_2________ , _______,
//|--------+--------------------------|  |--------------------------+--------|
    _______,  ________L_FUN_3________ ,     ________R_FUN_3________ , _______,
//|--------+--------------------------|  |--------------------------+--------|
    _______,  ________L_FUN_4________ ,     ________R_FUN_4________ , _______,
//`--------+--------------------------|  |--------------------------+--------'
             _______, _______, _______,    _______, _______, _______
//         `--------+--------+--------'  `--------+--------+--------'
  ),

  /* templates
  [_LAYER] = LAYOUT_split_3x6_3(
//,-----------------------------------------------------.  ,-----------------------------------------------------.
    _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
//|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
//|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
//`--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------'
                               _______, _______, _______,    _______, _______, _______
//                           `--------+--------+--------'  `--------+--------+--------'
  ),
  */
};
// clang-format on

#if defined(RGB_MATRIX_ENABLE)

#define LWR_LED 7
#define RSE_LED 30

bool rgb_matrix_indicators_keymap(void) {
    uint8_t k_rgb_matrix_split[2] = RGB_MATRIX_SPLIT;
    uint8_t left_leds = k_rgb_matrix_split[0];

    switch (get_highest_layer(layer_state|default_layer_state)) {
        case _LWR:
        case _GAMELWR:
            rgb_matrix_set_color(LWR_LED, LWR_RGB);
            break;

        case _RSE:
            rgb_matrix_set_color(RSE_LED, RSE_RGB);
            break;

        case _AUG:
            rgb_matrix_set_color(LWR_LED, AUG_RGB);
            rgb_matrix_set_color(RSE_LED, AUG_RGB);
            break;
    }

    if (layer_state_is(_NUM) || layer_state_is(_NUML)) {
        uint8_t offset = layer_state_is(_NUM) ? 0 : left_leds;

        // left side on NUM, right on NUML
        rgb_matrix_set_color(offset + LWR_LED, 64, 0, 0);

        rgb_matrix_set_color(offset + 5, RGB_PURPLE);
        rgb_matrix_set_color(offset + 10, RGB_PURPLE);
        rgb_matrix_set_color(offset + 11, RGB_PURPLE);
        rgb_matrix_set_color(offset + 13, RGB_PURPLE);

        // right side on NUM, left on NUML
        rgb_matrix_set_color(k_rgb_matrix_split[0] - offset + RSE_LED , 64, 0, 0);

        // inner colunm, top key, right for NUM, left for NUML
        rgb_matrix_set_color(44 - offset, 64, 0, 0);

        rgb_matrix_set_color(k_rgb_matrix_split[0] - offset + 4, NUM_RGB);
        rgb_matrix_set_color(k_rgb_matrix_split[0] - offset + 5, NUM_RGB);
        rgb_matrix_set_color(k_rgb_matrix_split[0] - offset + 6, NUM_RGB);
        rgb_matrix_set_color(k_rgb_matrix_split[0] - offset + 7, NUM_RGB);
        rgb_matrix_set_color(k_rgb_matrix_split[0] - offset + 9, NUM_RGB);
        rgb_matrix_set_color(k_rgb_matrix_split[0] - offset + 10, NUM_RGB);
        rgb_matrix_set_color(k_rgb_matrix_split[0] - offset + 11, NUM_RGB);
        rgb_matrix_set_color(k_rgb_matrix_split[0] - offset + 12, NUM_RGB);
        rgb_matrix_set_color(k_rgb_matrix_split[0] - offset + 13, NUM_RGB);
        rgb_matrix_set_color(k_rgb_matrix_split[0] - offset + 14, NUM_RGB);
    }

#   if defined(HOME_ROW_MODS)
    uint8_t mods = mod_config(get_mods());
#   ifndef NO_ACTION_ONESHOT
    mods |= mod_config(get_oneshot_mods());
#   endif

    uint8_t nav_index = nav_keys_index();
    uint8_t mods_offset = 0;

    if (!is_keyboard_left()) {
        mods = mods >> 4;
        mods_offset = left_leds;
    }

    if (mods & MOD_BIT(KC_LGUI)) {
        rgb_matrix_set_color(mods_offset + 5 + 11 * nav_index, RGB_PURPLE);
    }

    if (mods & MOD_BIT(KC_LCTL)) {
        rgb_matrix_set_color(mods_offset + 16 - 11 * nav_index, RGB_TEAL);
    }

    if (mods & MOD_BIT(KC_LSFT)) {
        rgb_matrix_set_color(mods_offset + 13, RGB_RED);
    }

    if (mods & MOD_BIT(KC_LALT)) {
        rgb_matrix_set_color(mods_offset + 10, RGB_SPRINGGREEN);
    }
#   endif

#   if defined(CAPS_WORD_ENABLE)
    if (caps_word_enabled()) {
        rgb_matrix_set_color(9, CAPS_RGB);
    }
#   endif

    if (layer_state_is(_FUNC)) {
        rgb_matrix_set_color(LWR_LED, FUN_RGB);
        rgb_matrix_set_color(RSE_LED, FUN_RGB);

        rgb_matrix_set_color(5, FUN_RGB);
        rgb_matrix_set_color(10, FUN_RGB);
        rgb_matrix_set_color(13, FUN_RGB);
        rgb_matrix_set_color(16, FUN_RGB);

        for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
            for (uint8_t col = 0; col < MATRIX_COLS; col++) {
                uint16_t keycode = keymap_key_to_keycode(_FUNC, (keypos_t){.row = row, .col = col});
                uint8_t index = g_led_config.matrix_co[row][col];

                switch (keycode) {
                    case KC_F1 ... KC_F12:
                        rgb_matrix_set_color(index, FUN_RGB);
                        break;

                }
            }
        }
    }

    if (layer_state_is(_CFG)) {
        rgb_matrix_set_color(left_leds + 3, CFG_RGB);
        rgb_matrix_set_color(LWR_LED, CFG_RGB);
        rgb_matrix_set_color(RSE_LED, CFG_RGB);

        if (default_layer_index()) {
            rgb_matrix_set_color(left_leds + 10, RGB_OFF);
            rgb_matrix_set_color(left_leds + 5, COLEMAK_RGB);
        } else {
            rgb_matrix_set_color(left_leds + 5, RGB_OFF);
            rgb_matrix_set_color(left_leds + 10, QWERTY_RGB);
        }

        if (nav_keys_index() == 0) {
            rgb_matrix_set_color(g_led_config.matrix_co[5][2], MAC_RGB);
        } else {
            rgb_matrix_set_color(g_led_config.matrix_co[5][2], WIN_RGB);
        }
    }

    return true;
}
#endif

layer_state_t layer_state_set_keymap(layer_state_t state) {
#if defined(RGB_MATRIX_ENABLE)
    if (!layer_state_is(_GAME) && layer_state_cmp(state, _GAME)) {
        rgb_matrix_reload_from_eeprom();
        rgb_matrix_enable_noeeprom();
    }

    if (layer_state_is(_GAME) && !layer_state_cmp(state, _GAME)) {
        rgb_matrix_enable_noeeprom();
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
        rgb_matrix_sethsv_noeeprom(HSV_OFF);
    }
#endif
    return state;
}

#if defined(RGB_MATRIX_ENABLE) && defined(DEFERRED_EXEC_ENABLE)
uint32_t disable_boot_rgb(uint32_t next_trigger_time, void *cb_arg) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
    rgb_matrix_set_speed_noeeprom(128);
    return 0;
}
#endif

#if defined(RGB_MATRIX_ENABLE)
void keyboard_post_init_keymap() {
    #if defined(DEFERRED_EXEC_ENABLE)
    rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
    rgb_matrix_set_speed_noeeprom(191);
    defer_exec(1200, disable_boot_rgb, NULL);
    #else
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
    #endif
    rgb_matrix_enable_noeeprom();
}
#endif
