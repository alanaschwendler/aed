//Alana Schwendler - M1
#include <stdio.h>
#include <stdlib.h>

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
void pop(Aluno *a, Pilha *p);
void clear(Pilha *p);
void reset(Pilha *p);
Aluno buscaNome(Aluno *a, Pilha *p);

int main() {
	Aluno *aluno;
	aluno = malloc(sizeof(Aluno));

	Pilha *pilha;
	pilha = malloc(sizeof(Pilha));
	*pilha = NULL;

	int op = 0;
	printf("1 - Inserir \n2 - Remover \n3 - Limpar pilha \n4 - Resetar pilha \n5 - Buscar");
	scanf("%d", &op);

	switch(op) {
		case 1:
			printf("-----INSERE-----\n");
			printf("Nome: ");
			scanf("%s", aluno->nome);
			printf("Matricula: ");
			scanf("%d", aluno->matricula);

			push(aluno, pilha);
			break;
		case 2:
		printf("-----REMOVE-----\n");
			printf("Nome: ");
			scanf("%s", aluno->nome);
			printf("Matricula: ");
			scanf("%d", aluno->matricula);

			pop(aluno, pilha);
			break;
		case 3:
			printf("-----LIMPA-----\n");
			clear(pilha);
			break;
		case 4:
			printf("-----RESETAS-----\n");
			reset(pilha);
			break;
		case 5:
			printf("-----BUSCA-----\n");
			buscaNome(aluno);
			break;
		default:
			printf("Inválido.\n");
			break;
	}
	
	free(aluno);
	free(pilha);
	return 0;
}

void push(Aluno *a, Pilha *p) {
	//incrementa a quantidade da pilha
	p->quantidade++;

	//vai alocar espaço para a pilha de acordo com a quantidade de alunos inseridos
	p = realloc(p, sizeof(Aluno) * p->quantidade);	
	//ajusta os ponteiros da pilha
	//o primeiro aluno na pilha é a primeira posição da pilha
	p->primeiro = *p;
	//o ultimo é quem está sendo inserido 
	p->ultimo = a;
}

//tira um elemento da pilha
void pop(Aluno *a, Pilha *p) {
	//decrementa a quantidade total
	p->quantidade--;
	//o ultimo vira NULL
	p->ultimo = NULL;
	//realoca memória pra nova quantidade de alunos
	p = realloc(p, sizeof(Aluno) * (p->quantidade));
	//ajusta os ponteiros
	p->primeiro = *p;
	p->ultimo = p + (sizeof(Aluno) * (p->quantidade - 1));
}

//limpa todos os dados da pilha
void clear(Pilha *p) {
	p->primeiro = NULL;
	p->ultimo = NULL;
	p->aluno = NULL;
}

//reseta todos os dados da pilha
void reset(Pilha *p) {
	p->primeiro = NULL;
	p->ultimo = NULL;
	p->aluno = NULL;
	p->quantidade = 0;
}

Aluno buscaNome(Aluno *a, Pilha *p) {
	int x = 0;
	for(x = 0; x < p->quantidade; x++) {
		if(strcmp(a->nome, p->aluno.nome) == 0)  {
			return a;
		}
	}
}