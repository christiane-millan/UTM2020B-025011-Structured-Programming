#include <stdio.h>
#define ARRAY_SIZE 4

int main(){
    int b[] = {10, 20, 30, 40};
    int *b_ptr = b;

    puts("Uso de indices para acceder al arreglo");
    for (int i = 0; i < ARRAY_SIZE; i++){
        printf("b[%d] = %d\n", i, b[i]);
    }

    puts("Uso de indirecciones para acceder al arreglo");
    for (int i = 0; i < ARRAY_SIZE; i++){
        printf("*(b + %d) = %d\n", i, *(b + i));
    }
    
    puts("Uso de un apuntadores para acceder al arreglo");
    for (int i = 0; i < ARRAY_SIZE; i++){
        printf("*b_ptr[%d] = %d\n", i, b_ptr[i]);
    }

    puts("Uso de un apuntadores e indirecciones para acceder al arreglo");
    for (int i = 0; i < ARRAY_SIZE; i++){
        printf("*(b_ptr + %d) = %d\n", i, *(b_ptr + i));
    }
    
}