#include "valrus.h"

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    [2] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    [3] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),          ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
#endif

#ifdef ENCODER_ENABLE
bool     is_cmd_tab_active = false;
uint16_t cmd_tab_timer     = 0;

/* void matrix_scan_user(void) { */
/*     if (is_cmd_tab_active) { */
/*         if (timer_elapsed(cmd_tab_timer) > 1000) { */
/*             unregister_code(KC_LGUI); */
/*             is_cmd_tab_active = false; */
/*         } */
/*     } */
/* } */

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (get_highest_layer(layer_state)) {
            case ACTIONS:
                if (clockwise) {
                    tap_code16(KC_BRID);
                } else {
                    tap_code16(KC_BRIU);
                }
                break;
            default:
                // Switch between apps on Mac with cmd tab.
                if (!is_cmd_tab_active) {
                    register_code(KC_LGUI);
                }
                is_cmd_tab_active = true;
                cmd_tab_timer     = timer_read();
                if (clockwise) {
                    tap_code16(S(KC_TAB));
                } else {
                    tap_code16(KC_TAB);
                }
                break;
        }
    } else if (index == 1) {
        switch (get_highest_layer(layer_state)) {
            case ACTIONS:
                if (clockwise) {
                    rgblight_increase_hue_noeeprom();
                } else {
                    rgblight_decrease_hue_noeeprom();
                }
                break;
            default:
                // Vertical scrolling
                if (clockwise) {
                    tap_code16(KC_MS_WH_UP);
                } else {
                    tap_code16(KC_MS_WH_DOWN);
                }
                break;
        }
    }
    return false;
}
#endif
