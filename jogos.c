#include "album.h"

/**
 * @brief Jogo de forca com temátca de copa do mundo, retorna 3 moedas se vencer
 * 
 * @return int 
 */
int forca(){
   FILE* arq;
   char chute;
   char palavra[30];
   char chutes[30];
   int erros=0, completa=0, acertos=0, errado=0;
   int sorteio;
   int tamanho;

   //abrindo arquivo de palavras .txt
   arq= fopen("palavras_copa.txt", "r");
   if(arq==0){
      printf("Banco de dados não disponível\n");
      exit(1);
   }
   
   //sorteando palavra
   srand(time(NULL));
   sorteio=rand()%68+1;
   for(int i=0; i<=sorteio; i++){
      fscanf(arq, "%s", palavra);
   }
   //fechando arquivo
   fclose(arq);

   tamanho = strlen(palavra);

   //espaços da palavra
   for(int i=0; i<tamanho; i++){
      chutes[i]='_';
   }

   //desenhando a forca
   do{
      limpa_tela();;
      errado=0;
      printf("  _______       \n");
      printf(" |/      |      \n");
      printf(" |      %c%c%c  \n", (erros>=1?'(':' '), (erros>=1?'_':' '), (erros>=1?')':' '));
      printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), (erros>=2?'|':' '), (erros>=4?'/': ' '));
      printf(" |       %c     \n", (erros>=2?'|':' '));
      printf(" |      %c %c   \n", (erros>=5?'/':' '), (erros>=6?'\\':' '));
      printf(" |              \n");
      printf("_|___           \n");
      printf("\n\n"); 

      for(int i=0; i<tamanho; i++){
         printf("%c ", chutes[i]);
      }

      //recebendo chute
      printf("\n\n");
      scanf(" %c", &chute);
      limpa_buffer();

      chute=toupper(chute);

      //conferindo com a palavra
      for(int i=0; i<tamanho; i++){
         if(palavra[i]==chute){
            chutes[i]=chute;
            acertos++;
         }else{
            errado++;
         }

         if(errado==tamanho){
            erros++;
         }
         if(acertos==tamanho){
            completa=1;
         }
      }

   //máximo 6 erros
   }while(erros<7 && completa==0);

   //mensagem final
   if(completa){
      //retorna 3 de ganhar o jogo
      printf("\nParabéns!! Você acertou a palavra! :)\n");
      return 3;
   }else{
      printf("\nVocê perdeu! :(\nResposta: %s\n", palavra);
      return 0;
   }

}

/**
 * @brief Jogo da memória com temática de copa do mundo, retorna 5 moedas se vencer
 * 
 * @return int 
 */
int memoria(){
   FILE* arq;
   int numeros[5];
   int acertos=0;
   char opcao;
   char palavras[5][30], resposta[30];
   int sorteio;

   printf("Preparado?(s/n)\n");
   do{
      scanf("%c", &opcao);
      limpa_buffer();
   }while(opcao!='s' && opcao!='S');

   //abrindo arquivo
   arq=fopen("palavras_copa.txt", "r");
   if(arq==0){
    printf("Desculpe, banco de dados não disponível\n\n");
    exit(1);
   }

   srand(time(NULL));
   
   //sorteando 5 palavras do arquivo
   for(int i=0; i<5; i++){
      sorteio = rand()%68+1;
      numeros[i]=sorteio;

      for(int j=0; j<numeros[i]; j++){
         fscanf(arq, "%s", palavras[i]);

      }
      fscanf(arq, "%s", palavras[i]);
      rewind(arq);
   }

   fclose(arq);

   //exibindo palavras
   printf("Decore as palavras abaixo em 5s\n");
   for(int i=0; i<5; i++){
      printf("%s\n",palavras[i]);
   }

   //limpando a tela depois de 5 segundos
   tempo(5);
   limpa_tela();

   printf("Digite as palavras na ordem em que apareceram:\n");
   //recebendo respostas
   for(int i=0; i<5; i++){
      printf("Palavra %d: ", i+1);
      fgets(resposta, 29, stdin);
      resposta[strcspn(resposta, "\n")]='\0';
      limpa_buffer();
      if(strcasecmp(palavras[i],resposta)==0){
         acertos++;
      }
   }

   if(acertos==5){
      printf("\n\nParabéns, você acertou todas!!!!!\n\n");
      //retorna 5 de ganhar o jogo
      return 5;
   }else{
      printf("\n\nQue pena! :( Sua memória não é tão boa\n\n");
      printf("Respostas corretas:\n");
      for(int i=0; i<5; i++){
         printf("%s\n", palavras[i]);
      }
      return 0;
   }

}

/**
 * @brief Escolher o jogo e atualizar e número de moedas 
 * 
 * @param album 
 */
void ganhar_moedas(Album* album){
   int opcao;
   //menu
   printf("Selecione um jogo: \n");
   printf("\t1 - Jogo da Forca (Prêmio: 3 moedas)\n\t2 - Jogo da Memória (Prêmio: 5 moedas)\n\t"RED"0 - Voltar\n\t"reset);
   scanf("%d", &opcao);
   limpa_buffer();

   switch (opcao){
   case 0:
      break;
   case 1:
      //somando as moedas recebidas no final do jogo
      album->moedas = album->moedas + forca();
      break;
   case 2:
      //somando as moedas recebidas no final do jogo
      album->moedas = album->moedas + memoria();
      break;
   default:
      printf("Opção inválida!\n");
      break;
   }
}
