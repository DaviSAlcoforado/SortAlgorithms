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
    int temp, menor; //variável auxiliar e variável para armazenar o menor número
    int tamanho = sizeof(array)/sizeof(int); //variável do tamanho do array
    clock_t Ticks[2];
    Ticks[0] = clock();
    //começa contagem
     for (i=0; i<(tamanho);i++)//laço for para checar o menor número
     {
        menor = i;//Armazenar o menor número
        for (j = (i+1); j<(tamanho); j++){//Laço for para varrer
                if (array[j]<array[menor])//Condicional if para armazenar o menor número
                {
                 menor = j;//Armazenar o menor número
               }
                 if (array[i] > array[menor]){//Se o array[i] não for o menor número, troca
                 temp = array[i];//Armazena a que não é menor em uma auxiliar
                 array[i] = array[menor];//O valor na posição I vira o menor
                 array[menor] = temp;//A auxiliar é o menor número
                }
              }
                     }
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;


    for(i=0;i<(tamanho)-1;i++){//Laço for para printar
        printf("%d ",array[i]);
    }
    printf("\nTempo gasto: %g ms.", Tempo);
    return 0;
}
