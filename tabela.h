#ifndef _tabela_h
#define _tabela_h

typedef struct tabela{
	int id;
	char *nome;
}Tabela;
typedef struct atributo{
	char *nome;
	char *tipo;		
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
void listarDados();
void inserirRegistros();
void pesquisarValor();

//funções reaproveitaveis
int escreverAtributos(char *nome, Atributo *atributo);
int contarColunas(FILE* tabela, char separador);
int verificaColunas(FILE *tabela, char *nome);
char* listarColunas(FILE *tabela);

#endif