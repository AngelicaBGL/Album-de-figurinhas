#include "album.h"

/**
 * @brief Lê dados salvos no hd, cria arquivo novo se necessário
 * 
 * @param album 
 * @param ptr_auxiliar 
 */
void iniciar_programa(Album *album, int *ptr_auxiliar)
{
   //abrindo arquivo binário
   FILE *arq_dados_album;
   arq_dados_album = fopen("dados_album.bin", "rb");

   if (arq_dados_album == NULL)
   {
      //se não existir arquivo será criado um
      //mensagem de boas vindas
      printf("\nSeja bem-vindo(a) ao seu novo álbum de figurinhas!\n");
      printf("Como este álbum é novo, devemos criar os arquivos necessários para o programa funcionar corretamente, mas deixe essa parte conosco ;)\n");
      printf("Devido ao programa utilizar arquivos binários para operar, recomendamos que não abra os arquivos pelo explorador de arquivos, mas somente pelo próprio programa.\n\n");
      printf("STATUS DA CONFIGURAÇÃO DO PROGRAMA:\n");

      //criando arquivo .bin
      arq_dados_album = fopen("dados_album.bin", "wb");
      if (arq_dados_album == NULL)
      {
         printf("Houve um erro de nossa parte ao criar o arquivo :(\n");
         exit(1);
      }
      else
      {
         //fechando arquivo
         fclose(arq_dados_album);
         
         printf("O arquivo necessário para salvar os dados do álbum foi criado com sucesso, e possui o nome de \"dados_album.bin\".\n");
         printf("Logo, todos os arquivos necessários foram criados com sucesso!\n\nVamos agora salvar os dados do proprietário, que... (um pouco de suspense)... é você!\n");
         
         //recebendo nome do proprietário
         printf("Comece inserindo seu nome: ");
         fgets(album->proprietario, 49, stdin);
         album->proprietario[strcspn(album->proprietario, "\n")] = '\0';
         limpa_buffer();
         
         //Explicando sobre o album
         printf("\nComo é bom poder colocar um rosto ... quero dizer, um nome, à este álbum! Seja bem-vindo(a), %s!\n\n", album->proprietario);
         printf("Antes de partir para a diversão, segue abaixo algumas informações que acho importante você saber:\n");
         printf("1º - Caso você não tenha percebido, isto é um jogo, onde você, proprietário, tem o objetivo de completar este álbum colando figurinhas da Copa do Mundo.\nEu espero, do fundo do meu coração (sou um programa mas tenho coração, ok?) que vocẽ saiba que está ocorrendo uma Copa no Catar. Se você não soubesse acharia estranho você estar aqui :\\ \n\n");
         printf("2º - Estas figurinhas vêm em pacotes com 5 figurinhas aleatórias, e para comprar cada pacote você deve desembolsar a bagatela de 4 moedas.\nNão se preocupe, você começa o jogo com 200 dessas moedas verdes ¯\\_(ツ)_/¯ e perde o jogo se acabar suas moedas e não conseguir completar o álbum. Vida difícil essa, não?\n\n");
         printf("3º - Dentro deste jogo há mini jogos, como Jogo da Memória e Forca, onde você pode ganhar mais moedas para continuar comprando pacotes. \n\n");
         printf("4º - Por último, acho importante você saber, mas não sei se isto é verdade: ouvi dizer que o vendedor de figurinhas gosta de passar a perna em seus clientes.\nEntão se liga, fica bem ligado(a)!\n\n");
         printf("Agora, sem mais delongas, que os jogos comecem! Boa sorte!\n\n");

         //alocando memoria dinamicamente 
         album->fig_coladas = (Figurinha *)calloc((album->posicao_no_album + 1), sizeof(Figurinha));
         album->fig_repetidas_ou_nao_coladas = (Figurinha *)calloc((album->posicao_repetidas_ou_nao_coladas + 1), sizeof(Figurinha));
         (*ptr_auxiliar) = 1;

         //dados iniciais do album
         album->moedas = 200;
         album->posicao_faltantes = 678;
         album->porcentagem_do_album = 0;
         album->dinheiro_gasto = 0;
      }
   }
   else
   {
      //SE já tiver dados salvos no hd
      if ((*ptr_auxiliar) == 0)
      {
         (*ptr_auxiliar) = 1;
         
         //lendo a struct nos dados do arquivo .bin
         fread(album, sizeof(Album), 1, arq_dados_album);

         //alocando memoria dinamicamente 
         album->fig_coladas = (Figurinha *)calloc((album->posicao_no_album + 1), sizeof(Figurinha));
         album->fig_repetidas_ou_nao_coladas = (Figurinha *)calloc((album->posicao_repetidas_ou_nao_coladas + 1), sizeof(Figurinha));

         //lendo os vetores de figurinhas salvos
         fread(album->fig_coladas, sizeof(Figurinha), album->posicao_no_album, arq_dados_album);
         fread(album->fig_repetidas_ou_nao_coladas, sizeof(Figurinha), album->posicao_repetidas_ou_nao_coladas, arq_dados_album);
         
         //fechando arquivo
         fclose(arq_dados_album);
        
      }

      printf("Bem-vindo(a) novamente %s. Por onde você deseja continuar?\n", album->proprietario);
   }
}

/**
 * @brief Salva os dados no hd
 * 
 * @param album 
 * @param ptr_auxiliar 
 */
void salvar_hd(Album *album, int *ptr_auxiliar)
{
   //abrindo arquivo .bin
   FILE *arq_dados_album2 = fopen("dados_album.bin", "wb");

   //escrevendo os dados no arquivo
   fwrite(album, sizeof(Album), 1, arq_dados_album2);
   fwrite(album->fig_coladas, sizeof(Figurinha), album->posicao_no_album, arq_dados_album2);
   fwrite(album->fig_repetidas_ou_nao_coladas, sizeof(Figurinha), album->posicao_repetidas_ou_nao_coladas, arq_dados_album2);
   fprintf(arq_dados_album2, "%s", album->fig_repetidas_ou_nao_coladas->titulo);
   (*ptr_auxiliar) = 0;

   //fechando arquivo
   fclose(arq_dados_album2);
  
}

/**
 * @brief Gera um arquivo .csv e escreve os dados do álbum nele
 * 
 * @param album 
 */
void exportar_dados(Album album){
   //criando arquivo
   FILE *arq;
   arq = fopen("dados.csv", "w");
   if(arq == NULL){
      printf("Erro ao abrir o arquivo!\n");
      exit(1);
   }
   //escrevendo os dados do album no arquivo .csv
   fprintf(arq, "Proprietario: %s\n",album.proprietario);
   fprintf(arq,"Dinheiro gasto: %d\n", album.dinheiro_gasto);
   fprintf(arq,"Porcentagem: %.2f\n", album.porcentagem_do_album);
   
   //escrevendo as figurinhas coladas 
   fprintf(arq, "Figurinhas coladas:\n");
   fprintf(arq,"Nro, Titulo, Secao, Tipo\n");
   for(int i = 0; i< album.posicao_no_album; i++){
      fprintf(arq, "%s,%s,%s,%s\n", album.fig_coladas[i].codigo,album.fig_coladas[i].titulo,album.fig_coladas[i].secao,album.fig_coladas[i].tipo);
   }

   //escrevendo as figurinhas repetidas ou não coladas
   fprintf(arq, "\nFigurinhas repetidas ou não coladas:\n");
   fprintf(arq,"Nro, Titulo, Secao, Tipo\n");
   for(int i = 0; i< album.posicao_repetidas_ou_nao_coladas; i++){
      if(strcasecmp(album.fig_repetidas_ou_nao_coladas[i].codigo,"00000")!=0){
         fprintf(arq, "%s,%s,%s,%s\n", album.fig_repetidas_ou_nao_coladas[i].codigo,album.fig_repetidas_ou_nao_coladas[i].titulo,album.fig_repetidas_ou_nao_coladas[i].secao,album.fig_repetidas_ou_nao_coladas[i].tipo);
      }
   }

   //fechando arquivo
   fclose(arq);
   
}
