//Alana Schwendler - M2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct p {
	char nome[20];
	int idade;
} Pessoa;

void inserir(Pessoa *p);
void imprimir(Pessoa *p);

int main() {
	void *pBuffer;	//buffer
	pBuffer = NULL;

	int *qt;		//quantidade de contatos no buffer
	int *opcao;		//opção desejada
	int *x;			//controle de laços
	Pessoa *inicio; //primeira pessoa no buffer
	Pessoa *atual;	//pessoa em questão 

	if(pBuffer == NULL) {
		pBuffer = malloc(sizeof(int) *3);	//aloca espaço pra uma pessoa e dois inteiros
	} else {
		printf("**Erro: Memória insuficiente**\n");
		return 1; //se não conseguir alocar memória, encerra o programa
	}

	qt = (int *)pBuffer; 	//qt aponta pro inicio do buffer
	*qt = 0; 				//quantidade é zero porque não tem ninguém na agenda
	opcao = qt + 1;	//opção aponta pra posição depois da quantidade
	x = opcao + 1; //x aponta pra posição depois da opção

	printf("1 - Inserir \n2 - Listar \n3 - Remover \n0 - Sair \n");
	
	do {
		printf("Opcao: ");
		scanf("%d", opcao);	//le a opção

		if(*opcao == 1) {
			*qt = *qt + 1;	//incrementa a quantidade
			pBuffer = realloc(pBuffer, (sizeof(int) * 3) + sizeof(Pessoa) * (*qt));	//realoca espaço pro buffer com a nova quantidade
			qt = (int *)pBuffer; 	//reajusta o ponteiro da quantidade
			opcao = qt + 1;	//reajusta o ponteiro da opção
			x = opcao + 1; //reajusta o ponteiro do x
			*x = 0;
			inicio = (Pessoa *)x + 1;	//reajusta o ponteiro da pessoa inicial

			if(*qt == 1) {
				inserir(inicio);	//chama a função pra inserir pessoa no buffer passando a inicial, se for o caso
			} else if (*qt > 1) {
				atual = (Pessoa *)inicio + (sizeof(Pessoa) * (*qt)); 	//reajusta o ponteiro da pessoa atual
				inserir(atual);		//caso não seja a primeira pessoa a ser inserida, chama a função passando a pessoa atual
			}
		}

		if(*opcao == 2) {
			atual = inicio;
			
			if(*qt == 0) {
				printf("**Aviso: Não existem registros**\n");
			} else {
				for(*x = 0; *x < *qt; (*x)++) {
					imprimir(atual);
					atual = (Pessoa *)atual + 1; //vai andando uma pessoa por vez e imprimindo
				}
			}
		}

	} while(*opcao != 0);

	free(pBuffer);	//libera o espaço de memória utilizado pelo buffer
	return 0;
}

void inserir(Pessoa *p) {
	printf("Nome: ");
	scanf("%s", (*p).nome);
	printf("Idade: ");
	scanf("%d", &(*p).idade);
}

void imprimir(Pessoa *p) {
	printf("Nome: %s\n", (*p).nome);
	printf("Idade: %d\n", (*p).idade);
	printf("----------\n");
}
