#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "tabela.h"
void apagarTabela(){
   char *nome_tabela = (char *) malloc (20*sizeof(char));  
   FILE *tabela;
   int op;
   do{
      printf("Digite o nome da sua tabela: \n");      
      fscanf(stdin, "%s", nome_tabela);           
      tabela = fopen(strcat(nome_tabela, ".txt"), "r+");     
      if (tabela==NULL)
      {
        printf("Essa tabela não existe!.\n");        
      }
    }while(tabela == NULL);
    for(int i = 0 ; i<30; i++){
      printf("=");
    }
    printf("\n");
    op=remove(nome_tabela);
    if(op==0){
      printf("Tabela %s removida com sucesso\n",nome_tabela);
    }
    else{
      printf("Erro :( \n");
    }
    fclose(tabela);
    free(nome_tabela);
}
