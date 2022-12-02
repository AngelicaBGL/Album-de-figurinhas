#include "album.h"
/**
 * @brief Limpar a tela
 * 
 */
void limpa_tela(){
   #ifdef linux
      system("clear");
   #elif _WIN64
      system("cls");
   #else

   #endif  
}
/**
 * @brief Limpar o buffer
 * 
 */
void limpa_buffer(){
   #ifdef linux
      #include <stdio_ext.h>
      __fpurge(stdin);
   #elif _WIN64
      setbuf(stdin,NULL);
   #else

   #endif
}
/**
 * @brief Contar segundos
 * 
 * @param seg 
 */
void tempo(int seg){
   
   #ifdef linux
   int tempo = 1000000;
   tempo = seg*tempo;
      usleep(tempo);
   #elif _WIN64
      int tempo = 1000;
      tempo = seg*tempo;
      #include <Windows.h>
      Sleep(tempo);
   #else

   #endif
}