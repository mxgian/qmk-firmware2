/* Copyright 2020 minhg
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [0] = LAYOUT( /* Base */
		KC_ESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,   KC_MINS, KC_EQL,     KC_BSPC,    KC_PGUP,
		LT(1,KC_TAB),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_ENT, KC_PGDN,
		LT(2,KC_TAB),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS,         KC_HOME,
		KC_LSFT, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,   KC_LSFT,   KC_UP,    KC_END,
		KC_LCTL, KC_LALT, KC_LGUI,                           KC_SPC,                     KC_RGUI, MO(1), KC_LALT,        KC_LEFT,KC_DOWN,  KC_RIGHT
	),
    [1] = LAYOUT( /* LAYER 3 */
        KC_ESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,   KC_MINS, KC_EQL,  KC_BSPC,        RESET,
		_______,  KC_Q,    KC_UP,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_LBRC, KC_RBRC,      KC_ENT,   KC_PGDN,
		_______,   KC_LEFT,    KC_DOWN,    KC_RIGHT,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT, KC_SLSH,       KC_HOME,
		KC_LSFT, KC_BSLS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,   KC_LSFT,  KC_UP,     KC_END,
		KC_LCTL, KC_LALT, KC_LGUI,                           KC_SPC,                     KC_RGUI, MO(1), KC_LALT,       KC_LEFT, KC_DOWN,   KC_RIGHT
     ),
    [2] = LAYOUT( /* LAYER 3 */
        KC_ESC, KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,   KC_F11, KC_F12,      KC_DEL,    RESET,
		_______, _______,    KC_UP,  _______,_______, _______, _______, _______, _______, _______, _______, _______, _______,     _______,   KC_PGDN,
		_______, KC_LEFT,  KC_DOWN,    KC_RIGHT,  _______, _______, _______, _______, _______,_______,  _______, _______, _______,    KC_HOME,
		KC_LSFT, _______, _______,     _______,    _______, _______, _______, _______, _______, _______, _______, _______,     KC_LSFT, KC_VOLU,   KC_END,
		KC_LCTL, KC_LALT, KC_LGUI,                           KC_SPC,                     KC_RGUI, MO(1), KC_LALT, KC_LEFT,       KC_VOLD,   KC_MUTE
  )


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
