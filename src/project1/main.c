#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN PB5  // Pin 13 on Arduino Uno (PB5)

int main(void) {
    // Set PB5 as output
    DDRB |= (1 << LED_PIN);

    while (1) {
        // Turn on LED (set PB5 high)
        PORTB |= (1 << LED_PIN);
        _delay_ms(2000);  // Delay for 2 s

        // Turn off LED (set PB5 low)
        PORTB &= ~(1 << LED_PIN);
        _delay_ms(2000);  // Delay for 2 s
    }

    return 0;
}
