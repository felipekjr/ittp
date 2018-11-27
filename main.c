#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"

int main(int argc, char const *argv[])
{
	int op = 0;
	do{

	printf("Escolha as funcionalidades:\n   0-Sair\n   1-Criar uma tabela\n   2-Listar todas as tabelas\n   3-Criar uma nova linha na tabela\n   4-Listar todos os dados de uma tabela\n   5-Pesquisar um valor em uma tabela\n   6-Apagar valor de uma tabela\n   7-Apagar uma tabela\n");
	scanf("%d", &op);
	switch (op)
		{
	    case 1:
            criarTabela(); //checkpoint 1
            break;
            case 2:
            listarTabelas(); //checkpoint 1
            break;
            case 3:
            inserirRegistros(); //checkpoint 2
            break;
            case 4:
            listarDados(); //checkpoint 2
            break;
            case 5:
            pesquisarValor(); //checkpoint 3
            break;
            case 6:
            // apagarRegistro(); //checkpoint 4
            break;
            case 7:
            // apagarTabela(); //checkpoint 4
            break;
            default:
            printf("Valor inválido!");
            break;
        }
    }while(op != 0);
    return 0;
}
