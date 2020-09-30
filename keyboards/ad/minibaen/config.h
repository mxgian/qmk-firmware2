/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

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

/* USB Device descriptor parameter */
#define VENDOR_ID       0xADAD
#define PRODUCT_ID      0x6D62 /* "MB" */
#define DEVICE_VER      0x0001
#define MANUFACTURER AeternusDecorum
#define PRODUCT Minibaen
#define DESCRIPTION Minibaen Keyboard

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 13

#define MATRIX_ROW_PINS { A10, B11, B8, F0 }
#define MATRIX_COL_PINS { B2, B1, B0, A7, A6, A5, A4, A3, A2, A1, F1, B9, B7 }

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE
