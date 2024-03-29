/*
Copyright 2019 rhruiz <rhruiz@gmail.com>

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

/* Select hand configuration */

#define EE_HANDS

/* #define SWAP_HANDS_ENABLE */


#undef RGBLIGHT_LED_COUNT
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_LED_COUNT 12
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

#define NO_ACTION_ONESHOT

// bootmagic

#define BOOTMAGIC_ROW 0
#define BOOTMAGIC_COLUMN 1

// bootloader

#ifdef KEYBOARD_keebio_viterbi_rev1
#define QMK_ESC_OUTPUT F5 // usually COL
#endif

#ifdef KEYBOARD_keebio_viterbi_rev2
#define QMK_ESC_OUTPUT F4 // usually COL
#endif

#define QMK_ESC_INPUT D4 // usually ROW
#define QMK_LED D5
#define QMK_SPEAKER B0
