/*
 * TEST_CODE_CONNECTION.c
 *
 * Created: 7/13/2022 9:02:50 PM
 * Author : KIORIA
 */ 
//define cpu speed
#define F_CPU 16000000UL

#include <avr/io.h>
//include the delay library
#include <avr/delay.h>
//renaming of ports and DDR
#define TEST_DDR    DDRB 
#define TEST_PORT PORTB 
#define output (0xff)
#define LED     PB5
#define LED_TOGGLE (1<<LED)//

1

int main(void)
{
	//set PORTB as output
	TEST_DDR=output;
    /* Replace with your application code */
    while (1) 
    {
		TEST_PORT^=LED_TOGGLE;//toggle the status of inbuilt led
		//delay
		_delay_ms(5000);
    }
}

