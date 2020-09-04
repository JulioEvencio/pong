/*
    Pong
*/

#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

//  Variaveis normais
//  Dados da janela
const int comprimento = 640;
const int altura = 480;
//  Variavel do loop do jogo
bool loop = true;

//  Dados do personagem
const int personagem_comprimento = 100;
const int personagem_altura = 30;
const int personagem_velocidade = 5;
bool personagem_movimento_direita = false;
bool personagem_movimento_esquerda = false;
int personagem_x = 50;
int personagem_y = 420;

//  Dados do alvo
const int alvo_comprimento = 30;
const int alvo_altura = 30;
int alvo_velocidade_x = 1;
int alvo_velocidade_y = 1;
int alvo_x = 50;
int alvo_y = 50;

//  Funcoes
void logica(void);
void grafico(void);
void desenhar_personagem(void);
void movimentar_personagem(void);
void verificar_qual_tecla_pressionada(void);
void verificar_qual_tecla_solta(void);
void desenhar_alvo(void);
void movimentar_alvo(void);

//  Variaveis SDL
SDL_Window *janela = NULL;
SDL_Renderer *tela = NULL;
SDL_Event evento;

int main(int argc, char *agrs[])
{
    //  Iniciando SDL
    if(SDL_Init(SDL_INIT_VIDEO))
    {
        printf("Erro ao iniciar SDL: %s \n", SDL_GetError());
        return -1;
    }

    //  Criando janela
    janela = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, comprimento, altura, 0);
    if(janela == NULL)
    {
        printf("Erro ao criar janela: %s \n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    //  Criando renderer
    tela = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(tela == NULL)
    {
        printf("Erro ao criar renderer: %s \n", SDL_GetError());
        SDL_DestroyWindow(janela);
        SDL_Quit();
        return -1;
    }

    //  Loop do jogo
    while(loop)
    {
        //  Verificando se ocorreu algum evento
        while(SDL_PollEvent(&evento) != 0)
        {
            //  Verificando qual evento ocorreu
            //  Verificnado se o usuario clicou no X da janela
            if(evento.type == SDL_QUIT)
            {
                loop = false;
            }
            //  Verificando se alguma tecla foi pressionada
            if(evento.type == SDL_KEYDOWN)
            {
                verificar_qual_tecla_pressionada();
            }
            //  Verificando se alguma tecla foi solta
            if(evento.type == SDL_KEYUP)
            {
                verificar_qual_tecla_solta();
            }
        }

        //  Logica
        logica();

        //  Grafico
        grafico();

        SDL_Delay(1000/60);
    }

    //  Encerrando SDL
    SDL_DestroyRenderer(tela);
    SDL_DestroyWindow(janela);
    SDL_Quit();

    return 0;
}

void logica(void)
{
    //  Movimento do alvo
    movimentar_alvo();

    //  Movimento do personagem
    movimentar_personagem();
}

void grafico(void)
{
    //  Definindo fundo branco para a tela
    SDL_SetRenderDrawColor(tela, 255, 255, 255, 255);
    SDL_RenderClear(tela);

    //  Desenhando alvo
    desenhar_alvo();

    //  Desenhando personagem
    desenhar_personagem();

    //  Atualizando tela
    SDL_RenderPresent(tela);
}

void desenhar_personagem(void)
{
    SDL_SetRenderDrawColor(tela, 60, 60, 60, 255);
    SDL_Rect personagem = {personagem_x, personagem_y, personagem_comprimento, personagem_altura};
    SDL_RenderFillRect(tela, &personagem);
}

void movimentar_personagem(void)
{
    if(personagem_movimento_direita)
    {
        //  Verificando se o personagem esta dentro da tela
        if(personagem_x + personagem_comprimento < comprimento)
        {
            personagem_x += personagem_velocidade;
        }
    }
    if(personagem_movimento_esquerda)
    {
        //  Verificando se o personagem esta dentro da tela
        if(personagem_x > 0 )
        {
            personagem_x -= personagem_velocidade;
        }
    }
}

void verificar_qual_tecla_pressionada(void)
{
    //  Tecla direita
    if(evento.key.keysym.sym == SDLK_RIGHT)
    {
        personagem_movimento_direita = true;
    }
    //  Tecla esquerda
    if(evento.key.keysym.sym == SDLK_LEFT)
    {
        personagem_movimento_esquerda = true;
    }
}

void verificar_qual_tecla_solta(void)
{
    //  Tecla direita
    if(evento.key.keysym.sym == SDLK_RIGHT)
    {
        personagem_movimento_direita = false;
    }
    //  Tecla esquerda
    if(evento.key.keysym.sym == SDLK_LEFT)
    {
        personagem_movimento_esquerda = false;
    }
}

void desenhar_alvo(void)
{
    SDL_SetRenderDrawColor(tela, 0, 0, 255, 255);
    SDL_Rect alvo = {alvo_x, alvo_y, alvo_comprimento, alvo_altura};
    SDL_RenderFillRect(tela, &alvo);
}

void movimentar_alvo(void)
{
    alvo_x += alvo_velocidade_x;
    alvo_y += alvo_velocidade_y;

    //  Verificando se o alvo saiu do eixo x da tela
    if(alvo_x + alvo_comprimento > comprimento || alvo_x < 0)
    {
        //  Invertendo velocidade no eixo x
        alvo_velocidade_x = -alvo_velocidade_x;
    }
    //  Verificando se o alvo saiu do eixo y da tela
    if(alvo_y + alvo_altura > altura || alvo_y < 0)
    {
        //  Invertendo velocidade no eixo y
        alvo_velocidade_y = -alvo_velocidade_y;
    }
}
