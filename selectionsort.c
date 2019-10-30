#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
    clock_t Ticks[2];
    Ticks[0] = clock();
    //começa contagem

    int i, j; // para varrer
    int array[] = {1,3,5,6,2,4,9,45,321,1}; //array definido (editável)
    int temp, menor; //variável auxiliar e variável para armazenar o menor número
    int tamanho = sizeof(array)/sizeof(int); //variável do tamanho do array
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


    for(i=0;i<(tamanho);i++){//Laço for para printar
        printf("%d ",array[i]);
    }

    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %g ms.", Tempo);
    getchar();
    return 0;
}
