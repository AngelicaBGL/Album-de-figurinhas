#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  char codigo[5];
  char titulo[10];
  char secao[10];
  char tipo[10];
}Figurinha;

typedef struct{
  char figurinhas_coladas[678][5];
  char figurinhas_faltantes[678][5];
  char proprietario[50];
  float porcentagem_do_album; 
  float dinheiro_gasto;
  int contador_figurinha;
}Album;

void Folhear_album(){
  int seletor;
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Qual album deseja folhear?");
  scanf("%d", &seletor);
}

void Dados_Album(Album album[]){
  int seletor;
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("De qual album voce deseja os dados?\n");
  scanf("%d", &seletor);
  seletor = seletor-1;
  printf("Nome do proprietario do album:\t%s\n",album[seletor].proprietario);
  printf("Total de figurinhas coladas:\t%d\n", album[seletor].contador_figurinha);
  printf("Total de figurinhas faltantes:\t%d\n", 679-album[seletor].contador_figurinha);
  printf("Porcentagem de conclusao do album:\t%f%%\n", album[seletor].porcentagem_do_album);
  printf("Total gasto com envelopes:\t%.2f\n", album[seletor].dinheiro_gasto);

  return;
}

void Comprar_Envelope(){}

void Figurinhas_Nao_Coladas(){
}

void Adicionar_album(){}

void Excluir_album(){}

int main(){
  Album album[2];
  Figurinha figurinha[2];
  int menu=1, menualbum=1;

  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("\tBEM-VINDO AO ALBUM\n\tO que voce gostaria de fazer?\n");
  while (menu!=0){
    printf("\t1. Folhear o album\n\t2. Comprar envelope\n\t3. Mostrar figurinha nao coladas\n\t4. Mostrar dados do album\n\t5. Configurar Albuns\n\t0. Sair do album\n\tEscolha a opcao: ");
    scanf("%d", &menu);
    switch (menu){
      case 1:
        Folhear_album();
        break;
      case 2:
        Comprar_Envelope();
        break;
      case 3:
        Figurinhas_Nao_Coladas();
        break;
      case 4:
        Dados_Album(album);
        break;
      case 5:
        while (menualbum!=0){
          printf("\t1. Adicionar album\n\t2. Excluir album\n\t0. Voltar ao menu principal\n");
          scanf("%d", &menualbum);
          switch (menualbum){
            case 1:
              Adicionar_album();
              break;
            case 2:
              Excluir_album();
          }
        }
    }
  }

  return 0;
}
