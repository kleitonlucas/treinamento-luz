#include <stdio.h>
#include <stdlib.h>

class No{
	private:
		int chave;
		No *proximo;
	
	public:
		No(int _chave);
		~No();
		void setChave(int _chave);
		int getChave();
		void setProximo(No *_proximo);
		No *getProximo();
};

class Lista{
	private:
		No *inicio;
		No *fim;
		int tamanho;
	
	public:
		Lista();
		~Lista();
		void setInicio(No *_inicio);
		No *getInicio();
		void setFim(No *_fim);
		No *getFim();
		void setTamanho(int _tamanho);
		int getTamanho();
		void inserirNoInicio(int novaChave);
		void inserirNoFim(int novaChave);
		void remover(int _removerChave);
		No *getNo(int _buscarChave);
		void exibir();
};

class Fila{
	private:
		Lista *lista;
		
	public:
		Fila();
		~Fila();
		void inserir(int _novaChave);
		void remover();
		No *buscar(int _ch);
		void exibir();
};

class Pilha{
	private:
		Lista *lista;
		
	public:
		Pilha();
		~Pilha();
		void push(int _novaChave);
		void pop();
		No *buscar(int _ch);
		void exibir();
};

//Métodos do Nó
No::No(int _chave){
	this->chave = _chave;
	this->proximo = NULL;
}
No::~No(){
	
}
void No::setChave(int _chave){
	this->chave = _chave;
}
int No::getChave(){
	return this->chave;
}
void No::setProximo(No *_proximo){
	this->proximo = _proximo;
}
No *No::getProximo(){
	return this->proximo;
}

//Métodos da Lista
Lista::Lista(){
	this->inicio = NULL;
	this->fim = NULL;
	this->tamanho = 0;
}
Lista::~Lista(){
	while(this->getInicio() != NULL){
		No *apagar = this->getInicio();
		this->setInicio(this->getInicio()->getProximo());
		
		if(this->getInicio() == this->getFim()){
			this->setFim(NULL);
		}
		
		delete apagar;
		this->setTamanho(this->getTamanho()-1);
	}
	printf("\n**Lista deletada!**");
}
void Lista::setInicio(No *_inicio){
	this->inicio = _inicio;
}
No *Lista::getInicio(){
	return this->inicio;
}
void Lista::setFim(No *_fim){
	this->fim = _fim;
}
No *Lista::getFim(){
	return this->fim;
}
void Lista::setTamanho(int _tamanho){
	this->tamanho = _tamanho;
}
int Lista::getTamanho(){
	return this->tamanho;
}
void Lista::inserirNoInicio(int _novaChave){
	No *novo = new No(_novaChave);
	if(this->getInicio() == NULL){
		this->setInicio(novo);
		this->setFim(novo);
		this->setTamanho(this->getTamanho()+1);
	}
	else{
		novo->setProximo(this->getInicio());
		this->setInicio(novo);
		this->setTamanho(this->getTamanho()+1);
	}
}
void Lista::inserirNoFim(int _novaChave){
	No *novo = new No(_novaChave);
	if(this->getFim() == NULL){
		this->setFim(novo);
		this->setInicio(novo);
		this->setTamanho(1);
	}
	else{
		No *fim = this->getFim();
		novo->setProximo(NULL);
		fim->setProximo(novo);
		this->setFim(novo);
		this->setTamanho(this->getTamanho()+1);
	}
}
void Lista::remover(int _removerChave){
	No *aux = this->getInicio();
	if(this->getInicio()->getChave() == _removerChave){
		this->setInicio(this->getInicio()->getProximo());
		this->setTamanho(this->getTamanho()-1);
		delete aux;
	}
	else{
		while(aux != NULL){
			if(aux->getProximo()->getChave() == _removerChave){
				No *remover = aux->getProximo();
				aux->setProximo(remover->getProximo());
				this->setFim(aux);
				this->setTamanho(getTamanho()-1);
				delete remover;
			}
			aux = aux->getProximo();
		}
	}
}
No *Lista::getNo(int _buscarChave){
	No *aux = getInicio();
	while(aux != NULL){
		if(aux->getChave() == _buscarChave){
			return aux;
		}
		aux = aux->getProximo();
	}
	return NULL;
}
void Lista::exibir(){
	No *aux = getInicio();
	printf("Tamanho: %d\n", this->getTamanho());
	while(aux != NULL){
		printf("%d ", aux->getChave());
		aux = aux->getProximo();
	}
}

//Métodos da Fila
Fila::Fila(){
	this->lista = new Lista();
}
Fila::~Fila(){
	delete this->lista;
}
void Fila::inserir(int _ch){
	this->lista->inserirNoFim(_ch);
}
void Fila::remover(){
	this->lista->remover(this->lista->getInicio()->getChave());
}
No *Fila::buscar(int _ch){
	return this->lista->getNo(_ch);
}
void Fila::exibir(){
	this->lista->exibir();
}

//Métodos da Pilha
Pilha::Pilha(){
	this->lista = new Lista();
}
Pilha::~Pilha(){
	delete this->lista;
}
void Pilha::push(int _ch){
	this->lista->inserirNoInicio(_ch);
}
void Pilha::pop(){
	this->lista->remover(this->lista->getInicio()->getChave());
}
No *Pilha::buscar(int _ch){
	return this->lista->getNo(_ch);
}
void Pilha::exibir(){
	this->lista->exibir();
}

int main(){
	//Lista
	printf("LISTA\n");
	Lista *lista = new Lista();
	
	lista->inserirNoFim(50);
	lista->inserirNoInicio(10);
	lista->inserirNoInicio(20);
	lista->inserirNoInicio(30);
	lista->inserirNoFim(40);
	lista->exibir();
	
	printf("\n");
	lista->remover(40);
	lista->exibir();
	
	printf("\n");
	No *buscar = lista->getNo(10);
	if(buscar != NULL)
		printf("Elemento encontrado: %d", buscar->getChave());
	else
		printf("Elemento não encontrado!");
		
	delete lista;
	
	//Fila
	printf("\n\nFILA\n");
	Fila *fila = new Fila();
	
	fila->inserir(5);
	fila->inserir(15);
	fila->inserir(25);
	fila->inserir(35);
	fila->exibir();
	
	printf("\n");
	fila->remover();
	fila->exibir();
	
	printf("\n");
	No *bFila = fila->buscar(25);
	if(bFila != NULL)
		printf("Elemento encontrado: %d", bFila->getChave());
	else
		printf("Elemento não encontrado!");
		
	delete fila;
	
	//Pilha
	printf("\n\nPILHA\n");
	Pilha *pilha = new Pilha();
	
	pilha->push(101);
	pilha->push(107);
	pilha->push(115);
	pilha->exibir();
	
	printf("\n");
	pilha->pop();
	pilha->exibir();
	
	printf("\n");
	No *bPilha = pilha->buscar(107);
	if(bPilha != NULL)
		printf("Elemento encontrado: %d", bPilha->getChave());
	else
		printf("Elemento não encontrado!");
		
	delete pilha;
	
	return 0;
}
