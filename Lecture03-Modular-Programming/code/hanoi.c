#include <stdio.h>

void resolver_hanoi(int n, int origen, int destino, int auxiliar);

int main(void){
    int cantidad_discos;
    printf("Ingrese la cantidad de discos a resolver");
    scanf("%d", &cantidad_discos);

    resolver_hanoi(cantidad_discos, 1, 2, 3);
    return 1;
}

void resolver_hanoi(int n, int origen, int destino, int auxiliar){
    if(n > 0){
        resolver_hanoi(n - 1, origen, auxiliar, destino);
        printf("Mover disco %d a %d\n", origen, destino);
        resolver_hanoi(n - 1, auxiliar, destino, origen);
    }
    // no hay caso base
}
