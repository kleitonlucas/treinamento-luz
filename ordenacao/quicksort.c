#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void exibir(int *v, int t){
	printf("\n");
	int i;
	for(i = 0; i < t; i++){
		printf(" %d ", v[i]);
	}
}

void preencher(int *v, int t){
	srand(time(NULL));
	int i;
	for(i=0; i<t; i++){
		v[i] = rand() % 1000;
	}
}

void quickSort(int *v, int inicio, int fim){
	int i, j, pivo, aux;
	i = inicio;
	j = fim;
	pivo = v[(inicio + fim) / 2];
	while(i <= j){
		while(v[i] < pivo && i < fim){
			i++;
		}
		while(v[j] > pivo && j > inicio){
			j--;
		}
		if(i <= j){
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
			i++;
			j--;
		}
	}
	if(j > inicio)
		quickSort(v, inicio, j+1);
	if(i < fim)
		quickSort(v, i, fim);
}

int main(){
	int tamanho, *vetor;
	
	printf("Digite a quantidade de elementos: ");
	scanf("%d", &tamanho);
	
	vetor = (int*)calloc(tamanho, sizeof(int));
	
	preencher(vetor, tamanho);
	//exibir(vetor, tamanho);
	
	quickSort(vetor, 0, tamanho-1);
	exibir(vetor, tamanho);
	
	free(vetor);
	
	return 0;
}
