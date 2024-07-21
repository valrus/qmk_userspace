#include "valrus.h"

// Backlight timeout feature
#define BACKLIGHT_TIMEOUT 50    // in minutes
static uint16_t idle_timer = 0;
static uint8_t halfmin_counter = 0;
static uint8_t old_backlight_level = -1;
static uint8_t old_hue = -1;
static uint8_t old_sat = -1;
static bool led_on = true;

bool process_record_user_rgb(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        if (led_on == false || old_backlight_level == -1) {
            if (old_backlight_level == -1) {
                old_hue = rgblight_get_hue();
            }
            if (old_backlight_level == -1) {
                old_sat = rgblight_get_sat();
            }
            if (old_backlight_level == -1) {
                old_backlight_level = rgblight_get_val();
            }
            rgblight_sethsv_noeeprom(old_hue, old_sat, old_backlight_level);
            led_on = true;
        }

        idle_timer = timer_read();
        halfmin_counter = 0;
    }
    return true;
  }

void matrix_scan_user_rgb(void) {
    // idle_timer needs to be set one time
    if (idle_timer == 0) {
        idle_timer = timer_read();
    }

    if (led_on && timer_elapsed(idle_timer) > 30000) {
        halfmin_counter++;
        idle_timer = timer_read();
    }

    if (led_on && halfmin_counter >= BACKLIGHT_TIMEOUT * 2) {
        old_backlight_level = rgblight_get_val();
        old_hue = rgblight_get_hue();
        old_sat = rgblight_get_sat();
        rgblight_sethsv_noeeprom(old_hue, old_sat, 0);
        led_on = false;
        halfmin_counter = 0;
    }
}


#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)
/* https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgblight#lighting-layers */
const rgblight_segment_t PROGMEM my_base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 54, HSV_WHITE}
);

const rgblight_segment_t PROGMEM my_symbols_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 54, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM my_actions_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 54, HSV_CYAN}
);

const rgblight_segment_t PROGMEM my_numeric_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 54, HSV_SPRINGGREEN}
);

const rgblight_segment_t PROGMEM my_caps_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 54, HSV_BLUE}
);

const rgblight_segment_t PROGMEM my_gaming_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 54, HSV_PINK}
);
// etc..

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_base_layer,
    my_symbols_layer,
    my_actions_layer,
    my_numeric_layer,
    my_gaming_layer,
    my_caps_layer
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
    rgblight_set_layer_state(4, layer_state_cmp(state, GAMING));
    rgblight_set_layer_state(5, layer_state_cmp(state, CAPS));
    return state;
}
#endif
