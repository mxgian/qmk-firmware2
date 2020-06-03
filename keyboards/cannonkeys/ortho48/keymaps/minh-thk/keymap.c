/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H
#include "muse.h"

#ifdef OLED_DRIVER_ENABLE
  #include "oled_driver.h"
    static uint32_t oled_timer                       = 0;

#endif



#define _MAIN 0
#define _ALPHA 1
#define _BETA 2

extern keymap_config_t keymap_config;
#define MEDIA_KEY_DELAY 10
//define modifiers
#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define MODS_CTRL_MASK  (MOD_BIT(KC_LCTL)|MOD_BIT(KC_RCTRL))
#define MODS_ALT_MASK  (MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))
#define MODS_GUI_MASK  (MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI))

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _RAISE 1
#define _LOWER 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE
};

/*
//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());

}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED
*/

void encoder_update_user(int8_t index, bool clockwise) {

  uint16_t held_keycode_timer = timer_read();

  // add logic here for layers, if layer 0, use scrolling, if layer 1 volume etc
  /*

	modifer - function:

nothing - vol up/down
lower - horizontal scroll
raise - vertical scroll
ctrl - cycle through chrome tabs
alt - cycle through workspaces/virtual desktops (Mac)
gui - zoom in/out
*/
//printf("index %i",index);

//this is the rightmost encoder
if (index == 0) {
	if (get_mods() & MODS_ALT_MASK) {
       if (clockwise) {
         register_code(KC_RIGHT);
         unregister_code(KC_RIGHT);
       }else {
            register_code(KC_LEFT);
           unregister_code(KC_LEFT);
       }
      }else {
        if (get_mods() & MODS_GUI_MASK) {
          if (clockwise) {
           register_code(KC_TAB);
              unregister_code(KC_TAB);
          }else {
              register_code(KC_LSHIFT);
              register_code(KC_TAB);
              unregister_code(KC_LSHIFT);
              unregister_code(KC_TAB);
          }
        } else {
          if (get_mods() & MODS_CTRL_MASK) {
            if (clockwise) {
              register_code(KC_TAB);
              unregister_code(KC_TAB);
            }else {
              register_code(KC_LSHIFT);
              register_code(KC_TAB);
              unregister_code(KC_LSHIFT);
              unregister_code(KC_TAB);
            }
          }
        }
      }

if (IS_LAYER_ON(_LOWER)) {
    if (clockwise) {
	    register_code(KC_WH_D);
		while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) {
	      // no-op
		}
		unregister_code(KC_WH_D);
    } else {
	    register_code(KC_WH_U);
		while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) {
	      // no-op
	    }
		unregister_code(KC_WH_U);
    }
    }
	if (IS_LAYER_ON(_RAISE)) {
	    if (clockwise) {
		    register_code(KC_PGDN);
		    while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) {
		      // no-op
		    }
			unregister_code(KC_PGDN);
	    } else {
		    register_code(KC_PGUP);
		    while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) {
		      // no-op
		    }
			unregister_code(KC_PGUP);
	    }
	    }
      else {
		    if (clockwise) {
		      register_code(KC_VOLU);
		      while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) {
		        // no-op
		      }
		      unregister_code(KC_VOLU);
		    } else {
		      register_code(KC_VOLD);
		      while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) {
		        // no-op
		      }
		      unregister_code(KC_VOLD);
		    }
    }
}  //end if index = 0

//this is the leftmost encoder
if (index == 1) {
	if (get_mods() & MODS_ALT_MASK) {
       if (clockwise) {
         register_code(KC_RIGHT);
         unregister_code(KC_RIGHT);
       }else {
           register_code(KC_LEFT);
           unregister_code(KC_LEFT);
       }
      }else {
        if (get_mods() & MODS_GUI_MASK) {
          if (clockwise) {
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
          }else {
              register_code(KC_MS_WH_DOWN);
              unregister_code(KC_MS_WH_DOWN);
          }
        } else {
          if (get_mods() & MODS_CTRL_MASK) {
            if (clockwise) {
              register_code(KC_TAB);
              unregister_code(KC_TAB);
            }else {
              register_code(KC_LSHIFT);
              register_code(KC_TAB);
              unregister_code(KC_LSHIFT);
              unregister_code(KC_TAB);
            }
          }
        }
      }

if (IS_LAYER_ON(_LOWER)) {
    if (clockwise) {
	    register_code(KC_WH_D);
		while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) {
	      // no-op
		}
		unregister_code(KC_WH_D);
    } else {
	    register_code(KC_WH_U);
		while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) {
	      // no-op
	    }
		unregister_code(KC_WH_U);
    }
    }
	if (IS_LAYER_ON(_RAISE)) {
	    if (clockwise) {
		    register_code(KC_PGDN);
		    while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) {
		      // no-op
		    }
			unregister_code(KC_PGDN);
	    } else {
		    register_code(KC_PGUP);
		    while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) {
		      // no-op
		    }
			unregister_code(KC_PGUP);
	    }
	    }
      else {
		    if (clockwise) {
		      register_code(KC_VOLU);
		      while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) {
		        // no-op
		      }
		      unregister_code(KC_VOLU);
		    } else {
		      register_code(KC_VOLD);
		      while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) {
		        // no-op
		      }
		      unregister_code(KC_VOLD);
		    }
    }
}  //end if index = 1

}



#ifdef OLED_DRIVER_ENABLE

void set_keylog(uint16_t keycode, keyrecord_t *record);

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_0;
}
void render_crkbd_logo(void) {
  static const char PROGMEM crkbd_logo[] = {
      0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
      0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
      0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
      0};
  oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {


     if (timer_elapsed32(oled_timer) > OLED_TIMEOUT) {
        oled_off();
        return;
    }
   else {
    render_crkbd_logo();
    oled_scroll_right() ;  // Turns on scrolling
  }
/*
 // Host Keyboard Layer Status
    uint8_t current_layer = biton32(layer_state);
    static const char PROGMEM icons[4][3][6] = {
        {
            { 0x80, 0x81, 0x82, 0x83, 0x84, 0 },
            { 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0 },
            { 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0 }
        },
        {
            { 0x85, 0x86, 0x87, 0x88, 0x89, 0 },
            { 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0 },
            { 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0 }
        },
        {
            { 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0 },
            { 0xaa, 0xab, 0xac, 0xad, 0xae, 0 },
            { 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0 }
        },
        {
            { 0x8f, 0x90, 0x91, 0x92, 0x93, 0 },
            { 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0 },
            { 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0 }
        }
    };

    uint8_t icon_index = current_layer == _MAIN ? 3 : current_layer == _ALPHA ? 1 : 2;
    for (int i = 0; i < 3; i++) {
        oled_set_cursor(0, i + 1);
        oled_write_P(icons[icon_index][i], false);
    }

    oled_set_cursor(6, 1);
    oled_write_P(PSTR("-D48 Custom-\n"), false);

    uint8_t layer_index = current_layer == _MAIN ? 0 : current_layer == _ALPHA ? 1 : 2;
    const char *layers[3] = {
        PSTR("MAIN"),
        PSTR("ALPHA"),
        PSTR("BETA")
    };
    oled_set_cursor(6, 2);
    oled_write_P("Layer: ", false);
    oled_write_P(layers[layer_index], false);
    oled_write_P("\n", false);

    */
/*
    static const char PROGMEM mods[][2] = {
        {0x94, 0x95}, // CTL
        {0x96, 0x97}, // ALT
        {0x98, 0x99}, // GUI
        {0x9a, 0x9b},  // SFT
        // {0x9c, 0x9d},  // EMPTY
    };
*/
   /* char mod_data[13] = "\x9c\x9d\x9c\x9d\x9c\x9d\x9c\x9d \x07\x07\x07\0";
    if (ctrl_pressed) strncpy(mod_data, mods[0], 2);;
    if (alt_pressed) strncpy(mod_data + 2, mods[1], 2);;
    if (gui_pressed) strncpy(mod_data + 4, mods[2], 2);;
    if (shift_pressed) strncpy(mod_data + 6, mods[3], 2);;
    uint8_t led_usb_state = host_keyboard_leds();
    if (led_usb_state & (1 << USB_LED_NUM_LOCK)) mod_data[9] = 'N';
    if (led_usb_state & (1 << USB_LED_CAPS_LOCK)) mod_data[10] = 'C';
    if (led_usb_state & (1 << USB_LED_SCROLL_LOCK)) mod_data[11] = 'S';

    oled_set_cursor(6, 3);
    oled_write(mod_data, false);
*/
    /*[>uint8_t led_usb_state = host_keyboard_leds();<]*/
    /*[>oled_write_P(led_usb_state & (1<<USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);<]*/
    /*[>oled_write_P(led_usb_state & (1<<USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);<]*/
    /*[>oled_write_P(led_usb_state & (1<<USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);<]*/
}
#endif
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {

    #ifdef OLED_DRIVER_ENABLE
      oled_timer = timer_read32();
     // set_keylog(keycode, record);
    #endif

    // set_timelog();
  }
  return true;

}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_ortho_4x12(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    RGB_MOD, KC_LCTL, KC_LALT, KC_LGUI, MO(_LOWER),   KC_SPC,  KC_SPC,  MO(_RAISE),   MT(MOD_RGUI,KC_LEFT), MT(MOD_RALT,KC_DOWN), MT(MOD_RCTL,KC_UP),   KC_RGHT
),
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
    RESET,   _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
    KC_GRV,  KC_1,    KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    RGB_TOG, RGB_MOD, RGB_VAI,  RGB_VAD, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),
};
