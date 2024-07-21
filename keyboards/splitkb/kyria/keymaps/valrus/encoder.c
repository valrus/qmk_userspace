#include "valrus.h"

#ifdef ENCODER_ENABLE
bool     is_cmd_tab_active = false;
uint16_t cmd_tab_timer     = 0;

void matrix_scan_user(void) {
    if (is_cmd_tab_active) {
        if (timer_elapsed(cmd_tab_timer) > 1000) {
            unregister_code(KC_LGUI);
            is_cmd_tab_active = false;
        }
    }
}

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
