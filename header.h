#ifndef header_h
#define header_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>

//teclas
#define ESC 's'
#define DIREITA 'd'
#define ESQUERDA 'a'

//cores
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define reset "\e[0m"

typedef struct{
   char codigo[10];
   char titulo[40];
   char secao[40];
   char tipo[15];
}Figurinha;

typedef struct
{
    Figurinha *fig_coladas;
    Figurinha *fig_faltantes;
    Figurinha *fig_repetidas_ou_nao_coladas;
    //Figurinha *fig_disponiveis;
    int quant_fig;
    int posicao_no_album;
    int posicao_repetidas_ou_nao_coladas;
    int posicao_faltantes;
    char proprietario[50];
    int quant_n_colada;
    int quant_colada;
    int quant_repetida;
    float porcentagem_do_album;
    float dinheiro_gasto;
    int contador_figurinha;
}Album;

int forca();
int memoria();
void ganhar_moedas(int* moedas);

void limpa_tela();
void limpa_buffer();
void tempo();
void biblioteca();

void mostra(Figurinha* figurinha, Album album, int total, char secao[]);
void capa();
void folhear_album(Figurinha* figurinha, Album album, int quant_fig);

void dados_album(Album album, int quant_fig);
void comprar_envelope(Figurinha *figurinha, Album *album);
void figurinhas_repetidas_ou_nao_coladas(Album album);
void trocar_figurinha(char repetida[], Figurinha* figurinha, Album* album, int quant_fig);

#endif