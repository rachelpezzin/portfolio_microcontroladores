/*
 * main.c
 *
 * Created: 3/6/2026 2:36:21 PM
 * Author: rachel
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>      // Biblioteca padrao para AVR no Microchip Studio
#include <util/delay.h>

/*@brief piscar um led ligado ao pino PC2 enquanto a chave ligada ao pino PD3 estiver fechado*/

// #define BIT3_MASK 0b00001000 //byte que armazena o valor da entrada da chave PD3 

void atividade1(){
    
    DDRC |= (1<<DDC2);                                //cofigurar o pino PC2 como saida p-72 datasheet
    DDRD &= ~(1<<DDD3);                               //configura o pino PD3 como entrada
    
    while(1) {
       if((PIND & (1<<PIND3)) != 0) {                //ler o valor da entrada da chave (1 ou 0) PINO d3(PD3) (0 ou 8 por conta de estar no 4 byte(2^4)-(0b00001000) -- & = e

    //se chave aberta = nivel logico baixo se fechada = nivel ogico alto
        PORTC |= (1<<PORTC2);//acende led
        _delay_ms(300);
        PORTC &= ~(1<<PORTC2);
        _delay_ms(700);
        }else{
            PORTC &= ~(1<<PORTC2);                    //apaga led
        }
    }
}

/*@brief exemplo de controle de 6 led em formato de pinhbeiro de natal ligados a porta b (PB0 a PB5) */
void atividade2(){
    
        DDRD &= ~(1<<DDD3);                                              //configura o pino PD3 como entrada
        DDRB |= (1<<DDB5)|(1<<DDB4)|(1<<DDB3)|(1<<DDB2)|(1<<DDB1)|(1<<DDB0);    //CONFIGURAR PINOS DDB0 ATE DDB5 COMO SAIDA
        
        uint8_t tState = 1;                                                 //guarda estado de acionamento do leds

        while (1){
            if((PIND & (1<<PIND3)) != 0){
                PORTB = tState;
                _delay_ms(200);
                
                tState = tState << 1;                                        //vai alternando de 1 em 1 pra esqueda
                if(tState >= 0b01000000){
                    tState = 1;
                }                                    
            } else {
                PORTB = 0;                                                 //chave aberta
                tState = 1;
                _delay_ms(200);
            }
    }
}

int main(void) {
    atividade1();
}