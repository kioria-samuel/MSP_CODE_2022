/*
 * uart.h
 *
 * Created: 6/18/2022 4:57:43 PM
 *  Author: BINDER TRONICS
 */ 


#ifndef UART_H_
#define UART_H_
#define  F_CPU 16000000UL
#include <avr/io.h>//include avr input/output files
#include <avr/interrupt.h>//include avr interrupt  header file
#include <util/delay.h>
#include <stdint.h>//include standard int header
#define RX_BUFFER_SIZE 128

void uart_init(uint32_t baud,uint8_t high_speed);
void uart_send_byte(uint8_t c);
void uart_send_array(uint8_t *c,uint16_t len);
void uart_send_string(uint8_t *c);
uint16_t uart_read_count(void);
uint8_t uart_read(void);





#endif /* UART_H_ */