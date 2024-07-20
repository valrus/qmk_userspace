#pragma once

#include QMK_KEYBOARD_H
#include "quantum.h"
#include "version.h"
#include "custom.h"

// legacy keycodes
#define KC_RBRACKET KC_RBRC
#define KC_LBRACKET KC_LBRC
#define KC_BSPACE KC_BSPC
#define KC_SCOLON KC_SEMICOLON
#define KC_BSLASH KC_BACKSLASH

enum layer_codes {
    BASE,
    SYMBOLS,
    ACTIONS,
    NUMERIC,
    GAMING,
    CAPS,
};

// helper
#define _HSV(H, S, V) (HSV){ .h = H, .s = S, .v = V }
