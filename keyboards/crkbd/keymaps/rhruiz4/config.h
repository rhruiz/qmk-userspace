/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define BASE_LAYERS _QWER, _CODH

#if defined(QMK_MCU_ATMEGA32U4)
#    define PRO_MICRO
#    define BLINK_LED_PIN B0
#    define EE_HANDS
#endif

#ifdef OLED_ENABLE
#    define OLED_BRIGHTNESS 8
#endif

#if defined(CONVERT_TO_PROMICRO_RP2040) && defined(RGBLIGHT_ENABLE)
#   define RGBLIGHT_EFFECT_RAINBOW_MOOD
#   undef RGB_DI_PIN
#   undef RGBLIGHT_LED_COUNT
#   define RGBLIGHT_LED_COUNT 1
#endif

#if defined(RGBLIGHT_ENABLE)
#    define RGBLIGHT_LAYERS
#    define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#    define RGBLIGHT_LAYER_BLINK
#    define RGBLIGHT_LAYERS_RETAIN_VAL
#    define RGBLIGHT_MAX_LAYERS 11
#endif

// bootmagic

#define BOOTMAGIC_ROW 0
#define BOOTMAGIC_COLUMN 1

// bootloader

#define QMK_ESC_OUTPUT F4  // usually COL
#define QMK_ESC_INPUT D4   // usually ROW
#define QMK_LED D5
#define QMK_SPEAKER B0

#ifdef AUDIO_ENABLE
#    define B5_AUDIO
#    define AUDIO_CLICKY
#    define STARTUP_SONG SONG(MARIO_MUSHROOM);
/* #    define STARTUP_SONG SONG(TO_BOLDLY_GO); */
#endif

#ifdef THUMBSTICK_ENABLE
#    define THUMBSTICK_FLIP_X
#    define THUMBSTICK_PIN_X B5
#    define THUMBSTICK_PIN_Y B6
#endif
