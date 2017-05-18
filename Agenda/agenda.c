#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa { 
	char nome[20];
	int idade;
} Pessoa;

int main() {
	void *pBuffer;
	int *qt;
	int *opcao;
	char *nomeAux;
	int *idadeAux;
	Pessoa *p;
 
	pBuffer = malloc(sizeof(int)); 
	qt = pBuffer; //quantidade de pessoas inseridas
	qt = 0; //seta como 0

	pBuffer = realloc(pBuffer, (pBuffer + sizeof(int))); //realoca espaço pra adicionar a opção
	opcao = (qt + sizeof(int)); //opção aponta pra qt + 4

	pBuffer = realloc(pBuffer, (pBuffer + sizeof(char)*20)); //aloca espaço pra adicionar o nome
	nomeAux = (opcao + sizeof(char)*20); //ajusta ponteiro do nome

	pBuffer = realloc(pBuffer, (pBuffer + sizeof(int))); //aloca espaço pra adicionar a idade
	idadeAux = (nomeAux + sizeof(int)); //ajusta ponteiro da idade


	return 0;
}