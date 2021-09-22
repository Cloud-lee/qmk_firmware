/* Copyright 2021 QMK
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

/*
 * This file was auto-generated by:
 *    `qmk chibios-confmigrate -i keyboards/massdrop/75_non_pro/mcuconf.h -r platforms/chibios/GENERIC_STM32_F303XC/configs/mcuconf.h`
 */

#pragma once

#include_next <mcuconf.h>

#undef STM32_I2C_USE_I2C1
#define STM32_I2C_USE_I2C1 TRUE

#undef STM32_MCOSEL
//#define STM32_MCOSEL STM32_MCOSEL_SYSCLK  // output SYSTEM clock on MCO pin (PA8), too fast to measure
//#define STM32_MCOSEL STM32_MCOSEL_LSI  // output LSI on MCO pin (PA8), 40 kHz
#define STM32_MCOSEL STM32_MCOSEL_HSE  // output HSE on MCO pin (PA8)
