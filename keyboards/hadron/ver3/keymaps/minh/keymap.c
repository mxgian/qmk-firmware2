#include QMK_KEYBOARD_H
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	LAYOUT(
		KC_ESC,  KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8,    KC_9,   KC_0,      KC_BSPC,
		KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,      KC_BSPC,             KC_P7, KC_P8,   KC_P9,
		KC_ESC,  KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,   KC_QUOT,             KC_P4, KC_P5,   KC_P6,
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,   RSFT_T(KC_ENT),            KC_P1, KC_P2,   KC_P3,
		KC_LCTL, KC_LCTL, KC_LALT, KC_LGUI, LT(1,KC_SPC), KC_SPC, KC_SPC, LT(2,KC_SPC), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_P0, KC_PDOT, KC_PENT),
/* Primary
 * ,------+------+------+------+------+------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | BKSP|
 * |------+------+------+------+------+------+------+------+------+------+------+------+--------------------.
 * |  Tab |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | "  " |  7   |   8  |   9  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |  ESC |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ;   |   "  |  4   |   5  |   6  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |  .   |  /?  |  ENT |   1  |   2  |  3   |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Ctl  | Alt  | GUI  | Raise|    Space    | Lower| Left | Down | Up   |Right |   0  |   .  | Enter|
 * `--------------------------------------------------------------------------------------------------------'
 */
	LAYOUT(
		KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
		KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS, KC_HOME, KC_INS, KC_PGUP,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_END, KC_DEL, KC_PGDN,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
/* Raise
 * ,------+------+------+------+------+------------------------------------------------.
 * |  Esc |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+--------------------.
 * |      |   !  |  @   |   #  |   $  |  %   |  ^   |   &  |   *  |   (  |  )   |      | Home | Ins  | PgUP |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   -  |  +   |   {  |  }   |   |  | End  |  Del | PgDN |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | Vol- |      |      |      |      |
 * `--------------------------------------------------------------------------------------------------------'
 */
LAYOUT(
		KC_TRNS, KC_F1,   KC_F2,    KC_F3,    KC_F4,    KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
		KC_TRNS, KC_1,    KC_2,     KC_3,     KC_4,     KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS, KC_HOME, KC_INS, KC_PGUP,
		KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_END, KC_DEL, KC_PGDN,
		HPT_TOG, HPT_FBK, HPT_MODI, HPT_MODD, HPT_RST,  AU_ON,   AU_OFF,  KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		RGB_TOG, RGB_MOD, RGB_VAI,  RGB_VAD,  MUV_DE,   MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  KC_VOLD, KC_TRNS, KC_TRNS, KC_TRNS, RESET),
/* Lower
 * ,------+------+------+------+------+------------------------------------------------.
 * |  Esc |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+--------------------.
 * |      |      |      |      |      |      |      |      |      |  F11 | F12  |      | Home | Ins  | PgUP |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   _  |   =  |   [  |  ]   |  \   | End  |  Del | PgDN |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |Aud on|Audoff|      |      | Vol+ |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |RGB TG|RGB ST|RGBV -|RGBV +|      |      |      ||      |      | Vol- |      |      |      | RST  |
 * `--------------------------------------------------------------------------------------------------------'
 */
};


void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {

}
