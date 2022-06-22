#include <stdio.h>
#include <stdlib.h>

void exibir(int *v, int t){
	printf("\n");
	int i;
	for(i = 0; i < t; i++){
		printf(" %d ", v[i]);
	}
}

void preencher(int *v, int t){
	int i;
	for(i=0; i<t; i++){
		v[i] = rand() % 1000;
	}
}

void insertionsort(int *v, int t){
	int i, j, aux;
	for(i=1; i<t; i++){
		aux = v[i];
		j = i-1;
		while(j>=0 && aux<v[j]){
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = aux;
	}
}

int main(){
	int tamanho, *vetor;
	
	printf("Digite a quantidade de elementos: ");
	scanf("%d", &tamanho);
	
	vetor = (int*)calloc(tamanho, sizeof(int));
	
	preencher(vetor, tamanho);
	
	insertionsort(vetor, tamanho);
	//exibir(vetor, tamanho);
	
	free(vetor);
	
	return 0;
}
