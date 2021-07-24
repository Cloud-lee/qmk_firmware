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
    {0, B_1,    A_1,    C_1},
    {0, B_2,    A_2,    C_2},
    {0, B_3,    A_3,    C_3},
    {0, B_4,    A_4,    C_4},
    {0, B_5,    A_5,    C_5},
    {0, B_6,    A_6,    C_6},
    {0, B_7,    A_7,    C_7},
    {0, B_8,    A_8,    C_8},
    {0, B_9,    A_9,    C_9},
    {0, B_10,   A_10,   C_10},
    {0, B_11,   A_11,   C_11},
    {0, B_12,   A_12,   C_12},
    {0, B_13,   A_13,   C_13},
    {0, B_14,   A_14,   C_14},
    {0, B_15,   A_15,   C_15},
    {0, B_16,   A_16,   C_16},
    {0, E_1,    D_1,    F_1},
    {0, E_2,    D_2,    F_2},
    {0, E_3,    D_3,    F_3},
    {0, E_4,    D_4,    F_4},
    {0, E_5,    D_5,    F_5},
    {0, E_6,    D_6,    F_6},
    {0, E_7,    D_7,    F_7},
    {0, E_8,    D_8,    F_8},
    {0, E_9,    D_9,    F_9},
    {0, E_10,   D_10,   F_10},
    {0, E_11,   D_11,   F_11},
    {0, E_12,   D_12,   F_12},
    {0, E_13,   D_13,   F_13},
    {0, E_14,   D_14,   F_14},
    {0, E_15,   D_15,   F_15},
    {0, E_16,   D_16,   F_16},
    {0, H_1,    G_1,    I_1},
    {0, H_2,    G_2,    I_2},
    {0, H_3,    G_3,    I_3},
    {0, H_4,    G_4,    I_4},
    {0, H_5,    G_5,    I_5},
    {0, H_6,    G_6,    I_6},
    {0, H_7,    G_7,    I_7},
    {0, H_8,    G_8,    I_8},
    {0, H_9,    G_9,    I_9},
    {0, H_10,   G_10,   I_10},
    {0, H_11,   G_11,   I_11},
    {0, H_12,   G_12,   I_12},
    {0, H_13,   G_13,   I_13},
    {0, H_14,   G_14,   I_14},
    {0, H_15,   G_15,   I_15},
    {0, H_16,   G_16,   I_16},
    {0, K_1,    J_1,    L_1},
    {0, K_2,    J_2,    L_2},
    {0, K_3,    J_3,    L_3},
    {0, K_4,    J_4,    L_4},
    {0, K_5,    J_5,    L_5},
    {0, K_6,    J_6,    L_6},
    {0, K_7,    J_7,    L_7},
    {0, K_8,    J_8,    L_8},
    {0, K_9,    J_9,    L_9},
    {0, K_10,   J_10,   L_10},
    {0, K_11,   J_11,   L_11},
    {0, K_12,   J_12,   L_12},
    {0, K_13,   J_13,   L_13},
    {0, K_14,   J_14,   L_14},
    {0, K_15,   J_15,   L_15},
    {0, K_16,   J_16,   L_16},

    {1, B_1,    A_1,    C_1},
    {1, B_2,    A_2,    C_2},
    {1, B_3,    A_3,    C_3},
    {1, B_4,    A_4,    C_4},
    {1, B_5,    A_5,    C_5},
    {1, B_6,    A_6,    C_6},
    {1, B_7,    A_7,    C_7},
    {1, B_8,    A_8,    C_8},
    {1, B_9,    A_9,    C_9},
    {1, B_10,   A_10,   C_10},
    {1, B_11,   A_11,   C_11},
    {1, B_12,   A_12,   C_12},
    {1, B_13,   A_13,   C_13},
    {1, B_14,   A_14,   C_14},
    {1, B_15,   A_15,   C_15},
    {1, B_16,   A_16,   C_16},
    {1, E_1,    D_1,    F_1},
    {1, E_2,    D_2,    F_2},
    {1, E_3,    D_3,    F_3},
    {1, E_4,    D_4,    F_4},
    {1, E_5,    D_5,    F_5},
    {1, E_6,    D_6,    F_6},
    {1, E_7,    D_7,    F_7},
    {1, E_8,    D_8,    F_8},
    {1, E_9,    D_9,    F_9},
    {1, E_10,   D_10,   F_10},
    {1, E_11,   D_11,   F_11},
    {1, E_12,   D_12,   F_12},
    {1, E_13,   D_13,   F_13},
    {1, E_14,   D_14,   F_14},
    {1, E_15,   D_15,   F_15},
    {1, E_16,   D_16,   F_16},
    {1, H_1,    G_1,    I_1},
    {1, H_2,    G_2,    I_2},
    {1, H_3,    G_3,    I_3},
    {1, H_4,    G_4,    I_4},
    {1, H_5,    G_5,    I_5},
    {1, H_6,    G_6,    I_6},
    {1, H_7,    G_7,    I_7},
    {1, H_8,    G_8,    I_8},
    {1, H_9,    G_9,    I_9},
    {1, H_10,   G_10,   I_10},
    {1, H_11,   G_11,   I_11},
    {1, H_12,   G_12,   I_12},
    {1, H_13,   G_13,   I_13},
    {1, H_14,   G_14,   I_14},
    {1, H_15,   G_15,   I_15},
    {1, H_16,   G_16,   I_16},
    {1, K_1,    J_1,    L_1},
    {1, K_2,    J_2,    L_2},
    {1, K_3,    J_3,    L_3},
    {1, K_4,    J_4,    L_4},
    {1, K_5,    J_5,    L_5},
    {1, K_6,    J_6,    L_6},
    {1, K_7,    J_7,    L_7},
    {1, K_8,    J_8,    L_8},
    {1, K_9,    J_9,    L_9},
    {1, K_10,   J_10,   L_10},
    {1, K_11,   J_11,   L_11},
    {1, K_12,   J_12,   L_12},
    {1, K_13,   J_13,   L_13},
    {1, K_14,   J_14,   L_14},
    {1, K_15,   J_15,   L_15},
    {1, K_16,   J_16,   L_16},
};

led_config_t g_led_config = { {
  // Key Matrix to LED Index

  // esc, f1~f12, home, end
  {  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  31 },
  // ~, 1~0, _, +, back, del
  {  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46,  47 },
  // tab, Q, W, E,...[, ], \, PGUP
  {  49,  50,  51,  52,  53,  54,  55,  56,  57,  58,  59,  60,  61,  62,  63 },
  // caps, A, D, F, ..., ENTER, PGDN
  {  65,  66,  67,  68,  69,  70,  71,  72,  73,  74,  91,  92  ,93, NO_LED, 110 },
  // SHIFT, Z, X, C, V..., SHIFT, UP
  {  81,  82,  83,  84,  85,  86,  87,  88,  89,  90, 107, 108, NO_LED, 109, NO_LED },
  // CTRL, WIN, ALT, SPACE, ALT, FN, CTRL, LEFT, DOWN, RIGHT
  {  97,  98,  99, NO_LED, NO_LED, 100, NO_LED, NO_LED, 101, 102, 103, NO_LED, 104, 105, 106 },

}, {
  // LED Index to Physical Position
  {0, 0}, {15, 0}, {30, 0}, {45, 0}, {60, 0}, {75, 0}, {90, 0}, {105, 0}, {120, 0}, {135, 0}, {150, 0}, {165, 0}, {180, 0}, {195, 0}, {210, 0}, {224, 0},
  {0, 9}, {15, 9}, {30, 9}, {45, 9}, {60, 9}, {75, 9}, {90, 9}, {105, 9}, {120, 9}, {135, 9}, {150, 9}, {165, 9}, {180, 9}, {195, 9}, {210, 9}, {224, 9},
  {0, 18}, {15, 18}, {30, 18}, {45, 18}, {60, 18}, {75, 18}, {90, 18}, {105, 18}, {120, 18}, {135, 18}, {150, 18}, {165, 18}, {180, 18}, {195, 18}, {210, 18}, {224, 18},
  {0, 27}, {15, 27}, {30, 27}, {45, 27}, {60, 27}, {75, 27}, {90, 27}, {105, 27}, {120, 27}, {135, 27}, {150, 27}, {165, 27}, {180, 27}, {195, 27}, {210, 27}, {224, 27},
  {0, 36}, {15, 36}, {30, 36}, {45, 36}, {60, 36}, {75, 36}, {90, 36}, {105, 36}, {120, 36}, {135, 36}, {150, 36}, {165, 36}, {180, 36}, {195, 36}, {210, 36}, {224, 36},
  {0, 45}, {15, 45}, {30, 45}, {45, 45}, {60, 45}, {75, 45}, {90, 45}, {105, 45}, {120, 45}, {135, 45}, {150, 45}, {165, 45}, {180, 45}, {195, 45}, {210, 45}, {224, 45},
  {0, 54}, {15, 54}, {30, 54}, {45, 54}, {60, 54}, {75, 54}, {90, 54}, {105, 54}, {120, 54}, {135, 54}, {150, 54}, {165, 54}, {180, 54}, {195, 54}, {210, 54}, {224, 54},
  {0, 63}, {15, 63}, {30, 63}, {45, 63}, {60, 63}, {75, 63}, {90, 63}, {105, 63}, {120, 63}, {135, 63}, {150, 63}, {165, 63}, {180, 63}, {195, 63}, {210, 63}, {224, 63},
}, {
  // LED Index to Flag
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 2,
  2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2,
  2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
} };

#endif

void suspend_power_down_kb(void) {
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
    wait_ms(10); // Wait for the release to happen

    palSetPadMode(I2C1_SCL_BANK, I2C1_SCL, PAL_MODE_ALTERNATE(I2C1_SCL_PAL_MODE) | PAL_STM32_OTYPE_OPENDRAIN);
    palSetPadMode(I2C1_SDA_BANK, I2C1_SDA, PAL_MODE_ALTERNATE(I2C1_SDA_PAL_MODE) | PAL_STM32_OTYPE_OPENDRAIN);

    //palSetPadMode(I2C1_SCL_BANK, I2C1_SDA, PAL_MODE_ALTERNATE(I2C1_SCL_PAL_MODE) | PAL_STM32_OTYPE_OPENDRAIN | PAL_STM32_PUPDR_PULLUP);
    //palSetPadMode(I2C1_SCL_BANK, I2C1_SCL, PAL_MODE_ALTERNATE(I2C1_SCL_PAL_MODE) | PAL_STM32_OTYPE_OPENDRAIN | PAL_STM32_PUPDR_PULLUP);
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
