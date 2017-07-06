//Alana Schwendler - M1

#include <stdio.h>
#include <stdlib.h>

void imprimir(int *v, int qt);
int bubbleSort(int *v, int qt);
int insertionSort(int *v, int qt);
int selectionSort(int *v, int qt);
void mergeSort(int *v, int inicio, int meio, int fim);

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
		printf("1 - Bubble \n2 - Insertion \n3 - Selection \n4 - Merge \n0 - Sair \n");
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
				if(ord == 1) {
					printf("Já ordenado.\n");
					break;
				} else {
					ord = selectionSort(vet, qt);
					printf("Ordenado selection.\n");
					imprimir(vet, qt);
					break;
				}
			case 4:
				if(ord == 1) {
					printf("Já ordenado.\n");
					break;
				} else {
					int inicio = vet[0];
					int fim = (int)(((void *) vet) + sizeof(int));
					int meio = qt/2;
					meio = meio + 1;

					mergeSort(vet, inicio, vet[meio], fim);
					printf("Ordenado merge.\n");
					imprimir(vet, qt);
					break;
				}
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

int selectionSort(int *v, int qt) {
	int i, j, menor, escolhido, posicao;
	for(i = 0; i <= qt-1; i++) {
		//o escolhido vai ser o primeiro do vetor, pra começar a comparar com os outros valores
		escolhido = v[i]; 
		//o proximo é dito como menor, pra comparar com o escolhido
		menor = v[i+1];
		//a posicao é sempre uma a mais do que o valor atual de i
		posicao = i+1;
		//j começa em i+1 e vai até o fim do vetor, pra não fazer testes duplicados
		for(j = i+1; j <= qt; j++) {
			//testa se a posição atual é menor que o menor valor escolhido no inicio
			if(v[j] < menor) {
				//faz a troca e atualiza a posição que é em relação a i+1
				menor = v[j];
				posicao = j;
			}
		}
		//ve se o valor de menor é menor que o valor de escolhido
		if(menor < escolhido) {
			//troca os valores 
			v[i] = v[posicao];
			v[posicao] = escolhido;
		}
		imprimir(v, qt);
	}
	return 1;
}

void mergeSort(int *v, int esq, int meio, int dir) {
	int i, j, k;
	int l1 = meio - esq + 1;
	int l2 = dir - meio;
	int esquerda[l1];
	int direita[l2];

	printf("ESQ: %d DIR: %d MEIO: %d\n", esq, dir, meio);
	printf("L2: %d\n", l2);

	for(i = 0; i < l1; i++) {
		esquerda[i] = v[esq + i];
	}
	for(j = 0; j < l2; j++) {
		direita[j] = v[meio + 1 + j];
	}

	imprimir(esquerda, l1);
	printf("\t");
	imprimir(direita, l2);
}
