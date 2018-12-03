#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"
#include <ctype.h>

int jogarPkArquivo(FILE *tabela, char *nome, FILE *pk);
int verificarPk(FILE *pk, char *nome);

void inserirRegistros()
{
  char *valor = (char *)malloc(20 * sizeof(char));
  char *nome_tabela = (char *)malloc(20 * sizeof(char));
  char *nome_atributo;
  char buffer[256];
  int count = 0, colunas;
  FILE *tabela;
  FILE *respostas = fopen("respostas.txt", "w+");
  FILE *pk = fopen("pk.txt", "w+");
  if (respostas == NULL || pk == NULL)
  {
    printf(RED "Erro" RESET);
  }
  else
  {
    do
    {
      printf("Digite o nome da sua tabela: \n");
      fscanf(stdin, "%s", nome_tabela);
      tabela = fopen(strcat(nome_tabela, ".txt"), "r+");
      if (tabela == NULL)
      {
        printf(RED "Essa tabela não existe!\n" RESET);
      }
    } while (tabela == NULL); //Até o usuario digitar uma tabela existente
    colunas = contarSeparador(tabela, '[');
    tabela = fopen(nome_tabela, "a+");
    jogarPkArquivo(tabela, valor, pk); //Joga as PK no arquivo
    printf("=Digite os valores da tabela %s=\n", nome_tabela);
    fseek(tabela, 0, SEEK_SET);
    while (EOF != fscanf(tabela, "%[^\n]\n", buffer))
    {
      if (strstr(buffer, "{") == NULL)
      {
        // É UMA COLUNA, tratar o dado
        nome_atributo = strtok(strtok(buffer, "]"), "[");
        if (count == 0)
        {
          do
          {
            printf("%s: ", nome_atributo);
            scanf("%s", valor);
            if (verificarPk(pk, valor) == -1)
            {
              printf(RED "ERRO! Valor da PK invalido\n" RESET);
            }
          } while (verificarPk(pk, valor) == -1);
          fprintf(respostas, "%s\n", valor);
        }
        else
        {
          printf("%s: ", nome_atributo);
          scanf("%s", valor);
          fprintf(respostas, "%s\n", valor);
        }
        count++;
      }
    }
    fseek(tabela, 0, SEEK_END);
    //Passando as respostas para o arquivo da tabela em edição.
    fprintf(tabela, "{");
    fseek(respostas, 0, SEEK_SET);
    for (int i = 1; i <= colunas; i++)
    {
      fscanf(respostas, "%s,", valor);
      if (i == colunas)
      {
        fprintf(tabela, "%s}\n", valor);
      }
      else
      {
        fprintf(tabela, "%s,", valor);
      }
    }
    printf(GREEN "Valores inseridos.\n" RESET);
    getchar();
    fclose(pk);
    fclose(respostas);
    fclose(tabela);
    free(valor);
    free(nome_tabela);
  }
}

int jogarPkArquivo(FILE *tabela, char *nome, FILE *pk)
{
  //Função que joga todas as pk em um arquivo;
  char *linha;
  char buffer[256];
  int controle = 0;
  fseek(tabela, 0, SEEK_CUR);
  while (EOF != fscanf(tabela, "%[^\n]\n", buffer))
  {
    if (strstr(buffer, "[") == NULL)
    {
      // É UMA TUPLA
      linha = strtok(strtok(buffer, "{"), ","); //Pega só o primeiro dado, que é a chave primária
      fprintf(pk, "%s\n", linha);
    }
  }
  free(linha);
  return 0;
}

int verificarPk(FILE *pk, char *nome)
{
  char *aux = (char *)malloc(20 * 1);
  fseek(pk, 0, SEEK_SET);
  char *pEnd;
  long int conversao;
  while (!feof(pk))
  {
    fscanf(pk, "%s", aux);
    conversao = strtol(nome, &pEnd, 20);
    if (strcmp(aux, nome) == 0 || conversao < 0 || !isdigit(*nome))
    {
      free(aux);
      return -1;
    }
  }
  free(aux);
  fre(pEnd);
  return 0;
}
