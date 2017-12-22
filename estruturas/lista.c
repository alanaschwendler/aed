#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct element {
	int value;
	struct element *next;
} element_t;

void insert(element_t *e, int v);
void print(element_t *e);
void clear(element_t *e);
int removeNode(element_t *e, int v);
int search(element_t *e, int v);

int main() {
	int op, n, r;
	element_t *e = malloc(sizeof(element_t));
	e->next = NULL;
	printf("1 - Insert \n2 - Print \n3 - Remove element \n4 - Search element \n5 - Clear list\n0 - Quit\n");

	do {
		printf("Option: ");
		scanf("%d", &op);

		if(op == 1) {
			printf("Value: ");
			scanf("%d", &n);
			insert(e, n);
		}

		if(op == 2) {
			print(e);
		}

		if(op == 3) {
			printf("Value: ");
			scanf("%d", &n);
			r = removeNode(e, n);
			if(r != -1) {
				printf("%d was removed\n", r);
			}
		}

		if(op == 4) {
			printf("Value: ");
			scanf("%d", &n);
			r = search(e, n);
			if(r != -1) {
				printf("%d is at the list\n", r);
			}
		}

		if(op == 5) {
			clear(e);
			printf("**Now it's clean**\n");
		}

	} while(op != 0);
	clear(e);
	return 0;
}

//insere novo elemento na lista
void insert(element_t *e, int v) {
	element_t *new = malloc(sizeof(element_t));
	assert(new);

	//verifica se o proximo é nulo
	while(e->next != NULL) {
		//anda na lista
		e = e->next;
	}
	//nesse ponto, "e" aponta pro ultimo da lista

	//ajusta os ponteiros e insere o valor
	e->next = new;
	new->value = v;
	new->next = NULL;
}

//imprime toda a lista
void print(element_t *e){
	if(e->next == NULL) {
		printf("*Empty list**\n");
	}
	e = e->next;
	while(e != NULL) {
		printf("Element value: %d\n", e->value);
		e = e->next;
	}	
}

//limpa a lista
void clear(element_t *e) {
	element_t *kill;

	while(e->next != NULL) {
		kill = e->next;
		e->next = e->next->next;
		free(kill);
	}
	//deixa só o sentinela
	e->next = NULL;
}


//remove um nodo especifico
int removeNode(element_t *e, int v) {
	int r;

	//não existem registros
	if(e->next == NULL) {
		printf("**Not your lucky day**\n");
		return -1;
	}

	//busca por toda a lista
	while((e->next != NULL) && (e->next->value != v)) {
		e = e->next;
	}

	//se entrar nesse if, é porque o valor não está na lista 
	if(e->next == NULL) {
		printf("**Not found**\n");
		return -1;
	}
	
	element_t *rem;
	//marca o valor a ser removido e ajusta os ponteiros
	rem = e->next;
	r = rem->value;
	e->next = rem->next;

	//remove efetivamente
	free(rem);	

	return r;
}

//busca por um elemento
int search(element_t *e, int v) {
	int r;
	//não existem registros
	if(e->next == NULL) {
		printf("**Not your lucky day**\n");
		return -1;
	}

	//percorre toda a lista
	while((e->next != NULL) && (e->next->value != v)) {
		e = e->next;
	}

	//se entrar aqui é porque não está na lista
	if(e->next == NULL) {
		printf("**Not found**\n");
		return -1;
	}

	//salva o valor e retorna
	r = e->next->value;
	return r;
}