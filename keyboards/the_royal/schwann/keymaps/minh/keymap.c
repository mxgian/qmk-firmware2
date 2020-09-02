#include QMK_KEYBOARD_H

enum layer_names {
  _QWERTY,
  _LOWER,
  _RAISE,
  _NAV,
  _OTHER
};

enum schwann_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST
};

//Tap Dance Declarations
enum {
  TD_RST
};
/*
void dance_rst_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 2) {
    reset_keyboard();
    reset_tap_dance(state);
  }
}

//All tap dance functions would go here. Only showing this one.
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_RST] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, NULL, dance_rst_reset)
};
*/

#define XXXXX KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Default Layer
   * ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
   * │Tab │ Q  │ W  │ E  │ R  │ T  │ Y  │ U  │ I  │ O  │ P  │BkSp│
   * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
   * │LCtl│ A  │ S  │ D  │ F  │ G  │ H  │ J  │ K  │ L  │ ;  │ '  │
   * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
   * │LSft│ Z  │ X  │ C  │ V  │ B  │ N  │ M  │ ,  │ .  │ /  │Entr│
   * └────┼────┼────┼────┼────┼────┴────┼────┼────┼────┼────┼────┘
   *      │Del │Gui │Alt │Lwr │         │Rse │Alt │Menu│Ctrl│
   *      └────┴────┴────┴────┴─────────┴────┴────┴────┴────┘
   */

  [_QWERTY] = LAYOUT_mit(
    KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,    KC_BSPC,
    LT(_NAV,KC_TAB), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    MT(MOD_RCTL,KC_COMM),  MT(MOD_RALT,KC_DOT),  MT(MOD_RGUI,KC_SLSH), MT(MOD_LSFT,KC_ENT),
              RAISE,  KC_LGUI, KC_LALT, LOWER,     KC_SPACE,       RAISE,   KC_RALT,  KC_MENU,  LOWER
  ),

  /* Lower Layer
   * ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
   * │Esc │ 1  │ 2  │ 3  │ 4  │ 5  │ 6  │ 7  │ 8  │ 9  │ 0  │    │
   * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
   * │ ~  │ !  │ @  │ #  │ $  │ %  │ ^  │ &  │ *  │ (  │ )  │ "  │
   * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
   * │    │    │    │    │    │    │    │    │ `  │ [  │ ]  │ .  │
   * └────┼────┼────┼────┼────┼────┴────┼────┼────┼────┼────┼────┘
   *      │    │    │    │    │         │    │    │    │    │
   *      └────┴────┴────┴────┴─────────┴────┴────┴────┴────┘
   */
  [_LOWER] = LAYOUT_mit(
    KC_ESC,     KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,     KC_8,     KC_9,     KC_0,     _______,
    KC_TILD,    KC_F1,    KC_F2,     KC_F3,      KC_F4,     KC_F5,     KC_F6,     KC_UNDS,  KC_PLUS,  KC_LCBR, KC_RCBR, KC_PIPE,
    _______,    _______,   _______,   _______,   _______,   _______,   _______,   _______,  KC_GRAVE, KC_LBRC, KC_RBRC,  KC_DOT,
                _______,   _______,   _______,   _______,         _______,        _______,  _______,  _______,  _______
  ),

  /* Raise Layer
   * ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
   * │    │    │    │    │    │    │    │    │    │    │ -  │    │
   * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
   * │CAPS│    │    │    │    │    │    │    │    │    │ _  │ \  │
   * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
   * │PrSc│    │    │    │    │    │    │    │    │ UP │    │ =  │
   * └────┼────┼────┼────┼────┼────┴────┼────┼────┼────┼────┼────┘
   *      │    │    │    │    │         │    │Left│Down│Rght│
   *      └────┴────┴────┴────┴─────────┴────┴────┴────┴────┘
   */
  [_RAISE] = LAYOUT_mit(
    KC_TILD,    KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,   KC_CIRC,   KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DQT,
    KC_CAPS,     KC_F1,   KC_F2,      KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC, KC_BSLS,
    KC_PSCR,    KC_F7,    KC_F8,      KC_F9,     KC_F10,    KC_F11,    KC_F12,    KC_NUHS,  KC_NUBS,  KC_PGUP,  KC_PGDN, _______,
                 _______,   _______,    _______,   _______,         _______,      _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT
),
/* Other Layer
   * ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
   * │RSET│    │    │    │    │    │    │    │    │SAT+│Hue+│Brt+│
   * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
   * │    │    │    │    │    │    │    │    │    │SAT-│Hue-│Brt-│
   * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
   * │    │    │    │    │    │    │    │    │    │    │    │RGB!│
   * └────┼────┼────┼────┼────┼────┴────┼────┼────┼────┼────┼────┘
   *      │    │    │    │    │         │    │    │    │    │
   *      └────┴────┴────┴────┴─────────┴────┴────┴────┴────┘
   */
  [_NAV] = LAYOUT_mit(
    _______, _______,   KC_UP,    _______,   _______,   _______,   _______,   _______,  _______,  RGB_SAI,  RGB_HUI,  RGB_VAI,
    _______,    KC_LEFT,   KC_DOWN,    KC_RIGHT,   _______,   _______,   _______,   _______,  _______,  RGB_SAD,  RGB_HUD,  RGB_VAD,
    KC_X,    _______,   _______,    _______,   _______,   _______,   _______,   _______,  _______,  _______,  _______,  RGB_MOD,
                _______,   _______,    _______,   _______,         _______,        _______,  _______,  _______,  RESET
  ),

  /* Other Layer
   * ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
   * │RSET│    │    │    │    │    │    │    │    │SAT+│Hue+│Brt+│
   * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
   * │    │    │    │    │    │    │    │    │    │SAT-│Hue-│Brt-│
   * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
   * │    │    │    │    │    │    │    │    │    │    │    │RGB!│
   * └────┼────┼────┼────┼────┼────┴────┼────┼────┼────┼────┼────┘
   *      │    │    │    │    │         │    │    │    │    │
   *      └────┴────┴────┴────┴─────────┴────┴────┴────┴────┘
   */
  [_OTHER] = LAYOUT_mit(
    RESET, _______,   _______,    _______,   _______,   _______,   _______,   _______,  _______,  RGB_SAI,  RGB_HUI,  RGB_VAI,
    _______,    _______,   _______,    _______,   _______,   _______,   _______,   _______,  _______,  RGB_SAD,  RGB_HUD,  RGB_VAD,
    KC_X,    _______,   _______,    _______,   _______,   _______,   _______,   _______,  _______,  _______,  _______,  RGB_MOD,
                _______,   _______,    _______,   _______,         _______,        _______,  _______,  _______,  _______
  )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _OTHER);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _OTHER);
      }
         return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _OTHER);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _OTHER);
      }
         return false;
      break;
     case ADJUST:
        if (record->event.pressed) {
          layer_on(_OTHER);
        } else {
          layer_off(_OTHER);
        }
      return false;
      break;
  }
  return true;

};
