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

class Lista{
	private:
		No *inicio;
		int tamanho;
	
	public:
		Lista();
		void setInicio(No *_inicio);
		No *getInicio();
		void setTamanho(int _tamanho);
		int getTamanho();
		No *criarNo(int ch);
		void inserir(int novaChave);
		void remover(int removerChave);
		No *getNo(int buscarChave);
		void exibir();
		~Lista();
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
//Métodos Lista
Lista::Lista(){
	inicio = NULL;
	tamanho = 0;
}
void Lista::setInicio(No *_inicio){
	inicio = _inicio;
}
No *Lista::getInicio(){
	return inicio;
}
void Lista::setTamanho(int _tamanho){
	tamanho = _tamanho;
}
int Lista::getTamanho(){
	return tamanho;
}
No *Lista::criarNo(int ch){
	No *novo = (No*)malloc(sizeof(No));
	novo->setChave(ch);
	novo->setProximo(NULL);
	return novo;
}
void Lista::inserir(int novaChave){
	No *novo = criarNo(novaChave);
	novo->setProximo(getInicio());
	setInicio(novo);
	setTamanho(getTamanho()+1);
}
void Lista::remover(int removerChave){
	No *aux = getInicio();
	if(getInicio()->getChave() == removerChave){
		setInicio(getInicio()->getProximo());
		setTamanho(getTamanho()-1);
		free(aux);
	}
	else{
		while(aux->getProximo() != NULL){
			if(aux->getProximo()->getChave() == removerChave){
				No *remover = aux->getProximo();
				aux->setProximo(remover->getProximo());
				setTamanho(getTamanho()-1);
				free(remover);
			}
			aux = aux->getProximo();
		}
	}
}
No *Lista::getNo(int buscarChave){
	No *aux = getInicio();
	while(aux != NULL){
		if(aux->getChave() == buscarChave){
			return aux;
		}
		aux = aux->getProximo();
	}
	return NULL;
}
void Lista::exibir(){
	No *aux = getInicio();
	while(aux != NULL){
		printf("%d ", aux->getChave());
		aux = aux->getProximo();
	}
}
Lista::~Lista(){
	No *aux = getInicio();
	while(aux != NULL){
		No *apagar = aux;
		aux = aux->getProximo();
		setTamanho(getTamanho()-1);
		free(apagar);
	}
}

int main(){
	Lista lista = Lista();
	
	lista.inserir(5);
	lista.inserir(10);
	lista.inserir(15);
	lista.inserir(20);
	lista.inserir(25);
	printf("Tamanho: %d\n", lista.getTamanho());
	lista.exibir();
	
	No *r = lista.getNo(20);
	if(r != NULL)
		printf("\n** Busca: %d\n", r->getChave());
	else
		printf("\nElemento não encontrado!\n");
	
	printf("Removendo...\n");
	lista.remover(20);
	printf("Tamanho: %d\n", lista.getTamanho());
	lista.exibir();
	
	lista.~Lista();
	return 0;
}
