#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

void leer_calorias(int *a, int tam);
float promedio_calorias(int *a, int tam);

int main(){
    int numeros[1000];
    int *calorias;
    int tamanno;

    printf("Igresar la cantidad de días que se registraran las calorías:");
    scanf("%d", &tamanno);

    calorias = (int *) malloc (tamanno * sizeof(int));

    if(calorias != NULL){
        leer_calorias(calorias, tamanno);
        printf("El promedio de calorias consumidas en %d días fue de: %.2f\n"
            , tamanno
            , promedio_calorias(calorias, tamanno));
    } else {
        printf("No se pudo reservar la memoria");
    }
    

    return 0;
}

void leer_calorias(int *a, int tam){
    for (int i = 0; i < tam; i++){
        printf("Ingrese el consumo de calorias del dia %d :", (i + 1));
        scanf("%d", &a[i]);
    }  
}

float promedio_calorias(int *a, int tam){
    float suma = 0.0;
    for (int i = 0; i < tam; i++){
        suma += *(a + i);
    }
    return (suma / tam);
}