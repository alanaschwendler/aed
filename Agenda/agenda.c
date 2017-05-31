//Alana Schwendler - M1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa { 
	char nome[20];
	int idade;
} Pessoa;

void inserir(Pessoa *pAtual);
void imprimir(Pessoa *pAtual);
int buscar(char *nomeAux, Pessoa *pAtual, Pessoa *pInicio, int *qt, int *x);
void remover(char *nomeAux, Pessoa *pAtual, Pessoa *pInicio, int *qt, int *x, void *pBuffer, int *opcao);

int main() {
	int 	z;
	void	*pBuffer;
	int		*qt;
	int 	*opcao;
	int 	*x; //controle do for 
	char 	*nomeAux;
	Pessoa 	*pInicio;
	Pessoa 	*pAtual;

	pBuffer = malloc(sizeof(int)*3); //aloca memória pros ints e pro nome auxiliar(usado na busca)
	pBuffer = realloc(pBuffer, sizeof(int)*3 + sizeof(char)*20);
	qt 		= (int *) pBuffer;
	*qt		= 0; //seta como 0
	opcao   = (int *)	((void *) qt)		+ sizeof(int); //opção aponta pra qt + 4	
	x 	    = (int *)	((void *) opcao)	+ sizeof(int);
	nomeAux = (char *)	((void *) x)		+ sizeof(int);

	printf("1 - Inserir Pessoa\n");
	printf("2 - Listar Pessoas\n");
	printf("3 - Buscar Pessoa\n");
	printf("4 - Remover Pessoa\n");
	printf("0 - Sair\n");
	
	do {
		printf("Opção: ");
		scanf("%d", opcao); //le qual opção o usuario vai querer
		if(*opcao == 1) {
			*qt = *qt + 1; //se a opção foi de inserir, adiciona mais um na quantidade
			
			pBuffer = realloc(pBuffer, (sizeof(int)*3) + (sizeof(char)*20) + (sizeof(Pessoa) * (*qt))); //realoca espaço de acordo com a qt de pessoas //  + (sizeof(char)*20)
			qt 		= (int *)		pBuffer; //reajusta o ponteiro de qt
			opcao 	= (int *)		((void *) qt)		+ sizeof(int); //opção aponta pra qt + 4
			x 		= (int *)		((void *) opcao)	+ sizeof(int); //x aponta pra opção + 4
			nomeAux = (char *)		((void *) x)		+ sizeof(int);
			pInicio = (Pessoa *)	((void *) nomeAux) 	+ sizeof(char)*20; //pessoa inicio aponta pra proxima posição depois de nomeAux
			pAtual  = (Pessoa *)	((void *) pInicio) 	+ sizeof(Pessoa) * ((*qt)-1); //agora a pessoa atual aponta pro inicio da memória alocada pra próxima pessoa

			inserir(pAtual);
		} else if(*opcao == 2) {
			pAtual = pInicio;

			for(*x = 0; *x < *qt; (*x)++) {
				imprimir(pAtual);
				pAtual = (Pessoa *) ((void *) pAtual) + sizeof(Pessoa);
			}
		} else if(*opcao == 3) {
			printf("Quem você deseja buscar? ");
			scanf("%s", nomeAux);
			buscar(nomeAux, pAtual, pInicio, qt, x);
		} else if(*opcao == 4) {
			printf("Quem você deseja remover? ");
			scanf("%s", nomeAux);
			remover(nomeAux, pAtual, pInicio, qt, x, pBuffer, opcao);
		}
	} while(*opcao != 0);

	free(pBuffer);

	return 0;
}

void inserir(Pessoa *pAtual) {
	printf("Insira o nome: ");
	scanf("%s", (*pAtual).nome);
	printf("Insira a idade: ");
	scanf("%d", &(*pAtual).idade);
	scanf("%*c"); 
}

void imprimir(Pessoa *pAtual) {
	printf("Nome: %s\n", pAtual->nome);
	printf("Idade: %d\n", pAtual->idade);
	printf("------\n");
}

int buscar(char *nomeAux, Pessoa *pAtual, Pessoa *pInicio, int *qt, int *x) {
	pAtual = pInicio;
	for(*x = 0; *x < *qt; (*x)++) {
		if(strcmp(pAtual->nome, nomeAux) == 0) {
			printf("Encontrado\n");
			printf("Nome: %s\n", pAtual->nome);
			printf("Idade: %d\n", pAtual->idade);

			return *x;
		}
		pAtual = (Pessoa *) ((void *) pAtual) + sizeof(Pessoa);
	}
	printf("Fim da busca.\n");
	return -1;
}

void remover(char *nomeAux, Pessoa *pAtual, Pessoa *pInicio, int *qt, int *x, void *pBuffer, int *opcao) {
	*x = buscar(nomeAux, pInicio, pInicio, qt, x); //aqui vai ter o indice da pessoa q eu quero remover
	
	if(*x == -1) {
		return;
	} 
	
	pAtual = (Pessoa *) ((void *) pInicio) + sizeof(Pessoa) * (*x);
	Pessoa *pAux = (Pessoa *) ((void *) pAtual) + sizeof(Pessoa);

	for(; *x < (*qt)-1; (*x)++) {
		pAtual->idade = pAux->idade;
		strcpy(pAtual->nome, pAux->nome);
		pAtual = pAux;
		pAux = (Pessoa *) ((void *) pAtual) + sizeof(Pessoa);
	}	

	*qt = *qt - 1;
	pBuffer = realloc(pBuffer, (sizeof(int)*3) + (sizeof(char)*20) + (sizeof(Pessoa) * (*qt)));
	qt 		= (int *)		pBuffer; //reajusta o ponteiro de qt
	opcao 	= (int *)		((void *) qt)		+ sizeof(int); //opção aponta pra qt + 4
	x 		= (int *)		((void *) opcao)	+ sizeof(int); //x aponta pra opção + 4
	nomeAux = (char *)		((void *) x)		+ sizeof(int);
	pInicio = (Pessoa *)	((void *) nomeAux) 	+ sizeof(char)*20; //pessoa inicio aponta pra proxima posição depois de nomeAux
	pAtual  = (Pessoa *)	((void *) pInicio) 	+ sizeof(Pessoa) * ((*qt)-1); //agora a pessoa atual aponta pro inicio da memória alocada pra próxima pessoa
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