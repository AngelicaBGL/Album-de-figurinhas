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
  char titulo[50];
  char secao[20];
  char tipo[10];
}Figurinha;

typedef struct{
  char figurinhas_coladas[678][10];
  char figurinhas_nao_coladas[678][10]
  char figurinhas_faltantes[678][10];
  char figurinhas_repetidas[678][10]
  char proprietario[50];
  float porcentagem_do_album; 
  float dinheiro_gasto;
  int contador_figurinha;
}Album;

void limpar_struct(Figurinha figurinha[]){
  for (int i=0; i<5; i++){
    if (strcmp(figurinha[i].codigo, "00000")!=0){
      strcpy(figurinha[i].codigo, "00000");
    }
  }
}

void mostra(Figurinha* figurinha, Album* album, int numero, int total, char secao[]){
   int quantidade=0;
   for(int i=0; i<total; i++){
      quantidade=0;
      if(strcasecmp(figurinha[i].secao, secao)==0){
         for(int j=0; j<numero; j++){
         if(strcasecmp(album[0].figurinhas_coladas[j],figurinha[i].codigo)==0){
            quantidade++;
         }//if2
         }//for2
         if(quantidade<=0){
            printf(RED);
         }else{
            if(strcasecmp(figurinha[i].tipo,'metalico')==0){
               printf(YEL);
            }else{
               printf(GRN);
            }//else interno
            
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
void simbolos(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf(" ___    _         ___    _____  _      _____  ___       ___    _____     ___    _____  ___    _____ \n");
   printf("(  _`\\ (_)/'\\_/`\\(  _`\\ (  _  )( )    (  _  )(  _`\\    (  _`\\ (  _  )   (  _`\\ (  _  )(  _`\\ (  _  )\n"); 
   printf("| (_(_)| ||     || (_) )| ( ) || |    | ( ) || (_(_)   | | ) || (_) |   | ( (_)| ( ) || |_) )| (_) |\n");
   printf("`\\__ \\ | || (_) ||  _ <'| | | || |  _ | | | |`\\__ \\    | | | )|  _  |   | |  _ | | | || ,__/'|  _  |\n");
   printf("( )_) || || | | || (_) )| (_) || |_( )| (_) |( )_) |   | |_) || | | |   | (_( )| (_) || |    | | | |\n");
   printf("`\\____)(_)(_) (_)(____/'(_____)(____/'(_____)`\\____)   (____/'(_) (_)   (____/'(_____)(_)    (_) (_)\n");

   mostra(figurinhas, selecionado, 8, quant_fig, 'Content');                                                       
}
void estadios_e_bola(Figurinha* figurinha, Album selecionado,int quant_fig){

   printf("    ___    ___    _____  _____  ___    _  _____  ___       ___       ___    _____  _      _____\n");
   printf("(  _`\\ (  _`\\ (_   _)(  _  )(  _`\\ (_)(  _  )(  _`\\    (  _`\\    (  _`\\ (  _  )( )    (  _  )\n");
   printf("| (_(_)| (_(_)  | |  | (_) || | ) || || ( ) || (_(_)   | (_(_)   | (_) )| ( ) || |    | (_) |\n");
   printf("|  _)_ `\\__ \\   | |  |  _  || | | )| || | | |`\\__ \\    |  _)_    |  _ <'| | | || |  _ |  _  |\n");
   printf("| (_( )( )_) |  | |  | | | || |_) || || (_) |( )_) |   | (_( )   | (_) )| (_) || |_( )| | | |\n");
   printf("(____/'`\\____)  (_)  (_) (_)(____/'(_)(_____)`\\____)   (____/'   (____/'(_____)(____/'(_) (_)\n");
   mostra(figurinhas, selecionado, 10, quant_fig, 'Stadiums');
   mostra(figurinhas, selecionado, 1, quant_fig, 'Official Match Ball');
}
void qatar(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf(" _____  _____  _____  _____  ___\n");
   printf("(  _  )(  _  )(_   _)(  _  )|  _`\\\n");
   printf("| ( ) || (_) |  | |  | (_) || (_) )\n");
   printf("| | | ||  _  |  | |  |  _  || ,  /\n");
   printf("| (('\\|| | | |  | |  | | | || |\\ \\\n");
   printf("(___\\_)(_) (_)  (_)  (_) (_)(_) (_)\n");   
   mostra(figurinhas, selecionado, 20, quant_fig, 'Qatar');
}
void equador(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf(" ___    _____  _   _  _____  ___    _____  ___  \n");
   printf("(  _`\\ (  _  )( ) ( )(  _  )(  _`\\ (  _  )|  _`\\ \n");
   printf("| (_(_)| ( ) || | | || (_) || | ) || ( ) || (_) )\n");
   printf("|  _)_ | | | || | | ||  _  || | | )| | | || ,  / \n");
   printf("| (_( )| (('\\|| (_) || | | || |_) || (_) || |\\ \\ \n");
   printf("(____/'(___\\_)(_____)(_) (_)(____/'(_____)(_) (_)\n");                                               
                                                 
   mostra(figurinhas, selecionado, 20, quant_fig, 'Ecuador');
}
void senegal(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf(" ___    ___    _   _  ___    ___    _____  _\n");
   printf("(  _`\\ (  _`\\ ( ) ( )(  _`\\ (  _`\\ (  _  )( )\n");
   printf("| (_(_)| (_(_)| `\\| || (_(_)| ( (_)| (_) || |\n");
   printf("`\\__ \\ |  _)_ | , ` ||  _)_ | |___ |  _  || |  _ \n");
   printf("( )_) || (_( )| |`\\ || (_( )| (_, )| | | || |_( )\n");
   printf("`\\____)(____/'(_) (_)(____/'(____/'(_) (_)(____/'\n");

   mostra(figurinhas, selecionado, 20, quant_fig, 'Senegal');
}
void holanda(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf(" _   _  _____  _      _____  _   _  ___    _____ \n");
   printf("( ) ( )(  _  )( )    (  _  )( ) ( )(  _`\\ (  _  )\n");
   printf("| |_| || ( ) || |    | (_) || `\\| || | ) || (_) |\n");
   printf("|  _  || | | || |  _ |  _  || , ` || | | )|  _  |\n");
   printf("| | | || (_) || |_( )| | | || |`\\ || |_) || | | |\n");
   printf("(_) (_)(_____)(____/'(_) (_)(_) (_)(____/'(_) (_)\n");                                              
                                                 
   mostra(figurinhas, selecionado, 20, quant_fig, 'Netherlands');
}
void inglaterra(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf(" _  _   _  ___    _      _____  _____  ___    ___    ___    _____ \n");
   printf("(_)( ) ( )(  _`\\ ( )    (  _  )(_   _)(  _`\\ |  _`\\ |  _`\\ (  _  )\n");
   printf("| || `\\| || ( (_)| |    | (_) |  | |  | (_(_)| (_) )| (_) )| (_) |\\\n");
   printf("| || , ` || |___ | |  _ |  _  |  | |  |  _)_ | ,  / | ,  / |  _  |\n");
   printf("| || |`\\ || (_, )| |_( )| | | |  | |  | (_( )| |\\ \\ | |\\ \\ | | | |\n");
   printf("(_)(_) (_)(____/'(____/'(_) (_)  (_)  (____/'(_) (_)(_) (_)(_) (_)\n");

   mostra(figurinhas, selecionado, 20, quant_fig, 'England');
}
void ira(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf("            _   _ \n");
   printf("         /' \\/' )\n");
   printf("         (_/\\__/' \n\n");
   printf(" _  ___    _____\n");
   printf("(_)|  _`\\ (  _  )\n");
   printf("| || (_) )| (_) |\n");
   printf("| || ,  / |  _  |\n");
   printf("| || |\\ \\ | | | |\n");
   printf("(_)(_) (_)(_) (_)\n");

   mostra(figurinhas, selecionado, 20, quant_fig, 'Iran');
}
void estados_unidos(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf(" _   _  ___    _____ \n");
   printf("( ) ( )(  _`\\ (  _  )\n");
   printf("| | | || (_(_)| (_) |\n");
   printf("| | | |`\\__ \\ |  _  |\n");
   printf("| (_) |( )_) || | | |\n");
   printf("(_____)`\\____)(_) (_)\n");
                     
   mostra(figurinhas, selecionado, 20, quant_fig, 'USA');
}
void pais_de_gales(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf(" ___    _____  _  ___       ___    ___       ___    _____  _      ___    ___   \n");
   printf("(  _`\\ (  _  )(_)(  _`\\    (  _`\\ (  _`\\    (  _`\\ (  _  )( )    (  _`\\ (  _`\\ \n");
   printf("| |_) )| (_) || || (_(_)   | | ) || (_(_)   | ( (_)| (_) || |    | (_(_)| (_(_)\n");
   printf("| ,__/'|  _  || |`\\__ \\    | | | )|  _)_    | |___ |  _  || |  _ |  _)_ `\\__ \\ \n");
   printf("| |    | | | || |( )_) |   | |_) || (_( )   | (_, )| | | || |_( )| (_( )( )_) |\n");
   printf("(_)    (_) (_)(_)`\\____)   (____/'(____/'   (____/'(_) (_)(____/'(____/'`\\____)\n");

   mostra(figurinhas, selecionado, 20, quant_fig, 'Wales');
}
void argentina(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf(" _____  ___    ___    ___    _   _  _____  _  _   _  _____ \n");
   printf("(  _  )|  _`\\ (  _`\\ (  _`\\ ( ) ( )(_   _)(_)( ) ( )(  _  )\n");
   printf("| (_) || (_) )| ( (_)| (_(_)| `\\| |  | |  | || `\\| || (_) |\n");
   printf("|  _  || ,  / | |___ |  _)_ | , ` |  | |  | || , ` ||  _  |\n");
   printf("| | | || |\\ \\ | (_, )| (_( )| |`\\ |  | |  | || |`\\ || | | |\n");
   printf("(_) (_)(_) (_)(____/'(____/'(_) (_)  (_)  (_)(_) (_)(_) (_)\n");
                                                         
   mostra(figurinhas, selecionado, 20, quant_fig, 'Argentina');
}
void arabia_saudita(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf(" _____  ___    _____  ___    _  _____     ___    _____  _   _  ___    _  _____  _____ \n");
   printf("(  _  )|  _`\\ (  _  )(  _`\\ (_)(  _  )   (  _`\\ (  _  )( ) ( )(  _`\\ (_)(_   _)(  _  )\n");
   printf("| (_) || (_) )| (_) || (_) )| || (_) |   | (_(_)| (_) || | | || | ) || |  | |  | (_) |\n");
   printf("|  _  || ,  / |  _  ||  _ <'| ||  _  |   `\\__ \\ |  _  || | | || | | )| |  | |  |  _  |\n");
   printf("| | | || |\\ \\ | | | || (_) )| || | | |   ( )_) || | | || (_) || |_) || |  | |  | | | |\n");
   printf("(_) (_)(_) (_)(_) (_)(____/'(_)(_) (_)   `\\____)(_) (_)(_____)(____/'(_)  (_)  (_) (_)\n");

   mostra(figurinhas, selecionado, 20, quant_fig, 'Saudi Arabia');
}
void mexico(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf("           __  \n");
   printf("          /_/ \n\n");
   printf("        ___    _    _  _  ___    _____ \n");
   printf("/'\\_/`\\(  _`\\ ( )  ( )(_)(  _`\\ (  _  )\n");
   printf("|     || (_(_)`\\`\\/'/'| || ( (_)| ( ) |\n");
   printf("| (_) ||  _)_   >  <  | || |  _ | | | |\n");
   printf("| | | || (_( ) /'/\\`\\ | || (_( )| (_) |\n");
   printf("(_) (_)(____/'(_)  (_)(_)(____/'(_____)\n");
                                       
   mostra(figurinhas, selecionado, 20, quant_fig, 'Mexico');
}
void polonia(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf("                       __  \n");
   printf("                      /  \\ \n");
   printf("                     (_/\\_) \n\n");
   printf(" ___    _____  _      _____  _   _  _  _____ \n");
   printf("(  _`\\ (  _  )( )    (  _  )( ) ( )(_)(  _  )\n");
   printf("| |_) )| ( ) || |    | ( ) || `\\| || || (_) |\n");
   printf("| ,__/'| | | || |  _ | | | || , ` || ||  _  |\n");
   printf("| |    | (_) || |_( )| (_) || |`\\ || || | | |\n");              
   printf("(_)    (_____)(____/'(_____)(_) (_)(_)(_) (_)\n");                                           
                                             
   mostra(figurinhas, selecionado, 20, quant_fig, 'Poland');
}
void franca(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf(" ___    ___    _____  _   _  ___    _____ \n");
   printf("(  _`\\ |  _`\\ (  _  )( ) ( )(  _`\\ (  _  )\n");
   printf("| (_(_)| (_) )| (_) || `\\| || ( (_)| (_) |\n");
   printf("|  _)  | ,  / |  _  || , ` || |  _ |  _  |\n");
   printf("| |    | |\\ \\ | | | || |`\\ || (_( )| | | |\n");
   printf("(_)    (_) (_)(_) (_)(_) (_)(____/'(_) (_)\n");
   printf("                              \\__, \\\n");
   printf("                              (____/  \n");

   mostra(figurinhas, selecionado, 20, quant_fig, 'France');
}
void australia(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf("                                        __\n");
   printf("                                       /_/\n\n");
   printf(" _____  _   _  ___    _____  ___    _____  _      _  _____ \n");
   printf("(  _  )( ) ( )(  _`\\ (_   _)|  _`\\ (  _  )( )    (_)(  _  )\n");
   printf("| (_) || | | || (_(_)  | |  | (_) )| (_) || |    | || (_) |\n");
   printf("|  _  || | | |`\\__ \\   | |  | ,  / |  _  || |  _ | ||  _  |\n");
   printf("| | | || (_) |( )_) |  | |  | |\\ \\ | | | || |_( )| || | | |\n");
   printf("(_) (_)(_____)`\\____)  (_)  (_) (_)(_) (_)(____/'(_)(_) (_)\n");

   mostra(figurinhas, selecionado, 20, quant_fig, 'Australia');
}
void dinamarca(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf(" ___    _  _   _  _____         _____  ___    ___    _____ \n");
   printf("(  _`\\ (_)( ) ( )(  _  )/'\\_/`\\(  _  )|  _`\\ (  _`\\ (  _  )\n");
   printf("| | ) || || `\\| || (_) ||     || (_) || (_) )| ( (_)| (_) |\n");
   printf("| | | )| || , ` ||  _  || (_) ||  _  || ,  / | |  _ |  _  |\n");
   printf("| |_) || || |`\\ || | | || | | || | | || |\\ \\ | (_( )| | | |\n");
   printf("(____/'(_)(_) (_)(_) (_)(_) (_)(_) (_)(_) (_)(____/'(_) (_)\n");

   mostra(figurinhas, selecionado, 20, quant_fig, 'Denmark');
}
void tunisia(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf("                      __  \n");
   printf("                     /_/\n\n");
   printf(" _____  _   _  _   _  _  ___    _  _____ \n");
   printf("(_   _)( ) ( )( ) ( )(_)(  _`\\ (_)(  _  )\n");
   printf("  | |  | | | || `\\| || || (_(_)| || (_) |\n");
   printf("  | |  | | | || , ` || |`\\__ \\ | ||  _  |\n");
   printf("  | |  | (_) || |`\\ || |( )_) || || | | |\n");
   printf("  (_)  (_____)(_) (_)(_)`\\____)(_)(_) (_)\n");
                                    
   mostra(figurinhas, selecionado, 20, quant_fig, 'Tunisia');
}
void espanha(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf(" ___    ___    ___    _____  _   _  _   _  _____ \n");
   printf("(  _`\\ (  _`\\ (  _`\\ (  _  )( ) ( )( ) ( )(  _  )\n");
   printf("| (_(_)| (_(_)| |_) )| (_) || `\\| || |_| || (_) |\n");
   printf("|  _)_ `\\__ \\ | ,__/'|  _  || , ` ||  _  ||  _  |\n");
   printf("| (_( )( )_) || |    | | | || |`\\ || | | || | | |\n");
   printf("(____/'`\\____)(_)    (_) (_)(_) (_)(_) (_)(_) (_)\n");

  mostra(figurinhas, selecionado, 20, quant_fig, 'Spain');
}
void costa_rica(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf(" ___    _____  ___    _____  _____     ___    _  ___    _____ \n");
   printf("(  _`\\ (  _  )(  _`\\ (_   _)(  _  )   |  _`\\ (_)(  _`\\ (  _  )\n");
   printf("| ( (_)| ( ) || (_(_)  | |  | (_) |   | (_) )| || ( (_)| (_) |\n");
   printf("| |  _ | | | |`\\__ \\   | |  |  _  |   | ,  / | || |  _ |  _  |\n");
   printf("| (_( )| (_) |( )_) |  | |  | | | |   | |\\ \\ | || (_( )| | | |\n");
   printf("(____/'(_____)`\\____)  (_)  (_) (_)   (_) (_)(_)(____/'(_) (_)\n");

   mostra(figurinhas, selecionado, 20, quant_fig, 'Costa Rica');
}
void alemanha(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf(" _____  _      ___           _____  _   _  _   _  _____ \n");
   printf("(  _  )( )    (  _`\\ /'\\_/`\\(  _  )( ) ( )( ) ( )(  _  )\n");
   printf("| (_) || |    | (_(_)|     || (_) || `\\| || |_| || (_) |\n");
   printf("|  _  || |  _ |  _)_ | (_) ||  _  || , ` ||  _  ||  _  |\n");
   printf("| | | || |_( )| (_( )| | | || | | || |`\\ || | | || | | |\n");
   printf("(_) (_)(____/'(____/'(_) (_)(_) (_)(_) (_)(_) (_)(_) (_)\n");

   mostra(figurinhas, selecionado, 20, quant_fig, 'Germany');
}
void japao(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf("                        _   _ \n");
   printf("                      /' \\/' )\n");
   printf("                     (_/\\__/' \n\n");
   printf(" _____  _____  ___    _____  _____ \n");
   printf("(___  )(  _  )(  _`\\ (  _  )(  _  )\n");
   printf("    | || (_) || |_) )| (_) || ( ) |\n");
   printf(" _  | ||  _  || ,__/'|  _  || | | |\n");
   printf("( )_| || | | || |    | | | || (_) |\n");
   printf("`\\___/'(_) (_)(_)    (_) (_)(_____)\n");

   mostra(figurinhas, selecionado, 20, quant_fig, 'Japao');
}
void belgica(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf("          __  \n");
   printf("         /_/\n\n");
   printf(" ___    ___    _      ___    _  ___    _____ \n");
   printf("(  _`\\ (  _`\\ ( )    (  _`\\ (_)(  _`\\ (  _  )\n");
   printf("| (_) )| (_(_)| |    | ( (_)| || ( (_)| (_) |\n");
   printf("|  _ <'|  _)_ | |  _ | |___ | || |  _ |  _  |\n");
   printf("| (_) )| (_( )| |_( )| (_, )| || (_( )| | | |\n");
   printf("(____/'(____/'(____/'(____/'(_)(____/'(_) (_)\n");

   mostra(figurinhas, selecionado, 20, quant_fig, 'Belgium');
}
void canada(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf("                                      __  \n");
   printf("                                     /_/\n\n");
   printf(" ___    _____  _   _  _____  ___    _____ \n");
   printf("(  _`\\ (  _  )( ) ( )(  _  )(  _`\\ (  _  )\n");
   printf("| ( (_)| (_) || `\\| || (_) || | ) || (_) |\n");
   printf("| |  _ |  _  || , ` ||  _  || | | )|  _  |\n");
   printf("| (_( )| | | || |`\\ || | | || |_) || | | |\n");
   printf("(____/'(_) (_)(_) (_)(_) (_)(____/'(_) (_)\n");                                       
                                    
   mostra(figurinhas, selecionado, 20, quant_fig, 'Canada');
}
void marrocos(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf("        _____  ___    ___    _____  ___    _____  ___   \n");
   printf("/'\\_/`\\(  _  )|  _`\\ |  _`\\ (  _  )(  _`\\ (  _  )(  _`\\ \n");
   printf("|     || (_) || (_) )| (_) )| ( ) || ( (_)| ( ) || (_(_)\n");
   printf("| (_) ||  _  || ,  / | ,  / | | | || |  _ | | | |`\\__ \\ \n");
   printf("| | | || | | || |\\ \\ | |\\ \\ | (_) || (_( )| (_) |( )_) |\n");
   printf("(_) (_)(_) (_)(_) (_)(_) (_)(_____)(____/'(_____)`\\____)\n");

   mostra(figurinhas, selecionado, 20, quant_fig, 'Marrocco');
}
void croacia(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf("                         __  \n");
   printf("                        /_/\n\n");
   printf(" ___    ___    _____  _____  ___    _  _____\n");
   printf("(  _`\\ |  _`\\ (  _  )(  _  )(  _`\\ (_)(  _  )\n");
   printf("| ( (_)| (_) )| ( ) || (_) || ( (_)| || (_) |\n");
   printf("| |  _ | ,  / | | | ||  _  || |  _ | ||  _  |\n");
   printf("| (_( )| |\\ \\ | (_) || | | || (_( )| || | | |\n");
   printf("(____/'(_) (_)(_____)(_) (_)(____/'(_)(_) (_)\n");

   mostra(figurinhas, selecionado, 20, quant_fig, 'Croatia');
}
void brasil(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf(" ___    ___    _____  ___    _  _   \n");
   printf("(  _`\\ |  _`\\ (  _  )(  _`\\ (_)( ) \n");
   printf("| (_) )| (_) )| (_) || (_(_)| || |  \n");
   printf("|  _ <'| ,  / |  _  |`\\__ \\ | || |  _ \n");
   printf("| (_) )| |\\ \\ | | | |( )_) || || |_( )\n");
   printf("(____/'(_) (_)(_) (_)`\\____)(_)(____/'\n");

   mostra(figurinhas, selecionado, 20, quant_fig, 'Brazil');
}
void servia(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf("          __  \n");
   printf("         /_/\n");
   printf(" ___    ___    ___    _   _  _  _____ \n");
   printf("(  _`\\ (  _`\\ |  _`\\ ( ) ( )(_)(  _  )\n");
   printf("| (_(_)| (_(_)| (_) )| | | || || (_) |\n");
   printf("`\\__ \\ |  _)_ | ,  / | | | || ||  _  |\n");
   printf("( )_) || (_( )| |\\ \\ | \\_/ || || | | |\n");
   printf("`\\____)(____/'(_) (_)`\\___/'(_)(_) (_)\n");
   

   mostra(figurinhas, selecionado, 20, quant_fig, 'Serbia');
}
void suica(Figurinha* figurinha, Album selecionado,int quant_fig){
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

   mostra(figurinhas, selecionado, 20, quant_fig, 'Switzerland');
}
void camaroes(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf("                                       _   _ \n");
   printf("                                     /' \\/' )\n");
   printf("                                    (_/\\__/'\n");
   printf(" ___    _____         _____  ___    _____  ___    ___  \n");
   printf("(  _`\\ (  _  )/'\\_/`\\(  _  )|  _`\\ (  _  )(  _`\\ (  _`\\ \n");
   printf("| ( (_)| (_) ||     || (_) || (_) )| ( ) || (_(_)| (_(_)\n");
   printf("| |  _ |  _  || (_) ||  _  || ,  / | | | ||  _)_ `\\__ \\ \n");
   printf("| (_( )| | | || | | || | | || |\\ \\ | (_) || (_( )( )_) |\n");
   printf("(____/'(_) (_)(_) (_)(_) (_)(_) (_)(_____)(____/'`\\____) \n");

   mostra(figurinhas, selecionado, 20, quant_fig, 'Cameroon');
}
void portugal(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf(" ___    _____  ___    _____  _   _  ___    _____  _  \n");
   printf("(  _`\\ (  _  )|  _`\\ (_   _)( ) ( )(  _`\\ (  _  )( ) \n");
   printf("| |_) )| ( ) || (_) )  | |  | | | || ( (_)| (_) || | \n");
   printf("| ,__/'| | | || ,  /   | |  | | | || |___ |  _  || |  _\n");
   printf("| |    | (_) || |\\ \\   | |  | (_) || (_, )| | | || |_( )\n");
   printf("(_)    (_____)(_) (_)  (_)  (_____)(____/'(_) (_)(____/'\n");                                                     

   mostra(figurinhas, selecionado, 20, quant_fig, 'Portugal');
}
void gana(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf(" ___    _____  _   _  _____ \n");
   printf("(  _`\\ (  _  )( ) ( )(  _  )\n");
   printf("| ( (_)| (_) || `\\| || (_) |\n");
   printf("| |___ |  _  || , ` ||  _  |\n");
   printf("| (_, )| | | || |`\\ || | | |\n");
   printf("(____/'(_) (_)(_) (_)(_) (_)\n");                          

   mostra(figurinhas, selecionado, 20, quant_fig, 'Ghana');
}
void uruguai(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf(" _   _  ___    _   _  ___    _   _  _____  _ \n");
   printf("( ) ( )|  _`\\ ( ) ( )(  _`\\ ( ) ( )(  _  )(_)\n");
   printf("| | | || (_) )| | | || ( (_)| | | || (_) || |\n");
   printf("| | | || ,  / | | | || |___ | | | ||  _  || |\n");
   printf("| (_) || |\\ \\ | (_) || (_, )| (_) || | | || |\n");
   printf("(_____)(_) (_)(_____)(____/'(_____)(_) (_)(_)\n");

   mostra(figurinhas, selecionado, 20, quant_fig, 'Uruguay');
}

void coreia_do_sul(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf(" ___    _____  ___    ___    _  _____     ___    _____     ___    _   _  _ \n");
   printf("(  _`\\ (  _  )|  _`\\ (  _`\\ (_)(  _  )   (  _`\\ (  _  )   (  _`\\ ( ) ( )( )    \n");
   printf("| ( (_)| ( ) || (_) )| (_(_)| || (_) |   | | ) || ( ) |   | (_(_)| | | || |    \n");
   printf("| |  _ | | | || ,  / |  _)_ | ||  _  |   | | | )| | | |   `\\__ \\ | | | || |  _ \n");
   printf("| (_( )| (_) || |\\ \\ | (_( )| || | | |   | |_) || (_) |   ( )_) || (_) || |_( )\n");
   printf("(____/'(_____)(_) (_)(____/'(_)(_) (_)   (____/'(_____)   `\\____)(_____)(____/'\n");
    
   mostra(figurinhas, selecionado, 20, quant_fig, 'Korea Republic');
}
void museu_da_fifa(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf("        _   _  ___    ___    _   _     ___    _____     ___    _  ___    _____ \n");
   printf("/'\\_/`\\( ) ( )(  _`\\ (  _`\\ ( ) ( )   (  _`\\ (  _  )   (  _`\\ (_)(  _`\\ (  _  )\n");
   printf("|     || | | || (_(_)| (_(_)| | | |   | | ) || (_) |   | (_(_)| || (_(_)| (_) |\n");
   printf("| (_) || | | |`\\__ \\ |  _)_ | | | |   | | | )|  _  |   |  _)  | ||  _)  |  _  |\n");
   printf("| | | || (_) |( )_) || (_( )| (_) |   | |_) || | | |   | |    | || |    | | | |\n");
   printf("(_) (_)(_____)`\\____)(____/'(_____)   (____/'(_) (_)   (_)    (_)(_)    (_) (_)\n");
                                                                          
   mostra(figurinhas, selecionado, 11, quant_fig, 'FIFA Museum');
}
void coca_cola(Figurinha* figurinha, Album selecionado,int quant_fig){
   printf(" ___    _____  ___    _____          ___    _____  _      _____ \n");
   printf("(  _`\\ (  _  )(  _`\\ (  _  )        (  _`\\ (  _  )( )    (  _  )\n");
   printf("| ( (_)| ( ) || ( (_)| (_) | ______ | ( (_)| ( ) || |    | (_) |\n");
   printf("| |  _ | | | || |  _ |  _  |(______)| |  _ | | | || |  _ |  _  |\n");
   printf("| (_( )| (_) || (_( )| | | |        | (_( )| (_) || |_( )| | | |\n");
   printf("(____/'(_____)(____/'(_) (_)        (____/'(_____)(____/'(_) (_)\n");  
                                                                
   mostra(figurinhas, selecionado, 20, quant_fig, 'CocanormalCola Team Believers');
}

void folhear_album(Figurinha* figurinha, Album selecionado, int quant_fig){
  
  char tecla;
   int pagina=0;

   capa();
   printf(reset"<- (a)                 (d) ->         (s) Sair\n");


   do{
      
      scanf("%c", &tecla);
      setbuf(stdin,NULL);

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
            system("clear");
            capa();
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 1:
            system("clear");
            simbolos(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 2:
            system("clear");
            estadios_e_bola(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 3:
            system("clear");
            qatar(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 4:
            system("clear");
            equador(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 5:
            system("clear");
            senegal(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 6:
            system("clear");
            holanda(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 7:
            system("clear");
            inglaterra(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 8:
            system("clear");
            ira(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 9:
            system("clear");
            estados_unidos(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 10:
            system("clear");
            pais_de_gales(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 11:
            system("clear");
            argentina(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 12:
            system("clear");
            arabia_saudita(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 13:
            system("clear");
            mexico(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 14:
            system("clear");
            polonia(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 15:
            system("clear");
            franca(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 16:
            system("clear");
            australia(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 17:
            system("clear");
            dinamarca(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 18:
            system("clear");
            tunisia(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 19:
            system("clear");
            espanha(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 20:
            system("clear");
            costa_rica(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 21:
            system("clear");
            alemanha(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 22:
            system("clear");
            japao(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 23:
            system("clear");
            belgica(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 24:
            system("clear");
            canada(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 25:
            system("clear");
            marrocos(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 26:
            system("clear");
            croacia(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 27:
            system("clear");
            brasil(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 28:
            system("clear");
            servia(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 29:
            system("clear");
            suica(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 30:
            system("clear");
            camaroes(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 31:
            system("clear");
            portugal(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 32:
            system("clear");
            gana(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 33:
            system("clear");
            uruguai(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 34:
            system("clear");
            coreia_do_sul(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 35:
            system("clear");
            museu_da_fifa(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 36:
            system("clear");
            coca_cola(figurinha, selecionado,quant_fig);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;


      }

   }while(tecla!=ESC);

}

void dados_album(Album album[]){
  int seletor;
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("De qual album voce deseja os dados?\n");
  scanf("%d", &seletor);
  seletor--;
  printf("Nome do proprietario do album:\t%s\n",album[seletor].proprietario);
  printf("Total de figurinhas coladas:\t%d\n", album[seletor].contador_figurinha);
  printf("Total de figurinhas faltantes:\t%d\n", 679-album[seletor].contador_figurinha);
  printf("Porcentagem de conclusao do album:\t%f%%\n", album[seletor].porcentagem_do_album);
  printf("Total gasto com envelopes:\t%.2f\n", album[seletor].dinheiro_gasto);

  return;
}

void comprar_envelope(){
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

        if (album->posicao_no_album == 0)
        {
            album->fig_coladas = (Figurinha *)calloc(1, sizeof(Figurinha));
            album->fig_repetidas_ou_nao_coladas = (Figurinha *)calloc(1, sizeof(Figurinha));
            album->fig_faltantes = (Figurinha *)calloc(1, sizeof(Figurinha));
        }
        else
        {

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
        }

        for (int j = 0; j <= album->quant_fig; j++)
        {
            if (strcasecmp(figurinha[num].codigo, album->fig_coladas[j].codigo) == 0)
            {
                aux++;
                break;
            }
        }

        if (aux == 1)
        {
            printf("Voce ja possui esta figurinha no seu album! Parabens :)\nAgora, esta figurinha esta salva na relacao de figurinhas repetidas/nao coladas.\n");
            album->fig_repetidas_ou_nao_coladas[album->posicao_repetidas_ou_nao_coladas] = figurinha[num];
            album->posicao_repetidas_ou_nao_coladas++;
        }
        else
        {
            setbuf(stdin, NULL);
            printf("Voce nao possui esta figurinha em seu album. Deseja cola-la?\nS para sim e N para nao. ");
            scanf("%c", &opcao);
            setbuf(stdin, NULL);

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
        }
        setbuf(stdin, NULL);
        printf("\n");
        printf("Porcentagem concluida deste album: %.2f\n\n", album->porcentagem_do_album);
    }
}


void figurinhas_nao_coladas(){}

int adicionar_album(Album album[], int quant_alb){
 int amais, aux = quant_alb;
  printf("Quantos albuns voce quer adicionar?");
  scanf("%d", &amais);
  quant_alb = quant_alb + amais;
  void *realloc(void *album, unsigned int quant_alb);
  for (int i=1; i<quant_alb; i++){
    strcpy(album[0].proprietario, album[i].proprietario);
  }

  printf("Mais %d album(s) foram adicionados\n", amais);

  return quant_alb;
}

int excluir_album(Album album[], int quant_alb, int quant_fig){
  int amenos, aux;
  printf("Quantos albuns voce quer excluir?");
  scanf("%d", &amenos);
  if (amenos < quant_alb){
   for (int i=0; i<amenos; i++){
    for(int j=0; j<quant_alb; j++){
      printf("album %d\n", j);
    }
    for (int a=0; a<amenos; a++){
    printf("Qual album deseja excluir?\n");
    scanf("%d", &aux);
    if(aux = quant_alb){
      quant_alb--;
      void *realloc(void *album, unsigned int quant_alb);
      break;
    }
    if (aux < quant_alb){
        for (int j=aux; j<quant_alb; j++){
          album[j].contador_figurinha=album[j+1].contador_figurinha;
          album[j].dinheiro_gasto=album[j+1].dinheiro_gasto;
          album[j].porcentagem_do_album=album[j+1].porcentagem_do_album;
          strcpy(album[j].proprietario,album[j+1].proprietario);
          for (int k=0; k<quant_fig; k++){
            strcpy(album[j].figurinhas_coladas[k],album[j+1].figurinhas_coladas[k]);
            strcpy(album[j].figurinhas_faltantes[k],album[j+1].figurinhas_faltantes[k]);
          }
      }
      quant_alb--;
      void *realloc(void *album, unsigned int quant_alb);
    }
    }
   }
  }
  else printf("Quantidade excede a de albuns atuais\n");

  return quant_alb;

}

int cadastrar_figurinha(Figurinha figurinha[], int quant_fig){
  int amais;
  printf("Quantas figurinhas vc deseja cadastrar?\n");
  scanf("%d", &amais);
  quant_fig = quant_fig + amais;
  void *realloc(void *figurinha, unsigned int quant_fig);
  limpar_struct(figurinha);
  for (int i=0; i<quant_fig; i++){
    if (strcmp(figurinha[i].codigo, "00000")==0){
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
  }

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
      system("clear");
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
      __fpurge(stdin);
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
   usleep(5000000);
   system("clear");
   printf("Digite as palavras na ordem em que apareceram:\n");
   for(int i=0; i<5; i++){
      printf("Palavra %d: ", i+1);
      fgets(resposta, 29, stdin);
      resposta[strcspn(resposta, "\n")]='\0';
      __fpurge(stdin);
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

void trocar_figurinha(char repetida, Figurinha figurinhas, Album* selecionado){
   int probabilidade;
   int sorteio;
   srand(time(0));
   probabilidade = rand()%10;
   if(probabilidade>0 && probabilidade<=3){
      printf("O dono da banca fugiu! Bem-vindo à Apucarana\n");
   }else{
      for(int i=0; i<10; i++){
         for(int j=0; j<10; j++){
            if(strcasecmp(figurinhas[i].codigo, repetida)==1){
               //adicionar o numero de figurinhas coladas 
               selecionado->figurinhas_coladas[] = figurinhas[i].codigo;
            }
         }
      }
   }
}

int main(){
  Album album[0];
  Figurinha figurinha[0];
  Album selecionado;
  int menu=1, menualbum=1, quant_alb, quant_fig=0;
  int moedas=200;
  char opcao;

  printf("Quantos albuns gostaria de cadastrar?\n");
  scanf("%d", &quant_alb);
  
  void *realloc(void *album, unsigned int quant_alb);

  while (menu!=0){
   printf(YEL"Moedas %d\n", moedas);
   printf(MAG" =========================================================================\n");
   printf(MAG"||"WHT"                             Álbum da Copa 2022                        "MAG"||\n");
   printf(MAG" =========================================================================\n"); 
   printf(MAG"\nMenu:\n\n");
   printf(WHT"\t1 - Folhear Álbum\n\t2 - Comprar Envelope\n\t3 - Figurinhas Não Coladas\n");
   printf("\t4 - Dados do Álbum\n\t5 - Configurara Álbum\n\t6 - Cadastrar Figurinha\n");
   printf("\t7 - Ganhar Moedas\n\t8 - Trocar Figurinha Repetida\n"RED"\t0 - Sair\n\n");
   printf(reset"Digite a opção desejada: ");  
   scanf("%d", &menu);
   switch (menu){
      case 0:
         break;
      case 1:
         int seletor;
         printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
         printf("Qual album deseja folhear?");
         scanf("%d", &seletor);
         selecionado = album[seletor];
        folhear_album(figurinha,selecionado);
        break;
      case 2:
         do{
            printf("Comprar envelope por 4 moedas? (s/n)\n");
         scanf("%c", &opcao);
         __fpurge(stdin);
         if(opcao=='n' || opcao=='N'){
            break;
         }else if(opcao!='s' || opcao!='S'){
            printf("Resposta inválida!\n");
         }
         }while (opcao!='s' || opcao!='S');
         
         if(moedas>4){
            moedas = moedas - 4;
            comprar_envelope();
         }else{
            printf("Você não possui moedas suficiente!\n");
         }
        break;
      case 3:
        figurinhas_nao_coladas();
        break;
      case 4:
        dados_album(album);
        break;
      case 5:
        while (menualbum!=0){
          printf("\t1. Adicionar album\n\t2. Excluir album\n\t0. Voltar ao menu principal\n");
          scanf("%d", &menualbum);
          switch (menualbum){
            case 1:
              quant_alb= adicionar_album(album, quant_alb);
              break;
            case 2:
              quant_alb= excluir_album(album, quant_alb, quant_fig);
              break;
            default:
               printf("Opção inválida!\n");
               break;
          }
        }
        break;
      case 6:
        quant_fig = cadastrar_figurinha(figurinha, quant_fig);
        break;
      case 7:
         ganhar_moedas(&moedas);
         break;
      case 8:
         printf("Qual o álbum escolhido? \n");
         scanf("%s", seletor);
         selecionado = album[seletor];
         printf("Digite o código da figurinha que deseja trocar: ");
         fgets(repetida, 29, stdin);
         repetida[strcspn(repetida, "\n")]='\0';
         __fpurge(stdin);
         for(int i=0;i<quant_fig; i++){
            if(strcasecmp(repetida,album[seletor].figurinhas_[i])==0){
               strcpy(album[seletor].figurinhas,"0000000000");
            }
         }
         trocar_figurinha(repetida, figurinhas, &selecionado);         
         break;
      default:
         printf("Opção inválida! Tente novamente!\n");
    }
  }


  return 0;
}
