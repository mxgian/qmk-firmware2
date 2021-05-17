 /*
 Copyright 2020 Garret Gartner

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

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x4B4B // "KK"
#define PRODUCT_ID      0x1225
#define DEVICE_VER      0x0011
#define MANUFACTURER    Kingly-Keys
#define PRODUCT         Clarabelle

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 17

#define MATRIX_ROW_PINS { F0, F1, C7, F4 }
#define MATRIX_COL_PINS {  F5, F6, F7, C6, B4, D7, D6, D4, D5, D3, D2, D1, D0, B3, B2, B5, B1}
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE