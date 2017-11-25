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
	unsigned char HM_data[7];
	unsigned char msg_buf[8];
	unsigned char SLA=0x20;
	
	HM_data[0]=0x30;
	HM_data[1]=0x31;
	HM_data[2]=0x32;
	HM_data[3]=0x33;
	HM_data[4]=0x34;
	HM_data[5]=0x35;
	HM_data[6]=0x36;
	
	/*msg_buf[0]=0x00;
	msg_buf[1]=0x00;
	msg_buf[2]=0x00;
	msg_buf[3]=0x00;
	msg_buf[4]=0x00;
	msg_buf[5]=0x00;
	msg_buf[6]=0x00;*/
		
	
	init_UART();
	TWI_Slave_Initialise(SLA);
	TWI_Start_Transceiver_With_Data(HM_data,7);
	//TWI_Start_Transceiver_With_Data(msg_buf,8);
	transmit_UART('3');
	transmit_UART('1');
    while (1) 
    {
		transmit_UART('2');
		_delay_ms(100);
		/* TWCR = (1<<TWEN)|                             // TWI Interface enabled.
		 (1<<TWIE)|(1<<TWINT)|                  // Enable TWI Interupt and clear the flag.
		 (1<<TWEA)|(0<<TWSTA)|(0<<TWSTO)|       // Prepare to ACK next time the Slave is addressed.
		 (0<<TWWC);*/
		//TWI_Start_Transceiver_With_Data(msg_buf,8);
		//transmit_UART('3');
		/*transmit_UART(TWI_buf[1]);
		transmit_UART(TWI_buf[2]);
		transmit_UART(TWI_buf[3]);
		transmit_UART(TWI_buf[4]);
		transmit_UART(TWI_buf[5]);
		transmit_UART(TWI_buf[6]);
		transmit_UART(TWI_buf[7]);*/
		//unsigned char z = TWI_Get_Data_From_Transceiver(msg_buf , 8);
		transmit_UART('3');
		//transmit_UART(z);
		/*unsigned char z = TWI_Get_Data_From_Transceiver(msg_buf , 8);
		transmit_UART(msg_buf[1]);
		transmit_UART(msg_buf[2]);
		transmit_UART(msg_buf[3]);
		transmit_UART(msg_buf[4]);
		transmit_UART(msg_buf[5]);
		transmit_UART(msg_buf[6]);
		transmit_UART(msg_buf[7]);
		_delay_ms(100);*/
	}
}

