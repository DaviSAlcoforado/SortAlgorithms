#include <stdio.h>
#include <stdlib.h>

int heaps(int *parray, int inc, int fim){
	int pron;
	int fmax;
	int aux;
	
	pron = 0;
	while((inc * 2 <= fim) && (!pron)){
		if(inc * 2 == fim){
			fmax = inc * 2;
			}
		else if(parray[inc * 2] > parray[inc * 2 + 1]){
			fmax = inc * 2;
			}
		else{
			fmax = inc * 2 + 1;
			}
		if(parray[inc] < parray[fmax]){
			aux = parray[inc];
			parray[inc] = parray[fmax];
			parray[fmax] = aux;
			inc = fmax;
			}
		else{
			pron = 1;
		}
	}
}
int heapsort(int *parray, int n){
	int aux;
	for(int i = (n/2);i>= 0; i--){
		heaps(parray,i,n - 1);
	}
	for(int i = n - 1; i >= 0;i--){
		aux = parray[0];
		parray[0] = parray[i];
		parray[i] = aux;
		heaps(parray, 0, i-1);
	}
}
int Printar(int *parray[], int n){
	for(int i = 0; i<n;++i){
		printf("%d ",parray[i]);
	}
}
int main(){
	int array[] = {4,5,6,7,8,1,2,3,65,98};
	int n=  sizeof(array)/sizeof(int);
	int *parray = array; 
	heapsort(parray, n);
	Printar(parray,n);
}