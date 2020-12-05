#include <stdio.h>

int main(){
    //declaramors
    int matriculas[20];
    char nombre[20][60];
    int b[4][4] = {{1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}, {4, 4, 4, 4}};

    // //inicializar
    // for (int i = 0; i < 20; i++)
    // {
    //     matriculas[i] = 2020123001 + i;//2020123456
    //     nombre = "Sin nombre" ;
    // }

    // //acceder
    // for (int i = 0; i < 20; i++)
    // {
    //     printf("La matricula es: %d\n", matriculas[i]);
  
    // }

    printf("contenido de mi matriz de 4x4\n");
    for (int fila = 0; fila < 4; fila++){
        for (int columna= 0; columna< 4; columna++){
            printf("%d\t", b[fila][columna]);
        }
        printf("\n");
    }
    
    int contador = 1;
    for (int fila = 0; fila < 4; fila++){
        for (int columna= 0; columna< 4; columna++){
            b[fila][columna] = contador++;
        }
    }
    


    printf("contenido de mi matriz de 4x4\n");
    for (int fila = 0; fila < 4; fila++){
        for (int columna= 0; columna< 4; columna++){
            printf("%d\t", b[fila][columna]);
        }
        printf("\n");
    }

    
    return 0;
}