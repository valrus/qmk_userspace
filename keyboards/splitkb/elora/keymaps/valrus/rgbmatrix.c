#include "valrus.h"

#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

#if defined(RGB_MATRIX_ENABLE) && defined(RGB_MATRIX_LAYERS)

void keyboard_post_init_rgbmatrix(void) {
    rgb_matrix_enable_noeeprom();
    rgb_matrix_sethsv(HSV_TEAL);
    rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
#ifdef CONSOLE_ENABLE
    print("in keyboard_post_init_kb");
#endif
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    HSV hsv = (HSV){HSV_TEAL};

    switch(get_highest_layer(layer_state|default_layer_state)) {
        case GAMING:
            hsv = (HSV){HSV_MAGENTA};
            break;
        case CAPS:
            hsv = (HSV){HSV_BLUE};
            break;
        case NUMERIC:
            hsv = (HSV){HSV_SPRINGGREEN};
            break;
        case ACTIONS:
            hsv = (HSV){HSV_GOLDENROD};
            break;
        case SYMBOLS:
            hsv = (HSV){HSV_PURPLE};
            break;
        default:
            break;
    }

    // limit brightness
    if (hsv.v > rgb_matrix_get_val()) {
        hsv.v = rgb_matrix_get_val();
    }

    RGB rgb = hsv_to_rgb(hsv);

    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }

    return false;
}

#endif
