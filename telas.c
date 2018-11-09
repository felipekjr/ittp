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
  char nome[20];
  int count = 0;
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
     printf("Digite o nome da coluna (max 20 caracteres): \n");
     fgets(nome, 20, stdin);
     if (ctr!=0 && ctr<=5)
     {
      switch(ctr){
       case 1:
       *(ptr_att+count).nome=nome;
       *(ptr_att+count).tipo=1;
       *(ptr_att+count).tamanho=sizeof(char);
       break;
       case 2:
       *(ptr_att+count).nome=nome;
       *(ptr_att+count).tipo=2;
       *(ptr_att+count).tamanho=sizeof(int);
       break;
       case 3:
       *(ptr_att+count).nome=nome;
       *(ptr_att+count).tipo=3;
       *(ptr_att+count).tamanho=sizeof(float);
       break;
       case 4:
       *(ptr_att+count).nome=nome;
       *(ptr_att+count).tipo=4;
       *(ptr_att+count).tamanho=sizeof(double);
       break;
       case 5:
       *(ptr_att+count).nome=nome;
       *(ptr_att+count).tipo=5;
       printf("Digite o tamanho da string que desejas: \n");
       scanf("%d", &ctr);
       *(ptr_att+count).tamanho=sizeof(char)*ctr;
       break; 
       default:
       printf("Numero invalido!\n");
     }
     count++;
     ptr_att= (Atributo*) realloc (ptr_att,count*sizeof(Atributo));
     
   }

 } while(ctr != 0)
}

}

void v_listarTabelas(){}
