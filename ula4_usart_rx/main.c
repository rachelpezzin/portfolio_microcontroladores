/*
 * main.c
 *
 * Created: 3/27/2026 3:54:15 PM
 *  Author: rachel
 */ 

#include <xc.h>

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
		while(UCSR0A & (1<<RXC0) ==0);
		uint8_t tReceivedByte = UDR0;
		if (tReceivedByte == 200){
			PORTB |= (1<<PORTB0);
			}else{
			PORTB=0;	
		}
    }
}