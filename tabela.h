#ifndef _tabela_h
#define _tabela_h
typedef struct tabela{
	int id;
	char *nome;
}Tabela;
typedef struct atributo{
	char *nome;
	char *tipo;	
	int tamanho;
}Atributo;

enum TIPOS{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	STRING
};
int contarColunas(FILE* tabela, char separador);
void criarTabela();
void listarTabelas();
void listarDados();
int escreverAtributos(char *nome, Atributo *atributo);
void inserirRegistros();
#endif