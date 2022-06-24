#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int chave;
	struct no *proximo;
} No;

typedef struct{
	No *topo;
	int tamanho;
} Pilha;

Pilha *criarPilha(){
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	p->topo = NULL;
	p->tamanho = 0;
}

No *criarNo(int ch){
	No *n = (No*)malloc(sizeof(No));
	n->chave = ch;
	n->proximo = NULL;
}

void push(Pilha *p, int ch){
	No *novo = criarNo(ch);
	novo->proximo = p->topo;
	p->topo = novo;
	p->tamanho++;
}

void pop(Pilha *p){
	No *aux = p->topo;
	p->topo = p->topo->proximo;
	free(aux);
	p->tamanho--;
}

void limpar(Pilha *p){
	No *apagar;
	No *topo = p->topo;
	while(topo != NULL){
		apagar = topo;
		topo = topo->proximo;
		p->tamanho--;
		free(apagar);
	}
	p->topo = NULL;
}

void exibirPilha(Pilha *p){
	No *i = p->topo;
	printf("Tamanho da pilha: %d\n", p->tamanho);
	while(i != NULL){
		printf("%d ", i->chave);
		i = i->proximo;
	}
	printf("\n\n");
}

int main(){
	Pilha *pilha = criarPilha();
	
	push(pilha, 201);
	push(pilha, 202);
	push(pilha, 203);
	push(pilha, 204);
	
	exibirPilha(pilha);
	
	pop(pilha);
	exibirPilha(pilha);
	
	limpar(pilha);	
	
	return 0;
}
