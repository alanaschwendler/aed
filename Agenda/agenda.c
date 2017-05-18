#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Faça uma agenda capaz de incluir, apagar, buscar
e listar quantas pessoas o usuário desejar, porém,
você não pode usar variáveis a não ser ponteiros.
Toda a informação deve ser guardada num “void
*pBuffer”.

pBuffer deve guardar desde as pessoas colocadas
na agenda até as variáveis locais que você precisa
para controlar um for, por exemplo.
*/

typedef struct Pessoa { 
	char nome[20];
	int idade;
} Pessoa;

int main() {
	void *pBuffer;
	int *qt;
	int *opcao;
	int *x; //controle do for 
	Pessoa *pInicio;
	Pessoa *pAtual;
 
	pBuffer = malloc(sizeof(int)); //aloca tamanho de um inteiro pra colocar a quantidade
	qt = pBuffer; //quantidade de pessoas inseridas
	*qt = 0; //seta como 0

	pBuffer = realloc(pBuffer, (sizeof(int)*2)); //realoca espaço pra adicionar a opção
	opcao = (qt + sizeof(int)); //opção aponta pra qt + 4
	qt = pBuffer; //reajusta o ponteiro de qt

	pBuffer = realloc(pBuffer, (sizeof(int)*3));
	qt = pBuffer;
	x = (opcao + sizeof(int));

	pBuffer = realloc(pBuffer, (sizeof(Pessoa))); //realoca espaço pra adicionar uma pessoa
	qt = pBuffer; //reajusta o ponteiro de qt
	pInicio = (Pessoa *) (x + sizeof(int));
	pAtual = pInicio; 

	printf("1 - Inserir\n");
	printf("2 - Listar Pessoas\n");
	printf("0 - Sair\n");
	
	do {
		printf("Opção: ");
		scanf("%d", opcao); //le qual oção o usuario vai querer
		if(*opcao == 1) {
			*qt = *qt + 1; //se a opção foi de inserir, adiciona mais um na quantidade
			scanf("Insira o nome: %s", (*pAtual).nome);
			printf("\n");
			scanf("Insira a idade: %d", &(*pAtual).idade);
		} else if(*opcao == 2) {
			for(*x = 0; *x < *qt; (*x)++) {
				printf("Nome: %s\n", pAtual->nome);
				printf("Idade: %d\n", pAtual->idade);
				printf("------\n");
			}
		}
	} while(*opcao != 0);

	free(pBuffer);

	return 0;
}