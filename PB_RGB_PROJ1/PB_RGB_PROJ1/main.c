/*
 * PB_RGB_PROJ1.c
 *
 * Created: 7/13/2022 9:38:25 PM
 * Author : kioria
 */ 
//PREPROCESSOR DIRIECTIVES
//define cpu speed
#define F_CPU 16000000UL
#include <avr/io.h>//avr input out peripherals ports,registers
//include delay library
#include <util/delay.h>
//include interrupt library
#include <avr/interrupt.h>
#include "interrupt.h"
const uint8_t   feedback[]="do kuninitialize man..\n\r";
/*uart communication for feedback*/
#include <stdint.h>//include standard int header
//#include "uart.h"//include the uart  header file
#define OUTPUT 0xFF
#define INPUT (0x00)
//port renaming
#define RGB_DDR		 DDRB
#define RGB_PORT	 PORTB
#define RED_LED			PB0
#define GREEN_LED		 PB1
#define BLUE_LED		PB2
int rgb_led_light_sequence []={0x01,0x02,0x04};

//define an isr 
ISR(INT0_vect){
	//_delay_ms(55);//debounce
// 	volatile uint8_t c[]="niko kw a interrupt\n\r";
// 	uart_send_string(c);
	
	for (int count=0;count<3;count++)
	{
		RGB_PORT=rgb_led_light_sequence[count];
		
		if(count==3){
			count=0;//reset count when count reaches 3
		}
		_delay_ms(2000);
	}
	
	RGB_PORT=INPUT;
	
}
ISR(INT1_vect){
	//_delay_ms(55);//debounce
	// 	volatile uint8_t c[]="niko kw a interrupt\n\r";
	// 	uart_send_string(c);
	
	for (int count=0;count<3;count++)
	{
		RGB_PORT=rgb_led_light_sequence[count];
		
		if(count==3){
			count=0;//reset count when count reaches 3
		}
		_delay_ms(2000);
	}
	
	RGB_PORT=INPUT;
	
}



int main(void)

{
	DDRC=(0xFF);
	//SET LEDPORT AS OUTPUT
	RGB_DDR=OUTPUT;
	//initialize interrupt
	interrupt_init(INTERRUPT_PIN_1,falling_edge_0);//enable interrupt 0 on the rising edge 
    /* Replace with your application code */
    while (1) 
    {
		//uart_send_string(feedback);
PORTC^=0XFF;
_delay_ms(1000);
    }
}

