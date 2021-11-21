/* Copyright 2020 Worldspawn <mcmancuso@gmail.com>
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_stagger(
        KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_DEL, KC_BSPC, KC_MUTE,
        LT(3, KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_SLSH), KC_UP,
        KC_LCTL, KC_LALT, KC_LGUI, LT(2, KC_BSPC), LT(1, KC_SPC),    KC_RGUI, MO(4), KC_LEFT, KC_DOWN, KC_RIGHT
    ),

    [1] = LAYOUT_stagger(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_RBRC, KC_BSLS, RGB_MOD,
        KC_TRNS, KC_MINS, KC_EQL,  KC_SCLN, KC_QUOT, KC_TRNS, KC_LEFT, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_QUOT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR,  KC_TRNS, KC_PGUP,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, MO(3),  KC_HOME, KC_PGDN, KC_END
    ),

    [2] = LAYOUT_stagger(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F12, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_UNDS, KC_PLUS, KC_COLN, KC_DQUO, KC_TRNS,     KC_HOME, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_DQUO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_SAD, RGB_SAI, KC_TRNS, RGB_VAI,
        KC_TRNS, KC_TRNS, KC_TRNS, MO(3), KC_TRNS, KC_TRNS, KC_TRNS, RGB_HUD, RGB_VAD, RGB_HUI
    ),

    [3] = LAYOUT_stagger(
        KC_TRNS, KC_TRNS, KC_UP,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET, RGB_MOD,
        KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [4] = LAYOUT_stagger(
        KC_TRNS, RGB_TOG, RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

void matrix_init_user(void) {
  // set  LED 1 to output and low
  setPinOutput(B5);
  writePinLow(B5);
  // set LED 2 to output and low
  setPinOutput(B6);
  writePinLow(B6);
  // set LED 3 to output and low
  setPinOutput(B7);
  writePinLow(B7);
}

layer_state_t layer_state_set_user(layer_state_t state) {
      if (state & (1<<1)) {
    writePinHigh(B5);
    } else {
        writePinLow(B5);
    }
    if (state & (1<<2)) {
    writePinHigh(B6);
    } else {
        writePinLow(B6);
    }
    if (state & (1<<3)) {
    writePinHigh(B7);
    } else {
        writePinLow(B7);
    }
    return state;

}

//bool led_update_user(led_t led_state) {
 //   writePin(B5, led_state.caps_lock);
 //   return false;
//}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}

