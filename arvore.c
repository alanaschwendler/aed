#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct n {
	int num;
	struct n *esq;
	struct n *dir;
	struct n *pai;
} No;

void inserir(No *n, int valor);
void imprimir(No *n);

int main() {
	No *n;
	n = malloc(sizeof(No));
	n->pai = NULL;
	n->esq = NULL;
	n->dir = NULL;
	n->num = -1; //inicializa o valor com -1 significando que nenhum valor foi inserido na raiz

	int val;
	int op;

	printf("1 - Inserir \n2 - Imprimir \n0 - Sair \n");

	do {
		printf("Opção: ");
		scanf("%d", &op);

		switch(op) {
			case 1:
				printf("-----INSERIR-----\n");
				printf("Numero: ");
				scanf("%d", &val);

				inserir(n, val);
				break;
			case 2:
				printf("-----IMPRIMIR AINDA NÃO ESTÁ PRONTA-----\n");

					imprimir(n);
				break;	
			default:
				printf("Programa encerrado. \n");
				break;
		}
	} while(op != 0);
	free(n);
	return 0;
}

void inserir(No *n, int valor) {
	No *novo;

	if(n->num == -1) {	//caso a arvore esteja vazia
		n->num = valor;	//preenche com os valores passados
		n->esq = NULL;
		n->dir = NULL;
		n->pai = NULL;
		printf("Raiz inserida. \n");
	} else if(valor < n->num) {
		novo = malloc(sizeof(No));
		
		n->esq = novo;
		novo->num = valor;
		novo->esq = NULL;
		novo->dir = NULL;
		novo->pai = n;
		printf("Inserido. \n");
	} else if(valor > n->num) {
		novo = malloc(sizeof(No));

		n->dir = novo;
		novo->num = valor;
		novo->esq = NULL;
		novo->dir = NULL;
		novo->pai = n;
		printf("Inserido. \n");
	} else {
		printf("Erro: registro já existente na árvore.\n");
	}
}           

void imprimir(No *n) {
	//SÓ PRA VER SE TÁ INSERINDO NOVO OU SOBRESCREVENDO
	//TENTAR INSERIR DOIS REGISTROS MAIORES OU DOIS MENORES QUE A RAIZ
	printf("\t %d \n", n->num);
	printf("%d            %d\n", n->esq->num, n->dir->num);
}