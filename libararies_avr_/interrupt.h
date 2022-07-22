/*
 * interrupt.h
 *
 * Created: 7/19/2022 9:48:19 PM
 *  Author: kioria
 */ 

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#define		OUTPUT						0xFF
#define		INPUT						(0x00)
//RENAMING PORT,DDR,PINS OF PORTD
#define			INTERRUPT_DDR			DDRD//ensure INT PINS DDR IS SETAS INPUT
#define			INTERRUPT_PORT			 PORTD
char 	        both_interrupts;
//rename interrupt register
#define			 interrupt_enable_reg	EIMSK//external interrupt mask register
#define			trigger_level_reg		 EICRA //external interrupt control reg
/*interrupt 0 definition*/
#define			 INTERRUPT_PIN_0								PD2
#define			 INTERRUPT_0									INT0
#define			rising_edge_0								((1<<ISC01)|(1<<ISC00))//interrupt on the rising edge
#define			falling_edge_0								((1<<ISC01)|(~(1<<ISC00)))//interrupt on the falling edge
#define			logic_change_edge_0							(~(1<<ISC01)|(1<<ISC00)//interrupt on the any logic change 
#define			low_level_edge_0							(~(1<<ISC01)|(~(1<<ISC00)))//interrupt on the low level edge
#define			enable_interrupt_0							(1<<INTERRUPT_0)//activate INT0
#define			set_internal_pullup_interrupt_pin_0			(1<<INTERRUPT_PIN_0)//enable a pull up resistor on PD2
/*end of interrupt 0 definition*/

/*start of external interrupt  1 definition*/
#define			INTERRUPT_1									INT1
#define			INTERRUPT_PIN_1								PD3
#define			rising_edge_interrupt_1						((1<<ISC11)|(1<<ISC10))//interrupt on the rising edge
#define			falling_edge_interrupt_1					((1<<ISC11)|(~(1<<ISC10)))//interrupt on the falling edge
#define			logic_change_edge_1							(~(1<<ISC11)|(1<<ISC10))//interrupt on any logic change
#define			low_level_edge_interrupt_1					(~(1<<ISC11)|(~(1<<ISC10)))//interrupt on the low level  edge


#define			enable_interrupt_1						 (1<<INTERRUPT_1)//activate INT1
#define			set_internal_pullup_interrupt_pin_1		(1<<INTERRUPT_PIN_1)//enable a pull up resistor on PD2

/*end of external interrupt  1 definition*/

#define enable_global_interrupt sei()
void interrupt_init(char interrupt_,char trigger_level);



#endif /* INTERRUPT_H_ */