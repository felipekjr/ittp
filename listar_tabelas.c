#include <dirent.h> // Biblioteca de funções de diretório
#include <stdio.h>
#include <string.h>
#include "tabela.h"

void listarTabelas()
{
  //listando todos os txt
  printf("----TABELAS----- \n");
  DIR *p;            //Arquivo de diretório
  struct dirent *pp; //Struct padrão da biblioteca que contem os metadados dos arquivos
  p = opendir("./"); //Abrindo o diretório em que o executável se encontra
  int controle = 0;
  if (p != NULL)
  {
    while ((pp = readdir(p)) != NULL) //Enquanto o diretório não termina
    {
      int length = strlen(pp->d_name);
      if (strncmp(pp->d_name + length - 4, ".txt", 4) == 0)
      {
        if (strcmp(pp->d_name, "respostas.txt") == 0 || strcmp(pp->d_name, "pk.txt") == 0)
        {
          //Excluimos da exibição os arquivos auxiliares respostas e pk
        }
        else
        {
          //Printando na tela as tabelas
          printf("%.*s\n", length - 4, pp->d_name);
          controle = 1;
        }
      }
    }
    if (controle != 1)
    {
      //Saida quando nenhum arquivo txt é encontrado
      printf(RED "Nenhuma tabela foi encontrada\n" RESET);
    }
    (void)closedir(p); //Fechando a variável de diretório
  }
  printf("-----------------\n");
}
