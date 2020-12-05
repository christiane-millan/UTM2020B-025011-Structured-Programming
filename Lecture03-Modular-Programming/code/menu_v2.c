#include <stdio.h>

int matricula;
char nombre[60];
float calificacion1;
float calificacion2; 
float calificacion3;
float calificacion_final;

//prototipo de una función
float promedio(float cal1, float cal2, float cal3, float cal_final);
void menu_principal();
void menu_modicar_calificacion();
void agregar_alumno();
void imprimir_alumno();
void modificar_alumno();


void menu_principal(){
    // Este un ejemplo de una función que no necesita parámetros de entrada
    printf("------------------------------------------------------\n");
    printf("\t\t\tMenu de opciones. \n");
    printf("------------------------------------------------------\n")
    printf("1.- Agregar datos del alumno.\n");
    printf("2.- Modificar los datos del alumno.\n");
    printf("3.- Mostrar datos del alumno.\n");
    printf("4.- Salir\n\n");        
}

void menu_modicar_calificacion(){
    // Este un ejemplo de una función que no necesita parámetros de entrada
    int op = 0;
    while (op != 5) {
        printf("------------------------------------------------------\n");
        printf("\t\t\t...Menu de cambio de califaciones. \n");
        printf("------------------------------------------------------\n");
        printf("1.- Modificar calificación 1:\n");
        printf("2.- Modificar calificación 2:\n");
        printf("3.- Modificar calificación 3:\n");
        printf("4.- Modificar calificación final:\n");
        printf("5.- Salir\n\n");

        printf("Ingresa una opción: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1: printf("Ingregar calificación 1: ");
                scanf("%f", &calificacion1);
            break;
        case 2: printf("Ingregar calificación 2: ");
                scanf("%f", &calificacion2);
            break;
        case 3: printf("Ingregar calificación 3: ");
                scanf("%f", &calificacion3);
            break;
        case 4: printf("Ingregar calificación final: ");
                scanf("%f", &calificacion_final);
            break;
        case 5:
            break;

        default:
            break;
        }
    }
            
}


void agregar_alumno(){
    printf("------------------------------------------------------\n");
    printf("\t\t\t...Nuevo alumno.\n");
    printf("------------------------------------------------------\n");
    printf("Ingresar matricula: ");
    scanf("%d", &matricula);
    printf("Ingresar nombre: ");
    scanf("%s", nombre);
    printf("Ingresar calificación 1: ");
    scanf("%f", &calificacion1);
    printf("Ingresar calificación 2: ");
    scanf("%f", &calificacion2);
    printf("Ingresar calificación 3: ");
    scanf("%f", &calificacion3);
    printf("Ingresar calificación final: ");
    scanf("%f", &calificacion_final);
}

void imprimir_alumno(){
    printf("------------------------------------------------------\n");
    printf("\t\t\tDatos del alumno \n");
    printf("------------------------------------------------------\n");
    printf("Matricula: \t%d\n", matricula);
    printf("Nombre: \t%s\n", nombre);
    printf("Calificación 1: \t%f\n", calificacion1);
    printf("Calificación 2: \t%f\n", calificacion2);
    printf("Calificación 3: \t%f\n", calificacion3);
    printf("Calificación f: \t%f\n", calificacion_final);
    float prom = promedio(calificacion1, calificacion2, calificacion3, calificacion_final);
    printf("Promedio: %f \n", prom);
}

float promedio(float cal1, float cal2, float cal3, float cal_final){
    float cal_total = (cal1 + cal2 + cal3) / 3;
    float cal = (cal_total + cal_final) / 2;
    return cal;
}

void modificar_alumno(){
    printf("Ingresar calificación 1: ");
    scanf("%f", &calificacion1);
    printf("Ingresar calificación 2: ");
    scanf("%f", &calificacion2);
    printf("Ingresar calificación 3: ");
    scanf("%f", &calificacion3);
    printf("Ingresar calificación final: ");
    scanf("%f", &calificacion_final);
}

int main() {
    int opt = 0;
    while( opt != 4) {
        menu_principal();
        printf("Ingresa un opción:");
        scanf("%d", &opt); 

        switch (opt) {
        case 1: agregar_alumno();
            break;
        case 2: menu_modicar_calificacion();
            break;
        case 3: imprimir_alumno();
            break;
        case 4:
            break;
        default:
            break;
        }
    }
    return 0;
}