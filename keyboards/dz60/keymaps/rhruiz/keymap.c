#include QMK_KEYBOARD_H

#include "rhruiz.h"
#define KC__FN1 MO(_FN1)
#define KC__FN2 MO(_FN2)
#define _DELFN1 LT(_FN1, KC_DEL)
#define _DELFN2 LT(_FN2, KC_DEL)

enum rhruiz_keys { KC_KBVSN = SAFE_RANGE };

#ifdef RGBLIGHT_LAYERS
const rgblight_segment_t PROGMEM fn1_colors[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, 127, 255, 255}, {7, 1, LWR_HSV});
const rgblight_segment_t PROGMEM fn2_colors[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, 21, 255, 255}, {7, 1, RSE_HSV});
const rgblight_segment_t PROGMEM aug_colors[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, 85, 255, 255}, {7, 1, AUG_HSV});
const rgblight_segment_t PROGMEM cfg_colors[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, 201, 255, 255}, {7, 1, CFG_HSV});

const rgblight_segment_t* const PROGMEM _rgb_layers[] = RGBLIGHT_LAYERS_LIST(fn1_colors, fn2_colors, aug_colors, cfg_colors);
#endif

// clang-format off

#define KC_CSPC LCTL_T(KC_SPACE)
#define CLLEFT MT(MOD_RGUI, KC_LEFT)
#define CLDOWN MT(MOD_RCTL, KC_DOWN)
#define CLUP MT(MOD_RSFT, KC_UP)
#define CLRIGHT LT(_NUM, KC_RIGHT)

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWER] = LAYOUT_wrapper(
		KC_GRV ,   _______L_QWER_R1_______, _______R_QWER_R1_______,  KC_MINS,  KC_EQL,   KC_BSLS,   KC_PIPE,
		KC_TAB ,   _______L_QWER_R2_______, _______R_QWER_R2_______,  KC_LBRC,  KC_RBRC,  KC_BSPC,
		CT_ESC ,   _______L_QWER_R3_______, _______R_QWER_R3_______,  KC_QUOT,  KC_ENT,
		KC_LSFT,   KC_NO,    _______L_QWER_R4_______, _______R_QWER_R4_______,  CLUP,     MO_RSE ,
		MO_LWR ,   KC_LALT,  KC_LGUI,  CT_SPC , MO_LWR ,  LT_RSE_ENT,  AT_BS  , CLLEFT,  KC_NO,  CLDOWN,   CLRIGHT
  ),

  [_NUM] = LAYOUT(
		_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
		_______,  MS_BTN1,   MS_UP ,  MS_BTN2,  MS_ACL0,  MS_ACL1,  MS_ACL2,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
		_______,  MS_LEFT,  MS_DOWN,  MS_RGHT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
		_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
		_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  ),

  [_FN1] = LAYOUT_wrapper(
		KC_GRV ,    ________L_LWR_1________  ,     ________R_LWR_1________  ,  KC_F11 ,  KC_F12 ,  _______,  KC_INS ,
		KC_CAPS,    ________L_LWR_2________  ,     ________R_LWR_2________  ,  _______,  _______,  KC_DEL ,
		_______,    ________L_LWR_3________  ,     ________R_LWR_3________  ,  _______,  KC_PENT,
		_______,  _______,  ________L_LWR_4________  ,     ________R_LWR_3________  ,  _______,  _______,
		_______,  _______,  _______,  _______,  _______,  _DELFN2,  _______,  _______,  _______,  _______,  _______
  ),

  [_FN2] = LAYOUT_wrapper(
		KC_GRV ,  ________L_RSE_2________, ________R_RSE_1________, KC_VOLD, KC_VOLU, _______, _______,
		KC_CAPS,  ________L_RSE_2________, ________R_RSE_2________, _______, _______, _______,
		_______,  ________L_RSE_3________, ________R_RSE_3________, _______, KC_PENT,
		_______,  _______, ________L_RSE_4________, ________R_RSE_4________, _______, _______,
		_______,  _______, _______, _______, _______, _DELFN1,  _______, _______, _______, _______, _______
  ),

  [_AUG] = LAYOUT_wrapper(
		_______, ________L_AUG_1________, ________R_AUG_1________, _______, _______, _______, _______,
		KC_CAPS, ________L_AUG_2________, ________R_AUG_2________, _______, _______, _______,
		_______, ________L_AUG_3________, ________R_AUG_3________, _______, KC_PENT,
		_______, _______, ________L_AUG_4________, ________R_AUG_4________, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_CFG] = LAYOUT_wrapper(
		_______, ________L_CFG_1________,                     ________R_CFG_1________, UG_SPDD, UG_SPDU, KC_MAKE, KC_KBVSN,
		_______, ________L_CFG_2________,                     ________R_CFG_2________, _______, _______, QK_BOOT,
		_______, ________L_CFG_3________,                     ________R_CFG_3________, _______, _______,
		_______, _______, BL_TOGG, BL_STEP, BL_BRTG, _______, QK_BOOT,  ________R_CFG_4________, _______, _______,
		_______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,  _______
  ),
};

// clang-format on

layer_state_t layer_state_set_keymap(layer_state_t state) {
#ifdef RGBLIGHT_LAYERS
    rgblight_set_layer_state(0, layer_state_cmp(state, _FN1));
    rgblight_set_layer_state(1, layer_state_cmp(state, _FN2));
    rgblight_set_layer_state(2, layer_state_cmp(state, _AUG));
    rgblight_set_layer_state(3, layer_state_cmp(state, _CFG));
#endif

    return state;
}

void keyboard_post_init_keymap(void) {
#ifdef RGBLIGHT_LAYERS
    rgblight_layers = _rgb_layers;
#endif
}
