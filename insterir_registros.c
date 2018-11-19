#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "tabela.h"
  void inserirRegistros(){
    char *nome_tabela;
    nome_tabela = (char *) malloc (20*sizeof(char));
    char nome_atributo[20];
    int atb_1;
    int atb_2;
    FILE *tabela = NULL; //Aqui fora utilizado o a pois, diferentemente do w+, não destroi o arquivo já existente, não cria outro e adicona por padrão no final do arquivo. 
    do
    {
    printf("Digite o nome da sua tabela: \n");
    //fgets(nome_tabela, 20, stdin);
    scanf("%s", nome_tabela);
    printf("%s\n", nome_tabela);
    strcat(nome_tabela, ".txt");
    //tabela = fopen(nome_tabela, "r");
    tabela = fopen ("bilbo.txt", "a+");
    if (tabela==NULL)
    {
    	printf("Digite um nome de uma tabela já existente.\n");
    	printf("O que foi digitado foi %s\n",nome_tabela);
    }
    }while(tabela==NULL);   
    //Comandos a serem executados ao digitar uma tabela válida 
    	fscanf(tabela, "[%s, %d, %d]", nome_atributo, &atb_1, &atb_2);
    	printf("%s,%d,%d\n",nome_atributo, atb_1, atb_2);
    
    fclose(tabela);
    free(nome_tabela);
    
  }
