#include <stdio.h>

int main(){
    FILE *cfPtr;

    if ((cfPtr = fopen("estudiantes.txt", "w")) == NULL){
        puts("Archivo no su puede abrir...");
    } else {
        puts("Ingresar matricula y nombre:");
        puts("Ingresa EOF (End Of File) para salir de la captura");

        int matricula;
        char nombre[60];

        scanf("%d %59s", &matricula, nombre);
        while(!feof(stdin)){
            fprintf(cfPtr, "%d %s\n", matricula, nombre);
            printf("Ingresar más datos:");
            scanf("%d%59s", &matricula, nombre);
        }

        fclose(cfPtr);
    }

    return 0;
}