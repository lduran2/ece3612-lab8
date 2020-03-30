/*
 * Lab 8 Activity 1.c
 *
 * Created: 3/26/2020 4:07:54 PM
 * Author : Leomar Duran <https://github.com/lduran2>
 * Board  : ATmega324PB Xplained Pro - 2505
 * For    : ECE 3612, Spring 2020
 * Self   : <https://github.com/lduran2/ece3612-lab8/blob/master/activity1.c>
 *
 * Counts up or down the numbers [0, 9] on the Seven Segment Display
 * depending on the state of switch PB0.
 */ 

#include <avr/io.h>
/* CPU at 16 MHz */
#define	F_CPU ((unsigned long)(16e+6))
#include <util/delay.h>

/* switch to test */
#define	SENSOR 0

int main(void)
{
	/* function protocols: */
	void inc(unsigned char *p);	/* increment update function */
	void dec(unsigned char *p);	/* decrement update function */
	void delay500nms(unsigned char n);	/* delays for 500n milliseconds */

	/* set up ports: */
	DDRA = 0xFF;	/* PORTA data direction to all outputs */
	PORTB = 0xFF;	/* activate PORTB pull switches */
	DDRB = 0x00;	/* PORTB data direction to all inputs */

	/* bit pattern encoder for 0 to 9 */
	char bit_patterns[] =
	{
		0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110,
		0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111
	};

	/* loop controls: */
	/* starting values (where the counter starts) */
	unsigned char starts[] = {0u, 9u};
	/* exit values (where the counter exits) */
	unsigned char exits[] = {10u, (unsigned char)(-1)};
	/* update functions : array of (unsigned char *)->(void) functions */
	void (*updates[])(unsigned char *p) = { inc, dec };

	/* amounts of times to show each bit pattern */
	unsigned char delays[] = {1u, 2u};

	unsigned char seq;	/* sequence index determined by PB0 */
	unsigned char digit;	/* counter to display */

	/* listen indefinitely */
	while (1) 
	{
		/* calculate the sequence index */
		seq = ((PINB >> SENSOR) & 1);

		/* loop from the start to exit, updating according to the lookup */
		for (digit = starts[seq]; digit != exits[seq]; updates[seq](&digit))
		{
			/* look up the bit pattern and copy to PORTA */
			PORTA = bit_patterns[digit];
			/* delay according to the lookup */
			delay500nms(delays[seq]);
		} /* end for (; digit != exits[pb0]; ) */
	} /* end while (1) */

	return 0; /* exit successfully */
} /* end main(void) */

/**
 * Increment update function.
 * @params
 *   *p : unsigned char = pointer to value to update
 */
void inc(unsigned char *p)
{
	++(*p);
} /* end inc(unsigned char *p) */

/**
 * Decrement update function.
 * @params
 *   *p : unsigned char = pointer to value to update
 */
void dec(unsigned char *p)
{
	--(*p);
} /* end dec(unsigned char *p) */

/**
 * Delays for 500n milliseconds.  Delay is implemented as a loop
 * because `_delay_ms` requires a compile time constant argument.
 * @params
 *   n : unsigned char = the number of times to delay by 500 ms
 */
void delay500nms(unsigned char n)
{
	/* countdown to 0: */
	for (; n; --n)
	{
		_delay_ms(500u); /* delay for 500ms each time */
	} /* end for (; n; ) */
} /* end delay500nms(unsigned char n) */
