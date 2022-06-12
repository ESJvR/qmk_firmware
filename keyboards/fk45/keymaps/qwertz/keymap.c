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
#include "keymap_german_osx.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTZ,
    _LOWER,
    _RAISE,
    _OTHER,
};

#define OTHER MO(_OTHER)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Default layer
   *  ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬──────┐
   *  │Esc │ Q  │ W  │ E  │ R  │ T  │ Z  │ U  │ I  │ O  │ P  │ Ü  │      │
   *  ├────┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┐ Ent │
   *  │Tab()│ A  │ S  │ D  │ F  │ G  │ H  │ J  │ K  │ L  │ Ö  │ Ä  │     │
   *  ├─────┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─────┤
   *  │Shift  │ Y  │ X  │ C  │ V  │ B  │ N  │ M  │ ,  │ .  │ .  │ Shift  │
   *  └───┬───┴─┬──┴──┬─┴───┬┴────┴────┼────┴────┴─┬──┴──┬─┴───┬┴────┬───┘
   *      │Ctrl │ Alt │ OS  │  Space   │   Layer   │ OS  │RAlt │Ctrl │
   *      └─────┴─────┴─────┴──────────┴───────────┴─────┴─────┴─────┘
   */
  [_QWERTZ] = layout_all(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,       KC_LBRC,  XXXXXXX, \
    LT(RAISE, KC_TAB),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,    KC_QUOT,  KC_ENTER,  \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    KC_RSFT,\
    KC_LCTRL, KC_LALT, KC_LGUI,          KC_SPACE,         _______,  MO(_LOWER), KC_RGUI, KC_RALT, KC_RCTRL \
  ),
  
  /* LOWER layer
   *  ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬──────┐
   *  │Esc │ 1  │ 2  │ 3  │ 4  │ 5  │ 6  │ 7  │ 8  │ 9  │ 0  │ ß  │      │
   *  ├────┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┐ Bac │
   *  │     │    │    │    │    │    │ ←  │ ↓  │ ↑  │ →  │ +  │ #  │     │
   *  ├─────┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴────┴─────┤
   *  │       │ <  │    │    │    │    │    │    │    │    │             │
   *  └───┬───┴─┬──┴──┬─┴────┴────┴────┴────┴────┴────┴──┬─┴───┬─────┬───┘
   *      │     │     │                                  │     │OTHER│
   *      └─────┴─────┴──────────────────────────────────┴─────┴─────┘
   */
  [_LOWER] = layout_all(
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    DE_SS,   XXXXXXX, \
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, DE_PLUS, DE_HASH, KC_BSPC,  \
    _______, KC_GRV,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
    _______, _______, _______, _______,         _______,           _______,  _______, _______, MO(_OTHER) \
  ),
  /* RAISE layer
   *  ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬──────┐
   *  │    │    │ _  │ [  │ ]  │ ^  │ !  │ <  │ >  │ =  │ &  │    │      │
   *  ├────┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┐ Bac │
   *  │     │ \  │ /  │ {  │ }  │ *  │ ?  │ (  │ )  │ -  │ :  │ @  │     │
   *  ├─────┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴────┴─────┤
   *  │       │ #  │ $  │ |  │ ~  │ `  │ +  │ %  │ "  │ '  │             │
   *  └───┬───┴─┬──┴──┬─┴────┴────┴────┴────┴────┴────┴──┬─┴───┬─────┬───┘
   *      │     │     │                                  │     │     │
   *      └─────┴─────┴──────────────────────────────────┴─────┴─────┘
   */
  [_RAISE] = layout_all(
    _______, _______, DE_UNDS, DE_LBRC, DE_RBRC, KC_NUBS, DE_EXLM, KC_GRV,  DE_DEG,  DE_EQL,  DE_AMPR, _______, _______, \
    _______, DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR, DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN, DE_AT,   _______,  \
    _______, DE_HASH, DE_DLR,  DE_PIPE, DE_TILD, DE_GRV,  DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, _______, _______,\
    _______, _______, _______, _______,         _______,           _______,  _______, _______, _______ \
  ),
  /* Other layer
   *  ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬──────┐
   *  │Res │    │    │    │    │    │    │    │    │    │    │    │      │
   *  ├────┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┐     │
   *  │     │    │    │    │    │    │    │    │    │    │    │    │     │
   *  ├─────┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴────┴─────┤
   *  │       │    │    │    │    │    │    │    │    │    │             │
   *  └───┬───┴─┬──┴──┬─┴────┴────┴────┴────┴────┴────┴──┬─┴───┬─────┬───┘
   *      │     │     │                                  │     │     │
   *      └─────┴─────┴──────────────────────────────────┴─────┴─────┘
   */
  [_OTHER] = layout_all(
    RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX,  \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX,\
    _______, _______, _______, XXXXXXX,         _______,           _______,  _______, _______, _______ \
  ),
};

void layer_indicator_leds(void) {
    writePin(INDICATOR_01, biton32(layer_state) == _QWERTZ);
    writePin(INDICATOR_02, biton32(layer_state) == _LOWER);
    writePin(INDICATOR_03, biton32(layer_state) == _RAISE);
    writePin(INDICATOR_04, biton32(layer_state) == _OTHER);
}