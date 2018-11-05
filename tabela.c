#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"
/*
A finalidade desse código é uma função que crie uma tabela em um arquivo txt.
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
