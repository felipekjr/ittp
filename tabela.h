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

enum TIPOS{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	STRING
};

void criarTabela();
void listarTabelas();
int escreverAtributos(char *nome, Atributo *atributo);

#endif