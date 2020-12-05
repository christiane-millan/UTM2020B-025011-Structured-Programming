#include <stdio.h>

unsigned long int factorial(int n){
    unsigned long int resultado = 1;
    int i = 0;
    for(i = 1; i <= n; i++){
        resultado *= i;
    }
    return resultado;
}


unsigned long int factorial_recursivo(int n){
    if (n == 0){
        return 1;
    } else {
        return (n * factorial_recursivo( n - 1));
    }
}

int main(){
    int n = 20;
    printf("El factorial (iterativo) de %d! es igual a %ld\n", n, factorial(n));

    printf("El factorial (recursivo) de %d! es igual a %ld\n", n, factorial_recursivo(n));
    return 0;

}