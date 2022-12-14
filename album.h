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
    Figurinha *fig_repetidas_ou_nao_coladas;
    int posicao_no_album;
    int posicao_repetidas_ou_nao_coladas;
    int posicao_faltantes;
    char proprietario[50];
    int moedas;
    float porcentagem_do_album;
    int dinheiro_gasto;
} Album;

void limpa_tela();
void limpa_buffer();
void tempo();
void mostra(Figurinha* figurinha, Album album, int total, char secao[]);
void capa();
void folhear_album(Figurinha* figurinha, Album album, int quant_fig);
void dados_album(Album album, int quant_fig);
void comprar_envelope(Figurinha *figurinha, Album *album, int quant_fig);
void figurinhas_repetidas_ou_nao_coladas(Album *album);
int forca();
int memoria();
void ganhar_moedas(Album* album);
void trocar_figurinha(char repetida[], Figurinha* figurinha, Album* album);
void iniciar_programa(Album *album, int *ptr_auxiliar);
void salvar_hd(Album *album, int *ptr_auxiliar);
void exportar_dados(Album album);
void remove_figurinha(char repetida[], Figurinha* figurinha, Album *album);
void cola_figurinha(Album *album, Figurinha *figurinha, char repetida[]);