#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int chave;
	struct no *esq, *dir;
} No;

No *iniciarNoVazio(){
	return NULL;
}

No *criarNo(int ch, No *e, No *d){
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
				raiz = iniciarNoVazio();
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

No *limpar(No *raiz){
	if(raiz !=NULL){
		raiz->esq = limpar(raiz->esq);
		raiz->dir = limpar(raiz->dir);
		free(raiz);
	}
	return iniciarNoVazio();
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
	No *no = criarNo(8, iniciarNoVazio(), iniciarNoVazio());
	
	no = inserir(no, criarNo(4, iniciarNoVazio(), iniciarNoVazio()));
	no = inserir(no, criarNo(12, iniciarNoVazio(), iniciarNoVazio()));
	no = inserir(no, criarNo(6, iniciarNoVazio(), iniciarNoVazio()));
	no = inserir(no, criarNo(9, iniciarNoVazio(), iniciarNoVazio()));
	no = inserir(no, criarNo(20, iniciarNoVazio(), iniciarNoVazio()));
	no = inserir(no, criarNo(11, iniciarNoVazio(), iniciarNoVazio()));
	no = inserir(no, criarNo(3, iniciarNoVazio(), iniciarNoVazio()));
	
	printf("\nPré-Ordem: ");
	preOrdem(no);
	printf("\nIn-Ordem: ");
	inOrdem(no);
	printf("\nPós-Ordem: ");
	posOrdem(no);
	
	printf("\nBusca: %d\n", buscar(no, 9)->chave);
	
	no = remover(no, 8);
	printf("\nPré-Ordem: ");
	preOrdem(no);
	
	no = limpar(no);

	return 0;
}
