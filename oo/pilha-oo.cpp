#include <stdio.h>
#include <stdlib.h>

class No{
	private:
		int chave;
		No *proximo;
		
	public:
		No();
		void setChave(int _chave);
		int getChave();
		void setProximo(No *_proximo);
		No *getProximo();
};

class Pilha{
	private:
		No *topo;
		int tamanho;
	
	public:
		Pilha();
		void setTopo(No *_topo);
		No *getTopo();
		void setTamanho(int _tamanho);
		int getTamanho();
		No *criarNo(int ch);
		void push(int novaChave);
		void pop();
		No *getNo(int buscarChave);
		void exibir();
		~Pilha();
};

//Métodos Nó
No::No(){
	
}
void No::setChave(int _chave){
	chave = _chave;
}
int No::getChave(){
	return chave;
}
void No::setProximo(No *_proximo){
	proximo = _proximo;
}
No *No::getProximo(){
	return proximo;
}

//Métodos Pilha
Pilha::Pilha(){
	topo = NULL;
	tamanho = 0;
}
void Pilha::setTopo(No *_topo){
	topo = _topo;
}
No *Pilha::getTopo(){
	return topo;
}
void Pilha::setTamanho(int _tamanho){
	tamanho = _tamanho;
}
int Pilha::getTamanho(){
	return tamanho;
}
No *Pilha::criarNo(int ch){
	No *novoNo = (No*)malloc(sizeof(No));
	novoNo->setChave(ch);
	novoNo->setProximo(NULL);
	return novoNo;
}
void Pilha::push(int novaChave){
	No *novoNo = criarNo(novaChave);
	novoNo->setProximo(getTopo());
	setTopo(novoNo);
	setTamanho(tamanho+1);
}
void Pilha::pop(){
	No *remover = getTopo();
	setTopo(remover->getProximo());
	free(remover);
	setTamanho(tamanho-1);
}
No *Pilha::getNo(int buscarChave){
	No *aux = getTopo();
	while(aux != NULL){
		if(aux->getChave() == buscarChave)
			return aux;
			
		aux = aux->getProximo();
	}
	return NULL;
}
void Pilha::exibir(){
	No *aux = getTopo();
	while(aux != NULL){
		printf("%d ", aux->getChave());
		aux = aux->getProximo();
	}
}
Pilha::~Pilha(){
	No *aux = getTopo();
	while(aux != NULL){
		No *apagar = aux;
		aux = aux->getProximo();
		free(apagar);
	}
}

int main(){
	Pilha pilha = Pilha();
	
	pilha.push(10);
	pilha.push(20);
	pilha.push(30);
	pilha.push(40);
	pilha.push(50);
	pilha.exibir();
	printf("\nTamanho: %d", pilha.getTamanho());
	
	pilha.pop();
	printf("\n");
	pilha.exibir();
	printf("\nTamanho: %d", pilha.getTamanho());
	
	No *buscar = pilha.getNo(20);
	if(buscar != NULL)
		printf("\nEncontrado: %d", buscar->getChave());
	else
		printf("\nNão encontrado!");
	
	pilha.~Pilha();
	
	return 0;
}
