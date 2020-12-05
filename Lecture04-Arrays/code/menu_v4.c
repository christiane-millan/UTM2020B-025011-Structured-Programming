#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> 

#define MAX_ASISTENCIA 5
#define MAX_CALIFICACIONES 4
#define MAX 25
#define DIV_2 2.0
#define MAX_NOM 60
#define prom_parcial(cal1, cal2, cal3) ((cal1 + cal2 + cal3) / 3.0)

const int MIN = 100;
char mensaje[] = {'S', 'I', 'S', 'T', 'E', 'M', 'A', ' ', 'C', 'O', 'N', 'T', 'R', 'O', 'L'};

int matricula = 123123;
char nombre[MAX_NOM] = "Juan Carlos";
float calificaciones[MAX_CALIFICACIONES] = {0.0 , 0.0, 0.0, 0.0};
int asistencias[MAX_ASISTENCIA];
//int asistencias[MAX_ASISTENCIA] = {1, 1, 1, 1, 1, 1};
// float calificacion1 = 7.0;
// float calificacion2 = 7.0; 
// float calificacion3 = 7.0;
// float calificacion_final = 7.0;
// asistencias[0] = 1;
// asistencias[1] = 1;
// asistencias[2] = 1;
// asistencias[3] = 1;
// asistencias[4] = 1;


//prototipo de una función por valor
float promedio(float cal[]);
float minimo(float c[]);
float maximo(float c[]);
void menu_principal();
//prototipo de una función por referencia
void menu_modicar_calificacion(float* c1, float* c2, float* c3, float* cf);
void menu_modicar_calificacion2(float calificaciones[]);
void agregar_alumno();
void imprimir_alumno();
void modificar_alumno();

void inicializar_asistencia();
void pase_lista();
void imprimir_asistencia();

void inicializar_asistencia(){
    // asistencias[0] = 1;
    // asistencias[1] = 1;
    // asistencias[2] = 1;
    // asistencias[3] = 1;
    // asistencias[4] = 1;  
    // for
    // while
    // do-while
    int i = 0;
    for(i = 0; i < MAX_ASISTENCIA; i++){
        asistencias[i] = 1;
    }
}

void pase_lista(){
    int dia;
    do {
        printf("Día de la semana de pase de lista: [1 - %d ]: ", MAX_ASISTENCIA);
        scanf("%d", &dia);    
    } while((dia < 1 ) && (dia > MAX_ASISTENCIA));
    printf("Indicar Asistencia [1] o Falta [0]: ");
    scanf("%d", &asistencias[dia - 1]);
}

void imprimir_asistencia(){
    int i;
    for(i = 0; i < MAX_ASISTENCIA - 1; i++){
        if ( asistencias[i] == 1)
            printf("A, ");
        else 
            printf("F, ");
    }
    // if(asistencias[MAX_ASISTENCIA-1] == 1) printf("A"); else printf("F");
    (asistencias[MAX_ASISTENCIA-1] == 1)? printf("A"): printf("F");
    printf("\n");
}


void menu_principal(){
    // Este un ejemplo de una función que no necesita parámetros de entrada
    //system("clear");
    printf("%s\n", mensaje);
    printf("------------------------------------------------------\n");
    printf("\t\tMenu de opciones. \n");
    printf("------------------------------------------------------\n");
    printf("1.- Agregar datos del alumno.\n");
    printf("2.- Modificar los datos del alumno.\n");
    printf("3.- Ingresar calificaciones del alumno.\n");
    printf("4.- Mostrar datos del alumno.\n");
    printf("5.- Pase de lista\n");
    printf("6.- Salir\n\n");        
}

void menu_modicar_calificacion(float* c1, float* c2, float* c3, float* cf){
    // Este un ejemplo de una función que no necesita parámetros de entrada
    int op = 0;
    while (op != 5) {
        system("clear");
        printf("------------------------------------------------------\n");
        printf("\t\t\t... Menu de cambio de califaciones. \n");
        printf("------------------------------------------------------\n");
        printf("1.- Modificar calificación 1:\n");
        printf("2.- Modificar calificación 2:\n");
        printf("3.- Modificar calificación 3:\n");
        printf("4.- Modificar calificación final:\n");
        printf("5.- Salir\n\n");

        printf("Ingresa una opción: ");
        scanf("%d", &op);

        float r;
        float nuevo_cal;
        switch (op)
        {
        case 1: printf("Ingregar calificación 1: ");
                scanf("%f", &nuevo_cal);
                *c1 = nuevo_cal;
            break;
        case 2: printf("Ingregar calificación 2: ");
                scanf("%f", &nuevo_cal);
                *c2 = nuevo_cal;
            break;
        case 3: printf("Ingregar calificación 3: ");
                scanf("%f", &nuevo_cal);
                *c3 = nuevo_cal;
            break;
        case 4: //printf("Ingregar calificación final: ");
                //scanf("%f", &nuevo_cal);
                // numero = rand () % (N-M+1) + M;   // Este está entre M y N // Entero
                // (float)rand()/(float)(RAND_MAX)) * a
                r = (float) rand() / (RAND_MAX);
                //rand = M + r * (N - M)
                *cf = 6.0 + r * (10.0 - 6.0);
            break;
        case 5:
            break;

        default:
            break;
        }
    }
            
}

void menu_modicar_calificacion2(float calificaciones[]){
    int op = 0;
    while (op != 5) {
        system("clear");
        printf("------------------------------------------------------\n");
        printf("\t\t\t... Menu de cambio de califaciones. \n");
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
                scanf("%f", &calificaciones[op - 1]);
            break;
        case 2: printf("Ingregar calificación 1: ");
                scanf("%f", &calificaciones[op - 1]);
            break;
        case 3: printf("Ingregar calificación 1: ");
                scanf("%f", &calificaciones[op - 1]);
            break;
        case 4: printf("Ingregar calificación 1: ");
                scanf("%f", &calificaciones[op - 1]);
            break;
        case 5:
            break;
        default:
            break;
        }
    }  
}


void agregar_alumno(){
    system("clear");
    printf("------------------------------------------------------\n");
    printf("\t\t\t... Nuevo alumno.\n");
    printf("------------------------------------------------------\n");
    printf("Ingresar matricula: ");
    scanf("%d", &matricula);
    printf("Ingresar nombre: ");
    scanf("%s", nombre);
    // printf("Ingresar calificación 1: ");
    // scanf("%f", &calificacion1);
    // calificacion1 = pow(calificacion1, 2);
    // calificacion2 = sqrt(calificacion1);
    // printf("Ingresar calificación 2: ");
    // scanf("%f", &calificacion2);
    // printf("Ingresar calificación 3: ");
    // scanf("%f", &calificacion3);
    // printf("Ingresar calificación final: ");
    // scanf("%f", &calificacion_final);
}

void imprimir_calificaciones(){
    float m = 0.0;
    for (int i = 0; i < MAX_CALIFICACIONES; i++)
    {
        printf("Calificacion %d :\t%.2f\n", i + 1, calificaciones[i]);
    }
    float prom = promedio(calificaciones);
    printf("Promedio: %.2f\n", prom);
    m = minimo(calificaciones);
    printf("La calificación mínima: %.2f\n", m);
    m = maximo(calificaciones);
    printf("La calificación máxima: %.2f\n", m);

}

void imprimir_alumno(){
    float m = 0;
    system("clear");
    printf("------------------------------------------------------\n");
    printf("\t\t\tDatos del alumno \n");
    printf("------------------------------------------------------\n");
    printf("Matricula: \t%d\n", matricula);
    printf("Nombre: \t%s\n", nombre);
    

    printf("Asistencias: \n");
    imprimir_asistencia();
    imprimir_calificaciones();
    // printf("Lunes : %d\n", asistencias[0]);
    // printf("Martes : %d\n", asistencias[1]);
    // printf("Miércoles : %d\n", asistencias[2]);
    // printf("Jueves : %d\n", asistencias[3]);
    // printf("Viernes : %d\n", asistencias[4]);


}

float promedio(float cal[]){
    float cal_total = (cal[0] + cal[1] + cal[2]) / 3.0;
    float cal_f = (cal_total + cal[3]) / DIV_2;
    return cal_f;
}

float minimo(float c[]){
    float min = c[0];
    if (min > c[1]){ 
        min = c[1];
    }
    if (min > c[2]){
        min = c[2]; 
    }
    if (min > c[3]) { 
        min = c[3];
    }
    return min;
}

float maximo(float c[]){
    float max = c[0];
    if (max < c[1]){ 
        max = c[1];
    }
    if (max < c[2]){
        max = c[2]; 
    }
    if (max < c[2]) { 
        max = c[2];
    }
    return max;
}

void modificar_alumno(){
    puts("Menu para modificar nombre del alumno.");
    printf("Nombre actual: %s\n", nombre);
    fflush(stdin);
    puts("Ingresar nombre: ");
    gets(nombre);
}

int main() {
    srand(time(0));
    inicializar_asistencia();
    int opt = 0;
    while( opt != 6) {
        menu_principal();
        printf("Ingresa un opción: ");
        scanf("%d", &opt); 

        switch (opt) {
        case 1: agregar_alumno();
            break;
        case 2: modificar_alumno();
            break;
        case 3: menu_modicar_calificacion2(calificaciones);
            break;
        case 4: imprimir_alumno();
            break;
        case 5: pase_lista();
            break;
        case 6:
            break;
        default:
            break;
        }
    }
    return 0;
}