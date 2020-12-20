#ifndef PONG_H_INCLUDED
#define PONG_H_INCLUDED

//  Bibliotecas
#include "sdl2/sdl2.h"

/*  Constantes */
//  Janela
#define JANELA_NOME "Pong"
#define JANELA_LARGURA 600
#define JANELA_ALTURA 400
#define JANELA_COR 255,255,255
//  Jogo
#define JOGO_DELAY 1000/60

/*  Variaveis */
int loop = 1;

/*  Structs */
//  Personagem
struct tipo_personagem
{
    SDL_Rect personagem;
    int x;
    int y;
    int velocidade;
};
typedef struct tipo_personagem Personagem;
Personagem personagem;

/*  Variaveis SDL */
//  Janela e tela
SDL_Window *janela = NULL;
SDL_Renderer *tela = NULL;
//  Evento
SDL_Event evento;

/*  Funcoes */
//  Verificacao de tecla
void verificar_tecla_pressionada(void);
void verificar_tecla_solta(void);

#endif // PONG_H_INCLUDED