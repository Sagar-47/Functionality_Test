/*
 * Power--OBCm-Power.c
 *
 * Created: 12-10-2017 21:46:08
 * Author : ZEUS
 */ 

#define F_CPU 8000000
#include <avr/io.h>
#include "common.h"
#include "uart.h"
#include "i2c.h"


int main(void)
{
    // Initializations
    init_UART();
	TWI_init_slave();
    // Variables
    
    //sei();
		
    while (1) 
    {
		unsigned char data = 'd';
		TWI__slave_read_address(0x21);
		transmit_UART('1');
		TWI_write_data(data);
		transmit_UART('2');
		_delay_ms(100);		
    }
}

