//Alana Schwendler - M2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * criaVetor();
void copia(int num, char *p, int i);
void imprime(char *p);

int main() {
	int num, i = 0;
	char *p, *aux;

	p = criaVetor(); //p tem o inicio do vetor criado
	aux = p;

	do {	
		printf("Numero positivo: ");
		scanf("%d", &num);
	} while(num < 0);
		
	p = p + 15; 		//aqui o ponteiro vai apontar pro inicio do último elemento do vetor
	copia(num, p, i);	//chama a função que escreve os valores binarios no vetor
	
	p = aux;	//o ponteiro agora aponta pro inicio do vetor
	imprime(p); //chama a função que imprime o vetor

	free(p); //libera a memória 
	return 0;
}

//cria o vetor de ponteiro de char e retorna o endereço de inicio do vetor
char * criaVetor() { 
	char *i;

	i = calloc(16, sizeof(char)); //aloca espaço e salva o inicio do vetor e já deixa tudo zerado com o calloc
	return i; //retorna o inicio do vetor
}

//percorre o vetor, pega o ultimo bit usando mod e escreve no vetor
void copia(int num, char *p, int i) {
	for(i = 0; i < 16; i++) {
		if(num % 2 == 0) {
			*p = '0';
		} else {
			*p = '1';
		}

		num = (num >> 1); //shifta pra direita pra pegar o último bit do numero
		p--; //decrementa o endereço do vetor pra escrever da direita pra esquerda e o valor ficar como bit menos significativo
	}
}

//imprime o vetor 
void imprime(char *p) {
	int i;
	for(i = 0; i < 16; i++) {
		printf("%c", *p);
		p++;
	}
	printf("\n");
}