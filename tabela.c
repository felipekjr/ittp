#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"
/*
A finalidade desse código é criar uma função que crie uma tabela em um arquivo txt.
A priori, será o main. Porém, no projeto final, será um arquivo .h
*/
int criarTabela(char *nome)
{
	FILE *ptr_arq; //Ponteiro do arquivo
  	//criando o arquivo com o nome da tabela
	ptr_arq = fopen(nome, "w+t");
	if(ptr_arq==NULL){		
		return -1;
	}	
  	fclose(ptr_arq);
	return 0;
}
