/*
 * interrupt.c
 *
 * Created: 7/19/2022 9:47:02 PM
 *  Author: bit_toggler
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
//initialize interrupt
void interrupt_init(char interrupt_,char trigger_level){
	//case interrupt 0
	if(interrupt_==INTERRUPT_PIN_0){
		//setting interrupt port as input
		INTERRUPT_DDR|=(1<<INTERRUPT_PIN_0);
		//enable the interrupt pin 
		interrupt_enable_reg=enable_interrupt_0;
		//define trigger level
		trigger_level_reg=trigger_level;
		//activate internal pull up resistor_on PD2
		INTERRUPT_PORT|=set_internal_pullup_interrupt_pin_0;	
	}else if(interrupt_==INTERRUPT_PIN_1){
		//case interrupt 1
		//setting interrupt port as input
		INTERRUPT_DDR|=(1<<INTERRUPT_PIN_1);
		//enable the interrupt pin 
		interrupt_enable_reg=enable_interrupt_1;
		//define trigger level
		trigger_level_reg=trigger_level;
		//activate internal pull up resistor_on PD2
		INTERRUPT_PORT|=set_internal_pullup_interrupt_pin_1;
	}else if(interrupt_==both_interrupts){
	//case interrupt 1					
	//setting interrupt port as input
	INTERRUPT_DDR|=(1<<INTERRUPT_PIN_1)|(1<<INTERRUPT_PIN_0);
	//enable the interrupt pin
	interrupt_enable_reg|=(enable_interrupt_0)|(enable_interrupt_1);
	//define trigger level
	trigger_level_reg=trigger_level;
	//activate internal pull up resistor_on PD2 and PD
	INTERRUPT_PORT|=(set_internal_pullup_interrupt_pin_1)|(set_internal_pullup_interrupt_pin_0);	
	}else{
		//break;
	}
	
	
	//case interrupt both
	//enable the global interrupt
	enable_global_interrupt;
	
}
/*DOCUMENTATION
this is a library for interacting with external hardware interrupts in Atmega328p micro controller
INT0
INT1
One can either choose to use either of the interrupts or both_interrupts and can specify the method of triggering the interrupt
sample function
case 1
			interrupt_init(enable_interrupt_0,rising_edge_0);//this activates interrupt 0 INTO on the rising edge ...its importnat to note however one can 
			specify other triggering levels as per definitions in the interrupt.h file 
case 2
			interrupt_init(enable_interrupt_1,falling_edge_interrupt_1);//its important to note that the last number is associted with interrupt numbei cre
I created this library with sole aim of reducing the complexity of writing your every time you want to work with interrupt.
however i have simplified the registers,the pins to something under stable according to the working go the interrupts 
.....
feel free to consult the data sheet every time you are in doubt.
Bit_toggler 



*/

