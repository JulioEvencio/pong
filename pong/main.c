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

//  Funcoes
void logica(void);
void grafico(void);

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
    //  Code
}

void grafico(void)
{
    //  Limpando a tela de preto
    SDL_RenderClear(tela);

    //  Atualizando tela
    SDL_RenderPresent(tela);
}
