/*
    Pong
*/

//  Bibliotecas
#include <stdio.h>
#include "sdl2/sdl2.h"
#include "sdl2/sdl2.c"
#include "pong.h"
#include "pong.c"

int main(int argc, char *args[])
{
    //  Iniciando SDl, IMG e TTF
    sdl2_iniciar_SDL2();

    //  Criando janela e tela
    janela = sdl2_criar_janela(JANELA_NOME, JANELA_LARGURA, JANELA_ALTURA);
    tela = sdl2_criar_tela(janela);

    //  Loop do jogo
    while(loop)
    {
        //  Verificando se algum evento ocorreu
        while(SDL_PollEvent(&evento) != 0)
        {
            /*  Verificando qual evento ocorreu */
            //  Usuario clicou no X da janela
            if(evento.type == SDL_QUIT)
            {
                loop = 0;
            }
        }

        /*  Logica */

        /*  Graficos */
        //  Definindo cor da tela
        sdl2_definir_cor_tela(tela, JANELA_COR);

        //  Atualizando tela
        sdl2_atualizar_tela(tela);

        /*  Delay */
        SDL_Delay(JOGO_DELAY);
    }

    /*  Finalizando programa */
    //  Fechando tela e janela
    sdl2_fechar_tela(tela);
    sdl2_fechar_janela(janela);
    //  Finalizando SDl, IMG e TTF
    sdl2_finalizar_SDL2();

    return 0;
}