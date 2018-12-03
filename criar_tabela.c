#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"

int definirAtributos(FILE *arquivo);
int escreverAtributos(char *nome, Atributo *atributo);
void criarTabela()
{
  FILE *ptr_arq;
  FILE *aux;
  //Ponteiro do arquivo
  char *nome_tabela = (char *)malloc(20 * sizeof(char));
  do
  {
    printf("Digite o nome da tabela: ");
    fscanf(stdin, "%s", nome_tabela);
    aux = fopen(strcat(nome_tabela, ".txt"), "r+"); //É usado o r+ pois ele só abre quando já existe um arquivo
    if (aux != NULL)
    {
      printf(RED "Essa tabela ja existe!\n" RESET);
    }
  } while (aux != NULL); //Executa até digitar o nome de uma tabela inexistente
  //criando o arquivo com o nome da tabela
  ptr_arq = fopen(nome_tabela, "w+");
  if (ptr_arq == NULL)
  {
    printf(RED "Erro de criacao" RESET);
  }
  else
  {
    printf(GREEN "Nome da tabela escolhido com sucesso!\n" RESET);
    //Inicio do processo de inserção de atributos
    if (definirAtributos(ptr_arq) >= 0)
    {
      printf(GREEN "Tabela criada com sucesso!\n" RESET);
    }
    else
    {
      printf(RED "Houve um erro ao tentar criar a tabela!\n" RESET);
    }
  }
  free(nome_tabela);
  fclose(ptr_arq);
}

int definirAtributos(FILE *tabela)
{
  char *nome = (char *)calloc(20, sizeof(char));
  int coluna_counter = 1, option, string_size;
  Atributo *ptr_att = (Atributo *)calloc(1, sizeof(Atributo));
  if (ptr_att == NULL)
  {
    printf(RED "Erro de memória!\n" RESET);
    return (-1);
  }
  else
  {
    printf("---------COLUNAS DA TABELA----------\n");
    //Chave primaria
    printf("(%d) Digite o nome da chave primária: ", coluna_counter);
    fscanf(stdin, "%s", nome);
    fprintf(tabela, "[*%s (%s)]\n", nome, "int");
    coluna_counter++;
    //Fim do processo de chave primaria
    //Lembrete, sempre a chave primária será a primeira coluna, por definição nossa
    do
    {
      //Definindo as colunas da tabela
      printf("(%d) Digite o tipo da coluna : \n1-CHAR | 2-INT | 3-FLOAT | 4-DOUBLE | 5-STRING | 0-FIM\n", coluna_counter);
      scanf("%d", &option);
      if (option != 0)
      {
        printf("(%d) Digite o nome da coluna (max 20 caracteres): \n", coluna_counter);
        fscanf(stdin, "%s", nome);
        //Verifica se o nome da coluna já existe, para evitar que duas colunas tenham o mesmo nome
        if (verificaColunas(tabela, nome) == 0)
        {
          //Coluna ainda não existe
          switch (option)
          {
          case 1:
            (ptr_att)->nome = nome;
            (ptr_att)->tipo = "char";
            break;
          case 2:
            (ptr_att)->nome = nome;
            (ptr_att)->tipo = "int";
            break;
          case 3:
            (ptr_att)->nome = nome;
            (ptr_att)->tipo = "float";
            break;
          case 4:
            (ptr_att)->nome = nome;
            (ptr_att)->tipo = "double";
            break;
          case 5:
            (ptr_att)->nome = nome;
            (ptr_att)->tipo = "string";
            printf("Digite o tamanho da string que desejas: ");
            getchar();
            scanf("%d", &string_size);
            break;
          default:
            printf(RED "Digite um valor válido!\n" RESET);
          }
          int length = strlen(ptr_att->nome);
          //String é um tipo separado pois precisamos do tamanho dela
          if (ptr_att->tipo == "string")
          {
            //Printando no arquivo da tabela
            fprintf(tabela, "[%s (%s|%d|)]\n", ptr_att->nome, ptr_att->tipo, string_size);
          }
          else
          {
            fprintf(tabela, "[%s (%s)]\n", ptr_att->nome, ptr_att->tipo);
          }
          coluna_counter++;
        }
        else
        {
          printf(RED "Já existe uma coluna com esse nome!\n" RESET);
        }
      }
    } while (option != 0); //Até o usuário digitar 0
  }
  //Liberando as variáveis alocadas
  free(ptr_att);
  free(nome);
  return 0;
}

int verificaColunas(FILE *tabela, char *nome)
{
  int count = 0, k = 0;
  char buffer[256];
  int qnt_colunas = contarSeparador(tabela, '[');
  char **linhas = (char **)calloc(qnt_colunas, sizeof(char *));
  if (linhas == NULL)
  {
    fprintf(stderr, "Erro1");
    return -1;
  }
  else
  {
    fseek(tabela, 0, SEEK_SET);
    while (fgets(buffer, 256, tabela))
    {
      linhas[count] = (char *)calloc(20, sizeof(char));
      if (linhas[count] == NULL)
      {
        fprintf(stderr, "Erro");
        return -1;
      }
      else
      {
        //armazena cada linha de colunas da tabela em um vetor
        strcpy(linhas[count], buffer);
      }
      count++;
    }
  }
  for (int j = 0; j < count; j++)
  {
    if (strstr(linhas[j], nome) != NULL)
    {
      return 1;
      //nome já existe existe
    }
  }
  return 0;
}

//Função declarada no arquivo .h
int contarSeparador(FILE *tabela, char separador)
{
  //Função que retorna a quantidade separadores, pode ser o [, que representa as colunas, ou o {, que representam as linhas
  int colunas = 0, ch = 0;
  fseek(tabela, 0, SEEK_SET);
  while (!feof(tabela))
  {
    //Lê o primeiro caractere
    ch = fgetc(tabela);
    if (ch == separador)
    {
      colunas++;
    }
  }
  return colunas;
}
