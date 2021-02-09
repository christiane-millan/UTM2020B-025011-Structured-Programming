#include <stdio.h>
#include <stdlib.h>

int main (){
    float **temperaturas = NULL;

    int tamanno_filas, tamanno_columnas;

    printf("Ingrese la cantidad de dias que se registrarán temperaturas:");
    scanf("%d", &tamanno_filas);
    printf("Ingrese la cada cuantas horas se registrarán temperaturas al día:");
    scanf("%d", &tamanno_columnas);

    temperaturas = (float **) malloc (tamanno_filas * sizeof(float *));
    for (int i = 0; i < tamanno_filas; i++){
        temperaturas[i] = (float *) malloc (tamanno_columnas * sizeof(float));
    }
    
    return 0;
}