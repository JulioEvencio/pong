//  Bibliotecas
#include <stdio.h>
#include "pong.h"

/*  Funcoes */
/*  Verificacao de tecla */
//  Funcao que verifica se alguma tecla do teclado foi pressionada
void verificar_tecla_pressionada(void)
{
    //  Code
}

//  Funcao que verifica se alguma tecla do teclado foi solta
void verificar_tecla_solta(void)
{
    //  Tecla ESC
    if(evento.key.keysym.sym == SDLK_ESCAPE)
    {
        loop = 0;
    }
}

/*  Funcoes do personagem */
//  Funcao que define os atributos iniciais do personagem
void definir_personagem(Personagem *personagem)
{
    personagem->x = 350;
    personagem->y = 350;
    personagem->largura = PERSONAGEM_LARGURA;
    personagem->altura = PERSONAGEM_ALTURA;
    personagem->velocidade = PERSONAGEM_VELOCIDADE;
}