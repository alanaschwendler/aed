//Alana Schwendler - M1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct a {
	char nome[20];
	int matricula;
} Aluno;

typedef struct p {
	Aluno *primeiro;
	Aluno *ultimo;
	int quantidade;
} Pilha;

void push(Aluno *a, Pilha *p);
void pop(Pilha *p);
void clear(Pilha *p);
void reset(Pilha *p);
void buscaNome(char nome[], Pilha *p);
void listar(Pilha *p);
void ajusta(Aluno *aux, int x, Pilha *p);
void deletaNome(char nome[], Pilha *p);

int main() {
	Aluno *aluno;
	aluno = (Aluno *)malloc(sizeof(Aluno));

	Pilha *pilha;
	pilha = (Pilha *)malloc(sizeof(Pilha));

	int op = 0;

	printf("1 - Inserir \n2 - Remover \n3 - Limpar \n4 - Resetar \n5 - Buscar \n6 - Listar \n7 - Deleta \n0 - Sair \n");
	do {
		printf("Opção: ");
		scanf("%d", &op);
		switch(op) {
			case 1:
				printf("-----INSERIR-----\n");
				printf("Nome: ");
				scanf("%s", aluno->nome);
				printf("Matricula: ");
				scanf("%d", &aluno->matricula);

				push(aluno, pilha);
				break;
			case 2:
				printf("-----REMOVER-----\n");
				pop(pilha);
				break;
			case 3:
				printf("-----LIMPAR-----\n");
				clear(pilha);
				break;
			case 4:
				printf("-----RESETAR-----\n");
				reset(pilha);
				break;
			case 5:
				printf("-----BUSCAR-----\n");
				char nomeBusca[20];
				printf("Nome: ");
				scanf("%s", nomeBusca);

				buscaNome(nomeBusca, pilha);
				break;
			case 6:
				printf("-----LISTAR-----\n");
				listar(pilha);
				break;
			case 7:
				printf("-----DELETAR-----\n");
				char nomeDeleta[20];
				printf("Nome: ");
				scanf("%s", nomeDeleta);

				deletaNome(nomeDeleta, pilha);
				break;
			default:
				printf("Programa encerrado.\n");
				break;
		}
	} while(op != 0);

	free(aluno);
	free(pilha);
	return 0;
}

void push(Aluno *a, Pilha *p) {
	//incrementa a quantidade da pilha
	p->quantidade = p->quantidade + 1;

	//aloca espaço de acordo com a quantidade e ajusta o ponteiro do primeiro
	p->primeiro = (Aluno *)realloc(p->primeiro, sizeof(Aluno) * p->quantidade);	
	//o ultimo é quem está sendo inserido 
	p->ultimo = p->primeiro + (p->quantidade -1);

	//copia os valores do aluno pro que foi inserido na pilha
	strcpy(p->ultimo->nome, a->nome);
	p->ultimo->matricula = a->matricula;
}

//tira um elemento da pilha
void pop(Pilha *p) {
	if(p->quantidade == 0) {
		printf("Pilha vazia.\n");
	} else {
		//decrementa a quantidade total
		p->quantidade--;
		//o ultimo vira NULL
		p->ultimo = NULL;
		//realoca memória pra nova quantidade de alunos
		p->primeiro = realloc(p->primeiro, sizeof(Aluno) * (p->quantidade));
		p->ultimo = p->primeiro + (sizeof(Aluno) * (p->quantidade - 1));

		printf("Removido.\n");
	}
}

//limpa todos os dados da pilha
void clear(Pilha *p) {
	p->primeiro = NULL;
	p->ultimo = NULL;
	p->quantidade = 0;
	printf("Lista limpa.\n");
}

//reseta todos os dados da pilha
void reset(Pilha *p) {
	p->primeiro = 0;
	p->ultimo = 0;
	p->quantidade = 0;
	printf("Lista resetada.\n");
}

void buscaNome(char nome[], Pilha *p) {
	int x = 0, encontrado = 0;
	if(p->quantidade == 0) {
		printf("Pilha sem registros.\n");
	} else {
		Aluno *aux;
		aux = p->primeiro;
		for(x = 0; x < p->quantidade; x++) {
			if(strcmp(nome, aux->nome) == 0) {
				printf("Encontrado\n");
				printf("Nome: %s Matricula: %d\n", aux->nome, aux->matricula);
				return;
			} else {
				aux = aux + 1;
			}
		}

		if(encontrado == 0) {
			printf("Não encontrado.\n");
		} 
	}
}

void listar(Pilha *p) {
	int x = 0; //controle do loop
	Aluno *a; //aluno auxiliar
	a = p->primeiro; //o auxiliar vai ser o primeiro da pilha

	printf("\n");
	if(p->quantidade == 0) {
		printf("Pilha sem registros.\n");
	} else {
		printf("Quantidade de alunos na pilha: %d\n", p->quantidade);
		for(x = 0; x < p->quantidade; x++) {
			printf("Nome: %s\n", a->nome);
			printf("Matricula: %d\n", a->matricula);
			a = a + 1; //incrementa uma struct aluno em a
		}
	}
	printf("\n");
}

void ajusta(Aluno *aux, int x, Pilha *p) {
	int y = 0;

	for(y = x; y < p->quantidade; y++) {
		strcpy(aux->nome, (aux+1)->nome);
		aux->matricula = (aux+1)->matricula;
		aux = aux + 1;
	}
}


void deletaNome(char nome[], Pilha *p) {
	int x = 0, encontrado = 0;
	if(p->quantidade == 0) {
		printf("Pilha sem registros.\n");
	} else {
		Aluno *aux;
		aux = p->primeiro;
		for(x = 0; x < p->quantidade; x++) {
			if(strcmp(nome, aux->nome) == 0) {
				printf("Encontrado\n");
				printf("Nome: %s Matricula: %d\n", aux->nome, aux->matricula);
				ajusta(aux, x, p);
			} else {
				aux = aux + 1;
			}
		}

		p->quantidade = p->quantidade - 1;
		p->primeiro = realloc(p->primeiro, sizeof(Aluno) * p->quantidade);
		p->ultimo = p->primeiro + (p->quantidade -1);

		printf("Deletado\n");
		listar(p);

		if(encontrado == 0) {
			printf("Não encontrado.\n");
		} 
	}
}