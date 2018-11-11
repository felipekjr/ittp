#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"

//cria uma tabela como um arquivo txt.
int criarTabela(char *nome){	
	FILE *banco = fopen("banco.txt", "w+");		
	FILE *ptr_arq; //Ponteiro do arquivo	
  	//criando o arquivo com o nome da tabela
	ptr_arq = fopen(strcat(nome, ".txt"), "w+t");
	if(ptr_arq==NULL){		
		return -1;
	}
  	fclose(ptr_arq);
	fclose(banco);
	return 0;
}

//escreve os atributos que a tabela possui (colunas)
int escreverAtributos(char *nome, Atributo *atributo){
	FILE *ptr_arq = fopen(strcat(nome, ".txt"), "w+");
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
