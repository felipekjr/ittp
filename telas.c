#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"

int definirAtributos();

typedef struct tabela{
	int id;
	char *nome;
}Tabela;

typedef struct atributo{
	char *nome;
	int tipo;
	int tamanho;
}Atributo;


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
    	if(definirAtributos()){

    	}
	}
}

int definirAtributos(){
	int count = 1;
	Atributo *ptr_att = (Atributo*) calloc(1,sizeof(Atributo));   
	if (ptr_att==NULL)
	{
    	printf("Erro de memória!\n");
    	return (-3);
	}
	else{
	int ctr;
	do{
    	//tela de tipos
    	printf("Digite o tipo da coluna: \n\n1-CHAR\n2-INT\n3-FLOAT\n4-DOUBLE\n5-STRING\n0-FIM\n");
    	scanf("%d", &ctr);
    	if (ctr!=0)
    	{
       	switch(ctr){
            	case 1:

       	}
       	ptr_att= (Atributo*) realloc (p,count*sizeof(Atributo));
	count++;
    	}
   	 
	} while(ctr != 0)
	}

}

void v_listarTabelas(){}
