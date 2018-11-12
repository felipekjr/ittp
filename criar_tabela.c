#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"

int definirAtributos(FILE *arquivo);
int escreverAtributos(char *nome, Atributo *atributo);
int escolherPK(char *nome_tabela);

void criarTabela(){
    FILE *ptr_arq; //Ponteiro do arquivo
    char *nome_tabela;
	nome_tabela = (char *) malloc (20*sizeof(char));
    printf("Digite o nome da sua tabela: ");
	getchar();
    fgets(nome_tabela, 20, stdin);
    strcat(nome_tabela,".txt");

  	//criando o arquivo com o nome da tabela
	ptr_arq = fopen(nome_tabela, "w+");
	if(ptr_arq==NULL){		
	printf("Erro de criacao");
	}
	else{
		if(definirAtributos(ptr_arq)>=0){
            printf("Tabela criada com sucesso! Escolha uma coluna como chave primária:\n");
            escolherPK(nome_tabela);
        }else{
            printf("Houve um erro ao tentar criar a tabela!\n");
        }		
	}
  	fclose(ptr_arq);
}



int definirAtributos(FILE *tabela){
  char nome[20];
  int option, string_size;  
  Atributo *ptr_att = (Atributo*) calloc(1,sizeof(Atributo));   
  if(ptr_att==NULL){
    printf("Erro de memória!\n");
    return (-1);
  }
  else {    
    printf("---------COLUNAS DA TABELA----------\n");
    do{
    	//definindo as colunas da tabela  
      printf("Digite o tipo da coluna: \n1-CHAR | 2-INT | 3-FLOAT | 4-DOUBLE | 5-STRING | 0-FIM\n");      
      scanf("%d", &option);
      if(option!=0){ 
        printf("Digite o nome da coluna (max 20 caracteres): \n");  
        getchar();
        fgets(nome, 20, stdin);      
        fprintf(stdout, "%s", nome); 
        switch(option){          
          case 1:            
            (ptr_att)->nome=nome;
            (ptr_att)->tipo=1;
            (ptr_att)->tamanho=sizeof(char);
            break;
          case 2:
            (ptr_att)->nome=nome;
            (ptr_att)->tipo=2;
            (ptr_att)->tamanho=sizeof(int);
            break;
          case 3:
            (ptr_att)->nome=nome;
            (ptr_att)->tipo=3;
            (ptr_att)->tamanho=sizeof(float);
            break;
          case 4:
            (ptr_att)->nome = nome;
            (ptr_att)->tipo = 4;
            (ptr_att)->tamanho=sizeof(double);
            break;
          case 5:
            (ptr_att)->nome=nome;
            (ptr_att)->tipo=5;
            printf("Digite o tamanho da string que desejas: \n");
            scanf("%d", &string_size);
            (ptr_att)->tamanho=sizeof(char)*string_size;
            break; 
          default:
            printf("Digite um valor válido!\n");            
        } 
        fprintf(tabela, "coluna: %s, %d, %d \n", ptr_att->nome, ptr_att->tipo, ptr_att->tamanho);        
      }
    }while(option != 0);       
  }
  free(ptr_att);
  return 0;
}

int escolherPK(char *nome_tabela){
  printf("COLUNAS\n");
  // listar as colunas da tabela por nome e escolher uma para ser a PK
}

//escreve os atributos que a tabela possui (colunas)




