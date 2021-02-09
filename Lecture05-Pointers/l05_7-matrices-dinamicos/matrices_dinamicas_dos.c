#include <stdio.h>
#include <stdlib.h>

void leer_temperaturas(float **temperaturas, int f, int c);
void mostrar_temperaturas(float **temperaturas, int f, int c);

int main (){
    float **temperaturas = NULL;

    int tamanno_filas, tamanno_columnas, frecuencia;

    printf("Ingrese la cantidad de dias que se registrarán temperaturas:");
    scanf("%d", &tamanno_filas);
    printf("Ingrese cada cuantas horas se registrarán temperaturas al día:");
    scanf("%d", &frecuencia);

    tamanno_columnas = 24 / frecuencia;

    temperaturas = (float **) malloc (tamanno_filas * sizeof(float *));
    if ( temperaturas == NULL){
        printf("No se pudo reservar la memoria\n");
        return -1;
    }
    
    for (int i = 0; i < tamanno_filas; i++){
        temperaturas[i] = (float *) malloc (tamanno_columnas * sizeof(float));
        if( temperaturas[i] == NULL){
            printf("No se pudo reservar la memoria\n");
            return -1;
        }
    }
    
    leer_temperaturas(temperaturas, tamanno_filas, tamanno_columnas);
    mostrar_temperaturas(temperaturas, tamanno_filas, tamanno_columnas);

    return 0;
}

void leer_temperaturas(float **temperaturas, int f, int c){
    for (int fila = 0; fila < f; fila++){
        for (int columna = 0; columna < c; columna++){
            printf("Ingresar la temperatura numero %d del día %d:", columna + 1, fila + 1);
            scanf("%f", &temperaturas[fila][columna]);
        }
    }
    
}

void mostrar_temperaturas(float **temperaturas, int f, int c){
    for (int i = 0; i < f; i++){
        for (int j = 0; j < c; j++){
            printf("%f\t", temperaturas[i][j]);
        }
        printf("\n");
    }
    
}