/*
Copyright 2021 Cloud-Lee

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* Cloud test define */
//#define DEBUG_MATRIX_SCAN_RATE

/* USB Device descriptor parameter */
//#define VENDOR_ID       0x4B50 //BM16a
//#define PRODUCT_ID      0x016B //BM16a
#define VENDOR_ID    0x0483  //4x4
#define PRODUCT_ID   0xEED7  //4x4
#define DEVICE_VER   0x0001
#define MANUFACTURER "Drop Inc."
#define PRODUCT      "4x4 keyboard"

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 4
#define MATRIX_ROW_PINS { D1, D3, D5, D7 }
#define MATRIX_COL_PINS { D0, D2, D4, D6 }

#define UNUSED_PINS

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* the delay in microseconds when between changing matrix pin state and reading values */
//#define MATRIX_IO_DELAY 30

/* sets the USB polling rate in milliseconds for the keyboard, mouse, and shared (NKRO/media keys) interfaces */
//#define USB_POLLING_INTERVAL_MS 10

//#define RGB_DI_PIN E2
//#ifdef RGB_DI_PIN
//#    define RGBLED_NUM 16
//#    define RGBLIGHT_HUE_STEP 8
//#    define RGBLIGHT_SAT_STEP 8
//#    define RGBLIGHT_VAL_STEP 8
//#    define RGBLIGHT_LIMIT_VAL 255 /* The maximum brightness level */
//#    define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
/*== all animations enable ==*/
#    define RGBLIGHT_ANIMATIONS
/*== or choose animations ==*/
//#    define RGBLIGHT_EFFECT_BREATHING
//#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
//#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//#    define RGBLIGHT_EFFECT_SNAKE
//#    define RGBLIGHT_EFFECT_KNIGHT
//#    define RGBLIGHT_EFFECT_CHRISTMAS
//#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
//#    define RGBLIGHT_EFFECT_RGB_TEST
//#    define RGBLIGHT_EFFECT_ALTERNATING
/*== customize breathing effect ==*/
/*==== (DEFAULT) use fixed table instead of exp() and sin() ====*/
//#    define RGBLIGHT_BREATHE_TABLE_SIZE 256      // 256(default) or 128 or 64
/*==== use exp() and sin() ====*/
//#    define RGBLIGHT_EFFECT_BREATHE_CENTER 1.85  // 1 to 2.7
//#    define RGBLIGHT_EFFECT_BREATHE_MAX    255   // 0 to 255
//#endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* If defined, GRAVE_ESC will always act as ESC when CTRL is held.
 * This is useful for the Windows task manager shortcut (ctrl+shift+esc).
 */
//#define GRAVE_ESC_CTRL_OVERRIDE

/*
 * Force NKRO
 *
 * Force NKRO (nKey Rollover) to be enabled by default, regardless of the saved
 * state in the bootmagic EEPROM settings. (Note that NKRO must be enabled in the
 * makefile for this to work.)
 *
 * If forced on, NKRO can be disabled via magic key (default = LShift+RShift+N)
 * until the next keyboard reset.
 *
 * NKRO may prevent your keystrokes from being detected in the BIOS, but it is
 * fully operational during normal computer usage.
 *
 * For a less heavy-handed approach, enable NKRO via magic key (LShift+RShift+N)
 * or via bootmagic (hold SPACE+N while plugging in the keyboard). Once set by
 * bootmagic, NKRO mode will always be enabled until it is toggled again during a
 * power-up.
 *
 */
//#define FORCE_NKRO

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

/* Bootmagic Lite key configuration */
//#define BOOTMAGIC_LITE_ROW 0
//#define BOOTMAGIC_LITE_COLUMN 0


/* I2C bus test */
#if 1
#define I2C_DRIVER      I2CD1
#define I2C1_SCL_BANK   GPIOB
#define I2C1_SDA_BANK   GPIOB
//#define I2C1_SCL        6
//#define I2C1_SDA        7
#define I2C1_SCL        8
#define I2C1_SDA        9
#define I2C1_SCL_PAL_MODE     4
#define I2C1_SDA_PAL_MODE     4

#define BH1750_ADDRESS  (0x46 << 0)  //depend on ADDR(AD0) < 0.3*VCC
//#define BH1750_ADDRESS  (0xB8 << 0)    //depend on ADDR(AD0) > 0.7*VCC
#endif


/* LED driver config */
#define DRIVER_ADDR_1 0b1010000
//#define DRIVER_ADDR_2 0b1010011
#define DRIVER_ADDR_2 DRIVER_ADDR_1

#define DRIVER_COUNT 2
#define DRIVER_1_LED_TOTAL (16+6)
#define DRIVER_LED_TOTAL (DRIVER_1_LED_TOTAL)
//#define DRIVER_2_LED_TOTAL 3
//#define DRIVER_LED_TOTAL (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)


#if 1
#define DISABLE_RGB_MATRIX_ALPHAS_MODS
#define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#define DISABLE_RGB_MATRIX_BREATHING
#define DISABLE_RGB_MATRIX_CYCLE_ALL
#define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
#define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define DISABLE_RGB_MATRIX_DUAL_BEACON
#define DISABLE_RGB_MATRIX_RAINBOW_BEACON
#define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#define DISABLE_RGB_MATRIX_RAINDROPS
#define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#define DISABLE_RGB_MATRIX_TYPING_HEATMAP
#define DISABLE_RGB_MATRIX_DIGITAL_RAIN
#if 1
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#define DISABLE_RGB_MATRIX_SPLASH
#define DISABLE_RGB_MATRIX_MULTISPLASH
#define DISABLE_RGB_MATRIX_SOLID_SPLASH
#define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif
#endif

#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_LED_PROCESS_LIMIT 15
#define RGB_MATRIX_LED_FLUSH_LIMIT 10
#define RGB_DISABLE_WHEN_USB_SUSPENDED true

//#undef STM32_EEPROM_ENABLE
#ifdef EEPROM_DRIVER
//#error "asdasds"
#define EXTERNAL_EEPROM_I2C_BASE_ADDRESS  0b10101000
#define EEPROM_I2C_24LC256
#endif


/* Bootmagic Lite key configuration */
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0
// Backlight config starts after VIA's EEPROM usage,
// dynamic keymaps start after this.
//#define VIA_EEPROM_CUSTOM_CONFIG_SIZE 32

// VIA lighting is handled by the keyboard-level code
//#define VIA_CUSTOM_LIGHTING_ENABLE
//
/* Custom EEPROM start addressing. This is to support
 * both 128kb and 256kb versions of F303.
 * Register 0x1FFFF7CC holds the size of the flash memory.
 */
#if 0
#define EEPROM_START_ADDRESS
#define FEE_MCU_FLASH_SIZE                              \
({                                                      \
    uint16_t (*flash_size) = (uint16_t*)FLASHSIZE_BASE;  \
    *flash_size;                                        \
})
#endif
