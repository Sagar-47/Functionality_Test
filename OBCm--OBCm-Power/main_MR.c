/*
 * OBCm--OBCm-Power.c
 *
 * Created: 12-10-2017 21:45:03
 * Author : ZEUS
 */ 

#define F_CPU 8000000
#include <avr/io.h>
#include "common.h"
#include "timer.h"
#include "uart.h"
#include "spi.h"
#include "i2c.h"
#include "led_tests.h"


int main(void)
{
	// Initializations 
	init_UART0();
	TWI_init_master();
	// Variables 
	
	
	//sei();
	
    while (1) 
    {
		// Loop 
		uint8_t recv_data;
		transmit_UART0('1');
		//uint8_t data= 'a';
		TWI_start();
		transmit_UART0('2');
		TWI_read_address(0x21);
		transmit_UART0('3');
		recv_data = TWI_read_data();
		transmit_UART0('4');
		_delay_ms(100);
		TWI_stop();
		transmit_UART0(recv_data);
    }
}

