/*
 * main.c
 *
 * Created: 5/15/2026 2:49:48 PM
 *  Author: Rachel
 */ 

#define F_CPU 8000000
#include <xc.h>
#include "avr/interrupt.h"

ISR(TIMER0_OVF_vect){
	PORTB ^= (1<<PORTB0); //alterna PB0
}

int main(void){
	DDRB = (1<<DDB0);
	TCCR0A = (0<<WGM00)|(1<<WGM01); //MODO CTC
	TCCR0B = (0<<WGM02)|(0<<CS02)|(1<<CS01)|(0<<CS00); // prescaler de 8
	OCR0A = 249; //contagem ate 250us (considerando clk do timer = 1MHz
	
	TIMSK0 = (1<<TOIE0); //habilita interrupção de overflow  do timer 0
	sei();
    while(1){
        
    }
}