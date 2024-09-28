# Bare-Metal Arduino Coding in C

## Overview
This project demonstrates bare-metal programming on an Arduino using C. The code directly manipulates hardware registers to control basic peripherals like LEDs and buttons, without relying on the Arduino libraries.

## Project 1: Blink an LED
This project blinks an LED connected to **pin PB5** (Arduino Uno's digital pin 13) by directly controlling the pin using hardware registers.

## Project 2: Button-Controlled LED
In this project, an LED is toggled on/off by pressing a button. The button and LED control is modularized using C header files for better code organization and reuse.