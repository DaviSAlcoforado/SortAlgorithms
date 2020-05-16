#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heaps(int parray[], int in, int fim){
	int j = in * 2 + 1;
	int aux = parray[in];

	while(j <= fim){
	
		if(j < fim){
			if(parray[j] < parray[j + 1]){
				j++;
			}
		}
	
		if(aux < parray[j]){
			parray[in] = parray[j];
			in = j;
			j = 2 * in + 1;
		}
	
		else{
			j = fim + 1;
		}
	}
	parray[in] = aux;
}
void *heapsort(int parray[], int n){
	int aux, i;
	for(i = (n/2);i> -1; i--){
		heaps(parray, i, n-1);
		}
	for(i = n-1; i > -1; i--){
		
		aux= parray[i];
		parray[i] = parray[0];
		parray[0] = aux;
		heaps(parray, 0,i -1);

		}
	return parray;
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
	int n=  sizeof(parray)/sizeof(int);
	 heapsort(parray, n);
		for(int i = 0; i<n;i++){
			printf("%d ",parray[i]);
	}
	Ticks[1] = clock();
	double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
	printf("\nTempo gasto: %g ms.", Tempo);
	return 0;
}
