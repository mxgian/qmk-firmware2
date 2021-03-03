// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum chimera_ergo_layers
{
  _QWERTY,
  _CAPS,
  _NUMPAD,
  _SYMBOLS,
  _MACROS,
  _NAV
};

#define SC_NMPD MO(_NUMPAD)
#define SC_SYMB MO(_SYMBOLS)

#define SC_SCTL MT(MOD_LCTL, KC_2)
#define SC_SPLT MT(MOD_LALT, KC_3)
#define SC_SPLG MT(MOD_LGUI, KC_4)
#define SC_SPFN LT(_NAV,KC_4)
#define SC_GBRC MT(MOD_RGUI, KC_7)

#define SC_SPRT MT(MOD_LALT, KC_8)
#define SC_SCTR MT(MOD_LCTL, KC_9)
#define SC_MESC LT(_MACROS, KC_ESC)
#define SC_INCL M(0)
#define SC_PULL M(1)
#define SC_PUSH M(2)
#define SC_SCAP M(3)
#define SC_SCOF M(4)
#define SC_CAD LALT(LCTL(KC_DEL))
#define SC_CTLENT MT(MOD_LCTL,KC_ENT)
#define SC_GUISPC MT(MOD_LGUI,KC_SPC)
#define SC_L1ENT LT(_NUMPAD,KC_ENT)
#define SC_L2SPC LT(_SYMBOLS,KC_SPC)

#define LONGPRESS_DELAY 150
//#define LAYER_TOGGLE_DELAY 300
/*
 //,-----------------------------------------.                ,-----------------------------------------.
        ~,     1,     MT(CTL,2),MT(ALT,3), MO(_NAV,4), 5,          MT(GUI,6),MT(ALT,7), MT(CTRL,8), 9,   0,     BSPC,\
 //,-----------------------------------------.                ,-----------------------------------------.
        TAB,     Q,     W,     E,     R,     T,                      Y,        U,         I,          O,   P,   BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      ESC,     A,     S,     D,     F,     G,                      H,        J,         K,          L,  SCLN,   QUOT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LSFT,     Z,     X,     C,     V,     B,                      N,        M,        COMM,        DOT, SLSH, RSFT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  , NUMPAD,   SPC,           ENT, SYMBS,  \
                              //`--------------------'  `--------------------'
  */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
     KC_TAB, KC_1,    SC_SCTL, SC_SPLT, SC_SPLG, KC_5,          KC_6,    SC_GBRC, KC_8, SC_SCTR,    KC_0,     KC_BSPC,
     SC_MESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,     KC_DEL,
     KC_LSFT,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,          KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN,  KC_QUOT,
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_ENT,
                                         KC_LGUI, SC_L1ENT,       SC_L2SPC,  KC_LALT
  ),

  [_CAPS] = LAYOUT(
     _______, KC_UNDS, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, KC_COLN, _______,
     SC_SCOF, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, SC_SCOF,
                                         _______, _______,       _______, _______
  ),

  [_NUMPAD] = LAYOUT(
     _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, KC_MINS, _______,
     _______, _______, KC_COLN, _______, _______, _______,       _______, KC_7,    KC_8,    KC_9,    KC_ASTR, _______,
     _______, _______, KC_DOT , _______, _______, _______,       _______, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
     _______, KC_LEFT, KC_DOWN,   KC_UP,   KC_RIGHT,_______,       _______, KC_1,    KC_2,    KC_3,    KC_SLSH, _______,
                                         _______, _______,       _______, _______
  ),

  [_SYMBOLS] = LAYOUT(
     _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS,
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,         KC_UNDS, KC_EQL,  KC_UNDS, KC_LCBR, KC_RCBR, KC_PIPE,
     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,        KC_GRV,  KC_PLUS, KC_MINS, KC_LBRC, KC_RBRC, _______,
                                         KC_PIPE, _______,       _______, _______
  ),

  [_MACROS] = LAYOUT(
     _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,       _______, _______, SC_INCL, _______, _______, _______,
     _______, _______, _______, SC_CAD,  _______, _______,       _______, _______, _______, _______, _______, _______,
     SC_SCAP, _______, _______, _______, _______, _______,       _______, _______, SC_PULL, SC_PUSH, _______, _______,
                                         _______, _______,       _______, _______
  ),

  [_NAV] = LAYOUT(
     _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,       _______, KC_PGUP, KC_UP,   KC_PGDN, KC_PSCR, _______,
     _______, _______, _______, _______, _______, _______,       _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
     _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
                                         _______, KC_DEL,        _______, _______
  ),

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    /* include some kind of library or header */
    case 0:
      if (record->event.pressed) {
        SEND_STRING("#include <>");
        return MACRO( T(LEFT), END);
      }
      break;
    case 1:
      if (record->event.pressed) {
        SEND_STRING("git pull");
        return MACRO( T(ENT), END );
      }
      break;
    case 2:
      if (record->event.pressed){
        SEND_STRING("git push");
        return MACRO( T(ENT), END );
      }
      break;
    case 3:
      if (record->event.pressed){
        layer_on(_CAPS);
        register_code(KC_CAPSLOCK);
        unregister_code(KC_CAPSLOCK);
      }
      break;
    case 4:
      if (record->event.pressed){
        layer_off(_CAPS);
        register_code(KC_CAPSLOCK);
        unregister_code(KC_CAPSLOCK);
      }
      break;
  }
  return MACRO_NONE;
};


void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    switch (layer) {
      case _QWERTY:
          set_led_green;
          break;
        case _CAPS:
      set_led_white;
      break;
        case _NUMPAD:
            set_led_blue;
            break;
        case _SYMBOLS:
            set_led_red;
            break;
        case _NAV:
      set_led_magenta;
      break;
        case _MACROS:
      set_led_cyan;
      break;
       default:
            set_led_green;
            break;
    }
};
