#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
A finalidade desse código é criar uma função que crie uma tabela em um arquivo txt.
A priori, será o main. Porém, no projeto final, será um arquivo .h
*/
int main(int argc, char const *argv[])
{
  
	char * nome = NULL; //Nome da tabela-arquivo.txt
	FILE *ptr_arq; //Ponteiro do arquivo

  //nomeando o arquivo de texto
	printf("Digite o nome da sua tabela: ");
	nome = (char *) malloc (20*sizeof(char));
	fgets(nome, 20, stdin);
  	strcat(nome, ".txt");

  //criando o arquivo com o nome da tabela
	ptr_arq = fopen(nome, "w+t");
	if(ptr_arq==NULL){
		printf("Erro de abertura!\n");
		return -2;
	}
	else{
		printf("RODOU!\n");
	}
  	fclose(ptr_arq);
	return 0;
}
