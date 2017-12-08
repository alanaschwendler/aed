//Alana Schwendler

#include <stdio.h>
#include <stdlib.h>

void quick(int f, int l, int vet[]);

int main() {
	//int *vet = malloc(sizeof(int));
	//int n = 0, num = 1;

	int vet[] = {8, 2, 4, 1, 5, 9, 12, 3};

	quick(0, 7, vet);

	return 0;
}

void quick(int f, int l, int vet[]) {
	int wall = f;
	int current = f;
	int pivot = (f+l)/2;
	int aux;

	if(l <= f) { //se não tiver subvetor, não faz nada
		return;
	}

	for(current = f; current <= l; current++) { //percorre o vetor/subvetor do inicio ao fim
		if(current != pivot) {				   //verifica se o atual é o pivô pra não testar com ele mesmo
			if(vet[current] < vet[pivot]) {	   //verifica se precisa fazer a troca
				aux = vet[wall];			   //começa o swap dos dados
				vet[wall] = vet[current];	  
				vet[current] = aux;

				if(wall == pivot) {
			 		pivot = current;
			 	}
				wall++;		
			} 
		}
	}	
	//arruma o pivô
	aux = vet[pivot];
	vet[pivot] = vet[wall];
	vet[wall] = aux;
	pivot = wall;
	//recursão pros subvetores
	quick(f, wall - 1, vet);
	quick(wall + 1, l, vet);
}