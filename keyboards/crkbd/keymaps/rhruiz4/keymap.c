#include QMK_KEYBOARD_H
#include "rhruiz.h"
#ifdef THUMBSTICK_ENABLE
#    include "thumbstick.h"
#endif

#define SWAP_SIDE(K1, K2, K3, K4, K5) K5, K2, K3, K4, K1
#define SWSD(...) SWAP_SIDE(__VA_ARGS__)

#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)
const rgblight_segment_t PROGMEM fn1_colors[] = RGBLIGHT_LAYER_SEGMENTS({7, 1, 127, 255, 255});
const rgblight_segment_t PROGMEM fn2_colors[] = RGBLIGHT_LAYER_SEGMENTS({30, 1, 21, 255, 255});
const rgblight_segment_t PROGMEM aug_colors[] = RGBLIGHT_LAYER_SEGMENTS({7, 1,  85, 255, 255}, {30, 1, 85, 255, 255});
const rgblight_segment_t PROGMEM cfg_colors[] = RGBLIGHT_LAYER_SEGMENTS({26, 1, 201, 255, 255});
const rgblight_segment_t PROGMEM num_colors[] = RGBLIGHT_LAYER_SEGMENTS({44, 1, 0, 255, 255});
const rgblight_segment_t PROGMEM fun_colors[] = RGBLIGHT_LAYER_SEGMENTS({27, 3, 0, 255, 255}, {32, 9, 0, 255, 255});
const rgblight_segment_t PROGMEM caps_colors[] = RGBLIGHT_LAYER_SEGMENTS({14, 8, 201, 255, 255});
const rgblight_segment_t PROGMEM qwerty_colors[] = RGBLIGHT_LAYER_SEGMENTS({33, 1, 43, 255, 255});
const rgblight_segment_t PROGMEM colemak_dh_colors[] = RGBLIGHT_LAYER_SEGMENTS({28, 1, 180, 255, 255});
const rgblight_segment_t PROGMEM mac_colors[] = RGBLIGHT_LAYER_SEGMENTS({36, 1, 0, 0, 255});
const rgblight_segment_t PROGMEM win_colors[] = RGBLIGHT_LAYER_SEGMENTS({36, 1, 148, 255, 255});

const rgblight_segment_t* const PROGMEM _rgb_layers[] = RGBLIGHT_LAYERS_LIST(fn1_colors, fn2_colors, aug_colors, cfg_colors, num_colors, fun_colors, caps_colors, qwerty_colors, colemak_dh_colors, mac_colors, win_colors);
#endif


// clang-format off
#define LAYOUT_base_wrapper(...) LAYOUT_base(__VA_ARGS__)
#define LAYOUT_split_3x6_3_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)
#define LAYOUT_split_3x6_3_ex2_wrapper(...) LAYOUT_split_3x6_3_ex2(__VA_ARGS__)

#ifdef LOCK_LAYERS
#define LAYOUT_base( \
    L01, L02, L03, L04, L05, R01, R02, R03, R04, R05, \
    L11, L12, L13, L14, L15, R11, R12, R13, R14, R15, \
    L21, L22, L23, L24, L25, R21, R22, R23, R24, R25  \
  ) \
  LAYOUT_split_3x6_3_wrapper_ex2( \
/*  ,-----------------------------------------------.   ,-----------------------------------------------.*/ \
      KC_TAB ,   L01  , L02, L03, L04, L05 , TG_NUML,     TG_NUM ,   R01  , R02, R03, R04, R05 , KC_BSPC, \
/*  |--------+--------+----+----+----+-----+--------|   |--------+--------+----+----+-----+----+--------|*/ \
      CT_ESC , HRL(L11, L12, L13, L14, L15),  KC_NO ,      KC_NO , HRR(R11, R12, R13, R14, R15), KC_QUOT, \
/*  |--------+--------+----+----+----+-----+--------.   `--------+--------+----+----+----+-----+--------|*/ \
      KC_LSFT,   L21  , L22, L23, L24, L25 ,                         R21  , R22, R23, R24, R25 , KC_RSFT, \
/*  `--------+-----------------------------|                     |-----------------------------+--------'*/ \
                  KC_LGUI, KC_LGUI, CT_SPC ,                       ST_ENT , TO_LWR , KC_RALT              \
/*              `--------+--------+--------'                     `--------+--------+--------'            */ \
  )
#else
#define LAYOUT_base( \
    L01, L02, L03, L04, L05, R01, R02, R03, R04, R05, \
    L11, L12, L13, L14, L15, R11, R12, R13, R14, R15, \
    L21, L22, L23, L24, L25, R21, R22, R23, R24, R25  \
  ) \
  LAYOUT_split_3x6_3_ex2_wrapper( \
/*  ,-----------------------------------------------.   ,-----------------------------------------------.*/ \
      KC_TAB ,   L01  , L02, L03, L04, L05 , TG_NUML,     TG_NUM ,   R01  , R02, R03, R04, R05 , KC_BSPC, \
/*  |--------+--------+----+----+----+-----+--------|   |--------+--------+----+----+-----+----+--------|*/ \
      CT_ESC , HRL(L11, L12, L13, L14, L15),  KC_NO ,      KC_NO , HRR(R11, R12, R13, R14, R15), KC_QUOT, \
/*  |--------+--------+----+----+----+-----+--------.   `--------+--------+----+----+----+-----+--------|*/ \
      KC_LSFT,   L21  , L22, L23, L24, L25 ,                         R21  , R22, R23, R24, R25 , KC_RSFT, \
/*  `--------+-----------------------------|                     |-----------------------------+--------'*/ \
                  KC_LGUI, MO_LWR , CT_SPC ,                       ST_ENT , MO_RSE , KC_RALT              \
/*              `--------+--------+--------'                     `--------+--------+--------'            */ \
  )
#endif

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

  [_GAMEFN1] = LAYOUT_split_3x6_3_wrapper(
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

  [_FN1] = LAYOUT_split_3x6_3_wrapper(
//,-----------------------------------.  ,-----------------------------------.
    KC_GRV ,  ________L_LWR_2________ ,     ________R_LWR_2________ , KC_DEL ,
//|--------+--------------------------|  |--------------------------+--------|
    KC_TILD,  ________L_LWR_3________ ,     ________R_LWR_3________ , KC_DQUO,
//|--------+--------------------------|  |--------------------------+--------|
    _______,  ________L_LWR_4________ ,     ________R_LWR_4________ , _______,
//`--------+--------------------------|  |--------------------------+--------'
#ifdef LOCK_LAYERS
             _______,  TO_BL , _______,    _______, TO_AUG , _______
#else
             _______, _______, _______,    _______, _______, _______
#endif
//         `--------+--------+--------'  `--------+--------+--------'
  ),

  [_FN2] = LAYOUT_split_3x6_3_wrapper(
//,-----------------------------------.  ,-----------------------------------.
    KC_GRV ,  ________L_RSE_2________ ,     ________R_RSE_2________ , KC_DEL ,
//|--------+--------------------------|  |--------------------------+--------|
    KC_TILD,  ________L_RSE_3________ ,     ________R_RSE_3________ , KC_DQUO,
//|--------+--------------------------|  |--------------------------+--------|
    _______,  ________L_RSE_4________ ,     ________R_RSE_4________ , _______,
//`--------+--------------------------|  |--------------------------+--------'
#ifdef LOCK_LAYERS
             _______,  TO_BL , _______,    _______, TO_LWR , _______
#else
             _______, _______, _______,    _______, _______, _______
#endif
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
#ifdef LOCK_LAYERS
             _______,  TO_BL , _______,    _______, TO_LWR , _______
#else
             _______, _______, _______,    _______, _______, _______
#endif
//         `--------+--------+--------'  `--------+--------+--------'
),

  [_CFG] = LAYOUT_split_3x6_3_ex2_wrapper(
//,--------------------------------------------.   ,--------------------------------------------.
    _______,  ________L_CFG_2________ , RM_SPDU,      KC_NO ,  ________R_CFG_2________ , _______,
//|--------+--------------------------+--------|   |--------+--------------------------+--------|
    _______,  ________L_CFG_3________ , RM_SPDD,      KC_NO ,  ________R_CFG_3________ , _______,
//|--------+--------------------------+--------.   `--------+--------------------------+--------|
    _______,  ________L_CFG_4________ ,                        ________R_CFG_4________ , _______,
//`--------+--------------------------|                     |--------------------------+--------'
             _______, _______, _______,                       _______, _______, _______
//         `--------+--------+--------'                     `--------+--------+--------'
  ),

  [_NUM] = LAYOUT_split_3x6_3_ex2_wrapper(
//,--------------------------------------------.   ,--------------------------------------------.
    _______,  ________L_NUM_2________ ,  KC_NO ,     TG_NUM ,  ________R_NUM_1________ , _______,
//|--------+--------------------------+--------|   |--------+--------------------------+--------|
    _______,  ________L_NUM_3________ ,  KC_NO ,      KC_NO ,  ________R_NUM_2________ , TG_NUM ,
//|--------+--------------------------+--------.   `--------+--------------------------+--------|
    _______,  ________L_NUM_4________ ,                        ________R_NUM_3________ , _______,
//`--------+--------------------------|                     |--------------------------+--------'
             MS_BTN2, _______, MS_BTN1,                       _______,LT_RSE_0, AT_TAB
//         `--------+--------+--------'                     `--------+--------+--------'
    ),

  [_NUML] = LAYOUT_split_3x6_3_ex2_wrapper(
//,--------------------------------------------------.   ,--------------------------------------------------.
    _______,  SWSD(________R_NUM_1________) , TG_NUML,     TG_NUM ,  SWSD(________L_NUM_2________) , _______,
//|--------+--------------------------------+--------|   |--------+--------------------------------+--------|
    _______,  SWSD(________R_NUM_2________) , KC_ENT ,      KC_NO ,  SWSD(________L_NUM_3________) , TG_NUM ,
//|--------+--------------------------------+--------.   `--------+--------------------------------+--------|
    _______,  SWSD(________R_NUM_3________) ,                        SWSD(________L_NUM_4________) , _______,
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

void housekeeping_task_keymap(void) {
#if defined(RGBLIGHT_LAYERS) && defined(RGBLIGHT_ENABLE)
    rgblight_set_layer_state(7, layer_state_is(_CFG) && default_layer_index() == 0);
    rgblight_set_layer_state(8, layer_state_is(_CFG) && default_layer_index() == 1);
    rgblight_set_layer_state(9, layer_state_is(_CFG) && nav_keys_index() == 0);
    rgblight_set_layer_state(10, layer_state_is(_CFG) && nav_keys_index() == 1);
#endif
#if defined(PRO_MICRO)
    gpio_write_pin(D5, !layer_state_cmp(layer_state, _NUM));
#endif
}

#if defined(RGB_MATRIX_ENABLE)
bool rgb_matrix_indicators_keymap(void) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case _FN1:
        case _GAMEFN1:
            if (is_keyboard_left()) {
                rgb_matrix_set_color(7, 0x0f, 0xff, 0xfb);
            }
            break;

        case _FN2:
            if (!is_keyboard_left()) {
                rgb_matrix_set_color(30, 0xff, 0x99, 0x00);
            }
            break;

        case _AUG:
            rgb_matrix_set_color(7, RGB_GREEN);
            break;
    }

    if ((is_keyboard_left() && layer_state_is(_NUM)) ||
        (!is_keyboard_left() && layer_state_is(_NUML))) {
        rgb_matrix_set_color(5, RGB_PURPLE);
        rgb_matrix_set_color(10, RGB_PURPLE);
        rgb_matrix_set_color(11, RGB_PURPLE);
        rgb_matrix_set_color(13, RGB_PURPLE);
    }

    if ((!is_keyboard_left() && layer_state_is(_NUM)) ||
        (is_keyboard_left() && layer_state_is(_NUML))) {
        rgb_matrix_set_color(21, 64, 0, 0);

        rgb_matrix_set_color(4, 140, 40, 0);
        rgb_matrix_set_color(5, 140, 40, 0);
        rgb_matrix_set_color(6, 140, 40, 0);
        rgb_matrix_set_color(7, 140, 40, 0);
        rgb_matrix_set_color(9, 140, 40, 0);
        rgb_matrix_set_color(10, 140, 40, 0);
        rgb_matrix_set_color(11, 140, 40, 0);
        rgb_matrix_set_color(12, 140, 40, 0);
        rgb_matrix_set_color(13, 140, 40, 0);
        rgb_matrix_set_color(14, 140, 40, 0);
    }

#   if defined(HOME_ROW_MODS)
    uint8_t mods = mod_config(get_mods());
#   ifndef NO_ACTION_ONESHOT
    mods |= mod_config(get_oneshot_mods());
#   endif

    if (!is_keyboard_left()) {
        mods = mods >> 4;
    }

    uint8_t nav_index = nav_keys_index();

    if (mods & MOD_BIT(KC_LGUI)) {
        rgb_matrix_set_color(5 + 11 * nav_index, RGB_PURPLE);
    }
    if (mods & MOD_BIT(KC_LCTL)) {
        rgb_matrix_set_color(16 - 11 * nav_index, RGB_TEAL);
    }
    if (mods & MOD_BIT(KC_LSFT)) {
        rgb_matrix_set_color(13, RGB_RED);
    }
    if (mods & MOD_BIT(KC_LALT)) {
        rgb_matrix_set_color(10, RGB_SPRINGGREEN);
    }
#   endif


    if (is_keyboard_left()) {
#       if defined(CAPS_WORD_ENABLE)
        if (caps_word_enabled()) {
            rgb_matrix_set_color(9, 64, 0, 0);
        }
#       endif

        if (layer_state_is(_FUNC)) {
            rgb_matrix_set_color(5, 0x47, 0xa7, 0xed);
            rgb_matrix_set_color(10, 0x47, 0xa7, 0xed);
            rgb_matrix_set_color(13, 0x47, 0xa7, 0xed);
            rgb_matrix_set_color(16, 0x47, 0xa7, 0xed);
        }
    } else {
        if (layer_state_is(_CFG)) {
            rgb_matrix_set_color(3, 0xb7, 0x00, 0xff);

            rgb_matrix_set_color(5, RGB_OFF);
            rgb_matrix_set_color(10, RGB_OFF);
            rgb_matrix_set_color(g_led_config.matrix_co[1][3 + default_layer_index()], 255, 255, 255);

            if (nav_keys_index() == 0) {
                rgb_matrix_set_color(g_led_config.matrix_co[5][2], RGB_WHITE);
            } else {
                rgb_matrix_set_color(g_led_config.matrix_co[5][2], RGB_TEAL);
            }
        }

        if (layer_state_is(_FUNC)) {
            rgb_matrix_set_color(4, 0x47, 0xa7, 0xed);
            rgb_matrix_set_color(5, 0x47, 0xa7, 0xed);
            rgb_matrix_set_color(6, 0x47, 0xa7, 0xed);
            rgb_matrix_set_color(9, 0x47, 0xa7, 0xed);
            rgb_matrix_set_color(10, 0x47, 0xa7, 0xed);
            rgb_matrix_set_color(11, 0x47, 0xa7, 0xed);
            rgb_matrix_set_color(12, 0x47, 0xa7, 0xed);
            rgb_matrix_set_color(13, 0x47, 0xa7, 0xed);
            rgb_matrix_set_color(14, 0x47, 0xa7, 0xed);
            rgb_matrix_set_color(15, 0x47, 0xa7, 0xed);
            rgb_matrix_set_color(16, 0x47, 0xa7, 0xed);
            rgb_matrix_set_color(17, 0x47, 0xa7, 0xed);
        }
    }

    return true;
}
#endif

layer_state_t layer_state_set_keymap(layer_state_t state) {
#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)
    rgblight_set_layer_state(0, layer_state_cmp(state, _FN1) || layer_state_cmp(state, _GAMEFN1));
    rgblight_set_layer_state(1, layer_state_cmp(state, _FN2));
    rgblight_set_layer_state(2, layer_state_cmp(state, _AUG));
    rgblight_set_layer_state(3, layer_state_cmp(state, _CFG));
    rgblight_set_layer_state(4, layer_state_cmp(state, _NUM));
    rgblight_set_layer_state(5, layer_state_cmp(state, _FUNC));

    if (layer_state_is(_GAME)) {
        rgblight_enable_noeeprom();
    } else {
        rgblight_reload_from_eeprom();
    }
#endif
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

void keyboard_post_init_keymap() {
#if defined(RGB_MATRIX_ENABLE)
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
    rgb_matrix_enable_noeeprom();
#endif
#if defined(RGBLIGHT_LAYERS)
    rgblight_layers = _rgb_layers;
#endif
}
