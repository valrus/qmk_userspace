/* Copyright 2020 valrus
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "valrus.h"

#define ___ KC_TRNS
#define _X_ KC_NO

// legacy keycodes
#define KC_RBRACKET KC_RBRC
#define KC_LBRACKET KC_LBRC

enum custom_keycodes {
	EPRM = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[BASE] = LAYOUT(
                /* Row 1 */
MT(MOD_LCTL, KC_ESCAPE),
KC_Q, KC_W, KC_F, KC_P, KC_B,
KC_J, KC_L, KC_U, KC_Y, KC_QUOTE,
KC_F13,

                /* Row 2 */
TG(CAPS),
MT(MOD_LCTL, KC_A), MT(MOD_LALT, KC_R), MT(MOD_LGUI, KC_S), MT(MOD_LSFT, KC_T), KC_G,
KC_M, MT(MOD_LSFT, KC_N), MT(MOD_LGUI, KC_E), MT(MOD_LALT, KC_I), MT(MOD_LCTL, KC_O),
KC_F14,

                /* Row 3 */
KC_Z, KC_X, KC_C, KC_D, KC_V,
KC_SLASH, KC_K, KC_H, KC_COMMA, KC_DOT,

                /* Thumbs */
TT(NUMERIC), OSL(SYMBOLS), MT(MOD_LSFT, KC_BSPACE), MT(MOD_LGUI, KC_ESCAPE),
MT(MOD_LGUI, KC_ENTER), MT(MOD_LSFT, KC_SPACE), OSL(SYMBOLS), TT(NUMERIC)
                ),


[SYMBOLS] =
LAYOUT(
KC_F15, KC_EXCLAIM, KC_CIRCUMFLEX, KC_HASH, KC_PLUS, KC_PERCENT,
KC_PIPE, KC_AMPERSAND, KC_ASTERISK, KC_DOLLAR, KC_GRAVE, KC_PGUP,

KC_F16, KC_AT, KC_SCOLON, KC_COLON, KC_MINUS, KC_EQUAL,
KC_TILDE, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_PGDN,

KC_LEFT_ANGLE_BRACKET, KC_LEFT_CURLY_BRACE, KC_LBRACKET, KC_LEFT_PAREN, KC_TILDE,
KC_BSLASH, KC_RIGHT_PAREN, KC_RBRACKET, KC_RIGHT_CURLY_BRACE, KC_RIGHT_ANGLE_BRACKET,

___, TG(SYMBOLS), KC_DELETE, KC_TAB,
KC_TAB, KC_UNDERSCORE, TG(SYMBOLS), ___
       ),


[ACTIONS] = LAYOUT(
KC_F15, ___, KC_MS_UP, ___, ___, ___,
___, ___, ___, ___, ___, KC_F16,

KC_F17, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, ___, ___,
___, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, KC_F18,

___, ___, ___, ___, ___,
___, ___, ___, ___, ___,

KC_MS_BTN2, KC_MS_BTN1, KC_MS_BTN3, KC_MS_BTN4,
KC_MS_BTN4, KC_MS_BTN3, KC_MS_BTN1, KC_MS_BTN2
                   ),


[NUMERIC] = LAYOUT(
___, KC_1, KC_2, KC_3, KC_4, KC_5,                  KC_6, KC_7, KC_8, KC_9, KC_0, ___,
___, ___, ___, ___, ___, ___,                       ___, KC_4, KC_5, KC_6, ___, ___,
     ___, ___, ___, ___, ___,                       ___, KC_1, KC_2, KC_3, ___,
                    ___, ___, ___, ___,   ___, ___, KC_0, ___),

[GAMING] = LAYOUT(
KC_LCTL, ___, KC_W, ___, ___, ___,                       ___, ___, ___, ___, ___, ___,
KC_LSFT, KC_A, KC_S, KC_D, ___, ___,                       ___, KC_H, KC_J, KC_K, KC_L, KC_LSFT,
         ___, ___, ___, ___, ___,                       ___, ___, ___, ___, ___,
KC_BSPACE, KC_DELETE, KC_SPACE, KC_ENTER,   KC_ENTER, KC_SPACE, KC_LCTL, ___),

[CAPS] = LAYOUT(
___, LSFT(KC_Q), LSFT(KC_W), LSFT(KC_F), LSFT(KC_P), LSFT(KC_B),
LSFT(KC_J), LSFT(KC_L), LSFT(KC_U), LSFT(KC_Y), ___, ___,

___, LSFT(KC_A), LSFT(KC_R), LSFT(KC_S), LSFT(KC_T), LSFT(KC_G),
LSFT(KC_M), LSFT(KC_N), LSFT(KC_E), LSFT(KC_I), LSFT(KC_O), ___,

LSFT(KC_Z), LSFT(KC_X), LSFT(KC_C), LSFT(KC_D), LSFT(KC_V),
___, LSFT(KC_K), LSFT(KC_H), ___, ___,

___, ___, ___, ___,
___, ___, ___, ___)
};
