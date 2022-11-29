#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>

//teclas
#define ESC 's'
#define DIREITA 'd'
#define ESQUERDA 'a'


//cores
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define reset "\e[0m"


typedef struct{
   char codigo[10];
   char titulo[40];
   char secao[40];
   char tipo[15];
}Figurinha;

typedef struct
{
    Figurinha *fig_coladas;
    Figurinha *fig_faltantes;
    Figurinha *fig_repetidas_ou_nao_coladas;
    //Figurinha *fig_disponiveis;
    int quant_fig;
    int posicao_no_album;
    int posicao_repetidas_ou_nao_coladas;
    int posicao_faltantes;
    char proprietario[50];
    int moedas;
    float porcentagem_do_album;
    int dinheiro_gasto;
    int contador_figurinha;
} Album;

void limpa_tela(){
   #ifdef linux
      system("clear");
   #elif _WIN64
      system("clc");
   #else

   #endif
   
}
void limpa_buffer(){
   #ifdef linux
      __fpurge(stdin);
   #elif _WIN64
      setbuf(stdin,NULL);
   #else

   #endif
}
void tempo(){
   #ifdef linux
      usleep(5000000);
   #elif _WIN64
      Sleep(5000);
   #else

   #endif
}


void mostra(Figurinha* figurinha, Album album, int total, char secao[]){
   int quantidade=0;
   int auxiliar=0;
   for(int i=1; i<total; i++){
      quantidade=0;
      if(strcasecmp(figurinha[i].secao, secao)==0){
         
         for(int j=0; j<album.posicao_no_album; j++){
         if(strcasecmp(album.fig_coladas[j].codigo,figurinha[i].codigo)==0){
            quantidade=1;
         }
         }//for2
      if(quantidade==0){
            printf(RED);
      }else{
            printf(GRN);           
      }//else
         
         printf("%40s\t", figurinha[i].titulo);
         auxiliar++;
         if(auxiliar%3==0){
         printf("\n");
      }


         printf(reset);  
      
      
      }//if
      
   }//for
   printf("\n");
}
void capa(){

   printf(reset);
  printf("                           @@@&@@@@@%%%%%%%%%%@@@#\n");
   printf("                        /@@&@@@@@@@&%%@@@@@@@&&%%@\n");
   printf("                       @@@@@@@@@%%%%###%%%%%%%%%%%%%%%%%%%%%%%% \n");
   printf("                     @&@@@@%%@@       #%%%%%%%%%%%%%%%%%%%%%%@\n");
   printf("                    @@,%%@%%,@          %%%%%%%%#%%%%%%%%%%@@\n");
   printf("                   @@@@@@%%@            ##%%%%#%%%%%%%%@@\n");
   printf("                   @@@@&@%%@@           ##%%%%#%%%%%%%%@@\n");
   printf("                    @@@%%@%%@@           ##%%%%#%%%%%%%%@@\n");
   printf("                     @&@@@@@@@         ###%%#%%%%%%%%@@\n");
   printf("                      @&@&@%%@%%@        ##%%##%%%%%%@@\n");
   printf("                       @&&@@%%@@@      #####%%%%%%@@\n");
   printf("                        &&&@@@@@@   ###(#%%%%%%@@\n");
   printf("                          @@@@@@@@@####((%%%%%%@\n");
   printf("                           @&@@@@@@@@#((#%%&@\n");
   printf("                           %% @@@@@@@@@###&@ \n");
   printf("                           %%   @&@@@@@@@@&\n");
   printf("                              @@&@@@/,@@&\n");
   printf("                              @(((@@@,@@,@, \n");
   printf("                            @#((((@@@@&,,,@,\n");
   printf("                           @@(((((@@,@,@@#@@,\n");
   printf("                          @#((((((@@@,/&,@@@@ \n");
   printf("                         @@(((((((@&@@@@(@,,(@ \n");
   printf("                         @#(((((((@@@@@&&@@@@@\n");
   printf("                          @@#(((((@@@@@*,,@@@@@ \n");
   printf("                           %%@@@@@@,@@@,&,@@@@@\n");
   printf("                              %%@@@,&*,*&@@&& \n");
   

   printf(WHT" _____   ___   _____      _       __        __   ___    ____    _       ____       ____   _   _   ____  \n");
   printf("|  ___| |_ _| |  ___|    / \\      \\ \\      / /  / _ \\  |  _ \\  | |     |  _ \\     / ___| | | | | |  _ \\ \n");
   printf("| |_     | |  | |_      / _ \\      \\ \\ /\\ / /  | | | | | |_) | | |     | | | |   | |     | | | | | |_) |\n");
   printf("|  _|    | |  |  _|    / ___ \\      \\ V  V /   | |_| | |  _ <  | |___  | |_| |   | |___  | |_| | |  __/\n");
   printf("|_|     |___| |_|     /_/   \\_\\      \\_/\\_/     \\___/  |_| \\_\\ |_____| |____/     \\____|  \\___/  |_|    \n");
}

void folhear_album(Figurinha* figurinha, Album album, int quant_fig){
  
  char tecla;
   int pagina=0;

   capa();
   printf(reset"<- (a)                 (d) ->         (s) Sair\n");


   do{
      
      scanf("%c", &tecla);
      limpa_buffer();

      if(tecla==ESQUERDA){
         pagina--;
      }
      if(tecla==DIREITA){
         pagina++;
      }
      if(pagina<0){
         pagina=0;
      }
      if(pagina>36){
         pagina=36;
      }
      switch(pagina){
         case 0:
            limpa_tela();
            capa();
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 1:
            limpa_tela();
            printf(MAG" ___    _         ___    _____  _      _____  ___       ___    _____     ___    _____  ___    _____ \n");
            printf("(  _`\\ (_)/'\\_/`\\(  _`\\ (  _  )( )    (  _  )(  _`\\    (  _`\\ (  _  )   (  _`\\ (  _  )(  _`\\ (  _  )\n"); 
            printf("| (_(_)| ||     || (_) )| ( ) || |    | ( ) || (_(_)   | | ) || (_) |   | ( (_)| ( ) || |_) )| (_) |\n");
            printf(WHT"`\\__ \\ | || (_) ||  _ <'| | | || |  _ | | | |`\\__ \\    | | | )|  _  |   | |  _ | | | || ,__/'|  _  |\n");
            printf("( )_) || || | | || (_) )| (_) || |_( )| (_) |( )_) |   | |_) || | | |   | (_( )| (_) || |    | | | |\n");
            printf("`\\____)(_)(_) (_)(____/'(_____)(____/'(_____)`\\____)   (____/'(_) (_)   (____/'(_____)(_)    (_) (_)\n"reset);

            mostra(figurinha, album, quant_fig, "Content");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 2:
            limpa_tela();
            printf(GRN" ___    ___    _____  _____  ___    _  _____  ___       ___       ___    _____  _      _____\n");
            printf("(  _`\\ (  _`\\ (_   _)(  _  )(  _`\\ (_)(  _  )(  _`\\    (  _`\\    (  _`\\ (  _  )( )    (  _  )\n");
            printf("| (_(_)| (_(_)  | |  | (_) || | ) || || ( ) || (_(_)   | (_(_)   | (_) )| ( ) || |    | (_) |\n");
            printf(WHT"|  _)_ `\\__ \\   | |  |  _  || | | )| || | | |`\\__ \\    |  _)_    |  _ <'| | | || |  _ |  _  |\n");
            printf("| (_( )( )_) |  | |  | | | || |_) || || (_) |( )_) |   | (_( )   | (_) )| (_) || |_( )| | | |\n");
            printf("(____/'`\\____)  (_)  (_) (_)(____/'(_)(_____)`\\____)   (____/'   (____/'(_____)(____/'(_) (_)\n"reset);
            
            mostra(figurinha, album, quant_fig, "Stadiums");
            mostra(figurinha, album, quant_fig, "Official Match Ball");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 3:
            limpa_tela();
            printf(WHT" _____  _____  _____  _____  ___\n");
            printf("(  _  )(  _  )(_   _)(  _  )|  _`\\\n");
            printf("| ( ) || (_) |  | |  | (_) || (_) )\n");
            printf(MAG"| | | ||  _  |  | |  |  _  || ,  /\n");
            printf("| (('\\|| | | |  | |  | | | || |\\ \\\n");
            printf("(___\\_)(_) (_)  (_)  (_) (_)(_) (_)\n"reset);   
            
            mostra(figurinha, album, quant_fig, "Qatar");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 4:
            limpa_tela();
            printf(YEL" ___    _____  _   _  _____  ___    _____  ___  \n");
            printf("(  _`\\ (  _  )( ) ( )(  _  )(  _`\\ (  _  )|  _`\\ \n");
            printf(BLU"| (_(_)| ( ) || | | || (_) || | ) || ( ) || (_) )\n");
            printf("|  _)_ | | | || | | ||  _  || | | )| | | || ,  / \n");
            printf(RED"| (_( )| (('\\|| (_) || | | || |_) || (_) || |\\ \\ \n");
            printf("(____/'(___\\_)(_____)(_) (_)(____/'(_____)(_) (_)\n"reset);                                               
                                                         
            mostra(figurinha, album, quant_fig, "Ecuador");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 5:
            limpa_tela();
            printf(GRN" ___    ___    _   _  ___    ___    _____  _\n");
            printf("(  _`\\ (  _`\\ ( ) ( )(  _`\\ (  _`\\ (  _  )( )\n");
            printf(YEL"| (_(_)| (_(_)| `\\| || (_(_)| ( (_)| (_) || |\n");
            printf("`\\__ \\ |  _)_ | , ` ||  _)_ | |___ |  _  || |  _ \n");
            printf(RED"( )_) || (_( )| |`\\ || (_( )| (_, )| | | || |_( )\n");
            printf("`\\____)(____/'(_) (_)(____/'(____/'(_) (_)(____/'\n"reset);

            mostra(figurinha, album, quant_fig, "Senegal");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 6:
            limpa_tela();
            printf(RED" _   _  _____  _      _____  _   _  ___    _____ \n");
            printf("( ) ( )(  _  )( )    (  _  )( ) ( )(  _`\\ (  _  )\n");
            printf(WHT"| |_| || ( ) || |    | (_) || `\\| || | ) || (_) |\n");
            printf("|  _  || | | || |  _ |  _  || , ` || | | )|  _  |\n");
            printf(BLU"| | | || (_) || |_( )| | | || |`\\ || |_) || | | |\n");
            printf("(_) (_)(_____)(____/'(_) (_)(_) (_)(____/'(_) (_)\n"reset);                                              
                                                         
            mostra(figurinha, album, quant_fig, "Netherlands");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 7:
            limpa_tela();
            printf(RED" _  _   _  ___    _      _____  _____  ___    ___    ___    _____ \n");
            printf("(_)( ) ( )(  _`\\ ( )    (  _  )(_   _)(  _`\\ |  _`\\ |  _`\\ (  _  )\n");
            printf("| || `\\| || ( (_)| |    | (_) |  | |  | (_(_)| (_) )| (_) )| (_) |\\\n");
            printf(WHT"| || , ` || |___ | |  _ |  _  |  | |  |  _)_ | ,  / | ,  / |  _  |\n");
            printf("| || |`\\ || (_, )| |_( )| | | |  | |  | (_( )| |\\ \\ | |\\ \\ | | | |\n");
            printf("(_)(_) (_)(____/'(____/'(_) (_)  (_)  (____/'(_) (_)(_) (_)(_) (_)\n"reset);

            mostra(figurinha, album, quant_fig, "England");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 8:
            limpa_tela();
            printf(GRN"            _   _ \n");
            printf("         /' \\/' )\n");
            printf("         (_/\\__/' \n\n");
            printf(WHT" _  ___    _____\n");
            printf("(_)|  _`\\ (  _  )\n");
            printf("| || (_) )| (_) |\n");
            printf(RED"| || ,  / |  _  |\n");
            printf("| || |\\ \\ | | | |\n");
            printf("(_)(_) (_)(_) (_)\n"reset);

            mostra(figurinha, album, quant_fig, "Iran");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 9:
            limpa_tela();
            printf(BLU" _   _  ___    _____ \n");
            printf("( ) ( )(  _`\\ (  _  )\n");
            printf(RED"| | | || (_(_)| (_) |\n");
            printf("| | | |`\\__ \\ |  _  |\n");
            printf(WHT"| (_) |( )_) || | | |\n");
            printf("(_____)`\\____)(_) (_)\n"reset);
                              
            mostra(figurinha, album, quant_fig, "USA");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 10:
            limpa_tela();
            printf(WHT" ___    _____  _  ___       ___    ___       ___    _____  _      ___    ___   \n");
            printf("(  _`\\ (  _  )(_)(  _`\\    (  _`\\ (  _`\\    (  _`\\ (  _  )( )    (  _`\\ (  _`\\ \n");
            printf(RED"| |_) )| (_) || || (_(_)   | | ) || (_(_)   | ( (_)| (_) || |    | (_(_)| (_(_)\n");
            printf("| ,__/'|  _  || |`\\__ \\    | | | )|  _)_    | |___ |  _  || |  _ |  _)_ `\\__ \\ \n");
            printf(GRN"| |    | | | || |( )_) |   | |_) || (_( )   | (_, )| | | || |_( )| (_( )( )_) |\n");
            printf("(_)    (_) (_)(_)`\\____)   (____/'(____/'   (____/'(_) (_)(____/'(____/'`\\____)\n"reset);

            mostra(figurinha, album, quant_fig, "Wales");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 11:
            limpa_tela();
            printf(BLU" _____  ___    ___    ___    _   _  _____  _  _   _  _____ \n");
            printf("(  _  )|  _`\\ (  _`\\ (  _`\\ ( ) ( )(_   _)(_)( ) ( )(  _  )\n");
            printf("| (_) || (_) )| ( (_)| (_(_)| `\\| |  | |  | || `\\| || (_) |\n");
            printf(WHT"|  _  || ,  / | |___ |  _)_ | , ` |  | |  | || , ` ||  _  |\n");
            printf("| | | || |\\ \\ | (_, )| (_( )| |`\\ |  | |  | || |`\\ || | | |\n");
            printf("(_) (_)(_) (_)(____/'(____/'(_) (_)  (_)  (_)(_) (_)(_) (_)\n"reset);
                                                                  
            mostra(figurinha, album, quant_fig, "Argentina");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 12:
            limpa_tela();
            printf(GRN" _____  ___    _____  ___    _  _____     ___    _____  _   _  ___    _  _____  _____ \n");
            printf("(  _  )|  _`\\ (  _  )(  _`\\ (_)(  _  )   (  _`\\ (  _  )( ) ( )(  _`\\ (_)(_   _)(  _  )\n");
            printf("| (_) || (_) )| (_) || (_) )| || (_) |   | (_(_)| (_) || | | || | ) || |  | |  | (_) |\n");
            printf(WHT"|  _  || ,  / |  _  ||  _ <'| ||  _  |   `\\__ \\ |  _  || | | || | | )| |  | |  |  _  |\n");
            printf("| | | || |\\ \\ | | | || (_) )| || | | |   ( )_) || | | || (_) || |_) || |  | |  | | | |\n");
            printf("(_) (_)(_) (_)(_) (_)(____/'(_)(_) (_)   `\\____)(_) (_)(_____)(____/'(_)  (_)  (_) (_)\n"reset);

            mostra(figurinha, album, quant_fig, "Saudi Arabia");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 13:
            limpa_tela();
            printf(GRN"           __  \n");
            printf("          /_/ \n\n");
            printf("        ___    _    _  _  ___    _____ \n");
            printf(WHT"/'\\_/`\\(  _`\\ ( )  ( )(_)(  _`\\ (  _  )\n");
            printf("|     || (_(_)`\\`\\/'/'| || ( (_)| ( ) |\n");
            printf(RED"| (_) ||  _)_   >  <  | || |  _ | | | |\n");
            printf("| | | || (_( ) /'/\\`\\ | || (_( )| (_) |\n");
            printf("(_) (_)(____/'(_)  (_)(_)(____/'(_____)\n"reset);
                                                
            mostra(figurinha, album, quant_fig, "Mexico");

            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 14:
            limpa_tela();
            printf(WHT"                       __  \n");
            printf("                      /  \\ \n");
            printf("                     (_/\\_) \n\n");
            printf(" ___    _____  _      _____  _   _  _  _____ \n");
            printf("(  _`\\ (  _  )( )    (  _  )( ) ( )(_)(  _  )\n");
            printf(RED"| |_) )| ( ) || |    | ( ) || `\\| || || (_) |\n");
            printf("| ,__/'| | | || |  _ | | | || , ` || ||  _  |\n");
            printf("| |    | (_) || |_( )| (_) || |`\\ || || | | |\n");              
            printf("(_)    (_____)(____/'(_____)(_) (_)(_)(_) (_)\n"reset);                                           
                                                      
            mostra(figurinha, album, quant_fig, "Poland");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 15:
            limpa_tela();
            printf(BLU" ___    ___    _____  _   _  ___    _____ \n");
            printf("(  _`\\ |  _`\\ (  _  )( ) ( )(  _`\\ (  _  )\n");
            printf("| (_(_)| (_) )| (_) || `\\| || ( (_)| (_) |\n");
            printf(WHT"|  _)  | ,  / |  _  || , ` || |  _ |  _  |\n");
            printf("| |    | |\\ \\ | | | || |`\\ || (_( )| | | |\n");
            printf(RED"(_)    (_) (_)(_) (_)(_) (_)(____/'(_) (_)\n");
            printf("                              \\__, \\\n");
            printf("                              (____/  \n"reset);

            mostra(figurinha, album, quant_fig, "France");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 16:
            limpa_tela();
            printf(WHT"                                        __\n");
            printf("                                       /_/\n\n");
            printf(" _____  _   _  ___    _____  ___    _____  _      _  _____ \n");
            printf(BLU"(  _  )( ) ( )(  _`\\ (_   _)|  _`\\ (  _  )( )    (_)(  _  )\n");
            printf("| (_) || | | || (_(_)  | |  | (_) )| (_) || |    | || (_) |\n");
            printf("|  _  || | | |`\\__ \\   | |  | ,  / |  _  || |  _ | ||  _  |\n");
            printf(RED"| | | || (_) |( )_) |  | |  | |\\ \\ | | | || |_( )| || | | |\n");
            printf("(_) (_)(_____)`\\____)  (_)  (_) (_)(_) (_)(____/'(_)(_) (_)\n"reset);

            mostra(figurinha, album, quant_fig, "Australia");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 17:
            limpa_tela();
            printf(WHT" ___    _  _   _  _____         _____  ___    ___    _____ \n");
            printf("(  _`\\ (_)( ) ( )(  _  )/'\\_/`\\(  _  )|  _`\\ (  _`\\ (  _  )\n");
            printf(RED"| | ) || || `\\| || (_) ||     || (_) || (_) )| ( (_)| (_) |\n");
            printf("| | | )| || , ` ||  _  || (_) ||  _  || ,  / | |  _ |  _  |\n");
            printf("| |_) || || |`\\ || | | || | | || | | || |\\ \\ | (_( )| | | |\n");
            printf("(____/'(_)(_) (_)(_) (_)(_) (_)(_) (_)(_) (_)(____/'(_) (_)\n"reset);

            mostra(figurinha, album, quant_fig, "Denmark");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 18:
            limpa_tela();
            printf(RED"                      __  \n");
            printf("                     /_/\n\n");
            printf(" _____  _   _  _   _  _  ___    _  _____ \n");
            printf("(_   _)( ) ( )( ) ( )(_)(  _`\\ (_)(  _  )\n");
            printf("  | |  | | | || `\\| || || (_(_)| || (_) |\n");
            printf("  | |  | | | || , ` || |`\\__ \\ | ||  _  |\n");
            printf(WHT"  | |  | (_) || |`\\ || |( )_) || || | | |\n");
            printf("  (_)  (_____)(_) (_)(_)`\\____)(_)(_) (_)\n"reset);
                                             
            mostra(figurinha, album, quant_fig, "Tunisia");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 19:
            limpa_tela();
            printf(RED" ___    ___    ___    _____  _   _  _   _  _____ \n");
            printf("(  _`\\ (  _`\\ (  _`\\ (  _  )( ) ( )( ) ( )(  _  )\n");
            printf("| (_(_)| (_(_)| |_) )| (_) || `\\| || |_| || (_) |\n");
            printf(YEL"|  _)_ `\\__ \\ | ,__/'|  _  || , ` ||  _  ||  _  |\n");
            printf("| (_( )( )_) || |    | | | || |`\\ || | | || | | |\n");
            printf("(____/'`\\____)(_)    (_) (_)(_) (_)(_) (_)(_) (_)\n"reset);

         mostra(figurinha, album, quant_fig, "Spain");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 20:
            limpa_tela();
            printf(BLU" ___    _____  ___    _____  _____     ___    _  ___    _____ \n");
            printf("(  _`\\ (  _  )(  _`\\ (_   _)(  _  )   |  _`\\ (_)(  _`\\ (  _  )\n");
            printf(WHT"| ( (_)| ( ) || (_(_)  | |  | (_) |   | (_) )| || ( (_)| (_) |\n");
            printf("| |  _ | | | |`\\__ \\   | |  |  _  |   | ,  / | || |  _ |  _  |\n");
            printf(RED"| (_( )| (_) |( )_) |  | |  | | | |   | |\\ \\ | || (_( )| | | |\n");
            printf("(____/'(_____)`\\____)  (_)  (_) (_)   (_) (_)(_)(____/'(_) (_)\n"reset);

            mostra(figurinha, album, quant_fig, "Costa Rica");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 21:
            limpa_tela();
            printf(BLK" _____  _      ___           _____  _   _  _   _  _____ \n");
            printf("(  _  )( )    (  _`\\ /'\\_/`\\(  _  )( ) ( )( ) ( )(  _  )\n");
            printf(RED"| (_) || |    | (_(_)|     || (_) || `\\| || |_| || (_) |\n");
            printf("|  _  || |  _ |  _)_ | (_) ||  _  || , ` ||  _  ||  _  |\n");
            printf(YEL"| | | || |_( )| (_( )| | | || | | || |`\\ || | | || | | |\n");
            printf("(_) (_)(____/'(____/'(_) (_)(_) (_)(_) (_)(_) (_)(_) (_)\n"reset);

            mostra(figurinha, album, quant_fig, "Germany");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 22:
            limpa_tela();
            printf(WHT"                        _   _ \n");
            printf("                      /' \\/' )\n");
            printf("                     (_/\\__/' \n\n");
            printf(" _____  _____  ___    _____  _____ \n");
            printf("(___  )(  _  )(  _`\\ (  _  )(  _  )\n");
            printf(RED"    | || (_) || |_) )| (_) || ( ) |\n");
            printf(" _  | ||  _  || ,__/'|  _  || | | |\n");
            printf("( )_| || | | || |    | | | || (_) |\n");
            printf("`\\___/'(_) (_)(_)    (_) (_)(_____)\n"reset);

            mostra(figurinha, album, quant_fig, "Japan");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 23:
            limpa_tela();
            printf(BLK"          __  \n");
            printf("         /_/\n\n");
            printf(" ___    ___    _      ___    _  ___    _____ \n");
            printf("(  _`\\ (  _`\\ ( )    (  _`\\ (_)(  _`\\ (  _  )\n");
            printf(YEL"| (_) )| (_(_)| |    | ( (_)| || ( (_)| (_) |\n");
            printf("|  _ <'|  _)_ | |  _ | |___ | || |  _ |  _  |\n");
            printf(RED"| (_) )| (_( )| |_( )| (_, )| || (_( )| | | |\n");
            printf("(____/'(____/'(____/'(____/'(_)(____/'(_) (_)\n"reset);

            mostra(figurinha, album, quant_fig, "Belgium");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 24:
            limpa_tela();
            printf(WHT"                                      __  \n");
            printf("                                     /_/\n\n");
            printf(" ___    _____  _   _  _____  ___    _____ \n");
            printf("(  _`\\ (  _  )( ) ( )(  _  )(  _`\\ (  _  )\n");
            printf("| ( (_)| (_) || `\\| || (_) || | ) || (_) |\n");
            printf(RED"| |  _ |  _  || , ` ||  _  || | | )|  _  |\n");
            printf("| (_( )| | | || |`\\ || | | || |_) || | | |\n");
            printf("(____/'(_) (_)(_) (_)(_) (_)(____/'(_) (_)\n"reset);                                       
                                             
            mostra(figurinha, album, quant_fig, "Canada");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 25:
            limpa_tela();
            printf(RED"        _____  ___    ___    _____  ___    _____  ___   \n");
            printf("/'\\_/`\\(  _  )|  _`\\ |  _`\\ (  _  )(  _`\\ (  _  )(  _`\\ \n");
            printf("|     || (_) || (_) )| (_) )| ( ) || ( (_)| ( ) || (_(_)\n");
            printf("| (_) ||  _  || ,  / | ,  / | | | || |  _ | | | |`\\__ \\ \n");
            printf(GRN"| | | || | | || |\\ \\ | |\\ \\ | (_) || (_( )| (_) |( )_) |\n");
            printf("(_) (_)(_) (_)(_) (_)(_) (_)(_____)(____/'(_____)`\\____)\n"reset);

            mostra(figurinha, album, quant_fig, "Morocco");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 26:
            limpa_tela();
            printf(RED"                         __  \n");
            printf("                        /_/\n\n");
            printf(" ___    ___    _____  _____  ___    _  _____\n");
            printf("(  _`\\ |  _`\\ (  _  )(  _  )(  _`\\ (_)(  _  )\n");
            printf(WHT"| ( (_)| (_) )| ( ) || (_) || ( (_)| || (_) |\n");
            printf("| |  _ | ,  / | | | ||  _  || |  _ | ||  _  |\n");
            printf(BLU"| (_( )| |\\ \\ | (_) || | | || (_( )| || | | |\n");
            printf("(____/'(_) (_)(_____)(_) (_)(____/'(_)(_) (_)\n"reset);

            mostra(figurinha, album, quant_fig, "Croatia");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 27:
            limpa_tela();
            printf(GRN" ___    ___    _____  ___    _  _   \n");
            printf("(  _`\\ |  _`\\ (  _  )(  _`\\ (_)( ) \n");
            printf("| (_) )| (_) )| (_) || (_(_)| || |  \n");
            printf(YEL"|  _ <'| ,  / |  _  |`\\__ \\ | || |  _ \n");
            printf("| (_) )| |\\ \\ | | | |( )_) || || |_( )\n");
            printf("(____/'(_) (_)(_) (_)`\\____)(_)(____/'\n"reset);

            mostra(figurinha, album, quant_fig, "Brazil");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 28:
            limpa_tela();
            printf(RED"          __  \n");
            printf("         /_/\n");
            printf(BLU" ___    ___    ___    _   _  _  _____ \n");
            printf("(  _`\\ (  _`\\ |  _`\\ ( ) ( )(_)(  _  )\n");
            printf("| (_(_)| (_(_)| (_) )| | | || || (_) |\n");
            printf("`\\__ \\ |  _)_ | ,  / | | | || ||  _  |\n");
            printf(WHT"( )_) || (_( )| |\\ \\ | \\_/ || || | | |\n");
            printf("`\\____)(____/'(_) (_)`\\___/'(_)(_) (_)\n"reset);
            

            mostra(figurinha, album, quant_fig, "Serbia");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 29:
            limpa_tela();
            printf(WHT"                __  \n");
            printf("               /_/\n\n");
            printf(" ___    _   _  _  ___    _____ \n");
            printf("(  _`\\ ( ) ( )(_)(  _`\\ (  _  )\n");
            printf("| (_(_)| | | || || ( (_)| (_) |\n");
            printf(RED"`\\__ \\ | | | || || |  _ |  _  |\n");
            printf("( )_) || (_) || || (_( )| | | |\n");
            printf("`\\____)(_____)(_)(____/'(_) (_)\n");
            printf("                  \\__, \\\n");
            printf("                  (____/\n"reset);

            mostra(figurinha, album, quant_fig, "Switzerland");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 30:
            limpa_tela();
            printf(GRN"                                       _   _ \n");
            printf("                                     /' \\/' )\n");
            printf("                                    (_/\\__/'\n");
            printf(RED" ___    _____         _____  ___    _____  ___    ___  \n");
            printf("(  _`\\ (  _  )/'\\_/`\\(  _  )|  _`\\ (  _  )(  _`\\ (  _`\\ \n");
            printf("| ( (_)| (_) ||     || (_) || (_) )| ( ) || (_(_)| (_(_)\n");
            printf(YEL"| |  _ |  _  || (_) ||  _  || ,  / | | | ||  _)_ `\\__ \\ \n");
            printf("| (_( )| | | || | | || | | || |\\ \\ | (_) || (_( )( )_) |\n");
            printf("(____/'(_) (_)(_) (_)(_) (_)(_) (_)(_____)(____/'`\\____) \n"reset);

            mostra(figurinha, album, quant_fig, "Cameroon");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 31:
            limpa_tela();
            printf(GRN" ___    _____  ___    _____  _   _  ___    _____  _  \n");
            printf("(  _`\\ (  _  )|  _`\\ (_   _)( ) ( )(  _`\\ (  _  )( ) \n");
            printf("| |_) )| ( ) || (_) )  | |  | | | || ( (_)| (_) || | \n");
            printf(RED"| ,__/'| | | || ,  /   | |  | | | || |___ |  _  || |  _\n");
            printf("| |    | (_) || |\\ \\   | |  | (_) || (_, )| | | || |_( )\n");
            printf("(_)    (_____)(_) (_)  (_)  (_____)(____/'(_) (_)(____/'\n"reset);                                                     

            mostra(figurinha, album,  quant_fig, "Portugal");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 32:
            limpa_tela();
            printf(RED" ___    _____  _   _  _____ \n");
            printf("(  _`\\ (  _  )( ) ( )(  _  )\n");
            printf(YEL"| ( (_)| (_) || `\\| || (_) |\n");
            printf("| |___ |  _  || , ` ||  _  |\n");
            printf(GRN"| (_, )| | | || |`\\ || | | |\n");
            printf("(____/'(_) (_)(_) (_)(_) (_)\n"reset);                          

            mostra(figurinha, album, quant_fig, "Ghana");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 33:
            limpa_tela();
            printf(WHT" _   _  ___    _   _  ___    _   _  _____  _ \n");
            printf("( ) ( )|  _`\\ ( ) ( )(  _`\\ ( ) ( )(  _  )(_)\n");
            printf("| | | || (_) )| | | || ( (_)| | | || (_) || |\n");
            printf(BLU"| | | || ,  / | | | || |___ | | | ||  _  || |\n");
            printf("| (_) || |\\ \\ | (_) || (_, )| (_) || | | || |\n");
            printf("(_____)(_) (_)(_____)(____/'(_____)(_) (_)(_)\n"reset);

            mostra(figurinha, album, quant_fig, "Uruguay");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 34:
            limpa_tela();
            printf(WHT" ___    _____  ___    ___    _  _____     ___    _____     ___    _   _  _ \n");
            printf("(  _`\\ (  _  )|  _`\\ (  _`\\ (_)(  _  )   (  _`\\ (  _  )   (  _`\\ ( ) ( )( )    \n");
            printf(RED"| ( (_)| ( ) || (_) )| (_(_)| || (_) |   | | ) || ( ) |   | (_(_)| | | || |    \n");
            printf("| |  _ | | | || ,  / |  _)_ | ||  _  |   | | | )| | | |   `\\__ \\ | | | || |  _ \n");
            printf(BLU"| (_( )| (_) || |\\ \\ | (_( )| || | | |   | |_) || (_) |   ( )_) || (_) || |_( )\n");
            printf("(____/'(_____)(_) (_)(____/'(_)(_) (_)   (____/'(_____)   `\\____)(_____)(____/'\n"reset);
            
            mostra(figurinha, album, quant_fig, "Korea Republic");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 35:
            limpa_tela();
            printf(WHT"        _   _  ___    ___    _   _     ___    _____     ___    _  ___    _____ \n");
            printf("/'\\_/`\\( ) ( )(  _`\\ (  _`\\ ( ) ( )   (  _`\\ (  _  )   (  _`\\ (_)(  _`\\ (  _  )\n");
            printf("|     || | | || (_(_)| (_(_)| | | |   | | ) || (_) |   | (_(_)| || (_(_)| (_) |\n");
            printf("| (_) || | | |`\\__ \\ |  _)_ | | | |   | | | )|  _  |   |  _)  | ||  _)  |  _  |\n");
            printf("| | | || (_) |( )_) || (_( )| (_) |   | |_) || | | |   | |    | || |    | | | |\n");
            printf("(_) (_)(_____)`\\____)(____/'(_____)   (____/'(_) (_)   (_)    (_)(_)    (_) (_)\n"reset);
                                                                                 
            mostra(figurinha, album, quant_fig, "FIFA Museum");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 36:
            limpa_tela();
            printf(RED" ___    _____  ___    _____          ___    _____  _      _____ \n");
            printf("(  _`\\ (  _  )(  _`\\ (  _  )        (  _`\\ (  _  )( )    (  _  )\n");
            printf("| ( (_)| ( ) || ( (_)| (_) | ______ | ( (_)| ( ) || |    | (_) |\n");
            printf("| |  _ | | | || |  _ |  _  |(______)| |  _ | | | || |  _ |  _  |\n");
            printf("| (_( )| (_) || (_( )| | | |        | (_( )| (_) || |_( )| | | |\n");
            printf("(____/'(_____)(____/'(_) (_)        (____/'(_____)(____/'(_) (_)\n"reset);  
                                                                        
            mostra(figurinha, album, quant_fig, "Coca-Cola Team Believers");
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;


      }

   }while(tecla!=ESC);

   limpa_tela();

}

void dados_album(Album album, int quant_fig){
  printf("Nome do proprietario do album:\t%s\n",album.proprietario);
  printf("Total de figurinhas coladas:\t%d\n", album.contador_figurinha);
  printf("Total de figurinhas faltantes:\t%d\n", quant_fig - album.contador_figurinha);
  printf("Porcentagem de conclusao do album:\t%f%%\n", album.porcentagem_do_album);
  printf("Total gasto com envelopes:\t%d\n", album.dinheiro_gasto);

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
        int num = rand() % 678 + 1; // gerar um numero
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


void figurinhas_repetidas_ou_nao_coladas(Album *album){
   printf("| Codigo    | Titulo                                  | Secao                                   | Tipo           |\n");

   for(int i=0; i<album->posicao_repetidas_ou_nao_coladas; i++){
      if(strcasecmp(album->fig_repetidas_ou_nao_coladas[i].codigo,"00000")!=0){
         printf("| %-9s | %-39s | %-39s | %-14s |\n", album->fig_repetidas_ou_nao_coladas[i].codigo,album->fig_repetidas_ou_nao_coladas[i].titulo,album->fig_repetidas_ou_nao_coladas[i].secao,album->fig_repetidas_ou_nao_coladas[i].tipo);
      }  
   }
   /*Dar a opção para colar no album, conferir se já não está colada e depois organizar a struct*/

}

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
   sorteio=rand()%68+1;
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
      sorteio = rand()%68+1;
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

void ganhar_moedas(Album* album){
   int opcao;
   printf("Selecione um jogo: \n");
   printf("\t1 - Jogo da Forca (Prêmio: 3 moedas)\n\t2 - Jogo da Memória (Prêmio: 5 moedas)\n\t"RED"0 - Voltar\n\t"reset);
   scanf("%d", &opcao);
   limpa_buffer();
   switch (opcao){
   case 0:
      break;
   case 1:
      album->moedas = album->moedas + forca();
      break;
   case 2:
      album->moedas = album->moedas + memoria();
      break;
   default:
      printf("Opção inválida!\n");
      break;
   }
}

void trocar_figurinha(char repetida[], Figurinha* figurinha, Album* album){
   int probabilidade;
   int sorteio;
   srand(time(0));
   probabilidade = rand()%10;
   
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

   if(probabilidade>0 && probabilidade<=3){
      printf(YEL"O dono da banca fugiu! Bem-vindo à Apucarana\n"reset);
      if(album->posicao_repetidas_ou_nao_coladas>1){
         album->posicao_repetidas_ou_nao_coladas--;
      }
      if (album->posicao_repetidas_ou_nao_coladas > 0)
      {
         album->fig_repetidas_ou_nao_coladas = realloc(album->fig_repetidas_ou_nao_coladas, (album->posicao_repetidas_ou_nao_coladas ) * sizeof(Figurinha));
      
      }

   }else{
      album->posicao_no_album++;
      album->fig_coladas = realloc(album->fig_coladas, (album->posicao_no_album) * sizeof(Figurinha));

      do{
         sorteio = rand()%678+1;
         if(strcasecmp(figurinha[sorteio].codigo,"Nro")!=0){
            if(strcasecmp(figurinha[sorteio].codigo, repetida)!=0){
            
            album->fig_coladas[album->posicao_no_album] = figurinha[sorteio]; 

            printf("Nova figurinha: \n");
            printf("| Codigo    | Titulo                                  | Secao                                   | Tipo           |\n");
            printf("| %-9s | %-39s | %-39s | %-14s |\n",album->fig_coladas[album->posicao_no_album].codigo,album->fig_coladas[album->posicao_no_album].titulo,album->fig_coladas[album->posicao_no_album].secao,album->fig_coladas[album->posicao_no_album].tipo);
            
            if(album->posicao_repetidas_ou_nao_coladas>1){
               album->posicao_repetidas_ou_nao_coladas--;
            }//if
            if (album->posicao_repetidas_ou_nao_coladas > 0)
            {
              album->fig_repetidas_ou_nao_coladas = realloc(album->fig_repetidas_ou_nao_coladas, (album->posicao_repetidas_ou_nao_coladas ) * sizeof(Figurinha));
            }//if  
            break;
            }//if
         }//if sorteio
      }while(strcasecmp(figurinha[sorteio].codigo,"Nro")==0);
      
   }//else

}

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
         printf("3º - Dentro deste jogo há mini jogos, onde você pode ganhar mais moedas para continuar comprando pacotes.\n\n");
         printf("4º - Por último, acho importante você saber, mas não sei se isto é verdade: ouvi dizer que o vendedor de figurinhas gosta de passar a perna em seus clientes.\nEntão se liga, fica bem ligado(a)!\n\n");
         printf("Agora, sem mais delongas, que os jogos comecem! Boa sorte!\n\n");
         (*ptr_auxiliar) = 1;
         album->moedas = 200;
      }
   }
   else
   {
      if ((*ptr_auxiliar) == 0)
      {
         /// tem problema pra abrir essa coisa dai fode com o resto do codigo inteiro e dai como n tem o contador n da pra fazer a alocaçao

         // depois de voltar pro menu tem q temum if e contador pra nao realocar de novo ou chamar a salvar depois de escolher nao na compra de fig
         fread(album, sizeof(Album), 1, arq_dados_album);
         album->fig_coladas = (Figurinha *)realloc(album->fig_coladas, (album->posicao_no_album) * sizeof(Figurinha));
         album->fig_repetidas_ou_nao_coladas = (Figurinha *)realloc(album->fig_repetidas_ou_nao_coladas, (album->posicao_repetidas_ou_nao_coladas) * sizeof(Figurinha));
         fread(album->fig_coladas, sizeof(Figurinha), album->posicao_no_album, arq_dados_album);
         fread(album->fig_repetidas_ou_nao_coladas, sizeof(Figurinha), album->posicao_repetidas_ou_nao_coladas, arq_dados_album);
         fclose(arq_dados_album);
         // printf("%s", album->fig_repetidas_ou_nao_coladas[0]);
      }

      printf("Bem-vindo(a) novamente %s. Por onde você deseja continuar?\n", album->proprietario);
      printf("%d\n", album->posicao_repetidas_ou_nao_coladas);
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
   printf("%d", album->posicao_repetidas_ou_nao_coladas);
   fprintf(arq_dados_album2, "%s", album->fig_repetidas_ou_nao_coladas->titulo);
   (*ptr_auxiliar) = 0;
   fclose(arq_dados_album2);
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



int main(){
  Album album;
  int menu=1, quant_fig=679;
  char opcao;
  char repetida[30];
  int i = 0;
  int auxiliar = 0;

   

  
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

   iniciar_programa(&album, &auxiliar);



  while (menu!=0){
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
            salvar_hd(&album, &auxiliar);
            break;
         case 1:
            dados_album(album, quant_fig);
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
                  if(album.moedas>4){
                  album.moedas = album.moedas - 4;
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
            figurinhas_repetidas_ou_nao_coladas(&album);
            break;
         case 5:
            printf("Digite o código da figurinha que deseja trocar: ");
            fgets(repetida, 29, stdin);
            repetida[strcspn(repetida, "\n")]='\0';
            limpa_buffer();
            int tem = 0;
            for(int j=0;j<quant_fig; j++){
               if(strcasecmp(repetida,album.fig_repetidas_ou_nao_coladas[j].codigo)==0){
                  strcpy(album.fig_repetidas_ou_nao_coladas[j].codigo,"00000");
                  tem = 1;
               }
            }
            if(tem==0){
               printf("Esta figurinha não está na relação de figurinhas repetidas e/ou não coladas.\n");
            }else{
               trocar_figurinha(repetida, figurinha, &album);       
            }
            break;
         case 6:
            ganhar_moedas(&album);         
            break;
         case 7:
            exportar_dados(album);
            break;
         default:
            printf("Opção inválida! Tente novamente!\n");
            break;
      }//switch


   }
      
  }//while

   //limpa_tela();

   free(album.fig_coladas);
   free(album.fig_repetidas_ou_nao_coladas);
   free(album.fig_faltantes);
 
   

  return 0;
}
