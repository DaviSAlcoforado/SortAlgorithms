#include <stdio.h>
#include <stdlib.h>

int heaps(int array[], int i, int n){
	int esq;
	int dir;
	int aux;
	int maior;

	maior = i;
	esq = 2 * i + 1;
	dir = 2 * i + 2;

	if(esq < n && array[i] < array[esq]){
		maior = esq;
	}
	if(dir < n && array[maior] < array[dir]){
		maior = dir;
	}
	if(maior != i){
		aux = array[i];
		array[i] = array[maior];
		array[maior] = aux;
	}
}
int swap(int *array[0],int *array[]){
	int aux;

	aux= *array[0];
	*array[] = *array[0];
	*array[0] = *array[];
}
int heapsort(int*array[], int n){
	for(int i = n/2 - 1;i>= 0; i--){
		heaps(&array, n, i);
	}
	for(int i = n - 1; i >= 0;i--){
		swap(&array[0],&array[i]);
		heaps(&array, i, 0);
	}
}
int Printar(int*array[], int n){
	for(int i = 0; i<n;++i){
		printf("%d ",array[i]);
	}
}
int main(){
	int array[] = {4,5,6,7,8,1,2,3,65,98};
	int n=  sizeof(array)/sizeof(int);
	heapsort(&array, n);
	Printar(&array,n);
}