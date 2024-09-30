// ************************************
// Project 3: Control LED using PWM
// 
// Author: Emanuel Alvarez
// Date: 09/28/2024
// Purpose: This project controls the brightness of an LED connected to pin PB1
//              using PWM.
// ************************************

#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN PB1  // Pin 9 on Arduino Uno (OC1A)
#define PWM_MAX 65535  // Maximum PWM value (16-bit resolution)

int main(void) {
    // Set PB1 as output
    DDRB |= (1 << LED_PIN);

    TCCR1A = 0;  // Clear TCCR1A
    TCCR1B = 0;  // Clear TCCR1B

    // Initialize Timer1 for PWM mode
    TCCR1A |= (1 << COM1A1) | (1 << WGM11);  // Fast PWM mode, 16-bit
    TCCR1B |= (1 << WGM13) | (1 << WGM12) | (1 << CS10);  // Fast PWM mode, prescaler = 8
    TCCR1A &= ~(1 << WGM10);  // Ensure WGM10 is cleared


    // Set the TOP value for 16-bit timer
    ICR1 = PWM_MAX;

    uint16_t brightness = 0;
    int16_t direction = 1024;  // Larger step for noticeable change

    while (1) {
        // Set PWM duty cycle
        OCR1A = brightness;

        // Change brightness
        brightness += direction;

        // Reverse direction at limits
        if (brightness <= 0 || brightness >= PWM_MAX) {
            direction = -direction;
        }

        _delay_ms(10);  // Small delay for visible effect
    }

    return 0;
}

