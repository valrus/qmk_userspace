USER_NAME := valrus
ENCODER_ENABLE = yes

RGBLIGHT_ENABLE = no
RGBLIGHT_LAYERS = no
RGBLIGHT_ANIMATIONS = no

RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = ws2812
RGB_MATRIX_CUSTOM_USER = no

OLED_ENABLE = no
OLED_DRIVER_ENABLE = no

CONSOLE_ENABLE = no

COMBO_ENABLE = yes

NKRO_ENABLE = yes

AUDIO_ENABLE = no

JOYSTICK_ENABLE = yes

# Incompatible with Vial
PER_KEY_TAPPING_TERM_ENABLE = yes

# Supported keycodes
MOUSEKEY_ENABLE = yes      # Mouse movement using keys
EXTRAKEY_ENABLE = yes      # Audio and system control

# Space savers
LTO_ENABLE = yes
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
SPACE_CADET_ENABLE = no

SRC += rgbmatrix.c
SRC += encoder.c
QUANTUM_LIB_SRC += i2c_master.c

## Vial-specific settings

VIA_ENABLE = no
VIAL_ENABLE = no
VIALRGB_ENABLE = no
# ENCODER_MAP_ENABLE = yes
