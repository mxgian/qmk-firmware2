<<<<<<< HEAD
#ifndef CONFIG_H
#define CONFIG_H
=======
#pragma once
>>>>>>> 7085066f0860087fa140241d25b29ad5f60c8179

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
<<<<<<< HEAD
#define PRODUCT_ID      0x6060
=======
#define PRODUCT_ID      0x4140
>>>>>>> 7085066f0860087fa140241d25b29ad5f60c8179
#define DEVICE_VER      0x0001
#define MANUFACTURER    Triangle_Lab
#define PRODUCT         TR60W
#define DESCRIPTION     Keyboard

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 14

/* key matrix pins */
#define MATRIX_ROW_PINS { D0, D1, B1, B2, E6, B3 }
#define MATRIX_COL_PINS { F5, F4, F1, F0, B0, D5, D3, D6, D7, B4, B5, B6, C6, D2 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */
#define BACKLIGHT_PIN B7
#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 3
#endif

/* Set 0 if debouncing isn't needed */
<<<<<<< HEAD
#define DEBOUNCING_DELAY 5
=======
#define DEBOUNCE 5
>>>>>>> 7085066f0860087fa140241d25b29ad5f60c8179

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

<<<<<<< HEAD
/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/* prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS

=======
>>>>>>> 7085066f0860087fa140241d25b29ad5f60c8179
#define RGB_DI_PIN F7
#ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 4
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#endif
<<<<<<< HEAD

#endif
=======
>>>>>>> 7085066f0860087fa140241d25b29ad5f60c8179
