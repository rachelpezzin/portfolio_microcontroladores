/*
 * main.c
 *
 * Created: 3/13/2026 2:22:34 PM
 *  Author: rachel
 */ 

#define F_CPU 16000000
#include <xc.h>
#include "avr/interrupt.h"
#include "util/delay.h"
int gLedFlag = 0;
int gPD2State = 0;
int gPD3State = 0;

ISR(INT0_vect) {
	gLedFlag = 1;
}

ISR(INT1_vect) {
	gLedFlag = 1;
}

ISR(PCINT2_vect) {
	
	if((PIND & (1<<PIND2)) != 0) {
		if(gPD2State == 0) {
			gLedFlag = 1;
		}
		gPD2State = 1;
		} else {
		gPD2State = 0;
	}
	
	if((PIND & (1<<PIND3)) != 0) {
		if(gPD3State == 0) {
			gLedFlag = 1;
		}
		gPD3State = 1;
		} else {
		gPD3State = 0;
	}
	}

void EXTINT_config() {
	EICRA = (0<<ISC01)|(1<<ISC00)	
	| (1<<ISC11)|(1<<ISC10);	
	EIMSK = (1<<INT1)|(1<<INT0);	
}
void PCINT_config() {
	PCMSK2 |= (1<<PCINT18)|(1<<PCINT19);	
	PCICR |= (1<<PCIE2);					
}
int main(void) {
	DDRC = (1<<DDC0);				
	PCINT_config(); 
	sei();
	while(1) {
		if(gLedFlag) {
			PORTC = (1<<PORTC0);
			_delay_ms(100);
			PORTC = 0;
			gLedFlag = 0;
		}
	}
}