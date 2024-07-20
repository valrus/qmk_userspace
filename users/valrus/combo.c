#include "valrus.h"

#ifdef COMBO_ENABLE
enum combo_events {
    /* INDEX_PAREN, */
    /* MIDDLE_BRACKET, */
    /* RING_CURLY, */
    /* PINKY_ANGLE, */

    UNDO,
    CUT,
    COPY,
    PASTE,
    PASTE_MATCH,
    SELECT_ALL,
};

const uint16_t PROGMEM paren_combo[]   = {KC_D, KC_K, COMBO_END};
const uint16_t PROGMEM bracket_combo[] = {KC_C, KC_H, COMBO_END};
const uint16_t PROGMEM curly_combo[]   = {KC_X, KC_COMMA, COMBO_END};
const uint16_t PROGMEM angle_combo[]   = {KC_Z, KC_DOT, COMBO_END};

/* Hands Down combos https://sites.google.com/alanreiser.com/handsdown/home/design-notes#h.78t0l0ai08ty */
/* UNDO=x+b(z+x on QWERTY; sends cmd/ctrl-z, depending on platform.) */
/* CUT=x+l(z+c) */
/* COPY=m+l(x+c) */
/* PASTE=l+d(c+v) */
/* PASTE Match=m+d (x+v) */
/* Select ALL=x+d (z+v) */
const uint16_t PROGMEM undo_combo[]        = {KC_X, KC_D, COMBO_END};
const uint16_t PROGMEM cut_combo[]         = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM copy_combo[]        = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM paste_combo[]       = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM paste_match_combo[] = {KC_X, KC_D, COMBO_END};
const uint16_t PROGMEM select_all_combo[]  = {KC_Z, KC_D, COMBO_END};

combo_t key_combos[] = {
    /* [INDEX_PAREN]    = COMBO_ACTION(paren_combo), */
    /* [MIDDLE_BRACKET] = COMBO_ACTION(bracket_combo), */
    /* [RING_CURLY]     = COMBO_ACTION(curly_combo), */
    /* [PINKY_ANGLE]    = COMBO_ACTION(angle_combo), */

    [UNDO]        = COMBO_ACTION(undo_combo),
    [CUT]         = COMBO_ACTION(cut_combo),
    [COPY]        = COMBO_ACTION(copy_combo),
    [PASTE]       = COMBO_ACTION(paste_combo),
    [PASTE_MATCH] = COMBO_ACTION(paste_match_combo),
    [SELECT_ALL]  = COMBO_ACTION(select_all_combo)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        /* case INDEX_PAREN: */
        /*     if (pressed) { */
        /*         tap_code16(KC_LEFT_PAREN); */
        /*         tap_code16(KC_RIGHT_PAREN); */
        /*         tap_code16(KC_LEFT); */
        /*     } */
        /*     break; */
        /* case MIDDLE_BRACKET: */
        /*     if (pressed) { */
        /*         tap_code16(KC_LBRACKET); */
        /*         tap_code16(KC_RBRACKET); */
        /*         tap_code16(KC_LEFT); */
        /*     } */
        /*     break; */
        /* case RING_CURLY: */
        /*     if (pressed) { */
        /*         tap_code16(KC_LEFT_CURLY_BRACE); */
        /*         tap_code16(KC_RIGHT_CURLY_BRACE); */
        /*         tap_code16(KC_LEFT); */
        /*     } */
        /*     break; */
        /* case PINKY_ANGLE: */
        /*     if (pressed) { */
        /*         tap_code16(KC_LEFT_ANGLE_BRACKET); */
        /*         tap_code16(KC_RIGHT_ANGLE_BRACKET); */
        /*         tap_code16(KC_LEFT); */
        /*     } */
        /*     break; */
        case UNDO:
            if (pressed) {
                tap_code16(LGUI(KC_Z));
            }
            break;
        case CUT:
            if (pressed) {
                tap_code16(LGUI(KC_X));
            }
            break;
        case COPY:
            if (pressed) {
                tap_code16(LGUI(KC_C));
            }
            break;
        case PASTE:
        case PASTE_MATCH:
            if (pressed) {
                tap_code16(LGUI(KC_V));
            }
            break;
        case SELECT_ALL:
            if (pressed) {
                tap_code16(LGUI(KC_A));
            }
            break;
    }
}
#endif
