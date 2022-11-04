#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include <Windows.h>

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




typedef struct
{
    char codigo[11];
    char titulo[51];
    char secao[21];
    char tipo[11];
} Figurinha;

typedef struct
{
    Figurinha *fig_coladas;
    Figurinha *fig_faltantes;
    Figurinha *fig_repetidas_ou_nao_coladas;
    Figurinha *fig_disponiveis;
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


void limpar_struct(Figurinha figurinha[], int quant_fig){
  for (int i=0; i<quant_fig; i++){
    if (strcmp(figurinha[i].codigo, "0000000000")!=0){
      strcpy(figurinha[i].codigo, "0000000000");
    }
  }
}

void mostra(Figurinha* figurinha, Album album, int numero, int total, char secao[]){
   int quantidade=0;
   for(int i=0; i<total; i++){
      quantidade=0;
      if(strcasecmp(figurinha[i].secao, secao)==0){
         for(int j=0; j<numero; j++){
         if(strcasecmp(album.fig_coladas[j].codigo,figurinha[i].codigo)==0){
            quantidade++;
         }//if2
         }//for2
         if(quantidade<=0){
            printf(RED);
         }else{
            printf(GRN);           
         }//else
         printf("\n%s\n", figurinha[i].titulo);
         printf(reset);
      }//if
      
   }//for
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
void simbolos(Figurinha* figurinha, Album album,int quant_fig){
   printf(" ___    _         ___    _____  _      _____  ___       ___    _____     ___    _____  ___    _____ \n");
   printf("(  _`\\ (_)/'\\_/`\\(  _`\\ (  _  )( )    (  _  )(  _`\\    (  _`\\ (  _  )   (  _`\\ (  _  )(  _`\\ (  _  )\n"); 
   printf("| (_(_)| ||     || (_) )| ( ) || |    | ( ) || (_(_)   | | ) || (_) |   | ( (_)| ( ) || |_) )| (_) |\n");
   printf("`\\__ \\ | || (_) ||  _ <'| | | || |  _ | | | |`\\__ \\    | | | )|  _  |   | |  _ | | | || ,__/'|  _  |\n");
   printf("( )_) || || | | || (_) )| (_) || |_( )| (_) |( )_) |   | |_) || | | |   | (_( )| (_) || |    | | | |\n");
   printf("`\\____)(_)(_) (_)(____/'(_____)(____/'(_____)`\\____)   (____/'(_) (_)   (____/'(_____)(_)    (_) (_)\n");

   mostra(figurinha, album, 8, quant_fig, "Content");                                                       
}
void estadios_e_bola(Figurinha* figurinha, Album album,int quant_fig){

   printf("    ___    ___    _____  _____  ___    _  _____  ___       ___       ___    _____  _      _____\n");
   printf("(  _`\\ (  _`\\ (_   _)(  _  )(  _`\\ (_)(  _  )(  _`\\    (  _`\\    (  _`\\ (  _  )( )    (  _  )\n");
   printf("| (_(_)| (_(_)  | |  | (_) || | ) || || ( ) || (_(_)   | (_(_)   | (_) )| ( ) || |    | (_) |\n");
   printf("|  _)_ `\\__ \\   | |  |  _  || | | )| || | | |`\\__ \\    |  _)_    |  _ <'| | | || |  _ |  _  |\n");
   printf("| (_( )( )_) |  | |  | | | || |_) || || (_) |( )_) |   | (_( )   | (_) )| (_) || |_( )| | | |\n");
   printf("(____/'`\\____)  (_)  (_) (_)(____/'(_)(_____)`\\____)   (____/'   (____/'(_____)(____/'(_) (_)\n");
   mostra(figurinha, album, 10, quant_fig, "Stadiums");
   mostra(figurinha, album, 1, quant_fig, "Official Match Ball");
}
void qatar(Figurinha* figurinha, Album album,int quant_fig){
   printf(" _____  _____  _____  _____  ___\n");
   printf("(  _  )(  _  )(_   _)(  _  )|  _`\\\n");
   printf("| ( ) || (_) |  | |  | (_) || (_) )\n");
   printf("| | | ||  _  |  | |  |  _  || ,  /\n");
   printf("| (('\\|| | | |  | |  | | | || |\\ \\\n");
   printf("(___\\_)(_) (_)  (_)  (_) (_)(_) (_)\n");   
   mostra(figurinha, album, 20, quant_fig, "Qatar");
}
void equador(Figurinha* figurinha, Album album,int quant_fig){
   printf(" ___    _____  _   _  _____  ___    _____  ___  \n");
   printf("(  _`\\ (  _  )( ) ( )(  _  )(  _`\\ (  _  )|  _`\\ \n");
   printf("| (_(_)| ( ) || | | || (_) || | ) || ( ) || (_) )\n");
   printf("|  _)_ | | | || | | ||  _  || | | )| | | || ,  / \n");
   printf("| (_( )| (('\\|| (_) || | | || |_) || (_) || |\\ \\ \n");
   printf("(____/'(___\\_)(_____)(_) (_)(____/'(_____)(_) (_)\n");                                               
                                                 
   mostra(figurinha, album, 20, quant_fig, "Ecuador");
}
void senegal(Figurinha* figurinha, Album album,int quant_fig){
   printf(" ___    ___    _   _  ___    ___    _____  _\n");
   printf("(  _`\\ (  _`\\ ( ) ( )(  _`\\ (  _`\\ (  _  )( )\n");
   printf("| (_(_)| (_(_)| `\\| || (_(_)| ( (_)| (_) || |\n");
   printf("`\\__ \\ |  _)_ | , ` ||  _)_ | |___ |  _  || |  _ \n");
   printf("( )_) || (_( )| |`\\ || (_( )| (_, )| | | || |_( )\n");
   printf("`\\____)(____/'(_) (_)(____/'(____/'(_) (_)(____/'\n");

   mostra(figurinha, album, 20, quant_fig, "Senegal");
}
void holanda(Figurinha* figurinha, Album album,int quant_fig){
   printf(" _   _  _____  _      _____  _   _  ___    _____ \n");
   printf("( ) ( )(  _  )( )    (  _  )( ) ( )(  _`\\ (  _  )\n");
   printf("| |_| || ( ) || |    | (_) || `\\| || | ) || (_) |\n");
   printf("|  _  || | | || |  _ |  _  || , ` || | | )|  _  |\n");
   printf("| | | || (_) || |_( )| | | || |`\\ || |_) || | | |\n");
   printf("(_) (_)(_____)(____/'(_) (_)(_) (_)(____/'(_) (_)\n");                                              
                                                 
   mostra(figurinha, album, 20, quant_fig, "Netherlands");
}
void inglaterra(Figurinha* figurinha, Album album,int quant_fig){
   printf(" _  _   _  ___    _      _____  _____  ___    ___    ___    _____ \n");
   printf("(_)( ) ( )(  _`\\ ( )    (  _  )(_   _)(  _`\\ |  _`\\ |  _`\\ (  _  )\n");
   printf("| || `\\| || ( (_)| |    | (_) |  | |  | (_(_)| (_) )| (_) )| (_) |\\\n");
   printf("| || , ` || |___ | |  _ |  _  |  | |  |  _)_ | ,  / | ,  / |  _  |\n");
   printf("| || |`\\ || (_, )| |_( )| | | |  | |  | (_( )| |\\ \\ | |\\ \\ | | | |\n");
   printf("(_)(_) (_)(____/'(____/'(_) (_)  (_)  (____/'(_) (_)(_) (_)(_) (_)\n");

   mostra(figurinha, album, 20, quant_fig, "England");
}
void ira(Figurinha* figurinha, Album album,int quant_fig){
   printf("            _   _ \n");
   printf("         /' \\/' )\n");
   printf("         (_/\\__/' \n\n");
   printf(" _  ___    _____\n");
   printf("(_)|  _`\\ (  _  )\n");
   printf("| || (_) )| (_) |\n");
   printf("| || ,  / |  _  |\n");
   printf("| || |\\ \\ | | | |\n");
   printf("(_)(_) (_)(_) (_)\n");

   mostra(figurinha, album, 20, quant_fig, "Iran");
}
void estados_unidos(Figurinha* figurinha, Album album,int quant_fig){
   printf(" _   _  ___    _____ \n");
   printf("( ) ( )(  _`\\ (  _  )\n");
   printf("| | | || (_(_)| (_) |\n");
   printf("| | | |`\\__ \\ |  _  |\n");
   printf("| (_) |( )_) || | | |\n");
   printf("(_____)`\\____)(_) (_)\n");
                     
   mostra(figurinha, album, 20, quant_fig, "USA");
}
void pais_de_gales(Figurinha* figurinha, Album album,int quant_fig){
   printf(" ___    _____  _  ___       ___    ___       ___    _____  _      ___    ___   \n");
   printf("(  _`\\ (  _  )(_)(  _`\\    (  _`\\ (  _`\\    (  _`\\ (  _  )( )    (  _`\\ (  _`\\ \n");
   printf("| |_) )| (_) || || (_(_)   | | ) || (_(_)   | ( (_)| (_) || |    | (_(_)| (_(_)\n");
   printf("| ,__/'|  _  || |`\\__ \\    | | | )|  _)_    | |___ |  _  || |  _ |  _)_ `\\__ \\ \n");
   printf("| |    | | | || |( )_) |   | |_) || (_( )   | (_, )| | | || |_( )| (_( )( )_) |\n");
   printf("(_)    (_) (_)(_)`\\____)   (____/'(____/'   (____/'(_) (_)(____/'(____/'`\\____)\n");

   mostra(figurinha, album, 20, quant_fig, "Wales");
}
void argentina(Figurinha* figurinha, Album album,int quant_fig){
   printf(" _____  ___    ___    ___    _   _  _____  _  _   _  _____ \n");
   printf("(  _  )|  _`\\ (  _`\\ (  _`\\ ( ) ( )(_   _)(_)( ) ( )(  _  )\n");
   printf("| (_) || (_) )| ( (_)| (_(_)| `\\| |  | |  | || `\\| || (_) |\n");
   printf("|  _  || ,  / | |___ |  _)_ | , ` |  | |  | || , ` ||  _  |\n");
   printf("| | | || |\\ \\ | (_, )| (_( )| |`\\ |  | |  | || |`\\ || | | |\n");
   printf("(_) (_)(_) (_)(____/'(____/'(_) (_)  (_)  (_)(_) (_)(_) (_)\n");
                                                         
   mostra(figurinha, album, 20, quant_fig, "Argentina");
}
void arabia_saudita(Figurinha* figurinha, Album album,int quant_fig){
   printf(" _____  ___    _____  ___    _  _____     ___    _____  _   _  ___    _  _____  _____ \n");
   printf("(  _  )|  _`\\ (  _  )(  _`\\ (_)(  _  )   (  _`\\ (  _  )( ) ( )(  _`\\ (_)(_   _)(  _  )\n");
   printf("| (_) || (_) )| (_) || (_) )| || (_) |   | (_(_)| (_) || | | || | ) || |  | |  | (_) |\n");
   printf("|  _  || ,  / |  _  ||  _ <'| ||  _  |   `\\__ \\ |  _  || | | || | | )| |  | |  |  _  |\n");
   printf("| | | || |\\ \\ | | | || (_) )| || | | |   ( )_) || | | || (_) || |_) || |  | |  | | | |\n");
   printf("(_) (_)(_) (_)(_) (_)(____/'(_)(_) (_)   `\\____)(_) (_)(_____)(____/'(_)  (_)  (_) (_)\n");

   mostra(figurinha, album, 20, quant_fig, "Saudi Arabia");
}
void mexico(Figurinha* figurinha, Album album,int quant_fig){
   printf("           __  \n");
   printf("          /_/ \n\n");
   printf("        ___    _    _  _  ___    _____ \n");
   printf("/'\\_/`\\(  _`\\ ( )  ( )(_)(  _`\\ (  _  )\n");
   printf("|     || (_(_)`\\`\\/'/'| || ( (_)| ( ) |\n");
   printf("| (_) ||  _)_   >  <  | || |  _ | | | |\n");
   printf("| | | || (_( ) /'/\\`\\ | || (_( )| (_) |\n");
   printf("(_) (_)(____/'(_)  (_)(_)(____/'(_____)\n");
                                       
   mostra(figurinha, album, 20, quant_fig, "Mexico");
}
void polonia(Figurinha* figurinha, Album album,int quant_fig){
   printf("                       __  \n");
   printf("                      /  \\ \n");
   printf("                     (_/\\_) \n\n");
   printf(" ___    _____  _      _____  _   _  _  _____ \n");
   printf("(  _`\\ (  _  )( )    (  _  )( ) ( )(_)(  _  )\n");
   printf("| |_) )| ( ) || |    | ( ) || `\\| || || (_) |\n");
   printf("| ,__/'| | | || |  _ | | | || , ` || ||  _  |\n");
   printf("| |    | (_) || |_( )| (_) || |`\\ || || | | |\n");              
   printf("(_)    (_____)(____/'(_____)(_) (_)(_)(_) (_)\n");                                           
                                             
   mostra(figurinha, album, 20, quant_fig, "Poland");
}
void franca(Figurinha* figurinha, Album album,int quant_fig){
   printf(" ___    ___    _____  _   _  ___    _____ \n");
   printf("(  _`\\ |  _`\\ (  _  )( ) ( )(  _`\\ (  _  )\n");
   printf("| (_(_)| (_) )| (_) || `\\| || ( (_)| (_) |\n");
   printf("|  _)  | ,  / |  _  || , ` || |  _ |  _  |\n");
   printf("| |    | |\\ \\ | | | || |`\\ || (_( )| | | |\n");
   printf("(_)    (_) (_)(_) (_)(_) (_)(____/'(_) (_)\n");
   printf("                              \\__, \\\n");
   printf("                              (____/  \n");

   mostra(figurinha, album, 20, quant_fig, "France");
}
void australia(Figurinha* figurinha, Album album,int quant_fig){
   printf("                                        __\n");
   printf("                                       /_/\n\n");
   printf(" _____  _   _  ___    _____  ___    _____  _      _  _____ \n");
   printf("(  _  )( ) ( )(  _`\\ (_   _)|  _`\\ (  _  )( )    (_)(  _  )\n");
   printf("| (_) || | | || (_(_)  | |  | (_) )| (_) || |    | || (_) |\n");
   printf("|  _  || | | |`\\__ \\   | |  | ,  / |  _  || |  _ | ||  _  |\n");
   printf("| | | || (_) |( )_) |  | |  | |\\ \\ | | | || |_( )| || | | |\n");
   printf("(_) (_)(_____)`\\____)  (_)  (_) (_)(_) (_)(____/'(_)(_) (_)\n");

   mostra(figurinha, album, 20, quant_fig, "Australia");
}
void dinamarca(Figurinha* figurinha, Album album,int quant_fig){
   printf(" ___    _  _   _  _____         _____  ___    ___    _____ \n");
   printf("(  _`\\ (_)( ) ( )(  _  )/'\\_/`\\(  _  )|  _`\\ (  _`\\ (  _  )\n");
   printf("| | ) || || `\\| || (_) ||     || (_) || (_) )| ( (_)| (_) |\n");
   printf("| | | )| || , ` ||  _  || (_) ||  _  || ,  / | |  _ |  _  |\n");
   printf("| |_) || || |`\\ || | | || | | || | | || |\\ \\ | (_( )| | | |\n");
   printf("(____/'(_)(_) (_)(_) (_)(_) (_)(_) (_)(_) (_)(____/'(_) (_)\n");

   mostra(figurinha, album, 20, quant_fig, "Denmark");
}
void tunisia(Figurinha* figurinha, Album album,int quant_fig){
   printf("                      __  \n");
   printf("                     /_/\n\n");
   printf(" _____  _   _  _   _  _  ___    _  _____ \n");
   printf("(_   _)( ) ( )( ) ( )(_)(  _`\\ (_)(  _  )\n");
   printf("  | |  | | | || `\\| || || (_(_)| || (_) |\n");
   printf("  | |  | | | || , ` || |`\\__ \\ | ||  _  |\n");
   printf("  | |  | (_) || |`\\ || |( )_) || || | | |\n");
   printf("  (_)  (_____)(_) (_)(_)`\\____)(_)(_) (_)\n");
                                    
   mostra(figurinha, album, 20, quant_fig, "Tunisia");
}
void espanha(Figurinha* figurinha, Album album,int quant_fig){
   printf(" ___    ___    ___    _____  _   _  _   _  _____ \n");
   printf("(  _`\\ (  _`\\ (  _`\\ (  _  )( ) ( )( ) ( )(  _  )\n");
   printf("| (_(_)| (_(_)| |_) )| (_) || `\\| || |_| || (_) |\n");
   printf("|  _)_ `\\__ \\ | ,__/'|  _  || , ` ||  _  ||  _  |\n");
   printf("| (_( )( )_) || |    | | | || |`\\ || | | || | | |\n");
   printf("(____/'`\\____)(_)    (_) (_)(_) (_)(_) (_)(_) (_)\n");

  mostra(figurinha, album, 20, quant_fig, "Spain");
}
void costa_rica(Figurinha* figurinha, Album album,int quant_fig){
   printf(" ___    _____  ___    _____  _____     ___    _  ___    _____ \n");
   printf("(  _`\\ (  _  )(  _`\\ (_   _)(  _  )   |  _`\\ (_)(  _`\\ (  _  )\n");
   printf("| ( (_)| ( ) || (_(_)  | |  | (_) |   | (_) )| || ( (_)| (_) |\n");
   printf("| |  _ | | | |`\\__ \\   | |  |  _  |   | ,  / | || |  _ |  _  |\n");
   printf("| (_( )| (_) |( )_) |  | |  | | | |   | |\\ \\ | || (_( )| | | |\n");
   printf("(____/'(_____)`\\____)  (_)  (_) (_)   (_) (_)(_)(____/'(_) (_)\n");

   mostra(figurinha, album, 20, quant_fig, "Costa Rica");
}
void alemanha(Figurinha* figurinha, Album album,int quant_fig){
   printf(" _____  _      ___           _____  _   _  _   _  _____ \n");
   printf("(  _  )( )    (  _`\\ /'\\_/`\\(  _  )( ) ( )( ) ( )(  _  )\n");
   printf("| (_) || |    | (_(_)|     || (_) || `\\| || |_| || (_) |\n");
   printf("|  _  || |  _ |  _)_ | (_) ||  _  || , ` ||  _  ||  _  |\n");
   printf("| | | || |_( )| (_( )| | | || | | || |`\\ || | | || | | |\n");
   printf("(_) (_)(____/'(____/'(_) (_)(_) (_)(_) (_)(_) (_)(_) (_)\n");

   mostra(figurinha, album, 20, quant_fig, "Germany");
}
void japao(Figurinha* figurinha, Album album,int quant_fig){
   printf("                        _   _ \n");
   printf("                      /' \\/' )\n");
   printf("                     (_/\\__/' \n\n");
   printf(" _____  _____  ___    _____  _____ \n");
   printf("(___  )(  _  )(  _`\\ (  _  )(  _  )\n");
   printf("    | || (_) || |_) )| (_) || ( ) |\n");
   printf(" _  | ||  _  || ,__/'|  _  || | | |\n");
   printf("( )_| || | | || |    | | | || (_) |\n");
   printf("`\\___/'(_) (_)(_)    (_) (_)(_____)\n");

   mostra(figurinha, album, 20, quant_fig, "Japao");
}
void belgica(Figurinha* figurinha, Album album,int quant_fig){
   printf("          __  \n");
   printf("         /_/\n\n");
   printf(" ___    ___    _      ___    _  ___    _____ \n");
   printf("(  _`\\ (  _`\\ ( )    (  _`\\ (_)(  _`\\ (  _  )\n");
   printf("| (_) )| (_(_)| |    | ( (_)| || ( (_)| (_) |\n");
   printf("|  _ <'|  _)_ | |  _ | |___ | || |  _ |  _  |\n");
   printf("| (_) )| (_( )| |_( )| (_, )| || (_( )| | | |\n");
   printf("(____/'(____/'(____/'(____/'(_)(____/'(_) (_)\n");

   mostra(figurinha, album, 20, quant_fig, "Belgium");
}
void canada(Figurinha* figurinha, Album album,int quant_fig){
   printf("                                      __  \n");
   printf("                                     /_/\n\n");
   printf(" ___    _____  _   _  _____  ___    _____ \n");
   printf("(  _`\\ (  _  )( ) ( )(  _  )(  _`\\ (  _  )\n");
   printf("| ( (_)| (_) || `\\| || (_) || | ) || (_) |\n");
   printf("| |  _ |  _  || , ` ||  _  || | | )|  _  |\n");
   printf("| (_( )| | | || |`\\ || | | || |_) || | | |\n");
   printf("(____/'(_) (_)(_) (_)(_) (_)(____/'(_) (_)\n");                                       
                                    
   mostra(figurinha, album, 20, quant_fig, "Canada");
}
void marrocos(Figurinha* figurinha, Album album,int quant_fig){
   printf("        _____  ___    ___    _____  ___    _____  ___   \n");
   printf("/'\\_/`\\(  _  )|  _`\\ |  _`\\ (  _  )(  _`\\ (  _  )(  _`\\ \n");
   printf("|     || (_) || (_) )| (_) )| ( ) || ( (_)| ( ) || (_(_)\n");
   printf("| (_) ||  _  || ,  / | ,  / | | | || |  _ | | | |`\\__ \\ \n");
   printf("| | | || | | || |\\ \\ | |\\ \\ | (_) || (_( )| (_) |( )_) |\n");
   printf("(_) (_)(_) (_)(_) (_)(_) (_)(_____)(____/'(_____)`\\____)\n");

   mostra(figurinha, album, 20, quant_fig, "Marrocco");
}
void croacia(Figurinha* figurinha, Album album,int quant_fig){
   printf("                         __  \n");
   printf("                        /_/\n\n");
   printf(" ___    ___    _____  _____  ___    _  _____\n");
   printf("(  _`\\ |  _`\\ (  _  )(  _  )(  _`\\ (_)(  _  )\n");
   printf("| ( (_)| (_) )| ( ) || (_) || ( (_)| || (_) |\n");
   printf("| |  _ | ,  / | | | ||  _  || |  _ | ||  _  |\n");
   printf("| (_( )| |\\ \\ | (_) || | | || (_( )| || | | |\n");
   printf("(____/'(_) (_)(_____)(_) (_)(____/'(_)(_) (_)\n");

   mostra(figurinha, album, 20, quant_fig, "Croatia");
}
void brasil(Figurinha* figurinha, Album album,int quant_fig){
   printf(" ___    ___    _____  ___    _  _   \n");
   printf("(  _`\\ |  _`\\ (  _  )(  _`\\ (_)( ) \n");
   printf("| (_) )| (_) )| (_) || (_(_)| || |  \n");
   printf("|  _ <'| ,  / |  _  |`\\__ \\ | || |  _ \n");
   printf("| (_) )| |\\ \\ | | | |( )_) || || |_( )\n");
   printf("(____/'(_) (_)(_) (_)`\\____)(_)(____/'\n");

   mostra(figurinha, album, 20, quant_fig, "Brazil");
}
void servia(Figurinha* figurinha, Album album,int quant_fig){
   printf("          __  \n");
   printf("         /_/\n");
   printf(" ___    ___    ___    _   _  _  _____ \n");
   printf("(  _`\\ (  _`\\ |  _`\\ ( ) ( )(_)(  _  )\n");
   printf("| (_(_)| (_(_)| (_) )| | | || || (_) |\n");
   printf("`\\__ \\ |  _)_ | ,  / | | | || ||  _  |\n");
   printf("( )_) || (_( )| |\\ \\ | \\_/ || || | | |\n");
   printf("`\\____)(____/'(_) (_)`\\___/'(_)(_) (_)\n");
   

   mostra(figurinha, album, 20, quant_fig, "Serbia");
}
void suica(Figurinha* figurinha, Album album,int quant_fig){
   printf("                __  \n");
   printf("               /_/\n\n");
   printf(" ___    _   _  _  ___    _____ \n");
   printf("(  _`\\ ( ) ( )(_)(  _`\\ (  _  )\n");
   printf("| (_(_)| | | || || ( (_)| (_) |\n");
   printf("`\\__ \\ | | | || || |  _ |  _  |\n");
   printf("( )_) || (_) || || (_( )| | | |\n");
   printf("`\\____)(_____)(_)(____/'(_) (_)\n");
   printf("                  \\__, \\n");
   printf("                  (____/\n");

   mostra(figurinha, album, 20, quant_fig, "Switzerland");
}
void camaroes(Figurinha* figurinha, Album album,int quant_fig){
   printf("                                       _   _ \n");
   printf("                                     /' \\/' )\n");
   printf("                                    (_/\\__/'\n");
   printf(" ___    _____         _____  ___    _____  ___    ___  \n");
   printf("(  _`\\ (  _  )/'\\_/`\\(  _  )|  _`\\ (  _  )(  _`\\ (  _`\\ \n");
   printf("| ( (_)| (_) ||     || (_) || (_) )| ( ) || (_(_)| (_(_)\n");
   printf("| |  _ |  _  || (_) ||  _  || ,  / | | | ||  _)_ `\\__ \\ \n");
   printf("| (_( )| | | || | | || | | || |\\ \\ | (_) || (_( )( )_) |\n");
   printf("(____/'(_) (_)(_) (_)(_) (_)(_) (_)(_____)(____/'`\\____) \n");

   mostra(figurinha, album, 20, quant_fig, "Cameroon");
}
void portugal(Figurinha* figurinha, Album album,int quant_fig){
   printf(" ___    _____  ___    _____  _   _  ___    _____  _  \n");
   printf("(  _`\\ (  _  )|  _`\\ (_   _)( ) ( )(  _`\\ (  _  )( ) \n");
   printf("| |_) )| ( ) || (_) )  | |  | | | || ( (_)| (_) || | \n");
   printf("| ,__/'| | | || ,  /   | |  | | | || |___ |  _  || |  _\n");
   printf("| |    | (_) || |\\ \\   | |  | (_) || (_, )| | | || |_( )\n");
   printf("(_)    (_____)(_) (_)  (_)  (_____)(____/'(_) (_)(____/'\n");                                                     

   mostra(figurinha, album, 20, quant_fig, "Portugal");
}
void gana(Figurinha* figurinha, Album album,int quant_fig){
   printf(" ___    _____  _   _  _____ \n");
   printf("(  _`\\ (  _  )( ) ( )(  _  )\n");
   printf("| ( (_)| (_) || `\\| || (_) |\n");
   printf("| |___ |  _  || , ` ||  _  |\n");
   printf("| (_, )| | | || |`\\ || | | |\n");
   printf("(____/'(_) (_)(_) (_)(_) (_)\n");                          

   mostra(figurinha, album, 20, quant_fig, "Ghana");
}
void uruguai(Figurinha* figurinha, Album album,int quant_fig){
   printf(" _   _  ___    _   _  ___    _   _  _____  _ \n");
   printf("( ) ( )|  _`\\ ( ) ( )(  _`\\ ( ) ( )(  _  )(_)\n");
   printf("| | | || (_) )| | | || ( (_)| | | || (_) || |\n");
   printf("| | | || ,  / | | | || |___ | | | ||  _  || |\n");
   printf("| (_) || |\\ \\ | (_) || (_, )| (_) || | | || |\n");
   printf("(_____)(_) (_)(_____)(____/'(_____)(_) (_)(_)\n");

   mostra(figurinha, album, 20, quant_fig, "Uruguay");
}
void coreia_do_sul(Figurinha* figurinha, Album album,int quant_fig){
   printf(" ___    _____  ___    ___    _  _____     ___    _____     ___    _   _  _ \n");
   printf("(  _`\\ (  _  )|  _`\\ (  _`\\ (_)(  _  )   (  _`\\ (  _  )   (  _`\\ ( ) ( )( )    \n");
   printf("| ( (_)| ( ) || (_) )| (_(_)| || (_) |   | | ) || ( ) |   | (_(_)| | | || |    \n");
   printf("| |  _ | | | || ,  / |  _)_ | ||  _  |   | | | )| | | |   `\\__ \\ | | | || |  _ \n");
   printf("| (_( )| (_) || |\\ \\ | (_( )| || | | |   | |_) || (_) |   ( )_) || (_) || |_( )\n");
   printf("(____/'(_____)(_) (_)(____/'(_)(_) (_)   (____/'(_____)   `\\____)(_____)(____/'\n");
    
   mostra(figurinha, album, 20, quant_fig, "Korea Republic");
}
void museu_da_fifa(Figurinha* figurinha, Album album,int quant_fig){
   printf("        _   _  ___    ___    _   _     ___    _____     ___    _  ___    _____ \n");
   printf("/'\\_/`\\( ) ( )(  _`\\ (  _`\\ ( ) ( )   (  _`\\ (  _  )   (  _`\\ (_)(  _`\\ (  _  )\n");
   printf("|     || | | || (_(_)| (_(_)| | | |   | | ) || (_) |   | (_(_)| || (_(_)| (_) |\n");
   printf("| (_) || | | |`\\__ \\ |  _)_ | | | |   | | | )|  _  |   |  _)  | ||  _)  |  _  |\n");
   printf("| | | || (_) |( )_) || (_( )| (_) |   | |_) || | | |   | |    | || |    | | | |\n");
   printf("(_) (_)(_____)`\\____)(____/'(_____)   (____/'(_) (_)   (_)    (_)(_)    (_) (_)\n");
                                                                          
   mostra(figurinha, album, 11, quant_fig, "FIFA Museum");
}
void coca_cola(Figurinha* figurinha, Album album,int quant_fig){
   printf(" ___    _____  ___    _____          ___    _____  _      _____ \n");
   printf("(  _`\\ (  _  )(  _`\\ (  _  )        (  _`\\ (  _  )( )    (  _  )\n");
   printf("| ( (_)| ( ) || ( (_)| (_) | ______ | ( (_)| ( ) || |    | (_) |\n");
   printf("| |  _ | | | || |  _ |  _  |(______)| |  _ | | | || |  _ |  _  |\n");
   printf("| (_( )| (_) || (_( )| | | |        | (_( )| (_) || |_( )| | | |\n");
   printf("(____/'(_____)(____/'(_) (_)        (____/'(_____)(____/'(_) (_)\n");  
                                                                
   mostra(figurinha, album, 20, quant_fig, "CocanormalCola Team Believers");
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
            simbolos(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 2:
            limpa_tela();
            estadios_e_bola(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 3:
            limpa_tela();
            qatar(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 4:
            limpa_tela();
            equador(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 5:
            limpa_tela();
            senegal(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 6:
            limpa_tela();
            holanda(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 7:
            limpa_tela();
            inglaterra(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 8:
            limpa_tela();
            ira(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 9:
            limpa_tela();
            estados_unidos(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 10:
            limpa_tela();
            pais_de_gales(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 11:
            limpa_tela();
            argentina(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 12:
            limpa_tela();
            arabia_saudita(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 13:
            limpa_tela();
            mexico(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 14:
            limpa_tela();
            polonia(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 15:
            limpa_tela();
            franca(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 16:
            limpa_tela();
            australia(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 17:
            limpa_tela();
            dinamarca(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 18:
            limpa_tela();
            tunisia(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 19:
            limpa_tela();
            espanha(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 20:
            limpa_tela();
            costa_rica(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 21:
            limpa_tela();
            alemanha(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 22:
            limpa_tela();
            japao(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 23:
            limpa_tela();
            belgica(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 24:
            limpa_tela();
            canada(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 25:
            limpa_tela();
            marrocos(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 26:
            limpa_tela();
            croacia(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 27:
            limpa_tela();
            brasil(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 28:
            limpa_tela();
            servia(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 29:
            limpa_tela();
            suica(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 30:
            limpa_tela();
            camaroes(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 31:
            limpa_tela();
            portugal(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 32:
            limpa_tela();
            gana(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 33:
            limpa_tela();
            uruguai(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 34:
            limpa_tela();
            coreia_do_sul(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 35:
            limpa_tela();
            museu_da_fifa(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 36:
            limpa_tela();
            coca_cola(figurinha, album,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;


      }

   }while(tecla!=ESC);

}

void dados_album(Album album, int quant_fig){
  printf("Nome do proprietario do album:\t%s\n",album.proprietario);
  printf("Total de figurinhas coladas:\t%d\n", album.contador_figurinha);
  printf("Total de figurinhas faltantes:\t%d\n", quant_fig - album.contador_figurinha);
  printf("Porcentagem de conclusao do album:\t%f%%\n", album.porcentagem_do_album);
  printf("Total gasto com envelopes:\t%.2f\n", album.dinheiro_gasto);

  return;
}

void comprar_envelope(Figurinha *figurinha, Album album)
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
        int num = rand() % 10; // gerar um numero de 0 a 9
        printf("FIGURINHA %d:\n", i + 1);
        printf("| Codigo | Titulo           | Secao       | Tipo       |\n");
        printf("| %-6s | %-16s | %-11s | %-10s |\n", figurinha[num].codigo, figurinha[num].titulo, figurinha[num].secao, figurinha[num].tipo);

        // tenho q fazer o strcomp pra ver se ta no album antes de perguntar se quer colar ou nao

        if (album.posicao_no_album == 0)
        {
            album.fig_coladas = (Figurinha *)calloc(1, sizeof(Figurinha));
            album.fig_repetidas_ou_nao_coladas = (Figurinha *)calloc(1, sizeof(Figurinha));
            album.fig_faltantes = (Figurinha *)calloc(1, sizeof(Figurinha));
        }
        else
        {

            // realocar a relacao de figurinhas coladas, repetidas/nao coladas e faltantes
            if (album.posicao_no_album > 0)
            {
                for (int l = 1; l <= album.posicao_no_album; l++)
                {
                    album.fig_coladas = realloc(album.fig_coladas, (album.posicao_no_album + 1) * sizeof(Figurinha));
                }
            }
            if (album.posicao_repetidas_ou_nao_coladas > 0)
            {
                for (int l = 1; l <= album.posicao_repetidas_ou_nao_coladas; l++)
                {
                    album.fig_repetidas_ou_nao_coladas = realloc(album.fig_repetidas_ou_nao_coladas, (album.posicao_repetidas_ou_nao_coladas + 1) * sizeof(Figurinha));
                }
            }

            if (album.posicao_faltantes > 0)
            {
                for (int l = 1; l <= album.posicao_faltantes; l++)
                {
                    album.fig_faltantes = realloc(album.fig_faltantes, (album.posicao_faltantes + 1) * sizeof(Figurinha));
                }
            }
        }

        for (int j = 0; j <= album.quant_fig; j++)
        {
            if (strcasecmp(figurinha[num].codigo, album.fig_coladas[j].codigo) == 0)
            {
                aux++;
                break;
            }
        }

        if (aux == 1)
        {
            printf("Voce ja possui esta figurinha no seu album! Parabens :)\nAgora, esta figurinha esta salva na relacao de figurinhas repetidas/nao coladas.\n");
            album.fig_repetidas_ou_nao_coladas[album.posicao_repetidas_ou_nao_coladas] = figurinha[num];
            album.posicao_repetidas_ou_nao_coladas++;
        }
        else
        {
            setbuf(stdin, NULL);
            printf("Voce nao possui esta figurinha em seu album. Deseja cola-la?\nS para sim e N para nao. ");
            scanf("%c", &opcao);
            setbuf(stdin, NULL);

            if (opcao == 'S' || opcao == 's')
            {

                album.fig_coladas[album.posicao_no_album] = figurinha[num];
                album.posicao_no_album++;

                album.porcentagem_do_album = ((100.0 * album.posicao_no_album) / 678);
            }

            if (opcao == 'N' || opcao == 'n')
            {
                printf("Tudo bem, voce ainda tem a chance de obte-la novamente!\nEsta figurinha foi salva na relacao de figurinhas nao coladas/repetidas.\n");
                album.fig_repetidas_ou_nao_coladas[album.posicao_repetidas_ou_nao_coladas] = figurinha[num];
                album.posicao_repetidas_ou_nao_coladas++;
            }
        }
        setbuf(stdin, NULL);
        printf("\n");
        printf("Porcentagem concluida deste album: %.2f\n\n", album.porcentagem_do_album);
    }
}

void figurinhas_repetidas_ou_nao_coladas(Album album){
   for(int i=0; i<album.posicao_repetidas_ou_nao_coladas; i++){
      if(strcasecmp(album.fig_repetidas_ou_nao_coladas[i].codigo,"0000000000")==1){
        printf("%s\n", album.fig_repetidas_ou_nao_coladas[i].titulo); 
      }
      
   }

}

int cadastrar_figurinha(Figurinha* figurinha, int quant_fig){
   int amais;
   printf("Quantas figurinhas vc deseja cadastrar?\n");
   scanf("%d", &amais);
   for (int i=quant_fig; i<quant_fig+amais; i++){
      fflush(stdin);
      printf("Digite o codigo da figurinha: ");
      fgets(figurinha[i].codigo, 5, stdin);
      fflush(stdin);
      printf("Digite o titulo da figurinha: ");
      fgets(figurinha[i].titulo, 10, stdin);
      fflush(stdin);
      printf("Digite a secao da figurinha: ");
      fgets(figurinha[i].secao, 10, stdin);
      fflush(stdin);
      printf("Digite o tipo da figurinha: ");
      fgets(figurinha[i].tipo, 10, stdin);
      fflush(stdin);
  }

  quant_fig = quant_fig + amais;
  void *realloc(void *figurinha, unsigned int quant_fig);

  return quant_fig;


}

int forca(){
   FILE* f;
   char chute;
   char palavra[30];
   char chutes[30];
   int erros=0, completa=0, acertos=0, errado=0;
   int sorteio;

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

   for(int i=0; i<strlen(palavra); i++){
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
      for(int i=0; i<strlen(palavra); i++){
         printf("%c ", chutes[i]);
      }
      printf("\n\n");
      scanf(" %c", &chute);
      limpa_buffer();
      chute=toupper(chute);
      for(int i=0; i<strlen(palavra); i++){
         if(palavra[i]==chute){
            chutes[i]=chute;
            acertos++;
         }else{
            errado++;
         }

         if(errado==strlen(palavra)){
            erros++;
         }
         if(acertos==strlen(palavra)){
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
   printf("1 - Jogo da Forca (Prêmio: 3 moedas)\n2 - Jogo da Memória (Prêmio: 5 moedas)\n");
   scanf("%d", &opcao);
   limpa_buffer();
   switch (opcao){
   case 1:
      moedas = moedas + forca();
      break;
   case 2:
      moedas = moedas + memoria();
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
      printf(GRN"O dono da banca fugiu! Bem-vindo à Apucarana\n"reset);
   }else{
      for(int i=0; i<quant_fig; i++){
            if(strcasecmp(figurinha[i].codigo, repetida)==1){
               album->fig_coladas[album->posicao_no_album] = figurinha[i];
               album->posicao_no_album++;
               album->fig_coladas = realloc (album->fig_coladas,album->posicao_no_album*sizeof(Figurinha));
               break;
            }//if
      }//for
   }//else
}

int main(){
  Album album;
  Figurinha figurinha[1];
  int menu=1, quant_fig=0;
  int moedas=200;
  char opcao;
  char repetida[30];
  


  while (menu!=0){
   printf(YEL"Moedas %d\n", moedas);
   printf(MAG" =========================================================================\n");
   printf(MAG"||"WHT"                             Álbum da Copa 2022                        "MAG"||\n");
   printf(MAG" =========================================================================\n"); 
   printf(MAG"\nMenu:\n\n");
   printf(WHT"\t1 - Folhear Álbum\n\t2 - Comprar Envelope\n\t3 - Figurinhas Repetidas e/ou não coladas\n");
   printf("\t4 - Dados do Álbum\n\t5 - Cadastrar Figurinha\n\t6 - Ganhar Moedas\n");
   printf("\t7 - Trocar Figurinha Repetida\n"RED"\t0 - Sair\n\n");
   printf(reset"Digite a opção desejada: ");  
   scanf("%d", &menu);
   limpa_buffer();
   switch (menu){
      case 0:
         break;
      case 1:
        folhear_album(figurinha,album,quant_fig);
        break;
      case 2:
         do{
         printf("Comprar envelope por 4 moedas? (s/n)\n");
         scanf("%c", &opcao);
         limpa_buffer();
         if(opcao=='n' || opcao=='N'){
            break;
         }else if(opcao!='s' || opcao!='S'){
            printf("Resposta inválida!\n");
         }else{
            printf("Opção inválida!\n");
         }
         }while (opcao!='s' || opcao!='S');
         
         if(moedas>4){
            moedas = moedas - 4;
            album.dinheiro_gasto = album.dinheiro_gasto + 4; 
            comprar_envelope(figurinha,album);
         }else{
            printf("Você não possui moedas suficiente!\n");
         }
        break;
      case 3:
        figurinhas_repetidas_ou_nao_coladas(album);
        break;
      case 4:
        dados_album(album, quant_fig);
        break;
      case 5:
        quant_fig = cadastrar_figurinha(figurinha, quant_fig);
        break;
      case 6:
         ganhar_moedas(&moedas);
         break;
      case 7:
         printf("Digite o código da figurinha que deseja trocar: ");
         fgets(repetida, 29, stdin);
         repetida[strcspn(repetida, "\n")]='\0';
         limpa_buffer();
         for(int i=0;i<quant_fig; i++){
            if(strcasecmp(repetida,album.fig_repetidas_ou_nao_coladas[i].codigo)==0){
               strcpy(album.fig_repetidas_ou_nao_coladas[i].codigo,"0000000000");
            }
         }
         trocar_figurinha(repetida, figurinha, &album, quant_fig);       
         break;
      default:
         printf("Opção inválida! Tente novamente!\n");
    }
  }


  return 0;
}
