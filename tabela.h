#ifndef _tabela_h
#define _tabela_h

typedef struct tabela{
	int id;
	char *nome;
}Tabela;
typedef struct atributo{
	char *nome;
	int tipo;
	int tamanho;
}Atributo;

int criarTabela(char *nome);
int escreverAtributos(char *arquivo, Atributo *atributo);

#endif