#ifdef OLED_DRIVER_ENABLE
#    define OLED_DISPLAY_128X64
#    define OLED_TIMEOUT 60000
#endif

#undef TAPPING_TERM
#define TAPPING_TERM 140
#define TAPPING_TERM_PER_KEY

#define ENCODER_RESOLUTION 2

#define TAPPING_TOGGLE 1

#ifdef RGBLIGHT_ENABLE
#    undef RGBLIGHT_ANIMATIONS
#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 8
#    define RGBLIGHT_SLEEP
#    undef RGBLIGHT_LIMIT_VAL
#    define RGBLIGHT_LIMIT_VAL 120
#    define RGBLIGHT_LAYERS
#endif

// Allows to use either side as the master. Look at the documentation for info:
// https://docs.qmk.fm/#/config_options?id=setting-handedness
// #define EE_HANDS
