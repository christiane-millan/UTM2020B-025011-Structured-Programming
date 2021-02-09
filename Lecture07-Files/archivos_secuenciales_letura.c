#include <stdio.h>

int main(){
    FILE *cfPtr;

    if ((cfPtr = fopen("estudiantes.txt", "r")) == NULL){
        puts("Archivo no se puede abrir...");
    } else {
        
        int matricula;
        char nombre[60];

        printf("%-10s%-18s\n", "Matricula", "Nombre");
        fscanf(cfPtr, "%d %60s", &matricula, nombre);

        while(!feof(cfPtr)){
            printf("%-10d%-18s\n", matricula, nombre);
            fscanf(cfPtr, "%d\t%59s", &matricula, nombre);
        }

        //sirve para posicionarse al principio del archivo
        // rewind(cfPrt);

        // fscanf(cfPtr, "%d %60s", &matricula, nombre);

        fclose(cfPtr);
    }

    return 0;
}