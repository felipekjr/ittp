#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include "tabela.h"


void listarDados(){
    char *nome_tabela;    
    char buffer[256];
    FILE *tabela = fopen("listarDadosTeste.txt", "w+");
    int qnt_colunas = contarColunas(tabela);
    printf("Digite o nme da tabela:");
    fscanf(stdin, "%s", nome_tabela);
    fseek(tabela ,0, SEEK_CUR);        
    // while (fgets(buffer,256, tabela)) 
    // {                         
               
    // }
}