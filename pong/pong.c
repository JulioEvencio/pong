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
            personagem.direita = VERDADEIRO;
            break;
        case(SDLK_LEFT):
            personagem.esquerda = VERDADEIRO;
            break;
    }
}

//  Funcao que verifica se alguma tecla do teclado foi solta
void verificar_tecla_solta(void)
{
    switch(evento.key.keysym.sym)
    {
        case(SDLK_ESCAPE):
            loop = FALSO;
            break;
        case(SDLK_RIGHT):
            personagem.direita = FALSO;
            break;
        case(SDLK_LEFT):
            personagem.esquerda = FALSO;
            break;
    }
}

/*  Funcoes do personagem */
//  Funcao que reseta os atributos iniciais do personagem
void resetar_personagem(void)
{
    personagem.x = PERSONAGEM_X;
    personagem.y = PERSONAGEM_Y;
    personagem.direita = PERSONAGEM_DIREITA;
    personagem.esquerda = PERSONAGEM_ESQUERDA;
    personagem.largura = PERSONAGEM_LARGURA;
    personagem.altura = PERSONAGEM_ALTURA;
    personagem.velocidade = PERSONAGEM_VELOCIDADE;
}

//  Funcao que faz o movimento do personagem
void movimentar_personagem(void)
{
    if(personagem.direita && (personagem.x + personagem.largura) < JANELA_LARGURA)
    {
        personagem.x += personagem.velocidade;
    }
    if(personagem.esquerda && personagem.x > (JANELA_LARGURA - JANELA_LARGURA))
    {
        personagem.x -= personagem.velocidade;
    }
}

/*  Funcoes do inimigo */
//  Funcao que reseta os atributos iniciais do inimigo
void resetar_inimigo(void)
{
    inimigo.x = INIMIGO_X;
    inimigo.y = INIMIGO_Y;
    inimigo.largura = INIMIGO_LARGURA;
    inimigo.altura = INIMIGO_ALTURA;
    inimigo.velocidade_x = INIMIGO_VELOCIDADE_X;
    inimigo.velocidade_y = INIMIGO_VELOCIDADE_Y;
}

//  Funcao que faz o movimento do inimigo
void movimentar_inimigo(void)
{
    inimigo.x += inimigo.velocidade_x;
    inimigo.y += inimigo.velocidade_y;
    if(inimigo.x < (JANELA_LARGURA - JANELA_LARGURA) || (inimigo.x + inimigo.largura) > JANELA_LARGURA)
    {
        inimigo.velocidade_x = -inimigo.velocidade_x;
    }
    if(inimigo.y < (JANELA_ALTURA - JANELA_ALTURA) || (inimigo.y + inimigo.altura) > JANELA_ALTURA)
    {
        inimigo.velocidade_y = -inimigo.velocidade_y;
    }
    //  Verificando se o inimigo colidiu com o personagem
    if(verificar_colisao(personagem.x, personagem.y, personagem.largura, personagem.altura))
    {
        inimigo.velocidade_y = -inimigo.velocidade_y;
    }
}

/*  Funcoes do jogo */
//  Funcao que verifica se o inimigo colidiu com algo
int verificar_colisao(int x, int y, int largura, int altura)
{
    if((inimigo.y + inimigo.altura) < y)
    {
        return FALSO;
    }
    if(inimigo.y > (y + altura))
    {
        return FALSO;
    }
    if((inimigo.x + inimigo.largura) < x)
    {
        return FALSO;
    }
    if(inimigo.x > (x + largura))
    {
        return FALSO;
    }
    return VERDADEIRO;
}