#include <stdio.h>
#include <string.h>

#define MAX_ALUMNO 60
#define MAX_CALIFICACIONES 4
#define MAX_ASISTENCIA 5

struct direccion{
    char calle[60];
    char ciudad[40];
    char estado[40];
    long int codigo_postal;
}

typedef struct direccion mi_direccion;
typedef int mi_integercito;

struct estudiante {
    int matricula;
    char nombre[MAX_ALUMNO];
    mi_direccion dir_estudiante;
    float calificaciones[MAX_CALIFICACIONES];
    int asistencias[MAX_ASISTENCIA];
} e5 = { 456, "Karla Ramirez", {9.0, 9.7, 9.9, 9.9}, {1, 1 , 0, 1, 1}};

typedef struct estudiante mi_estudiante;

struct estudiante e1, e2, e3;
struct estudiante e6;
struct estudiante e4 = { 123, "Juan Pablo", {9.0, 8.7, 9.0, 8.9}, {1, 1 , 0, 1, 1}};

int i1, i2, i3, i4, i5;
int i[1000];

mi_estudiante grupo[100];


int main(){
    mi_integercito numero = 1;
    int numeros[] = {1, 2, 3, 4, 5};

    numeros[0] = 6;

    //sizeof
    printf("El tamaño (sizeof) de estudiante : %lu\n", sizeof(e5));

    printf("Ingresar matricula: ");
    scanf("%d", &e1.matricula);
    printf("Ingresar nombre:");
    //gets(e1.nombre);
    fflush(stdin);
    fgets(e1.nombre, MAX_ALUMNO, stdin);
    
    for (int i = 0; i < MAX_CALIFICACIONES; i++){
        printf("Ingresar calificación paricial %d:", i + 1);
        scanf("%f", &e1.calificaciones[i]);   
    }
    
    for (int i = 0; i < MAX_ASISTENCIA; i++){
        printf("Ingresar asistencia no. %d:", i + 1);
        scanf("%d", &e1.asistencias[i]);   
    }

    printf("Datos del alumno:\n");
    printf("Matricula: %d\n", e1.matricula);
    printf("Nombre: %s\n", e1.nombre);
    for (int i = 0; i < MAX_CALIFICACIONES; i++){
        printf("Calificacion %d: %f \n", i+1, e1.calificaciones[i]);
    }
    for (int i = 0; i < MAX_ASISTENCIA; i++) {
        printf("Asistencia %d: %d\n", i+1, e1.asistencias[i]);
    }
    



    e2.matricula = 123;
    strcpy(e2.nombre, "Carlos Gonzalez");
    e2.calificaciones[0] = 0.0;
    e2.calificaciones[1] = 0.0;
    e2.calificaciones[2] = 0.0;
    e2.calificaciones[3] = 0.0;
    e2.asistencias[0] = 0;
    e2.asistencias[1] = 0;
    e2.asistencias[2] = 0;
    e2.asistencias[3] = 0;
    e2.asistencias[4] = 0;

    struct estudiante *p_e3;
    p_e3 = &e3;

    p_e3->matricula = 567;
    strcpy(p_e3->nombre,  "Jose Garcia");
    p_e3->calificaciones[0] = 10.0;
    p_e3->asistencias[0] = 1;

    printf("Datos del alumno:\n");
    printf("Matricula: %d\n", p_e3->matricula);
    printf("Nombre: %s\n", p_e3->nombre);
    for (int i = 0; i < MAX_CALIFICACIONES; i++){
        printf("Calificacion %d: %f \n", i+1, p_e3->calificaciones[i]);
    }
    for (int i = 0; i < MAX_ASISTENCIA; i++) {
        printf("Asistencia %d: %d\n", i+1, p_e3->asistencias[i]);
    }

    return 0;
}