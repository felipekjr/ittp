#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "tabela.h"
  #include <ctype.h>
  void inserirRegistros(){
    char *nome_tabela;
    nome_tabela = (char *) malloc (20*sizeof(char));
    char *nome_atributo;    
    int count = 0;       
    char buffer[256];   
    FILE *tabela;
    do{
    // printf("Digite o nome da sua tabela: \n");
    // //fgets(nome_tabela, 20, stdin);
    // scanf("%s", nome_tabela);
    // printf("%s\n", nome_tabela);
    // strcat(nome_tabela, ".txt");
    //tabela = fopen(nome_tabela, "r");
    tabela = fopen ("a.txt", "r+");
    if (tabela==NULL)
    {
    	printf("Digite um nome de uma tabela já existente.\n");
    	printf("O que foi digitado foi %s\n",nome_tabela);
    }
    }while(tabela == NULL);
    //le cada linha do arquivo        
    while (EOF != fscanf(tabela, "%[^\n]\n", buffer))
    {    
        if(strstr(buffer, "{") == NULL){
          // É UMA COLUNA, tratar o dado
          nome_atributo = strtok(strtok(buffer,","),"[");
          printf("> %s\n", nome_atributo);
          count++;
        }
    }        
    fclose(tabela);
    free(nome_tabela);
    
  }

