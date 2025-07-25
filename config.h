#pragma once

#define SPLIT_MODS_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_LAYER_STATE_ENABLE

#define PERMISSIVE_HOLD
#define QUICK_TAP_TERM 0

#define TAPPING_TERM 160

#define LEADER_TIMEOUT 250
#define LEADER_PER_KEY_TIMING
#define LEADER_NO_TIMEOUT

#define RGBLIGHT_LED_COUNT 68
#define RGBLIGHT_DEFAULT_HUE 0
#define RGBLIGHT_DEFAULT_SAT 0
#define RGBLIGHT_SPLIT
#define RGBLED_SPLIT { 34, 34 }
#define RGBLIGHT_SLEEP
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT

#undef RGBLIGHT_EFFECT_ALTERNATING
#undef RGBLIGHT_EFFECT_BREATHING
#undef RGBLIGHT_EFFECT_CHRISTMAS
#undef RGBLIGHT_EFFECT_KNIGHT
#undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#undef RGBLIGHT_EFFECT_RGB_TEST
#undef RGBLIGHT_EFFECT_SNAKE
#undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#undef RGBLIGHT_EFFECT_TWINKLE
#undef RGBLIGHT_ANIMATIONS

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define NO_ACTION_ONESHOT
#define NO_MUSIC_MODE
