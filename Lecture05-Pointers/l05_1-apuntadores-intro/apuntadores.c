/*
 *
 * Christian Millán
 * Unidad 5. Apuntadores - Introducción 
 * Ejemplo de classe de la implementación de apuntadores
 *
 */

#include <stdio.h>

int main(void){
    int count = 5;
    int x;
    int y;
    const int n = 5;

    /*
     * Un apuntado es declarado mediante el uso del operador *, considerar que el tipo de dato del apuntador
     * debe ser igual al tipo de dato que se desa que apunte, en este ejemplo apuntara a la variable x, con
     * el operador & se asisigna la dirección de la variable x
     *
     */

    int * const p_number = &x;

    /* Asinación idirecta del valor 7 a la variable count */

    *p_number = 7;
    
    //p_number = &y;


    int x1 = 5;
    int y1;

    const int * const ptr = &x1;
    
    //*ptr = 7;
    //ptr = &y1;

    //scanf("%d", &ccount);
    // int *countPtr;
    // int *ptrCount;
    // int *ptr_count;
    // int *count_ptr;
    // int *count_p;

    //declaración
    int *p_count;

    //asigación de una direccion o inicialización
    p_count = &count;

    printf("count %d\n", count);
    // acceso de manera indirecta
    printf(" p_count %d\n", *p_count);
    
    printf("La dirección de count es %p\n", &count);
    printf("La direccion de p_count es %p\n", &p_count);
    printf("La direccion almacenada en p_count es %p\n", p_count);

    printf("ejemplos de * y & %p\n", &*p_count);
    printf("ejemplos de * y & %p\n", *&p_count);
    return 0;
}
