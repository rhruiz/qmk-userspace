/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "rhruiz.h"

#ifdef RGBLIGHT_LAYERS
const rgblight_segment_t PROGMEM fn1_colors[] = RGBLIGHT_LAYER_SEGMENTS({7, 7, LWR_HSV});

const rgblight_segment_t PROGMEM fn2_colors[] = RGBLIGHT_LAYER_SEGMENTS({7, 7, RSE_HSV});

const rgblight_segment_t PROGMEM cfg_colors[] = RGBLIGHT_LAYER_SEGMENTS({7, 7, CFG_HSV});

const rgblight_segment_t PROGMEM num_colors[] = RGBLIGHT_LAYER_SEGMENTS({7, 7, NUM_HSV});

const rgblight_segment_t PROGMEM game_colors[] = RGBLIGHT_LAYER_SEGMENTS({7, 7, 148, 255, 255});

const rgblight_segment_t PROGMEM aug_colors[] = RGBLIGHT_LAYER_SEGMENTS({7, 7, AUG_HSV});

const rgblight_segment_t* const PROGMEM _rgb_layers[] = RGBLIGHT_LAYERS_LIST(fn1_colors, fn2_colors, cfg_colors, num_colors, game_colors, aug_colors);
#endif

layer_state_t layer_state_set_keymap(layer_state_t state) {
#ifdef RGBLIGHT_LAYERS
    rgblight_set_layer_state(0, layer_state_cmp(state, _FN1));
    rgblight_set_layer_state(1, layer_state_cmp(state, _FN2));
    rgblight_set_layer_state(2, layer_state_cmp(state, _CFG));
    rgblight_set_layer_state(3, layer_state_cmp(state, _NUM));
    rgblight_set_layer_state(4, layer_state_cmp(state, _GAME));
    rgblight_set_layer_state(5, layer_state_cmp(state, _AUG));
#endif

    return state;
}

#ifdef RGBLIGHT_LAYERS
void keyboard_post_init_keymap(void) {
    rgblight_layers = _rgb_layers;
}
#endif

#include "layouts/ortho_5x14.c"
