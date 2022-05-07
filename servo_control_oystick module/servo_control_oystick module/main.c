/*
 * servo_control_oystick module.c
 *
 * Created: 4/30/2022 11:50:18 AM
 * Author : kioria
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "timer_pwm.h"//pwm header ile
#include "adc.h"//adc header ile
#define min_pulse 250
#define scal_down  4.887
//interrupt config
void interruptConfig(void){
	DDRD=1<<PD3;
	PORTD=1<<PD3;//ENABLE THE INTERNAL PULLUP RESISTOR
	EIMSK=1<<INT1;//enable interrupt one
	EICRA=1<<ISC11;//falling edge
	
}
//isr routine
ISR(INT1_vect){
	for(int servo=500;servo>=250;servo--){
		OCR1A=servo;
		_delay_ms(15);
	}
	for(int servo=500;servo>=250;servo--){
		OCR1B=servo;
		_delay_ms(15);
	}
	// 		for (int servo_control=min_pulse;servo_control<=500;servo_control++){
	// 		 	OCR1B=servo_control;
	// 		 	_delay_ms(15);
	// 		 	}
	
}
//functions declaration
// void adc_init(void){
// 	DDRC&=(0x00);//MAKE PC0 AS INPUT
// 	ADMUX=(1<<REFS0);//SELECT AVCC AS INPUT,RIGHT ADJUST RESULT
// 	ADCSRA=(1<<ADEN)|(1<<ADIE)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);//ENABLED ADC,ENABLE INTERRUPT,SELECTE 128 PERSCALER
// 	
// }
// //ADC RED FUNCTION
// int adc_read(int channel){
// 	ADMUX|=((0X0F&ADMUX)|channel);//ACTIVATING THE FIRST FOUR CHANNELS
// 	ADCSRA|=(1<<ADSC);
// 	while(ADCSRA&(1<<ADSC));//WAIT TILL CO9NVERSION IS COMPLETE
// 	return ADCW;
// }




int main(void)
{
	/*pwm_init();*/
	//interrupt coniguration
	
	interruptConfig();
	sei();
	pwm_init_tmr1();
	adc_init();
	
	/* Replace with your application code */
	//OCR1A=1999;//-90 degrees position
	while (1)
	{
// 		
			//int servo_control=(min_pulse+(adc_read(0)*scal_down ));
			int servo_control=((adc_read(0)*scal_down ));
					OCR1A=servo_control;
					//_delay_ms(15);
// 		 for (int servo_control=min_pulse;servo_control<=500;servo_control++){
// 		 	OCR1A=servo_control;
// 		 	_delay_ms(15);
// 			}
//  		for(int servo=500;servo>=250;servo--){
//  					OCR1A=servo;
//  				 		_delay_ms(15);
// 			 	}

// 		OCR1A=500;
// 		OCR1B=500;


	}
}
