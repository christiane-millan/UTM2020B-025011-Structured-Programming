#include <stdio.h>
#include <stdlib.h>

int tiempo(int horas, int minutos, int segundos);

int main(){
    int horas, minutos, segundos;
    printf("Ingrese horas, minutos y segundos");
    scanf("%d %d %d", &horas, &minutos, &segundos);
    int resultado1 = tiempo(horas, minutos, segundos);
    printf("Ingrese horas, minutos y segundos");
    scanf("%d %d %d", &horas, &minutos, &segundos);
    int resultado2 = tiempo(horas, minutos, segundos);
    // int resultado3 = tiempo(50, 100, 1000);
    // printf("%d\n", resultado3);
    printf("La cantidad de tiempo entre las dos horas es: %d\n", abs(resultado2 - resultado1) );
}

// 3h, 10m, 15s
// 15h, 30m, 5s
// 50h, 100m, 1000s
int tiempo(int horas, int minutos, int segundos){
    int segundos_total = 0;

    segundos_total = horas * 60 * 60;
    segundos_total += minutos * 60;
    segundos_total += segundos;
    segundos_total = segundos_total % 43200;
    return segundos_total;
}