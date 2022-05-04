/*
 * servo control.c
 *
 * Created: 3/26/2022 9:26:21 PM
 * Author : kioria
 */ 
# define F_CPU 16000000UL
#include <avr/io.h>
# include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	DDRB=(1<<PB5);
    while (1) 
    {
		PORTB=1<<PB5;
		_delay_ms(3000);
		PORTB=~(1<<PB5);
		_delay_ms(3000);
		
    }
}

