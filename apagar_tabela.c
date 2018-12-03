#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"
void apagarTabela()
{
  char *nome_tabela = (char *)malloc(20 * sizeof(char));
  FILE *tabela;
  int op;
  do
  {
    printf("Digite o nome da sua tabela: \n");
    fscanf(stdin, "%s", nome_tabela);
    tabela = fopen(strcat(nome_tabela, ".txt"), "r+");
    if (tabela == NULL)
    {
      printf(RED "Erro! Essa tabela não existe!\n" RESET);
    }
  } while (tabela == NULL); // Executa até o usuário digitar uma tabela existente
  printf(GREEN "Tabela escolhida com sucesso!\n" RESET);
  for (int i = 0; i < 30; i++)
  {
    printf("=");
  }
  printf("\n");
  op = remove(nome_tabela); // Função que remove o arquivo. Obs, retorna 0 quando apaga algum arquivo
  if (op == 0)
  {
    printf(GREEN "Tabela %s removida com sucesso\n" RESET, nome_tabela);
  }
  else
  {
    printf(RED "Erro :( \n" RESET);
  }
  fclose(tabela);
  free(nome_tabela);
}
