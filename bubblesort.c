#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    int i, j;
    int array[] = {1,3,5,6,2,4,9,45,321,1}; 
    int temp;
    int tamanho = sizeof(array)/sizeof(int);

     for (i=0; i<(tamanho-1);i++)
     {
        for (j = 0; j<(tamanho-1); j++){
                if (array[j]>array[j+1])
                {
                 temp = array[j];
                 array[j] = array[j+1];
                 array[j+1] = temp;
                }
                }
              }

    for(j=0;j<(tamanho);j++){
        printf("%d ",array[j]);
    }
  }