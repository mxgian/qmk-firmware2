#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    TheRoyalSweatshirt
#define PRODUCT         romac
#define DESCRIPTION     A *Plaid inspired twelve-key macropad
/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 3

/* for QMK DFU */
#define QMK_ESC_OUTPUT F7 // usually COL
#define QMK_ESC_INPUT D4 // usually ROW
#define QMK_LED B0
//#define QMK_SPEAKER C6


/* key matrix pins */
#define MATRIX_ROW_PINS { D4, C6, D7, E6 }
#define MATRIX_COL_PINS { F7, B1, B3 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */

#define BACKLIGHT_LEVELS 0

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

//added this section to add RGB underglow support
#define RGB_DI_PIN F5
#ifdef RGB_DI_PIN
 #define RGBLED_NUM 12
 #define RGBLIGHT_HUE_STEP 8
 #define RGBLIGHT_SAT_STEP 8
 #define RGBLIGHT_VAL_STEP 8
 #define RGBLIGHT_ANIMATIONS
#endif
