#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
    int array[cont];
    cont = 0;
        while (!feof(ptr)) {
            fscanf(ptr,"%d",&array[cont]);
            cont++;
    }


    int temp;
    int tamanho = sizeof(array)/sizeof(int);
     for (i=1; i<(tamanho);i++)
     {
        for (j = i; j>0; j--){
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
    return 0;
}
