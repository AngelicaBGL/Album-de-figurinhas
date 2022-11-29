#include "album.h"
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