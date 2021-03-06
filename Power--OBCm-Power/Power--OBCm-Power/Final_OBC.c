/*
 * Final_OBC.c
 *
 * Created: 11/4/2017 7:25:55 PM
 * Author : zeus
 */ 

#include <avr/io.h>
#include "avr/interrupt.h"
#include "TWI_Master.h"
#include "common.h"
#include "uart.h"


int main(void)
{
	sei();
	unsigned char HM_data[7];	
	//unsigned char msg_buf[8];
	unsigned char SLA=0x20;
	
	HM_data[0]=SLA+0x00;
	HM_data[1]=0x31;
	HM_data[2]=0x32;
	HM_data[3]=0x33;
	HM_data[4]=0x34;
	HM_data[5]=0x35;
	HM_data[6]=0x36;
	HM_data[7]=0x37;
	
	TWI_Master_Initialise();
	init_UART0();
	
    while (1) 
    {
		//msg_buf[0]=SLA+0x01;
		//TWI_Start_Transceiver_With_Data(msg_buf,8);
		//TWI_Start_Transceiver();
		TWI_Start_Transceiver_With_Data(HM_data,8);
		//unsigned char z = TWI_Get_Data_From_Transceiver(msg_buf , 8);
		_delay_ms(100);
		/*transmit_UART0('a');
		transmit_UART0(msg_buf[1]);
		transmit_UART0(msg_buf[2]);
		transmit_UART0(msg_buf[3]);
		transmit_UART0(msg_buf[4]);
		transmit_UART0(msg_buf[5]);
		transmit_UART0(msg_buf[6]);
		transmit_UART0(msg_buf[7]);*/
    }
}

