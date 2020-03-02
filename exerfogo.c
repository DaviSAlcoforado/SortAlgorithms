#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int array[10];
    for (int i = 0; i<10; i++){
        scanf("%d",&array[i]);
    }

    int soma = 0;
    int maior_soma = 0;
    int size = 10;
    int contador = 0;
        for (int j = 0; j<size; j++){
                
            for (int i = 0; i<size; i++){
                soma += array[i];
    
        }
                if (soma > maior_soma)
                    maior_soma = soma;
            soma = 0;
        }
    printf("Maior soma: %d",maior_soma);
    return 0;
}
//Entrada de exemplo: -1 -1 -1 -1 4 9 5 4 3 2 1 
