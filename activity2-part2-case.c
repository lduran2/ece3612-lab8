/*
 * Lab 8 Activity 2 Part 1 Case.c
 *
 * Created: 3/26/2020 5:22:04 PM
 * Author : Leomar Duran
 * Board  : ATmega324PB Xplained Pro - 2505
 * For    : ECE 3612, Spring 2020
 *
 * Encodes the number represented in binary by the switches PB[3:0] and
 * displays it on the Seven Segment Display.  This implementation uses
 * `switch` and `case` statements to encode.
 */ 
#include <avr/io.h>

/* PB switches whereto, to listen */
#define	PORTB_MASK (0b00001111)

int main(void)
{
	/* set up ports: */
	DDRA = 0xFF;	/* PORTA data direction to all outputs */
	PORTB = 0xFF;	/* activate PORTB pull switches */
	DDRB = 0x00;	/* PORTB data direction to all inputs */

	/* encoding: */
	char digit;	/* the digit to encode */
	char bit_pattern;	/* the bit pattern encoded */

	/* listen indefinitely */
	while (1)
	{
		/* encode the relevant switches into a bit_pattern */
		switch (PINB & PORTB_MASK)
		{
			case 0b0001:
				bit_pattern = 0b00000110;
			break;
			case 0b0010:
				bit_pattern = 0b01011011;
			break;
			case 0b0011:
				bit_pattern = 0b01001111;
			break;
			case 0b0100:
				bit_pattern = 0b01100110;
			break;
			case 0b0101:
				bit_pattern = 0b01101101;
			break;
			case 0b0110:
				bit_pattern = 0b01111101;
			break;
			case 0b0111:
				bit_pattern = 0b00000111;
			break;
			case 0b1000:
				bit_pattern = 0b01111111;
			break;
			case 0b1001:
				bit_pattern = 0b01101111;
			break;
			case 0b1010:
				bit_pattern = 0b01110111;
			break;
			case 0b1011:
				bit_pattern = 0b01111100;
			break;
			case 0b1100:
				bit_pattern = 0b00111001;
			break;
			case 0b1101:
				bit_pattern = 0b01011110;
			break;
			case 0b1110:
				bit_pattern = 0b01111001;
			break;
			case 0b1111:
				bit_pattern = 0b01110001;
			break;
			default: /* so digit must be 0b0000 */
				bit_pattern = 0b00111111;
			break;
		} /* end switch (PINB & PORTB_MASK) */

		/* set the PORTA to the encoded bit_pattern */
		PORTA = bit_pattern;
	} /* end while (1) */

	return 0;
} /* end main(void) */
