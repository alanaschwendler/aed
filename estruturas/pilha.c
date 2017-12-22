//Alana Schwendler - M2

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct s {
	int *top;
	int *base;
	int n;
} Stack;

void push(Stack *st, int v);
int  empty(Stack *st);
void print(Stack *st);
int  pop(Stack *st);
void search(Stack *st, int v);
void putItBack(Stack *st, Stack *aux);

int main() {
	//aloca espaço pra pilha
	Stack *st = malloc(sizeof(Stack));
	//verifica se conseguiu alocar corretamente
	assert(st);
	//ajusta os ponteiros 
	st->top = NULL;
	st->base = NULL;
	//seta quantidade como 0
	st->n = 0;

	int op, v;

	printf("1 - Insert \n2 - Print Stack \n3 - Remove \n4 - Search Value \n0 - Quit\n");

	do { 
		printf("Option: ");
		scanf("%d", &op);

		if(op == 1) {
			
			printf("\n----------\n");
			printf("Value: ");
			scanf("%d", &v);
			printf("\n----------\n");
			
			push(st, v);
		}

		if(op == 2) {
			print(st);
		}

		if(op == 3) {
			v = pop(st);
			printf("Removed: %d\n", v);
		}

		if(op == 4) {
			printf("Value: ");
			scanf("%d", &v);
			search(st, v);
		}

	} while(op != 0);

	//libera memória da pilha
	free(st);
	return 0;
}

void push(Stack *st, int v) {
	st->n += 1;
	//realoca espaço de acordo com a quantidade de elementos
	st->base = realloc(st->base, sizeof(int) * st->n);
	//verifica se conseguiu alocar corretamente
	assert(st->base);

	//ajusta o ponteiro do topo
	st->top = st->base + (st->n -1);
	*st->top = v;
}

int empty(Stack *st) {
	//testa se a pilha está vazia
	if(st->n == 0) {
		printf("\n**You are at the bottom of the stack**\n");
		return 1;
	}
	return 0;
}

//print percorrendo o vetor sem dar pop
void print(Stack *st) {
	int i;
	//faz uma cópia do topo pra um ponteiro auxiliar
	int *a = st->top;

	//verifica se a pilha está vazia
	if(empty(st)) {
		return;
	}

	//imprime na ordem da pilha
	printf("\nTOP\n---\n");
	for(i = st->n; i > 0; i--) {
		printf("%d\n", *a);
		a--;
	}
	printf("---\nBASE\n\n");
}

int pop(Stack *st) {
	//testa se a pilha está vazia
	if(empty(st)) {
		printf("**You cannot remove from the empty stack** \n");
		exit(1);
	}
	if(st->n > 0) {
		st->n -= 1;
	}
	int r = *st->top;
	//realoca espaço com a quantidade -1
	st->base = realloc(st->base, sizeof(int) * st->n); 
	//ajusta o ponteiro do topo
	st->top = st->base + (st->n -1);

	return r;
}

//print fazendo o pop e salvando em uma pilha auxiliar
void search(Stack *st, int v) {
	int i, j, r;

	//testa se a pilha está vazia
	if(empty(st)) {
		return;
	}

	//cria uma pilha auxiliar
	Stack *auxStack = malloc(sizeof(Stack));
	auxStack->base = NULL;
	auxStack->top = auxStack->base;
	auxStack->n = 0;

	//busca enquanto a pilha original não está vazia
	while(!empty(st)) {
		//faz pop do topo
		r = pop(st);
		//compara o valor retirado da pilha com o valor desejado
		if(r == v) {
			printf("\n**Founded**\n");
			printf("%d\n", r);
			//faz push do valor retirado
			push(st, r);
			//copia o conteudo da pilha auxiliar de volta para a pilha original
			putItBack(st, auxStack);
			//libera a memória da pilha auxiliar
			free(auxStack);
			return;
		}
		//coloca da pilha original para a pilha auxiliar, caso o valor não seja o desejado
		push(auxStack, r);

		//avisa se a pilha está vazia e não encontrou o valor
		if(empty(st)) {
			printf("**Not founded on the stack**\n");
			putItBack(st, auxStack);
			free(auxStack);
			return;
		}
	}
}

//cloca os valores da pilha auxiliar de volta na pilha original
void putItBack(Stack *st, Stack *aux) {
	int i;
	
	//enquanto a pilha auxiliar ainda tem algo, coloca na pilha original 
	while(!empty(aux)) {
		i = pop(aux);
		push(st, i);
	}
}