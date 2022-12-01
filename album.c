#include "album.h"

void dados_album(Album album, int quant_fig){
  printf("Nome do proprietario do album:\t%s\n",album.proprietario);
  printf("Total de figurinhas coladas:\t%d\n", album.posicao_no_album);
  printf("Total de figurinhas faltantes:\t%d\n", quant_fig - album.posicao_faltantes);
  printf("Porcentagem de conclusao do album:\t%f%%\n", album.porcentagem_do_album);
  printf("Total gasto com envelopes:\t%d\n", album.dinheiro_gasto);

  return;
}
void comprar_envelope(Figurinha *figurinha, Album *album, int quant_fig)
{
    srand(time(NULL));

    
    printf("\n");
    printf("Vamos comprar pacotes de figurinhas! Lembrando que cada pacote possui 5 figurinhas :)\n");
    

    printf("Neste pacote voce obteve:\n");

    for (int i = 0; i < 5; i++)
    {
        char opcao;
        int aux = 0;
        int num = rand() % 678 + 1; // gerar um numero
        printf("FIGURINHA %d:\n", i + 1);
        printf("| Codigo    | Titulo                                  | Secao                                   | Tipo           |\n");
        printf("| %-9s | %-39s | %-39s | %-14s |\n", figurinha[num].codigo, figurinha[num].titulo, figurinha[num].secao, figurinha[num].tipo);

        
        

         /*if (album->posicao_faltantes > 0)
         {
            album->fig_faltantes = realloc(album->fig_faltantes, (album->posicao_faltantes + 1) * sizeof(Figurinha));   
         }*/

        for (int j = 0; j <= quant_fig; j++)
        {
            if (strcasecmp(figurinha[num].codigo, album->fig_coladas[j].codigo) == 0)
            {
                aux++;
                break;
            }
        }

        if (aux >= 1)
        {
            printf("Voce ja possui esta figurinha no seu album! Parabens :)\nAgora, esta figurinha esta salva na relacao de figurinhas repetidas/nao coladas.\n");
            album->posicao_repetidas_ou_nao_coladas++;
            album->fig_repetidas_ou_nao_coladas = realloc(album->fig_repetidas_ou_nao_coladas, (album->posicao_repetidas_ou_nao_coladas) * sizeof(Figurinha));
            album->fig_repetidas_ou_nao_coladas[album->posicao_repetidas_ou_nao_coladas-1] = figurinha[num];
           

        }
        else
        {
            limpa_buffer();
            printf("Voce nao possui esta figurinha em seu album. Deseja cola-la?\nS para sim e N para nao. ");
            
            
            do{
               scanf("%c", &opcao);
               limpa_buffer();
               if (opcao == 'S' || opcao == 's')
               {
                  // realocar a relacao de figurinhas coladas
                  if (album->posicao_no_album > 0)
                  {
                     album->fig_coladas = realloc(album->fig_coladas, (album->posicao_no_album + 1) * sizeof(Figurinha));

                  }
                     
                  album->fig_coladas[album->posicao_no_album] = figurinha[num];
                  album->posicao_no_album++;
                  printf("\nQuantidade de figurinhas: %d\n",album->posicao_no_album);
                  album->posicao_faltantes--;

                  album->porcentagem_do_album = ((100.0 * album->posicao_no_album) / 678);
               }
               if (opcao == 'N' || opcao == 'n')
               {
                  printf("Tudo bem, voce ainda tem a chance de obte-la novamente!\nEsta figurinha foi salva na relacao de figurinhas nao coladas/repetidas.\n");
                  album->posicao_repetidas_ou_nao_coladas++;
                  album->fig_repetidas_ou_nao_coladas = realloc(album->fig_repetidas_ou_nao_coladas, (album->posicao_repetidas_ou_nao_coladas) * sizeof(Figurinha));
                  album->fig_repetidas_ou_nao_coladas[album->posicao_repetidas_ou_nao_coladas-1] = figurinha[num];
               }
               if(opcao!='s' && opcao!='S' && opcao!='n' && opcao!='N'){
                  printf("Opção inválida! Digite novamente: ");
               }
            }while(opcao!='s' && opcao&&'S' && opcao!='n' && opcao!='N');
            
        }
        limpa_buffer();
        printf("\n");
    }
}
void figurinhas_repetidas_ou_nao_coladas(Album *album){
   printf("| Codigo    | Titulo                                  | Secao                                   | Tipo           |\n");

   for(int i=0; i<album->posicao_repetidas_ou_nao_coladas; i++){
      
      printf("| %-9s | %-39s | %-39s | %-14s |\n", album->fig_repetidas_ou_nao_coladas[i].codigo,album->fig_repetidas_ou_nao_coladas[i].titulo,album->fig_repetidas_ou_nao_coladas[i].secao,album->fig_repetidas_ou_nao_coladas[i].tipo);
  
   }
   /*Dar a opção para colar no album, conferir se já não está colada e depois organizar a struct*/

}

void remove_figurinha(char repetida[], Figurinha* figurinha, Album* album){
   int pos;

   //Localiza a posicao do 00000
   for(int l = 0; l<= album->posicao_repetidas_ou_nao_coladas; l++){
      if(strcasecmp(album->fig_repetidas_ou_nao_coladas[l].codigo,"00000")==0){
         pos = l;
         break;
      }
   }//for

   //Puxa os valores de 0000 de pos ate o final do vetor
   for(int k = pos; k< album->posicao_repetidas_ou_nao_coladas; k++){
            album->fig_repetidas_ou_nao_coladas[k] = album->fig_repetidas_ou_nao_coladas[k+1];
   }

   if(album->posicao_repetidas_ou_nao_coladas>1){
     album->posicao_repetidas_ou_nao_coladas--;
   }
   if (album->posicao_repetidas_ou_nao_coladas > 1){
      printf("Antes do realloc %d\n", album->posicao_repetidas_ou_nao_coladas);
      album->fig_repetidas_ou_nao_coladas =  realloc(album->fig_repetidas_ou_nao_coladas, (album->posicao_repetidas_ou_nao_coladas* sizeof(Figurinha)));
      printf("Depois do realloc %d\n", album->posicao_repetidas_ou_nao_coladas);
   }

}

void trocar_figurinha(char repetida[], Figurinha* figurinha, Album* album){
   int probabilidade;
   int sorteio;
   srand(time(0));
   probabilidade = rand()%10;
   

   if(probabilidade>0 && probabilidade<=3){
      printf(YEL"O dono da banca fugiu! Bem-vindo à Apucarana\n"reset);
   }else{
     
      do{
         sorteio = rand()%678+1;
         if(strcasecmp(figurinha[sorteio].codigo,"Nro")!=0){
            if(strcasecmp(figurinha[sorteio].codigo, repetida)!=0){
            
            printf("\nAntes do realloc coladas %d\n", album->posicao_no_album);
            album->fig_coladas = realloc(album->fig_coladas, (album->posicao_no_album + 1)* sizeof(Figurinha));
            printf("\nDepois do realloc coladas%d\n", album->posicao_no_album);                                                                        
            
            album->fig_coladas[album->posicao_no_album] = figurinha[sorteio]; 

            printf("Nova figurinha: \n");
            printf("| Codigo    | Titulo                                  | Secao                                   | Tipo           |\n");
            printf("| %-9s | %-39s | %-39s | %-14s |\n",album->fig_coladas[album->posicao_no_album].codigo,album->fig_coladas[album->posicao_no_album].titulo,album->fig_coladas[album->posicao_no_album].secao,album->fig_coladas[album->posicao_no_album].tipo);
            
            album->posicao_no_album++;
            break;
            }//if
         }//if sorteio
      }while(strcasecmp(figurinha[sorteio].codigo,"Nro")==0);
      
   }//else

}
