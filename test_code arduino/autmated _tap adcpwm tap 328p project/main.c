/*
 * automated _tap madcaps tap 328p project.c
 *
 * Created: 3/12/2022 6:00:09 PM
 * Author : kioria
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define min_pulse 250

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
void adc_init(void){
	DDRC&=(0x00);//MAKE PC0 AS INPUT
	ADMUX=(1<<REFS0);//SELECT AVCC AS INPUT,RIGHT ADJUST RESULT
	ADCSRA=(1<<ADEN)|(1<<ADIE)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);//ENABLED ADC,ENABLE INTERRUPT,SELECTE 128 PERSCALER
	
}
//ADC RED FUNCTION
int adc_read(int channel){
	ADMUX|=((0X0F&ADMUX)|channel);//ACTIVATING THE FIRST FOUR CHANNELS
	ADCSRA|=(1<<ADSC);
	while(ADCSRA&(1<<ADIF));//WAIT TILL CO9NVERSION IS COMPLETE
	return ADCW;
}
//PWM INITILAIZE TIMER O
// void pwm_init(void){
// 	DDRD=1<<PD6;//make ocoa as output
// 	TCCR0A=(1<<WGM00)|(1<<WGM10)|(1<<COM0A1);//enable fast pwm,non-inerting mode
// 	TCCR0B=(1<<CS00);//no prescling
// 	
// }
//PWM INITILAIZE TIMER 1 16 BIT TIMER 
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
			
// 		int servo_control=(adc_read(0)*3.5);
// 		OCR1A=servo_control;
// for (int servo_control=min_pulse;servo_control<=500;servo_control++){
// 	OCR1A=servo_control;
// 	_delay_ms(15);
// 	}
// for(int servo=500;servo>=250;servo--){
// 		OCR1A=servo;
// 		_delay_ms(15);
// 	}

OCR1A=500;
OCR1B=500;


    }
}

