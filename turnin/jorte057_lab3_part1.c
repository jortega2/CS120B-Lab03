/*	Author: jorte057
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab 3  Exercise 1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; // configure ports A and B's pins as input, initialize to 1s
	DDRB = 0x00; PORTB = 0xFF; //
	DDRC = 0xFF; PORTC = 0x00; // configure port C's pins as outputs/ initialize to 0s
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
    /* Insert your solution below */
    while (1) {
	tmpA = ((PINA & 0x80) && 1) + ((PINA & 0x40) && 1) +((PINA & 0x20) && 1) +((PINA & 0x10) && 1) +((PINA & 0x08) && 1) +((PINA & 0x04) && 1) +((PINA & 0x02) && 1) +((PINA & 0x01) && 1);

	tmpB = ((PINB & 0x80) && 1) + ((PINB & 0x40) && 1) +((PINB & 0x20) && 1) +((PINB & 0x10) && 1) +((PINB & 0x08) && 1) +((PINB & 0x04) && 1) +((PINB & 0x02) && 1) +((PINB & 0x01) && 1);

	PORTC = tmpA + tmpB;
	
    }
    return 1;
}
