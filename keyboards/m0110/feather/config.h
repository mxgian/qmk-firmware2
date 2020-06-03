#define FEATHER_CONFIG_H

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 16

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
*/
//TODO: set up row  and cols
#define MATRIX_ROW_PINS {A0, A1, A2, A3, A4}
#define MATRIX_COL_PINS {}
//#define MATRIX_COL_PINS { GPA4, GPA3, GPA2, GPA5, GPA6, GPA7, GPB2, GPB1, GPB0, GPB3, GPB4, GB5, GB6, GB7 }

#define UNUSED_PINS

#define AdafruitBleResetPin D4
#define AdafruitBleCSPin B4
#define AdafruitBleIRQPin E6
