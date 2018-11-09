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
  int count = 0, qnt_atributos = 1, ctr;  
  Atributo *ptr_att = (Atributo*) calloc(qnt_atributos,sizeof(Atributo));   
  if(ptr_att==NULL){
    printf("Erro de memória!\n");
    return (-3);
  }
  else {
    
    printf("---------ATRIBUTOS----------\n");
    do{
    	//definindo as colunas da tabela
      printf("%d", count);      
      printf("Digite o tipo da coluna: \n1-CHAR | 2-INT | 3-FLOAT | 4-DOUBLE | 5-STRING | 0-FIM\n");      
      scanf("%d", &ctr);
      if(ctr!=0 && ctr<=5){ 
        printf("Digite o nome da coluna (max 20 caracteres): \n");  
        getchar();
        fgets(nome, 20, stdin);
        switch(ctr){          
          case 1:            
            (ptr_att+count)->nome=nome;
            (ptr_att+count)->tipo=1;
            (ptr_att+count)->tamanho=sizeof(char);
            break;
          case 2:
            (ptr_att+count)->nome=nome;
            (ptr_att+count)->tipo=2;
            (ptr_att+count)->tamanho=sizeof(int);
            break;
          case 3:
            (ptr_att+count)->nome=nome;
            (ptr_att+count)->tipo=3;
            (ptr_att+count)->tamanho=sizeof(float);
            break;
          case 4:
            (ptr_att+count)->nome = nome;
            (ptr_att+count)->tipo = 4;
            (ptr_att+count)->tamanho=sizeof(double);
            break;
          case 5:
            (ptr_att+count)->nome=nome;
            (ptr_att+count)->tipo=5;
            printf("Digite o tamanho da string que desejas: \n");
            scanf("%d", &ctr);
            (ptr_att+count)->tamanho=sizeof(char)*ctr;
            break; 
          default:
            printf("Numero invalido!\n");
        }
        count++;
        qnt_atributos++;        
        ptr_att=(Atributo*) realloc (ptr_att,qnt_atributos*sizeof(Atributo));     
      }
    }while(ctr != 0);   
    //checando se os atributos foram armazenados
    for(int i = 0; i < 2; i++){
      printf("%s\n", ptr_att[i].nome);
    }
  }
  free(ptr_att);
}

void v_listarTabelas(){}
