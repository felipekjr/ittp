#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"
#include <ctype.h>

void listarColunas(FILE *tabela);
void listarDados(){
    char *nome_tabela;  
    char *linha;  
    char buffer[256];    
    FILE *tabela;       
    nome_tabela = (char *) malloc (20*sizeof(char));
    if(nome_tabela == NULL){
        printf("Erro com o nome da tabela");       
    }else{        
        do{
            printf("Digite o nome da tabela: ");    
            getchar();
            fscanf(stdin, "%s", nome_tabela);            
            tabela = fopen (strcat(nome_tabela,".txt"), "r+");
            if (tabela==NULL)
            {
                printf("Essa tabela não existe!\n");               
            }        
        }while(tabela == NULL);         
        int s_nome = strlen(nome_tabela);
        fprintf(stdout, "TABELA: %.*s\n", s_nome-4, nome_tabela);                         
        listarColunas(tabela);
        tabela = fopen (nome_tabela, "a+");  
        fseek(tabela ,0, SEEK_CUR);   
        while (EOF != fscanf(tabela, "%[^\n]\n", buffer))
        {    
            if(strstr(buffer, "[") == NULL){
            // É UMA TUPLA
            linha = strtok(strtok(buffer,"{"),"}");
            printf("%s\n", linha);         
            }            
        }
        free(nome_tabela);        
    }        
    fclose(tabela);    
}

void listarColunas(FILE *tabela){
    char *coluna;
    char buffer[256];
    while (EOF != fscanf(tabela, "%[^\n]\n", buffer))
        {    
            if(strstr(buffer, "{") == NULL){
            // É UMA TUPLA
            coluna = strtok(strtok(buffer,"["),"]");
            printf("%s   ", coluna);         
            }
        }
        printf("\n"); 
}