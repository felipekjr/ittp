#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"


void v_criarTabela();
void v_listarTabelas();
int main(int argc, char const *argv[])
{
    int op = 0;
    do{
        printf("1 - Criar uma tabela\n");
        printf("2 - Listar todas as tabelas\n");
        scanf("%d", &op);
        switch(op){
            case 1: v_criarTabela(); break;
            case 2: v_listarTabelas(); break;
            default: break;
        }
    }while(op != 0);

   

    return 0;
}

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