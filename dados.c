#include "album.h"


void iniciar_programa(Album *album, int *ptr_auxiliar)
{
    // arrumar moedas
   FILE *arq_dados_album;
   arq_dados_album = fopen("dados_album.bin", "rb"); // tem q fechar?

   if (arq_dados_album == NULL)
   {
      printf("\nSeja bem-vindo(a) ao seu novo álbum de figurinhas!\n");
      printf("Como este álbum é novo, devemos criar os arquivos necessários para o programa funcionar corretamente, mas deixe essa parte conosco ;)\n");
      printf("Devido ao programa utilizar arquivos binários para operar, recomendamos que não abra os arquivos pelo explorador de arquivos, mas somente pelo próprio programa.\n\n");
      printf("STATUS DA CONFIGURAÇÃO DO PROGRAMA:\n");

      arq_dados_album = fopen("dados_album.bin", "wb");
      if (arq_dados_album == NULL)
      {
         printf("Houve um erro de nossa parte ao criar o arquivo :(\n");
         exit(1);
      }
      else
      {
         fclose(arq_dados_album);
         printf("O arquivo necessário para salvar os dados do álbum foi criado com sucesso, e possui o nome de \"dados_album.bin\".\n");
         printf("Logo, todos os arquivos necessários foram criados com sucesso!\n\nVamos agora salvar os dados do proprietário, que... (um pouco de suspense)... é você!\n");
         printf("Comece inserindo seu nome: ");
         fgets(album->proprietario, 49, stdin);
         album->proprietario[strcspn(album->proprietario, "\n")] = '\0';
         limpa_buffer();
         // fwrite(album, sizeof(Album), 1, arq_dados_album);
         //  fwrite(album->fig_coladas, sizeof(Figurinha), album->posicao_no_album, arq_dados_album);
         //  fwrite(album->fig_repetidas_ou_nao_coladas, sizeof(Figurinha), album->posicao_repetidas_ou_nao_coladas, arq_dados_album);
         printf("\nComo é bom poder colocar um rosto ... quero dizer, um nome, à este álbum! Seja bem-vindo(a), %s!\n\n", album->proprietario);
         printf("Antes de partir para a diversão, segue abaixo algumas informações que acho importante você saber:\n");
         printf("1º - Caso você não tenha percebido, isto é um jogo, onde você, proprietário, tem o objetivo de completar este álbum colando figurinhas da Copa do Mundo.\nEu espero, do fundo do meu coração (sou um programa mas tenho coração, ok?) que vocẽ saiba que está ocorrendo uma Copa no Catar. Se você não soubesse acharia estranho você estar aqui :\\ \n\n");
         printf("2º - Estas figurinhas vêm em pacotes com 5 figurinhas aleatórias, e para comprar cada pacote você deve desembolsar a bagatela de 4 moedas.\nNão se preocupe, você começa o jogo com 200 dessas moedas verdes ¯\\_(ツ)_/¯ e perde o jogo se acabar suas moedas e não conseguir completar o álbum. Vida difícil essa, não?\n\n");
         printf("3º - Dentro deste jogo há mini jogos, onde você pode ganhar mais moedas para continuar comprando pacotes.\nComo nada nessa vida é fácil, é preciso investir algumas moedas para dar play nos mini jogos, então tome cuidado para não acabar com o seu nome negativado.\n\n");
         printf("4º - Por último, acho importante você saber, mas não sei se isto é verdade: ouvi dizer que o vendedor de figurinhas gosta de passar a perna em seus clientes.\nEntão se liga, fica bem ligado(a)!\n\n");
         printf("Agora, sem mais delongas, que os jogos comecem! Boa sorte!\n\n");
         album->fig_coladas = (Figurinha *)calloc((album->posicao_no_album + 1), sizeof(Figurinha));
         album->fig_repetidas_ou_nao_coladas = (Figurinha *)calloc((album->posicao_repetidas_ou_nao_coladas + 1), sizeof(Figurinha));
         (*ptr_auxiliar) = 1;
         album->moedas = 200;
         album->posicao_faltantes = 278;
      }
   }
   else
   {
      if ((*ptr_auxiliar) == 0)
      {
         (*ptr_auxiliar) = 1;
         /// tem problema pra abrir essa coisa dai fode com o resto do codigo inteiro e dai como n tem o contador n da pra fazer a alocaçao

         // depois de voltar pro menu tem q temum if e contador pra nao realocar de novo ou chamar a salvar depois de escolher nao na compra de fig
         fread(album, sizeof(Album), 1, arq_dados_album);

         album->fig_coladas = (Figurinha *)calloc((album->posicao_no_album + 1), sizeof(Figurinha));
         album->fig_repetidas_ou_nao_coladas = (Figurinha *)calloc((album->posicao_repetidas_ou_nao_coladas + 1), sizeof(Figurinha));

         // album->fig_repetidas_ou_nao_coladas = (Figurinha *)realloc(album->fig_repetidas_ou_nao_coladas, (album->posicao_repetidas_ou_nao_coladas) * sizeof(Figurinha));
        
         // album->fig_coladas = (Figurinha *)realloc(album->fig_coladas, (album->posicao_no_album) * sizeof(Figurinha));
        
         fread(album->fig_coladas, sizeof(Figurinha), album->posicao_no_album, arq_dados_album);
        
         fread(album->fig_repetidas_ou_nao_coladas, sizeof(Figurinha), album->posicao_repetidas_ou_nao_coladas, arq_dados_album);
         
         printf("\nQuantidade repetidas %d\n", album->posicao_repetidas_ou_nao_coladas);
         fclose(arq_dados_album);
         // printf("%s", album->fig_repetidas_ou_nao_coladas[0]);
      }

      printf("Bem-vindo(a) novamente %s. Por onde você deseja continuar?\n", album->proprietario);
      //printf("%d\n", album->posicao_repetidas_ou_nao_coladas);
      // 2printf("%s", album->fig_repetidas_ou_nao_coladas[0].codigo);

      // tem q fechar arquivo ainda
   }
}

void salvar_hd(Album *album, int *ptr_auxiliar)
{
   
   FILE *arq_dados_album2 = fopen("dados_album.bin", "wb");
   fwrite(album, sizeof(Album), 1, arq_dados_album2);
   fwrite(album->fig_coladas, sizeof(Figurinha), album->posicao_no_album, arq_dados_album2);
   fwrite(album->fig_repetidas_ou_nao_coladas, sizeof(Figurinha), album->posicao_repetidas_ou_nao_coladas, arq_dados_album2);
   fprintf(arq_dados_album2, "%s", album->fig_repetidas_ou_nao_coladas->titulo);
   (*ptr_auxiliar) = 0;
   fclose(arq_dados_album2);
   // free(album->fig_coladas);
   // free(album->fig_repetidas_ou_nao_coladas);
   // free(album);

   // free(album->fig_coladas);
   // free(album->fig_repetidas_ou_nao_coladas);
}

void exportar_dados(Album album){
   FILE *arq;
   arq = fopen("dados.csv", "w");
   if(arq == NULL){
      printf("Erro ao abrir o arquivo!\n");
      exit(1);
   }
      fprintf(arq, "Proprietario: %s\n",album.proprietario);
      fprintf(arq,"Dinheiro gasto: %d\n", album.dinheiro_gasto);
      fprintf(arq,"Porcentagem: %.2f\n", album.porcentagem_do_album);
      fprintf(arq, "Figurinhas coladas:\n");
      fprintf(arq,"Nro, Titulo, Secao, Tipo\n");
      for(int i = 0; i< album.posicao_no_album; i++){
         fprintf(arq, "%s,%s,%s,%s\n", album.fig_coladas[i].codigo,album.fig_coladas[i].titulo,album.fig_coladas[i].secao,album.fig_coladas[i].tipo);
      }
      fprintf(arq, "\nFigurinhas repetidas ou não coladas:\n");
      fprintf(arq,"Nro, Titulo, Secao, Tipo\n");
      for(int i = 0; i< album.posicao_repetidas_ou_nao_coladas; i++){
         fprintf(arq, "%s,%s,%s,%s\n", album.fig_repetidas_ou_nao_coladas[i].codigo,album.fig_repetidas_ou_nao_coladas[i].titulo,album.fig_repetidas_ou_nao_coladas[i].secao,album.fig_repetidas_ou_nao_coladas[i].tipo);
      }
      fclose(arq);
   
}
