//Alana Schwendler - M1

#include <stdio.h>
#include <stdlib.h>

void imprimir(int *v, int qt);
int bubbleSort(int *v, int qt);
int insertionSort(int *v, int qt);
int selectionSort(int *v, int qt);
void mergeSort(int *v, int inicio, int meio, int fim);
void merge(int *vet, int inicio, int fim);

int main() {	
	int qt = 0, op = 0, ord = 0, aux, inicio, fim;
	int *vet;
	vet = malloc(sizeof(int));

	do {
		qt++;
		vet = realloc(vet, (sizeof(int) * qt));
		printf("Valor: ");
		scanf("%d", &aux);
		if(aux != 0) {
			vet[qt-1] = aux;
		}		
	} while (aux != 0);
	qt--;
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
					inicio = 0;
					fim = qt-1;

					merge(vet, inicio, fim);
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
	int pLivre, iniEsq, iniDir, i;
	int qt = esq+dir;
	int *aux;
	aux = malloc(sizeof(int) * qt);
	iniEsq = esq;
	iniDir = meio + 1;
	pLivre = esq;

	while(iniEsq <= meio && iniDir <= dir) {
		//intercala os valores do vetor
		if(v[iniEsq] <= v[iniDir]) {
			aux[pLivre] = v[iniEsq];
			iniEsq++;
		} else {
			aux[pLivre] = v[iniDir];
			iniDir++;
		}
		pLivre++;

		//ajusta o vetor da esquerda
		for(i = iniEsq; i <= meio; i++) {
			aux[pLivre] = v[i];
			pLivre++;
		}

		//ajusta o vetor da direita
		for(i = iniDir; i <= dir; i++) {
			aux[pLivre] = v[i];
			pLivre++;
		}

		//preenche o vetor final com os valores intercalados
		for(i = esq; i <= dir; i++) {
			v[i] = aux[i];
		}
	}
	free(aux);
}

void merge(int *vet, int inicio, int fim) {
	int meio;
	if(inicio < fim) {
		meio = (inicio + fim)/2;
		merge(vet, inicio, meio);
		merge(vet, meio+1, fim);
		mergeSort(vet, inicio, fim, meio);
	}
}