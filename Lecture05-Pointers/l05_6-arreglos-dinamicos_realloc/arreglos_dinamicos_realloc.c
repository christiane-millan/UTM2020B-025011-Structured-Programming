#include <stdio.h>
#include <stdlib.h>

int main(){

    int *numeros;

    numeros = (int *) malloc(5 * sizeof(int));

    numeros[0] = 0;
    numeros[1] = 1;
    numeros[2] = 2;
    numeros[3] = 3;
    numeros[4] = 4;

    numeros = (int *) realloc(numeros, 3 * sizeof(int) );

    // numeros[5] = 5;
    // numeros[6] = 6;
    // numeros[7] = 7;
    // numeros[8] = 8;
    // numeros[9] = 9;

    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", numeros[i]);
    }
    
    return 0;
}