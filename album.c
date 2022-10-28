#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  char codigo[10];
  char titulo[50];
  char secao[20];
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

void limpar_struct(Figurinha figurinha[]){
  for (int i=0; i<5; i++){
    if (strcmp(figurinha[i].codigo, "00000")!=0){
      strcpy(figurinha[i].codigo, "00000");
    }
  }
}

void folhear_album(){
  int seletor;
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Qual album deseja folhear?");
  scanf("%d", &seletor);
}

void dados_album(Album album[]){
  int seletor;
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("De qual album voce deseja os dados?\n");
  scanf("%d", &seletor);
  seletor--;
  printf("Nome do proprietario do album:\t%s\n",album[seletor].proprietario);
  printf("Total de figurinhas coladas:\t%d\n", album[seletor].contador_figurinha);
  printf("Total de figurinhas faltantes:\t%d\n", 679-album[seletor].contador_figurinha);
  printf("Porcentagem de conclusao do album:\t%f%%\n", album[seletor].porcentagem_do_album);
  printf("Total gasto com envelopes:\t%.2f\n", album[seletor].dinheiro_gasto);

  return;
}

void comprar_envelope(){}

void figurinhas_nao_coladas(){}

int adicionar_album(Album album[], int quant_alb){
  int amais;
  printf("Quantos albuns voce quer adicionar?");
  scanf("%d", &amais);
  quant_alb = quant_alb + amais;
  void *realloc(void *album, unsigned int quant_alb);
  printf("Mais %d album(s) foram adicionados\n", amais);

  return quant_alb;
}

int excluir_album(Album album[], int quant_alb, int quant_fig){
  int amenos, aux;
  printf("Quantos albuns voce quer excluir?");
  scanf("%d", &amenos);
  if (amenos < quant_alb){
   for (int i=0; i<amenos; i++){
    for(int j=0; j<quant_alb; j++){
      printf("album %d\n", j);
    }
    for (int a=0; a<amenos; a++){
    printf("Qual album deseja excluir?\n");
    scanf("%d", &aux);
    if(aux = quant_alb){
      quant_alb--;
      void *realloc(void *album, unsigned int quant_alb);
      break;
    }
    if (aux < quant_alb){
        for (int j=aux; j<quant_alb; j++){
          album[j].contador_figurinha=album[j+1].contador_figurinha;
          album[j].dinheiro_gasto=album[j+1].dinheiro_gasto;
          album[j].porcentagem_do_album=album[j+1].porcentagem_do_album;
          strcpy(album[j].proprietario,album[j+1].proprietario);
          for (int k=0; k<quant_fig; k++){
            strcpy(album[j].figurinhas_coladas[k],album[j+1].figurinhas_coladas[k]);
            strcpy(album[j].figurinhas_faltantes[k],album[j+1].figurinhas_faltantes[k]);
          }
      }
      quant_alb--;
      void *realloc(void *album, unsigned int quant_alb);
    }
    }
   }
  }
  else printf("Quantidade excede a de albuns atuais\n");

  return quant_alb;

}

int cadastrar_figurinha(Figurinha figurinha[], int quant_fig){
  int amais;
  printf("Quantas figurinhas vc deseja cadastrar?\n");
  scanf("%d", &amais);
  quant_fig = quant_fig + amais;
  void *realloc(void *figurinha, unsigned int quant_fig);
  limpar_struct(figurinha);
  for (int i=0; i<quant_fig; i++){
    if (strcmp(figurinha[i].codigo, "00000")==0){
      fflush(stdin);
      printf("Digite o codigo da figurinha: ");
      fgets(figurinha[i].codigo, 5, stdin);
      fflush(stdin);
      printf("Digite o titulo da figurinha: ");
      fgets(figurinha[i].titulo, 10, stdin);
      fflush(stdin);
      printf("Digite a secao da figurinha: ");
      fgets(figurinha[i].secao, 10, stdin);
      fflush(stdin);
      printf("Digite o tipo da figurinha: ");
      fgets(figurinha[i].tipo, 10, stdin);
      fflush(stdin);
    }
  }

  return quant_fig;

}

int main(){
  Album album[0];
  Figurinha figurinha[0];
  int menu=1, menualbum=1, quant_alb, quant_fig=0;

  printf("Quantos albuns gostaria de cadastrar?\n");
  scanf("%d", &quant_alb);
  
  void *realloc(void *album, unsigned int quant_alb);

  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("\tBEM-VINDO AO ALBUM\n\tO que voce gostaria de fazer?\n");
  while (menu!=0){
    printf("\t1. Folhear o album\n\t2. Comprar envelope\n\t3. Mostrar figurinha nao coladas\n\t4. Mostrar dados do album\n\t5. Configurar Albuns\n\t6. Cadastar Figurinha\n\t0. Sair do album\n\tEscolha a opcao: ");
    scanf("%d", &menu);
    switch (menu){
      case 1:
        folhear_album();
        break;
      case 2:
        comprar_envelope();
        break;
      case 3:
        figurinhas_nao_coladas();
        break;
      case 4:
        dados_album(album);
        break;
      case 5:
        while (menualbum!=0){
          printf("\t1. Adicionar album\n\t2. Excluir album\n\t0. Voltar ao menu principal\n");
          scanf("%d", &menualbum);
          switch (menualbum){
            case 1:
              quant_alb= adicionar_album(album, quant_alb);
              break;
            case 2:
              quant_alb= excluir_album(album, quant_alb, quant_fig);
              break;
          }
        }
        break;
      case 6:
        quant_fig = cadastrar_figurinha(figurinha, quant_fig);
        break;
    }
  }

  return 0;
}
