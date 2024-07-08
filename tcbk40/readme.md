# tcbk40

![tcbk40]

*A short description of the keyboard/project*

* Keyboard Maintainer: [Arthur feijó](https://github.com/tukacustoms)
* Hardware Supported: Uses an atmega 32u4 as main micro controller, a custom PCB made by tuka customs, uses a promicro board as main source for the keyboard so any simmilar board can be used on this project.
* Hardware Availability: *Links to where you can find this hardware*

Make example for this keyboard (after setting up your build environment):

    make tcbk40:default

Flashing example for this keyboard:

    make tcbk40:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - or short RESET and GND buttons.
* **Keycode in layout**: Press the key mapped to `QK_BOOT` wich is MOD2 and KC ENTER
