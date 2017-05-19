//Alana Schwendler - M1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa { 
	char nome[20];
	int idade;
} Pessoa;

void insere(Pessoa *pAtual);
void imprime(Pessoa *pAtual);
void busca(char *nomeAux, Pessoa *pAtual, Pessoa *pInicio, int *qt, int *x);

int main() {
	void *pBuffer;
	int *qt;
	int *opcao;
	int *x; //controle do for 
	char *nomeAux;
	Pessoa *pInicio;
	Pessoa *pAtual;
 
	/*
	pBuffer = malloc(sizeof(int)); //aloca tamanho de um inteiro pra colocar a quantidade
	qt = pBuffer; //quantidade de pessoas inseridas

	pBuffer = realloc(pBuffer, (sizeof(int)*2)); //realoca espaço pra adicionar a opção
	qt = pBuffer; //reajusta o ponteiro de qt
	opcao = (qt + sizeof(int)); //opção aponta pra qt + 4
	*/

	pBuffer = malloc(sizeof(int)*3); //aloca memória pros ints e pro nome auxiliar(usado na busca)
	pBuffer = realloc(pBuffer, sizeof(int)*3 + sizeof(char)*20);
	qt = pBuffer;
	*qt = 0; //seta como 0
	opcao = (qt + sizeof(int)); //opção aponta pra qt + 4	
	x = (opcao + sizeof(int));
	nomeAux = (char *)(x + sizeof(int));

	printf("1 - Inserir Pessoa\n");
	printf("2 - Listar Pessoas\n");
	printf("3 - Buscar Pessoa\n");
	printf("0 - Sair\n");
	
	do {
		printf("Opção: ");
		scanf("%d", opcao); //le qual opção o usuario vai querer

		if(*opcao == 1) {
			*qt = *qt + 1; //se a opção foi de inserir, adiciona mais um na quantidade
			
			pBuffer = realloc(pBuffer, (sizeof(int)*3) + (sizeof(char)*20) + (sizeof(Pessoa) * (*qt))); //realoca espaço de acordo com a qt de pessoas //  + (sizeof(char)*20)
			qt = pBuffer; //reajusta o ponteiro de qt
			opcao = (qt + sizeof(int)); //opção aponta pra qt + 4
			x = (opcao + sizeof(int)); //x aponta pra opção + 4
			nomeAux = (char *)(pBuffer + (sizeof(int)*3));
			pInicio = (Pessoa *)(nomeAux + (sizeof(char)*20)); //pessoa inicio aponta pra proxima posição depois de nomeAux
			//pAtual = pInicio;
			pAtual = (pInicio) + (sizeof(Pessoa) * ((*qt)-1)); //agora a pessoa atual aponta pro inicio da memória alocada pra próxima pessoa

			insere(pAtual);
		} else if(*opcao == 2) {
			pAtual = pInicio;
			for(*x = 0; *x < *qt; (*x)++) {
				imprime(pAtual);
				pAtual = pAtual + sizeof(Pessoa);
			}
		} else if(*opcao == 3) {
			pInicio = (Pessoa *) (pBuffer + (sizeof(int)*3) + (sizeof(char)*20));
			printf("Quem você deseja buscar? ");
			scanf("%s", nomeAux);
			busca(nomeAux, pAtual, pInicio, qt, x);
		}
	} while(*opcao != 0);

	free(pBuffer);

	return 0;
}

void insere(Pessoa *pAtual) {
	printf("Insira o nome: ");
	scanf("%s", (*pAtual).nome);
	printf("Insira a idade: ");
	scanf("%d", &(*pAtual).idade);
}

void imprime(Pessoa *pAtual) {
	printf("Nome: %s\n", pAtual->nome);
	printf("Idade: %d\n", pAtual->idade);
	printf("------\n");
}

void busca(char *nomeAux, Pessoa *pAtual, Pessoa *pInicio, int *qt, int *x) {
	pAtual = pInicio;
	for(*x = 0; *x < *qt; (*x)++) {
		if(strcmp(pAtual->nome, nomeAux) == 0) {
			printf("Encontrado\n");
			printf("Nome: %s\n", pAtual->nome);
			printf("Idade: %d\n", pAtual->idade);
		}
		pAtual = pAtual + sizeof(Pessoa);
	}
	printf("Fim da busca.\n");
}


/*
PROPOSTA DA AGENDA

Faça uma agenda capaz de incluir, apagar, buscar
e listar quantas pessoas o usuário desejar, porém,
você não pode usar variáveis a não ser ponteiros.
Toda a informação deve ser guardada num “void
*pBuffer”.

pBuffer deve guardar desde as pessoas colocadas
na agenda até as variáveis locais que você precisa
para controlar um for, por exemplo.
*/