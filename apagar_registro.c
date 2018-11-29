#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"
//int jogarPkArquivo(FILE *tabela, char *nome, FILE *pk);
void apagarRegistro(){
  char *nome_tabela = (char *) malloc (20*sizeof(char));  
  FILE *tabela;
  FILE *pk= fopen("pk.txt", "w+");
  FILE *output = fopen ("respostas.txt","w");
  char *p_key = (char*)calloc(20,sizeof(char));
  char *linha = (char *) calloc (1001,sizeof(char));
  char *linha1 = (char *) calloc (1001,sizeof(char));
  char aux[20];
  char *buffer = (char *) calloc (1001,sizeof(char));
  int crtl=0;
  do{
      printf("Digite o nome da sua tabela que deseja excluir o registro: \n");      
      fscanf(stdin, "%s", nome_tabela);           
      tabela = fopen(strcat(nome_tabela, ".txt"), "r+");     
      if (tabela==NULL)
      {
        printf(RED"Erro! Essa tabela não existe!\n"RESET);        
      }
    }while(tabela == NULL);
      printf(GREEN"Tabela escolhida com sucesso!\n"RESET);    
      printf("Digite a primary key (obs, se a PK nao existir, não vai apagar nenhuma linha):\n");
      scanf("%s", p_key);
      fseek(tabela ,0, SEEK_SET);
      int controle = 0;
      int cont = 0;
        do{  
          fgets(buffer, 1001, tabela);
          fprintf(pk,"%s",buffer);
        }while(!feof(tabela));
          fseek(tabela ,0, SEEK_SET);
          fseek(pk ,0, SEEK_SET);
          while(!feof(tabela)){
            fgets(buffer, 1001, tabela);
            fgets(linha1, 1001, pk);
            linha = strtok(strtok(buffer,"{"),",");
            if(strcmp(p_key,linha)!=0){                
              fprintf(output,"%s",linha1);
            }
            if(strcmp(p_key,linha)==0){
                controle = 1;    
            }
          }         
    if(controle == 0){
        printf("Chave primária inexistente!\n");
    }
    remove(nome_tabela);
    rename("respostas.txt",nome_tabela);
    free(nome_tabela);
    fclose(tabela);
    fclose(pk);
    fclose(output);
}
