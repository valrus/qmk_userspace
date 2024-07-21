#include "valrus.h"

#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)
/* https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgblight#lighting-layers */
const rgblight_segment_t PROGMEM my_base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 20, HSV_WHITE}
);

const rgblight_segment_t PROGMEM my_symbols_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 20, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM my_actions_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 20, HSV_CYAN}
);

const rgblight_segment_t PROGMEM my_numeric_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 20, HSV_SPRINGGREEN}
);

const rgblight_segment_t PROGMEM my_caps_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 20, HSV_BLUE}
);

const rgblight_segment_t PROGMEM my_gaming_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 20, HSV_PINK}
);
// etc..

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_base_layer,
    my_symbols_layer,
    my_actions_layer,
    my_numeric_layer,
    my_caps_layer,
    my_gaming_layer
);

void keyboard_post_init_rgb(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user_rgb(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, BASE));
    return state;
}

layer_state_t layer_state_set_user_rgb(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, SYMBOLS));
    rgblight_set_layer_state(2, layer_state_cmp(state, ACTIONS));
    rgblight_set_layer_state(3, layer_state_cmp(state, NUMERIC));
    rgblight_set_layer_state(4, layer_state_cmp(state, CAPS));
    rgblight_set_layer_state(5, layer_state_cmp(state, GAMING));
    return state;
}
#endif
