#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"
char* listarValores(FILE* tabela, int separador);
char **listarLinhas(FILE* tabela);
char **listarColunasOrdem(FILE *tabela);
void pesquisarMaiores(FILE *tabela, char* valor);

void pesquisarValor(){
    char *nome_tabela;  
    char **colunas, *coluna_escolhida, *valor;          
    int option, qnt_colunas, existeColuna = 0;
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
            qnt_colunas = contarSeparador(tabela, '[');        
            colunas = listarColunasOrdem(tabela);  
            for(int i = 0; i< qnt_colunas; i++){
                fprintf(stdout,"%s\n", colunas[i]);
            }                
        do{
            getchar();
            fscanf(stdin, "%s", coluna_escolhida);            
            for(int i = 0; i < qnt_colunas; i++){
                if(strncmp(colunas[i], coluna_escolhida,1) == 0){
                    existeColuna = 1;
                }
            }
            if(existeColuna!=1){
                printf("Opção inválida! Digite novamente:\n");
            }            
        }while(existeColuna != 1);
        //o valor da coluna digitado está correto
        printf("Digite o valor a ser pesquisado: ");        
        fscanf(stdin, "%s", valor);
        getchar();
        while(option != 0){
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
        }      

    }
    fclose(tabela);
}


char **listarColunasOrdem(FILE *tabela){
    char *coluna;
    int count = 0; 
    int qnt_colunas = contarSeparador(tabela, '[');
    char **aux = (char**) calloc(qnt_colunas, sizeof(char*));
    char buffer[256];
    fseek(tabela ,0, SEEK_SET);     
    while (fgets(buffer,256, tabela)){                  
        if(strstr(buffer, "{") == NULL){
            // É UMA COLUNA                  
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
    listarValores(tabela, 1);    
}

char* listarValores(FILE* tabela, int separador){
    int qnt_linhas = contarSeparador(tabela, '{');
    char **linhas = listarLinhas(tabela);
    for(int i = 0; i<qnt_linhas; i++){
        //contar os separadores e exibir
    }
}

char **listarLinhas(FILE* tabela){
    int qnt_linhas = contarSeparador(tabela, '{');    
    int count = 0;
    char buffer[256];
    char *linha;
    char **linhas = (char**) calloc(qnt_linhas, sizeof(char*));
    if(linhas == NULL){
        fprintf(stderr, "Erro");
    }else{        
        fseek(tabela ,0, SEEK_SET);   
        while (fgets(buffer,256, tabela)){
            if(strstr(buffer, "[") == NULL){
                // É UMA TUPLA                 
                linhas[count] = (char*) calloc(256, sizeof(char));
                if(linhas[count] == NULL){
                    fprintf(stderr, "ERRO");
                }else{                             
                    linha = strtok(strtok(buffer,"{"),"}");
                    strcpy(linhas[count], linha);
                    count++;                 
                }                 
            }
        } 
        return linhas;      
    }
}