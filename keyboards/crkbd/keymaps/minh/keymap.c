#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif
#ifdef OLED_DRIVER_ENABLE
  #include "oled_driver.h"
  static uint32_t oled_timer                       = 0;
//  static uint16_t log_timer                        = 0;

#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;
//if you want to switch to QMK-DFU for pro-micro mcu
// make crkbd:minh:bootloader
// avrdude -c usbtiny -p m32u4  -U flash:w:"crkbd_rev1_minh_bootloader.hex":a -U lfuse:w:0x5E:m -U hfuse:w:0xD9:m -U efuse:w:0xC3:m -U lock:w:0x3F:m



// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _NAV 5

#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_LOWER LOWER
#define KC_RAISE RAISE
#define KC_RST   RESET
#define KC_LRST  RGBRST
#define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LVAI  RGB_VAI
#define KC_LVAD  RGB_VAD
#define KC_LMOD  RGB_MOD
#define KC_CTLTB CTL_T(KC_TAB)
#define KC_GUIEI GUI_T(KC_LANG2)
#define KC_ALTKN ALT_T(KC_LANG1)
#define KC_RENT MT(MOD_RSFT,KC_ENT)
#define KC_LTENT LT(3,KC_ENT)
#define KC_LTSPC LT(4,KC_SPC)

#define KC_LTESC LT(_NAV, KC_ESC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
     LTESC,     Q,     W,     E,     R,     T,                      Y,     U,     I,     O,     P,  BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      CTLTB,     A,     S,     D,     F,     G,                      H,     J,     K,     L,  SCLN,  QUOT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LSFT,     Z,     X,     C,     V,     B,                      N,     M,  COMM,   DOT,  SLSH,  RENT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  GUIEI, LOWER,   LTENT,      LTSPC, RAISE, ALTKN \
                              //`--------------------'  `--------------------'
  ),

  [_LOWER] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
       ESC,  EXLM,    AT,  HASH,   DLR,  PERC,                   CIRC,  AMPR,  ASTR,  LPRN,  RPRN,  BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      CTLTB,    F1,    F2,    F3,    F4,    F5,                     UNDS,    PLUS,    LCBR,    RCBR,   PIPE, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LSFT,   LEFT,   DOWN,   UP, RIGHT,   F15,                    F16,   F17,   LEFT,   DOWN,   UP, RIGHT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  GUIEI, LOWER,   LTENT,      LTSPC, RAISE, ALTKN \
                              //`--------------------'  `--------------------'
  ),

  [_RAISE] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        ESC,     1,     2,     3,     4,     5,                      6,     7,     8,     9,     0,  BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      CTLTB, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                   MINS,   EQL,  LCBR,  RCBR,  PIPE,   GRV,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LSFT, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                   UNDS,  PLUS,  LBRC,  RBRC,  BSLS,  TILD,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  GUIEI, LOWER,   LTENT,      LTSPC, RAISE, ALTKN \
                              //`--------------------'  `--------------------'
  ),
   [_NAV] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
     XXXXX,  XXXXX, UP,    XXXXX, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, MUTE,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     LTOG,  LEFT,  DOWN, RIGHT, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, VOLU,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LSFT,  LEFT,  DOWN,   UP, RIGHT,  XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, VOLD,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  GUIEI, LOWER,   LTENT,      LTSPC, RAISE, ALTKN \
                              //`--------------------'  `--------------------'
  ),

  [_ADJUST] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        RST,  LRST, XXXXX, XXXXX, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LTOG,  LHUI,  LSAI,  LVAI, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LMOD,  LHUD,  LSAD,  LVAD, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  GUIEI, LOWER,   LTENT,      LTSPC, RAISE, ALTKN \
                              //`--------------------'  `--------------------'
  )




};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

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
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
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

#ifdef OLED_DRIVER_ENABLE
//sourced from keylogger.c
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_master) {
    return OLED_ROTATION_270;
  } else {
    return rotation;
  }
}

void render_crkbd_logo(void) {
  static const char PROGMEM crkbd_logo[] = {
      0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
      0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
      0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
      0};
  oled_write_P(crkbd_logo, false);
}


void render_status(void) {

  oled_write_P(PSTR("Layer"), false);
  switch (biton32(layer_state)) {
    case 0:
      oled_write_P(PSTR("Base "), false);
      break;
    case _RAISE:
      oled_write_P(PSTR("Raise"), false);
      break;
    case _LOWER:
      oled_write_P(PSTR("Lower"), false);
      break;
    case _ADJUST:
      oled_write_P(PSTR("Adjst"), false);
      break;
    default:
      oled_write_P(PSTR("Unkn "), false);
      break;
  }


  uint8_t modifiers = get_mods();
  uint8_t one_shot = get_oneshot_mods();

  oled_write_P(PSTR("Mods:"), false);
  oled_write_P( (modifiers & MOD_MASK_CTRL  || one_shot & MOD_MASK_CTRL ) ? PSTR(" CTL ") : PSTR("     "), false);
  oled_write_P( (modifiers & MOD_MASK_GUI   || one_shot & MOD_MASK_GUI  ) ? PSTR(" GUI ") : PSTR("     "), false);
  oled_write_P( (modifiers & MOD_MASK_ALT   || one_shot & MOD_MASK_ALT  ) ? PSTR(" ALT ") : PSTR("     "), false);
  oled_write_P( (modifiers & MOD_MASK_SHIFT || one_shot & MOD_MASK_SHIFT) ? PSTR(" SFT ") : PSTR("     "), false);


  oled_write_P(PSTR("BTMGK"), false);
  static const char PROGMEM mode_logo[4][4] = {
    {0x95,0x96,0x0a,0},
    {0xb5,0xb6,0x0a,0},
    {0x97,0x98,0x0a,0},
    {0xb7,0xb8,0x0a,0} };

  if (keymap_config.swap_lalt_lgui != false) {
    oled_write_P(mode_logo[0], false);
    oled_write_P(mode_logo[1], false);
  } else {
    oled_write_P(mode_logo[2], false);
    oled_write_P(mode_logo[3], false);
  }

    oled_write_P(PSTR("Key:\n"), false  );
    oled_write(read_keylogs(), false);

 //
 // uint8_t led_usb_state = host_keyboard_leds();
 // oled_write_P(PSTR("Lock:"), false);
 // oled_write_P(led_usb_state & (1<<USB_LED_NUM_LOCK)    ? PSTR(" NUM ") : PSTR("     "), false);
 // oled_write_P(led_usb_state & (1<<USB_LED_CAPS_LOCK)   ? PSTR(" CAPS") : PSTR("     "), false);
 // oled_write_P(led_usb_state & (1<<USB_LED_SCROLL_LOCK) ? PSTR(" SCRL") : PSTR("     "), false);
}


void oled_task_user(void) {
   if (timer_elapsed32(oled_timer) > OLED_TIMEOUT) {
        oled_off();
        return;
    }
  if (is_master) {
    render_status();     // Renders the current keyboard state (layer, lock, caps, scroll, etc)
  } else {
    render_crkbd_logo();
    oled_scroll_left();  // Turns on scrolling
  }
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif

#ifdef OLED_DRIVER_ENABLE
    oled_timer = timer_read32();
  set_keylog(keycode, record);
#endif

    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
      break;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}

