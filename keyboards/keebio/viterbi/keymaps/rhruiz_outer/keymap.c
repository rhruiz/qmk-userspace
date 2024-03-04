#include QMK_KEYBOARD_H
#include "rhruiz.h"
#include "layouts/keys.h"

#define LAYOUT_ortho_5x14_wrapper(...) LAYOUT_ortho_5x14(__VA_ARGS__)

// clang-format off

#define KC_GGRV RGUI_T(KC_GRV)
#define KC_ALDE RALT_T(KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWER] = LAYOUT_ortho_5x14_wrapper(
 //,--------------------------------------------+--------+--------.  ,--------+--------+--------------------------------------------.
       _______L_QWER_R1_______                  , KC_GRV , KC_MINS,    TG_NUM , KC_EQL ,                  _______R_QWER_R1_______   ,
 //|--------------------------------------------+--------+--------|  |--------+--------+--------------------------------------------+
       _______L_QWER_R2_______                  , KC_TAB , NV_NWIN,    NV_TAN , KC_BSPC,                  _______R_QWER_R2_______   ,
 //|--------------------------------------------+--------+--------|  |--------+--------+--------------------------------------------+
       _______L_QWER_R3_______                  , KC_ESC , KC_PGUP,    NV_BCK , KC_QUOT,                  _______R_QWER_R3_______   ,
 //|--------------------------------------------+--------+--------|  |--------+--------+--------------------------------------------+
       _______L_QWER_R4_______                  , KC_LSFT, KC_PGDN,    KC_EPIP, KC_RSFT,                  _______R_QWER_R4_______   ,
 //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+
     MO_NUM , KC_ESC , KC_TAB , KC_LGUI, MO_LWR , CT_SPC , CT_SPC ,    ST_ENT , ST_ENT , MO_RSE ,  AT_BS , KC_RGUI, KC_DEL , MO_NUM
 //`--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------'
  ),

  [_GAME] = LAYOUT_ortho_5x14(
 //,--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------.
     _______, _______, _______, _______, _______,  KC_6  ,  KC_7  ,    TG_NUM , _______, _______, _______, _______, _______, _______,
 //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+
     _______, _______, _______, _______, _______, _______,  KC_8  ,    _______, _______, _______, _______, _______, _______, _______,
 //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+
     _______, _______, _______, _______, _______, _______,  KC_9  ,    _______, _______, _______, _______, _______, _______, _______,
 //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+
     _______, _______, _______, _______, _______, _______, KC_BSPC,    _______, _______, _______, _______, _______, _______, _______,
 //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+
     _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______
 //`--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------'
  ),

  [_FN1] = LAYOUT_ortho_5x14_wrapper(
 //,--------------------------------------------+--------+--------.  ,--------+--------+--------------------------------------------.
       ________L_LWR_1________                  , KC_ESC , _______,    TG_GAME, _______,                  ________R_LWR_1________   ,
 //|--------------------------------------------+--------+--------|  |--------+--------+--------------------------------------------+
       ________L_LWR_2________                  , KC_TILD, KC_RBRC,    NV_TAP , KC_DEL ,                  ________R_LWR_2________   ,
 //|--------------------------------------------+--------+--------|  |--------+--------+--------------------------------------------+
       ________L_LWR_3________                  , _______, NV_SCTP,    NV_FWD , KC_DQUO,                  ________R_LWR_3________   ,
 //|--------------------------------------------+--------+--------|  |--------+--------+--------------------------------------------+
       ________L_LWR_4________                  , _______, NV_SCBT,    _______, _______,                  ________R_LWR_4________   ,
 //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+
     _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______
 //`--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------'
  ),

  [_FN2] = LAYOUT_ortho_5x14_wrapper(
 //,--------------------------------------------+--------+--------.  ,--------+--------+--------------------------------------------.
        ________L_RSE_1________                 , KC_ESC , KC_F11 ,    KC_F12 , _______,                  ________R_RSE_1________   ,
 //|--------------------------------------------+--------+--------|  |--------+--------+--------------------------------------------+
        ________L_RSE_2________                 , KC_GRV , KC_RBRC,    NV_TAP , KC_DEL ,                  ________R_RSE_2________   ,
 //|--------------------------------------------+--------+--------|  |--------+--------+--------------------------------------------+
        ________L_RSE_3________                 , _______, NV_SCTP,    NV_FWD , KC_DQUO,                  ________R_RSE_3________   ,
 //|--------------------------------------------+--------+--------|  |--------+--------+--------------------------------------------+
        ________L_RSE_4________                 , _______, NV_SCBT,    _______, _______,                  ________R_RSE_4________   ,
 //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+
     _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______
 //`--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------'
  ),

  [_CFG] = LAYOUT_ortho_5x14_wrapper(
 //,--------+--------+--------+--------+--------+--------+--------.  ,---------+-------+--------+--------+--------+--------+--------.
       ________L_CFG_1________                  , _______, _______,    KC_MAKE, _______,                  ________R_CFG_1________   ,
 //|--------------------------------------------+--------+--------|  |--------+--------+--------------------------------------------+
       ________L_CFG_2________                  , RGB_SAD, QK_BOOT,    QK_BOOT, _______,                  ________R_CFG_2________   ,
 //|--------------------------------------------+--------+--------|  |--------+--------+--------------------------------------------+
       ________L_CFG_3________                  , _______, _______,    _______, _______,                  ________R_CFG_3________   ,
 //|--------------------------------------------+--------+--------|  |--------+--------+--------------------------------------------+
       ________L_CFG_4________                  , _______, _______,    _______, _______,                  ________R_CFG_4________   ,
 //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+
     _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______
 //`--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------'
  ),

  [_FUNC] = LAYOUT_ortho_5x14_wrapper(
 //,--------+--------+--------+--------+-------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------.
       ________L_FUN_1________                 , _______, _______,    _______, _______,                  ________R_FUN_1________   ,
 //|--------+--------+-------------------------+--------+--------|  |--------+--------+--------------------------------------------+
       ________L_FUN_2________                 , _______, _______,    _______, _______,                  ________R_FUN_2________   ,
 //|-------------------------------------------+--------+--------|  |--------+--------+--------------------------------------------+
       ________L_FUN_3________                 , _______, _______,    _______, _______,                  ________R_FUN_3________   ,
 //|-------------------------------------------+--------+--------|  |--------+--------+--------------------------------------------+
       ________L_FUN_4________                 , _______, _______,    _______, _______,                  ________R_FUN_4________   ,
 //|-------+--------+--------+--------+-------+---------+--------|  |--------+--------+--------+--------+--------+--------+--------+
    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______
 //`-------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------'
  ),

  [_NUM] = LAYOUT_ortho_5x14_wrapper(
 //,-------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------.
              _____NUMBERS_LEFT_____           , _______, _______,    _______, _______,           _____NUMBERS_RGHT_____           ,
 //|-------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+
    _______,  KC_NO , KC_MS_U,  KC_NO , _______, _______, _______,    _______, _______, _______,  KC_4  ,  KC_5  ,  KC_6  , KC_PLUS,
 //|-------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+
    KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______,    _______, _______, KC_ASTR,  KC_1  ,  KC_2  ,  KC_3  , KC_MINS,
 //|-------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+
    KC_WH_U, _______, _______, _______, _______, _______, _______,    _______, KC_ENT , KC_EQL ,  KC_0  , _______,  KC_UP , _______,
 //|-------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+
    _______, _______, _______, KC_BTN2, _______, KC_BTN1, KC_BTN1,    _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT
 //`-------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------'
  )
};

// clang-format on

layer_state_t layer_state_set_keymap(layer_state_t state) {
    if (state & (1 << _NUM)) {
        gpio_write_pin_low(D5);
        gpio_write_pin_low(B0);
    } else {
        gpio_write_pin_high(D5);
        gpio_write_pin_high(B0);
    }

    return state;
}
