#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "tabela.h"
  #include <ctype.h>

  int contarColuna(FILE* tabela);

  void inserirRegistros(){
    char *valor = (char*) malloc (20*sizeof(char));
    char *nome_tabela = (char *) malloc (20*sizeof(char)); ;
    char *nome_atributo;    
    int count = 0, colunas;       
    char buffer[256];   
    FILE *tabela;
    FILE *respostas= fopen("respostas.txt", "w+");
    if(respostas==NULL){
      printf("Erro");
    }else{ 
    do{
    // printf("Digite o nome da sua tabela: \n");
    // //fgets(nome_tabela, 20, stdin);
    // scanf("%s", nome_tabela);
    // printf("%s\n", nome_tabela);
    // strcat(nome_tabela, ".txt");
    //tabela = fopen(nome_tabela, "r");
    tabela = fopen ("a.txt", "a+");
    if (tabela==NULL)
    {
    	printf("Digite um nome de uma tabela já existente.\n");
    	printf("O que foi digitado foi %s\n",nome_tabela);
    }
    }while(tabela == NULL);
    //le cada linha do arquivo        
    colunas = contarColuna(tabela);
    //colocando para ler no inicio do documento
    fseek(tabela,0,SEEK_SET);
    while (EOF != fscanf(tabela, "%[^\n]\n", buffer))
    {    
        if(strstr(buffer, "{") == NULL){
          // É UMA COLUNA, tratar o dado
          nome_atributo = strtok(strtok(buffer,","),"[");
          printf("Digite o valor para a coluna %s: ", nome_atributo);
          scanf("%s", valor);
          fprintf(respostas,"%s\n", valor);
          count++;
        }
    }   
    fseek(tabela,0,SEEK_END);
    fprintf(tabela,"\n{");
    fseek(respostas,0, SEEK_SET);
    for(int i = 1; i<=colunas;i++){
      fscanf(respostas,"%s, ", valor);
      if (i == colunas){
        fprintf(tabela,"%s}", valor);
      }else{
        fprintf(tabela,"%s, ", valor);
      }
    }
    fclose(tabela);
    free(nome_tabela);
    }
  }
  int contarColuna(FILE* tabela){
    int coluna = 0, ch = 0;
    while(!feof(tabela))
      {
        ch = fgetc(tabela);
        if(ch == '[')
        {
          coluna++;
        }
      }
      return coluna;
  }
