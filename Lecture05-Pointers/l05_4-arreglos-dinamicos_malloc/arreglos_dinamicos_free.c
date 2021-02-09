#include <stdio.h>
#include <stdlib.h>

int main(){

    float *numeros = NULL;
    int tamanno;

    printf("Ingese el tamaño:");
    scanf("%d", &tamanno);

    for (int i = 0; i < 100000; i++){
        numeros = (float *) malloc (tamanno * sizeof(float));
    }
    
    free(numeros);
    return 0;

}