/*
 * test_code.c
 *
 * Created: 7/19/2022 7:36:47 PM
 * Author : user
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include "util/delay.h"


int main(void)
{
	DDRB=(0XFF);
    /* Replace with your application code */
    while (1) 
    {
		PORTB^=(0XFF);
		_delay_ms(100);
		
    }
}

