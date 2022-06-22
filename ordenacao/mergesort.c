#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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

void merge(int *v, int inicio, int meio, int fim){
	int i, j, k;
	int t_esq = meio-inicio+1;
	int t_dir = fim-meio;
	int *esq = (int*)malloc(t_esq*sizeof(int));
	int *dir = (int*)malloc(t_dir*sizeof(int));
	
	for(i=0; i<t_esq; i++)
		esq[i] = v[i+inicio];
		
	for(i=0; i<t_dir; i++)
		dir[i] = v[i+meio+1];
		
	for(i=0, j=0, k=inicio; k<=fim; k++){
		if(i == t_esq)
			v[k] = dir[j++];
		else if(j == t_dir)
			v[k] = esq[i++];
		else if(esq[i] < dir[j])
			v[k] = esq[i++];
		else
			v[k] = dir[j++];
	}
	free(esq);
	free(dir);
}

void mergeSort(int *v, int inicio, int fim){
	if(inicio==fim)
		return;
	
	int meio = floor((fim + inicio) / 2);
	mergeSort(v, inicio, meio);
	mergeSort(v, meio+1, fim);
	merge(v, inicio, meio, fim);
}

int main(){
	int tamanho, *vetor;
	
	printf("Digite a quantidade de elementos: ");
	scanf("%d", &tamanho);
	
	vetor = (int*)calloc(tamanho, sizeof(int));
	
	preencher(vetor, tamanho);
	
	mergeSort(vetor, 0, tamanho-1);
	//exibir(vetor, tamanho);
	
	free(vetor);
	
	return 0;
}
