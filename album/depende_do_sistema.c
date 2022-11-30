#include "album.h"

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
      #include <stdio_ext.h>
      __fpurge(stdin);
   #else _WIN64
      setbuf(stdin,NULL);

   #endif
}
void tempo(){
   #ifdef linux
      usleep(5000000);
   #else _WIN64
      #include <Windows.h>
      Sleep(5000);

   #endif
}
