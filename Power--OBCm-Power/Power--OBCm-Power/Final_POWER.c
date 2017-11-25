/*
 * Final_Power.c
 *
 * Created: 11/4/2017 7:22:58 PM
 * Author : zeus
 */ 

#include <avr/io.h>
#include "avr/interrupt.h"
#include "TWI_slave.h"
#include "common.h"
#include "uart.h"


int main(void)
{
    sei();
	unsigned char msg_buf[8];
	unsigned char SLA=0x20;
	
		
	
	init_UART();
	TWI_Slave_Initialise(SLA);
	TWI_Start_Transceiver_With_Data(msg_buf,8);
    while (1) 
    {
		unsigned char z = TWI_Get_Data_From_Transceiver(msg_buf , 8);
		transmit_UART(msg_buf[0]);
		transmit_UART(msg_buf[1]);
		transmit_UART(msg_buf[2]);
		transmit_UART(msg_buf[3]);
		transmit_UART(msg_buf[4]);
		transmit_UART(msg_buf[5]);
		transmit_UART(msg_buf[6]);
		_delay_ms(100);
	}
}

