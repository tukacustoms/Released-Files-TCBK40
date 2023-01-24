# Released-Files-TCBK40

# TCBK40
This is a 40% Custom Keyboard with RGB, made from scratch By Tuka Customs, It's inspired by HHK8 Layout !

-This Keyboard was made for a community use For testing and figuring out Problems with QMK Firmware and for a compact satisfatory keyboard to work with.

![keyboard-layout](https://user-images.githubusercontent.com/115516996/214220018-d1240622-77c8-433f-96e1-704550308988.png)

At first, this project was created to figure out all things needed to complete the first keyboard idea, the tcbk60, the main keyboard created by Tuka Customs.

# How it started?

  Having problems with a custom PCB Created for the TCBK60, the first custom firmware created after some studies was outdated, many files and algoritms are unecessary to make the custom firmware, still compiled, but after so many tries was decided that wanted to create a simpler keyboard version, with custom layers and same components.
  At the end, after looking for some inspirations and remembering a old project of macro-pad, was decided to use a pre-build Pro micro board to be soldered to the finished PCB, the choosen one was specially with USB-C connector, the better connector on the market nowadays.
  
  ![image](https://user-images.githubusercontent.com/115516996/214223540-ccb4da91-337c-464e-a0c2-f939b0339db3.png)

# What processors could be the option and why the Pro micro (Atmega32u4)?

  Nowadays we have many processors that can be used to make a custom keyboard, making a little question at first what one should we choose, and in this project wasn't diferent.
  The ones that was chosen were ATmega32u4(Pro micro board), Raspberry Pi Pico (RP2040) and the famous STM32 Processor.
 
# Why didn't use Raspberry PI PICO?

![image](https://user-images.githubusercontent.com/115516996/214224287-f3fde7cd-7b2c-4d5f-add3-9545506abc65.png)
![image](https://user-images.githubusercontent.com/115516996/214224469-b21da7f4-d63d-49b5-b753-f6fb16c284ff.png)

  The Raspberry PI PICO is a great option as a main processor for a pre-build board to add to the TCBK40, has 40 GPIO pins, 27 multifunctional GPIO pins, features a dual-core Arm Cortex-M0+ processor with 264kB internal RAM and support for up to 16MB of off-chip flash, has I2C and SPI Features.
  Total GPIOS are more than enought to make Butter Keyboards Series, but it has some downsides:
  - It uses micro usb conection, but can be changed using a usb-c shield but unfortunaly could use some GPIO's;
  - More Difficult to find supply's for it in Brazil
  - Uses an micro processor that is a bit propietary but nowadays the QMK Community made it able to use on QMK Firmware
  
# Why didn't use STM32 Processor

![image](https://user-images.githubusercontent.com/115516996/214225472-ef0a55bd-cbf2-41e1-9166-7d97b0a52f0e.png)

  STM32 Processor is one of the best cost effective processors known, super fast and has plenty GPIO Pins to use it, 64K flash memory, has internal 4-16mhz crystal (but i recommend to use a external one),has USART connection wich is icredibly usefull, SPI and I2C Connection, a powerfull micro controller.
  
![image](https://user-images.githubusercontent.com/115516996/214226004-98c2c98f-6d91-45f6-a479-87bae1c894dc.png)
    
  This one of the best development boards known, used in many areas like 3d printers and CNC machines motherboards, and for a keyboard processor it's one of the best ones, unfortunaly it wasn't used in this project just because the ATMEGA32u4 is a processor that is most used by Tuka Customs and most known for the area, making it more acessible for every person, easier to find and has more pre-build development boards on market, but STM32 family will be the best for a Custom PCB.
    
# Custom Firmware

  Since the choosen firmware was the QMK for all Butter Keyboards Series, while the PCB idea is beeing finished, to make the custom case, and be more acessible as possible, the custom firmware was being studied to be made from scratch, the first firmware made was based on a standart 60-ansi keyboard but has a old firmware built on it, and for make it as a scratch was created a file base on: "https://kbfirmware.com/" wich is super outdated, but at first with help of the QMK Community was corrected and ajusted to work as it is, still with some features, files, algoritms outdated making it be compiled and .hex file created wich probably has some problems.
  After some research, was discovered that QMK SYS ( the program that compile all the keyboards and keymaps ) has a function that it is "qmk new-keyboard", who creates every file needed to create a custom keyboard firmware with updated files and algoritms, many of the core files are the same but was so much easier to program and make a custom firmware since many other unecessary files was removed, like "keyboardname.[ch]" files.
  
  ![image](https://user-images.githubusercontent.com/115516996/214229763-13981989-774c-45e7-955b-63d56a7eeeec.png)
  
  The Best part of it, is that on readme.md file has all the informations of the firmware creator for anybody flash their keyboard using it.
  This updated firmware, the core file now is the info.json file, who has the config for manufacturer, kayboard name to show when plug in, bootloader, diode direction, feature to be able or disable, rgb light configure, matrix pins, processor, usb specifications, and most important the layout.
  On the outdated version on the QMK Firmware needed the keyboard.[ch] files, wich has the layout position for each row and collum to be substitute, now it won't need anymore because the info.json has the positiona and size of each key:
  
![image](https://user-images.githubusercontent.com/115516996/214231061-71b2df3c-0252-476f-a71b-959d993328be.png)

  The default layout will be splited into 3 layers that will be acessible by using 2 keys togheter with other keys, and another feature for the keyboard is the split space bar that on default both are space bars but can be changed to any key:
  
  ![image](https://user-images.githubusercontent.com/115516996/214231836-dbd5726b-e500-45d1-bb0e-21140c98f432.png)

# Problems and Solutions ( Firmware )

  Fortunaly, was almost any problems with creating a custom firmware, just minnor problems that was solved super fast.
  Main problem was that when was filling up all the information and programing all the layout and functions, since was learned to ajust by the older way, it became mixed with outdated and updated files and algoritms, having a trouble with only on the layout, it was giving me an error with arguments, was limited by 39 and had 41/42 arguments on the layout, wich at first was tought that the problem was the split space bar because making into one probably will be the corrected number of arguments, but still wasn't the solution, after asking and checking, the keyboard folder has the both unecessary files ( Keyboardname.[ch] ) and info.json was missing one line/key to be mapped to the keyboard. Changed and still giving almost the same error, after counting several times the layout keys on keymap.c, say that the number of keys was correct, the solution was simpler than expected, just had comas on the end of each last line of the layout making the program think that was one more on each layer, changing it and re-compile it, was generated the final hex file for it to flash.
  
  ![image](https://user-images.githubusercontent.com/115516996/214233995-651348ac-a381-4cdf-867f-bf3216e4ae58.png)

# Schematic

![image](https://user-images.githubusercontent.com/115516996/214237870-b8e84007-0ea6-4141-89db-7ca58d9bb8b3.png)

  Schematic for the TCBK40 was prety straight foward, only thing that needed was a custom symbol and footprint for the pro micro board, since will be used a pre-build board to be added to the finished pcb. For adding the corrected size for each keyboard switch was made a layout on "http://www.keyboard-layout-editor.com/" wich is the best for visualising the keyboard layout and ajusting for the best fitment and design.
  To make the matrix connection and better to visualize, was written on the board all the rows and collums to be easier to verify while connecting, the rows are easier since is a straight horizontal connection on all switches (lines), but on the collums are a bit more different. Was chosen to use diagonal lines to be easier to program at first and be more likely to work, unfortunaly will use more GPIO PINS or make a custom matrix for the switches and reprogram it's position on info.json to save some GPIO but it's more difficult and could not work.
  
  ![image](https://user-images.githubusercontent.com/115516996/214242807-abb5780d-35d9-42d5-b549-d6f0123d3201.png)
  (This is a second Draw to view again the connections)
  

  
# Creating The PCB Design

# Creating the PCB

# Case

# Why The Case is this design?
  




    
    
  
