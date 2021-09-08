# cloud option (ref: https://docs.qmk.fm/#/config_options)

# MCU name
MCU = STM32F303

# Bootloader selection
BOOTLOADER = stm32-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = lite     # Virtual DIP switch configuration
#BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality on B7 by default
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
MIDI_ENABLE = no            # MIDI support
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no           # Audio output on port C6
VIRTSER_ENABLE = no         # USB Serial Driver
RAW_ENABLE = no             # Raw device
AUTO_SHIFT_ENABLE = no      # Auto Shift


#ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
#  # Include my fancy rgb functions source here
#  SRC += cool_rgb_stuff.c
#endif

#QUANTUM_LIB_SRC += i2c_master.c
#SRC += i2c_master.c

# LED driver
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = IS31FL3733

## Built-in EEPROM
#EEPROM_DRIVER = vendor

## EEPROM (24LC256)
EEPROM_DRIVER = i2c

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE

# Rotary Encoder
ENCODER_ENABLE = yes
