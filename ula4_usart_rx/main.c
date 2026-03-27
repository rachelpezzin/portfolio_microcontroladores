/*
 * main.c
 *
 * Created: 3/27/2026 3:54:15 PM
 *  Author: rachel
 */

#define F_CPU 16000000	
#include <xc.h>
#include "util/delay.h"

uint8_t gReceivedByte[4];

void UART_receiveMessage (uint8_t *pBuffer, int pSize){
	uint8_t * tBuffePtr = pBuffer;
	for(int i=0; i<pSize; i++){
		while(UCSR0A & (1<<RXC0) ==0);
		uint8_t tReceivedByte = UDR0;
		*tBuffePtr = tReceivedByte;
		tBuffePtr++;
	}
}

void UART_parseMessage(uint8_t *pMessage){
	uint8_t tCheckSum = 0;
	for(int i=0; i<3; i++){
	tCheckSum += pMessage[i];	
	}
	if(pMessage[3] == tCheckSum){
		PORTB = (1<<PORTB0);
		}else{
			PORTB = (1<<PORTB2);
		}
}

int main(void){
	
		DDRB = (1<<DDB0);
		UBRR0 = 103;
		UCSR0A = (0<<U2X0);
		UCSR0B = (1<<RXEN0)|(0<<UCSZ02);
		UCSR0C = (0<<UMSEL00)| (0<<UMSEL01)
		| (1<<UPM01)| (0<<UPM00)
		| (0<<USBS0)
		| (1<<UCSZ01) |(1<<UCSZ00);
		
    while(1){
			PORTB=0;
			UART_receiveMessage(gReceivedByte, 4);
			UART_parseMessage(gReceivedByte);
			_delay_ms(1);	

    }
}