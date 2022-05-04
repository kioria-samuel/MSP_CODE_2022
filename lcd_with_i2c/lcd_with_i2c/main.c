/*
 * lcd_with_i2c.c
 *
 * Created: 4/29/2022 9:32:47 PM
 * Author : kioria
 */ 

#include <avr/io.h>
#include "i2c.h"
#include "LCD_I2C.h"
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	i2c_init();
	i2c_start();
	i2c_write(0x70);
	lcd_init();//lcd initialize
    while (1) 
    {
		lcd_cmd(0x80);
		lcd_msg("exodus");
		lcd_cmd(0xc3);
		lcd_msg("i2c");
    }
}

