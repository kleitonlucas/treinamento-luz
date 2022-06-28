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
class Fila{
	private:
		No *inicio;
		No *fim;
		int tamanho;
	
	public:
		Fila();
		void setInicio(No *_inicio);
		No *getInicio();
		void setFim(No *_fim);
		No *getFim();
		void setTamanho(int _tamanho);
		int getTamanho();
		No *criarNo(int ch);
		void inserir(int novaChave);
		void remover();
		void exibir();
		No *getNo(int buscarChave);
		~Fila();
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

//Métodos Fila
Fila::Fila(){
	inicio = NULL;
	fim = NULL;
	tamanho = 0;
}
void Fila::setInicio(No *_inicio){
	inicio = _inicio;
}
No *Fila::getInicio(){
	return inicio;
}
void Fila::setFim(No *_fim){
	fim = _fim;
}
No *Fila::getFim(){
	return fim;
}
void Fila::setTamanho(int _tamanho){
	tamanho = _tamanho;
}
int Fila::getTamanho(){
	return tamanho;
}
No *Fila::criarNo(int ch){
	No *novo = (No*)malloc(sizeof(No));
	novo->setChave(ch);
	novo->setProximo(NULL);
	return novo;
}
void Fila::inserir(int novaChave){
	No *novo = criarNo(novaChave);
	if(getInicio() == NULL){
		setInicio(novo);
		setFim(novo);
		setTamanho(getTamanho()+1);
	} 
	else{
		No *aux = getFim();
		aux->setProximo(novo);
		setFim(novo);
		setTamanho(getTamanho()+1);
	}
}
void Fila::remover(){
	No *aux = getInicio();
	setInicio(aux->getProximo());
	setTamanho(getTamanho()-1);
	if(getInicio() == NULL)
		setFim(NULL);
	free(aux);
}
void Fila::exibir(){
	No *aux = getInicio();
	while(aux != NULL){
		printf("%d ", aux->getChave());
		aux = aux->getProximo();
	}
}
Fila::~Fila(){
	No *aux = getInicio();
	while(aux != NULL){
		No *apagar = aux;
		aux = aux->getProximo();
		setTamanho(getTamanho()-1);
		free(apagar);
	}
	setFim(NULL);
}
	
int main(){
	Fila fila = Fila();
	
	fila.inserir(101);
	fila.inserir(102);
	fila.inserir(103);
	fila.inserir(104);
	printf("Tamanho: %d\n", fila.getTamanho());
	fila.exibir();
	
	printf("\n");
	fila.remover();
	printf("Tamanho: %d\n", fila.getTamanho());
	fila.exibir();
	
	fila.~Fila();
	return 0;
}
