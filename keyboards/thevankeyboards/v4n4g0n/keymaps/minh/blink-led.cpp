/* paste in your keymap.c (make sure to merge/delete any duplicate functions) */

uint16_t bspace_timer = 0;
bool bspace_first_press = true;
uint8_t bspace_blink_count = 0;
bool bspace_led_on = false;
bool bspace_held = false;

bool on_layer_1 = false;
bool l1_led_on = false;
uint16_t l1_timer = 0;

void keyboard_post_init_user(void) {
  setPinOutput(B6);
  writePinHigh(B6);

  setPinOutput(B5);

  setPinOutput(B4);
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_BSPACE:
      if (record->event.pressed) {
        bspace_held = true;
        if (bspace_first_press) {
          bspace_timer = timer_read();
          bspace_first_press = false;
        }

        if (bspace_blink_count >= 3) {
          bspace_timer = timer_read();
        }
      } else {
        bspace_held = false;
      }
    break;
  }

  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
  if (state & (1<<1)) {
    on_layer_1 = true;
    writePinHigh(B5);

    l1_timer = timer_read();
    l1_led_on = true;
  } else {
    on_layer_1 = false;
    writePinLow(B5);

    l1_timer = 0;
    l1_led_on = false;
  }

  return state;
};

void matrix_scan_user(void) {
  if (on_layer_1) {
    if (timer_elapsed(l1_timer) > 500) {
      l1_timer = timer_read();
      if (l1_led_on) {
        l1_led_on = false;
        writePinLow(B5);
      } else {
        l1_led_on = true;
        writePinHigh(B5);
      }
    }
  }

  if (bspace_timer != 0) {
    if (bspace_blink_count < 3) {
      if (timer_elapsed(bspace_timer) > 125) {
        if (bspace_led_on) {
          writePinLow(B4);
        } else {
          writePinHigh(B4);
          bspace_blink_count++;
        }

        bspace_timer = timer_read();
        bspace_led_on = !bspace_led_on;
      }
    } else if (bspace_blink_count >= 3) {
      if (bspace_held) {
        bspace_timer = timer_read();
      } else {
        if (timer_elapsed(bspace_timer) > 500) {
          writePinLow(B4);
          bspace_timer = 0;
          bspace_first_press = true;
          bspace_blink_count = 0;
          bspace_led_on = false;
        } else {
          writePinHigh(B4);
          bspace_led_on = true;
        }
      }
    }
  }
}
