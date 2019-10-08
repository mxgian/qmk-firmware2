#pragma once

#include "config_common.h"


//added this section to add RGB underglow support
#ifdef RGBLED_NUM
#undef RGBLED_NUM
#endif

#define RGB_DI_PIN F5
#ifdef RGB_DI_PIN
 #define RGBLED_NUM 12
 #define RGBLIGHT_HUE_STEP 8
 #define RGBLIGHT_SAT_STEP 8
 #define RGBLIGHT_VAL_STEP 8
 #define RGBLIGHT_ANIMATIONS
#endif
