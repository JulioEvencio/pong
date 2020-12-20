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

    //  Resetando parametros inicias do personagem antes de iniciar o jogo
    resetar_personagem();

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
            //  Verificando se o usuario apertou alguma tecla do teclado
            if(evento.type == SDL_KEYDOWN)
            {
                verificar_tecla_pressionada();
            }
            //  Verificando se o usuario soltou alguma tecla do teclado
            if(evento.type == SDL_KEYUP)
            {
                verificar_tecla_solta();
            }
        }

        /*  Logica */
        //  Movimentando o personagem
        movimentar_personagem();

        /*  Graficos */
        //  Definindo cor da tela
        sdl2_definir_cor_tela(tela, JANELA_COR);

        //  Desenhando um retangulo que representa o personagem
        sdl2_desenhar_retangulo(tela, personagem.retangulo, personagem.x, personagem.y, personagem.largura, personagem.altura, AZUL);

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