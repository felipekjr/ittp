  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "tabela.h"

  int definirAtributos(FILE *arquivo);
  int escreverAtributos(char *nome, Atributo *atributo);
  int contarLinhas(FILE* tabela);
  int verificaColunas(FILE *tabela, char nome[20]);


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
              
          }else{
              printf("Houve um erro ao tentar criar a tabela!\n");
          }   
    }
      fclose(ptr_arq);
  }



  int definirAtributos(FILE *tabela){
    char *nome;
    int option, string_size;  
    Atributo *ptr_att = (Atributo*) calloc(1,sizeof(Atributo));   
    if(ptr_att==NULL){
      printf("Erro de memória!\n");
      return (-1);
    }
    else {    
      printf("---------COLUNAS DA TABELA----------\n");
      //CHAVE PRIMARIA
            printf("Digite o nome da chave primária: ");
            fgets(nome, 20, stdin);
            int length= strlen(nome);
            fprintf(tabela, "coluna: %.*s, %d, %d \n", length-1, nome, 2, sizeof(int));
            //FIM DO PROCESSO DA CHAVE PRIMARIA
            
            //Lembtete, sempre a chave primária será a primeira coluna, por definição nossa
      do{
        //definindo as colunas da tabela  
        printf("Digite o tipo da coluna: \n1-CHAR | 2-INT | 3-FLOAT | 4-DOUBLE | 5-STRING | 0-FIM\n");      
        scanf("%d", &option);
        if(option!=0){ 
          printf("Digite o nome da coluna (max 20 caracteres): \n");
          getchar();
          fgets(nome, 20, stdin);  
          printf("%d",verificaColunas(tabela, nome));
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
              printf("Digite o tamanho da string que desejas: ");
              scanf("%d", &string_size);
              (ptr_att)->tamanho=sizeof(char)*string_size;
              break; 
            default:
              printf("Digite um valor válido!\n");            
          } 
          length= strlen(ptr_att->nome);
          fprintf(tabela, "coluna: %.*s, %d, %d \n", length-1, ptr_att->nome, ptr_att->tipo, ptr_att->tamanho);        
        }
      }while(option != 0);       
    }
    free(ptr_att);
    return 0;
  }

  int verificaColunas(FILE *tabela, char *nome){
      int count = 0, k = 0;        
      char buffer[256];   
      int qnt_colunas = contarColunas(tabela);        
      char **linhas = (char**) calloc(qnt_colunas, sizeof(char*));
      if(linhas == NULL){
        printf("Erro1");
        return -1;
      }else{ 
        fseek(tabela,0, SEEK_SET);        
        while (fgets(buffer, 256, tabela)) // buffer will contain also the newline!
        {                         
          linhas[count] = (char*) calloc(20, sizeof(char));
          if(linhas[count] == NULL){
            printf("Erro");
            return -1;
          }else{            
            strcpy(linhas[count],buffer);
          }
          count++;
        }
      }   
      for(int j = 0; j<count; j++){        
        // fprintf(stdout,"%s",strstr(linhas[j], strcpy("",nome)));
        // if(strstr(linhas[j], nome) != NULL){
        //   return 1;
        // }
      }
      //limpando ponteiro      
      for(int j = 0; j<count; j++){
        free(linhas[j]);
      }    
      free(linhas);  
      return 0;
          
  }

  int contarColunas(FILE* tabela){
    int colunas = 0, ch = 0;
    while(!feof(tabela))
      {
        ch = fgetc(tabela);
        if(ch == 'c')
        {
          colunas++;
        }
      }
      return colunas;
  }

