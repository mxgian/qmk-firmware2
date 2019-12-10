#include "tr60w.h"
<<<<<<< HEAD
=======

bool led_update_kb(led_t led_state) {
    bool runDefault = led_update_user(led_state);
    if (runDefault) {
      writePin(B1, !led_state.num_lock);
      writePin(B2, !led_state.caps_lock);
      writePin(B3, !led_state.scroll_lock);
    }
    return runDefault;
}
>>>>>>> 7085066f0860087fa140241d25b29ad5f60c8179
