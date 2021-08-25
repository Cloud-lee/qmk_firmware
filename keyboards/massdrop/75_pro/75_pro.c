/* Copyright 2021 Cloud Li
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

#include "75_pro.h"
//#include "i2c_master.h"

//void i2c_init(void);
void matrix_init_kb(void) {
	matrix_init_user();
    //debug_enable=true;
    //debug_matrix=true;
}

#if 0
void matrix_scan_kb(void) {
	matrix_scan_user();
}
#endif


#ifdef RGB_MATRIX_ENABLE


const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |  R location
 *   |  |       G location
 *   |  |       |       B location
 *   |  |       |       | */
    {0, E_2,    D_2,    F_2}, // ESC index17
    {0, E_3,    D_3,    F_3}, // F1
    {0, E_4,    D_4,    F_4}, // F2
    {0, E_5,    D_5,    F_5}, // F3
    {0, E_6,    D_6,    F_6}, // F4
    {0, E_7,    D_7,    F_7}, // F5
    {0, E_8,    D_8,    F_8}, // F6
    {0, E_9,    D_9,    F_9}, // F7
    {0, E_10,   D_10,   F_10}, // F8
    {0, E_11,   D_11,   F_11}, // F9
    {0, E_12,   D_12,   F_12}, // F10
    {0, E_13,   D_13,   F_13}, // F11
    {0, E_14,   D_14,   F_14}, // F12
    {0, E_15,   D_15,   F_15}, // ANY
    {0, E_16,   D_16,   F_16}, // Rotary

    {0, H_2,    G_2,    I_2}, // ~
    {0, H_3,    G_3,    I_3}, // 1
    {0, H_4,    G_4,    I_4}, // 2
    {0, H_5,    G_5,    I_5}, // 3
    {0, H_6,    G_6,    I_6}, // 4
    {0, H_7,    G_7,    I_7}, // 5
    {0, H_8,    G_8,    I_8}, // 6
    {0, H_9,    G_9,    I_9}, // 7
    {0, H_10,   G_10,   I_10}, // 8
    {0, H_11,   G_11,   I_11}, // 9
    {0, H_12,   G_12,   I_12}, // 0
    {0, H_13,   G_13,   I_13}, // -
    {0, H_14,   G_14,   I_14}, // +
    {0, H_15,   G_15,   I_15}, // BKSP
    {0, H_16,   G_16,   I_16}, // PgUp
    {0, K_2,    J_2,    L_2}, // TAB
    {0, K_3,    J_3,    L_3}, // Q
    {0, K_4,    J_4,    L_4}, // W
    {0, K_5,    J_5,    L_5}, // E
    {0, K_6,    J_6,    L_6}, // R
    {0, K_7,    J_7,    L_7}, // T
    {0, K_8,    J_8,    L_8}, // Y
    {0, K_9,    J_9,    L_9}, // U
    {0, K_10,   J_10,   L_10}, // I
    {0, K_11,   J_11,   L_11}, // O
    {0, K_12,   J_12,   L_12}, // P
    {0, K_13,   J_13,   L_13}, // [
    {0, K_14,   J_14,   L_14}, // ]
    {0, K_15,   J_15,   L_15}, // |
    {0, K_16,   J_16,   L_16}, // PgDn

    {1, B_2,    A_2,    C_2}, // CAPS
    {1, B_3,    A_3,    C_3}, // A
    {1, B_4,    A_4,    C_4}, // S
    {1, B_5,    A_5,    C_5}, // D
    {1, B_6,    A_6,    C_6}, // F
    {1, B_7,    A_7,    C_7}, // G
    {1, B_8,    A_8,    C_8}, // H
    {1, B_9,    A_9,    C_9}, // J
    {1, B_10,   A_10,   C_10}, // K
    {1, B_11,   A_11,   C_11}, // L

    {1, E_2,    D_2,    F_2}, // L_SHIFT
    {1, E_3,    D_3,    F_3}, // Z
    {1, E_4,    D_4,    F_4}, // X
    {1, E_5,    D_5,    F_5}, // C
    {1, E_6,    D_6,    F_6}, // V
    {1, E_7,    D_7,    F_7}, // B
    {1, E_8,    D_8,    F_8}, // N
    {1, E_9,    D_9,    F_9}, // M
    {1, E_10,   D_10,   F_10}, // <
    {1, E_11,   D_11,   F_11}, // >
    {1, E_12,   D_12,   F_12}, // ;
    {1, E_13,   D_13,   F_13}, // "
    {1, E_14,   D_14,   F_14}, // ENTER

    {1, H_2,    G_2,    I_2}, // L_CTRL
    {1, H_3,    G_3,    I_3}, // L_WIN
    {1, H_4,    G_4,    I_4}, // L_ALT
    {1, H_5,    G_5,    I_5}, // SPACE
    {1, H_6,    G_6,    I_6}, // R_ALT
    {1, H_7,    G_7,    I_7}, // FN
    {1, H_8,    G_8,    I_8}, // R_CTRL
    {1, H_9,    G_9,    I_9}, // LEFT
    {1, H_10,   G_10,   I_10}, // DOWN
    {1, H_11,   G_11,   I_11}, // RIGHT
    {1, H_12,   G_12,   I_12}, // ?
    {1, H_13,   G_13,   I_13}, // R_SHIFT
    {1, H_14,   G_14,   I_14}, // UP
    {1, H_15,   G_15,   I_15}, // END

    /* Underglow / Border */
    {0, B_1,    A_1,    C_1}, // S1
    {0, B_2,    A_2,    C_2}, // S2
    {0, B_3,    A_3,    C_3}, // S3
    {0, B_4,    A_4,    C_4}, // S4
    {0, B_5,    A_5,    C_5}, // S5
    {0, B_6,    A_6,    C_6}, // S6
    {0, B_7,    A_7,    C_7}, // S7
    {0, B_8,    A_8,    C_8}, // S8
    {0, B_9,    A_9,    C_9}, // S9
    {0, B_10,   A_10,   C_10}, // S10
    {0, B_11,   A_11,   C_11}, // S11
    {0, B_12,   A_12,   C_12}, // S12
    {0, B_13,   A_13,   C_13}, // S13
    {0, B_14,   A_14,   C_14}, // S14
    {0, B_15,   A_15,   C_15}, // S15
    {0, B_16,   A_16,   C_16}, // S16
    {0, E_1,    D_1,    F_1}, // S46
    {0, H_1,    G_1,    I_1}, // S45
    {0, K_1,    J_1,    L_1}, // S44
    {1, B_1,    A_1,    C_1}, // S43
    {1, B_12,   A_12,   C_12}, // S17
    {1, B_13,   A_13,   C_13}, // S18
    {1, B_14,   A_14,   C_14}, // S19
    {1, B_15,   A_15,   C_15}, // S20
    {1, B_16,   A_16,   C_16}, // S21
    {1, E_1,    D_1,    F_1}, // S42
    {1, E_15,   D_15,   F_15}, // S22
    {1, E_16,   D_16,   F_16}, // S23
    {1, H_1,    G_1,    I_1}, // S41
    {1, H_16,   G_16,   I_16}, // S24
    {1, K_1,    J_1,    L_1}, // S40
    {1, K_2,    J_2,    L_2}, // S39
    {1, K_3,    J_3,    L_3}, // S38
    {1, K_4,    J_4,    L_4}, // S37
    {1, K_5,    J_5,    L_5}, // S36
    {1, K_6,    J_6,    L_6}, // S35
    {1, K_7,    J_7,    L_7}, // S34
    {1, K_8,    J_8,    L_8}, // S33
    {1, K_9,    J_9,    L_9}, // S32
    {1, K_10,   J_10,   L_10}, // S31
    {1, K_11,   J_11,   L_11}, // S30
    {1, K_12,   J_12,   L_12}, // S29
    {1, K_13,   J_13,   L_13}, // S28
    {1, K_14,   J_14,   L_14}, // S27
    {1, K_15,   J_15,   L_15}, // S26
    {1, K_16,   J_16,   L_16}, // S25
};

led_config_t g_led_config = { {
  /* Key Matrix to LED Index */
  // ESC, F1~F12, Home, ANY, Rotary
  {  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,  11,  12,  13,  14 },
  // ~, 1~0, _, +, BKSP, PgUp
  {  15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29 },
  // TAB, Q, W, E,...[, ], |, PgDn
  {  30,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44 },
  // CAPS, A, S, D, ..., ENTER, END
  {  45,  46,  47,  48,  49,  50,  51,  52,  53,  54,  55,  56,  57, NO_LED, 58 },
  // L_SHIFT, Z, X, C, V..., R_SHIFT, UP
  {  59,  60,  61,  62,  63,  64,  65,  66,  67,  68, 69, 70, NO_LED, 71, NO_LED },
  // L_CTRL, L_WIN, L_ALT, SPACE, R_ALT, FN, R_CTRL, LEFT, DOWN, RIGHT
  {  72,  73,  74, NO_LED, NO_LED, 75, NO_LED, NO_LED, 76, 77, 78, NO_LED, 79, 80, 81 },

}, {
  /* LED Index to Physical Position */
  {3, 5}, {18, 5}, {34, 5}, {49, 5}, {65, 5}, {80, 5}, {96, 5}, {111, 5}, {127, 5}, {142, 5}, {158, 5}, {174, 5}, {190, 5}, {206, 5}, {221, 5},
  {3, 17}, {18, 17}, {34, 17}, {49, 17}, {65, 17}, {80, 17}, {96, 17}, {111, 17}, {127, 17}, {142, 17}, {158, 17}, {174, 17}, {190, 17}, {206, 17}, {221, 17},
  {3, 29}, {18, 29}, {34, 29}, {49, 29}, {65, 29}, {80, 29}, {96, 29}, {111, 29}, {127, 29}, {142, 29}, {158, 29}, {174, 29}, {190, 29}, {206, 29}, {221, 29},
  {3, 40}, {25, 40}, {39, 40}, {54, 40}, {68, 40}, {83, 40}, {97, 40}, {112, 40}, {126, 40}, {141, 40}, {156, 40}, {170, 40}, {195, 40}, {221, 40},
  {3, 51}, {32, 51}, {46, 51}, {61, 51}, {75, 51}, {90, 51}, {104, 51}, {119, 51}, {133, 51}, {148, 51}, {162, 51}, {184, 51}, {206, 51},
  {3, 63}, {18, 63}, {38, 63}, {90, 63}, {140, 63}, {154, 63}, {169, 63}, {192, 63}, {206, 63}, {221, 63},

  /* Underglow / Border */
  {0, 0}, {8, 0}, {16, 0}, {31, 0}, {46, 0}, {62, 0}, {77, 0}, {93, 0}, {108, 0}, {124, 0}, {139, 0}, {155, 0}, {171, 0}, {187, 0}, {203, 0}, {210, 0}, {218, 0}, {224, 0},
  {0, 10}, {224, 10},
  {0, 21}, {224, 21},
  {0, 31}, {224, 31},
  {0, 42}, {224, 42},
  {0, 52}, {224, 52},
  {0, 64}, {224, 64},
  {8, 64}, {16, 64}, {31, 64}, {46, 64}, {62, 64}, {77, 64}, {93, 64}, {108, 64}, {124, 64}, {139, 64}, {155, 64}, {171, 64}, {187, 64}, {203, 64}, {210, 64}, {218, 64},

}, {
  /* LED Index to Flag */
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
  1, 1, 1, 4, 1, 1, 1, 4, 4, 4,

  /* Underglow / Border */
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2,                                                 2,
  2,                                                 2,
  2,                                                 2,
  2,                                                 2,
  2,                                                 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
} };

#endif

void suspend_power_down_kb(void) {
    //rgb_matrix_set_color_all(0, 0, 0);
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}


#if 0
void rgb_matrix_indicators_kb(void) {
    //rgb_matrix_set_color_all(0xf, 0xf, 0xf);
    rgb_matrix_set_color(0, 0xf, 0xf, 0xf);
    rgb_matrix_set_color(1, 0xf, 0xf, 0xf);
    rgb_matrix_set_color(2, 0xf, 0xf, 0xf);
    rgb_matrix_set_color(14, 0xf, 0xf, 0xf);
    rgb_matrix_set_color(15, 0xf, 0xf, 0xf);
}
#endif

#if 1
void i2c_init(void) {
    __attribute__ ((unused)) int ret;
    /* Try releasing special pins for a short time */
    setPinInput(B6); // workaround for B6->B8
    setPinInput(B7); // workaround for B7->B9
    palSetPadMode(I2C1_SCL_BANK, I2C1_SCL, PAL_MODE_INPUT);
    palSetPadMode(I2C1_SDA_BANK, I2C1_SDA, PAL_MODE_INPUT);

    /* with external pull up resistor */
    //palSetPadMode(I2C1_SCL_BANK, I2C1_SCL, PAL_MODE_ALTERNATE(I2C1_SCL_PAL_MODE) | PAL_STM32_OTYPE_OPENDRAIN);
    //palSetPadMode(I2C1_SDA_BANK, I2C1_SDA, PAL_MODE_ALTERNATE(I2C1_SDA_PAL_MODE) | PAL_STM32_OTYPE_OPENDRAIN);

    /* without external pull up resistor */
    palSetPadMode(I2C1_SCL_BANK, I2C1_SDA, PAL_MODE_ALTERNATE(I2C1_SCL_PAL_MODE) | PAL_STM32_OTYPE_OPENDRAIN | PAL_STM32_PUPDR_PULLUP);
    palSetPadMode(I2C1_SCL_BANK, I2C1_SCL, PAL_MODE_ALTERNATE(I2C1_SCL_PAL_MODE) | PAL_STM32_OTYPE_OPENDRAIN | PAL_STM32_PUPDR_PULLUP);
    wait_ms(10); // Wait for the release to happen
}
#endif

#if 0
void bh1750_read_data(void){

    int ret;
    uint8_t data[2];
    //data[0] = 0x00; //power off
    data[0] = 0x01; //power on
    ret = i2c_transmit(BH1750_ADDRESS, data, 1, 100);
    dprintf("i2c_transmit ret = %d\n", ret);

    data[0] = 0x13; //set continuous L-resolution
    ret = i2c_transmit(BH1750_ADDRESS, data, 1, 100);
    dprintf("i2c_transmit ret = %d\n", ret);

    ret = i2c_receive(BH1750_ADDRESS, data, 2, 100);
    dprintf("i2c_receive ret = %d\n", ret);
    if(ret >= 0){
        dprintf("data[0]= 0x%x\n", data[0]);
        dprintf("data[1]= 0x%x\n", data[1]);
    }
}
#endif
