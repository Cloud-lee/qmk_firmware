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
    /* First encoder */
    if (index == 0) {
        if (IS_LAYER_ON(0)) {
            if (clockwise) {
                //tap_code(KC_VOLU);
                rgblight_increase_val();
            } else {
                //tap_code(KC_VOLD);
                rgblight_decrease_val();
            }
#if 0
            dprintf("mode = %d\n", rgb_matrix_get_mode());
            dprintf("hue = %d\n", rgb_matrix_get_hue());
            dprintf("sat = %d\n", rgb_matrix_get_sat());
            dprintf("val = %d\n", rgb_matrix_get_val());
            dprintf("speed = %d\n", rgb_matrix_get_speed());
#endif
        }
    }
    return true;
}
#endif

#if 1
void matrix_init_user(void) {
    //debug_enable = true; // for dprintf() enable or not
    rgblight_enable();
    rgblight_mode(RGB_MATRIX_BREATHING);
    rgblight_sethsv(255,0,255);
    rgblight_set_speed(50);
    //eeconfig_disable();
}
#endif
