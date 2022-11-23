#include "header.h"

void dados_album(Album album, int quant_fig){
  printf("Nome do proprietario do album:\t%s\n",album.proprietario);
  printf("Total de figurinhas coladas:\t%d\n", album.contador_figurinha);
  printf("Total de figurinhas faltantes:\t%d\n", quant_fig - album.contador_figurinha);
  printf("Porcentagem de conclusao do album:\t%f%%\n", album.porcentagem_do_album);
  printf("Total gasto com envelopes:\t%.2f\n", album.dinheiro_gasto);

  return;
}

void comprar_envelope(Figurinha *figurinha, Album *album)
{
    srand(time(NULL));

    // se colocar mais de um album temos q fazer um if e switch pra escolher o album
    printf("\n");
    printf("Vamos comprar pacotes de figurinhas! Lembrando que cada pacote possui 5 figurinhas :)\n");
    // printf("Para qual album voce deseja comprar figurinhas? ");

    printf("Neste pacote voce obteve:\n");

    for (int i = 0; i < 5; i++)
    {
        char opcao;
        int aux = 0;
        int num = rand() % 679; // gerar um numero
        printf("FIGURINHA %d:\n", i + 1);
        printf("| Codigo    | Titulo                                  | Secao                                   | Tipo           |\n");
        printf("| %-9s | %-39s | %-39s | %-14s |\n", figurinha[num].codigo, figurinha[num].titulo, figurinha[num].secao, figurinha[num].tipo);

        // tenho q fazer o strcomp pra ver se ta no album antes de perguntar se quer colar ou nao

        
         // realocar a relacao de figurinhas coladas, repetidas/nao coladas e faltantes
         if (album->posicao_no_album > 0)
         {
               for (int l = 1; l <= album->posicao_no_album; l++)
               {
                  album->fig_coladas = realloc(album->fig_coladas, (album->posicao_no_album + 1) * sizeof(Figurinha));
               }
         }
            
        if (album->posicao_repetidas_ou_nao_coladas > 0)
         {
               for (int l = 1; l <= album->posicao_repetidas_ou_nao_coladas; l++)
               {
                  album->fig_repetidas_ou_nao_coladas = realloc(album->fig_repetidas_ou_nao_coladas, (album->posicao_repetidas_ou_nao_coladas + 1) * sizeof(Figurinha));
               }
         }

         if (album->posicao_faltantes > 0)
         {
               for (int l = 1; l <= album->posicao_faltantes; l++)
               {
                  album->fig_faltantes = realloc(album->fig_faltantes, (album->posicao_faltantes + 1) * sizeof(Figurinha));
               }
         }

        for (int j = 0; j <= album->quant_fig; j++)
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
            album->fig_repetidas_ou_nao_coladas[album->posicao_repetidas_ou_nao_coladas] = figurinha[num];
            album->posicao_repetidas_ou_nao_coladas++;
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
                  album->fig_coladas[album->posicao_no_album] = figurinha[num];
                  album->posicao_no_album++;

                  album->porcentagem_do_album = ((100.0 * album->posicao_no_album) / 678);
               }
               if (opcao == 'N' || opcao == 'n')
               {
                  printf("Tudo bem, voce ainda tem a chance de obte-la novamente!\nEsta figurinha foi salva na relacao de figurinhas nao coladas/repetidas.\n");
                  album->fig_repetidas_ou_nao_coladas[album->posicao_repetidas_ou_nao_coladas] = figurinha[num];
                  album->posicao_repetidas_ou_nao_coladas++;
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

void figurinhas_repetidas_ou_nao_coladas(Album album){
   printf("| Codigo    | Titulo                                  | Secao                                   | Tipo           |\n");

   for(int i=0; i<album.posicao_repetidas_ou_nao_coladas; i++){
      if(strcasecmp(album.fig_repetidas_ou_nao_coladas[i].codigo,"00000")!=0){
         printf("| %-9s | %-39s | %-39s | %-14s |\n", album.fig_repetidas_ou_nao_coladas[i].codigo,album.fig_repetidas_ou_nao_coladas[i].titulo,album.fig_repetidas_ou_nao_coladas[i].secao,album.fig_repetidas_ou_nao_coladas[i].tipo);
      }  
   }

}

void trocar_figurinha(char repetida[], Figurinha* figurinha, Album* album, int quant_fig){
   int probabilidade;
   int sorteio;
   srand(time(0));
   probabilidade = rand()%10;
   
   if(probabilidade>0 && probabilidade<=3){
      printf(YEL"O dono da banca fugiu! Bem-vindo à Apucarana\n"reset);
      if(album->posicao_repetidas_ou_nao_coladas>1){
         album->posicao_repetidas_ou_nao_coladas--;
      }
      album->fig_repetidas_ou_nao_coladas = realloc(album->fig_repetidas_ou_nao_coladas,album->posicao_repetidas_ou_nao_coladas*sizeof(Figurinha)); 
   }else{
      
      for (int l = 1; l <= album->posicao_no_album; l++)
               {
                  album->fig_coladas = realloc(album->fig_coladas, (album->posicao_no_album + 1) * sizeof(Figurinha));
               }
      do{
         sorteio = rand()%679;
         if(strcasecmp(figurinha[sorteio].codigo,"Nro")!=0){
            if(strcasecmp(figurinha[sorteio].codigo, repetida)!=0){
            
            album->fig_coladas[album->posicao_no_album] = figurinha[sorteio]; 

            printf("Nova figurinha: \n");
            printf("| Codigo    | Titulo                                  | Secao                                   | Tipo           |\n");
            printf("| %-9s | %-39s | %-39s | %-14s |\n",album->fig_coladas[album->posicao_no_album].codigo,album->fig_coladas[album->posicao_no_album].titulo,album->fig_coladas[album->posicao_no_album].secao,album->fig_coladas[album->posicao_no_album].tipo);
            
            if(album->posicao_repetidas_ou_nao_coladas>1){
               album->posicao_repetidas_ou_nao_coladas--;
            }
            if (album->posicao_repetidas_ou_nao_coladas > 0)
            {
               for (int l = 1; l <= album->posicao_repetidas_ou_nao_coladas; l++)
               {
                  album->fig_repetidas_ou_nao_coladas = realloc(album->fig_repetidas_ou_nao_coladas, (album->posicao_repetidas_ou_nao_coladas + 1) * sizeof(Figurinha));
               }
            }
            
            album->posicao_no_album++;      
            break;
            
            }//if

   
         }//if sorteio
      }while(strcasecmp(figurinha[sorteio].codigo,"Nro")==0);
            
   }//else
   for(int k = album->posicao_repetidas_ou_nao_coladas; k>=1; k--){
      for(int l = 0; l<=k; l++){
         if(strcasecmp(album->fig_repetidas_ou_nao_coladas[l].codigo,"00000")==0){
            Figurinha auxiliar;
            auxiliar = album->fig_repetidas_ou_nao_coladas[l];
            album->fig_repetidas_ou_nao_coladas[l] = album->fig_repetidas_ou_nao_coladas[l+1];
            album->fig_repetidas_ou_nao_coladas[l+1] = auxiliar;
         }
      }
   }
   
}