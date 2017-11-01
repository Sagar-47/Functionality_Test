/*
 * Power--OBCm-Power.c
 *
 * Created: 30-10-2017 20:46:08
 * Author : ZEUS
 */ 

//#define F_CPU 8000000
//#include <avr/io.h>
#include "common.h"
#include "uart.h"
#include "i2c.h"
uint8_t data;

ISR(TWI_vect){
	//TWCR|= (1<<TWINT)|(1<<TWEA);//|(1<<TWEN);//|(1<<TWIE);
	unsigned char data_1 = 'd';
	transmit_UART(TWSR);
	switch(TWSR){
		case 0x60://it is being addressed
		TWCR|= (1<<TWINT)|(1<<TWEA);	//sending ack
		break;
		
		case 0x80://checking whether ack has been sent
		data=TWDR;
		transmit_UART(data);
		//TWCR|= (1<<TWINT)|(1<<TWEA);//|(1<<TWEN);//|(1<<TWIE);
		TWCR|= (1<<TWINT)|(1<<TWEA);
		break;
		
		case 0xA8://Slave is being addressed
		//transmit_UART('a');
		TWCR|=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);	
		/*unsigned char data_1 = 'd'; 
		TWI_write_data('d')//*/
		break;
		
		case 0xC0://Data being sent 
		//transmit_UART('b');
		TWDR='d'; 
		TWCR=(1<<TWINT)|(1<<TWEN);	//sending ack
		break;
		/*case 0xA0:
		TWCR|= (1<<TWINT)|(1<<TWEA)|(1<<TWEN)|(1<<TWIE);    //sei();
		break;*/
		/*
		default:
		transmit_UART('f');
		TWCR|= (1<<TWINT)|(1<<TWEA)|(1<<TWEN)|(1<<TWIE)|(0<<TWSTA)|(0<<TWSTO);
		break;*/
		
	}
	TWCR = (1<<TWINT)|(1<<TWEA)|(1<<TWEN)|(1<<TWIE);
}

 
int main(void)
{
    // Initializations
    init_UART();
	TWI_init_slave();
	//_delay_ms(2000);
	sei();
	TWCR = (1<<TWEN)|                             // TWI Interface enabled.
	(1<<TWIE)|(1<<TWINT)|                  // Enable TWI Interupt and clear the flag.
	(1<<TWEA);
	  //TWCR|= (1<<TWINT)|(1<<TWEA)|(1<<TWEN)|(1<<TWIE);
	while (1){}
}

