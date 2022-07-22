/*
 * interrupt_test.c
 *
 * Created: 7/19/2022 8:10:51 PM
 * Author : user
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
//ISR
ISR(INT0_vect){
	int display[]={0x01,0x02,0x04};
		int color=0;
		while ( color<3)
		{
			PORTB=display[color];
			_delay_ms(200);
			color++;
			if (color==3)
			{
				color=0;
			}
			
		}
			
		
// 	PORTB^=(1<<PB5);
// 	_delay_ms(300);
	
}
int main(void)
{
	
	DDRD=(0x00);//make port d as input
	DDRB=(0xff);//make port b as output
	DDRC=(0xff);
	EIMSK=(1<<INT0);//enable interrupt 0
	EICRA=(0x03);//
	
	PORTD=(1<<PD2);//ACTIVE INTRNAL PULL RES
	sei();
    /* Replace with your application code */
    while (1) 
    {
		PORTC^=(0xff);
		_delay_ms(100);
    }
}

