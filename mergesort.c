#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//I = Início
//F = Fim
//Parray = ponteiro pra array

void merge (int parray[], int i, int meio, int f){
	//variaveis globais
	int a,b,c;
	//tamanho esquerda e direita
	int esq = meio - i + 1;
	int dir = f - meio;
	//arrays auxiliares
	int esqd[esq], dirt[dir];
	
	//para colocar os valores nos arrays auxiliares
	for(a = 0; a < esq; a++){
		esqd[a] = parray[i + a];
	}
	for(b = 0; b < dir; b++){
		dirt[b] = parray[meio + 1 + b];
	}

	a = 0;
	b = 0;
	c = i;

	while (a < esq && b < dir){
		
		if (esqd[a] <= dirt[b]){
			parray[c] = esqd[a];
			a++;
		}
			
		else{
			parray[c] = dirt[b];
			b++;
			}
		c++;
	}

	while (a < esq){
		parray[c] = esqd[a];
		a++;
		c++;
	}
	while (b < dir){
		parray[c] = dirt[b];
		b++;
		c++;
	}
}
void mergesort(int parray[], int i, int f){
	
	if(i < f){
		int meio; 
		meio = i +(f - i)/2;
	
		mergesort(parray,i,meio);

		mergesort(parray, meio+1, f);

		merge(parray,i,meio,f);
	}	

}
void print(int parray[], int n){
	for(int i = 0; i < n; i++){
		printf("%d ",parray[i]);
	}
}

int main (){
 	clock_t Ticks[2];
    Ticks[0] = clock();

	int parray[] = {3,1,8,4,5,6};
	int n=  sizeof(parray)/sizeof(parray[0]);

	mergesort(parray, 0, n-1);
	print(parray, n);

	
    Ticks[1] = clock();
   	double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %g ms.", Tempo);
   
   	return 0;
}
