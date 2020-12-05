#include <stdio.h>
#include <math.h>

int es_primo(int numero);

int main(){
    // int numero = 9;
    // printf("Ingresa un numero:");
    // scanf("%d", &numero);
    // (es_primo(numero)==1)?printf("%d es primo\n", numero):printf("%d no es primo\n", numero);

    int primos = 0, no_primos = 0;
    for (int numero = 1; numero <= 10000; numero++)
    {   
        if(es_primo(numero)==1){
            //printf("%d es primo\n", numero);
            primos++;
        } else {
            //printf("%d no es primo\n", numero);  
            no_primos++;
        }
    }
    printf("Numero de primos %d, numero no primos %d", primos, no_primos);

    return 0;
}

//2,3,5 y 7
//4,6,8 y 9
int es_primo(int numero){
    for (int i = 2; i <= sqrt(numero); i++){
        if ( numero % i == 0) {
            return 0;
        }
    }
    return 1;
}