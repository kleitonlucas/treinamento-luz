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

void selectionsort(int *v, int t) { 
	int i, j, min, aux;
	for(i=0; i<t-1; i++){
    	min = i;
    	for(j=i+1; j<t; j++) {
			if(v[j] < v[min])
				min = j;
		}
		if(i != min) {
			aux = v[i];
			v[i] = v[min];
			v[min] = aux;
		}
	}
}

int main(){
	int tamanho, *vetor;
	
	printf("Digite a quantidade de elementos: ");
	scanf("%d", &tamanho);
	
	vetor = (int*)calloc(tamanho, sizeof(int));
	
	preencher(vetor, tamanho);
	
	selectionsort(vetor, tamanho);
	//exibir(vetor, tamanho);
	
	free(vetor);
	
	return 0;
}
