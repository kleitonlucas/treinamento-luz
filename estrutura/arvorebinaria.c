#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int chave;
	struct no *esq, *dir;
} No;

No *iniciarArvVazia(){
	return NULL;
}

No *criarArvore(int ch, No *e, No *d){
	No *novo = (No*)malloc(sizeof(No));
	novo->chave = ch;
	novo->esq = e;
	novo->dir = d;
	
	return novo;
}

No *inserir(No *raiz, No *novo){
	if(raiz == NULL)
		return novo;
	else if(raiz->chave > novo->chave)
		raiz->esq = inserir(raiz->esq, novo);
	else
		raiz->dir = inserir(raiz->dir, novo);
		
	return raiz;
}

No *remover(No *raiz, int ch){
	if(raiz == NULL)
		return NULL;
	else{
		if(raiz->chave > ch)
			raiz->esq = remover(raiz->esq, ch);
		else if(raiz->chave < ch)
			raiz->dir = remover(raiz->dir, ch);
		else{
			if(raiz->esq == NULL && raiz->dir == NULL){
				free(raiz);
				raiz = iniciarArvVazia();
			}
			else if(raiz->dir == NULL){
				No *aux = raiz;
				raiz = raiz->esq;
				free(aux);
			}
			else if(raiz->esq == NULL){
				No *aux = raiz;
				raiz = raiz->dir;
				free(aux);
			}
			else{
				No *aux = raiz->esq;
				while(aux->dir != NULL)
					aux = aux->dir;
				
				raiz->chave = aux->chave;
				aux->chave = ch;
				raiz->esq = remover(raiz->esq, ch);
			}
		}
	}
}

No *limparArvore(No *raiz){
	if(raiz !=NULL){
		raiz->esq = limparArvore(raiz->esq);
		raiz->dir = limparArvore(raiz->dir);
		free(raiz);
	}
	return iniciarArvVazia();
}

No *buscar(No *raiz, int ch){
	if(raiz == NULL)
		return NULL;
	else if(raiz->chave > ch)
		return buscar(raiz->esq, ch);
	else if(raiz->chave < ch)
		return buscar(raiz->dir, ch);
	else
		return raiz;
}

void preOrdem(No *raiz){
	if(raiz != NULL){
		printf(" [%d] ", raiz->chave);
		preOrdem(raiz->esq);
		preOrdem(raiz->dir);
	}
}

void inOrdem(No *raiz){
	if(raiz != NULL){
		inOrdem(raiz->esq);
		printf(" [%d] ", raiz->chave);
		inOrdem(raiz->dir);
	}
}

void posOrdem(No *raiz){
	if(raiz != NULL){
		posOrdem(raiz->esq);
		posOrdem(raiz->dir);
		printf(" [%d] ", raiz->chave);
	}
}

int main(){
	No *arvore = criarArvore(8, iniciarArvVazia(), iniciarArvVazia());
	
	arvore = inserir(arvore, criarArvore(4, iniciarArvVazia(), iniciarArvVazia()));
	arvore = inserir(arvore, criarArvore(12, iniciarArvVazia(), iniciarArvVazia()));
	arvore = inserir(arvore, criarArvore(6, iniciarArvVazia(), iniciarArvVazia()));
	arvore = inserir(arvore, criarArvore(9, iniciarArvVazia(), iniciarArvVazia()));
	arvore = inserir(arvore, criarArvore(20, iniciarArvVazia(), iniciarArvVazia()));
	arvore = inserir(arvore, criarArvore(11, iniciarArvVazia(), iniciarArvVazia()));
	arvore = inserir(arvore, criarArvore(3, iniciarArvVazia(), iniciarArvVazia()));
	
	printf("\nPré-Ordem: ");
	preOrdem(arvore);
	printf("\nIn-Ordem: ");
	inOrdem(arvore);
	printf("\nPós-Ordem: ");
	posOrdem(arvore);
	
	printf("\nBusca: %d\n", buscar(arvore, 9)->chave);
	
	arvore = remover(arvore, 8);
	printf("\nPré-Ordem: ");
	preOrdem(arvore);
	
	arvore = limparArvore(arvore);

	return 0;
}
