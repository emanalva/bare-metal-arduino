# Bare-Metal Arduino Coding in C

## Overview
This project demonstrates bare-metal programming on an Arduino using C. The code directly manipulates hardware registers to control basic peripherals like LEDs and buttons, without relying on the Arduino libraries.

## Project 1: Blink an LED
This project blinks an LED connected to **pin PB5** (Arduino Uno's digital pin 13) by directly controlling the pin using hardware registers.

## Project 2: Button-Controlled LED
In this project, an LED is controlled using a button connected to **pin PB4** (Arduino Uno's digital pin 12). A pull-up resistor is enabled on the button pin to ensure stable input, and the button’s state is debounced in software to avoid noise. The project is modularized, with functions for initializing the pins and reading the button state.

## Project 3: PWM-Controlled LED Brightness
In this project, we introduce **Pulse Width Modulation (PWM)** to control the brightness of an LED connected to **pin PB1** (Arduino Uno's digital pin 9).

## Steps to Upload Code to Arduino
Follow these steps to compile and upload the code to your Arduino:

1. Navigate to the project directory:
   ```bash
   cd path/to/project/directory
   ```

2. Open the Makefile and update the USB port connection to match your Arduino's port. For example:
   ```bash
   sed -i 's/ARDUINO_PORT = \/dev\/ttyACM0/ARDUINO_PORT = \/dev\/ttyUSB0/' Makefile
   ```
   Replace `/dev/ttyUSB0` with the actual port your Arduino is connected to.

3. Compile the code:
   ```bash
   make
   ```

4. Upload the compiled code to the Arduino:
   ```bash
   make flash
   ```

## Datasheet Links
The datasheets provide detailed technical information needed for using the Arduino configuring the microcontroller.

- [Arduino Uno Documentation](https://docs.arduino.cc/hardware/uno-rev3/): This Arduino site provides the datasheet for the Uno showing the **pinout** and other hardware specifications for the Arduino Uno board. It's useful for understanding which pins are connected to specific microcontroller functions.
- [ATmega328P Datasheet](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf): This datasheet provides technical details on the **ATmega328P microcontroller**, which is used in the Arduino Uno. It’s essential for understanding **timers**, **registers**, and how to control peripherals at a low level.

© 2024 Emanuel Alvarez