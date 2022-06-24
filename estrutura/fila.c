#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int chave;
	struct no *proximo;
} No;

typedef struct{
	No *inicio;
	No *fim;
	int tamanho;
} Fila;

Fila *criarFila(){
	Fila *f = (Fila*)malloc(sizeof(Fila));
	f->inicio = NULL;
	f->fim = NULL;
	f->tamanho = 0;
}

No *criarNo(ch){
	No *n = (No*)malloc(sizeof(No));
	n->chave = ch;
	n->proximo = NULL;
}

void inserirNo(Fila *f, int ch){
	No *novo = criarNo(ch);
	if(f->inicio==NULL)
		f->inicio = novo;
	else
		f->fim->proximo = novo;
		
	f->fim = novo;
	f->tamanho++;
}

void removerNo(Fila *f){
	No *aux = f->inicio;
	f->inicio = f->inicio->proximo;
	free(aux);
	f->tamanho--;
	if(f->inicio == NULL)
		f->fim = NULL;
}

void limpar(Fila *f){
	No *aux = f->inicio;
	while(aux != NULL){
		No *apagar = aux;
		aux = aux->proximo;
		f->tamanho--;
		free(apagar);
	}
	f->inicio = NULL;
	f->fim = NULL;
}

No *buscar(Fila *f, int ch){
	No *n = f->inicio;
	
	while(n != NULL){
		if(n->chave == ch) return n;
		n = n->proximo;
	}
	
	return NULL;
}

void exibirFila(Fila *f){
	No *i = f->inicio;
	printf("Tamanho da fila: %d\n", f->tamanho);
	while(i != NULL){
		printf("%d ", i->chave);
		i = i->proximo;
	}
	printf("\n\n");
}

int main(){
	Fila *fila = criarFila();
	
	inserirNo(fila, 101);
	inserirNo(fila, 102);
	inserirNo(fila, 103);
	inserirNo(fila, 104);
	
	exibirFila(fila);
	
	removerNo(fila);
	
	exibirFila(fila);
	
	printf("%d", buscar(fila, 103)->chave);
	
	limpar(fila);
	
	return 0;
}
