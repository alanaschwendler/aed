#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct n {
	int num;
	int altura;
	struct n *esq;
	struct n *dir;
} No;

int maior(int x, int y);
int alturaArvore(No *n);
int balanceamento(No *n);
void rotacaoEE(No *n);
void rotacaoDD(No *n);
void rotacaoED(No *n);
void rotacaoDE(No *n);
No* inserir(No *n, int valor);
void imprimir(No *raiz);

int main() {
	No *raiz;
	raiz = NULL;

	int op;
	int valor;

	printf("1 - Inserir \n0 - Sair\n");

	do {
		printf("Opção: ");
		scanf("%d", &op);

		switch(op) {
			case 1:
				printf("-----INSERIR-----\n");

				printf("Valor: ");
				scanf("%d", &valor);

				raiz = inserir(raiz, valor);
				break;

			case 2:
				printf("-----IMPRIMIR-----\n");

				printf("%d\n", raiz->num);
				imprimir(raiz);
				break;
			default:
				printf("Programa encerrado.\n");
				break;
		}
	} while(op != 0);

	free(raiz);
	return 0;
}

No* inserir(No *raiz, int valor) {
	No *aux;
	aux = raiz;

	if(raiz == NULL) {
		raiz = malloc(sizeof(No));
		raiz->altura = 0;
		raiz->num = valor;
		raiz->esq = NULL;
		raiz->dir = NULL;

		printf("Raiz inserida.\n");
		return raiz;
	} else {
		do {
			if(valor < aux->num) { //esquerda
				if(aux->esq != NULL) {
					aux = aux->esq; //anda na arvore
				} else {
					aux->esq = malloc(sizeof(No));

					aux->esq->num = valor;
					aux->esq->altura = aux->altura++;
					aux->esq->esq = NULL;
					aux->esq->dir = NULL;

					printf("Inserido à esquerda.\n");
					return raiz;
				}
			} else if(valor > aux->num) { //direita
				if(aux->dir != NULL) {
					aux = aux->dir;	//anda na arvore
				} else {
					aux->dir = malloc(sizeof(No));

					aux->dir->num = valor;
					aux->dir->altura = aux->altura++;
					aux->dir->esq = NULL;
					aux->dir->dir = NULL;

					printf("Inserido à direita.\n");
					return raiz;
				}
			} else {
				printf("Erro: valor duplicado.\n");
				exit(1);
			}
		} while(aux != NULL);
	}
	return raiz;
}

int alturaArvore(No *n) {
	if(n->esq == NULL) {
		return n->altura;
	} else {
		return alturaArvore(n->esq);
	}
}

void imprimir(No *raiz) {
	No *aux;
	aux = raiz;
	int x, altura;

	altura = alturaArvore(raiz);
	for(x = 0; x < altura; x++) {
		if(aux->altura == altura) {
			printf("\t%d\n", aux->esq->num);
			printf("\t%d\n", aux->dir->num);
			aux = aux->esq;
		}
	}
}