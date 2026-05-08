/*
 * main.c
 *
 * Created: 5/8/2026 5:09:32 PM
 *  Author: rachel
 */ 

#define F_CPU 16000000
#include <xc.h>
#include "avr/interrupt.h"
#include "util/delay.h"

uint8_t gTWIData = 5;

ISR(TWI_vect){
	uint8_t tState = (TWSR & 0b11111000);
	switch(tState){
		case 0x60: {
			gTWIData = TWDR;
			TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
		}break;
		case 0xA8: {
			TWDR = gTWIData ;
			TWCR = (1<<TWINT)|(1<<TWEN);
		}break;
		default:{
				TWCR = (1<<TWINT)|(1<<TWEN);
		}break;
	}
}

void TWI_slave_config(){
	TWBR = 12; //bit rate 400khz (p.150)
	TWSR = ((0<<TWPS1)|(0<<TWPS0)); // prescaler = 1
	TWAR = (0x55<<1);
	TWCR= (1<<TWEN)|(1<<TWIE);
	sei();
}

int main(void){
	TWI_slave_config();
	while(1){
		
	}
}