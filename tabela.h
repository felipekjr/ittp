#ifndef _tabela_h
#define _tabela_h
//Definindo Cores
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

typedef struct tabela
{
	int id;
	char *nome;
} Tabela;

typedef struct atributo
{
	char *nome;
	char *tipo;
} Atributo;

enum TIPOS
{
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
void apagarTabela();
void apagarRegistro();
//funções reaproveitaveis
int escreverAtributos(char *nome, Atributo *atributo);
int contarSeparador(FILE *tabela, char separador);
int verificaColunas(FILE *tabela, char *nome);
char *listarColunas(FILE *tabela);

#endif
