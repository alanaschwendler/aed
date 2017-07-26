//Alana Schwendler - M1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct para armazenar Nomes
typedef struct Item {
	char nome[20];
	int idade;
	int cpf;
	struct Item *prox;
} Item;

void inserir(Item *i, char nome[], int idade, int cpf);
void remover(Item *i, char nome[]);
void imprimir(Item *i);

int main() {
	//cria um Item, aloca espaço e ajusta o ponteiro de próximo pra apontar pra NULL
	Item *i;
	i = malloc(sizeof(Item));
	i->prox = NULL;
	
	int op = 0;

	printf("1 - Inserir \n2 - Remover \n3 - Limpar \n4 - Imprimir \n0 - Sair \n");

	do {
		printf("Opção: ");
		scanf("%d", &op);

		switch(op) {
			case 1:
				printf("-----INSERIR-----\n");
				char nomeInserir[20];
				int idade;
				int cpf;

				printf("Nome: " );
				scanf("%[^\n]s", nomeInserir);
				printf("Idade: ");
				scanf("%d", &idade);
				printf("CPF (apenas numeros): ");
				scanf("%d", &cpf);

				inserir(i, nomeInsere, idade, cpf);
				break;
			case 2:
				printf("-----REMOVER REGISTRO-----\n");
				char nomeRemover[20];

				printf("Nome: ");
				scanf("%[^\n]s", nomeRemover);

				remover(i, nomeRemover);
				break;
			case 4:
				printf("-----IMPRIMIR REGISTROS-----\n");

				imprimir(i);
				break;
			default:
				printf("Programa encerrado\n");
				break;
		}
		
	} while(op != 0);
	return 0;
}

void inserir(Item *i, char nome[], int idade, int cpf) {
	Item *novo;
	novo = malloc(sizeof(Item));
	//copia os valores pro novo nodo
	strcpy(novo->nome, nome);
	novo->idade = idade;
	novo->cpf = cpf;
	//ajusta o prox para apontar para NULL
	novo->prox = i->prox;
	//ajusta o prox do item
	i->prox = novo;
	printf("Inserido.\n");
}

void remover(Item *i, char nome[]){
	Item *j, *k; //itens auxiliares
	j = i; //j tem a cabeça da lista
	k = i->prox; //k tem o próximo item da lista
	
	for(j = i->prox; j != NULL; j = j->prox) {
		if(strcmp(j->nome, nome) == 0) {

		}
	}
}

void imprimir(Item *i) {
	Item *j;
	for(j = i->prox; j != NULL; j = j->prox) {
		printf("Nome: %s, Idade: %d, CPF: %d\n", j->nome, j->idade, j->cpf);
	}
}