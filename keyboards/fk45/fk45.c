/* Copyright 2020 Nguyen Minh Hoang
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
#include "timer.h"
#include "fk45.h"

void layer_indicator_leds(void);

static bool num_lock_init_check = false;
static uint8_t led_num_flash_count = 0;
static bool led_num_on = false;
static uint16_t led_flash_time = 0;
static bool in_lock_down = false;
static bool is_all_leds_on = false;

void keyboard_pre_init_kb(void) {
  setPinOutput(INDICATOR_01);
  setPinOutput(INDICATOR_02);
  setPinOutput(INDICATOR_03);
  setPinOutput(INDICATOR_04);

  keyboard_pre_init_user();
}

void keyboard_post_init_user(void) {
  led_flash_time = timer_read();
}

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if(res && !in_lock_down && led_num_flash_count == 0) {
        // writePin(B1, led_state.num_lock);
        writePin(INDICATOR_01, led_state.caps_lock);
    }
    return res;
}

void matrix_scan_user(void) {
  if (!num_lock_init_check && TIMER_DIFF_16(timer_read(), led_flash_time) > 500) {
    num_lock_init_check = true;
    if (host_keyboard_led_state().num_lock) led_num_flash_count = 2;
    else led_num_flash_count = 1;
  }

  if (in_lock_down) {
    if (TIMER_DIFF_16(timer_read(), led_flash_time) > 250) {
      led_flash_time = timer_read();

      is_all_leds_on = !is_all_leds_on;
    }
    writePin(INDICATOR_01, is_all_leds_on);
    writePin(INDICATOR_02, is_all_leds_on);
    writePin(INDICATOR_03, is_all_leds_on);
    writePin(INDICATOR_04, is_all_leds_on);
  } else {
    if (led_num_flash_count > 0) {
      if (TIMER_DIFF_16(timer_read(), led_flash_time) > 250) {
        led_flash_time = timer_read();

        led_num_on = !led_num_on;

        if (led_num_on == false) led_num_flash_count--;
      }
      writePin(INDICATOR_01, led_num_on);
    }
    layer_indicator_leds();
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (in_lock_down) {
    if (keycode == KC_OUT && record->event.pressed) {
      in_lock_down = false;
      return false;
    }
    return !ACTION_KEY(action_for_key(biton32(layer_state), record->event.key).code);
  } else {
    if (keycode == KC_OUT && record->event.pressed) {
      in_lock_down = true;
      return false;
    }
  }
  if (keycode == KC_NLCK && !record->event.pressed) {
    if (host_keyboard_led_state().num_lock) led_num_flash_count = 2;
    else led_num_flash_count = 1;
  }
  return true;
}
