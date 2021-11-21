# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = lufa-dfu

# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
NKRO_ENABLE = yes           # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight.
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
#HARDWARE_SERIAL = yes
CUSTOM_MATRIX = yes

SRC += matrix.c led.c
ifdef HARDWARE_SERIAL
  SRC += protocol/serial_uart.c
  OPT_DEFS += -DHARDWARE_SERIAL
else
  SRC += protocol/serial_soft.c
endif

DEFAULT_FOLDER = converter/sun_usb/type5
