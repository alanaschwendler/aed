//Alana Schwendler - M1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa {
	char nome[20];
	int idade;
} pessoa;

typedef struct Fila {
	Fila *next;
	Fila *prev;
	Pessoa *pessoa;
} fila;

void push(Fila *f, char nome[], int idade);

int main() {
	Fila *f;
	f = malloc(sizeof(Fila));

	Pessoa *p;
	p = malloc(sizeof(Pessoa));

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
			default:
				printf("Programa encerrado. \n");
				break;
		}

	} while(op != 0);

	return 0;
}

void push(Fila *f, char nome[], int idade) {
	if(f->next == NULL) { //se o próximo da fila é NULL, é ai que precisa inserir
		f = f->next; //anda na fila
		strcpy(f->pessoa->nome, nome); //copia os dados pra pessoa	
		f->pessoa->idade = idade;
		f->next = NULL;
	}
}