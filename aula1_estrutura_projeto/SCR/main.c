/*
 * main.c
 *
 * Created: 2/27/2026 4:27:33 PM
 *  Author: Aluno
 */ 

#include <xc.h>
#include "gpio.h"
#include "usart.h"

int main(void)
{
	GPIO_initialize();
	USART_initialize();
	while(1){
		GPIO_blinkled();
		USART_send();
	}
}