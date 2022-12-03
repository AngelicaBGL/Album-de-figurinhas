#include "album.h"

/**
 * @brief Exibe na tela os dados do álbum
 * 
 * @param album 
 * @param quant_fig 
 */
void dados_album(Album album, int quant_fig){

   //exibindo na tela os dados do álbum
   printf("Nome do proprietario do album:\t%s\n",album.proprietario);
   printf("Total de figurinhas coladas:\t%d\n", album.posicao_no_album);
   printf("Total de figurinhas faltantes:\t%d\n", album.posicao_faltantes);
   printf("Porcentagem de conclusao do album:\t%f%%\n", album.porcentagem_do_album);
   printf("Total gasto com envelopes:\t%d\n", album.dinheiro_gasto);

   return;
}

/**
 * @brief Abre um pacote com 5 figurinhas aleatória, cola no álbum ou salva no vetor de não coladas
 * 
 * @param figurinha 
 * @param album 
 * @param quant_fig 
 */
void comprar_envelope(Figurinha *figurinha, Album *album, int quant_fig){
   //função para gerar numero aleatorio
   srand(time(NULL));

   printf("\n");
   printf("Vamos comprar pacotes de figurinhas! Lembrando que cada pacote possuí 5 figurinhas :)\n");
   
   printf("Neste pacote você obteve:\n");

   for (int i = 0; i < 5; i++)
   {
      char opcao;
      int aux = 0;
      //numero aleatorio 
      int num = rand() % 679; 

      printf("FIGURINHA %d:\n", i + 1);
      printf("| Código    | Título                                  | Seção                                   | Tipo           |\n");
      printf("| %-9s | %-39s | %-39s | %-14s |\n", figurinha[num].codigo, figurinha[num].titulo, figurinha[num].secao, figurinha[num].tipo);


      //conferindo se a figurinha já está colada
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
         //seaa figurinha for repetida
         printf("Você já possuí esta figurinha no seu álbum! Parabéns :)\nAgora, esta figurinha está salva na relação de figurinhas repetidas/não coladas.\n");
         album->posicao_repetidas_ou_nao_coladas++;
         album->fig_repetidas_ou_nao_coladas = realloc(album->fig_repetidas_ou_nao_coladas, (album->posicao_repetidas_ou_nao_coladas) * sizeof(Figurinha));
         album->fig_repetidas_ou_nao_coladas[album->posicao_repetidas_ou_nao_coladas-1] = figurinha[num];
   
      }
      else
      {
         limpa_buffer();
         printf("Você não possuí esta figurinha em seu álbum. Deseja cola-lá?\nS para sim e N para não. ");
         
         //opção de colar ou não a nova figurinha
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
                  
               //colando a figurinha 
               album->fig_coladas[album->posicao_no_album] = figurinha[num];
               album->posicao_no_album++;
               
               //atualizando dados do álbum
               album->posicao_faltantes--;
               album->porcentagem_do_album = ((100.0 * album->posicao_no_album) / 678);
            }
            if (opcao == 'N' || opcao == 'n')
            {
               printf("Tudo bem, você ainda tem a chance de obte-la novamente!\nEsta figurinha foi salva na relação de figurinhas repetidas/não coladas.\n");
               
               //salvando na relação de figurinhas não coladas ou repetidas
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

/**
 * @brief Colar figurinha que foi salva no vetor de não coladas
 * 
 * @param album 
 * @param figurinha 
 * @param repetida 
 */
void cola_figurinha(Album *album, Figurinha *figurinha, char repetida[]){
   int tem = 0;
   int colada = 0;
   int pos;
   Figurinha auxiliar;
   for(int j=0;j<album->posicao_repetidas_ou_nao_coladas; j++){
      //conferindo se a figurinha está realmente no vetor
      if(strcasecmp(repetida,album->fig_repetidas_ou_nao_coladas[j].codigo)==0){
         auxiliar=album->fig_repetidas_ou_nao_coladas[j];
         tem = 1; 
         pos = j;
      }
   }
   if(tem==0){
      printf("Esta figurinha não está na relação de figurinhas repetidas e/ou não coladas.\n");
   }else{ 
      //conferindo se a figurinha já foi colada
      for(int k=0; k<album->posicao_no_album; k++){
         if(strcasecmp(repetida,album->fig_coladas[k].codigo)==0){
            colada=1;
         }
      }//for

      if(colada==0){
         
         strcpy(album->fig_repetidas_ou_nao_coladas[pos].codigo,"00000");
         //removendo a figurinha do vetor de não coladas
         remove_figurinha(repetida, figurinha, album);
         
         //salvando figurinha no vetor de coladas
         album->fig_coladas = realloc(album->fig_coladas, (album->posicao_no_album + 1)* sizeof(Figurinha));
         album->fig_coladas[album->posicao_no_album] = auxiliar;
         album->posicao_no_album++;
         album->posicao_faltantes--;
      }else{
         printf("Essa figurinha é repetida!\n");
      }
   }
}

/**
 * @brief Exibe na tela as figurinha repetidas e as não coladas no álbum
 * 
 * @param album 
 */
void figurinhas_repetidas_ou_nao_coladas(Album *album){
   int j=0;
   //exibindo na tela as figurinhas
   printf("| Codigo    | Titulo                                  | Secao                                   | Tipo           |\n");
   for(int i=0; i<album->posicao_repetidas_ou_nao_coladas; i++){
      if(strcasecmp(album->fig_repetidas_ou_nao_coladas[i].codigo,"00000")!=0){
         printf("| %-9s | %-39s | %-39s | %-14s |\n", album->fig_repetidas_ou_nao_coladas[i].codigo,album->fig_repetidas_ou_nao_coladas[i].titulo,album->fig_repetidas_ou_nao_coladas[i].secao,album->fig_repetidas_ou_nao_coladas[i].tipo);
      }
  
   }  
}

/**
 * @brief Para remover figurinha do vetor de não coladas e/ou repetidas
 * 
 * @param repetida 
 * @param figurinha 
 * @param album 
 */
void remove_figurinha(char repetida[], Figurinha* figurinha, Album* album){
   int pos;
   //Localiza a posicao do 00000
   for(int l = 0; l<= album->posicao_repetidas_ou_nao_coladas; l++){
      if(strcasecmp(album->fig_repetidas_ou_nao_coladas[l].codigo,"00000")==0){
         pos = l;
         break;
      }
   }//for

   //Puxa os valores de 00000 de pos ate o final do vetor
   for(int k = pos; k< album->posicao_repetidas_ou_nao_coladas; k++){
            album->fig_repetidas_ou_nao_coladas[k] = album->fig_repetidas_ou_nao_coladas[k+1];
   }

   //reallocando o vetor para um tamanho menor
   if(album->posicao_repetidas_ou_nao_coladas>1){
     album->posicao_repetidas_ou_nao_coladas--;
   }
   if (album->posicao_repetidas_ou_nao_coladas > 1){
      
      album->fig_repetidas_ou_nao_coladas =  realloc(album->fig_repetidas_ou_nao_coladas, (album->posicao_repetidas_ou_nao_coladas* sizeof(Figurinha)));
   }

}

/**
 * @brief Trocar figurinha repetida e/ou não colada com a banca de figurinhas
 * 
 * @param repetida 
 * @param figurinha 
 * @param album 
 */
void trocar_figurinha(char repetida[], Figurinha* figurinha, Album* album){
   int probabilidade;
   int sorteio;
   //probabildade da troca de figurinhas acontecer
   srand(time(0));
   probabilidade = rand()%10;
   

   if(probabilidade>0 && probabilidade<=3){
      //30% de chance do dono da banca fugir sem devolver a figurinha
      printf(YEL"O dono da banca fugiu! Bem-vindo à Apucarana\n"reset);
   }else{
     //troca por uma figurinha nova
      do{
         //figurinha nova aleatória
         sorteio = rand()%678+1;
         if(strcasecmp(figurinha[sorteio].codigo,"Nro")!=0){
            //conferindo se a figurinha já não foi colada
            if(strcasecmp(figurinha[sorteio].codigo, repetida)!=0){
         
            //colando a figurinha nova no álbum
            album->fig_coladas = realloc(album->fig_coladas, (album->posicao_no_album + 1)* sizeof(Figurinha));                                                              
            album->fig_coladas[album->posicao_no_album] = figurinha[sorteio]; 

            printf("Nova figurinha: \n");
            printf("| Codigo    | Titulo                                  | Secao                                   | Tipo           |\n");
            printf("| %-9s | %-39s | %-39s | %-14s |\n",album->fig_coladas[album->posicao_no_album].codigo,album->fig_coladas[album->posicao_no_album].titulo,album->fig_coladas[album->posicao_no_album].secao,album->fig_coladas[album->posicao_no_album].tipo);
            
            album->posicao_no_album++;
            album->posicao_faltantes--;
            break;
            }//if
         }//if sorteio
      }while(strcasecmp(figurinha[sorteio].codigo,"Nro")==0);
      
   }//else

}
