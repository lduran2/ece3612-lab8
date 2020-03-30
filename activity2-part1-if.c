/*
 * Lab 8 Activity 2 Part 1 If.c
 *
 * Created: 3/26/2020 12:09:38 PM
 * Author : Leomar Duran <https://github.com/lduran2>
 * Board  : ATmega324PB Xplained Pro - 2505
 * For    : ECE 3612, Spring 2020
 * Self   : <https://github.com/lduran2/ece3612-lab8/blob/master/activity2-part1-if.c>
 *
 * Encodes the number represented in binary by the switches PB[3:0] and
 * displays it on the Seven Segment Display.  This implementation uses
 * `if` statements to encode.
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
		/* get only the relevant switches */
		digit = (PINB & PORTB_MASK);

		/* encode the digit into a bit_pattern */
		if (0b0001 == digit)
		{
			bit_pattern = 0b00000110;
		} /* end if (0b0001 == digit) */
		else if (0b0010 == digit)
		{
			bit_pattern = 0b01011011;
		} /* end if (0b0010 == digit) */
		else if (0b0011 == digit)
		{
			bit_pattern = 0b01001111;
		} /* end if (0b0011 == digit) */
		else if (0b0100 == digit)
		{
			bit_pattern = 0b01100110;
		} /* end if (0b0100 == digit) */
		else if (0b0101 == digit)
		{
			bit_pattern = 0b01101101;
		} /* end if (0b0101 == digit) */
		else if (0b0110 == digit)
		{
			bit_pattern = 0b01111101;
		} /* end if (0b0110 == digit) */
		else if (0b0111 == digit)
		{
			bit_pattern = 0b00000111;
		} /* end if (0b0111 == digit) */
		else if (0b1000 == digit)
		{
			bit_pattern = 0b01111111;
		} /* end if (0b1000 == digit) */
		else if (0b1001 == digit)
		{
			bit_pattern = 0b01101111;
		} /* end if (0b1001 == digit) */
		else if (0b1010 == digit)
		{
			bit_pattern = 0b01110111;
		} /* end if (0b1010 == digit) */
		else if (0b1011 == digit)
		{
			bit_pattern = 0b01111100;
		} /* end if (0b1011 == digit) */
		else if (0b1100 == digit)
		{
			bit_pattern = 0b00111001;
		} /* end if (0b1100 == digit) */
		else if (0b1101 == digit)
		{
			bit_pattern = 0b01011110;
		} /* end if (0b1101 == digit) */
		else if (0b1110 == digit)
		{
			bit_pattern = 0b01111001;
		} /* end if (0b1110 == digit) */
		else if (0b1111 == digit)
		{
			bit_pattern = 0b01110001;
		} /* end if (0b1111 == digit) */
		else
		{ /* so digit must be 0b0000 */
			bit_pattern = 0b00111111;
		} /* end if (0b0000 == digit) */

		/* set the PORTA to the encoded bit_pattern */
		PORTA = bit_pattern;
	} /* end while (1) */

	return 0;
} /* end main(void) */
