#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int quick(int array[], int menor, int tamanho){
	int aux;
	int pivo = array[tamanho];
	int menos  = menor - 1;

	for(int i = menor; i <= tamanho - 1;i++){
		if(array[i] < pivo){
			menos++;
			aux = array[menos];
			array[menos] = array[i];
			array[i] = aux;
		}
	}
	aux = array[menos + 1];
	array[menos + 1] = array[tamanho];
	array[tamanho] = aux;
	return (menos + 1);
}
int quicksort(int array[],int menor, int tamanho){

	if(menor < tamanho){
		
		int qui = quick(array, menor, tamanho);

		quicksort(array, menor, qui -1);
		quicksort(array, qui + 1, tamanho);
	}
}

int main(int argc, char *argv[]){

	clock_t Ticks[2];
        Ticks[0] = clock();
        int i, j;
        FILE *ptr;
        ptr = fopen(argv[1],"r");
        int cont = 0;
        int test = 0;
        while (!feof(ptr)) {
                fscanf(ptr,"%d",&test);
                cont++;
        }
        rewind(ptr);
        int parray[cont];
        cont = 0;
                while (!feof(ptr)) {
                fscanf(ptr,"%d",&parray[cont]);
                cont++;
        } 
	int tamanho = sizeof(parray)/sizeof(int);

	quicksort(parray, 0, tamanho-1);
	for(int j = 0; j < tamanho; j++){
		printf("%d ",parray[j]);
	}
    Ticks[1] = clock();
   	double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %g ms.", Tempo);
    return 0;
}
