#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int chave;
	struct no *proximo;
} No;

typedef struct{
	No *inicio;
	int tam;
} Lista;

Lista *criarLista(){
	Lista *l = (Lista*)malloc(sizeof(Lista));
	l->inicio = NULL;
	l->tam = 0;
}

No *criarNo(int ch){
	No *n = (No*)malloc(sizeof(No));
	n->chave = ch;
	n->proximo = NULL;
}

void inserirNo(Lista *l, int ch){
	No * novo = criarNo(ch);
	novo->proximo = l->inicio;
	l->inicio = novo;
	l->tam++;
}

void removerNo(Lista *l, int ch){ 
	No *aux = l->inicio;
	if(l->inicio->chave == ch){
		l->inicio = l->inicio->proximo;
		l->tam--;
		free(aux);
	} else{
		while(aux->proximo != NULL){
			No *apagar;
			if(aux->proximo->chave == ch){
				apagar = aux->proximo;
				aux->proximo = aux->proximo->proximo;
				l->tam--;
				free(apagar);
				break;
			}
			aux = aux->proximo;
		}
	}
}

void limpar(Lista *l){
	No *aux = l->inicio;
	while(aux != NULL){
		No *apagar = aux;
		aux = aux->proximo;
		l->tam--;
		free(apagar);
	}
	l->inicio = NULL;
}

No *buscar(Lista *l, int ch){
	No *n = l->inicio;
	
	while(n != NULL){
		if(n->chave == ch) return n;
		n = n->proximo;
	}
	
	return NULL;
}

void exibirLista(Lista *l){
	No *i = l->inicio;
	printf("Tamanho da lista: %d\n", l->tam);
	while(i != NULL){
		printf("%d ", i->chave);
		i = i->proximo;
	}
	printf("\n\n");
}

int main(){
	Lista *lista = criarLista();
	
	inserirNo(lista, 1001);
	inserirNo(lista, 1002);
	inserirNo(lista, 1003);
	inserirNo(lista, 1004);
	
	exibirLista(lista);
	
	removerNo(lista, 1002);
	exibirLista(lista);
	
	printf("%d", buscar(lista, 1003)->chave);
	
	limpar(lista);
		
	return 0;
}
