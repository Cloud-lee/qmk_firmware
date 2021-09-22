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
    {0, B_5,    A_5,    C_5},
    {0, B_4,    A_4,    C_4},
    {0, B_3,    A_3,    C_3},
    {0, B_2,    A_2,    C_2},

    {0, E_5,    D_5,    F_5},
    {0, E_4,    D_4,    F_4},
    {0, E_3,    D_3,    F_3},
    {0, E_2,    D_2,    F_2},

    {0, H_5,    G_5,    I_5},
    {0, H_4,    G_4,    I_4},
    {0, H_3,    G_3,    I_3},
    {0, H_2,    G_2,    I_2},

    {0, K_5,    J_5,    L_5},
    {0, K_4,    J_4,    L_4},
    {0, K_3,    J_3,    L_3},
    {0, K_2,    J_2,    L_2},

    //underglow
    {0, B_1,    A_1,    C_1},
    {0, E_1,    D_1,    F_1},
    {0, H_1,    G_1,    I_1},
    {0, K_1,    J_1,    L_1},
};

led_config_t g_led_config = { {
  // Key Matrix to LED Index, underglow {4,9,14,19}
  {   0,  1,  2,  3 },
  {   4,  5,  6,  7 },
  {   8,  9,  10, 11 },
  {   12, 13, 14, 15 },
}, {
  // LED Index to Physical Position
  { 0,  0 },  { 56,  0 }, { 112,  0 }, { 168,  0 },
  { 0,  21 },  { 56,  21 }, { 112,  21 }, { 168,  21 },
  { 0,  43 },  { 56,  43 }, { 112,  43 }, { 168,  43 },
  { 0,  64 },  { 56,  64 }, { 112,  64 }, { 168,  64 },

  // underglow
  { 224,  0 },  { 224,  21 }, { 224,  43 }, { 224,  64 },
}, {
  // LED Index to Flag
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,

  // underglow
  2,2,2,2,
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

    /* no weakly pull up */
    //palSetPadMode(I2C1_SCL_BANK, I2C1_SCL, PAL_MODE_ALTERNATE(I2C1_SCL_PAL_MODE) | PAL_STM32_OTYPE_OPENDRAIN);
    //palSetPadMode(I2C1_SDA_BANK, I2C1_SDA, PAL_MODE_ALTERNATE(I2C1_SDA_PAL_MODE) | PAL_STM32_OTYPE_OPENDRAIN);

    /* weakly pull up */
    palSetPadMode(I2C1_SCL_BANK, I2C1_SDA, PAL_MODE_ALTERNATE(I2C1_SCL_PAL_MODE) | PAL_STM32_OTYPE_OPENDRAIN | PAL_STM32_PUPDR_PULLUP);
    palSetPadMode(I2C1_SCL_BANK, I2C1_SCL, PAL_MODE_ALTERNATE(I2C1_SCL_PAL_MODE) | PAL_STM32_OTYPE_OPENDRAIN | PAL_STM32_PUPDR_PULLUP);

    /* enable clock on MCO (PA8) */
    palSetPadMode(GPIOA, 8, PAL_MODE_ALTERNATE(0)); // MCO
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
