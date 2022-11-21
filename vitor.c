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
    int quant_n_colada;
    int quant_colada;
    int quant_repetida;
    float porcentagem_do_album;
    float dinheiro_gasto;
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

int main(){
  Album album;
  int menu=1, menu2 = 1, quant_fig=679;
  int seletor=0;
  int moedas=200;
  char opcao;
  char repetida[30];
  int i = 0;

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
                  int tem = 0;
                  printf("Digite o código da figurinha que deseja trocar: ");
                  fgets(repetida, 29, stdin);
                  repetida[strcspn(repetida, "\n")]='\0';
                  limpa_buffer();
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
