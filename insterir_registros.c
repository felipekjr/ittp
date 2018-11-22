#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"
#include <ctype.h>

int verificaPK(FILE *tabela, char *nome);
int contarLinhas(FILE* tabela);

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
      printf("Digite o nome da sua tabela: \n");      
      fscanf(stdin, "%s", nome_tabela);           
      tabela = fopen(strcat(nome_tabela, ".txt"), "r+");     
      if (tabela==NULL)
      {
        printf("Essa tabela não existe!.\n");        
      }
    }while(tabela == NULL);
    //le cada linha do arquivo        
    colunas = contarColunas(tabela, '[');
    printf("%i", colunas);
    //colocando para ler no inicio do documento
    tabela = fopen (nome_tabela, "a+");
    fseek(tabela,0,SEEK_SET);
    printf("=Digite os valores da tabela %s=\n", nome_tabela);
    while (EOF != fscanf(tabela, "%[^\n]\n", buffer))
    {    
      if(strstr(buffer, "{") == NULL){
          // É UMA COLUNA, tratar o dado
        nome_atributo = strtok(strtok(buffer,","),"[");
        if(count==0){
          do{
            printf("%s): ", nome_atributo);  
            scanf("%s", valor);
            if(verificaPK(tabela, valor)==-1){
            printf("Digite uma chave primaria valida\n");
            }
          }while(verificaPK(tabela, valor)!=0);
        }else{
          printf("%s): ", nome_atributo);  
          scanf("%s", valor);
          fprintf(respostas,"%s\n", valor);
        }
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
    fclose(respostas);
    fclose(tabela);
    free(valor);
    free(nome_tabela);
  }
}

int verificaPK(FILE *tabela, char *nome){   
    char *linha;  
    char buffer[256];    
        fseek(tabela ,0, SEEK_SET);        
        while (EOF != fscanf(tabela, "%[^\n]\n", buffer))
        {    
            if(strstr(buffer, "[") == NULL){
            // É UMA TUPLA
            linha = strtok(strtok(buffer,"{"),",");
            printf("> %s\n", linha);
            if(strcmp(nome,linha)==0){
              //já existe
              return -1;
            }
            return 0;        
            }
        }       
    } 

int contarLinhas(FILE* tabela){
    int colunas = 0, ch = 0;
    while(!feof(tabela))
      {
        ch = fgetc(tabela);
        if(ch == '{')
        {
          colunas++;
        }
      }
      return colunas;
  }