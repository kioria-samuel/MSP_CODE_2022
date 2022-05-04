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
#define min_pulse 250
#define scal_down  4.887
//interrupt config
void interruptConfig(void){
	DDRD=1<<PD3;
	PORTD=1<<PD3;//ENABLE THE INTERNAL PULLUP RESISTOR
	EIMSK=1<<INT1;//enable interrrrupt one
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
void adc_init()
{
	// AREF = AVcc
	ADMUX = (1<<REFS0);
	
	// ADC Enable and prescaler of 128
	// 16000000/128 = 125000
	ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}
uint16_t adc_read(uint8_t ch)
{
	// select the corresponding channel 0~7
	// ANDing with ’7? will always keep the value
	// of ‘ch’ between 0 and 7
	ch &= 0b00000111;  // AND operation with 7
	ADMUX = (ADMUX & 0xF8)|ch; // clears the bottom 3 bits before ORing
	
	// start single convertion
	// write ’1? to ADSC
	ADCSRA |= (1<<ADSC);
	
	// wait for conversion to complete
	// ADSC becomes ’0? again
	// till then, run loop continuously
	while(ADCSRA & (1<<ADSC));
	
	return (ADC);
}


void pwm_init_tmr1(void){
	DDRB=(1<<PB1)|(1<<PB2);//SET OC1A OC1B AS OUTPUT
	
	TCCR1A=((1<<WGM11)|(1<<COM1A1));//SET A FAST PWM,TOP IN ICR1,NON-INVERTING MODEclear output on compare match
	/*TCCR1B=(1<<WGM12)|(1<<WGM13)|(1<<CS11)|(1<<CS10);//TOP IN ICR1,CLK/64*/
	TCCR1B=((1<<WGM12)|(1<<WGM13)|(1<<CS10)|(1<<CS11));//TOP IN ICR1,CLK/64
	//CALCULATING FPWM---PWM REQUENCY fOCnxPFCPWM
	//FPWM=F(OSC)/(N*(1+TOP)).WHERE N PRESCALER DIVIDER=16000000/(64*(1+)
	//TOP=39999..PS1--319999 PS64-4999 PS256-1249
	/*TCNT1=4499;*/
	TCNT1=0;
	
	ICR1=4999;//setting the top count
	//TIMER 1 CLKFRE=16000000/64=250000 THEREORE 0.000004 I CYCLE
	//MIN ON TIME 0.001/0.000004=250

}

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
