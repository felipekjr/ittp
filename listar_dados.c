#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"
#include <ctype.h>


void listarDados(){
    char *nome_tabela;  
    char *linha;  
    char buffer[256];    
    FILE *tabela;    
    tabela = fopen ("a.txt", "a+");
    nome_tabela = (char *) malloc (20*sizeof(char));
    if(nome_tabela == NULL){
        printf("Erro com o nome da tabela");       
    }else{        
        printf("Digite o nome da tabela: ");    
        fscanf(stdin, "%s", nome_tabela);
        
        fprintf(stdout, "TABELA: %s\n", nome_tabela);
        fseek(tabela ,0, SEEK_CUR);        
        while (EOF != fscanf(tabela, "%[^\n]\n", buffer))
        {    
            if(strstr(buffer, "[") == NULL){
            // É UMA TUPLA
            linha = strtok(strtok(buffer,"{"),"}");
            printf("> %s\n", linha);         
            }
        }
        free(nome_tabela);        
    }        
    fclose(tabela);    
}