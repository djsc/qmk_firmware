/* Copyright 2019 Danny Nguyen <danny@keeb.io>
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

// Macros
enum {
    VIDEO_SPEED_DOWN,
    VIDEO_SPEED_RESET,
    VIDEO_SPEED_UP,
    SKIP_BACK,
    PLAY_TOGGLE,
    SKIP_FORWARD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        VIDEO_SPEED_DOWN, VIDEO_SPEED_RESET, VIDEO_SPEED_UP,
        SKIP_BACK  , PLAY_TOGGLE  , SKIP_FORWARD,
        KC_AUDIO_VOL_DOWN, KC_AUDIO_MUTE, KC_AUDIO_VOL_UP
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case VIDEO_SPEED_DOWN:
                SEND_STRING(SS_DOWN(X_LALT) SS_DOWN(X_LSHIFT) "z" SS_UP(X_LSHIFT) SS_UP(X_LALT));
                return false;
                break;
            case VIDEO_SPEED_RESET:
                SEND_STRING(SS_DOWN(X_LALT) SS_DOWN(X_LSHIFT) "x" SS_UP(X_LSHIFT) SS_UP(X_LALT));
                return false;
                break;
            case VIDEO_SPEED_UP:
                SEND_STRING(SS_DOWN(X_LALT) SS_DOWN(X_LSHIFT) "c" SS_UP(X_LSHIFT) SS_UP(X_LALT));
                return false;
                break;
            case SKIP_BACK:
                SEND_STRING(SS_DOWN(X_LALT) SS_DOWN(X_LSHIFT) "a" SS_UP(X_LSHIFT) SS_UP(X_LALT));
                return false;
                break;
            case PLAY_TOGGLE:
                SEND_STRING(SS_DOWN(X_LALT) SS_DOWN(X_LSHIFT) "q" SS_UP(X_LSHIFT) SS_UP(X_LALT));
                return false;
                break;
            case SKIP_FORWARD:
                SEND_STRING(SS_DOWN(X_LALT) SS_DOWN(X_LSHIFT) "d" SS_UP(X_LSHIFT) SS_UP(X_LALT));
                return false;
                break;
        }
    }
    return true;
}