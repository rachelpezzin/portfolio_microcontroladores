/*
 * main.c
 *
 * Created: 5/8/2026 3:57:33 PM
 *  Author: Rachel
 */ 

#define F_CPU 16000000
#include <xc.h>
#include "util/delay.h"

void TWI_master_config(){
	//DDRC = (1<<DDC4)|(1<<DDC5);
	TWBR = 12; //bit rate 400khz (p.150)
	TWSR = ((0<<TWPS1)|(0<<TWPS0)); // prescaler = 1
	TWCR= (1<<TWEN);
}

void TWI_master_write(uint8_t pAdress, uint8_t pData){
	TWCR|=(1<<TWSTA)|(1<<TWINT)|(1<<TWEN);//enviar condição de start
		while ((TWCR &(1<<TWINT))==0);// espera conclusao
			//TWCR |= (1<<TWINT);//limpa flag de interrupção
			
		TWDR =  (pAdress <<1)| 0 ;//1=Read e 0 =write
		TWCR = (1<<TWINT)|(1<<TWEN);//limpa flag de interrupção
		
		while ((TWCR &(1<<TWINT))==0);// espera conclusao
			

	uint8_t tState = TWSR & 0b11111000;
	
	switch(tState){
		case 0x18: break;//ack recebido
		case 0x20: break; // anenhum ack recebido
		default: break;
	}
	TWCR = (1<<TWEN)|(1<<TWINT)|(1<<TWSTO);
}

int main(void){
	TWI_master_config();
	_delay_ms(1000);
    while(1){
        TWI_master_write(55, 'a');
		_delay_ms(1000) ;
    }
}