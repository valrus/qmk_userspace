#undef TAPPING_TERM
#define TAPPING_TERM 140

#define MYRIAD_ENABLE

#define ENCODER_RESOLUTION 2

#define TAPPING_TOGGLE 1
#define DYNAMIC_KEYMAP_LAYER_COUNT 8
#define VIA_EEPROM_LAYOUT_OPTIONS_SIZE 2
#define SPLIT_LAYER_STATE_ENABLE

#ifdef RGB_MATRIX_ENABLE
    #ifdef RGB_MATRIX_DEFAULT_MODE
        #undef RGB_MATRIX_DEFAULT_MODE
    #endif
    #define RGB_DISABLE_WHEN_USB_SUSPENDED
    #define ENABLE_RGB_MATRIX_STARLIGHT_DUAL_HUE
    #define RGB_MATRIX_LAYERS
#endif

// Min 0, max 32
#define JOYSTICK_BUTTON_COUNT 1
// Min 0, max 6: X, Y, Z, Rx, Ry, Rz
#define JOYSTICK_AXIS_COUNT 2
// Min 8, max 16
#define JOYSTICK_AXIS_RESOLUTION 10

// Allows to use either side as the master. Look at the documentation for info:
// https://docs.qmk.fm/#/config_options?id=setting-handedness
// #define EE_HANDS

#define VIAL_KEYBOARD_UID {0xB3, 0x8D, 0x94, 0xDA, 0xB3, 0xD7, 0xDC, 0x3D}
#define VIAL_COMBO_ENTRIES 32
#define VIAL_UNLOCK_COMBO_ROWS { 3, 9 }
#define VIAL_UNLOCK_COMBO_COLS { 2, 5 }
