#include QMK_KEYBOARD_H
#include "rhruiz.h"

#define REVERSE_FIVE(K1, K2, K3, K4, K5) K5, K2, K3, K4, K1
#define REV5(...) REVERSE_FIVE(__VA_ARGS__)

#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)
const rgblight_segment_t PROGMEM fn1_colors[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, LWR_HSV});
const rgblight_segment_t PROGMEM fn2_colors[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, RSE_HSV});
const rgblight_segment_t PROGMEM aug_colors[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, AUG_HSV});
const rgblight_segment_t PROGMEM cfg_colors[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, CFG_HSV});
const rgblight_segment_t PROGMEM num_colors[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, NUM_HSV});
const rgblight_segment_t PROGMEM fun_colors[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, FUN_HSV});
const rgblight_segment_t PROGMEM caps_colors[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, CAPS_HSV});
const rgblight_segment_t PROGMEM qwerty_colors[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, QWERTY_HSV});
const rgblight_segment_t PROGMEM colemak_dh_colors[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, COLEMAK_HSV});
const rgblight_segment_t PROGMEM mac_colors[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, MAC_HSV});
const rgblight_segment_t PROGMEM win_colors[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, WIN_HSV});

const rgblight_segment_t* const PROGMEM _rgb_layers[] = RGBLIGHT_LAYERS_LIST(fn1_colors, fn2_colors, aug_colors, cfg_colors, num_colors, fun_colors, caps_colors, qwerty_colors, colemak_dh_colors, mac_colors, win_colors);
#endif

// clang-format off
#define LAYOUT_base_wrapper(...) LAYOUT_base(__VA_ARGS__)
#define LAYOUT_split_3x5_3_wrapper(...) LAYOUT_split_3x5_3(__VA_ARGS__)

#define LAYOUT_base( \
    L01, L02, L03, L04, L05, R01, R02, R03, R04, R05, \
    L11, L12, L13, L14, L15, R11, R12, R13, R14, R15, \
    L21, L22, L23, L24, L25, R21, R22, R23, R24, R25, \
    ENC \
  ) \
  LAYOUT_split_3x5_3_wrapper( \
/*  ,-----------------------------.     ,-----------------------------.*/ \
        L01  , L02, L03, L04, L05 ,         R01  , R02, R03, R04, R05 , \
/*  |--------+----+----+----+-----|     |--------+----+----+-----+----|*/ \
      HRL(L11, L12, L13, L14, L15),       HRR(R11, R12, R13, R14, R15), \
/*  |--------+----+----+----+-----'     `--------+----+----+----+-----|*/ \
        L21  , L22, L23, L24, L25 ,         R21  , R22, R23, R24, R25 , \
/*  `-----------------------------|     |-----------------------------'*/ \
                                    ENC,                                \
         KC_LGUI, MO_LWR , CT_SPC ,       ST_ENT , MO_RSE , KC_RALT     \
/*     `--------+--------+--------'     `--------+--------+--------'   */ \
  )

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWER] = LAYOUT_base_wrapper(
      _______L_QWER_R2_______, _______R_QWER_R2_______,
      _______L_QWER_R3_______, _______R_QWER_R3_______,
      _______L_QWER_R4_______, _______R_QWER_R4_______,
      KC_MPLY
  ),

  [_CODH] = LAYOUT_base_wrapper(
      _______L_CODH_R2_______, _______R_COLE_R2_______,
      _______L_CODH_R3_______, _______R_COLE_R3_______,
      _______L_CODH_R4_______, _______R_COLE_R4_______,
      KC_MPLY
  ),

  [_GAME] = LAYOUT_split_3x5_3_wrapper(
//,--------------------------.  ,--------------------------.
     _______L_QWER_R2_______ ,     _______R_QWER_R2_______ ,
//|--------------------------|  |--------------------------|
     _______L_QWER_R3_______ ,     _______R_QWER_R3_______ ,
//|--------------------------|  |--------------------------|
     _______L_QWER_R4_______ ,     _______R_QWER_R4_______ ,
//|--------------------------|  |--------------------------|
                             KC_MPLY,
     GT_BS ,OSL_GLWR, ST_SPC ,    ST_ENT , MO_RSE ,  AT_BS
//`--------+--------+--------'  `--------+--------+--------'
    ),

  [_GAMEFN1] = LAYOUT_split_3x5_3_wrapper(
//,--------------------------.  ,--------------------------------------------.
     _____NUMBERS_LEFT_____  ,    _______, _______,  KC_UP , _______, _______,
//|--------------------------|  |--------------------------------------------|
     _____NUMBERS_RGHT_____  ,    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,
//|--------------------------|  |--------------------------------------------|
     ____FUNCTIONS_LEFT____  ,    _______, _______,  KC_LT ,  KC_GT , KC_QUES,
//|--------------------------|  |--------------------------------------------'
                             KC_MPLY,
    _______, _______, KC_LSFT,    _______, _______, _______
//`--------+--------+--------'  `--------+--------+--------'
    ),

  [_FN1] = LAYOUT_split_3x5_3_wrapper(
//,--------------------------.  ,--------------------------.
     ________L_LWR_2________ ,     ________R_LWR_2________ ,
//|--------------------------|  |--------------------------|
     ________L_LWR_3________ ,     ________R_LWR_3________ ,
//|--------------------------|  |--------------------------|
     ________L_LWR_4________ ,     ________R_LWR_4________ ,
//|--------------------------|  |--------------------------|
                             KC_MUTE,
    _______, _______, _______,    _______, _______, _______
//`--------+--------+--------'  `--------+--------+--------'
  ),

  [_FN2] = LAYOUT_split_3x5_3_wrapper(
//,--------------------------.  ,--------------------------.
     ________L_RSE_2________ ,     ________R_RSE_2________ ,
//|--------------------------|  |--------------------------|
     ________L_RSE_3________ ,     ________R_RSE_3________ ,
//|--------------------------|  |--------------------------|
     ________L_RSE_4________ ,     ________R_RSE_4________ ,
//|--------------------------|  |--------------------------|
                             KC_MPLY,
    _______, _______, _______,    _______, _______, _______
//`--------------------------'  `--------------------------'
),

  [_AUG] = LAYOUT_split_3x5_3_wrapper(
//,--------------------------.  ,--------------------------.
     ________L_AUG_2________ ,     ________R_AUG_2________ ,
//|--------------------------|  |--------------------------|
     ________L_AUG_3________ ,     ________R_AUG_3________ ,
//|--------------------------|  |--------------------------|
     ________L_AUG_4________ ,     ________R_AUG_4________ ,
//`--------------------------'  `--------------------------|
                             KC_MPLY,
    _______, _______, _______,    _______, _______, _______
//`--------+--------+--------'  `--------+--------+--------'
),

  [_CFG] = LAYOUT_split_3x5_3_wrapper(
//,--------------------------.  ,--------------------------.
     ________L_CFG_2________ ,     ________R_CFG_2________ ,
//|--------------------------|  |--------------------------|
     ________L_CFG_3________ ,     ________R_CFG_3________ ,
//|--------------------------|  |--------------------------|
     ________L_CFG_4________ ,     ________R_CFG_4________ ,
//`--------------------------|  |--------------------------|
                             QK_BOOT,
    _______, _______, _______,    _______, _______, _______
//`--------+--------+--------'  `--------+--------+--------'
  ),

  [_NUM] = LAYOUT_split_3x5_3_wrapper(
//,--------------------------.  ,--------------------------.
     ________L_NUM_2________ ,     ________R_NUM_1________ ,
//|--------------------------|  |--------------------------|
     ________L_NUM_3________ ,     ________R_NUM_2________ ,
//|--------------------------|  |--------------------------|
     ________L_NUM_4________ ,     ________R_NUM_3________ ,
//|--------------------------|  |--------------------------|
                             TG_NUM,
    MS_BTN2, _______, MS_BTN1,    _______,LT_RSE_0, AT_TAB
//`--------+--------+--------'  `--------+--------+--------'
    ),

  [_NUML] = LAYOUT_split_3x5_3_wrapper(
//,--------------------------------.  ,--------------------------------.
     REV5(________R_NUM_1________) ,     REV5(________L_NUM_2________) ,
//|--------------------------------|  |--------------------------------|
     REV5(________R_NUM_2________) ,     REV5(________L_NUM_3________) ,
//|--------------------------------'  |--------------------------------|
     REV5(________R_NUM_3________) ,     REV5(________L_NUM_4________) ,
//`--------------------------------|  |--------------------------------'
                                  TG_NUML,
           GT_BS ,LT_LWR_0, _______,    MS_BTN1, _______, MS_BTN2
//      `--------+--------+--------'  `--------+--------+--------'
    ),

  [_FUNC] = LAYOUT_split_3x5_3_wrapper(
//,--------------------------.  ,--------------------------.
     ________L_FUN_2________ ,     ________R_FUN_2________ ,
//|--------------------------|  |--------------------------|
     ________L_FUN_3________ ,     ________R_FUN_3________ ,
//|--------------------------|  |--------------------------|
     ________L_FUN_4________ ,     ________R_FUN_4________ ,
//|--------------------------|  |--------------------------|
                              KC_MPLY,
    _______, _______, _______,    _______, _______, _______
//`--------+--------+--------'  `--------+--------+--------'
  ),

  /* templates
  [_LAYER] = LAYOUT_split_3x5_3(
//,--------------------------------------------.  ,--------------------------------------------.
    _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
//|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
//|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
//`--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------'
                      _______, _______, _______,    _______, _______, _______
//                  `--------+--------+--------'  `--------+--------+--------'
  ),
  */
};
// clang-format on

#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)
void housekeeping_task_keymap(void) {
    rgblight_set_layer_state(6, is_caps_word_on());
}

layer_state_t layer_state_set_keymap(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _FN1) || layer_state_cmp(state, _GAMEFN1));
    rgblight_set_layer_state(1, layer_state_cmp(state, _FN2));
    rgblight_set_layer_state(2, layer_state_cmp(state, _AUG));
    rgblight_set_layer_state(3, layer_state_cmp(state, _CFG));
    rgblight_set_layer_state(4, layer_state_cmp(state, _NUM));
    rgblight_set_layer_state(5, layer_state_cmp(state, _FUNC));

    if (!layer_state_is(_GAME) && layer_state_cmp(state, _GAME)) {
        rgblight_enable_noeeprom();
    }

    if (layer_state_is(_GAME) && !layer_state_cmp(state, _GAME)) {
        rgblight_reload_from_eeprom();
    }

    return state;
}

void keyboard_post_init_keymap() {
    rgblight_layers = _rgb_layers;
}
#endif

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    if (layer_state_is(_CFG)) {
        if (!record->event.pressed) {
            switch(keycode) {
#ifdef RGBLIGHT_LAYERS
                case KC_LAY0:
                case KC_LAY1:
                    rgblight_blink_layer_repeat(default_layer_index() + 7, 200, 2);
                    break;

                case KC_NOS:
                    rgblight_blink_layer_repeat(nav_keys_index() + 9, 200, 2);
                    break;
#endif
            }
        }
    }

    return true;
}


#ifdef ENCODER_ENABLE
#    ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWER]    = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [_CODH]    = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [_GAME]    = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_GAMEFN1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_FN1]     = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_FN2]     = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_AUG]     = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [_CFG]     = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_NUM]     = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [_NUML]    = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [_FUNC]    = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};
#    endif
#    ifndef ENCODER_MAP_ENABLE
bool encoder_update_keymap(uint8_t _index, bool clockwise) {
    switch (get_highest_layer(default_layer_state)) {
        case _QWER:
        case _CODH:
        case _GAME:
        case _GAMEFN1:
        case _FN1:
        case _FN2:
        case _AUG:
        case _FUNC:
            break;
        case _CFG:
            if (clockwise) {
                tap_code(KC_VOLU);
                return false;
            } else {
                tap_code(KC_VOLD);
                return false;
            }
        case _NUM:
        case _NUML:
            if (clockwise) {
                tap_code(KC_PGDN);
                return false;
            } else {
                tap_code(KC_PGUP);
                return false;
            }
        default:
            break;
    }

    return true;
}
#    endif
#endif
