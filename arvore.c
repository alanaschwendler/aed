#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct n {
	int num;
	int altura;
	struct n *esq;
	struct n *dir;
	struct n *pai;
} No;

No* inicializar();
int maior(int x, int y);
int altura(No* n);
int balanceamento(No* n);
void rotacaoEE(No *a);
void rotacaoDD(No *a);
void rotacaoED(No *a);
void rotacaoDE(No *a);
void inserir(No *raiz, int valor);
void imprimir(No *n);

int main() {
	No *n;
	n = inicializar(); //inicializa o nó

	int val;
	int op;

	printf("1 - Inserir \n2 - Imprimir \n0 - Sair \n");

	do {
		printf("Opção: ");
		scanf("%d", &op);

		switch(op) {
			case 1:
				printf("-----INSERIR-----\n");
				printf("Numero: ");
				scanf("%d", &val);

				inserir(n, val);
				break;
			case 2:
				printf("-----IMPRIMIR AINDA NÃO ESTÁ PRONTA-----\n");

					imprimir(n);
				break;	
			default:
				printf("Programa encerrado. \n");
				break;
		}
	} while(op != 0);
	free(n);
	return 0;
}

No* inicializar() { //vai inicializar a árvore
	No* raiz;
	raiz = (No*)malloc(sizeof(No));

	if(raiz != NULL){
		*raiz = NULL;
	}
}

int maior(int x, int y) { //verifica qual nó tem maior altura
    if(x > y) {
        return x;
    } else {
        return y;
    }
}

int altura(No* n) {
    if(n == NULL) {	//se o nó é nulo, retorna -1
        return -1;
    } else {
    	return n->altura; //senão, pega a altura do nó
    }
}

int balanceamento(No* n) {
    return altura(n->esq) - altura(n->dir); //vai ver a diferença entre os nós
}

void rotacaoEE(No *a) {	//Esquerda Esquerda
    printf("Rotacao Esq Esq\n");
    No *b;
    b = (*a)->esq;
    (*a)->esq = b->dir;
    b->dir = *a;
    (*a)->altura = maior(altura((*a)->esq), altura((*a)->dir)) + 1;
    b->altura = maior(altura(b->esq), (*a)->altura) + 1;
    *a = b;
}

void rotacaoDD(No *a) {	//Direita Direita
    printf("Rotacao Dir Dir\n");
    No *b;
    b = (*a)->dir;
    (*a)->dir = b->esq;
    b->esq = (*a);
    (*a)->altura = maior(altura((*a)->esq),altura((*a)->dir)) + 1;
    b->altura = maior(altura(b->dir),(*a)->altura) + 1;
    (*a) = b;
}


void rotacaoED(No *a) {	//Esquerda Direita
    rotacaoDD(&(*a)->esq);
    rotacaoEE(a);
}

void rotacaoDE(No *a){	//Direita Esquerda
    rotacaoEE(&(*a)->dir);
    rotacaoDD(a);
}

void inserir(No *raiz, int valor) {
	No *novo;
	int retorno;

	if(*raiz == NULL) {
		novo = malloc(sizeof(No));

		if(novo == NULL) {
			return 0;
		}

		novo->num = valor;
		novo->pai = NULL;
		novo->esq = NULL;
		novo->dir = NULL;
		novo->altura = 0;
		*raiz = novo;
	}

	No *atual = *raiz;
	if(valor < n->num){
        if((retorno = inserir(&(atual->esq), valor)) == 1){
            if(balanceamento(atual) >= 2){
                if(valor < (*raiz)->esq->num ){
                    rotacaoEE(raiz);
                }else{
                    rotacaoED(raiz);
                }
            }
        }
    } else {
        if(valor > atual->info){
            if((retorno = inserir(&(atual->dir), valor)) == 1) {
                if(balanceamento(atual) >= 2) {
                    if((*raiz)->dir->num < valor) {
                        rotacaoDD(raiz);
                    }else{
                        rotacaoDE(raiz);
                    }
                }
            }
        } else {
            printf("Registro já existe na árvore.\n");
            return 0;
        }
    }
}

void imprimir(No *n) {
	//SÓ PRA VER SE TÁ INSERINDO NOVO OU SOBRESCREVENDO
	//TENTAR INSERIR DOIS REGISTROS MAIORES OU DOIS MENORES QUE A RAIZ
	printf("\t %d \n", n->num);
	printf("%d            %d\n", n->esq->num, n->dir->num);
}

