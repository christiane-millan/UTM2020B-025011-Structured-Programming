#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h> 

#define MAX_ASISTENCIA 5
#define MAX_CALIFICACIONES 4
#define MAX_ALUMNOS 5
#define MAX 25
#define DIV_2 2.0
#define MAX_NOM 60
#define prom_parcial(cal1, cal2, cal3) ((cal1 + cal2 + cal3) / 3.0)

const int MIN = 100;
char mensaje[100] = "Mensaje";

int matriculas[MAX_ALUMNOS] = {123, 345, 567};
char nombres[MAX_ALUMNOS][MAX_NOM] = {"Juan Carlos", "Karla", "Alberto"};
float calificaciones[MAX_ALUMNOS][MAX_CALIFICACIONES] = {{0.0 , 0.0, 0.0, 0.0}, {0.0 , 0.0, 0.0, 0.0}, {0.0 , 0.0, 0.0, 0.0}};
int asistencias[MAX_ALUMNOS][MAX_ASISTENCIA];


//prototipo de una función por valor
float promedio(float cal[]);
float minimo(float c[]);
float maximo(float c[]);
void menu_principal();
//prototipo de una función por referencia
void menu_modicar_calificacion(float* c1, float* c2, float* c3, float* cf);
void menu_modicar_calificacion2(float calificaciones[][MAX_CALIFICACIONES]);
void agregar_alumno();
int posicion_alumno_imprimir();
void imprimir_alumno(int posicion);
void modificar_alumno();

void inicializar_asistencia();
void pase_lista();
void imprimir_asistencia(int posicion);
void imprimir_calificaciones(int posicion);

void busqueda_matricula();
int busqueda_secuencial(int matricula);

void inicializar_asistencia(){
    for (int filas = 0; filas < MAX_ALUMNOS; filas++){
        for(int columnas = 0; columnas < MAX_ASISTENCIA; columnas++){
            asistencias[filas][columnas] = -1;
        }
    }
    
    
}

void pase_lista(){
    int posicion;
    printf("Indica la posición del alumno [1 - %d]: ", MAX_ALUMNOS);
    scanf("%d", &posicion);
    posicion--;
    int dia;
    do {
        printf("Día de la semana de pase de lista: [1 - %d ]: ", MAX_ASISTENCIA);
        scanf("%d", &dia);    
    } while((dia < 1 ) && (dia > MAX_ASISTENCIA));
    printf("Indicar Asistencia [1] o Falta [0]: ");
    scanf("%d", &asistencias[posicion][dia - 1]);
}

void imprimir_asistencia(int posicion){
    int i;
    for(i = 0; i < MAX_ASISTENCIA - 1; i++){
        if ( asistencias[posicion][i] == 1)
            printf("A, ");
        else{
            if (asistencias[posicion][i] == -1)
                printf("*, ");
            else
            {
                printf("F, ");
            }
            
        } 
            
    }
    
    if(asistencias[posicion][MAX_ASISTENCIA-1] == 1) 
        printf("A");
    else
        if(asistencias[posicion][MAX_ASISTENCIA-1] == -1) 
            printf("*");
        else
            printf("F");
            
    //(asistencias[posicion][MAX_ASISTENCIA-1] == 1)? printf("A"):(asistencias[posicion][MAX_ASISTENCIA-1] == -1)?printf("*"):printf("F");

    printf("\n");
    //? :
    // (condiciion)?V:F
    // (condiciion1)?V:(condicion2)?V:F
}


void menu_principal(){
    // Este un ejemplo de una función que no necesita parámetros de entrada
    //system("clear");
    //mensaje = "SISTEMA DE CONTROL ESCOLAR";
    char mensaje2[100] = "SISTEMA DE CONTROL ESCOLAR";
    strcpy(mensaje, mensaje2); //copia toda la cadena
    //strncpy copiar n caracters 
    //strcmp comparar dos cadena
    //strlen tamño de la cade
    printf("%s\n", mensaje);
    printf("------------------------------------------------------\n");
    printf("\t\tMenu de opciones. \n");
    printf("------------------------------------------------------\n");
    printf("1.- Agregar datos del alumno.\n");
    printf("2.- Modificar los datos del alumno.\n");
    printf("3.- Ingresar calificaciones del alumno.\n");
    printf("4.- Mostrar datos del alumno.\n");
    printf("5.- Pase de lista\n");
    printf("6.- Busqueda de alumno por matricula\n");
    printf("7.- Salir\n\n");        
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

void menu_modicar_calificacion2(float calificaciones[][MAX_CALIFICACIONES]){
    int op = 0;
    int posicion;
    printf("Indicar la posición a modificar [1 - %d]: ", MAX_ALUMNOS);
    scanf("%d", &posicion);
    posicion = posicion - 1;
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
                scanf("%f", &calificaciones[posicion][op - 1]);
            break;
        case 2: printf("Ingregar calificación 1: ");
                scanf("%f", &calificaciones[posicion][op - 1]);
            break;
        case 3: printf("Ingregar calificación 1: ");
                scanf("%f", &calificaciones[posicion][op - 1]);
            break;
        case 4: printf("Ingregar calificación 1: ");
                scanf("%f", &calificaciones[posicion][op - 1]);
            break;
        case 5:
            break;
        default:
            break;
        }
    }  
}


void agregar_alumno(){
    int posicion;
    system("clear");
    printf("------------------------------------------------------\n");
    printf("\t\t\t... Nuevo alumno.\n");
    printf("------------------------------------------------------\n");
    printf("La posicion donde deseas almacenar al alumno [1 - %d]:", MAX_ALUMNOS);
    scanf("%d", &posicion);
    posicion--;
    printf("Ingresar matricula: ");
    scanf("%d", &matriculas[posicion]);
    printf("Ingresar nombre: ");
    //scanf("%s", nombres[posicion - 1]);
    fflush(stdin);
    fgets(nombres[posicion], MAX_NOM, stdin);
    puts("Datos almacenado correctamente...");
    puts("Ejemplo de putchar():");
    putchar('X');
    puts("Presiona cualquier tecla para continuar...");
    fflush(stdin);
    getchar();
}

void imprimir_calificaciones(int posicion){
    float m = 0.0;
    for (int i = 0; i < MAX_CALIFICACIONES; i++)
    {
        printf("Calificacion %d :\t%.2f\n", i + 1, calificaciones[posicion][i]);
    }
    float prom = promedio(calificaciones[posicion]);
    printf("Promedio: %.2f\n", prom);
    m = minimo(calificaciones[posicion]);
    printf("La calificación mínima: %.2f\n", m);
    m = maximo(calificaciones[posicion]);
    printf("La calificación máxima: %.2f\n", m);

}

int posicion_alumno_imprimir(){
    int posicion;

    printf("Indicar la posición del alumno [1 - %d]:", MAX_ALUMNOS);
    scanf("%d", &posicion);
    posicion--;
    return posicion;
}

void imprimir_alumno(int posicion){
    float m = 0;
    system("clear");
    printf("------------------------------------------------------\n");
    printf("\t\t\tDatos del alumno \n");
    printf("------------------------------------------------------\n");
    printf("Matricula: \t%d\n", matriculas[posicion]);
    printf("Nombre: \t%s\n", nombres[posicion]);
    

    printf("Asistencias: \n");
    imprimir_asistencia(posicion);
    imprimir_calificaciones(posicion);
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
    int posicion;
    puts("Menu para modificar nombre del alumno.");
    printf("Indica la posicion [1 - %d]:", MAX_ALUMNOS);
    scanf("%d", &posicion);
    printf("Nombre actual: %s\n", nombres[posicion - 1]);
    fflush(stdin);
    puts("Ingresar nombre: ");
    gets(nombres[posicion - 1]);
}

int main() {
    srand(time(0));
    inicializar_asistencia();
    int opt = 0;
    while( opt != 7) {
        menu_principal();
        printf("Ingresa un opción: ");
        scanf("%d", &opt); 
        int index;
        switch (opt) {
        case 1: agregar_alumno();
            break;
        case 2: modificar_alumno();
            break;
        case 3: //menu_modicar_calificacion(&opt, &opt, &opt, &opt);
                menu_modicar_calificacion2(calificaciones);
            break;
        case 4: index = posicion_alumno_imprimir();
                imprimir_alumno(index);
            break;
        case 5: pase_lista();
            break;
        case 6: busqueda_matricula();
            break;
        case 7:
            break;
        default:
            break;
        }
    }
    return 0;
}

void busqueda_matricula(){
    int matricula;
    printf("\tBusqueda por matricula:\n");
    printf("Ingresar matricula del alumno: ");
    scanf("%d", &matricula);
    int posicion = busqueda_secuencial(matricula);
    if (posicion == -1){
        printf("Matricula no coincide con ningun alumno...\n\n");
    } else {
        imprimir_alumno(posicion);
    }
    printf("Presiona cualquier tecla para continuar....");
    fflush(stdin);
    getchar();
    //system("PAUSE");
}

int busqueda_secuencial(int matricula){
    for (int i = 0; i < MAX_ALUMNOS; i++){
        if(matriculas[i] == matricula){
            return i;
        } 
    }
    return -1;
}