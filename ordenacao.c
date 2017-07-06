//Alana Schwendler - M1

#include <stdio.h>
#include <stdlib.h>

void imprimir(int *v, int qt);
int bubbleSort(int *v, int qt);
int insertionSort(int *v, int qt);
//void mergeSort(int v*, int qt);

int main() {
	int qt = 0, op = 0, ord = 0;
	int *vet;
	vet = malloc(sizeof(int));

	do {
		qt++;
		vet = realloc(vet, (sizeof(int) * qt));
		printf("Valor: ");
		scanf("%d", &vet[qt-1]);
	} while (vet[qt-1] != 0);
	
	imprimir(vet, qt);
	
	do {
		printf("---Ordenação---\n");
		printf("1 - Bubble \n2 - Insertion \n0 - Sair \n");
		scanf("%d", &op);
		switch(op) {
			case 1:
				if(ord == 1) {
					printf("Já ordenado. \n");
					break;
				} else {
					ord = bubbleSort(vet, qt);
					printf("Ordenado bubble.\n");
					imprimir(vet, qt);
					break;
				}
			case 2:
				if(ord == 1) {
					printf("Já ordenado.\n");
					break;
				} else {
					ord = insertionSort(vet, qt);
					printf("Ordenado insertion.\n");
					imprimir(vet, qt);
					break;
				}
			case 3:
				//mergeSort();
				printf("Ordenado merge.\n");
				imprimir(vet, qt);
				break;
			default: 
				printf("Programa encerrado.\n");
				break;
		}
	} while(op != 0);
	free(vet);
	return 0;
}

void imprimir(int *v, int qt) {
	int i;
	for(i = 0; i < qt; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

//bubble melhorado
int bubbleSort(int *v, int qt) {
	//n controla quantas vezes já percorreu o vetor e troca indica se o vetor já está ordenado
	int x = 1, i, aux, troca = 1;
	
	while(x <= qt && troca == 1) {
		//seta troca com 0 pra poder ordenar
		troca = 0;
		for(i = 0; i < qt-1; i++) {
			if(v[i] > v[i+1]) {
				troca = 1;
				aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux;
				imprimir(v, qt);
			}
		}
		x++;
	}	
	return 1;
}

int insertionSort(int *v, int qt) {
	int i, j, aux;
	//começa na segunda posição do vetor
	for(j = 1; j <= qt; j++) {
		//i vai ser a posição anterior ao j
		i = j - 1;
		//aux tem a posição atual de j
		aux = v[j];
		//enquanto o i é maior ou igual a 0 e o valor escolhido é menor que a posição atual em i
		while(i >= 0 && aux < v[i]) {
			//faz a troca
			v[i+1] = v[i];
			//decrementa o i
			i--;
			imprimir(v, qt);
		}
		//muda o escolhido
		v[i+1] = aux;
	}
	return 1;
}

//void mergeSort(int v*, int qt) { }
