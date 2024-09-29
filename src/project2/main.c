// ************************************
// Project 2: Blink an LED with button
// 
// Author: Emanuel Alvarez
// Date: 09/28/2024
// Purpose: This project blinks an LED connected to pin PB5, using a button on PB4
//              using pull-up configuration.
// ************************************

#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    // Set PB5 (LED pin) as an output
    DDRB |= (1 << PB5);
    
    // Set PB4 (Button pin) as an input
    DDRB &= ~(1 << PB4);
    
    // Enable internal pull-up resistor on PB4 (button)
    PORTB |= (1 << PB4);

    while (1) {
        // Check if the button is pressed (pull-up means LOW when pressed)
        if (!(PINB & (1 << PB4))) {
            
            // Button is pressed, turn on LED (PB5)
            PORTB |= (1 << PB5);
        } else {
            // Button is not pressed, turn off LED
            PORTB &= ~(1 << PB5);
        }
    }
}
