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

void bubblesort(int *v, int t){
	int i, j, aux;
	for(i=0; i<t; i++){
		for(j = 0; j < t-1; j++){
	        if(v[j]>v[j+1]){
	        	aux = v[j];
	        	v[j] = v[j+1];
	        	v[j+1] = aux;
			}
		}
	}
}

int main(){
	int tamanho, *vetor;
	
	printf("Digite a quantidade de elementos: ");
	scanf("%d", &tamanho);
	
	vetor = (int*)calloc(tamanho, sizeof(int));
	
	preencher(vetor, tamanho);
	
	bubblesort(vetor, tamanho);
	//exibir(vetor, tamanho);
	
	free(vetor);
	
	return 0;
}
