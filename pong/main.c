/*
    Pong
*/

//  Bibliotecas
#include <stdio.h>
#include <time.h>
#include "sdl2/sdl2.h"
#include "sdl2/sdl2.c"
#include "pong.h"
#include "pong.c"

int main(int argc, char *args[])
{
    //  Definindo semente para funcao rand
    srand(time(NULL));
    
    //  Iniciando SDl, IMG e TTF
    sdl2_iniciar_SDL2();

    //  Criando janela
    janela = sdl2_criar_janela(JANELA_NOME, JANELA_LARGURA, JANELA_ALTURA);

    //  Criando tela
    tela = sdl2_criar_tela(janela);

    //  Resetando parametros inicias do inimigo
    resetar_inimigo();
    
    //  Resetando parametros inicias do personagem
    resetar_personagem();

    //  Resetando parametros inicias dos blocos
    resetar_bloco();

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
                loop = FALSO;
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
        //  Movimentando o inimigo
        movimentar_inimigo();

        //  Movimentando o personagem
        movimentar_personagem();

        //  Verificando se o usuario perdeu
        verificar_fim_jogo();

        /*  Graficos */
        //  Definindo cor da tela
        sdl2_limpar_tela(tela, JANELA_COR);

        //  Desenhando o inimigo
        sdl2_desenhar_retangulo(tela, inimigo.retangulo, inimigo.x, inimigo.y, inimigo.largura, inimigo.altura, INIMIGO_COR);
        
        //  Desenhando blocos
        for(int i = 0; i < BLOCO_NUMERO; i++)
        {
            if(bloco[i].vida)
            {
                sdl2_desenhar_retangulo(tela, bloco[i].retangulo, bloco[i].x, bloco[i].y, bloco[i].largura, bloco[i].altura, BLOCO_COR);
            }
        }
        
        //  Desenhando o personagem
        sdl2_desenhar_retangulo(tela, personagem.retangulo, personagem.x, personagem.y, personagem.largura, personagem.altura, PERSONAGEM_COR);

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