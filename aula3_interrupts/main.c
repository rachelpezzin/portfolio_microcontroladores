/*
 * main.c
 *
 * Created: 3/13/2026 2:22:34 PM
 *  Author: rachel
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

ISR(INT0_vect){
	PORTC ^= (1 << PORTC0); 
	_delay_ms(100);
}

int main(void){

	
	DDRC |= (1 << DDC0);
	EICRA = (1 << ISC01) | (1 << ISC00);
	EIMSK = (1 << INT0);
	sei();
	
	while(1)
	{
		
	}
}