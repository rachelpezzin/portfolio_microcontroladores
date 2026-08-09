# Portfólio de Microcontroladores 💻🔋

## Descrição
Este repositório contém os exercícios práticos e projetos desenvolvidos em sala de aula para a disciplina de Microcontroladores do curso de Engenharia de Controle e Automação. O foco principal é a programação de baixo nível (Bare-Metal) em linguagem C, garantindo o controle direto sobre o hardware e a compreensãoda arquitetura do sistema.

## Arquitetura e Hardware
* **Microcontrolador:** ATmega328P
* **Linguagem:** C (Bare-Metal)

## Tópicos Abordados e Habilidades
Ao longo dos exercícios, foram implementados códigos envolvendo:
* **Controle de I/O Digital:** Configuração e leitura de pinos utilizando os registradores `DDR`, `PORT` e `PIN`.
* **Manipulação de Bits (Bitwise):** Setar, limpar, alternar e ler bits específicos em registradores para um controle otimizado e seguro dos periféricos.
* **Comunicação Serial:** Implementação e configuração de comunicação via protocolo `UART/USART` para envio e recebimento de dados.
* **Interrupções e Timers:** Configuração de temporizadores internos e tratamento de interrupções de hardware para eventos de tempo real.

## Estrutura do Repositório
Cada pasta neste repositório corresponde a um exercício ou laboratório específico realizado em aula, contendo o código fonte `.c` e as configurações necessárias para a simulação.

## Como Compilar
Os códigos presentes neste repositório foram escritos para a arquitetura AVR e podem ser compilados utilizando o MicrochipStudio e gravados via avrdude`
