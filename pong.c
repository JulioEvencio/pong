//  Bibliotecas
#include <stdio.h>
#include "pong.h"

/*  Funcoes */
/*  Verificacao de tecla */
//  Funcao que verifica se alguma tecla do teclado foi pressionada
void verificar_tecla_pressionada(void)
{
    switch(evento.key.keysym.sym)
    {
        case(SDLK_RIGHT):
            personagem.direita = 1;
            break;
        case(SDLK_LEFT):
            personagem.esquerda = 1;
            break;
    }
}

//  Funcao que verifica se alguma tecla do teclado foi solta
void verificar_tecla_solta(void)
{
    switch(evento.key.keysym.sym)
    {
        case(SDLK_ESCAPE):
            loop = 0;
            break;
        case(SDLK_RIGHT):
            personagem.direita = 0;
            break;
        case(SDLK_LEFT):
            personagem.esquerda = 0;
            break;
    }
}

/*  Funcoes do personagem */
//  Funcao que define os atributos iniciais do personagem
void definir_personagem(void)
{
    personagem.x = 350;
    personagem.y = 350;
    personagem.direita = 0;
    personagem.esquerda = 0;
    personagem.largura = 100;
    personagem.altura = 30;
    personagem.velocidade = 1;
}

//  Funcao que faz o movimento do personagem
void movimentar_personagem(void)
{
    if(personagem.direita)
    {
        personagem.x += personagem.velocidade;
    }
    if(personagem.esquerda)
    {
        personagem.x -= personagem.velocidade;
    }
}