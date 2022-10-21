#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  char codigo[10];
  char titulo[10];
  char secao[10];
  char tipo[10];
}Figurinha;

typedef struct{
  //figurinhas coladas
  //figurinhas faltantes
  //proprirtário
  //porcentagem do album
  //dinheiro gasto
}Album;

//void cadastraFigurinha()
//void dadosAlbum()
//void folhearAlbum()
//void comprarEnvelope()
//void bancaFigurinhas()

int main(){
   Album album[2];
  Figurinha figurinha[2];
  int menu;

  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("\tBEM-VINDO AO ALBUM\n\tO que voce gostaria de fazer?\n");
  while (menu!=0){
    printf("\t1. Folhear o album\n\t2. Comprar envelope\n\t3. Mostrar figurinha nao coladas\n\t4. Mostrar dados do album\n\t0. Sair do album\n\tEscolha a opcao: ");
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
        Dados_Album();
    }
  }

  return 0;
  return 0;
}
