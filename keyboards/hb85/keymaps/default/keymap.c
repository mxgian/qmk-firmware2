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
#define _FN2 2 //Function layer
#define _FN3 3 //Function layer

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
  KC_ESC,  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  MO(3),  \
  KC_GRV,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_BSPC,  KC_PSLS, KC_PAST, KC_MINS, \
  LT(2,KC_TAB),  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,             KC_P7,   KC_P8,   KC_P9, \
  LT(2,KC_CAPS), KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,    KC_L,   KC_SCLN, KC_QUOT,         KC_ENT,               KC_P4,   KC_P5,   KC_P6,      \
  KC_LSPO, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH,                  KC_RSPC,    KC_UP,    KC_P1,   KC_P2,   KC_P3,  \
     KC_LCTL,  KC_LGUI,                KC_SPC,                               KC_LCTL, KC_LALT, MO(1), KC_LEFT,   KC_DOWN, KC_RGHT,  KC_P0       \
  ),
  [_FN1] = LAYOUT_CAOP( /* Base */
  KC_ESC,  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  MO(3),  \
  KC_GRV,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_BSPC,  KC_PSLS, KC_PAST, KC_MINS, \
  KC_TAB,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,             KC_P7,   KC_P8,   KC_P9, \
  KC_CAPS, KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,    KC_L,   KC_SCLN, KC_QUOT,         KC_ENT,               KC_P4,   KC_P5,   KC_P6,      \
  KC_LSPO, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH,                  KC_RSPC,    KC_UP,    KC_P1,   KC_P2,   KC_P3,  \
     KC_LCTL,  KC_LGUI,                KC_SPC,                               KC_LCTL, KC_LALT, MO(1), KC_LEFT,   KC_DOWN, KC_RGHT,  KC_P0       \
  ),
  [_FN2] = LAYOUT_CAOP( /* Base */
  KC_ESC,  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  MO(3),  \
  KC_GRV,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_BSPC,  KC_PSLS, KC_PAST, KC_MINS, \
  KC_TRNS,  KC_Q,  KC_UP,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,             KC_P7,   KC_P8,   KC_P9, \
  KC_CAPS, KC_LEFT,  KC_DOWN,  KC_RIGHT,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,    KC_L,   KC_SCLN, KC_QUOT,         KC_ENT,               KC_P4,   KC_P5,   KC_P6,      \
  KC_LSPO, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH,                  KC_RSPC,    KC_UP,    KC_P1,   KC_P2,   KC_P3,  \
     KC_LCTL,  KC_LGUI,                KC_SPC,                               KC_LCTL, KC_LALT, MO(1), KC_LEFT,   KC_DOWN, KC_RGHT,  KC_P0       \
  ),
  [_FN3] = LAYOUT_CAOP( /* Layer 3 */
  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,  \
  _______,  RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______,  _______, _______, _______, _______,    _______, _______, _______, \
  _______,  BL_TOGG,BL_DEC, BL_INC, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,             _______, _______, _______, \
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

void keyboard_post_init_user(void) {
  #ifdef RGBLIGHT_ENABLE
  /*
    // Set up RGB effects on _only_ the first 5 LED (index 4)
    rgblight_set_effect_range(0, 4);
    // Set LED effects to breathing mode in a tealish blue color
    rgblight_sethsv_noeeprom(185, 255, 255);
    //rgblight_mode_noeeprom(RGBLIGHT_EFFECT_BREATHING + 2);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    // Init the first two LEDs to a static color
    setrgb(0, 0, 0, (LED_TYPE *)&led[5]);
    setrgb(0, 0, 0, (LED_TYPE *)&led[6]);
    setrgb(0, 0, 0, (LED_TYPE *)&led[7]);
    setrgb(0, 0, 0, (LED_TYPE *)&led[8]);

    rgblight_set();
    */
  #endif //RGBLIGHT_ENABLE
}

uint32_t layer_state_set_user(uint32_t state){
  #ifdef RGBLIGHT_ENABLE
  /*  uint8_t led0r = 0; uint8_t led0g = 0; uint8_t led0b = 0;
    uint8_t led1r = 0; uint8_t led1g = 0; uint8_t led1b = 0;

    if (layer_state_cmp(state, 1)) {
      led0r = 255;
    }
    if (layer_state_cmp(state, 2)) {
      led1g = 255;
    }

    if (layer_state_cmp(state, 4)) {
      led1b = 255;
    }
    if (layer_state_cmp(state, 5)) {
      led1r = 255;
    }

    //setrgb(led0r, led0g, led0b, (LED_TYPE *)&led[1]);
   // setrgb(led1r, led1g, led1b, (LED_TYPE *)&led[2]);
  //  rgblight_set();
  */
  #endif //RGBLIGHT_ENABLE

  return state;
}
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
