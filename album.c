#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  char figurinhas_coladas[678][5];
  char figurinhas_faltantes[678][5];
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
void simbolos(Figurinha* figurinha, Album* album){
   printf(" ___    _         ___    _____  _      _____  ___       ___    _____     ___    _____  ___    _____ \n");
   printf("(  _`\\ (_)/'\\_/`\\(  _`\\ (  _  )( )    (  _  )(  _`\\    (  _`\\ (  _  )   (  _`\\ (  _  )(  _`\\ (  _  )\n"); 
   printf("| (_(_)| ||     || (_) )| ( ) || |    | ( ) || (_(_)   | | ) || (_) |   | ( (_)| ( ) || |_) )| (_) |\n");
   printf("`\\__ \\ | || (_) ||  _ <'| | | || |  _ | | | |`\\__ \\    | | | )|  _  |   | |  _ | | | || ,__/'|  _  |\n");
   printf("( )_) || || | | || (_) )| (_) || |_( )| (_) |( )_) |   | |_) || | | |   | (_( )| (_) || |    | | | |\n");
   printf("`\\____)(_)(_) (_)(____/'(_____)(____/'(_____)`\\____)   (____/'(_) (_)   (____/'(_____)(_)    (_) (_)\n");

   mostra(figurinhas, album, 8, 278, 'Content');                                                       
}
void estadios_e_bola(Figurinha* figurinha, Album* album){

   printf("    ___    ___    _____  _____  ___    _  _____  ___       ___       ___    _____  _      _____\n");
   printf("(  _`\\ (  _`\\ (_   _)(  _  )(  _`\\ (_)(  _  )(  _`\\    (  _`\\    (  _`\\ (  _  )( )    (  _  )\n");
   printf("| (_(_)| (_(_)  | |  | (_) || | ) || || ( ) || (_(_)   | (_(_)   | (_) )| ( ) || |    | (_) |\n");
   printf("|  _)_ `\\__ \\   | |  |  _  || | | )| || | | |`\\__ \\    |  _)_    |  _ <'| | | || |  _ |  _  |\n");
   printf("| (_( )( )_) |  | |  | | | || |_) || || (_) |( )_) |   | (_( )   | (_) )| (_) || |_( )| | | |\n");
   printf("(____/'`\\____)  (_)  (_) (_)(____/'(_)(_____)`\\____)   (____/'   (____/'(_____)(____/'(_) (_)\n");
   mostra(figurinhas, album, 10, 278, 'Stadiums');
   mostra(figurinhas, album, 1, 278, 'Official Match Ball');
}
void qatar(Figurinha* figurinha, Album* album){
   printf(" _____  _____  _____  _____  ___\n");
   printf("(  _  )(  _  )(_   _)(  _  )|  _`\\\n");
   printf("| ( ) || (_) |  | |  | (_) || (_) )\n");
   printf("| | | ||  _  |  | |  |  _  || ,  /\n");
   printf("| (('\\|| | | |  | |  | | | || |\\ \\\n");
   printf("(___\\_)(_) (_)  (_)  (_) (_)(_) (_)\n");   
   mostra(figurinhas, album, 20, 278, 'Qatar');
}
void equador(Figurinha* figurinha, Album* album){
   printf(" ___    _____  _   _  _____  ___    _____  ___  \n");
   printf("(  _`\\ (  _  )( ) ( )(  _  )(  _`\\ (  _  )|  _`\\ \n");
   printf("| (_(_)| ( ) || | | || (_) || | ) || ( ) || (_) )\n");
   printf("|  _)_ | | | || | | ||  _  || | | )| | | || ,  / \n");
   printf("| (_( )| (('\\|| (_) || | | || |_) || (_) || |\\ \\ \n");
   printf("(____/'(___\\_)(_____)(_) (_)(____/'(_____)(_) (_)\n");                                               
                                                 
   mostra(figurinhas, album, 20, 278, 'Ecuador');
}
void senegal(Figurinha* figurinha, Album* album){
   printf(" ___    ___    _   _  ___    ___    _____  _\n");
   printf("(  _`\\ (  _`\\ ( ) ( )(  _`\\ (  _`\\ (  _  )( )\n");
   printf("| (_(_)| (_(_)| `\\| || (_(_)| ( (_)| (_) || |\n");
   printf("`\\__ \\ |  _)_ | , ` ||  _)_ | |___ |  _  || |  _ \n");
   printf("( )_) || (_( )| |`\\ || (_( )| (_, )| | | || |_( )\n");
   printf("`\\____)(____/'(_) (_)(____/'(____/'(_) (_)(____/'\n");

   mostra(figurinhas, album, 20, 278, 'Senegal');
}
void holanda(Figurinha* figurinha, Album* album){
   printf(" _   _  _____  _      _____  _   _  ___    _____ \n");
   printf("( ) ( )(  _  )( )    (  _  )( ) ( )(  _`\\ (  _  )\n");
   printf("| |_| || ( ) || |    | (_) || `\\| || | ) || (_) |\n");
   printf("|  _  || | | || |  _ |  _  || , ` || | | )|  _  |\n");
   printf("| | | || (_) || |_( )| | | || |`\\ || |_) || | | |\n");
   printf("(_) (_)(_____)(____/'(_) (_)(_) (_)(____/'(_) (_)\n");                                              
                                                 
   mostra(figurinhas, album, 20, 278, 'Netherlands');
}
void inglaterra(Figurinha* figurinha, Album* album){
   printf(" _  _   _  ___    _      _____  _____  ___    ___    ___    _____ \n");
   printf("(_)( ) ( )(  _`\\ ( )    (  _  )(_   _)(  _`\\ |  _`\\ |  _`\\ (  _  )\n");
   printf("| || `\\| || ( (_)| |    | (_) |  | |  | (_(_)| (_) )| (_) )| (_) |\\\n");
   printf("| || , ` || |___ | |  _ |  _  |  | |  |  _)_ | ,  / | ,  / |  _  |\n");
   printf("| || |`\\ || (_, )| |_( )| | | |  | |  | (_( )| |\\ \\ | |\\ \\ | | | |\n");
   printf("(_)(_) (_)(____/'(____/'(_) (_)  (_)  (____/'(_) (_)(_) (_)(_) (_)\n");

   mostra(figurinhas, album, 20, 278, 'England');
}
void ira(Figurinha* figurinha, Album* album){
   printf("            _   _ \n");
   printf("         /' \\/' )\n");
   printf("         (_/\\__/' \n\n");
   printf(" _  ___    _____\n");
   printf("(_)|  _`\\ (  _  )\n");
   printf("| || (_) )| (_) |\n");
   printf("| || ,  / |  _  |\n");
   printf("| || |\\ \\ | | | |\n");
   printf("(_)(_) (_)(_) (_)\n");

   mostra(figurinhas, album, 20, 278, 'Iran');
}
void estados_unidos(Figurinha* figurinha, Album* album){
   printf(" _   _  ___    _____ \n");
   printf("( ) ( )(  _`\\ (  _  )\n");
   printf("| | | || (_(_)| (_) |\n");
   printf("| | | |`\\__ \\ |  _  |\n");
   printf("| (_) |( )_) || | | |\n");
   printf("(_____)`\\____)(_) (_)\n");
                     
   mostra(figurinhas, album, 20, 278, 'USA');
}
void pais_de_gales(Figurinha* figurinha, Album* album){
   printf(" ___    _____  _  ___       ___    ___       ___    _____  _      ___    ___   \n");
   printf("(  _`\\ (  _  )(_)(  _`\\    (  _`\\ (  _`\\    (  _`\\ (  _  )( )    (  _`\\ (  _`\\ \n");
   printf("| |_) )| (_) || || (_(_)   | | ) || (_(_)   | ( (_)| (_) || |    | (_(_)| (_(_)\n");
   printf("| ,__/'|  _  || |`\\__ \\    | | | )|  _)_    | |___ |  _  || |  _ |  _)_ `\\__ \\ \n");
   printf("| |    | | | || |( )_) |   | |_) || (_( )   | (_, )| | | || |_( )| (_( )( )_) |\n");
   printf("(_)    (_) (_)(_)`\\____)   (____/'(____/'   (____/'(_) (_)(____/'(____/'`\\____)\n");

   mostra(figurinhas, album, 20, 278, 'Wales');
}
void argentina(Figurinha* figurinha, Album* album){
   printf(" _____  ___    ___    ___    _   _  _____  _  _   _  _____ \n");
   printf("(  _  )|  _`\\ (  _`\\ (  _`\\ ( ) ( )(_   _)(_)( ) ( )(  _  )\n");
   printf("| (_) || (_) )| ( (_)| (_(_)| `\\| |  | |  | || `\\| || (_) |\n");
   printf("|  _  || ,  / | |___ |  _)_ | , ` |  | |  | || , ` ||  _  |\n");
   printf("| | | || |\\ \\ | (_, )| (_( )| |`\\ |  | |  | || |`\\ || | | |\n");
   printf("(_) (_)(_) (_)(____/'(____/'(_) (_)  (_)  (_)(_) (_)(_) (_)\n");
                                                         
   mostra(figurinhas, album, 20, 278, 'Argentina');
}
void arabia_saudita(Figurinha* figurinha, Album* album){
   printf(" _____  ___    _____  ___    _  _____     ___    _____  _   _  ___    _  _____  _____ \n");
   printf("(  _  )|  _`\\ (  _  )(  _`\\ (_)(  _  )   (  _`\\ (  _  )( ) ( )(  _`\\ (_)(_   _)(  _  )\n");
   printf("| (_) || (_) )| (_) || (_) )| || (_) |   | (_(_)| (_) || | | || | ) || |  | |  | (_) |\n");
   printf("|  _  || ,  / |  _  ||  _ <'| ||  _  |   `\\__ \\ |  _  || | | || | | )| |  | |  |  _  |\n");
   printf("| | | || |\\ \\ | | | || (_) )| || | | |   ( )_) || | | || (_) || |_) || |  | |  | | | |\n");
   printf("(_) (_)(_) (_)(_) (_)(____/'(_)(_) (_)   `\\____)(_) (_)(_____)(____/'(_)  (_)  (_) (_)\n");

   mostra(figurinhas, album, 20, 278, 'Saudi Arabia');
}
void mexico(Figurinha* figurinha, Album* album){
   printf("           __  \n");
   printf("          /_/ \n\n");
   printf("        ___    _    _  _  ___    _____ \n");
   printf("/'\\_/`\\(  _`\\ ( )  ( )(_)(  _`\\ (  _  )\n");
   printf("|     || (_(_)`\\`\\/'/'| || ( (_)| ( ) |\n");
   printf("| (_) ||  _)_   >  <  | || |  _ | | | |\n");
   printf("| | | || (_( ) /'/\\`\\ | || (_( )| (_) |\n");
   printf("(_) (_)(____/'(_)  (_)(_)(____/'(_____)\n");
                                       
   mostra(figurinhas, album, 20, 278, 'Mexico');
}
void polonia(Figurinha* figurinha, Album* album){
   printf("                       __  \n");
   printf("                      /  \\ \n");
   printf("                     (_/\\_) \n\n");
   printf(" ___    _____  _      _____  _   _  _  _____ \n");
   printf("(  _`\\ (  _  )( )    (  _  )( ) ( )(_)(  _  )\n");
   printf("| |_) )| ( ) || |    | ( ) || `\\| || || (_) |\n");
   printf("| ,__/'| | | || |  _ | | | || , ` || ||  _  |\n");
   printf("| |    | (_) || |_( )| (_) || |`\\ || || | | |\n");              
   printf("(_)    (_____)(____/'(_____)(_) (_)(_)(_) (_)\n");                                           
                                             
   mostra(figurinhas, album, 20, 278, 'Poland');
}
void franca(Figurinha* figurinha, Album* album){
   printf(" ___    ___    _____  _   _  ___    _____ \n");
   printf("(  _`\\ |  _`\\ (  _  )( ) ( )(  _`\\ (  _  )\n");
   printf("| (_(_)| (_) )| (_) || `\\| || ( (_)| (_) |\n");
   printf("|  _)  | ,  / |  _  || , ` || |  _ |  _  |\n");
   printf("| |    | |\\ \\ | | | || |`\\ || (_( )| | | |\n");
   printf("(_)    (_) (_)(_) (_)(_) (_)(____/'(_) (_)\n");
   printf("                              \\__, \\\n");
   printf("                              (____/  \n");

   mostra(figurinhas, album, 20, 278, 'France');
}
void australia(Figurinha* figurinha, Album* album){
   printf("                                        __\n");
   printf("                                       /_/\n\n");
   printf(" _____  _   _  ___    _____  ___    _____  _      _  _____ \n");
   printf("(  _  )( ) ( )(  _`\\ (_   _)|  _`\\ (  _  )( )    (_)(  _  )\n");
   printf("| (_) || | | || (_(_)  | |  | (_) )| (_) || |    | || (_) |\n");
   printf("|  _  || | | |`\\__ \\   | |  | ,  / |  _  || |  _ | ||  _  |\n");
   printf("| | | || (_) |( )_) |  | |  | |\\ \\ | | | || |_( )| || | | |\n");
   printf("(_) (_)(_____)`\\____)  (_)  (_) (_)(_) (_)(____/'(_)(_) (_)\n");

   mostra(figurinhas, album, 20, 278, 'Australia');
}
void dinamarca(Figurinha* figurinha, Album* album){
   printf(" ___    _  _   _  _____         _____  ___    ___    _____ \n");
   printf("(  _`\\ (_)( ) ( )(  _  )/'\\_/`\\(  _  )|  _`\\ (  _`\\ (  _  )\n");
   printf("| | ) || || `\\| || (_) ||     || (_) || (_) )| ( (_)| (_) |\n");
   printf("| | | )| || , ` ||  _  || (_) ||  _  || ,  / | |  _ |  _  |\n");
   printf("| |_) || || |`\\ || | | || | | || | | || |\\ \\ | (_( )| | | |\n");
   printf("(____/'(_)(_) (_)(_) (_)(_) (_)(_) (_)(_) (_)(____/'(_) (_)\n");

   mostra(figurinhas, album, 20, 278, 'Denmark');
}
void tunisia(Figurinha* figurinha, Album* album){
   printf("                      __  \n");
   printf("                     /_/\n\n");
   printf(" _____  _   _  _   _  _  ___    _  _____ \n");
   printf("(_   _)( ) ( )( ) ( )(_)(  _`\\ (_)(  _  )\n");
   printf("  | |  | | | || `\\| || || (_(_)| || (_) |\n");
   printf("  | |  | | | || , ` || |`\\__ \\ | ||  _  |\n");
   printf("  | |  | (_) || |`\\ || |( )_) || || | | |\n");
   printf("  (_)  (_____)(_) (_)(_)`\\____)(_)(_) (_)\n");
                                    
   mostra(figurinhas, album, 20, 278, 'Tunisia');
}
void espanha(Figurinha* figurinha, Album* album){
   printf(" ___    ___    ___    _____  _   _  _   _  _____ \n");
   printf("(  _`\\ (  _`\\ (  _`\\ (  _  )( ) ( )( ) ( )(  _  )\n");
   printf("| (_(_)| (_(_)| |_) )| (_) || `\\| || |_| || (_) |\n");
   printf("|  _)_ `\\__ \\ | ,__/'|  _  || , ` ||  _  ||  _  |\n");
   printf("| (_( )( )_) || |    | | | || |`\\ || | | || | | |\n");
   printf("(____/'`\\____)(_)    (_) (_)(_) (_)(_) (_)(_) (_)\n");

  mostra(figurinhas, album, 20, 278, 'Spain');
}
void costa_rica(Figurinha* figurinha, Album* album){
   printf(" ___    _____  ___    _____  _____     ___    _  ___    _____ \n");
   printf("(  _`\\ (  _  )(  _`\\ (_   _)(  _  )   |  _`\\ (_)(  _`\\ (  _  )\n");
   printf("| ( (_)| ( ) || (_(_)  | |  | (_) |   | (_) )| || ( (_)| (_) |\n");
   printf("| |  _ | | | |`\\__ \\   | |  |  _  |   | ,  / | || |  _ |  _  |\n");
   printf("| (_( )| (_) |( )_) |  | |  | | | |   | |\\ \\ | || (_( )| | | |\n");
   printf("(____/'(_____)`\\____)  (_)  (_) (_)   (_) (_)(_)(____/'(_) (_)\n");

   mostra(figurinhas, album, 20, 278, 'Costa Rica');
}
void alemanha(Figurinha* figurinha, Album* album){
   printf(" _____  _      ___           _____  _   _  _   _  _____ \n");
   printf("(  _  )( )    (  _`\\ /'\\_/`\\(  _  )( ) ( )( ) ( )(  _  )\n");
   printf("| (_) || |    | (_(_)|     || (_) || `\\| || |_| || (_) |\n");
   printf("|  _  || |  _ |  _)_ | (_) ||  _  || , ` ||  _  ||  _  |\n");
   printf("| | | || |_( )| (_( )| | | || | | || |`\\ || | | || | | |\n");
   printf("(_) (_)(____/'(____/'(_) (_)(_) (_)(_) (_)(_) (_)(_) (_)\n");

   mostra(figurinhas, album, 20, 278, 'Germany');
}
void japao(Figurinha* figurinha, Album* album){
   printf("                        _   _ \n");
   printf("                      /' \\/' )\n");
   printf("                     (_/\\__/' \n\n");
   printf(" _____  _____  ___    _____  _____ \n");
   printf("(___  )(  _  )(  _`\\ (  _  )(  _  )\n");
   printf("    | || (_) || |_) )| (_) || ( ) |\n");
   printf(" _  | ||  _  || ,__/'|  _  || | | |\n");
   printf("( )_| || | | || |    | | | || (_) |\n");
   printf("`\\___/'(_) (_)(_)    (_) (_)(_____)\n");

   mostra(figurinhas, album, 20, 278, 'Japao');
}
void belgica(Figurinha* figurinha, Album* album){
   printf("          __  \n");
   printf("         /_/\n\n");
   printf(" ___    ___    _      ___    _  ___    _____ \n");
   printf("(  _`\\ (  _`\\ ( )    (  _`\\ (_)(  _`\\ (  _  )\n");
   printf("| (_) )| (_(_)| |    | ( (_)| || ( (_)| (_) |\n");
   printf("|  _ <'|  _)_ | |  _ | |___ | || |  _ |  _  |\n");
   printf("| (_) )| (_( )| |_( )| (_, )| || (_( )| | | |\n");
   printf("(____/'(____/'(____/'(____/'(_)(____/'(_) (_)\n");

   mostra(figurinhas, album, 20, 278, 'Belgium');
}
void canada(Figurinha* figurinha, Album* album){
   printf("                                      __  \n");
   printf("                                     /_/\n\n");
   printf(" ___    _____  _   _  _____  ___    _____ \n");
   printf("(  _`\\ (  _  )( ) ( )(  _  )(  _`\\ (  _  )\n");
   printf("| ( (_)| (_) || `\\| || (_) || | ) || (_) |\n");
   printf("| |  _ |  _  || , ` ||  _  || | | )|  _  |\n");
   printf("| (_( )| | | || |`\\ || | | || |_) || | | |\n");
   printf("(____/'(_) (_)(_) (_)(_) (_)(____/'(_) (_)\n");                                       
                                    
   mostra(figurinhas, album, 20, 278, 'Canada');
}
void marrocos(Figurinha* figurinha, Album* album){
   printf("        _____  ___    ___    _____  ___    _____  ___   \n");
   printf("/'\\_/`\\(  _  )|  _`\\ |  _`\\ (  _  )(  _`\\ (  _  )(  _`\\ \n");
   printf("|     || (_) || (_) )| (_) )| ( ) || ( (_)| ( ) || (_(_)\n");
   printf("| (_) ||  _  || ,  / | ,  / | | | || |  _ | | | |`\\__ \\ \n");
   printf("| | | || | | || |\\ \\ | |\\ \\ | (_) || (_( )| (_) |( )_) |\n");
   printf("(_) (_)(_) (_)(_) (_)(_) (_)(_____)(____/'(_____)`\\____)\n");

   mostra(figurinhas, album, 20, 278, 'Marrocco');
}
void croacia(Figurinha* figurinha, Album* album){
   printf("                         __  \n");
   printf("                        /_/\n\n");
   printf(" ___    ___    _____  _____  ___    _  _____\n");
   printf("(  _`\\ |  _`\\ (  _  )(  _  )(  _`\\ (_)(  _  )\n");
   printf("| ( (_)| (_) )| ( ) || (_) || ( (_)| || (_) |\n");
   printf("| |  _ | ,  / | | | ||  _  || |  _ | ||  _  |\n");
   printf("| (_( )| |\\ \\ | (_) || | | || (_( )| || | | |\n");
   printf("(____/'(_) (_)(_____)(_) (_)(____/'(_)(_) (_)\n");

   mostra(figurinhas, album, 20, 278, 'Croatia');
}
void brasil(Figurinha* figurinha, Album* album){
   printf(" ___    ___    _____  ___    _  _   \n");
   printf("(  _`\\ |  _`\\ (  _  )(  _`\\ (_)( ) \n");
   printf("| (_) )| (_) )| (_) || (_(_)| || |  \n");
   printf("|  _ <'| ,  / |  _  |`\\__ \\ | || |  _ \n");
   printf("| (_) )| |\\ \\ | | | |( )_) || || |_( )\n");
   printf("(____/'(_) (_)(_) (_)`\\____)(_)(____/'\n");

   mostra(figurinhas, album, 20, 278, 'Brazil');
}
void servia(Figurinha* figurinha, Album* album){
   printf("          __  \n");
   printf("         /_/\n");
   printf(" ___    ___    ___    _   _  _  _____ \n");
   printf("(  _`\\ (  _`\\ |  _`\\ ( ) ( )(_)(  _  )\n");
   printf("| (_(_)| (_(_)| (_) )| | | || || (_) |\n");
   printf("`\\__ \\ |  _)_ | ,  / | | | || ||  _  |\n");
   printf("( )_) || (_( )| |\\ \\ | \\_/ || || | | |\n");
   printf("`\\____)(____/'(_) (_)`\\___/'(_)(_) (_)\n");
   

   mostra(figurinhas, album, 20, 278, 'Serbia');
}
void suica(Figurinha* figurinha, Album* album){
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

   mostra(figurinhas, album, 20, 278, 'Switzerland');
}
void camaroes(Figurinha* figurinha, Album* album){
   printf("                                       _   _ \n");
   printf("                                     /' \\/' )\n");
   printf("                                    (_/\\__/'\n");
   printf(" ___    _____         _____  ___    _____  ___    ___  \n");
   printf("(  _`\\ (  _  )/'\\_/`\\(  _  )|  _`\\ (  _  )(  _`\\ (  _`\\ \n");
   printf("| ( (_)| (_) ||     || (_) || (_) )| ( ) || (_(_)| (_(_)\n");
   printf("| |  _ |  _  || (_) ||  _  || ,  / | | | ||  _)_ `\\__ \\ \n");
   printf("| (_( )| | | || | | || | | || |\\ \\ | (_) || (_( )( )_) |\n");
   printf("(____/'(_) (_)(_) (_)(_) (_)(_) (_)(_____)(____/'`\\____) \n");

   mostra(figurinhas, album, 20, 278, 'Cameroon');
}
void portugal(Figurinha* figurinha, Album* album){
   printf(" ___    _____  ___    _____  _   _  ___    _____  _  \n");
   printf("(  _`\\ (  _  )|  _`\\ (_   _)( ) ( )(  _`\\ (  _  )( ) \n");
   printf("| |_) )| ( ) || (_) )  | |  | | | || ( (_)| (_) || | \n");
   printf("| ,__/'| | | || ,  /   | |  | | | || |___ |  _  || |  _\n");
   printf("| |    | (_) || |\\ \\   | |  | (_) || (_, )| | | || |_( )\n");
   printf("(_)    (_____)(_) (_)  (_)  (_____)(____/'(_) (_)(____/'\n");                                                     

   mostra(figurinhas, album, 20, 278, 'Portugal');
}
void gana(Figurinha* figurinha, Album* album){
   printf(" ___    _____  _   _  _____ \n");
   printf("(  _`\\ (  _  )( ) ( )(  _  )\n");
   printf("| ( (_)| (_) || `\\| || (_) |\n");
   printf("| |___ |  _  || , ` ||  _  |\n");
   printf("| (_, )| | | || |`\\ || | | |\n");
   printf("(____/'(_) (_)(_) (_)(_) (_)\n");                          

   mostra(figurinhas, album, 20, 278, 'Ghana');
}
void uruguai(Figurinha* figurinha, Album* album){
   printf(" _   _  ___    _   _  ___    _   _  _____  _ \n");
   printf("( ) ( )|  _`\\ ( ) ( )(  _`\\ ( ) ( )(  _  )(_)\n");
   printf("| | | || (_) )| | | || ( (_)| | | || (_) || |\n");
   printf("| | | || ,  / | | | || |___ | | | ||  _  || |\n");
   printf("| (_) || |\\ \\ | (_) || (_, )| (_) || | | || |\n");
   printf("(_____)(_) (_)(_____)(____/'(_____)(_) (_)(_)\n");

   mostra(figurinhas, album, 20, 278, 'Uruguay');
}

void coreia_do_sul(Figurinha* figurinha, Album* album){
   printf(" ___    _____  ___    ___    _  _____     ___    _____     ___    _   _  _ \n");
   printf("(  _`\\ (  _  )|  _`\\ (  _`\\ (_)(  _  )   (  _`\\ (  _  )   (  _`\\ ( ) ( )( )    \n");
   printf("| ( (_)| ( ) || (_) )| (_(_)| || (_) |   | | ) || ( ) |   | (_(_)| | | || |    \n");
   printf("| |  _ | | | || ,  / |  _)_ | ||  _  |   | | | )| | | |   `\\__ \\ | | | || |  _ \n");
   printf("| (_( )| (_) || |\\ \\ | (_( )| || | | |   | |_) || (_) |   ( )_) || (_) || |_( )\n");
   printf("(____/'(_____)(_) (_)(____/'(_)(_) (_)   (____/'(_____)   `\\____)(_____)(____/'\n");
    
   mostra(figurinhas, album, 20, 278, 'Korea Republic');
}
void museu_da_fifa(Figurinha* figurinha, Album* album){
   printf("        _   _  ___    ___    _   _     ___    _____     ___    _  ___    _____ \n");
   printf("/'\\_/`\\( ) ( )(  _`\\ (  _`\\ ( ) ( )   (  _`\\ (  _  )   (  _`\\ (_)(  _`\\ (  _  )\n");
   printf("|     || | | || (_(_)| (_(_)| | | |   | | ) || (_) |   | (_(_)| || (_(_)| (_) |\n");
   printf("| (_) || | | |`\\__ \\ |  _)_ | | | |   | | | )|  _  |   |  _)  | ||  _)  |  _  |\n");
   printf("| | | || (_) |( )_) || (_( )| (_) |   | |_) || | | |   | |    | || |    | | | |\n");
   printf("(_) (_)(_____)`\\____)(____/'(_____)   (____/'(_) (_)   (_)    (_)(_)    (_) (_)\n");
                                                                          
   mostra(figurinhas, album, 11, 278, 'FIFA Museum');
}
void coca_cola(Figurinha* figurinha, Album* album){
   printf(" ___    _____  ___    _____          ___    _____  _      _____ \n");
   printf("(  _`\\ (  _  )(  _`\\ (  _  )        (  _`\\ (  _  )( )    (  _  )\n");
   printf("| ( (_)| ( ) || ( (_)| (_) | ______ | ( (_)| ( ) || |    | (_) |\n");
   printf("| |  _ | | | || |  _ |  _  |(______)| |  _ | | | || |  _ |  _  |\n");
   printf("| (_( )| (_) || (_( )| | | |        | (_( )| (_) || |_( )| | | |\n");
   printf("(____/'(_____)(____/'(_) (_)        (____/'(_____)(____/'(_) (_)\n");  
                                                                
   mostra(figurinhas, album, 20, 278, 'CocanormalCola Team Believers');
}

void folhear_album(Figurinha* figurinha, Album* album){
  int seletor;
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Qual album deseja folhear?");
  scanf("%d", &seletor);
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
            capa();
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 1:
            simbolos(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 2:
            estadios_e_bola(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 3:
            qatar(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 4:
            equador(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 5:
            senegal(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 6:
            holanda(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 7:
            inglaterra(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 8:
            ira(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 9:
            estados_unidos(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 10:
            pais_de_gales(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 11:
            argentina(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 12:
            arabia_saudita(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 13:
            mexico(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 14:
            polonia(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 15:
            franca(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 16:
            australia(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 17:
            dinamarca(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 18:
            tunisia(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 19:
            espanha(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 20:
            costa_rica(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 21:
            alemanha(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 22:
            japao(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 23:
            belgica(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 24:
            canada(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 25:
            marrocos(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 26:
            croacia(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 27:
            brasil(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 28:
            servia(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 29:
            suica(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 30:
            camaroes(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 31:
            portugal(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 32:
            gana(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 33:
            uruguai(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 34:
            coreia_do_sul(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 35:
            museu_da_fifa(figurinha, album);
            printf(reset"<- (a)                 (d) ->         (s) Sair\n");
            break;
         case 36:
            coca_cola(figurinha, album);
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

void comprar_envelope(){}

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

int main(){
  Album album[0];
  Figurinha figurinha[0];
  int menu=1, menualbum=1, quant_alb, quant_fig=0;

  printf("Quantos albuns gostaria de cadastrar?\n");
  scanf("%d", &quant_alb);
  
  void *realloc(void *album, unsigned int quant_alb);

  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("\tBEM-VINDO AO ALBUM\n\tO que voce gostaria de fazer?\n");
  while (menu!=0){
    printf("\t1. Folhear o album\n\t2. Comprar envelope\n\t3. Mostrar figurinha nao coladas\n\t4. Mostrar dados do album\n\t5. Configurar Albuns\n\t6. Cadastar Figurinha\n\t0. Sair do album\n\tEscolha a opcao: ");
    scanf("%d", &menu);
    switch (menu){
      case 1:
        folhear_album(figurinha,album);
        break;
      case 2:
        comprar_envelope();
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
          }
        }
        break;
      case 6:
        quant_fig = cadastrar_figurinha(figurinha, quant_fig);
        break;
    }
  }

  return 0;
}
