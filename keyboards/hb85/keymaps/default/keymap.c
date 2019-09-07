/* Copyright 2019 'minhg'
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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};
#define _BL 0 //Base layer
#define _FN1 1 //Function layer
/*

 The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 * 8 x 15
 * Physical Layout CA0P
 * Layout:
 *            ┌────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───┐
 *    ________│ESC │ F1  │F2   │F3   │F4   │F5   │F6   │F7   │F8   │F9   │F10  │F11  │F12  │FN │
 *   │        │    │     │     │     │     │     │     │     │     │     │     │     │         │     │     │     │
 *   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─
 *   │  ~  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │   BCKSPC  │ PDIV│ PMLT│PMIN │
 *   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─
 *   │TAB     │ Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  |  \|     │  P7 │ P8  │ P9  │
 *   │        │    │     │     │     │     │     │     │     │     │     │     │     │         │     │     │     │
 *   ├─ ───--─┴── ─┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─---──┼─────┼─────┼─────┼─
 *   │CAPS      │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │ Enter      │  P4 │ P5  │ P6  │
 *   │          │     │     │     │     │     │     │     │     │     │     │     │            │     │     │     │
 *   ├──────--──┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴-----─┬─────┼─────┼─────┼─────┼─
 *   │SHIFT       │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │SHIFT     │ UP  │  P1 │  P2 │  P3 │
 *   │            │     │     │     │     │     │     │     │     │     │     │          │     │     │     │     │
 *   ├───────┬─--─┴-┬─--─┴──┬──┴────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──-----┴─────┬─-───┼─────┼─────┼─
 *           │ALT   │ CTRL  │     SPACE                              │CTRL │WIN│ALT  │LFT|DWN  │RGHT │  P0 │
 *           │      │       │                                        │     │   │     │   │     │     │     │
 *           └─────-┴───────┴────────────────────────────────────────┴─────┴───┴─────┴───┴────-┴─────┴──--─┴─
 *
 *
 *              ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 *   _________ |K0C  │ K0B │ K0A │ K00 │ K01 │ K02 │K03  │K04  │K05  │K06  │K07  │K08  │K09  │K0E  │
 *   │         │     │     │     │     │     │     │     │     │     │     │     │     │     │     │
 *   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─
 *   │ K1E │ K1D │ K1C │ K1B │ K1A │ K10 │ K11 │ K12 │ K13 │ K14 │ K15 │ K16 │ K17 │  K18 K19  │ K59 │ K58 │ K57 │
 *   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─
 *   │K2E     │ K2D│  K2C│ K2B │ K2A │ K20 │K21  │ K22 │ K23 │ K24 │ K25 │ K26 │ K27 |  K28    │ K29 │ K56 │ K55 │
 *   │        │    │     │     │     │     │     │     │     │     │     │     │     │         │     │     │     │
 *   ├─ ───--─┴── ─┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─---──┼─────┼─────┼─────┼─
 *   │K3E       │ K3D │ K3C │ K3B │ K3A │  K30│ K31 │ K32 │ K33 │ K34 │ K35 │ K36 │ K37        │ K39 │ K76 │ K75 │
 *   │          │     │     │     │     │     │     │     │     │     │     │     │            │     │     │     │
 *   ├──────--──┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴-----─┬─────┼─────┼─────┼─────┼─
 *   │K4E         │ K4C │ K4B │ K4A │ K40 │ K41 │ K42 │ K43 │ K44 │ K45 │ K46 │K47       │ K48 │ K49 │ K78 │ K77 │
 *   │            │     │     │     │     │     │     │     │     │     │     │          │     │     │     │     │
 *   ├───────┬─--─┴-┬─--─┴──┬──┴────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─┬──------┴─────┬─-───┼─────┼─────┼─
 *           │K6D   │ K6C   │     K61                                │K64  │K65 │K66 │K67|K68  │K69  │ K79 │
 *           │      │       │                                        │     │    │    │   │     │     │     │
 *           └─────-┴───────┴────────────────────────────────────────┴─────┴─── ┴────┴───┴────-┴──--─┴──--─┴─
 *
 *
 *   empty layer to use as base to add more layers`
 * [0] = LAYOUT(  // Base
  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,  \
  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______,    _______, _______, _______, \
  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,             _______, _______, _______, \
  _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______,               ______,  _______, _______,      \
  _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,                  _______,   _______,    _______, _______, _______,  \
       _______,  _______,                _______,                                          _______, _______, _______, _______,    _______,    _______,  _______       \
  ),
 *
 *
 */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BL] = LAYOUT_CAOP( /* Base */
  KC_ESC,  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  MO(1),  \
  KC_GRV,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_BSPC,  KC_PSLS, KC_PAST, KC_MINS, \
  KC_TAB,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,             KC_P7,   KC_P8,   KC_P9, \
  KC_CAPS, KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,    KC_L,   KC_SCLN, KC_QUOT,         KC_ENT,               KC_P4,   KC_P5,   KC_P6,      \
  KC_LSPO, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH,                  KC_RSPC,    KC_UP,    KC_P1,   KC_P2,   KC_P3,  \
     KC_LCTL,  KC_LGUI,                KC_SPC,                               KC_LCTL, KC_LALT, MO(1), KC_LEFT,   KC_DOWN, KC_RGHT,  KC_P0       \
  ),
  [_FN1] = LAYOUT_CAOP( /* Layer 1 */
  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,  \
  _______,  RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______,  _______, _______, _______, _______,    _______, _______, _______, \
  _______,  BL_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,             _______, _______, _______, \
  _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______,               _______, _______, _______,      \
  _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,                  _______,   KC_VOLU,    _______, _______, _______,  \
       _______,  _______,                _______,                                          _______, _______, _______, _______,    KC_VOLD,    _______, _______       \
  ),

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
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
