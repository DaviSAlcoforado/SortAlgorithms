#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
    clock_t Ticks[2];
    Ticks[0] = clock();

    int i, j;
    int array[] = {15,84,75,21,36,47,95,32,14,20,1,3,2,8,4,6};
    int temp;
    int tamanho = sizeof(array)/sizeof(int);

     for (i=0; i<(tamanho);i++)
     {
        for (j = 1; j<(tamanho); j++){
                 if (array[j] < array[j-1]){
                   temp = array[j];
                   array[j] = array[j-1];
                   array[j-1] = temp;
                 
                }
                }
              }

    for(j=0;j<(tamanho);j++){
        printf("%d ",array[j]);
    }

    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %g ms.", Tempo);
    getchar();
    return 0;
}
