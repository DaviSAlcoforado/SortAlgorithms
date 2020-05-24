#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]){

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


    int inserido = 0;
    int tamanho = sizeof(array)/sizeof(int);
    clock_t Ticks[2];
    Ticks[0] = clock();
     for (i=1; i<(tamanho);i++) {
        inserido = array[i];
        for (j = (i-1); j>=0 && array[j] > inserido; j--) {
            array[j+1] = array[j];
        }
        array[j+1] = inserido;
     }
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    for(j=0;j<(tamanho)-1;j++){
        printf("%d ",array[j]);
    }

    printf("\nTempo gasto: %g ms.", Tempo);
    return 0;
}
