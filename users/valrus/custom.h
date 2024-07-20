#pragma once
#include "valrus.h"

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_rgb(void);
#endif

void keyboard_post_init_user(void);

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

#ifdef OLED_DRIVER_ENABLE
bool process_record_oled(uint16_t keycode, keyrecord_t *record);
#endif

#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)
layer_state_t default_layer_state_set_user_rgb(layer_state_t state);
layer_state_t layer_state_set_user_rgb(layer_state_t state);
#endif
