/*
 * main.c
 *
 * Created: 3/27/2026 1:57:54 PM
 *  Author: rachel
 */ 

#define F_CPU 16000000 // define frequencia do processador

#include <xc.h>
#include "util/delay.h"

uint8_t gMessage[3] = {200, 100, 50};
	
void USART_sendMessage (uint8_t * pData, int pSize){
	uint8_t *tMsgPtr = pData;
	uint8_t tChecksum = 0;
	for(int i=0; i<pSize; i++){
		while ((UCSR0A &(1<<UDRE0)) == 0);
		uint8_t tMessageByte = *tMsgPtr;
		tChecksum += tMessageByte;
		UDR0 = tMessageByte;
		UDR0 = *tMsgPtr++;
	}
	while ((UCSR0A &(1<<UDRE0)) == 0);
	UDR0 = tChecksum;
}


int main(void){
	
	UBRR0 = 103;
	UCSR0A = (0<<U2X0);
	UCSR0B = (1<<TXEN0)|(0<<UCSZ02);
	UCSR0C = (0<<UMSEL00)| (0<<UMSEL01)
			| (1<<UPM01)| (0<<UPM00)
			| (0<<USBS0)
			| (1<<UCSZ01) |(1<<UCSZ00);
    while(1) {
		USART_sendMessage (gMessage, 3);
		_delay_ms (10);
     
    }
}