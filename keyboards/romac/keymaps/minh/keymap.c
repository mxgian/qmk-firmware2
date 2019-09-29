/* Copyright 2018 Jack Humbert
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

/*
avrdude -c usbtiny -p m32u4  -U flash:w:"romac_minh_production.hex":a -U lfuse:w:0x5E:m -U hfuse:w:0xD9:m -U efuse:w:0xC3:m -U lock:w:0x3F:m

  */

#include QMK_KEYBOARD_H

#define _BASE 0
#define _FN1 1
#define _FN2 2
#define _FN3 2


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE] = LAYOUT(
		KC_VOLU,  RGB_TOG,  KC_PGUP, \
		KC_VOLD,  KC_UP,    KC_PGDN, \
		KC_LEFT,  KC_DOWN,  KC_RIGHT, \
		TG(_FN1), LT(_FN2,KC_SPC), LT(_FN3,KC_ENT) \
	),

	[_FN1] = LAYOUT(
		KC_7, KC_8, KC_9, \
		KC_4, KC_5, KC_6, \
		KC_1, KC_2, KC_3, \
		KC_TRNS, KC_0, KC_ENT \

	),
    [_FN2] = LAYOUT(
		KC_PPLS, KC_PMNS, KC_BSPC, \
		KC_PAST, KC_PSLS, KC_PENT, \
		KC_PCMM, KC_PDOT, KC_PEQL, \
		KC_TRNS, KC_SPC, KC_DEL \

	),
    [_FN3] = LAYOUT(
		KC_VOLU, RGB_TOG, RGB_HUI, \
		KC_VOLD, RGB_MOD, RGB_HUD, \
		KC_MUTE, KC_2,    RGB_VAI, \
		KC_TRNS, KC_TRNS, RGB_VAD \

	)
};
void keyboard_pre_init_user(void) {
// Call the keyboard pre init code.
// Set our LED pins as output.
// Pro Micro LEDs are active low.
setPinOutput(B0);
setPinOutput(D5);
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
uint8_t layer = biton32(layer_state);
switch (layer) {
case 0:
// LED 00
writePinHigh(B0);
writePinHigh(D5);
break;
case 1:
// LED 01
writePinHigh(B0);
writePinLow(D5);
break;
case 2:
// LED 10
writePinLow(B0);
writePinHigh(D5);
break;
case 3:
// LED 11
writePinLow(B0);
writePinLow(D5);
break;
}
};

