#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"
#include <ctype.h> //Necessário para a função isdigit()

void listarDados()
{
    char *nome_tabela = (char *)malloc(20 * sizeof(char));
    char *linha;
    char buffer[256];
    FILE *tabela;

    if (nome_tabela == NULL)
    {
        printf("Erro com o nome da tabela");
    }
    else
    {
        do
        {
            printf("Digite o nome da tabela: ");
            getchar();
            fscanf(stdin, "%s", nome_tabela);
            tabela = fopen(strcat(nome_tabela, ".txt"), "r+");
            if (tabela == NULL)
            {
                printf(RED "Essa tabela não existe!\n" RESET);
            }
        } while (tabela == NULL);
        int s_nome = strlen(nome_tabela);
        fprintf(stdout, "TABELA: %.*s\n\n", s_nome - 4, nome_tabela);
        listarColunas(tabela);
        tabela = fopen(nome_tabela, "a+");
        fseek(tabela, 0, SEEK_CUR);
        while (EOF != fscanf(tabela, "%[^\n]\n", buffer))
        {
            if (strstr(buffer, "[") == NULL)
            {
                // É UMA TUPLA
                linha = strtok(strtok(buffer, "{"), "}");
                printf("%s\n", linha);
            }
        }
        printf("\n");
    }
    free(nome_tabela);
    fclose(tabela);
}

char *listarColunas(FILE *tabela)
{
    char *coluna;
    char *aux = (char *)calloc(100, sizeof(char));
    char buffer[256];
    fseek(tabela, 0, SEEK_CUR);
    while (EOF != fscanf(tabela, "%[^\n]\n", buffer))
    {
        if (strstr(buffer, "{") == NULL)
        {
            // É UMA TUPLA
            coluna = strtok(strtok(buffer, "["), "]");
            strcat(aux, coluna);
            fprintf(stdout, "%s | ", coluna);
        }
    }
    printf("\n");
    return aux;
}
