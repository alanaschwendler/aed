//Alana Schwendler - M1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct a {
	char nome[20];
	int matricula;
} Aluno;

typedef struct p {
	Aluno *primeiro; //
	Aluno *ultimo;
	Aluno *aluno;
	int quantidade;
} Pilha;

void push(Aluno *a, Pilha *p);
//void pop(Aluno *a, Pilha *p);
//void clear(Pilha *p);
//void reset(Pilha *p);
//Aluno buscaNome(Aluno *a, Pilha *p);
void listar(Pilha *p);

int main() {
	Aluno *aluno;
	aluno = (Aluno *)malloc(sizeof(Aluno));

	Pilha *pilha;
	pilha = (Pilha *)malloc(sizeof(Pilha));

	int op = 0;

	do {
		printf("1 - Inserir \n2 - Remover \n3 - Limpar \n4 - Resetar \n5 - Buscar \n6 - Listar \n0 - Sair \n");
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
				printf("Nome: ");
				scanf("%s", aluno->nome);
				printf("Matricula: ");
				scanf("%d", &aluno->matricula);

				//pop(aluno, pilha);
				break;
			case 3:
				printf("-----LIMPAR-----\n");
				//clear(pilha);
				break;
			case 4:
				printf("-----RESETAR-----\n");
				//reset(pilha);
				break;
			case 5:
				printf("-----BUSCAR-----\n");
				//buscaNome(aluno, pilha);
				break;
			case 6:
				printf("-----LISTAR-----\n");
				listar(pilha);
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

	//vai alocar espaço para a pilha de acordo com a quantidade de alunos inseridos
	p = (Pilha *)realloc(p, sizeof(Aluno) * p->quantidade);	
	//ajusta os ponteiros da pilha
	//o primeiro aluno na pilha é a primeira posição da pilha
	p->primeiro = ((Aluno *) p);
	//o ultimo é quem está sendo inserido 
	p->ultimo = p->primeiro + (p->quantidade -1);

	//copia os valores do aluno pro que foi inserido na pilha
	strcpy(p->ultimo->nome, a->nome);
	p->ultimo->matricula = a->matricula;
}

//tira um elemento da pilha
// void pop(Aluno *a, Pilha *p) {
// 	//decrementa a quantidade total
// 	p->quantidade--;
// 	//o ultimo vira NULL
// 	p->ultimo = NULL;
// 	//realoca memória pra nova quantidade de alunos
// 	p = realloc(p, sizeof(Aluno) * (p->quantidade));
// 	//ajusta os ponteiros
// 	p->primeiro = p;
// 	p->ultimo = p + (sizeof(Aluno) * (p->quantidade - 1));
// }

//limpa todos os dados da pilha
// void clear(Pilha *p) {
// 	p->primeiro = NULL;
// 	p->ultimo = NULL;
// 	p->aluno = NULL;
// }

//reseta todos os dados da pilha
// void reset(Pilha *p) {
// 	p->primeiro = NULL;
// 	p->ultimo = NULL;
// 	p->aluno = NULL;
// 	p->quantidade = 0;
// }

// Aluno buscaNome(Aluno *a, Pilha *p) {
// 	int x = 0;
// 	for(x = 0; x < p->quantidade; x++) {
// 	}
// }

void listar(Pilha *p) {
	int x = 0; //controle do loop
	Aluno *a; //aluno auxiliar
	a = (Aluno *)p; //o auxiliar vai ser o primeiro da pilha

	printf("\n");
	if(p->quantidade == 0) {
		printf("Pilha sem registros.\n");
	} else {
		printf("Quantidade de alunos na pilha: %d\n", p->quantidade);
		for(x = 0; x < p->quantidade; x++) {
			printf("Nome: %s\n", a->nome);
			printf("Matricula: %d\n", a->matricula);
			a++; //incrementa uma struct aluno em a
		}
	}
	printf("\n");
}