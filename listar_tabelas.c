#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include "tabela.h"

void listarTabelas(){
  //listando todos os txt, falta retirar o .txt  
  printf("----TABELAS----- \n");
  DIR *p;
  struct dirent *pp;     
  p = opendir ("./");
  int controle = 0;
  if (p != NULL)
  {
    while ((pp = readdir (p))!=NULL) {
      int length = strlen(pp->d_name);
      if (strncmp(pp->d_name + length - 4, ".txt", 4) == 0) {   
        if(strcmp(pp->d_name, "respostas.txt")==0 || strcmp(pp->d_name, "pk.txt")==0){
          }
          else{
          printf("%.*s\n",length - 4, pp->d_name);
          controle = 1;
          }
      }
    }
    if(controle != 1){
      printf(RED"Nenhuma tabela foi encontrada\n"RESET);
    }
    (void) closedir (p);
  }
  printf("-----------------\n");
}
