//Alana Schwendler - M1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct p {
	char nome[20];
	int idade;
} Pessoa;

typedef struct f {
	struct f *next;
	struct f *prev;
	Pessoa *pessoa;
	int qt;
} Fila;

void inserir(Fila *f, char nome[], int idade);
void remover(Fila *f);
void imprimir(Fila *f);
void limpar(Fila *f);

int main() {
	Fila *f;
	f = malloc(sizeof(Fila));
	f->prev = NULL;
	f->next = NULL;


	int op;

	printf("1 - Inserir \n2 - Remover \n3 - Imprimir \n4 - Limpar \n0 - Sair \n");

	do {
		printf("Opção: ");
		scanf("%d", &op);

		switch(op) {
			case 1:
				printf("-----INSERIR-----\n");

				char nomeInserir[20];
				int idadeInserir;

				printf("Nome: ");
				scanf("%s", nomeInserir);
				printf("Idade: ");
				scanf("%d", &idadeInserir);

				inserir(f, nomeInserir, idadeInserir);
				break;
			case 2:
				printf("-----REMOVER-----\n");

				remover(f);
				break;
			case 3:
				printf("-----IMPRIMIR-----\n");

				imprimir(f);
				break;
			case 4:
				printf("-----LIMPAR-----\n");

				limpar(f);
				break;
			default:
				printf("Programa encerrado. \n");
				break;
		}

	} while(op != 0);

	free(f);
	return 0;
}

void inserir(Fila *f, char nome[], int idade) {
	Fila *nv;
	Fila *aux;

	Pessoa *p;
	p = malloc(sizeof(Pessoa));

	aux = f->next;

	f->qt++;
	nv = malloc(sizeof(Fila));
	nv->pessoa = p;

	if(aux != NULL) {
		while(aux->next != NULL) { //enquanto o próximo for diferente de NULL
			aux = aux->next; //anda na fi
		}

		aux->next = nv;
		nv->prev = aux;
		nv->next = NULL;
		strcpy(nv->pessoa->nome, nome);
		nv->pessoa->idade = idade;

	} else {
		f->next = nv;
		nv->prev = f;
		nv->next = NULL;
		strcpy(nv->pessoa->nome, nome);
		nv->pessoa->idade = idade;
	}
	printf("Inserido. \n");
}

void remover(Fila *f) {
	Fila *aux;

	aux = f->next;

	if(f->next == NULL) {
		printf("Fila vazia. \n");
	} else {
		f->next = aux->next;
		free(aux);
		printf("Removido. \n");
	}
}

void imprimir(Fila *f) {
	Fila *aux;

	aux = f->next;

	if(f->next == NULL) {
		printf("Fila vazia. \n");
	} else {
		while(aux != NULL) {
			printf("Nome: %s, Idade: %d\n", aux->pessoa->nome, aux->pessoa->idade);
			aux = aux->next;
		}
	}
	printf("Fim dos registros. \n");
}

void limpar(Fila *f) {
	Fila *aux, *p;

	aux = f->next;
	if(aux == NULL) {
		free(f);
		printf("Apenas a cabeça da fila foi removida. Não há mais elementos. \n");
	} else {
		while(aux != NULL) {
			p = aux;
			aux = aux->next;
			free(p);
		}
		free(aux);
		f->next = NULL;
		printf("Todos os elementos foram removidos. \n");
	}
}