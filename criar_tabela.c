  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "tabela.h"

int definirAtributos(FILE *arquivo);
int escreverAtributos(char *nome, Atributo *atributo);  
int verificaColunas(FILE *tabela, char *nome);


void criarTabela(){
      FILE *ptr_arq; //Ponteiro do arquivo
      char *nome_tabela;
      nome_tabela = (char *) malloc (20*sizeof(char));
      int controle;
      /*printf("Digite o nome da sua tabela: ");
      getchar();
      fgets(nome_tabela, 20, stdin);
      strcat(nome_tabela,".txt");
      */
      do
      {
      	printf("Digite o nome da sua tabela: ");
      	getchar();
      	scanf("%s", nome_tabela);
      	strcat(nome_tabela,".txt");
      	ptr_arq = fopen (nome_tabela, "r");
      	if (ptr_arq==NULL)
      	{
      		controle = 1;
      	}
      	else
      	{
      		controle = 0;
      		printf("Digite uma tabela intedita, senao sobreescreve!\n");
      	}
      } while (controle==0);
      fclose(ptr_arq);
      //criando o arquivo com o nome da tabela
      ptr_arq = fopen(nome_tabela, "w+");
      if(ptr_arq==NULL){    
        printf("Erro de criacao");
      }
      else{
        if(definirAtributos(ptr_arq)>=0){
          printf("Tabela criada com sucesso!\n");              
        }else{
          printf("Houve um erro ao tentar criar a tabela!\n");
        }   
      }
      free(nome_tabela);
      fclose(ptr_arq);
    }



    int definirAtributos(FILE *tabela){
      char *nome;
      nome = (char*) calloc (20, sizeof(char));
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
        fscanf(stdin, "%s", nome);            
        fprintf(tabela, "[%s, %d, %d]\n", nome, 2, 4);
            //FIM DO PROCESSO DA CHAVE PRIMARIA            
            //Lembrete, sempre a chave primária será a primeira coluna, por definição nossa
        do{
        //definindo as colunas da tabela  
          printf("Digite o tipo da coluna: \n1-CHAR | 2-INT | 3-FLOAT | 4-DOUBLE | 5-STRING | 0-FIM\n");      
          scanf("%d", &option);
          if(option!=0){ 
            printf("Digite o nome da coluna (max 20 caracteres): \n");
            fscanf(stdin, "%s", nome);   
            if(verificaColunas(tabela, nome) == 0){
            //coluna ainda n existe
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
              int length= strlen(ptr_att->nome);
              fprintf(tabela, "[%s, %d, %d]\n",ptr_att->nome, ptr_att->tipo, ptr_att->tamanho); 
            }else{
              printf("Já existe uma coluna com esse nome!\n");
            }      
          }
        }while(option != 0);       
      }
      free(ptr_att);
      free(nome);
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
        while (fgets(buffer,256, tabela)) 
        {                         
          linhas[count] = (char*) calloc(20, sizeof(char));
          if(linhas[count] == NULL){
            printf("Erro");
            return -1;
          }else{            
            //armazena cada linha de colunas da tabela em um vetor
            strcpy(linhas[count],buffer);
          }
          count++;
        }
      }
      for(int j = 0; j<count; j++){
        if(strstr(linhas[j], nome) != NULL){
          return 1;
          //nome já existe existe
        }
      }      
      return 0;
      
    }

    int contarColunas(FILE* tabela){
      int colunas = 0, ch = 0;
      while(!feof(tabela))
      {
        ch = fgetc(tabela);
        if(ch == '[')
        {
          colunas++;
        }
      }
      return colunas;
    }
