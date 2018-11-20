#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include "tabela.h"
 #include <ctype.h>


void listarDados(){
    char *nome_tabela;  
    char *dado;  
    char buffer[256];
    FILE *tabela = fopen("a.txt", "r+");    
    // printf("Digite o nme da tabela:");
    // fscanf(stdin, "%s", nome_tabela);
    fseek(tabela ,0, SEEK_CUR);        
    while (EOF != fscanf(tabela, "%[^\n]\n", buffer))
    {    
        if(strstr(buffer, "[") == NULL){
          // É UMA COLUNA, tratar o dado
          dado = strtok(strtok(buffer,"{"),"}");
          printf("> %s\n", dado);         
        }
    }
}