/*
 * gpio.c
 *
 * Created: 27/02/2026 16:31:56
 *  Author: Aluno
 */ 
#include <xc.h>
#include "gpio.h"

void GPIO_initialize() {
	DDRB = (1<<DDB0);// CONFIRGURA esse pino como saida
}

void GPIO_blinkled(){
	//meche na função gpio e faz piscar um led
	PORTB = (1<<PORTB0);
}
