#ifndef PONG_H_INCLUDED
#define PONG_H_INCLUDED

//  Bibliotecas
#include "sdl2/sdl2.h"

/*  Constantes */
//  Janela
#define JANELA_NOME "Pong"
#define JANELA_LARGURA 600
#define JANELA_ALTURA 400
#define JANELA_COR SDL2_CIANO
//  Jogo
#define JOGO_DELAY 10
#define JOGO_FONTE "lazy.ttf"
#define JOGO_FONTE_TAMANHO 20
#define VERDADEIRO 1
#define FALSO 0
//  Texto
#define TEXTO_VITORIA "Vitoria!!!!"
#define TEXTO_VITORIA_X 150
#define TEXTO_VITORIA_Y 150
#define TEXTO_VITORIA_LARGURA 300
#define TEXTO_VITORIA_ALTURA 100
//  Personagem
#define PERSONAGEM_X 300
#define PERSONAGEM_Y 350
#define PERSONAGEM_DIREITA 0
#define PERSONAGEM_ESQUERDA 0
#define PERSONAGEM_LARGURA 100
#define PERSONAGEM_ALTURA 30
#define PERSONAGEM_VELOCIDADE 8
#define PERSONAGEM_COR SDL2_MAGENTA
//  Inimigo
#define INIMIGO_X rand() % (JANELA_LARGURA - INIMIGO_LARGURA)
#define INIMIGO_Y 200
#define INIMIGO_LARGURA 30
#define INIMIGO_ALTURA 30
#define INIMIGO_VELOCIDADE_X 2
#define INIMIGO_VELOCIDADE_Y 2
#define INIMIGO_COR SDL2_VERDE
//  Bloco
#define BLOCO_NUMERO 18
#define BLOCO_X 4
#define BLOCO_Y 10
#define BLOCO_LARGURA 60
#define BLOCO_ALTURA 20
#define BLOCO_DISTANCIA_X 66
#define BLOCO_DISTANCIA_Y 23
#define BLOCO_DISTANCIA_LIMITE 560
#define BLOCO_COR SDL2_MARROM

/*  Variaveis */
int loop = VERDADEIRO;

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
    int vitoria;
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
    int velocidade_x;
    int velocidade_y;
};
typedef struct tipo_inimigo Inimigo;
Inimigo inimigo;
//  Blocos
struct tipo_bloco
{
    SDL_Rect retangulo;
    int x;
    int y;
    int largura;
    int altura;
    int vida;
};
typedef struct tipo_bloco Bloco;
Bloco bloco[BLOCO_NUMERO];

/*  Variaveis SDL */
//  Janela e tela
SDL_Window *janela = NULL;
SDL_Renderer *tela = NULL;
//  Fonte
TTF_Font *fonte = NULL;
//  Evento
SDL_Event evento;

/*  Funcoes */
//  Verificacao de tecla
void verificar_tecla_pressionada(void);
void verificar_tecla_solta(void);

//  Funcoes do personagem
void resetar_personagem(void);
void movimentar_personagem(void);

//  Funcoes do inimigo
void resetar_inimigo(void);
void movimentar_inimigo(void);
int verificar_colisao(int x, int y, int largura, int altura);

//  Funcoes do bloco
void resetar_bloco(void);

//  Funcoes do jogo
void verificar_fim_jogo(void);

#endif // PONG_H_INCLUDED