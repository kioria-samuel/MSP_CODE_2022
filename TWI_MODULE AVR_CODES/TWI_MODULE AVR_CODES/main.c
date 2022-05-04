/*
 * TWI_MODULE AVR_CODES.c
 *
 * Created: 5/4/2022 10:14:03 PM
 * Author : user
 */ 

#include <avr/io.h>
#include "TWI_functdeclaration.h"
#include <util/delay.h>
#define  i2c_expander DDRB
#define  i2c_expander_port PORTB
int main(void)
{
i2c_expander=0XFF;//this port will be connected to the i2c port expander
i2c_init;//i2c initialization
// i2c_start();//
// i2c_write(0x40);//write slave address
    /* Replace with your application code */
    while (1) 
    {
// 		i2c_write(0xFF);//data to io pin
// 		_delay_ms(1000);//i sec delay
// 		i2c_write(0xAA);//data to io pin
// 		_delay_ms(1000);//1 sec delay
		i2c_start();//
		i2c_write(0x41);//read f slave address
		i2c_expander_port=i2c_read();
    }
}

