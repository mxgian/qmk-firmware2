/* Copyright 2018 Josh Hinnebusch

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

  [0] = LAYOUT_all(   //base layer
    KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,     KC_F11,     KC_F12,                  KC_F13, KC_F14, MO(2),
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,    KC_EQL,     KC_BSPC,   KC_BSPC,      KC_INS,  KC_HOME, KC_PGUP,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,    KC_RBRC,    KC_BSLS,                 KC_DEL,  KC_END,  KC_PGDN,
    MO(1), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,    KC_NUHS,    KC_ENT,
    KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,    KC_RSFT,    MO(1),                          KC_UP,
    KC_LCTL, KC_LGUI, KC_LGUI,                   KC_SPC,                                      KC_RALT,  KC_RALT,    MO(1),      MO(1),                 KC_LEFT, KC_DOWN, KC_RIGHT),

  [1] = LAYOUT_all(    // punc/nav layer
    KC_TRNS, KC_TRNS, BL_TOGG, BL_DEC,  BL_INC, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,          RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI,                        BL_TOGG, BL_DEC,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_VOLU,
    KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, RESET,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                        KC_MPLY, KC_MNXT, KC_VOLD,
    KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

   [2] = LAYOUT_all(  // adjustment layer
    KC_TRNS, KC_TRNS, BL_TOGG, BL_DEC,  BL_INC, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,          RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI,                         RESET, BL_DEC,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_VOLU,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                        KC_MPLY, KC_MNXT, KC_VOLD,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};
//this manipulates the RGB leds, the ESC and PAUSE keys RGB HALOs are tied to the RGB strip
// PAUSE is LED#25-28 and ESC is LED#29-32
void keyboard_post_init_user(void) {
  #ifdef RGBLIGHT_ENABLE
    // Set up RGB effects on _only_ the LED# 1-24, which is index 0-23
    rgblight_set_effect_range(0, 24);
    // Set LED effects to breathing mode in a tealish blue color
    rgblight_sethsv_noeeprom(185, 255, 255);
    rgblight_mode_noeeprom(RGBLIGHT_EFFECT_BREATHING + 2);

    // Init the HALos to LEDs to a static color
    //rgblight_set_effect_range(23, 4);
    // Set LED effects to breathing mode in a tealish blue color
    //rgblight_sethsv_noeeprom(185, 255, 255);
    //rgblight_mode_noeeprom(RGBLIGHT_EFFECT_BREATHING + 2);
    setrgb(185, 255, 255, (LED_TYPE *)&led[24]);
    setrgb(185, 255, 255, (LED_TYPE *)&led[25]);
    setrgb(185, 255, 255, (LED_TYPE *)&led[26]);
    setrgb(185, 255, 255, (LED_TYPE *)&led[27]);

    //2nd ESC key
    //rgblight_set_effect_range(27, 4);
    // Set LED effects to breathing mode in a tealish blue color
    //rgblight_sethsv_noeeprom(185, 255, 255);
    //rgblight_mode_noeeprom(RGBLIGHT_EFFECT_BREATHING + 2);


    rgblight_set();


}
 #endif //RGBLIGHT_ENABLE

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_init_ports(void) {
  DDRD |= (1<<5); // OUT
  DDRE |= (1<<6); // OUT
}

void led_set_user(uint8_t usb_led) {

  if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
    DDRD |= (1 << 5); PORTD &= ~(1 << 5);
  } else {
    DDRD &= ~(1 << 5); PORTD &= ~(1 << 5);
  }

  if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
    DDRE |= (1 << 6); PORTE &= ~(1 << 6);
  } else {
    DDRE &= ~(1 << 6); PORTE &= ~(1 << 6);
  }

}
