/*
 * Lab 8 Activity 3.c
 *
 * Created: 3/28/2020 6:10:56 PM
 * Author : Leomar Duran <https://github.com/lduran2>
 * Board  : ATmega324PB Xplained Pro - 2505
 * For    : ECE 3612, Spring 2020
 * Self   : <https://github.com/lduran2/ece3612-lab8/blob/master/activity3.c>
 *
 * Counts the number of zeroes in 4 selected numbers and displays each
 * count on the Seven Segment Display.
 */ 
#include <avr/io.h>
/* CPU at 16 MHz */
#define	F_CPU ((unsigned long)(16e+6))
#include <util/delay.h>

/* number of bits in an 8 bit number */
#define	N_BITS (8u)
/* masks the least significant bit */
#define	LSB_MASK (0b00000001)
/* delay when Seven Segment Display is on */
#define	ON_DELAY (2000u)
/* delay when Seven Segment Display is off */
#define	OFF_DELAY (1000u)

int main(void)
{
	/* set up ports: */
	DDRA = 0xFF;	/* PORTA data direction to all outputs */
	PORTB = 0xFF;	/* activate PORTB pull switches */
	DDRB = 0x00;	/* PORTB data direction to all inputs */

	/* numbers to process */
	char numbers[] =
	{
		0b11001010	/*  -54 */,
		0b01101111	/*  111 */,
		0b10000100	/* -124 */,
		0b11111011	/*   -5 */,
		0
	};

	/* bit pattern encoder for 0 to 7 */
	char bit_patterns[N_BITS] =
	{
		0b00111111, 0b00000110, 0b01011011, 0b01001111,
		0b01100110, 0b01101101, 0b01111101, 0b00000111
	};

	/* counters: */
	char *p_number;	/* pointer to current number */
	unsigned char n_zeros;	/* number of zeroes */

	/* for each number */
	for (p_number = numbers; *p_number; ++p_number)
	{
		/* set number of zeroes */
		n_zeros = N_BITS;
		/* shift each bit to the right until we run out of ones */
		for (; *p_number; *p_number >>= 1)
		{
			/* when the least significant bit is set: */
			if (*p_number & LSB_MASK)
			{
				/* another one, so one less zero */
				--n_zeros;
				/* this happens at least once because the loop ensures */
				/* that `*p_number` is nonzero */
			} /* end if (*p_number & LSB_MASK) */
		} /* end for (; *p_number; *p_number >>= 1) */

		/* display the output: */
		/* show the bit pattern for number of zeroes */
		PORTA = bit_patterns[n_zeros];
		_delay_ms(ON_DELAY);	/* delay for on */
		PORTA = 0b00000000;	/* clear PORTA */
		_delay_ms(OFF_DELAY);	/* delay for off */
	} /* end for (; *p_number; ++p_number) */

	return 0;
} /* end main(void) */
