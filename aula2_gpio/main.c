/*
 * main.c
 *
 * Created: 3/6/2026 2:36:21 PM
 *  Author: rachel
 */ 

#define F_CPU 16000000
#include <xc.h>
#include "util/delay.h"

/*o que esse código faz?
piscar um led ligado ao pino PC2 enquanto a chave ligada ao pino PD3 estiver fechado*/

// #define BIT3_MASK 0b00001000 //byte que armazena o valor da entrada da chave PD3 

int main(void) {

	DDRC |= (1<<DDC2);	//cofigurar o pino PC2 como saida p-72 datasheet
	DDRD &=(1<<DDD3);   //configura o pino PD3 como entrada
    while(1) {
       if((PIND & (1<<PIND3)) !=0) {//ler o valor da entrada da chave (1 ou 0) PINO d3(PD3) (0 ou 8 por conta de estar no 4° byte(2^4)-(0b00001000) -- & = e
	   //chave pressionada?
	   //se chave aberta = nivel logico baixo se fechada = nivel ogico alto
	   PORTC |= (1<<PORTC2);//acende led
	   _delay_ms(300);
	   PORTC &= ~(1<<PORTC2);
	   _delay_ms(700);
		}else{
			PORTC &= ~(1<<PORTC2);//apaga led
		}
    }
}