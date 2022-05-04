/*
 * timer0config_delay_function atmega328p.c
 *
 * Created: 3/26/2022 7:09:09 PM
 * Author : user
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/delay.h>
//initialize timer function
void ngoja(int start_value_hex);
int main(void)
{
	DDRB=1<<PB5;//configure port as output
	
    /* Replace with your application code */
    while (1) 
    {
		PORTB=(1<<PB5);
		ngoja(0X83);
	/*	_delay_ms(100);*/
		PORTB=(0b00000000);
		ngoja(0X83);
		/*_delay_ms(100);*/
    }
}
void ngoja(int start_value_hex){
	TCCR0A=0x00;
	TCCR0B=1<<CS00|1<<CS02;//select prescaler as1024
	TCNT0=start_value_hex;
	 while((TIFR0 & 0x01) == 0);//wait till timer overflow flag is raised
	  //reset the registers
	  TCCR0A = 0x00;
	  TCCR0B = 0x00;
	  TIFR0 = 0x1;//CLEARING THE TIMER OVERFLOW INTERRUPT
}

