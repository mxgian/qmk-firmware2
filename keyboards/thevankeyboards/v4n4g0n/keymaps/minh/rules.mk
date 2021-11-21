# MCU name
MCU = atmega32u4

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
<<<<<<< HEAD:keyboards/thevankeyboards/v4n4g0n/keymaps/minh/rules.mk
BOOTMAGIC_ENABLE = no      # Virtual DIP switch configuration
=======
BOOTMAGIC_ENABLE = lite     # Enable Bootmagic Lite
>>>>>>> 739bf6211227254db5f8786df0c57f257d72cc78:keyboards/mechlovin/adelais/rules.mk
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # USB Nkey Rollover
<<<<<<< HEAD:keyboards/thevankeyboards/v4n4g0n/keymaps/minh/rules.mk
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality on B7 by default
MIDI_ENABLE = no            # MIDI controls
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no           # Audio output on port C6
=======
AUDIO_ENABLE = no           # Audio output

LAYOUTS = alice alice_split_bs

DEFAULT_FOLDER = mechlovin/adelais/standard_led/rev2
>>>>>>> 739bf6211227254db5f8786df0c57f257d72cc78:keyboards/mechlovin/adelais/rules.mk
