<!-- README.md (English) -->
# Released-Files-TCBK40

# TCBK40
Welcome to the TCBK40 project, a 40% Custom Keyboard with RGB, lovingly crafted from scratch by Tuka Customs. Inspired by the HHK8 layout, this keyboard aims to be a compact and satisfactory option for both community testing of the QMK Firmware and as a daily driver for tech enthusiasts and creators.

![keyboard-layout](https://user-images.githubusercontent.com/115516996/214220018-d1240622-77c8-433f-96e1-704550308988.png)

At first, this project was created to figure out all things needed to complete the first keyboard idea, the tcbk60, the main keyboard created by Tuka Customs.

# How it started?

  The journey of TCBK40 began with a custom PCB designed for TCBK60, the original custom keyboard by Tuka Customs. However, this initial project faced challenges due to an outdated custom firmware that contained numerous unnecessary files and algorithms. Despite successful compilation attempts, it was evident that a simpler keyboard version was needed—one that featured custom layers while retaining the same components.
  Inspiration struck when recalling an old macro-pad project, which sparked the idea of utilizing a pre-built Pro Micro board. This decision offered several advantages, including the convenience of soldering the Pro Micro to the finished PCB and the inclusion of a USB-C connector, known for its superior capabilities and widespread popularity in the market today.
  
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
  
# Pro Micro - The Chosen Processor
  To simplify the design and development process, a switch was made to a simpler keyboard version with custom layers and shared components. Enter the Pro Micro, an ATmega32u4-based board with a USB-C connector, chosen for its widespread popularity and accessibility.
    
# The Power of QMK and the Quest for a Custom Firmware

  Since the choosen firmware was the QMK for all Butter Keyboards Series, while the PCB idea is beeing finished, to make the custom case, and be more acessible as possible, the custom firmware was being studied to be made from scratch, the first firmware made was based on a standart 60-ansi keyboard but has a old firmware built on it, and for make it as a scratch was created a file base on: "https://kbfirmware.com/" wich is super outdated, but at first with help of the QMK Community was corrected and ajusted to work as it is, still with some features, files, algoritms outdated making it be compiled and .hex file created wich probably has some problems.
  The turning point came with the discovery of "qmk new-keyboard" in QMK SYS, which generated all the required files for a custom firmware with updated algorithms and core files. This streamlined the programming process, eliminating unneeded files like "keyboardname.[ch]". The core file now became the info.json, containing essential configurations for manufacturer details, keyboard name display, bootloader, diode direction, feature settings, RGB light configuration, matrix pins, processor specifications, USB settings, and most importantly, the keyboard layout.
  
  ![image](https://user-images.githubusercontent.com/115516996/214229763-13981989-774c-45e7-955b-63d56a7eeeec.png)
  
  The Best part of it, is that on readme.md file has all the informations of the firmware creator for anybody flash their keyboard using it.
  On the outdated version on the QMK Firmware needed the keyboard.[ch] files, wich has the layout position for each row and collum to be substitute, now it won't need anymore because the info.json has the positiona and size of each key:
  
![image](https://user-images.githubusercontent.com/115516996/214231061-71b2df3c-0252-476f-a71b-959d993328be.png)

# Customization and Layers - Enhancing the User Experience

  The TCBK40 boasts a default layout divided into three layers, each accessible through a combination of keys. Additionally, the keyboard features a split space bar, customizable to any key. These features were thoughtfully designed to maximize functionality while maintaining compactness.
  The default layout will be splited into 3 layers that will be acessible by using 2 keys togheter with other keys, and another feature for the keyboard is the split space bar that on default both are space bars but can be changed to any key:
  
  ![image](https://user-images.githubusercontent.com/115516996/214231836-dbd5726b-e500-45d1-bb0e-21140c98f432.png)

# Problems and Solutions ( Firmware )

  During the development of the custom firmware for TCBK40, I encountered a few minor challenges, but fortunately, most of them were swiftly resolved.
  The main issue arose when I was filling up all the information and programming the layout and functions for the keyboard. As I was adjusting the firmware, I found that some of the files and algorithms were outdated, leading to unexpected errors in the process. One particular problem revolved around the keyboard layout, where an error with arguments arose. The layout was limited to 39 arguments, but I had 41/42 arguments in the layout. Initially, I believed that the split space bar might be causing this issue, and I considered combining it into one to potentially resolve the argument count problem. However, this did not yield the desired solution.

Upon further investigation and seeking assistance from others, I discovered that the "keyboard" folder contained both unnecessary files (Keyboardname.[ch]) and that the info.json file was missing one key to be correctly mapped to the keyboard. Rectifying this by making the necessary adjustments and removing the extra commas at the end of each line in the layout, I successfully resolved the issue. With the firmware now corrected, I recompiled it and generated the final hex file, ready for flashing onto the keyboard.
  
  ![image](https://user-images.githubusercontent.com/115516996/214233995-651348ac-a381-4cdf-867f-bf3216e4ae58.png)
  
  This experience underscored the importance of meticulous attention to detail and the significance of staying up-to-date with the latest changes in firmware development. By overcoming these challenges, I was able to ensure the stability and functionality of the custom firmware, creating a smooth and satisfying user experience for the TCBK40 keyboard.

# Schematic

![image](https://user-images.githubusercontent.com/115516996/214237870-b8e84007-0ea6-4141-89db-7ca58d9bb8b3.png)

  The schematic for the TCBK40 keyboard was straightforward and well-planned, with careful consideration given to the design and connections. To ensure accurate representation, a custom symbol and footprint were created for the Pro Micro board, which was selected as the pre-built board to be added to the finished PCB. This decision allowed for easier integration and ensured compatibility with other components.
  To facilitate the process of adding the correct size for each keyboard switch, a layout was created using the "http://www.keyboard-layout-editor.com/" tool. This platform proved to be an invaluable resource for visualizing the keyboard layout and making necessary adjustments to achieve the best fitment and design.
  For the matrix connection, the schematic was thoughtfully designed to provide clear visual cues. All the rows and columns were explicitly labeled on the board, making it easier to verify and connect the components. The horizontal connection for the rows (lines) was relatively straightforward. However, the columns (columns) presented a unique challenge. To simplify programming and increase the likelihood of success, diagonal lines were chosen for the column connections.
  
  ![image](https://user-images.githubusercontent.com/115516996/214242807-abb5780d-35d9-42d5-b549-d6f0123d3201.png)
  (This is a second Draw to view again the connections)

  As a consequence, this approach required the utilization of additional GPIO pins, or alternatively, the creation of a custom matrix for the switches and reprogramming its position in the info.json file. This decision was made to potentially save some GPIO pins, although it came with its complexities and the possibility that it may not work perfectly.
  

# Creating The PCB Design

  After studys and searching for some inspirations to add to the keyboard

# Creating the PCB

# Case
  Designing the case for the TCBK40 keyboard was a crucial step in the overall project. To ensure a well-structured and aesthetically pleasing case, the process began with importing the finished PCB into Fusion 360. The utilization of Kicad's 3D viewer enabled the team to preview the appearance of the keyboard with the desired components mounted on it, providing valuable insights into the final look and feel of the product.
  ![front view](https://user-images.githubusercontent.com/115516996/230317285-8d12554d-603a-4e27-bb1d-752aa193ef91.png)
![Back side](https://user-images.githubusercontent.com/115516996/230317276-aa0b36cc-b4ff-4336-866c-8636a7fba0dc.png)

However, there was a challenge encountered during this stage. Some components' 3D models were missing from the chosen library, particularly the step files. To overcome this, the team decided to import all the step files for the components to simplify the export to Fusion 360. By doing so, every single component could be placed in its correct position and imported seamlessly into the overall design.
  
The primary focus for the case design was the creation of the Switch Plate. Since the main PCB is intended to be attached solely to the plate, this step was of utmost importance to the structural integrity of the keyboard. The placement and quantity of standoffs were meticulously considered to ensure stability and support for the keyboard during use. To achieve the desired result, eight standoffs were strategically distributed, with four on the top and four on the bottom.

For the material of the plate, Clear Acrylic was chosen. This decision was made to allow the diodes on the top part of the PCB to be exposed and visible, showcasing the custom PCB and enhancing the keyboard's aesthetics. In the pursuit of excellence, Chat GPT, an AI with remarkable capabilities, proved to be a valuable resource. It assisted in solving various mathematical problems, such as determining keyboard keycap sizes and spacing. Additionally, it provided insights on programming questions related to keyboard features, including creating a Python software to edit overall functions in the C++ files of the keyboard.

  Continuing with the progress of the Switch Plate, the team delved into understanding the correct spacing, sizing, and data sheets of the MX Switches. Valuable information was obtained from Kobuss's video on case design, which served as a source of inspiration and guidance for the project.
  https://www.youtube.com/watch?v=DsW-hKeB3mc&t=632s
  
  Moreover, a significant discovery was made in the form of a datasheet by Sparkfun, which presented all the recommended sizes for the switch and plate mounts. Armed with this data, the team underwent the necessary transformations to convert the size units from inches to millimeters, aligning with the chosen working units in Fusion 360. As part of the design process, precise measurements were learned and implemented for cutting the plate to accommodate the switches.
  
  ![image](https://user-images.githubusercontent.com/115516996/230322543-25ff6450-1e6f-4a34-bcad-76e51166fb2f.png)

  ![image](https://user-images.githubusercontent.com/115516996/230322608-69c2d541-3153-4961-9ac3-b713934f1529.png)

  Additionally, to enhance functionality and user experience, a thoughtful feature was introduced - circular cuts at each vertex on the plate. This design decision not only allowed for secure switch placement but also enabled easy swapping of switches without the risk of damaging the plate. This added benefit, in conjunction with a visually appealing design, enhanced the overall allure of the TCBK40 keyboard.

  ![another material render](https://github.com/tukacustoms/Released-Files-TCBK40/assets/115516996/b3f183d2-0dcf-4abf-860f-348f29c68e4e)

 # The Power of AI - Chat GPT in Action
Throughout the project, Chat GPT, an AI language model, was invaluable in assisting with mathematical calculations, programming queries, and design optimizations. It proved to be a creative and knowledgeable resource in the pursuit of perfection.
  
# Lessons Learned about Switch Plate Design

During the process of designing the switch plate for the TCBK40 keyboard, several valuable lessons were learned that significantly improved the efficiency and accuracy of the project.

![Keyboard case v26 close](https://github.com/tukacustoms/Released-Files-TCBK40/assets/115516996/d3682dd1-0710-4e38-ab72-60494f6e0b7b)

1. **Matching Switch Sizes and Spacing**: Initially, the first row of measurements matched perfectly, with each switch spaced at 1U (19.05mm) apart. However, complications arose in the subsequent rows due to the presence of different key sizes (2-2.25U, 2-1.75U, 7-1.25U). The challenge was to ensure that the distances between switches in the second row matched the switch placement on the PCB. After utilizing Chat GPT to investigate and think logically about the issue, it was discovered that the 21.4mm distance between switches was achieved by summing the first key size with the second key size and dividing it by 2. This method provided an approximate value for the spacing between different key sizes. Importantly, the calculations were made with exact values from the datasheet but rounded up to account for variations.

2. **Enhancing Switch Plate Design with Keyboard Layout Editor**: A valuable approach to designing the switch plate was found by using http://www.keyboard-layout-editor.com/. This website facilitated the organization and design of the desired layout by allowing users to change and add key sizes, layers, rotations, and colors. After completing the layout, it was saved by clicking on the perma link button, and the raw data was copied for the next step.

3. **Creating Vector Drawings for Switch Plate Design**: Building on the knowledge from the previous lesson, the next step involved making vector drawings for the switch plate based on the raw data provided by the keyboard layout. This eliminated the need to manually measure and calculate all the dimensions from scratch. By visiting http://builder.swillkb.com/, users could configure the plate design, including switch type, stabilizer type, plate corners, and more. This approach saved significant time and ensured the best quality for the switch plate.

In conclusion, through the journey of designing the switch plate, the team gained insights into effective spacing techniques for switches, leveraged innovative tools like the Keyboard Layout Editor and http://builder.swillkb.com/, and experienced the power of using AI assistance (Chat GPT) to solve design challenges. 
  
# Putting everything togheter

The assembly process for the TCBK40 keyboard, with its PCB-mounted stabilizers, involves several key steps to ensure a smooth and successful build:

1. **SMD Parts and PCB Stencil**: Begin by adding the Surface Mount Device (SMD) components to the PCB. These components require careful attention to detail, and it is highly recommended to use a PCB stencil to reduce the risk of burning components and to facilitate precise soldering. Apply solder paste through the stencil onto the designated areas for SMD components.

2. **Place Components and Stabilizers**: After the SMD parts are in place, proceed to add the through-hole components to the PCB. These components are typically larger and easier to handle. Additionally, install the PCB-mounted stabilizers into their designated positions.

3. **Microcontroller Placement**: The TCBK40 keyboard design incorporates a Pro Micro board, which is pre-soldered to the finished PCB. Since the Pro Micro board will sit between other components on the backside, it is best to leave it as the last component to be added. This ensures that it does not obstruct access to other parts of the PCB during assembly.

4. **Switch Placement and Soldering**: For keyboards that require soldering of individual switches, a recommended approach is to initially place some switches onto the main PCB. This step helps to ensure that the switches are correctly aligned and prevents any potential bending or misalignment during the soldering process. Once the initial switches are securely in place, the rest of the switches can be soldered onto the PCB.

5. **Completing the Case**: After the PCB assembly is finished, the switch plate and case can be assembled. The switch plate should align perfectly with the switches on the PCB. Depending on the chosen design, the case may be made of materials like clear acrylic to showcase the custom PCB. The standoffs on the case should be strategically positioned and of sufficient quantity to support the keyboard's stability during use.

6. **Testing and Finishing**: Before finalizing the assembly, it is crucial to thoroughly test the keyboard's functionality. Ensure that all switches register keystrokes correctly and that the PCB-mounted stabilizers are properly functioning. Additionally, verify that the Pro Micro board is functioning as expected.

   ![Keyboard_case_2023-Jul-07_09-18-37PM-000_CustomizedView6189358300](https://github.com/tukacustoms/Released-Files-TCBK40/assets/115516996/56c6411c-5285-478e-bd8b-542953b9d3cf)

# Troubleshooting and Solutions during Testing

During the testing phase of the TCBK40 keyboard, several issues were encountered that needed to be addressed to ensure the keyboard's functionality and usability. Let's examine the problems faced and the solutions implemented:

1. **RGB Lighting Issues**: Initially, when testing the keyboard without soldering the Pro Micro board and switches, the RGB lighting did not function as expected. Some keys' RGB lighting was not working, and there were brightness and color discrepancies among the LEDs.

   - Solution: Upon soldering everything in place, the RGB lighting issue was resolved, and the lighting started working correctly. This indicates that proper soldering of components is crucial for reliable functionality.

2. **Non-Responsive Keys**: After soldering the switches and the Pro Micro board, some keys still didn't register keystrokes during testing.

   - Solution: To address non-responsive keys, the firmware was carefully reviewed, and possible errors in the keymap were identified. After correcting these errors, all keys registered keystrokes as intended.

3. **LED Issues and Brightness**: When testing RGB commands and animations, some LEDs didn't match the top part LEDs, and brightness inconsistencies were noticed.

   - Solution: To resolve LED alignment issues and brightness inconsistencies, thorough testing was conducted to ensure all LEDs were correctly positioned and functional. Additionally, adjustments were made to the firmware to ensure that the RGB lighting settings were accurate and consistent.

4. **Layer and Keymap Improvements**: The initial keymap was found to be lacking some essential keys for regular typing and daily use.

   - Solution: The firmware's keymap was refined and improved to include all necessary keys for daily use, technology hobbies, studies, work, and fun. This ensures that the keyboard is versatile and suitable for various tasks and activities.

By addressing these issues and implementing appropriate solutions, the TCBK40 keyboard can now deliver a satisfactory user experience, with responsive keys, functional RGB lighting, and a well-designed keymap suitable for daily use and other tasks. It's essential to thoroughly test the keyboard and make iterative improvements to achieve the desired functionality and performance.

# Choosing the Perfect Keyboard Switches

  Choosing the keyboard switches could be a challeging thing, specially to choose for a final product options, mechanical keyboard switches are divided in 3 types, linears, tactiles and clicky

  Linear switches are switches with no bumpsj that you can feel when you do the keyoress, they press smothly and the keystroke register before the key hits the bottom, the advantages of this is about the fast response of the overal keystroke but it applys for the downside, witch is beeing the sensibility of the ovreal switches since its current start passing throught as soon as it moves
  ![image](https://github.com/tukacustoms/TCBK40/assets/115516996/7b9a5ee8-d93d-4560-b252-a01dfdd05c9d)

  Tactile switches has a little bump making it tactile as you press it, having a quiet audible click on each keystroke, offering a great feedback experience when typing making you kno by the feel and sound that everything is working properly
  ![image](https://github.com/tukacustoms/TCBK40/assets/115516996/14f68b43-ecd7-45ce-9af2-51596671e412)

  Clicky switches as designed as his name already says, it has a mechanism who creates a clicky sound on the keystroke, having the properties of the tactile switches but it has the oudible click to it
  ![image](https://github.com/tukacustoms/TCBK40/assets/115516996/32aec917-4adf-4d6a-95d3-ecd06c5d035b)


https://pt.aliexpress.com/store/1102816724?spm=a2g0o.detail.0.0.163aNSzPNSzPXC

# Conclusion - A Work of Passion and Expertise
The TCBK40 is the culmination of almost a year of hard work, creativity, and problem-solving. From designing a custom firmware and PCB to crafting a visually appealing case, every aspect has been carefully considered. Tuka Customs' dedication to excellence shines through the seamless user experience of the TCBK40, making it a keyboard worth every penny.

With an impressive blend of knowledge in keyboards, hardware, programming, QMK, schematics, materials, and presentation, Tuka Customs' journey continues to deliver innovative and inspiring projects. As the TCBK40 evolves and grows, new insights and information will continue to be added, making it a valuable and informative resource for keyboard enthusiasts worldwide.

![Keyboard_case_2023-Jul-07_09-18-37PM-000_CustomizedView6189358300](https://github.com/tukacustoms/Released-Files-TCBK40/assets/115516996/af208f74-7783-4bfb-a7ec-6eb87734a0a5)
