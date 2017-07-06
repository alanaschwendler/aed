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

<<<<<<< HEAD
	// pBuffer = malloc(sizeof(int)*3); //aloca memória pros ints e pro nome auxiliar(usado na busca)
	// pBuffer = realloc(pBuffer, sizeof(int)*3 + sizeof(char)*20);
	pBuffer = malloc(sizeof(int)*3 + sizeof(char)*20); //aloca memória pros ints e pro nome auxiliar(usado na busca)
	qt = pBuffer;
	*qt = 0; //seta como 0
	opcao = (qt + sizeof(int)); //opção aponta pra qt + 4	
	x = (opcao + sizeof(int));
	nomeAux = (char *)(x + sizeof(int));
=======
	pBuffer = malloc(sizeof(int)*3); //aloca memória pros ints e pro nome auxiliar(usado na busca)
	pBuffer = realloc(pBuffer, sizeof(int)*3 + sizeof(char)*20);
	qt 		= (int *) pBuffer;
	*qt		= 0; //seta como 0
	opcao   = (int *)	((void *) qt)		+ sizeof(int); //opção aponta pra qt + 4	
	x 	    = (int *)	((void *) opcao)	+ sizeof(int);
	nomeAux = (char *)	((void *) x)		+ sizeof(int);
>>>>>>> 2f4f5ff498faa3dae0889ddade09a963da703d64

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
<<<<<<< HEAD
			qt = pBuffer; //reajusta o ponteiro de qt
			opcao = qt + (sizeof(int)); //opção aponta pra qt + 4
			x = opcao + (sizeof(int)); //x aponta pra opção + 4
			nomeAux = (char *)(pBuffer + (sizeof(int)*3));
			// nomeAux = (char *)(x + (sizeof(int)));
			pInicio = (Pessoa *)(nomeAux + (sizeof(char)*20)); //pessoa inicio aponta pra proxima posição depois de nomeAux
			//pAtual = pInicio;
			pAtual = (pInicio) + (sizeof(Pessoa) * ((*qt)-1)); //agora a pessoa atual aponta pro inicio da memória alocada pra próxima pessoa
			printf("%p\n", pInicio);
			
			/*printf("pBuffer: \t%p\n", pBuffer);
			printf("qt: \t\t%p\n", qt);
			printf("opcao: \t\t%p\n", opcao);
			printf("x: \t\t%p\n", x);
			printf("nomeAux: \t%p\n", nomeAux);
			printf("pInicio: \t%p\n", pInicio);
			printf("pAtual: \t%p\n", pAtual);
			*/
			insere(pAtual);
=======
			qt 		= (int *)		pBuffer; //reajusta o ponteiro de qt
			opcao 	= (int *)		((void *) qt)		+ sizeof(int); //opção aponta pra qt + 4
			x 		= (int *)		((void *) opcao)	+ sizeof(int); //x aponta pra opção + 4
			nomeAux = (char *)		((void *) x)		+ sizeof(int);
			pInicio = (Pessoa *)	((void *) nomeAux) 	+ sizeof(char)*20; //pessoa inicio aponta pra proxima posição depois de nomeAux
			pAtual  = (Pessoa *)	((void *) pInicio) 	+ sizeof(Pessoa) * ((*qt)-1); //agora a pessoa atual aponta pro inicio da memória alocada pra próxima pessoa

			inserir(pAtual);
>>>>>>> 2f4f5ff498faa3dae0889ddade09a963da703d64
		} else if(*opcao == 2) {
			pAtual = pInicio;

			for(*x = 0; *x < *qt; (*x)++) {
<<<<<<< HEAD
				printf("%p\n", pAtual);
				imprime(pAtual);
				pAtual = pAtual + sizeof(Pessoa);
=======
				imprimir(pAtual);
				pAtual = (Pessoa *) ((void *) pAtual) + sizeof(Pessoa);
>>>>>>> 2f4f5ff498faa3dae0889ddade09a963da703d64
			}
		} else if(*opcao == 3) {
			printf("Quem você deseja buscar? ");
<<<<<<< HEAD
			scanf("%s%*c", nomeAux);
			busca(nomeAux, pAtual, pInicio, qt, x);
=======
			scanf("%s", nomeAux);
			buscar(nomeAux, pAtual, pInicio, qt, x);
		} else if(*opcao == 4) {
			printf("Quem você deseja remover? ");
			scanf("%s", nomeAux);
			remover(nomeAux, pAtual, pInicio, qt, x, pBuffer, opcao);
>>>>>>> 2f4f5ff498faa3dae0889ddade09a963da703d64
		}
	} while(*opcao != 0);

	free(pBuffer);

	return 0;
}

<<<<<<< HEAD
void insere(Pessoa *pAtual) {
	printf("%p\n", pAtual);
=======
void inserir(Pessoa *pAtual) {
>>>>>>> 2f4f5ff498faa3dae0889ddade09a963da703d64
	printf("Insira o nome: ");
	scanf("%s%*c", (*pAtual).nome);
	printf("Insira a idade: ");
	scanf("%d", &(*pAtual).idade);
<<<<<<< HEAD
	printf("DEBUG:%s\n",(*pAtual).nome);
=======
	scanf("%*c"); 
>>>>>>> 2f4f5ff498faa3dae0889ddade09a963da703d64
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