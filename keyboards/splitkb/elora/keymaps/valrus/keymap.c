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

enum custom_keycodes {
	EPRM = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[BASE] = LAYOUT(
                /* Row 0 */
KC_F15,
KC_1, KC_2, KC_3, KC_4, KC_5,
KC_LSFT,

KC_RSFT,
KC_6, KC_7, KC_8, KC_9, KC_0,
KC_F16,

                /* Row 1 */
KC_F15,
KC_Q, KC_W, KC_F, KC_P, KC_B,
KC_LCTL,

KC_RCTL,
KC_J, KC_L, KC_U, KC_Y, KC_QUOTE,
KC_F16,

                /* Row 2 */
MT(MOD_LCTL, KC_ESCAPE),
MT(MOD_LCTL, KC_A), MT(MOD_LALT, KC_R), MT(MOD_LGUI, KC_S), MT(MOD_LSFT, KC_T), KC_G,
KC_LALT, KC_RALT,
KC_M, MT(MOD_LSFT, KC_N), MT(MOD_LGUI, KC_E), MT(MOD_LALT, KC_I), MT(MOD_LCTL, KC_O),
KC_F13,

                /* Row 3 */
TG(CAPS),
KC_Z, KC_X, KC_C, KC_D, KC_V,
KC_PGUP, KC_HYPR,
KC_MEH, KC_PGDN,
KC_SLASH, KC_K, KC_H, KC_COMMA, KC_DOT,
KC_F14,

                /* Row 4 */
TG(GAMING), TT(NUMERIC), OSL(SYMBOLS), MT(MOD_LSFT, KC_BSPACE), MT(MOD_LGUI, KC_ESCAPE),
MT(MOD_LGUI, KC_ENTER), MT(MOD_LSFT, KC_SPACE), OSL(SYMBOLS), TT(NUMERIC), TG(ACTIONS)),


[SYMBOLS] =
LAYOUT(

                /* Row 0 */
___,
KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,
___,
___,
KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
___,

                /* Row 1 */
___, KC_EXCLAIM, KC_CIRCUMFLEX, KC_HASH, KC_PLUS, KC_PERCENT,
___,
___,
KC_PIPE, KC_AMPERSAND, KC_ASTERISK, KC_DOLLAR, KC_GRAVE, ___,

                /* Row 2 */
___, KC_AT, KC_SCOLON, KC_COLON, KC_MINUS, KC_EQUAL,
___,
___,
KC_TILDE, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, ___,

                /* Row 3 */
___,
KC_LEFT_ANGLE_BRACKET, KC_LEFT_CURLY_BRACE, KC_LBRACKET, KC_LEFT_PAREN, KC_TILDE,
KC_HOME, ___,
___, KC_END,
KC_BSLASH, KC_RIGHT_PAREN, KC_RBRACKET, KC_RIGHT_CURLY_BRACE, KC_RIGHT_ANGLE_BRACKET,
___,

                /* Row 4 */
___, ___, TG(SYMBOLS), KC_DELETE, KC_TAB, KC_TAB, KC_UNDERSCORE, TG(SYMBOLS), ___, ___
       ),


[ACTIONS] = LAYOUT(
                /* Row 0 */
EE_CLR,
___, ___, ___, KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP,
___,
___,
___, ___, ___, ___, ___,
___,

                /* Row 1 */
KC_F13,
___, ___, KC_MS_UP, ___, ___,
___,
___,
___, ___, ___, ___, ___,
KC_F17,

                /* Row 2 */
KC_F12,
___, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, ___,
___,
___,
___, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT,
KC_F16,

                /* Row 3 */
KC_F11,
___, ___, ___, ___, ___,
RGB_MOD, RGB_HUI,
RGB_VAI, RGB_TOG,
___, ___, ___, ___, ___,
KC_F15,

                /* Row 4 */
___, KC_MS_BTN2, KC_MS_BTN1, KC_MS_BTN3, KC_MS_BTN4,
KC_MS_BTN4, KC_MS_BTN3, KC_MS_BTN1, KC_MS_BTN2, ___
                   ),


[NUMERIC] = LAYOUT(
___, KC_1, KC_2, KC_3, KC_4, KC_5, ___,   ___,           KC_6, KC_7, KC_8, KC_9, KC_0, ___,
___, KC_1, KC_2, KC_3, KC_4, KC_5, ___,   ___,           KC_6, KC_7, KC_8, KC_9, KC_0, ___,
___, ___, ___, ___, ___, ___,      ___,   ___,      ___, KC_4, KC_5, KC_6, ___, ___,
___, ___, ___, ___, ___, ___, ___, ___,   ___, ___, ___, KC_1, KC_2, KC_3, ___, ___,
               ___, ___, ___, ___, ___,   ___, ___, KC_0, ___, ___), 

[GAMING] = LAYOUT(
                /* Row 0 */
___,
___, ___, ___, ___, ___,
___,

___,
___, ___, ___, ___, ___,
___,

                /* Row 1 */
KC_TAB,
KC_Q, KC_E, KC_W, KC_R, KC_T,
KC_LCTL,

KC_RCTL,
KC_Y, KC_U, KC_I, KC_O, KC_P,
KC_BSPC,

                /* Row 2 */
KC_TAB,
KC_G, KC_A, KC_S, KC_D, KC_F,
___,

___,
KC_SCLN, KC_H, KC_J, KC_K, KC_L,
___,

                /* Row 3 */
KC_LSFT,
KC_Z, KC_X, KC_C, KC_V, KC_B,
___, ___,

___, ___,
KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
KC_RSFT,
                /* Row 4 */
___, KC_ENTER, KC_BSPACE, KC_SPACE, KC_ESCAPE,
KC_ENTER, KC_SPACE, KC_LCTL, ___, ___
),

/* QWFPB JLUY' */
/* ARSTG MNEIO */
/* ZXCDV /KH,. */

[CAPS] = LAYOUT(
                /* Row 0 */
___,
___, ___, ___, ___, ___,
___,
___,
___, ___, ___, ___, ___,
___,

                /* Row 1 */
___, LSFT(KC_Q), LSFT(KC_W), LSFT(KC_F), LSFT(KC_P), LSFT(KC_B),
___,
___,
LSFT(KC_J), LSFT(KC_L), LSFT(KC_U), LSFT(KC_Y), ___, ___,

                /* Row 2 */
___, LSFT(KC_A), LSFT(KC_R), LSFT(KC_S), LSFT(KC_T), LSFT(KC_G),
___,
___,
LSFT(KC_M), LSFT(KC_N), LSFT(KC_E), LSFT(KC_I), LSFT(KC_O), ___,

                /* Row 3 */
___, LSFT(KC_Z), LSFT(KC_X), LSFT(KC_C), LSFT(KC_D), LSFT(KC_V), ___, ___,
___, ___, ___, LSFT(KC_K), LSFT(KC_H), ___, ___, ___,

                /* Row 4 */
___, ___, ___, ___, ___,
___, ___, ___, ___, ___)
};
