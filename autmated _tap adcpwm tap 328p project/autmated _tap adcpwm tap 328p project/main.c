/*
 * automated _tap madcaps tap 328p project.c
 *
 * Created: 3/12/2022 6:00:09 PM
 * Author : kioria
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#define minimal_count 31.25
#define  battery_scale_down 0.09775
#define feedback_DIR DDRD
#define feedback_port PORTD

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
	while(ADCSRA&(1<<ADSC));//WAIT TILL CO9NVERSION IS COMPLETE
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
	DDRB=(1<<PB1);//SET OC1A AS OUTPUT
	TCCR1A=(1<<WGM11)|(1<<COM1A1);//SET A FAST PWM,TOP IN ICR1,NON-INVERTING MODE
	/*TCCR1B=(1<<WGM12)|(1<<WGM13)|(1<<CS11)|(1<<CS10);//TOP IN ICR1,CLK/64*/
	TCCR1B=(1<<WGM12)|(1<<WGM13)|(1<<CS10);//TOP IN ICR1,no prescaling 
	//CALCULATING FPWM---PWM REQUENCY fOCnxPFCPWM
	//FPWM=F(OSC)/(N*(1+TOP)).WHERE N PRESCALER DIVIDER=16000000/(64*(1+)
	//TOP=39999..PS1--319999 PS64-4999 PS256-1249
	/*TCNT1=4499;*/
	/*TCNT1=0;*/
	
	ICR1=20000;
	//TIMER 1 CLKFRE=16000000/64=250000 THEREORE 0.000004 I CYCLE 
	//MIN ON TIME 0.001/0.000004=250

}

int main(void)
{
	/*pwm_init();*/
	feedback_DIR=(1<<PD0)|(1<<PD1);//MAKE PD1 AND PD2 AS OUPUT
	pwm_init_tmr1();
	adc_init();
    /* Replace with your application code */
	 //OCR1A=1999;//-90 degrees position
    while (1) 
    {
		/*int pwm_value=(adc_read(0)*0.25);*/
		//OCR0A=pwm_value;
// 		int batt_level =(adc_read(0)*battery_scale_down);
// 		if (batt_level<=20){
// 		feedback_port=0x01;
// 	}
// 		else if((batt_level>=80)){
// 		feedback_port=0x02;
// 	}else{
// 		feedback_port=0x00;
// 	}
// 	OCR1A-=55;
// 	_delay_ms(2000);
// 	OCR1A+=55;
// 	_delay_ms(2000);
		
// 		OCR0A=0;
// 		_delay_ms(100);
/*TCNT1=(ICR1-500);//-90 DEGREE REFERENCE POSITIOM*/
// OCR1A=999;//-90 degrees position
// _delay_ms(5000);
// OCR1A=1499;//0 degrees position
// _delay_ms(5000);
// OCR1A-=499;//90 degrees position
// _delay_ms(5000);


/* _delay_ms(300);*/
 
// OCR1A=375;
// _delay_ms(500);
// OCR1A=500;
// _delay_ms(500);
	
		int servo_control=(adc_read(0)*3.5);
		OCR1A=servo_control;
		_delay_ms(30);
    }
}

