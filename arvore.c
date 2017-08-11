#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct n {
	int num;
	int altura;
	struct n *esq;
	struct n *dir;
} No;

int alturaEsq(No *n);
int alturaDir(No *n);
int fatorBalanceamento(No *raiz);
No* inserir(No *n, int valor);
void imprimirLinha(No *raiz, int altura) ;
void buscar(No *n, int valor);
void rotacaoDir(No* n);
void rotacaoDirDir(No* n);
void rotacaoEsqDir(No* n);
void rotacaoDirEsq(No* n);
void rotacaoEsq(No* n);
void rotacaoEsqEsq(No* n);


int main() {
	No *raiz;
	raiz = NULL;
	
	int x, alturaE, alturaD, altura, fb, op, valor;

	printf("1 - Inserir \n2 - Imprimir \n3 - Buscar \n0 - Sair \n");

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
				alturaE = alturaEsq(raiz);
				alturaD = alturaDir(raiz);

				//verifica qual o lado da árvore é maior
				if(alturaE > alturaD) {
					altura = alturaE;
				} else {
					altura = alturaD;
				}

				//percorre até a altura maior da árvore
				for(x = 0; x < altura; x++) {
					imprimirLinha(raiz, x);
				}

				fb = fatorBalanceamento(raiz);
				printf("Fator de balanceamento: %d\n", fb);

				if(fb < -1) {	//caso o nó seja nulo, avisa e sai
					printf("ROTACAO DIREITA  %d\n", fb);
					rotacaoDirDir(raiz);
				} else if(fb > 1) {
					rotacaoEsqEsq(raiz);

					printf("ROTAÇAO ESQUERDA  %d\n", fb);
				} else {
					printf("Árvore balanceada.  %d\n", fb);
				}
				break;
			case 3:
				printf("-----BUSCAR-----\n");

				printf("Valor: ");
				scanf("%d", &valor);

				buscar(raiz, valor);
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
					aux->esq->altura = aux->altura + 1;
					aux->esq->esq = NULL;
					aux->esq->dir = NULL;
					printf("Altura: %d\n", aux->esq->altura);
					printf("Inserido à esquerda.\n");

					return raiz;
				}
			} else if(valor > aux->num) { //direita
				if(aux->dir != NULL) {
					aux = aux->dir;	//anda na arvore
				} else {
					aux->dir = malloc(sizeof(No));

					aux->dir->num = valor;
					aux->dir->altura = aux->altura + 1;
					aux->dir->esq = NULL;
					aux->dir->dir = NULL;
					printf("Altura: %d\n", aux->dir->altura);
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

void imprimirLinha(No *raiz, int altura) {
	if(raiz == NULL) {
		return;
	}
	if(raiz->altura == altura) {
		printf("%d \t|%d\n", raiz->num, altura);
	} else {
		imprimirLinha(raiz->esq, altura);
		imprimirLinha(raiz->dir, altura);
	}
}

void buscar(No *n, int valor) {
	if(n != NULL) {
		if(valor == n->num) {
			printf("Valor encontrado: %d \t |Altura: %d\n", n->num, n->altura);
			return;
		} else if(valor > n->num) {
			n = n->dir;
			buscar(n, valor);
		} else if(valor < n->num) {
			n = n->esq;
			buscar(n, valor);
		}
	} else {
		printf("Não encontrado.\n");
	}
}

int alturaEsq(No *n) {
	int alt = 0;

	while(n != NULL) {
		alt++;
		n = n->esq;
	}

	return alt;
}

int alturaDir(No *n) {
	int alt = 0;

	while(n != NULL) {
		alt++;
		n = n->dir;
	}

	return alt;
}

void buscaDesbalanceamento(No* n) {
	int fb;

	if(n == NULL) {
		printf("Nó nulo. \n");
	} else {
		fb = fatorBalanceamento(n);
		if(fb == 0) {
			printf("Árvore balanceada.\n");
			return;
		} else if(fb > 1) {
			n = n->dir;
			

		} else if(fb < -1) {
			n = n->esq;
		}
	}
}


int fatorBalanceamento(No *raiz) {
	int fb = 0;

	fb = alturaDir(raiz->dir) - alturaEsq(raiz->esq);

	return fb;
}

void rotacaoDir(No* n) {
	No *tmp, *aux;
	if(n == NULL) {
		printf("Nó nulo. \n");
		return;
	} else {
		aux = n->esq;
		tmp = aux->esq;
		aux->dir = n;
		aux->altura = aux->altura -1;
		n->esq = NULL;
		n = aux;
		n->altura = n->altura +1;
		printf("Balanceado.\n");
	}
}

void rotacaoEsq(No* n) {
	No *tmp, *aux;
	if(n == NULL) {
		printf("Nó nulo. \n");
		return;
	} else {
		aux = n->dir;
		tmp = aux->esq;
		aux->esq = n;
		aux->altura = aux->altura +1;
		n->dir = tmp;
		n = aux;
		n->altura = n->altura - 1;
		printf("Balanceado.\n");
	}
}

void rotacaoEsqDir(No *n) {
	rotacaoEsq(n->esq);
	rotacaoDir(n);
}

void rotacaoDirEsq(No *n) {
	rotacaoDir(n->dir);
	rotacaoEsq(n);
}

void rotacaoEsqEsq(No *n) {
	rotacaoEsq(n->esq);
	rotacaoEsq(n);
}

void rotacaoDirDir(No *n) {
	rotacaoDir(n->dir);
	rotacaoDir(n);
}