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

void push(Fila *f, char nome[], int idade);
void imprimir(Fila *f);

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

				push(f, nomeInserir, idadeInserir);
				break;
			case 3:
				printf("-----IMPRIMIR-----\n");

				imprimir(f);
				break;
			default:
				printf("Programa encerrado. \n");
				break;
		}

	} while(op != 0);

	free(f);
	return 0;
}

void push(Fila *f, char nome[], int idade) {
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
	 	printf("sddsdf\n");
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
	printf("Inserido.\n");
}

void imprimir(Fila *f) {
	int x = 0;

	
}