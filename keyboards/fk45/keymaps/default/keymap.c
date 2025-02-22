/* Copyright 2020 Nguyen Minh HOang

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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _DEF,
    _FN1,
    _FN2,
    _FN3,
};

#define CMD_COPY LCTL(KC_INS)
#define CMD_PASTE LSFT(KC_INS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEF] = layout_all(
    KC_LBRC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_RBRC, KC_BSPACE, \
       KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCOLON,    KC_ENTER,  XXXXXXX,  \
     KC_LSHIFT,   KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_RSHIFT, MO(_FN3),\
      KC_LCTRL,  KC_LGUI, KC_LALT, MO(_FN1),         KC_SPACE,       MO(_FN2),  KC_RALT, KC_RGUI, KC_RCTRL \
  ),
  [_FN1] = layout_all(
    KC_GRAVE, KC_1, KC_2, KC_3, KC_4, _______, _______, _______, _______, _______, _______, _______,     _______, \
       KC_ESC, KC_5, KC_6, KC_7, KC_8, _______, _______, _______, KC_QUOTE, _______, _______,    _______,  XXXXXXX,  \
     _______,   KC_9, KC_0, KC_MINUS, KC_EQUAL, _______, _______, _______, _______, _______, _______, XXXXXXX,\
      _______,  _______, _______, MO(_FN1),         _______,       XXXXXXX,  _______, _______, _______ \
  ),
  [_FN2] = layout_all(
    _______, _______, _______, _______, _______, _______, _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,     _______, \
       _______, _______, _______, _______, _______, _______, _______, KC_F6, KC_F7, KC_F8, KC_F9,    KC_PSCR,  XXXXXXX,  \
     _______,   _______, _______, _______, _______, _______, _______, KC_F10, KC_F11, KC_F12, _______, XXXXXXX,\
      _______,  _______, _______, XXXXXXX,         _______,       MO(_FN2),  _______, _______, _______ \
  ),
  [_FN3] = layout_all(
    KC_CAPS, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_UP, KC_END, KC_BSLASH,     KC_DEL, \
       _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT,    RALT(KC_PSCR),  XXXXXXX,  \
     _______,   KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, KC_INS, KC_PGDN, KC_PGUP, _______, MO(_FN3),\
            KC_OUT,  _______, _______, XXXXXXX,         _______,       XXXXXXX,  _______, _______, _______ \
  ),
};

void layer_indicator_leds(void) {
    writePin(INDICATOR_02, biton32(layer_state) == _FN1);
    writePin(INDICATOR_03, biton32(layer_state) == _FN2);
    writePin(INDICATOR_04, biton32(layer_state) == _FN3);
}