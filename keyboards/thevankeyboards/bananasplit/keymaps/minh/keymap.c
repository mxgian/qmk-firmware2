#include QMK_KEYBOARD_H

#define DEFAULT_LAYER 0
#define LAYER_1       1
#define LAYER_2       2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DEFAULT_LAYER] = LAYOUT_base(
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, \
    KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC, KC_BSPC, \
    KC_CAPS,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,   KC_QUOT, KC_ENT, \
    KC_LSPO,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  RSFT_T(KC_SLSH),  KC_UP, _______, \
    KC_LCTL,  KC_LALT,  KC_LGUI, LT(LAYER_1,KC_ENT),      MO(LAYER_1),     LT(LAYER_2, KC_SPC),  KC_RGUI, KC_RCTL,  KC_LEFT, KC_DOWN, KC_RIGHT
  ),

  [LAYER_1] = LAYOUT_base( \
    KC_GRAVE, KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_F11,  KC_F12, \
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU, _______, \
    _______, _______, _______,          _______, _______, _______,          _______, _______, _______, KC_VOLD, KC_MUTE \
  ),
  [LAYER_2] = LAYOUT_base( \
    KC_TILD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU, _______, \
    RESET  , _______, _______,          _______, _______, _______,          _______, _______, _______, KC_VOLD, KC_MUTE \
  ),
};

const uint16_t PROGMEM fn_actions[] = {
};
