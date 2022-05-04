/*
 * TWI_functdeclaration.h
 *
 * Created: 5/4/2022 10:16:20 PM
 *  Author: kioria
 */ 
/*header file TWI*/

#ifndef TWI_FUNCTDECLARATION_H_
#define TWI_FUNCTDECLARATION_H_
#include <avr/io.h>//include reg files of atmega 328p 
#define F_CPU 8000000UL//clock frequency
/*i2c initialization*/
void i2c_init(){//
	TWBR=0x62;//set the baud rate  needs be calculated
	TWCR=(1<<TWEN);//enable the i2c
	TWSR=0x00;//setting prescaler to 1
}
/*i2c start condition*/
void i2c_start(){
	TWCR =(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);//clear the twint flag,enabling twi,issuing start condition
	while(!(TWCR &(1<<TWINT ))) ;//wait for the start condition to be completed
}
/*i2c stop condition*/
/*i2c write command*/
void i2c_write(char x){
	TWDR=x;//moving value to i2c reg
	TWCR=(1<<TWINT)|(1<<TWEN);//enabling i2c and clearing interrupt flag
	while (!(TWCR &(1<<TWINT)));//wait till the write condition is complete
	
}
// i2c read condition
char i2c_read(){
	TWCR =(1<<TWEN)|(1<<TWINT);//enable i2c and clear the interrupt
	while (!(TWCR &(1<<TWINT)));//wait till the read condition is complete
	return TWDR;//return the result in TWDR data register
}
//end of header




#endif /* TWI_FUNCTDECLARATION_H_ */