#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"
#include <dirent.h>
int definirAtributos(char *nome_tabela);
int escolherPK(char *nome_tabela);

//tela para criar a tabela
void v_criarTabela(){    
	char * nome_tabela = NULL; 
  printf("Digite o nome da sua tabela: ");
  getchar();
  nome_tabela = (char *) malloc (20*sizeof(char));
  fgets(nome_tabela, 20, stdin);
  strcat(nome_tabela, ".txt");
  if(criarTabela(nome_tabela)<0){
   printf("Falha ao criar arquivo!\n");
  }else{
    if(definirAtributos(nome_tabela)>=0){
      printf("Tabela criada com sucesso! Escolha uma coluna como chave primária:\n");
      escolherPK(nome_tabela);
    }else{
      printf("Houve um erro ao tentar criar a tabela!\n");
    }
  }
}

int definirAtributos(char *nome_tabela){
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
      if(option!=0 && option<=5){ 
        printf("Digite o nome da coluna (max 20 caracteres): \n");  
        getchar();
        fgets(nome, 20, stdin);
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
            printf("Numero inválido!\n");            
        } 
        if(escreverAtributos(nome_tabela, ptr_att)<0){
          printf("Erro ao definir os atributos da tabela.\n");
          return -1;
        }
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

int v_listarTabelas(){
  //listando todos os txt, falta retirar o .txt
  DIR *p;
  struct dirent *pp;     
  p = opendir ("./");
  if (p != NULL)
  {
    while ((pp = readdir (p))!=NULL) {
      int length = strlen(pp->d_name);
      if (strncmp(pp->d_name + length - 4, ".txt", 4) == 0) {
          puts (pp->d_name);
      }
    }
    (void) closedir (p);
  }
}
