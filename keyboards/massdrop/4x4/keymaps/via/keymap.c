/* Copyright 2021 Cloud-Lee
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base */
    [0] = LAYOUT(
        KC_1, KC_2, KC_3, KC_4,
        KC_5, KC_6, KC_7, KC_8,
        KC_9, KC_0, KC_A, KC_B,
        KC_C, KC_D, KC_E, MO(1)
    ),

    [1] = LAYOUT(
        RESET,   EEP_RST,  RGB_TOG, XXXXXXX,
        RGB_MOD, RGB_HUI,  RGB_SAI, RGB_VAI,
        RGB_RMOD,RGB_HUD,  RGB_SAD, RGB_VAD,
        XXXXXXX, XXXXXXX,  DEBUG,   KC_TRNS
    ),

    [2] = LAYOUT( /* Empty for dynamic keymaps */
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [3] = LAYOUT( /* Empty for dynamic keymaps */
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (IS_LAYER_ON(0)) {
            if (clockwise) {
                //tap_code(KC_VOLU);
                rgblight_decrease_val();
            } else {
                //tap_code(KC_VOLD);
                rgblight_increase_val();
            }
        } else if (IS_LAYER_ON(1)){
            if (clockwise) {
                //rgblight_increase_val();
            } else {
                //rgblight_decrease_val();
            }
        }
    }
    return true;
}
#endif
