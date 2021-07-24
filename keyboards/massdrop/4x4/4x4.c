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

#include "4x4.h"
//#include "i2c_master.h"

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

    {0, K_11,   J_11,   L_11},
    {0, K_12,   J_12,   L_12},
    {0, K_13,   J_13,   L_13},
    {0, K_14,   J_14,   L_14},
    {0, K_15,   J_15,   L_15},
    {0, K_16,   J_16,   L_16},
};

led_config_t g_led_config = { {
  // Key Matrix to LED Index
  {   0,  1,  2,  3 },
  {   4,  5,  6,  7 },
  {   8,  9,  10, 11 },
  {   12, 13, 14, 15 },
}, {
  // LED Index to Physical Position
  { 0,  0 },  { 15,  0 }, { 30,  0 }, { 45,  0 }, { 60,  0 },  { 75,  0 }, { 90,  0 }, { 105,  0 }, { 120,  0 }, { 135,  0 }, { 150,  0 }, { 165,  0 }, { 180,  0 }, { 195, 0 }, { 210,  0 }, { 224,  0 },
  //{ 150,  64 }, { 165,  64 }, { 180,  64 }, { 195, 64 }, { 210,  64}, { 224,  64 }
  { 0,  64 }, { 15,  64 }, { 30,  64 }, { 45, 64 }, { 60,  64}, { 75,  64 }

}, {
  // LED Index to Flag
  4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
  4,4,4,2,2,2
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
