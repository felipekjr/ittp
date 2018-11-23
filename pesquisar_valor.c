#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"
char **listarColunasOrdem(FILE *tabela);
void pesquisarMaiores(FILE *tabela, char* valor);
void pesquisarValor(){
    char *nome_tabela;  
    char **colunas, *coluna_escolhida, *valor;          
    int option;
    FILE *tabela;       
    nome_tabela = (char *) malloc (20*sizeof(char));
    coluna_escolhida = (char *) malloc (20*sizeof(char));
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
            printf("Escolha uma das colunas disponíveis: \n");            
            colunas = listarColunasOrdem(tabela);  
            for(int i = 0; i<3; i++){
                fprintf(stdout,"%s\n", colunas[i]);
            }                
        do{
            getchar();
            fscanf(stdin, "%s", coluna_escolhida);            
            if(verificaColunas(tabela, coluna_escolhida)!=1){
                printf("Essa coluna não existe! Digite novamente:\n");
            }
        }while(verificaColunas(tabela, coluna_escolhida)!=1);
        //o valor da coluna digitado está correto
        printf("Digite o valor a ser pesquisado: ");
        fscanf(stdin, "%s", valor);
        do{
            printf("ESCOLHA UMA DAS OPÇÕES:\n");
            printf("0 - SAIR\n");
            printf("1 - Valores maiores que o informado\n");
            printf("2 - Valores maiores ou iguais que o informado\n");
            printf("3 - Valores iguais que o informado\n");
            scanf("%d", &option);
            switch(option){
                case 1: pesquisarMaiores(tabela, valor); break;
                default: break;
            }
        }while(option != 0);

    }
}


char **listarColunasOrdem(FILE *tabela){
    char *coluna;
    int count = 0; 
    int qnt_colunas = contarColunas(tabela, '[');
    char **aux = (char**) calloc(qnt_colunas, sizeof(char*));
    char buffer[256];
    fseek(tabela ,0, SEEK_SET);     
    while (fgets(buffer,256, tabela)){                  
        if(strstr(buffer, "{") == NULL){
            // É UMA TUPLA                   
            aux[count] = (char*) calloc(20, sizeof(char));
            if(aux[count] == NULL){
                fprintf(stderr, "ERRO");
            }else{                
                coluna = strtok(strtok(buffer,"["),"]");
                sprintf(aux[count], "%d-%s",count+1, coluna); 
                count++;                 
            }                 
        }
    }    
    return aux;       
}

void pesquisarMaiores(FILE *tabela, char* valor){
    fprintf(stdout, "%s", valor);
}
