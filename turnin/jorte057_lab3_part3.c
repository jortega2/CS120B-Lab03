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
	DDRA = 0x00; PORTA = 0xFF; // configure ports A's pins as input initialize with 1s
	DDRC = 0xFF; PORTC = 0x00; // configure port C's pins as outputs/ initialize to 0s
	unsigned char tmpA = 0x00;
    /* Insert your solution below */
    while (1) {
	tmpA = PINA;
	
	//check fuel level, ignore seatbelt/key/driver checks for now
	switch (tmpA & 0x0F){
		case (0x00) : PORTC = 0x40; //no light, low fuel warning (PC^)
		break; 
		case (0x01) : PORTC = 0x60; //PC5 lights, low fuel warning (PC6)
                break;
		case (0x02) : PORTC = 0x60; //PC5 lights, low fuel warning (PC6)
                break;
		case (0x03) : PORTC = 0x70; //PC5, PC4 lights, low fuel warning (PC6)
                break;
		case (0x04) : PORTC = 0x70; //PC5, PC4 lights, low fuel warning (PC6)
                break;
		case (0x05) : PORTC = 0x38; //PC5, PC4, PC3  lights, no fuel warning (PC6)
                break;
		case (0x06) : PORTC = 0x38; //PC5, PC4, PC3  lights, no fuel warning (PC6)
                break;
		case (0x07) : PORTC = 0x3C; //PC5, PC4, PC3, PC2  lights, no fuel warning (PC6)
                break;
		case (0x08) : PORTC = 0x3C; //PC5, PC4, PC3, PC2  lights, no fuel warning (PC6)
                break;
		case (0x09) : PORTC = 0x3C; //PC5, PC4, PC3, PC2  lights, no fuel warning (PC6)
                break;
		case (0x0A) : PORTC = 0x3E; //PC5, PC4, PC3, PC2, PC1  lights no fuel warning
                break;
		case (0x0B) : PORTC = 0x3E; //PC5, PC4, PC3, PC2, PC1  lights no fuel warning
                break;
		case (0x0C) : PORTC = 0x3E; //PC5, PC4, PC3, PC2, PC1  lights no fuel warning
                break;
		case (0x0D) : PORTC = 0x3F; // PC5, PC4, PC3, PC2, PC1 light no warning
		break;
		case (0x0E) : PORTC = 0x3F; // PC5, PC4, PC3, PC2, PC1 light no warning
                break;
		case (0x0F) : PORTC = 0x3F; // PC5, PC4, PC3, PC2, PC1 light no warning
                break;
	}
	//set P7 to 1 if driver in seat and key is in ignition but seatbelt not fasten	
	if ((tmpA & 0x70) == 0x60){
		PORTC = (PORTC & 0x7F) | 0x80;
	}
    }
    return 1;
}
