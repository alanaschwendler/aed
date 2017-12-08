//Alana Schwendler

#include <stdio.h>
#include <stdlib.h>

/*
 * combina os subvetores, ordenando
 */
void conquer(int i, int f, int mid, int vet[], int *ord) {
	int j = i; //iterador do vetor total
	int cLeft = i; //atual do vet da esquerda
	int cRight = mid+1; //atual do vet da direita

	while((cLeft <= mid) && (cRight <= f)) { //vai ordenando de encontro ao meio
		if(vet[cLeft] < vet[cRight]) { //vê qual o menor
			ord[j] = vet[cLeft];	//atribui ao vetor ordenado
			++cLeft;
		} else if(vet[cLeft] > vet[cRight]) {
			ord[j] = vet[cRight];
			++cRight;
		} else if(vet[cLeft] == vet[cRight]) {
			ord[j] = vet[cLeft];
			j++;
			ord[j] = vet[cRight];
			++cLeft;
			++cRight;
		}
		++j;
	}

	while(cLeft <= mid) {
		ord[j] = vet[cLeft];
		++j;
		++cLeft;
	}

	while(cRight <= f) {
		ord[j] = vet[cRight];
		++j;
		++cRight;
	}

	for(j = i; j <= f; ++j) { //copia tudo pro vetor original
		vet[j] = ord[j];
	}
}

/*
 * faz a divisão do vetor em subvetores
 */  
void divide(int vet[], int i, int f, int *ord) {
	if(f <= i) { //significa que tem apenas 1 elemento, então não divide mais
		return;
	}

	divide(vet, i, (i+f)/2, ord); //inicio+fim /2 pega o fim do vetor da esquerda
	divide(vet, (i+f)/2 + 1, f, ord); //inicio+fim/2 +1 pega o primeiro elemento do vetor da direita

	conquer(i, f, (i+f)/2, vet, ord);
}

int main() {
	int i = 0;
	int vet[] = {8, 6, 4, 12, 54, 3, 1, 9};
	int *ord = malloc(sizeof(int) * 8);

	divide(vet, 0, 7, ord);

	for(i = 0; i < 8; i++) {
		printf("%d\n", vet[i]);
	}

	free(ord);
	return 0;
}