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
	Pessoa *pInicio;
	Pessoa *pAtual;
 
	pBuffer = malloc(sizeof(int)); //aloca tamanho de um inteiro pra colocar a quantidade
	qt = pBuffer; //quantidade de pessoas inseridas
	*qt = 0; //seta como 0

	pBuffer = realloc(pBuffer, (sizeof(int)*2)); //realoca espaço pra adicionar a opção
	opcao = (qt + sizeof(int)); //opção aponta pra qt + 4
	qt = pBuffer; //reajusta o ponteiro de qt

	pBuffer = realloc(pBuffer, (sizeof(Pessoa))); //realoca espaço pra adicionar uma pessoa
	qt = pBuffer; //reajusta o ponteiro de qt
	pInicio = (Pessoa *) (opcao + sizeof(int));
	pAtual = pInicio; 

	printf("1 - Inserir\n");
	scanf("%d", opcao); //le qual oção o usuario vai querer

	if(*opcao == 1) {
		*qt = *qt + 1; //se a opção foi de inserir, adiciona mais um na quantidade
		scanf("%s", (*pAtual).nome);
		printf("\n");
		scanf("%d", &(*pAtual).idade);
	}

	printf("Nome: %s\n", pAtual->nome);
	printf("Idade: %d\n", pAtual->idade);

	free(pBuffer);

	return 0;
}