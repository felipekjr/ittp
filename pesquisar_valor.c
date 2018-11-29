#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"
#include <ctype.h>

typedef struct colunalinha{
	char *coluna;
	char *linha;		
}ColunaLinha;

ColunaLinha* listarValores(FILE* tabela, char* separador);
char **listarLinhas(FILE* tabela);
char **listarColunasOrdem(FILE *tabela);
void pesquisarMaiores(FILE *tabela, char* valor, char* coluna);
void pesquisarMaioresIguais(FILE *tabela, char* valor, char* coluna);
void pesquisarIguais(FILE *tabela, char* valor, char* coluna);
void pesquisarMenores(FILE *tabela, char* valor, char* coluna);
void pesquisarMenoresIguais(FILE *tabela, char* valor, char* coluna);
void pesquisarProximos(FILE *tabela, char* valor, char* coluna);

void pesquisarValor(){
    char *nome_tabela;  
    char **colunas, *coluna_escolhida, *valor;          
    int option = -1, qnt_colunas, existeColuna = 0;
    FILE *tabela;       
    valor = (char*)calloc(20,1);
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
                printf(RED"Essa tabela não existe!\n"RESET);               
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
        getchar();      
        scanf("%s", valor);        
        while(option != 0){
            printf("ESCOLHA UMA DAS OPÇÕES:\n");
            printf("0 - SAIR\n");
            printf("1 - Valores maiores que o informado\n");
            printf("2 - Valores maiores ou iguais que o informado\n");
            printf("3 - Valores iguais que o informado\n");
            printf("4 - Valores menores que o valor informado\n"); 
            printf("5 - Valores menores ou iguais que o valor informado\n"); 
            printf("6 - Valores próximos ao valor informado(se aplica apenas se a coluna for do tipo string)\n"); 
            scanf("%d", &option);
                    
            switch(option){                
                case 1: pesquisarMaiores(tabela, valor, coluna_escolhida); break;
                case 2: pesquisarMaioresIguais(tabela, valor,coluna_escolhida); break;
                case 3: pesquisarIguais(tabela, valor, coluna_escolhida); break;
                case 4: pesquisarMenores(tabela, valor, coluna_escolhida); break;
                case 5: pesquisarMenoresIguais(tabela, valor, coluna_escolhida); break;
                case 6: pesquisarProximos(tabela, valor, coluna_escolhida); break;
                default: break;
            }  
        }      

    }
    free(valor);
    free(coluna_escolhida);
    free(nome_tabela);

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

void pesquisarMaiores(FILE *tabela, char *valor, char *coluna){    
    int qnt_linhas = contarSeparador(tabela, '{'); 
    ColunaLinha* obj = listarValores(tabela, coluna); 
    printf("RESULTADO:\n");  
    for(int i = 0; i < qnt_linhas; i++){        
        if(atof(valor) != 0 && atof(obj[i].coluna) != 0 ){
            if(atof(obj[i].coluna) > atoi(valor)){                
                printf("%s\n", obj[i].linha);
            }else{
                continue;
            }            
        }      
        else if(strcmp(obj[i].coluna,valor)>0){
             printf("%s\n", obj[i].linha);
        }    
    }     
}
void pesquisarMaioresIguais(FILE *tabela, char *valor, char *coluna){
    int qnt_linhas = contarSeparador(tabela, '{'); 
    ColunaLinha* obj = listarValores(tabela, coluna);  
    printf("RESULTADO:\n"); 
    for(int i = 0; i < qnt_linhas; i++){                
        if(atof(valor) != 0 && atof(obj[i].coluna) != 0 ){
            if(atof(obj[i].coluna) >= atoi(valor)){
                printf("%s\n", obj[i].linha);
            }else{
                continue;
            }            
        }      
        else if(strcmp(obj[i].coluna,valor)>=0){
             printf("%s\n", obj[i].linha);
        }    
    
    }  
}
void pesquisarIguais(FILE *tabela, char *valor, char *coluna){
    int qnt_linhas = contarSeparador(tabela, '{'); 
    ColunaLinha* obj = listarValores(tabela, coluna);  
    printf("RESULTADO:\n"); 
    for(int i = 0; i < qnt_linhas; i++){
       
        if(atof(valor) != 0 && atof(obj[i].coluna) != 0 ){
            if(atof(obj[i].coluna) == atoi(valor)){
                printf("%s\n", obj[i].linha);
            }else{
                continue;
            }            
        }      
        else if(strcmp(obj[i].coluna,valor)==0){
             printf("%s\n", obj[i].linha);
        }    
    
    }  
}
void pesquisarMenores(FILE *tabela, char *valor, char *coluna){
    int qnt_linhas = contarSeparador(tabela, '{'); 
    ColunaLinha* obj = listarValores(tabela, coluna);  
    printf("RESULTADO:\n"); 
    for(int i = 0; i < qnt_linhas; i++){
              
        if(atof(valor) != 0 && atof(obj[i].coluna) != 0 ){
            if(atof(obj[i].coluna) < atoi(valor)){
                printf("%s\n", obj[i].linha);
            }else{
                continue;
            }            
        }      
        else if(strcmp(obj[i].coluna,valor)<0){
             printf("%s\n", obj[i].linha);
        }    
    
    }  
}
void pesquisarMenoresIguais(FILE *tabela, char *valor, char *coluna){
    int qnt_linhas = contarSeparador(tabela, '{'); 
    ColunaLinha* obj = listarValores(tabela, coluna);  
    printf("RESULTADO:\n"); 
    for(int i = 0; i < qnt_linhas; i++){
            
        if(atof(valor) != 0 && atof(obj[i].coluna) != 0 ){
            if(atof(obj[i].coluna) <= atoi(valor)){
                printf("%s\n", obj[i].linha);
            }else{
                continue;
            }            
        }      
        else if(strcmp(obj[i].coluna,valor)<=0){
             printf("%s\n", obj[i].linha);
        }    
    
    }  
}
void pesquisarProximos(FILE *tabela, char *valor, char *coluna){
    int qnt_linhas = contarSeparador(tabela, '{'); 
    ColunaLinha* obj = listarValores(tabela, coluna);  
    printf("RESULTADO:\n"); 
    for(int i = 0; i < qnt_linhas; i++){
        if(strstr(valor,obj[i].coluna)!= NULL || strstr(obj[i].coluna,valor)!= NULL){
            printf("%s\n", obj[i].linha);        
        }
    }  
}

ColunaLinha* listarValores(FILE* tabela, char* coluna){
    int qnt_linhas = contarSeparador(tabela, '{');   
    char **linhas = listarLinhas(tabela); 
    char **linhas_aux = listarLinhas(tabela); 
    char **linhas_token = (char**) calloc(qnt_linhas, sizeof(char*));      
    ColunaLinha *obj = (ColunaLinha*) calloc(qnt_linhas, sizeof(ColunaLinha)); 
    int j,count;        
    for(int i = 0; i<qnt_linhas; i++){  
        j = 0;                
        //corta a linha de acordo com o separador em substrings 
        linhas_token[i] = (char*) calloc(20, sizeof(char));
        linhas_token[i] = strtok(linhas[i],",");
        while(linhas_token[i] != NULL)       
        {               
            
            if(j == atoi(coluna)-1){                                
                obj[i].coluna = linhas_token[i];           
                obj[i].linha = linhas_aux[i];                  
                j++;
            }else if(j!=atoi(coluna)-1){                              
                j++;    
            }
            else{
                j++;
            }  
            linhas_token[i] =strtok(NULL, ",");
            
        }                 
    }  
    return obj;
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
