#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include "header.h"

int main(){
  Album album;
  int menu=1, menu2 = 1, quant_fig=679;
  int seletor=0;
  int moedas=200;
  char opcao;
  char repetida[30];
  int i = 0;

  biblioteca();

   album.posicao_faltantes=0;
   album.posicao_repetidas_ou_nao_coladas=0;

   album.fig_coladas = (Figurinha *)calloc(1, sizeof(Figurinha));
   album.fig_repetidas_ou_nao_coladas = (Figurinha *)calloc(1, sizeof(Figurinha));
   album.fig_faltantes = (Figurinha *)calloc(1, sizeof(Figurinha));

   Figurinha figurinha[679];
   FILE *arq;
   arq = fopen("figurinhas.csv", "r");

   if(arq == NULL){
      printf("Erro ao abrir o arquivo!\n");
      exit(1);
   }
   
   while(!feof(arq)){
      fscanf(arq, "%[^,],%[^,],%[^,],%[^\n]\n", figurinha[i].codigo,figurinha[i].titulo,figurinha[i].secao,figurinha[i].tipo);
      i++;
   }
   
   fclose(arq);

  while (menu!=0){
   printf(YEL"Moedas %d\n", moedas);
   printf(MAG" =========================================================================\n");
   printf(MAG"||"WHT"                             Álbum da Copa 2022                        "MAG"||\n");
   printf(MAG" =========================================================================\n"); 
   printf(MAG"\nMenu:\n\n");
   printf(WHT"\t1 - Criar Álbum\n\t2 - Álbuns\n\t3 - Ganhar Moedas\n\t4 - Salvar progresso\n"RED"\t0 - Sair\n\t"reset); 
   scanf("%d", &menu);
   limpa_buffer();
   switch (menu){
      case 1:
         //criar_album(album);
         break;
      case 2:
         //mostrar os albuns disponiveis
         //printf("Digite o número do álbum que deseja: ");
         //scanf("%d", &seletor);
         //limpa_buffer();
         //if(){}else{} possivel album
         while (menu2!=0)
         {
               printf(YEL"Moedas %d\n", moedas);
               printf(MAG" =========================================================================\n");
               printf(MAG"||"WHT"                             Álbum da Copa 2022                        "MAG"||\n");
               printf(MAG" =========================================================================\n"); 
               printf(MAG"\nÁlbuns:\n\n");
               printf(WHT"\t1 - Dados\n\t2 - Folhear Álbum\n\t3 - Comprar Envelope de Figurinhas\n\t4 - Figurinhas Repetidas e/ou Não Coladas\n");
               printf("\t5 - Trocar Figurinha\n\t6 - Exportar dados do Álbum\n\t7 - Álbum Apucarana\n"RED"\t0 - Voltar\n\t"reset);
               scanf("%d", &menu2);
               limpa_buffer();
            switch (menu2){
               case 0:
                  break;
               case 1:
                  //dados_album(album, seletor);
                  break;
               case 2:
                  folhear_album(figurinha, album, quant_fig);
                  break;
               case 3:
                  do{
                     printf("Comprar envelope por 4 moedas? (s/n)\n");
                     scanf("%c", &opcao);
                     limpa_buffer();
                     if(opcao=='s' || opcao=='S'){
                        if(moedas>4){
                        moedas = moedas - 4;
                        album.dinheiro_gasto = album.dinheiro_gasto + 4; 
                        comprar_envelope(figurinha,&album);
                        }else{
                           printf("Você não possui moedas suficiente!\n");
                        }
                        break;
                     }else if(opcao=='n' || opcao=='N'){
                        break;
                     }else{
                        printf("Opção inválida!\n");
                     }
                  }while (opcao!='n' || opcao!='N');
                  break;
               case 4: 
                  figurinhas_repetidas_ou_nao_coladas(album);
                  break;
               case 5:
                  printf("Digite o código da figurinha que deseja trocar: ");
                  fgets(repetida, 29, stdin);
                  repetida[strcspn(repetida, "\n")]='\0';
                  limpa_buffer();
                  int tem = 0;
                  for(int i=0;i<quant_fig; i++){
                     if(strcasecmp(repetida,album.fig_repetidas_ou_nao_coladas[i].codigo)==0){
                        strcpy(album.fig_repetidas_ou_nao_coladas[i].codigo,"00000");
                        tem = 1;
                     }
                  }
                  if(tem==0){
                     printf("Esta figurinha não está na relação de figurinhas repetidas e/ou não coladas.\n");
                  }else{
                     trocar_figurinha(repetida, figurinha, &album, quant_fig);       
                  }
                  break;
               case 6:
                  //criar um arquivo .csv
                  break;
               case 7:
                  //album_apucarana();
                  break;
               default:
                  printf("Opção inválida! Tente novamente!\n");
                  break;
               }
               break;
            }//switch 2
            break;

      case 3:
         ganhar_moedas(&moedas);         
         break;
      case 4:
         //salvar progresso
         break;
      default:
         printf("Opção inválida! Tente novamente!\n");
         break;
    }//switch

   
  }//while

   limpa_tela();

   free(album.fig_coladas);
   free(album.fig_repetidas_ou_nao_coladas);
   free(album.fig_faltantes);


  return 0;
}