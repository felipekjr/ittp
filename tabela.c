#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"

//cria uma tabela como um arquivo txt.
int criarTabela(char *arquivo)
{
	FILE *ptr_arq; //Ponteiro do arquivo	
  	//criando o arquivo com o nome da tabela
	ptr_arq = fopen(arquivo, "w+t");
		if(ptr_arq==NULL){		
		return -1;
		}	
  	fclose(ptr_arq);
	return 0;
}

//escreve os atributos que a tabela possui (colunas)
int escreverAtributos(char *arquivo, Atributo *atributo){
	FILE *ptr_arq = fopen(arquivo, "w+");
	if(ptr_arq==NULL){		
		return -1;
	}else{
		fprintf(ptr_arq, "Atributo: %s, %d, %d", atributo->nome, atributo->tipo, atributo->tamanho);		
	}	
	fclose(ptr_arq);
	return 0;
}

int nomeTabela(){

}
