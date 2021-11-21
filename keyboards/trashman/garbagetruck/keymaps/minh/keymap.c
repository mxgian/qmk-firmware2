#include QMK_KEYBOARD_H

enum {
  TD_MINS_EQL = 0,
  TD_9_LBRC,
  TD_0_RBRC,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_MINS_EQL] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_EQL),
  [TD_9_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_LBRC),
  [TD_0_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_RBRC)
};

enum custom_keycodes {
  M_IME = SAFE_RANGE
};

#define KC_LSZ LSFT_T(KC_Z)
#define KC_RSSL LSFT_T(KC_SLSH)
#define KC_LCTF LCTL_T(KC_F)
#define KC_RCTJ RCTL_T(KC_J)
#define KC_LGD LGUI_T(KC_D)
#define KC_RGK RGUI_T(KC_K)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_GESC,  KC_Q,     KC_W,   KC_E,           KC_R,     KC_T,   KC_Y,     KC_U,     KC_I,      KC_O,    KC_P,     KC_LBRC,  KC_BSPC,  KC_7,  KC_8,  KC_9,
    KC_TAB,   KC_A,     KC_S,   KC_LGD,         KC_LCTF,  KC_G,   KC_H,     KC_RCTJ,  KC_RGK,    KC_L,    KC_SCLN,  KC_ENT,   KC_NO,    KC_4,  KC_5,  KC_6,
    KC_LSFT,  KC_LSZ,   KC_X,   KC_C,           KC_V,     KC_B,   KC_N,     KC_M,     KC_COMM,   KC_DOT,  KC_SLSH,  KC_RSSL,  KC_UP,    KC_1,  KC_2,  KC_3,
    KC_LCTL,  KC_LGUI,  KC_NO,  LT(1, KC_SPC),  MO(3),    MO(2),  KC_LEFT,  KC_DOWN,  KC_RIGHT,  KC_0,    KC_DOT
  ),
  [1] = LAYOUT(
    KC_GRAVE, KC_0,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,      KC_RBRC,  KC_RBRC,  TD(TD_MINS_EQL),  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT,  KC_QUOT,  KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_BSLS,  KC_TRNS,          KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_NO,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS
  ),
  [2] = LAYOUT(
    KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,   KC_F11,   KC_F12,   KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_NO,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS
  ),
  [3] = LAYOUT(
    RESET,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_VOLD,  KC_VOLU,  KC_MUTE,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_NO,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  )
};

void process_indicator_update(layer_state_t state, uint8_t usb_led) {
  if (state & (1 << 2)) {
    writePinHigh(D6);
  } else {
    writePinLow(D6);
  }

  if (state & (1 << 3)) {
    writePinHigh(D4);
  } else {
    writePinLow(D4);
  }
}

void keyboard_post_init_user(void) {
  setPinOutput(D7);
  writePinHigh(D7);
  setPinOutput(D6);
  setPinOutput(D4);

  process_indicator_update(layer_state, host_keyboard_leds());
};

void led_set_user(uint8_t usb_led) {
  process_indicator_update(layer_state, host_keyboard_leds());
};

layer_state_t layer_state_set_user(layer_state_t state) {
  process_indicator_update(state, host_keyboard_leds());
  return state;
};

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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case M_IME:
        SEND_STRING(SS_DOWN(X_LSHIFT)SS_DOWN(X_LALT));
        return false;
    }
  }
  else {
    switch(keycode) {
      case M_IME:
        SEND_STRING(SS_UP(X_LSHIFT)SS_UP(X_LALT));
        return false;
    }
  }
  return true;
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_LSZ:
      return TAPPING_SHIFT_TERM;
    case KC_RSSL:
      return TAPPING_SHIFT_TERM;
    case KC_LGD:
    case KC_LCTF:
    case KC_RCTJ:
    case KC_RGK:
      return TAPPING_HM_TERM;
    default:
      return TAPPING_TERM;
  }
}
