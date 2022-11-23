#include "header.h"

int forca(){
   FILE* f;
   char chute;
   char palavra[30];
   char chutes[30];
   int erros=0, completa=0, acertos=0, errado=0;
   int sorteio;
   int tamanho;

   f= fopen("palavras_copa.txt", "r");
   if(f==0){
      printf("Banco de dados não disponível\n");
      exit(1);
   }
   
   srand(time(NULL));
   sorteio=rand()%69;
   for(int i=0; i<=sorteio; i++){
      fscanf(f, "%s", palavra);
   }
   fclose(f);

   tamanho = strlen(palavra);

   for(int i=0; i<tamanho; i++){
      chutes[i]='_';
   }


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
      printf("\n\n");
      scanf(" %c", &chute);
      limpa_buffer();
      chute=toupper(chute);
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

   }while(erros<7 && completa==0);

   if(completa){
      printf("\nParabéns!! Você acertou a palavra! :)\n");
      return 3;
   }else{
      printf("\nVocê perdeu! :(\nResposta: %s\n", palavra);
      return 0;
   }

}

int memoria(){
   FILE* f;
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

   f=fopen("palavras_copa.txt", "r");
   if(f==0){
    printf("Desculpe, banco de dados não disponível\n\n");
    exit(1);
   }
   srand(time(NULL));
   
   for(int i=0; i<5; i++){
      sorteio = rand()%69;
      numeros[i]=sorteio;

      for(int j=0; j<numeros[i]; j++){
         fscanf(f, "%s", palavras[i]);

      }
      fscanf(f, "%s", palavras[i]);
      rewind(f);
   }

   fclose(f);

   printf("Decore as palavras abaixo em 5s\n");
   for(int i=0; i<5; i++){
      printf("%s\n",palavras[i]);
   }
   tempo();
   limpa_tela();;
   printf("Digite as palavras na ordem em que apareceram:\n");
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

void ganhar_moedas(int* moedas){
   int opcao;
   printf("Selecione um jogo: \n");
   printf("\t1 - Jogo da Forca (Prêmio: 3 moedas)\n\t2 - Jogo da Memória (Prêmio: 5 moedas)\n\t"RED"0 - Voltar\n\t"reset);
   scanf("%d", &opcao);
   limpa_buffer();
   switch (opcao){
   case 0:
      break;
   case 1:
      *moedas = *moedas + forca();
      break;
   case 2:
      *moedas = *moedas + memoria();
      break;
   default:
      printf("Opção inválida!\n");
      break;
   }
}
