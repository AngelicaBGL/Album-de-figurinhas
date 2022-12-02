#include "album.h"


int main(){
   Album album;
   int menu=1, quant_fig=679;
   char opcao;
   char repetida[30];
   int i = 0;
   int auxiliar = 0;

   album.posicao_no_album = 0;
   album.posicao_faltantes=0;
   album.posicao_repetidas_ou_nao_coladas=0;

   //Preenchendo o vetor de figurinhas com os dados do arquivo
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

   //Lendo os dados salvos no hd, ou criando um arquivo caso não exista
   iniciar_programa(&album, &auxiliar);

   //menu
   while (menu!=0){
      //conferindo se tem moedas o suficiente para continuar no jogo
      if(album.moedas<=0){
         printf("Suas moedas acabaram! Você perdeu :-(\n");
         break;
      }else{
         printf(YEL"Moedas %d\n", album.moedas);
         printf(MAG" =========================================================================\n");
         printf(MAG"||"WHT"                             Álbum da Copa 2022                        "MAG"||\n");
         printf(MAG" =========================================================================\n"); 
         printf(MAG"\nMenu:\n\n");
         printf(WHT"\t1 - Dados do Álbum\n\t2 - Folhear Álbum\n\t3 - Comprar Envelope de Figurinhas\n"reset); 
         printf(WHT"\t4 - Figurinhas Repetidas e/ou Não Coladas\n\t5 - Trocar Figurinha\n\t6 - Ganhar Moedas\n\t7 - Exportar Dados do Álbum\n");
         printf(RED"\t0 - Sair\n\t"reset);
         scanf("%d", &menu);
         limpa_buffer();
         switch (menu){
            case 0:
               //salvar os dados em um arquivo .bin
               salvar_hd(&album, &auxiliar);
               limpa_tela();
               break;
            case 1:
               //exibe na tela os dados do album
               dados_album(album, quant_fig);
               break;
            case 2:
               //folhear o album
               folhear_album(figurinha, album, quant_fig);
               break;
            case 3: 
               //comprar pacote de figurinhas, gasta 4 moedas
               do{
                  printf("Comprar envelope por 4 moedas? (s/n)\n");
                  scanf("%c", &opcao);
                  limpa_buffer();
                  if(opcao=='s' || opcao=='S'){
                     if(album.moedas>=4){
                     album.moedas = album.moedas - 4;
                     album.dinheiro_gasto = album.dinheiro_gasto + 4; 
                     //função que abre o pacote de figurinha
                     comprar_envelope(figurinha,&album,quant_fig);
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
               //mostra as figurinhas não coladas e/ou repetidas e dá a opção de colar uma
               figurinhas_repetidas_ou_nao_coladas(&album);
               char opcao2;
               char repetida[30];
               printf("\nGostaria de colar alguma dessas figurinhas?(s/n)\n");
               do{
                  scanf("%c", &opcao2);
                  limpa_buffer();
                  if(opcao2=='s' || opcao2=='S'){
                     printf("Digite o código da figurinha que deseja trocar: ");
                     fgets(repetida, 29, stdin);
                     repetida[strcspn(repetida, "\n")]='\0';
                     limpa_buffer();
                     //função para colar a figurinha
                     cola_figurinha(&album, figurinha, repetida);
                  }else if(opcao2=='n' || opcao2=='N'){
                     printf("Tudo bem :), mas se quiser colar já sabe onde vir ;)\n");
                  }else{
                     printf("Opção inválida!\n");
                  }
            
               }while(opcao2!='s' && opcao2!='S' && opcao2!='n' && opcao2!='N');
               break;
            case 5:
               //trocar figurinha com a banca
               printf("Digite o código da figurinha que deseja trocar: ");
               fgets(repetida, 29, stdin);
               repetida[strcspn(repetida, "\n")]='\0';
               limpa_buffer();
               int tem = 0;
               
               //conferindo se tem essa figurionha na relação de repetidas/não coladas
               for(int j=0;j<album.posicao_repetidas_ou_nao_coladas; j++){
                  if(strcasecmp(repetida,album.fig_repetidas_ou_nao_coladas[j].codigo)==0){
                     strcpy(album.fig_repetidas_ou_nao_coladas[j].codigo,"00000");
                     tem = 1; 
                  }
               }
               if(tem==0){
                  printf("Esta figurinha não está na relação de figurinhas repetidas e/ou não coladas.\n");
               }else{ 
                  //função pra remover uma figurinha do vetor
                  remove_figurinha(repetida, figurinha, &album);
                  //função para trocar figurinha com a banca
                  trocar_figurinha(repetida, figurinha, &album);       
               }
               break;
            case 6:
               //ganhar moedas através de mini jogos
               ganhar_moedas(&album);         
               break;
            case 7:
               //exportar os dados do album, as figurinha coladas e as não coladas/repetida em um arquivo .csv
               exportar_dados(album);
               break;
            default:
               printf("Opção inválida! Tente novamente!\n");
               break;
         }//switch


      }
         
   }//while

   //liberando as memórias alocadas
   free(album.fig_coladas);
   free(album.fig_repetidas_ou_nao_coladas);
 
   

  return 0;
}
