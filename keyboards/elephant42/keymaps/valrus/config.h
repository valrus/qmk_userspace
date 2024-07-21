#undef TAPPING_TERM
#define TAPPING_TERM 140

#define TAPPING_TOGGLE 1

#ifdef RGBLIGHT_ENABLE
#    undef RGBLIGHT_ANIMATIONS
#    undef RGBLIGHT_LIMIT_VAL
#    define RGBLIGHT_SLEEP
#    define RGBLIGHT_LIMIT_VAL 120
#    define RGBLIGHT_LAYERS
#endif

#define SPLIT_TRANSPORT_MIRROR
#define MASTER_RIGHT

// Allows to use either side as the master. Look at the documentation for info:
// https://docs.qmk.fm/#/config_options?id=setting-handedness
// #define EE_HANDS
