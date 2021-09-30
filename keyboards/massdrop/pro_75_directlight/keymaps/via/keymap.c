/* Copyright 2021 Cloud.Li
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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKURL = SAFE_RANGE,
    LED_TEST,

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(    /* keymap for layer 0 */
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,  KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,  KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,            KC_PGDN,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                    KC_RALT, MO(1),   KC_RCTL,          KC_LEFT, KC_DOWN,  KC_RGHT
        ),
    [1] = LAYOUT(    /* keymap for layer 1 */
        EEP_RST, LED_TEST, DEBUG,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,
        _______, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, _______, _______, _______, _______, _______, _______, _______,  _______,
        _______, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______, _______,           _______,
        _______, RGB_TOG, _______, _______, _______, RESET , NK_TOGG,  _______, _______, _______, _______, _______,          _______,
        _______, _______, _______,                   _______,                   _______, _______, _______,          _______, _______,  _______
        ),
    [2] = LAYOUT(    /* Empty for dynamic keymaps */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______,                   _______,                   _______, _______, _______,          _______, _______, _______
    ),
    [3] = LAYOUT(    /* Empty for dynamic keymaps */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______,                   _______,                   _______, _______, _______,          _______, _______, _______
    ),

};

#if 1
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (IS_LAYER_ON(0)) {
            if (clockwise) {
                tap_code_delay(KC_VOLU, 10);
                //rgblight_increase_val();
            } else {
                tap_code_delay(KC_VOLD, 10);
                //rgblight_decrease_val();
            }
        }
    }
    return true;
}
#endif
#endif

#if 1
void matrix_init_user(void) {
    //debug_enable = true; // for dprintf() enable or not
    //debug_matrix = true;
    //rgblight_enable();
    //rgblight_mode(RGB_MATRIX_BREATHING);  // for factory test whole KB LED
    //rgb_matrix_mode(RGB_MATRIX_BREATHING);  // for factory test whole KB LED
    //rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_SIMPLE); // test single key LED
    //rgblight_sethsv(255,0,255); // white & brightness MAX
    //rgblight_set_speed(50);
    //eeconfig_disable();
}
#endif

#if 0
void eeconfig_init_user(void){

}
#endif

void rgb_matrix_indicators_user(void) {
    //rgb_matrix_set_color(0, 50,50,50); // fot github token test
    //rgb_matrix_set_color(1, 50,50,50);
    //rgb_matrix_set_color(2, 50,50,50);
    //rgb_matrix_set_color_all(200, 200, 200);
    //rgblight_setrgb(0, 16, 0); //green
#if 0
    for (uint8_t i = 0; i < 127; i++) {
        rgb_matrix_set_color(i, 0, 16, 0);
    }
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    //int16_t led_hue, led_sat, led_val;

    switch (keycode) {
        case RGB_MOD:
        case RGB_RMOD:
        if (record->event.pressed) {
            dprintf("mode = %d\n", rgb_matrix_get_mode());
            dprintf("hue = %d\n", rgb_matrix_get_hue());
            dprintf("sat = %d\n", rgb_matrix_get_sat());
            dprintf("val = %d\n", rgb_matrix_get_val());
        } else {
           // when keycode RGB_MOD is released
        }
        return true;

        case LED_TEST:
            rgblight_enable();
            rgblight_sethsv(255,0,255); // white & brightness MAX
            rgblight_mode(RGB_MATRIX_BREATHING);  // for factory test whole KB LED
            rgblight_set_speed(50);
        return true;
    }
#ifdef CONSOLE_ENABLE
    //uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    return true;
}
