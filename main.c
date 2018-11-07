#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "telas.h"
#include "tabela.h"


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


