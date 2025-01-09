#pragma once

#ifdef HOME_ROW_MODS
#    define HRL(k1, k2, k3, k4, k5) LCTL_T(k1), LSFT_T(k2), LALT_T(k3), LGUI_T(k4), k5
#    define HRR(k1, k2, k3, k4, k5) k1, RGUI_T(k2), RALT_T(k3), RSFT_T(k4), RCTL_T(k5)
#else
#    define HRL(k1, k2, k3, k4, k5) k1, k2, k3, k4, k5
#    define HRR(k1, k2, k3, k4, k5) k1, k2, k3, k4, k5
#endif

// clang-format off
//                                 .--------------------------------------------.
#define _______________________      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
//                                 `--------+--------+--------+--------+--------'

//                                 .--------+--------+--------+--------+--------.
#define _____NUMBERS_LEFT_____        KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5
//                                 |--------+--------+--------+--------+--------|
#define _____NUMBERS_RGHT_____        KC_6  ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0
//                                 |--------+--------+--------+--------+--------|
#define ____FUNCTIONS_LEFT____        KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5
//                                 |--------+--------+--------+--------+--------|
#define ____FUNCTIONS_RGHT____        KC_F6 ,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10
//                                 |--------+--------+--------+--------+--------|
#define _____SYMBOLS_LEFT_____       KC_EXLM,  KC_AT , KC_HASH, KC_DLR , KC_PERC
//                                 |--------+--------+--------+--------+--------|
#define _____SYMBOLS_RGHT_____       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN
//                                 `--------+--------+--------+--------+--------'

//                                 .--------------------------------------------.
#define _______L_QWER_R1_______                _____NUMBERS_LEFT_____
//                                 |--------+--------+--------+--------+--------|
#define _______L_QWER_R2_______       KC_Q  ,  KC_W  ,  KC_E  ,  KC_R  ,  KC_T
//                                 |--------+--------+--------+--------+--------|
#define _______L_QWER_R3_______       KC_A  ,  KC_S  ,  KC_D  ,  KC_F  ,  KC_G
//                                 |--------+--------+--------+--------+--------|
#define _______L_QWER_R4_______       KC_Z  ,  KC_X  ,  KC_C  ,  KC_V  ,  KC_B
//                                 `--------+--------+--------+--------+--------'

//                                 .--------------------------------------------.
#define _______R_QWER_R1_______                _____NUMBERS_RGHT_____
//                                 |--------+--------+--------+--------+--------|
#define _______R_QWER_R2_______       KC_Y  ,  KC_U  ,  KC_I  ,  KC_O  ,  KC_P
//                                 |--------+--------+--------+--------+--------|
#define _______R_QWER_R3_______       KC_H  ,  KC_J  ,  KC_K  ,  KC_L  , KC_SCLN
//                                 |--------+--------+--------+--------+--------|
#define _______R_QWER_R4_______       KC_N  ,  KC_M  , KC_COMM, KC_DOT , KC_SLSH
//                                 `--------+--------+--------+--------+--------'

//                                 .--------------------------------------------.
#define _______L_COLE_R1_______                _____NUMBERS_LEFT_____
//                                 |--------+--------+--------+--------+--------|
#define _______L_COLE_R2_______       KC_Q  ,  KC_W  ,  KC_F  ,  KC_P  ,  KC_G
//                                 |--------+--------+--------+--------+--------|
#define _______L_COLE_R3_______       KC_A  ,  KC_R  ,  KC_S  ,  KC_T  ,  KC_D
//                                 |--------+--------+--------+--------+--------|
#define _______L_COLE_R4_______       KC_Z  ,  KC_X  ,  KC_C  ,  KC_V  ,  KC_B
//                                 `--------+--------+--------+--------+--------'

//                                 .--------------------------------------------.
#define _______R_COLE_R1_______                _____NUMBERS_RGHT_____
//                                 |--------+--------+--------+--------+--------|
#define _______R_COLE_R2_______       KC_J  ,  KC_L  ,  KC_U  ,  KC_Y  , KC_SCLN
//                                 |--------+--------+--------+--------+--------|
#define _______R_COLE_R3_______       KC_H  ,  KC_N  ,  KC_E  ,  KC_I  ,  KC_O
//                                 |--------+--------+--------+--------+--------|
#define _______R_COLE_R4_______       KC_K  ,  KC_M  , KC_COMM, KC_DOT , KC_SLSH
//                                 `--------+--------+--------+--------+--------'

//                                 .--------------------------------------------.
#define _______L_CODH_R1_______                _____NUMBERS_LEFT_____
//                                 |--------+--------+--------+--------+--------|
#define _______L_CODH_R2_______       KC_Q  ,  KC_W  ,  KC_F  ,  KC_P  ,  KC_B
//                                 |--------+--------+--------+--------+--------|
#define _______L_CODH_R3_______       KC_A  ,  KC_R  ,  KC_S  ,  KC_T  ,  KC_G
//                                 |--------+--------+--------+--------+--------|
#define _______L_CODH_R4_______       KC_Z  ,  KC_X  ,  KC_C  ,  KC_D  ,  KC_V
//                                 `--------+--------+--------+--------+--------'

//                                 .--------------------------------------------.
#define _______R_CODH_R1_______                _____NUMBERS_RGHT_____
//                                 |--------+--------+--------+--------+--------|
#define _______R_CODH_R2_______       KC_J  ,  KC_L  ,  KC_U  ,  KC_Y  , KC_SCLN
//                                 |--------+--------+--------+--------+--------|
#define _______R_CODH_R3_______       KC_M  ,  KC_N  ,  KC_E  ,  KC_I  ,  KC_O
//                                 |--------+--------+--------+--------+--------|
#define _______R_CODH_R4_______       KC_K  ,  KC_H  , KC_COMM, KC_DOT , KC_SLSH
//                                 `--------+--------+--------+--------+--------'

//                                 .--------------------------------------------.
#define ________L_LWR_1________                ____FUNCTIONS_LEFT____
//                                 |--------+--------+--------+--------+--------|
#define ________L_LWR_2________      KC_EXLM, KC_LCBR, KC_RCBR, KC_DLR , KC_PERC
//                                 |--------+--------+--------+--------+--------|
#define ________L_LWR_3________      KC_HASH, KC_LBRC, KC_RBRC, KC_MINS, KC_PLUS
//                                 |--------+--------+--------+--------+--------|
#define ________L_LWR_4________       KC_AT , KC_LPRN, KC_RPRN, KC_EQL , KC_CCCP
//                                 `--------+--------+--------+--------+--------'

//                                 .--------------------------------------------.
#define ________R_LWR_1________                 ____FUNCTIONS_RGHT____
//                                 |--------+--------+--------+--------+--------|
#define ________R_LWR_2________      KC_PDIR, KC_EPIP, KC_ASTR, KC_BSLS, _______
//                                 |--------+--------+--------+--------+--------|
#define ________R_LWR_3________      KC_GRV , KC_COLN, KC_PIPE, KC_CIRC, KC_QUOT
//                                 |--------+--------+--------+--------+--------|
#ifdef LOCK_LAYERS
#define ________R_LWR_4________      KC_TILD, KC_AMPR, KC_FARW, KC_ARRW, TO_RSE
#else
#define ________R_LWR_4________      KC_TILD, KC_AMPR, KC_FARW, KC_ARRW, KC_DQUO
#endif
//                                 `--------+--------+--------+--------+--------'

//                                 .--------------------------------------------.
#define ________L_RSE_1________      KC_SCRL, KC_PAUS, NV_MICT, _______, UG_VALD
//                                 |--------+--------+--------+--------+--------|
#define ________L_RSE_2________                _____NUMBERS_LEFT_____
//                                 |--------+--------+--------+--------+--------|
#define ________L_RSE_3________      KC_CTAB, NV_TAP , NV_TAN , KC_TAB , _______
//                                 |--------+--------+--------+--------+--------|
#define ________L_RSE_4________      AS_SPC , _______, CW_TOGG, KC_ESC , KC_CCCP
//                                 `--------+--------+--------+--------+--------'

//                                 .--------------------------------------------.
#define ________R_RSE_1________      UG_VALU, KC_MRWD, KC_MFFD, KC_MPLY, KC_MUTE
//                                 |--------+--------+--------+--------+--------|
#define ________R_RSE_2________                _____NUMBERS_RGHT_____
//                                 |--------+--------+--------+--------+--------|
#define ________R_RSE_3________      OSL_FUN, KC_LEFT, KC_DOWN,  KC_UP , KC_RGHT
//                                 |--------+--------+--------+--------+--------|
#define ________R_RSE_4________      TG_NUM , KC_BSPC, _______, _______, _______
//                                 `--------+--------+--------+--------+--------'

//                                 .--------+--------+--------+--------+--------.
#define ________L_AUG_1________      _______, _______, _______, _______, _______
//                                 |--------+--------+--------+--------+--------|
#define ________L_AUG_2________      _______, _______, NV_SCSH, NV_WSCH, _______
//                                 |--------+--------+--------+--------+--------|
#define ________L_AUG_3________      NV_NWIN, NV_BCK , NV_FWD ,  S_TAB , _______
//                                 |--------+--------+--------+--------+--------|
#define ________L_AUG_4________      KC_MUTE, KC_VOLD, KC_VOLU, KC_EJCT, KC_GRET
//                                 `--------+--------+--------+--------+--------'

//                                 .--------+--------+--------+--------+--------.
#define ________R_AUG_1________      _______, _______, _______, _______, _______
//                                 |--------+--------+--------+--------+--------|
#define ________R_AUG_2________      TG_CFG , NV_BOL , NV_SCBT, NV_SCTP, NV_EOL
//                                 |--------+--------+--------+--------+--------|
#define ________R_AUG_3________      KC_TQUO, NV_WLFT, KC_PGDN, KC_PGUP, NV_WRGH
//                                 |--------+--------+--------+--------+--------|
#define ________R_AUG_4________      KC_K8S , KC_DEL , KC_MRWD, KC_MFFD, KC_MPLY
//                                 `--------+--------+--------+--------+--------'

//                                 .--------+--------+--------+--------+--------.
#define ________L_CFG_1________      KC_SCRL, KC_PAUS, UG_SATD, UG_VALD, UG_HUED
//                                 |--------+--------+--------+--------+--------|
#define ________L_CFG_2________      UG_TOGG, UG_NEXT, UG_SATU, UG_VALU, UG_HUEU
//                                 |--------+--------+--------+--------+--------|
#define ________L_CFG_3________      KC_OLBR, _______, _______, _______, TG_GAME
//                                 |--------+--------+--------+--------+--------|
#define ________L_CFG_4________      _______, _______, _______, _______, QK_BOOT
//                                 `--------+--------+--------+--------+--------'

//                                 .--------+--------+--------+--------+--------.
#define ________R_CFG_1________      _______, _______, _______, _______, _______
//                                 |--------+--------+--------+--------+--------|
#define ________R_CFG_2________      TG_CFG , _______, _______, _______, _______
//                                 |--------+--------+--------+--------+--------|
#define ________R_CFG_3________      KC_LAYO, KC_LAY1, KC_LAY0, KC_NOS , _______
//                                 |--------+--------+--------+--------+--------|
#define ________R_CFG_4________      _______, KC_MAKE, _______, _______, _______
//                                 `--------+--------+--------+--------+--------'

//                                 .--------+--------+--------+--------+--------.
#define ________L_NUM_1________      _______, _______, _______, _______, _______
//                                 |--------+--------+--------+--------+--------|
#define ________L_NUM_2________      _______,  KC_NO ,  MS_UP ,  KC_NO , MS_WHLD
//                                 |--------+--------+--------+--------+---u-----|
#define ________L_NUM_3________      _______, MS_LEFT, MS_DOWN, MS_RGHT, MS_WHLU
//                                 |--------+--------+--------+--------+--------|
#define ________L_NUM_4________      _______, KC_LPRN, KC_RPRN, KC_UNDS, KC_CCCP
//                                 `--------+--------+--------+--------+--------'

//                                 .--------+--------+--------+--------+--------.
#define ________R_NUM_1________      KC_SLSH,  KC_7  ,  KC_8  ,  KC_9  , KC_MINS
//                                 |--------+--------+--------+--------+--------|
#define ________R_NUM_2________      KC_ASTR,  KC_4  ,  KC_5  ,  KC_6  , KC_PLUS
//                                 |--------+--------+--------+--------+--------|
#define ________R_NUM_3________      KC_COMM,  KC_1  ,  KC_2  ,  KC_3  , KC_DOT
//                                 |--------+--------+--------+--------+--------|
#define ________R_NUM_4________      KC_EQL ,  KC_0  , _______, _______, _______
//                                 `--------+--------+--------+--------+--------'

//                                 .--------+--------+--------+--------+--------.
#define ________L_FUN_1________      _______, _______, _______, _______, _______
//                                 |--------+--------+--------+--------+--------|
#define ________L_FUN_2________      _______, _______, _______, _______, KC_NUM
//                                 |--------+--------+--------+--------+--------|
#define ________L_FUN_3________      KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, KC_CAPS
//                                 |--------+--------+--------+--------+--------|
#define ________L_FUN_4________      _______, _______, _______, _______, _______
//                                 `--------+--------+--------+--------+--------'

//                                 .--------+--------+--------+-------+--------.
#define ________R_FUN_1________      _______, _______, _______, _______, _______
//                                 |--------+--------+--------+--------+--------|
#define ________R_FUN_2________      KC_PSCR,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_F12
//                                 |--------+--------+--------+--------+--------|
#define ________R_FUN_3________      KC_SCRL,  KC_F4 ,  KC_F5 ,  KC_F6 , KC_F11
//                                 |--------+--------+--------+--------+--------|
#define ________R_FUN_4________      KC_PAUS,  KC_F1 ,  KC_F2 ,  KC_F3 , KC_F10
//                                 `--------+--------+--------+--------+--------'
// clang-format on
