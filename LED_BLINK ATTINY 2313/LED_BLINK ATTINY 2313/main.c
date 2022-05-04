/*
 * LED_BLINK ATTINY 2313.c
 *
 * Created: 3/12/2022 10:48:53 AM
 * Author : user
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
# include <avr/delay.h>
#define configure_port DDRD
#define set_logic_to PORTD
#define HIGH 1
#define LOW 0
#define OUTPUT 1
#define INPUT 0
#define LED PD0
#define state 0
int main(void)
{
    //my initialization
	configure_port=OUTPUT;
    while (1) 
    {
// 		set_logic_to=(HIGH<<LED);
// 		_delay_ms(100);
// 		set_logic_to=(LOW<<LED);
// 		_delay_ms(100);
set_logic_to=(!state);
_delay_ms(100);
    }
}

