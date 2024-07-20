#include "valrus.h"

#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

#ifdef RGB_MATRIX_ENABLE
__attribute__((weak)) void keyboard_post_init_rgbmatrix(void) { }
#endif

void keyboard_post_init_user(void) {
#ifdef CONSOLE_ENABLE
    print("in keyboard_post_init_user");
#endif
#ifdef RGB_MATRIX_ENABLE
    keyboard_post_init_rgbmatrix();
#endif
    return;
}


__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return process_record_keymap(keycode, record)
        ;  // Close return
}


#if RGBLIGHT_ENABLE
__attribute__ ((weak)) void matrix_scan_user_rgb(void) { return; }
#endif

void matrix_scan_user(void) {
    return;
}


layer_state_t default_layer_state_set_user(layer_state_t state) {
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return state;
}

#ifdef USE_PER_KEY_TAPPING_TERM
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LCTL, KC_A):
        case MT(MOD_LALT, KC_R):
        case MT(MOD_LGUI, KC_S):
        case MT(MOD_LSFT, KC_T):
            return 400;

        case MT(MOD_LSFT, KC_N):
        case MT(MOD_LGUI, KC_E):
        case MT(MOD_LALT, KC_I):
        case MT(MOD_LCTL, KC_O):
            return 400;

        default:
            return TAPPING_TERM;
    }
}
#endif
