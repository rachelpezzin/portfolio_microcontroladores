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

int gCount = 0;

ISR(INT0_vect){
	PORTC ^= (1 << PORTC0); 
	_delay_ms(100);
	PORTC = 0;
}

ISR(INT1_vect){
	gCount++;
	PORTC ^= (1 << PORTC0);
	_delay_ms(100);
	PORTC = 0;
	gCount = 0;
}

int main(void){

	
	DDRC |= (1 << DDC0);
	EICRA = (0 << ISC01) | (1 << ISC00) | (1<<ISC11) | (1<<ISC11);
	EIMSK = (1 << INT1)|(1<<INT0);
	sei();
	
	while(1)
	{
		
	}
}