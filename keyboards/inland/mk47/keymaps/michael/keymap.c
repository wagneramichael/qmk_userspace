/* Copyright (C) 2023 jonylee@hfd
 *
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

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_planck_mit(KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_QUOT, KC_SLSH, KC_LCTL, MO(4), KC_LALT, KC_LGUI, MO(1), KC_SPC, MO(2), KC_UP, KC_LEFT, KC_DOWN, KC_RGHT),
    [1] = LAYOUT_planck_mit(KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, KC_DEL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TILD, KC_BSLS, KC_HOME, KC_END, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),
    [2] = LAYOUT_planck_mit(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_DEL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_UNDS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_HASH, KC_SLSH, KC_PGUP, KC_PGDN, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),
    [3] = LAYOUT_planck_mit(TO(0), KC_NO, MS_UP, MS_BTN1, MS_WHLU, KC_NO, KC_NO, KC_P7, KC_P8, KC_P9, KC_PSLS, KC_BSPC, KC_NO, MS_LEFT, MS_DOWN, MS_RGHT, MS_WHLD, MS_WHLL, MS_WHLR, KC_P4, KC_P5, KC_P6, KC_PAST, KC_PEQL, KC_NO, KC_NO, KC_NO, MS_BTN1, MS_BTN2, KC_NO, KC_NO, KC_P1, KC_P2, KC_P3, KC_PMNS, KC_PENT, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, TO(0), KC_TRNS, KC_P0, KC_PDOT, KC_PPLS, KC_PCMM),
    [4] = LAYOUT_planck_mit(AC_TOGG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TURBO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO)
};

const uint16_t PROGMEM mouselayercombo[] = {MO(1), MO(2), COMBO_END};
combo_t key_combos[] = {
    COMBO(mouselayercombo, TO(3)),
};

socd_cleaner_t socd_opposing_pairs[] = {
  {{KC_W, KC_S}, SOCD_CLEANER_LAST},
  {{KC_A, KC_D}, SOCD_CLEANER_LAST},
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case 4:
            rgb_matrix_set_color(i, RGB_RED);
            break;
            case 3:
            rgb_matrix_set_color(i, RGB_PURPLE);
            break;
            case 2:
                rgb_matrix_set_color(i, RGB_GREEN);
                break;
            case 1:
                rgb_matrix_set_color(i, RGB_BLUE);
                break;
            default:
                break;
        }
    }
    return false;
};
// clang-format on

