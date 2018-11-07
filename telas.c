#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"

void v_criarTabela(){    
    	char * nome = NULL; //Nome da tabela-arquivo.txt
    	
	//nomeando o arquivo de texto
	printf("Digite o nome da sua tabela: ");
    	getchar();
	nome = (char *) malloc (20*sizeof(char));
	fgets(nome, 20, stdin);
  	strcat(nome, ".txt");
    if(criarTabela(nome)<0){
        printf("Falha ao criar arquivo!\n");
    }else{
        printf("Arquivo criado com sucesso!\n");
    }
}

void v_listarTabelas(){}