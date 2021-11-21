/* Copyright 2020 Matthew Gilbert <hello+github@mattir.com>
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

enum layers {
  QWERTY = 0,
  LOWER,
  RAISE,
  FUNCS,
  RGBLED
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QWERTY] = LAYOUT(
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
      KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
      KC_LEAD, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_GRV, XXXXXXX, XXXXXXX, KC_MINS, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_QUOT,
      KC_MUTE, KC_LCTL, KC_LGUI, TT(RAISE), SFT_T(KC_SPC), SFT_T(KC_SPC), TT(LOWER), KC_BSPC, KC_LALT, TG(RGBLED)
      ),
  [LOWER] = LAYOUT(
      _______, KC_EXLM, KC_AT, KC_HASH, KC_LCBR, KC_RCBR, _______, _______, _______, _______, _______, _______,
      _______, KC_DLR, KC_PERC, KC_CIRC, KC_LPRN, KC_RPRN, KC_EQL, KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, _______,
      TG(FUNCS), KC_AMPR, _______, _______, KC_LBRC, KC_RBRC, _______, XXXXXXX, XXXXXXX, _______, _______, _______, KC_COMM, KC_DOT, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
      ),
  [RAISE] = LAYOUT(
      _______, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______,
      _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, _______,
      _______, _______, KC_BTN1, KC_BTN3, KC_BTN2, _______, _______, XXXXXXX, XXXXXXX, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, KC_DEL, _______, _______
      ),
  [FUNCS] = LAYOUT(
      _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_PPLS, KC_P7, KC_P8, KC_P9, KC_PAST, _______,
      _______, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_PMNS, KC_P4, KC_P5, KC_P6, KC_PSLS, _______,
      TG(FUNCS), KC_F11, KC_F12, _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______, KC_P0, KC_P1, KC_P2, KC_P3, KC_PDOT, KC_PEQL,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
      ),
  [RGBLED] = LAYOUT(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, RGB_VAI, RGB_HUI, RGB_SAI, RGB_MOD, _______, _______, _______, _______, _______, _______,
      _______, _______, RGB_VAD, RGB_HUD, RGB_SAD, RGB_RMOD, _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______,
      RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, TG(RGBLED)
      ),
};

bool is_cmd_tab_active = false;
uint16_t cmd_tab_timer = 0;

LEADER_EXTERNS();

void matrix_scan_user(void) {
  if (is_cmd_tab_active) {
    if (timer_elapsed(cmd_tab_timer) > 1000) {
      unregister_code(KC_LGUI);
      is_cmd_tab_active = false;
    }
  }

  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_A) {
      tap_code16(SGUI(KC_L));
    }
    SEQ_TWO_KEYS(KC_S, KC_S) {
      tap_code16(SGUI(KC_5));
    }
  }
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_180;
}

static void render_mattir_logo(void) {
  static const char PROGMEM mattir_logo[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x3c, 0xfc, 0xf8, 0xe0,
    0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xe0, 0xc0,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x83, 0x07,
    0x1f, 0x7e, 0xf8, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xfe, 0x3f, 0x1f, 0x7f, 0xff,
    0xfc, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xfc, 0xf8, 0x1c, 0x0f, 0x07, 0x00,
    0x00, 0x00, 0x01, 0x07, 0x1f, 0x7e, 0xf8, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x80, 0xe0, 0xf0, 0xfc, 0x7f, 0x1f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x0f,
    0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xfe, 0xff, 0x3f, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x1f, 0x7f, 0xfc, 0xf0, 0xc0, 0x00, 0x00, 0x80,
    0xe0, 0xf8, 0xfe, 0x3f, 0x0f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x3f, 0xff, 0xfe, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0,
    0xfe, 0xff, 0x7f, 0xfc, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xfc, 0x7f, 0xff, 0xff, 0xe0,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0xe0, 0xe0, 0xe0,
    0x00, 0x00, 0xe0, 0xfe, 0xfe, 0xfe, 0xe0, 0xe0, 0x00, 0xe0, 0xfe, 0xfe, 0xfe, 0xe0, 0x60, 0x00,
    0xe3, 0xe3, 0xe3, 0x00, 0x00, 0x00, 0xe0, 0xe0, 0xe0, 0xc0, 0xe0, 0xe0, 0xe0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xf8, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x1f, 0x3f, 0x7f, 0x1f,
    0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x07, 0xff, 0xff, 0xf8, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff,
    0xff, 0x07, 0x00, 0x01, 0x07, 0x1f, 0x7f, 0xf8, 0xfe, 0x3f, 0x07, 0x01, 0x00, 0x03, 0xff, 0xff,
    0xfc, 0x00, 0x00, 0x00, 0x1e, 0x7f, 0xff, 0xe1, 0xc0, 0xc0, 0xc0, 0xc0, 0xe1, 0xff, 0xff, 0xff,
    0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00,
    0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x80, 0xfc, 0xff, 0x7f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
    0xfe, 0xff, 0xff, 0x1f, 0x7f, 0xfe, 0xf8, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x80, 0xe0, 0xf0, 0xfc, 0x7f, 0x1f, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01,
    0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xe0, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff,
    0xff, 0x3f, 0x00, 0x00, 0x00, 0x01, 0x03, 0x0f, 0x3f, 0xff, 0xfc, 0xf0, 0xc0, 0x80, 0x00, 0xc0,
    0xf0, 0xfc, 0xfe, 0x3f, 0x0f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xf0, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x78, 0xff, 0xef, 0xcf, 0xce, 0xfc, 0x7c, 0x30, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x38, 0x3f, 0x3f, 0x3f, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x3c, 0x3f, 0x3f,
    0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x1f, 0x3f, 0x3f, 0x1f,
    0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x3f, 0x3f, 0x3c, 0x38,
    0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x39, 0x39, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x30,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  };
  oled_write_raw_P(mattir_logo, sizeof(mattir_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
  };
  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
  // QMK Logo and version information
  render_qmk_logo();
  oled_write_P(PSTR("Matt's Kyria\n\n"), false);
  // Host Keyboard Layer Status
  oled_write_P(PSTR("Layer: "), false);
  switch (get_highest_layer(layer_state)) {
    case QWERTY:
      oled_write_P(PSTR("Default\n"), false);
      break;
    case LOWER:
      oled_write_P(PSTR("Lower\n"), false);
      break;
    case RAISE:
      oled_write_P(PSTR("Raise\n"), false);
      break;
    case FUNCS:
      oled_write_P(PSTR("F-keys\n"), false);
      break;
    case RGBLED:
      oled_write_P(PSTR("Underglow\n"), false);
      break;
    default:
      oled_write_P(PSTR("No idea dog\n"), false);
  }
}

void oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status(); // Renders the current keyboard layer
  } else {
    render_mattir_logo();
  }
}
#endif

// Layer-specific encoder knob functions
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { // left knob
    switch (get_highest_layer(layer_state)) {
      case QWERTY: // Volume
        if (clockwise) {
          tap_code(KC_VOLD);
        } else {
          tap_code(KC_VOLU);
        }
        break;
      case LOWER: // Desktop switching
        if (clockwise) {
          tap_code16(C(KC_RIGHT));
        } else {
          tap_code16(C(KC_LEFT));
        }
        break;
      case RAISE: // Mousewheel L/R
        if (clockwise) {
          tap_code(KC_WH_L);
        } else {
          tap_code(KC_WH_R);
        }
        break;
      case RGBLED: // Underglow color
        if (clockwise) {
          rgblight_increase_hue();
        } else {
          rgblight_decrease_hue();
        }
        break;
      default: // No action
        if (clockwise) {
          tap_code(KC_NO);
        } else {
          tap_code(KC_NO);
        }
        break;
    }
  } else if (index == 1) { // right knob
    switch (get_highest_layer(layer_state)) {
      case QWERTY: // Undo / Redo
        if (clockwise) {
          tap_code16(LGUI(KC_Z));
        } else {
          tap_code16(SGUI(KC_Z));
        }
        break;
      case LOWER: // App switching
        if (clockwise) {
          if (!is_cmd_tab_active) {
            is_cmd_tab_active = true;
            register_code(KC_LGUI);
          }
          cmd_tab_timer = timer_read();
          tap_code16(KC_TAB);
        } else {
          tap_code16(S(KC_TAB));
        }
        break;
      case RAISE: // Mouse wheel U/D
        if (clockwise) {
          tap_code(KC_WH_U);
        } else {
          tap_code(KC_WH_D);
        }
        break;
      case RGBLED: // Underglow brightness
        if (clockwise) {
          rgblight_increase_val();
        } else {
          rgblight_decrease_val();
        }
        break;
      default: // No action
        if (clockwise) {
          tap_code(KC_NO);
        } else {
          tap_code(KC_NO);
        }
        break;
    }
  }
    return true;
}
#endif
