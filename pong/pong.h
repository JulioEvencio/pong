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
#define JOGO_DELAY 10
//  Personagem
#define PERSONAGEM_X 350
#define PERSONAGEM_Y 350
#define PERSONAGEM_DIREITA 0
#define PERSONAGEM_ESQUERDA 0
#define PERSONAGEM_LARGURA 100
#define PERSONAGEM_ALTURA 30
#define PERSONAGEM_VELOCIDADE 8

/*  Variaveis */
int loop = 1;

/*  Structs */
//  Personagem
struct tipo_personagem
{
    SDL_Rect retangulo;
    int x;
    int y;
    int direita;
    int esquerda;
    int largura;
    int altura;
    int velocidade;
};
typedef struct tipo_personagem Personagem;
Personagem personagem;
//  Inimigo
struct tipo_inimigo
{
    SDL_Rect retangulo;
    int x;
    int y;
    int largura;
    int altura;
    int velocidade;
};

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
//  Funcoes do personagem
void resetar_personagem(void);
void movimentar_personagem(void);

#endif // PONG_H_INCLUDED