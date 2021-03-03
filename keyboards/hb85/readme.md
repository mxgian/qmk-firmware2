# hb85

![hb85](imgur.com image replace me!)

A short description of the keyboard/project

Keyboard Maintainer: [You](https://github.com/yourusername)  
Hardware Supported: Gray Studio HitBit 85 (HB-85) 
Hardware Availability: https://geekhack.org/index.php?topic=97816.0

Make example for this keyboard (after setting up your build environment):

    make hb85:default

Flashing

ps2avr(GB) boards use an atmega32a microcontroller and a different bootloader. It is not flashable using the regular QMK methods. 

Windows: 
1. Download [HIDBootFlash](http://vusb.wikidot.com/project:hidbootflash).
2. Place your keyboard into reset/bootloader mode. 
3. Press the `Find Device` button and ensure that your keyboard is found.
4. Press the `Open .hex File` button and locate the `.hex` file you created.
5. Press the `Flash Device` button and wait for the process to complete. 

macOS:
1. Install homebrew by typing the following:   
    ```
    /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
    ```
2. Install `crosspack-avr`.  
    ```
    brew cask install crosspack-avr
    ```
3. Install the following packages:
    ```
    brew install python
    brew install pyusb
    brew install --HEAD https://raw.githubusercontent.com/robertgzr/homebrew-tap/master/bootloadhid.rb

4. Place your keyboard into reset.    for the hb85 this is F3, so hold down F3 while plugging it in, this force it into bootloader mode and ready to accept the new .hex file.
5. Flash the board by typing `bootloadHID -r` followed by the path to your `.hex` file. 

If you want to reverse the changes and go back to bootloader, perform step 4 above but then upload the ps2avrgb firmware from the bootmapper gui. 

In some cases the board may lockup and you cannot update with QMK, in this case revert back to the ps2avrgb bootmapper firmware and then start over with the flashing steps. 

## Setting the board to bootloader mode and uploading a QMK hex or a bootmapper hex

The bootloader key is the top left key of your matrix (0,0), if you hold down this key when you plug in the board it will force the bootloader to load and wait for a new hex.  Once it is in bootloader mode, you can then upload a new QMK .hex file using bootloadHID.  If you want to revert back to ps2avrgb, then go to the bootmapper client and the options tab, and use the "Firm Up" button in the lower left to upload the bootmapper firmware.  


## Troubleshooting

From my experience, it's really hard to brick these boards. But these
tricks have been useful when it got stuck in a weird scenario.

1. Try plugging the board in while holding the bootloader key. This will force 
   it to boot only the bootloader without loading the firmware. Once this is
   done, just reflash the board with the original firmware.
2. Sometimes USB hubs can act weird, so try connecting the board directly
   to your computer or plugging/unplugging the USB hub.



See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
