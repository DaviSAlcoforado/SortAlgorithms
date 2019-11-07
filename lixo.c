#include <stdio.h>
#include <stdlib.h>


int heaps(int *parray, int n, int i){
	int esq;
	int dir;
	int aux;
	int maior;
	maior = i;
	int a, b;
	esq = (2*i) + 1;
	dir = (2*i) + 2;
	int tmp = 1;
	int j;

	while(2*i<=n && tmp==1)
    {
       j=2*i;
       if(j+1<=n && arr[j+1] > arr[j])
           j++;

       if( arr[j] < arr[i])
           int k=0;
       else
       {
           temp=arr[i];
           arr[i]=arr[j];
           arr[j]=temp;
           i=j;
        }
      }

	return parray;
}
int heapsort(int *parray, int n){
	int i;
	for(i = (n/2) - 1;i>= 0; i--){
		heaps(parray, n-1, i);
	}
	for(i = n-1; i >= 0; i--){
		int aux;
		aux= parray[0];
		parray[0] = parray[n];
		parray[n] = aux;
		heaps(parray, 0,i -1);

}
	return parray;
}
int main(){
	int array[] = {4,5,6,7,8,1,2,3,65,98};
	int *parray = array;
	int n=  sizeof(array)/sizeof(int);
	int i;
	 heapsort(parray, n);
		for(int i = 0; i<n;i++){
			printf("%d ",parray[i]);
	}
}