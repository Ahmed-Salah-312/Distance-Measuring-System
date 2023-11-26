#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include "ultrasonic.h"
#include <avr/interrupt.h>

int main(void) {
    LCD_init();
    Ultrasonic_init();
    uint16 Distance;

    LCD_moveCursor(0, 0);
    LCD_displayString("Distance =    cm");

    SREG |= (1<<7); // Enable global interrupts

    while (1) {
        Distance = Ultrasonic_readDistance()+1;
        LCD_moveCursor(0, 10);
        LCD_intgerToString(Distance);
        LCD_displayCharacter(' ');
    }

    return 0;
}
