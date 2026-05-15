/*
 * main.c
 *
 * Created: 5/15/2026 4:12:00 PM
 *  Author: RACHEL
 */ 

#define F_CPU 8000000
#include <xc.h>
#include "util/delay.h"


uint8_t gPWM = 0;


int main(void){
	DDRB = (1<<DDB0);
	DDRD = (1<<DDD5)|(1<<DDD6);
	
	TCCR0A = (0<<WGM00)|(1<<WGM01)|(0<<COM0A0)|(1<<COM0A1)|(0<<COM0B0)|(1<<COM0B1); 
	TCCR0B = (0<<WGM02)|(0<<CS02)|(1<<CS01)|(0<<CS00); 
	
	OCR0A = 99; 


	while(1){	
		gPWM ++;
		if(gPWM >99) gPWM = 0;
		OCR0B = gPWM;
		_delay_ms(100);

	}
}