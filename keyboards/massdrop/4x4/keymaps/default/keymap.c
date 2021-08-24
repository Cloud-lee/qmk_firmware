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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKURL = SAFE_RANGE,
    MD_BOOT,    //Restart into bootloader after hold timeout
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_1, KC_2, KC_3, KC_4,
        KC_5, KC_6, KC_7, KC_8,
        KC_9, KC_0, KC_A, KC_B,
        KC_C, KC_D, KC_E, MO(_FN)
    ),

    [_FN] = LAYOUT(
        MD_BOOT, EEP_RST,  RGB_TOG, XXXXXXX,
        RGB_MOD, RGB_HUI,  RGB_SAI, RGB_VAI,
        RGB_RMOD,RGB_HUD,  RGB_SAD, RGB_VAD,
        QMKURL,  XXXXXXX,  DEBUG,   KC_TRNS
    )
};

#if 0
void rgb_matrix_indicators_user(void) {
    //rgb_matrix_set_color(0, 100, 100, 0);
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                //SEND_STRING("https://qmk.fm/\n");
                rgb_matrix_set_color(0, 100, 100, 0);
            } else {
                // when keycode QMKURL is released
            }
            return true;

        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    SEND_STRING("75_non_pro MCU reset\n"); // #ifdef DEBUG_ACTION
                    reset_keyboard();
                }
            }
            return true;

        case KC_LSHIFT:
            if (record->event.pressed) {
                // when keycode KC_LSHIFT is pressed
                //SEND_STRING("SEND_STRING KC_LSHIFT"); // print msg, if, #ifdef DEBUG_ACTION
                dprintf("dprint KC_LSHIFT\n");  // print msg, if Quantum key DEBUG is on
                dprintf("PLATFORM_NAME = %s\n", PLATFORM_NAME);
                //setPinOutput(A8);
                //togglePin(A8);
                //writePinHigh(A8);
                //palSetLine(A8);
                //bh1750_i2c_init();


            } else {
                // when keycode KC_LSHIFT is released
            }
            return true;

        case RGB_MOD:
            if (record->event.pressed) {

            } else {
                dprintf("mode = %d\n", rgb_matrix_get_mode());
                //dprintf("hue = %d\n", rgb_matrix_get_hue());
                //dprintf("sat = %d\n", rgb_matrix_get_sat());
                //dprintf("val = %d\n", rgb_matrix_get_val());
            }
            return true;

    }
#ifdef CONSOLE_ENABLE
    //uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    return true;
}
