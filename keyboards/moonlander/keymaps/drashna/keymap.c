/* Copyright 2020 Drashna Jael're  <drashna@live.com>
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



#include "drashna.h"

#ifndef UNICODE_ENABLE
#    define UC(x) KC_NO
#endif

enum more_custom_keycodes { KC_SWAP_NUM = NEW_SAFE_RANGE };

// clang-format off
#define LAYOUT_moonlander_wrapper(...) LAYOUT_moonlander(__VA_ARGS__)

#define LAYOUT_moonlander_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
    ) \
    LAYOUT_moonlander_wrapper( \
        KC_ESC,  ________________NUMBER_LEFT________________, UC_FLIP,        UC_TABL, ________________NUMBER_RIGHT_______________, KC_MINS, \
        KC_TAB,  K01,     K02,     K03,     K04,     K05,   TG(_DIABLO),TG(_DIABLO),   K06,     K07,     K08,     K09,     K0A,     KC_BSLS, \
        KC_C1R3, K11,     K12,     K13,     K14,     K15,  TG(_GAMEPAD),TG(_GAMEPAD),  K16,     K17,     K18,     K19,     K1A,     RALT_T(KC_QUOT), \
        KC_MLSF, CTL_T(K21), K22,  K23,     K24,     K25,                              K26,     K27,     K28,     K29,  RCTL_T(K2A),KC_MRSF, \
        KC_GRV,  OS_MEH,  OS_HYPR, KC_LBRC, KC_RBRC,          KC_NO,          KC_DEL,           KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, UC(0x2E2E), \
                                            KC_SPC,  BK_LWER, OS_LALT,        OS_RGUI, DL_RAIS, KC_ENT \
    )

#define LAYOUT_moonlander_base_wrapper(...) LAYOUT_moonlander_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_moonlander_base_wrapper(
        _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
        _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
    ),

    [_COLEMAK] = LAYOUT_moonlander_base_wrapper(
        _________________COLEMAK_L1________________, _________________COLEMAK_R1________________,
        _________________COLEMAK_L2________________, _________________COLEMAK_R2________________,
        _________________COLEMAK_L3________________, _________________COLEMAK_R3________________
    ),

    [_DVORAK] = LAYOUT_moonlander_base_wrapper(
        _________________DVORAK_L1_________________, _________________DVORAK_R1_________________,
        _________________DVORAK_L2_________________, _________________DVORAK_R2_________________,
        _________________DVORAK_L3_________________, _________________DVORAK_R3_________________
    ),

    [_WORKMAN] = LAYOUT_moonlander_base_wrapper(
        _________________WORKMAN_L1________________, _________________WORKMAN_R1________________,
        _________________WORKMAN_L2________________, _________________WORKMAN_R2________________,
        _________________WORKMAN_L3________________, _________________WORKMAN_R3________________
    ),

    [_NORMAN] = LAYOUT_moonlander_base_wrapper(
        _________________NORMAN_L1_________________, _________________NORMAN_L1_________________,
        _________________NORMAN_L2_________________, _________________NORMAN_R2_________________,
        _________________NORMAN_L3_________________, _________________NORMAN_R3_________________
    ),

    [_MALTRON] = LAYOUT_moonlander_base_wrapper(
        _________________MALTRON_L1________________, _________________MALTRON_R1________________,
        _________________MALTRON_L2________________, _________________MALTRON_R2________________,
        _________________MALTRON_L3________________, _________________MALTRON_R3________________
    ),

    [_EUCALYN] = LAYOUT_moonlander_base_wrapper(
        _________________EUCALYN_L1________________, _________________EUCALYN_R1________________,
        _________________EUCALYN_L2________________, _________________EUCALYN_R2________________,
        _________________EUCALYN_L3________________, _________________EUCALYN_R3________________
    ),

    [_CARPLAX] = LAYOUT_moonlander_base_wrapper(
        _____________CARPLAX_QFMLWY_L1_____________, _____________CARPLAX_QFMLWY_R1_____________,
        _____________CARPLAX_QFMLWY_L2_____________, _____________CARPLAX_QFMLWY_R2_____________,
        _____________CARPLAX_QFMLWY_L3_____________, _____________CARPLAX_QFMLWY_R3_____________
    ),

#ifdef _MODS
    [_MODS] = LAYOUT_moonlander_wrapper(
        _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______,
        KC_LSFT, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, KC_RSFT,
        _______, KC_MEH,  KC_HYPR, _______, _______,          _______,        _______,          _______, _______, _______, _______, _______,
                                            KC_LALT, _______, _______,        _______, _______, KC_RGUI
    ),
#endif

    [_GAMEPAD] = LAYOUT_moonlander_wrapper(
        KC_ESC,  KC_NO,   KC_1,    KC_2,    KC_3,    KC_4, HYPR(KC_Q),                 KC_TRNS, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,   KC_NO,
        KC_F1,   KC_K,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                    UC_SHRG, UC_DISA, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_TAB,  KC_G,    KC_A,    KC_S,    KC_D,    KC_F,    KC_TRNS,            TG(_GAMEPAD), KC_I,    KC_O,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_LCTL, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,                                      KC_N,    KC_M,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_GRV,  KC_U,    KC_I,    KC_Y,    KC_T,             KC_PSCR,                 _______,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,
                                            KC_V,    KC_SPC,  KC_H,                    KC_NO, KC_NO,  KC_SWAP_NUM
    ),
    [_DIABLO] = LAYOUT_moonlander_wrapper(
        KC_ESC,  KC_V,    KC_D,    KC_LALT, KC_NO,   KC_NO,   KC_NO,                   KC_TRNS, KC_F9,   KC_F10,   KC_F11,  KC_F12,  KC_NO,   KC_NO,
        KC_TAB,  KC_S,    KC_I,    KC_F,    KC_M,    KC_T,    KC_TRNS,                 KC_TRNS, KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_1,    KC_2,    KC_3,    KC_4,    KC_G,    KC_TRNS,                 KC_TRNS, KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_LCTL, KC_D3_1, KC_D3_2, KC_D3_3, KC_D3_4, KC_Z,                                      KC_N,    KC_M,     KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_L,    KC_J,    KC_F,             KC_PSCR,                 KC_NO,            KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
                          KC_DIABLO_CLEAR,  SFT_T(KC_SPACE),  ALT_T(KC_Q),             KC_PGDN, KC_DEL,  KC_ENT
    ),

    [_LOWER] = LAYOUT_moonlander_wrapper(
        KC_F12,  _________________FUNC_LEFT_________________, _______,        _______, _________________FUNC_RIGHT________________, KC_F11,
        _______, _________________LOWER_L1__________________, _______,        _______, _________________LOWER_R1__________________, KC_PIPE,
        _______, _________________LOWER_L2__________________, _______,        _______, _________________LOWER_R2__________________, KC_DQUO,
        _______, _________________LOWER_L3__________________,                          _________________LOWER_R3__________________, KC_PSCR,
        _______, _______, _______, _______, _______,          _______,        _______,          _______, _______, _______, _______, KC_PAUS,
                                            _______, _______, _______,        _______, _______, _______
    ),

    [_RAISE] = LAYOUT_moonlander_wrapper(
        KC_F12,  _________________FUNC_LEFT_________________, _______,        _______, _________________FUNC_RIGHT________________, KC_F11,
        _______, _________________RAISE_L1__________________, _______,        _______, _________________RAISE_R1__________________, KC_BSLS,
        _______, _________________RAISE_L2__________________, _______,        _______, _________________RAISE_R2__________________, KC_QUOT,
        _______, _________________RAISE_L3__________________,                          _________________RAISE_R3__________________, KC_PSCR,
        _______, _______, _______, _______, _______,          _______,        _______,          KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_PAUS,
                                            _______, _______, _______,        _______, _______, _______
    ),

    [_ADJUST] = LAYOUT_moonlander_wrapper(
        KC_MAKE, _________________FUNC_LEFT_________________, UC_MOD,         KC_NUKE, _________________ADJUST_R1_________________, KC_RST,
        VRSN,    _________________ADJUST_L1_________________, _______,        _______, _________________ADJUST_R1_________________, EEP_RST,
        _______, _________________ADJUST_L2_________________, _______,        _______, _________________ADJUST_R2_________________, RGB_IDL,
        _______, _________________ADJUST_L3_________________,                          _________________ADJUST_R3_________________, TG_MODS,
        _______, _______, _______, _______, _______,          _______,        _______,          _______, _______, _______, _______, KC_PAUS,
                                            _______, _______, _______,        _______, _______, _______
    ),
};

/*  Blank

    [_LAYER] = LAYOUT_moonlander_wrapper(
        _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,        _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,        _______, _______, _______
    ),

*/


bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_1:
            if (layer_state_is(_GAMEPAD) && userspace_config.swapped_numbers) {
                if (record->event.pressed) {
                    register_code(KC_2);
                } else {
                    unregister_code(KC_2);
                }
                return false;
            }
            break;
        case KC_2:
            if (layer_state_is(_GAMEPAD) && userspace_config.swapped_numbers) {
                if (record->event.pressed) {
                    register_code(KC_1);
                } else {
                    unregister_code(KC_1);
                }
                return false;
            }
            break;
        case KC_SWAP_NUM:
            if (record->event.pressed) {
                userspace_config.swapped_numbers ^= 1;
                eeconfig_update_user(userspace_config.raw);
                unregister_code(KC_1);
                unregister_code(KC_2);
            }
            break;
    }
    return true;
}

#ifdef RGB_MATRIX_ENABLE
#    ifndef RGB_MATRIX_INDICATOR_SET_COLOR
#        define RGB_MATRIX_INDICATOR_SET_COLOR(i, r, g, b) rgb_matrix_set_color(i, r, g, b)
void rgb_matrix_indicators_user(void) {
    #else
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
#    endif
    if (g_suspend_state || !rgb_matrix_config.enable) return;

    if (layer_state_is(_GAMEPAD)) {
        RGB_MATRIX_INDICATOR_SET_COLOR(11, 0x00, 0xFF, 0x00);  // Q
        RGB_MATRIX_INDICATOR_SET_COLOR(16, 0x00, 0xFF, 0xFF);  // W
        RGB_MATRIX_INDICATOR_SET_COLOR(21, 0xFF, 0x00, 0x00);  // E
        RGB_MATRIX_INDICATOR_SET_COLOR(26, 0xFF, 0x80, 0x00);  // R
        RGB_MATRIX_INDICATOR_SET_COLOR(12, 0x00, 0xFF, 0xFF);  // A
        RGB_MATRIX_INDICATOR_SET_COLOR(17, 0x00, 0xFF, 0xFF);  // S
        RGB_MATRIX_INDICATOR_SET_COLOR(22, 0x00, 0xFF, 0xFF);  // D
        RGB_MATRIX_INDICATOR_SET_COLOR(27, 0x7A, 0x00, 0xFF);  // F

        RGB_MATRIX_INDICATOR_SET_COLOR((userspace_config.swapped_numbers ? 10 : 15), 0xFF, 0xFF, 0xFF);  // 1
        RGB_MATRIX_INDICATOR_SET_COLOR((userspace_config.swapped_numbers ? 15 : 10), 0x00, 0xFF, 0x00);  // 2
        RGB_MATRIX_INDICATOR_SET_COLOR(20, 0x7A, 0x00, 0xFF);                                          // 3
    }

    if (userspace_config.rgb_layer_change) {
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _QWERTY:
                rgb_matrix_layer_helper(HSV_CYAN, 0, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                break;
            case _COLEMAK:
                rgb_matrix_layer_helper(HSV_MAGENTA, 0, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                break;
            case _DVORAK:
                rgb_matrix_layer_helper(HSV_SPRINGGREEN, 0, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                break;
            case _WORKMAN:
                rgb_matrix_layer_helper(HSV_GOLDENROD, 0, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                break;
            case _NORMAN:
                rgb_matrix_layer_helper(HSV_CORAL, 0, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                break;
            case _MALTRON:
                rgb_matrix_layer_helper(HSV_YELLOW, 0, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                break;
            case _EUCALYN:
                rgb_matrix_layer_helper(HSV_PINK, 0, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                break;
            case _CARPLAX:
                rgb_matrix_layer_helper(HSV_BLUE, 0, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                break;
            case _GAMEPAD:
                rgb_matrix_layer_helper(HSV_ORANGE, 1, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                break;
            case _DIABLO:
                rgb_matrix_layer_helper(HSV_RED, 1, rgb_matrix_config.speed * 8, LED_FLAG_MODIFIER);
                break;
            case _RAISE:
                rgb_matrix_layer_helper(HSV_YELLOW, 1, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                break;
            case _LOWER:
                rgb_matrix_layer_helper(HSV_GREEN, 1, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                break;
            case _ADJUST:
                rgb_matrix_layer_helper(HSV_RED, 1, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                break;
        }
    }
}
#endif

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    if (keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) {
        if (mod_config(keycode & 0xf) & MOD_MASK_ALT) {
            return (2 * TAPPING_TERM);
        }
    }
    return TAPPING_TERM;
}
#endif
