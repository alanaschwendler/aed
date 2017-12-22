//Alana Schwendler - M2

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void push(int *p, int qt);
int pop(int *p, int qt);
void print(int *p, int qt);

int main() {
	int *p;
	p = malloc(sizeof(int));
	assert(p);
	int qt = 0, op, r;

	printf("1 - Inserir \n2 - Remover \n3 - Imprimir \n0 - Sair\n");
	do {
		printf("Opcao: ");
		scanf("%d", &op);

		if(op == 1) {
			qt++;
			push(p, qt);
		} 

		if(op == 2) {
			r = pop(p, qt);
			printf("Removido: %d\n", r);

			qt--;
			p = realloc(p, sizeof(int) * qt);
		}

		if(op == 3) {
			print(p, qt);
		}
	} while(op != 0);

	free(p);
	return 0;
}

void push(int *p, int qt) {
	int n = 0;

	p = realloc(p, sizeof(int) * qt);
	p = p + (qt-1); //p aponta pro final do vetor
	printf("----------\n");
	printf("Valor: ");
	scanf("%d", &n);
	printf("----------\n");
	*p = n;
}

int pop(int *p, int qt) {
	int i, r;
	r = p[0];

	for(i = 0; i < qt-1; i++) {
		p[i] = p[i+1];
	}
	return r;
}

void print(int *p, int qt) {
	int i = 0;
	for(i = 0; i < qt; i++) {
		printf("%d  ", *p);
		p++;
	}
	printf("\n");
}