#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h> 
#include <ctype.h>

#define MAX_ASISTENCIA 5
#define MAX_CALIFICACIONES 4
#define MAX_ALUMNOS 5
#define MAX_GRUPOS 10
#define MAX 25
#define DIV_2 2.0
#define MAX_NOM 60
#define prom_parcial(cal1, cal2, cal3) ((cal1 + cal2 + cal3) / 3.0)



struct estudiant_ {
    int matricula;
    char nombre[MAX_ALUMNOS];
    float calificaciones[MAX_CALIFICACIONES];
    int asistencias[MAX_ASISTENCIA];
};

typedef struct estudiant_ estudiante;

struct grup_ {
    char id[4];
    int semestre;
    int num_estudiantes;
    estudiante lista_estudiantes[MAX_ALUMNOS];
};

typedef struct grup_ grupo;

grupo lista_grupos[MAX_GRUPOS];

void menu_inicial();
void menu_grupo();
void imprimir_menu_modificar_calificacion();
int imprimir_solitar_posicion_alumno();
void imprimir_mensaje(const char *p_mensaje);
void imprimir_alumno(const int posicion);
void imprimir_asistencia(const int posicion);
void imprimir_calificaciones(const int posicion);
void busqueda_matricula();
int busqueda_secuencial(int matricula);
int buscar_grupo_id(char *id[]);

void agregar_grupo();
void seleecionar_grupo();
void gestion_alumnos();
void agregar_alumno();
void modificar_nombre_alumno();
void menu_modicar_calificacion();
void pase_lista();

float promedio(float *cal);
float minimo(float *c);
float maximo(float *c);

void inicializar_calificaciones(float *cal);
void convertir_mayusculas(char *p_cadena);

int siguiente_estudiante = 0;
int siguiente_grupo = 0;

char grupo_seleccionado[4];
int indice_grupo_seleccionado;

estudiante lista_estudiantes[MAX_ALUMNOS];

int main(){
    int opt = 0;
    while(opt != 4) {
        menu_inicial();
        printf("Ingresar una opción: ");
        scanf("%d", &opt);
        switch (opt) {
        case 1: agregar_grupo();
            break;
        
        case 4: seleecionar_grupo();
                gestion_alumnos();
            break;
        case 5: return 0;
            break;
    
        default:
            break;
        }

        
    }
     
    
    return 0;
}

void gestion_alumnos(){
    int opt = 0;
    while( opt != 7) {
        menu_grupo();
        printf("Ingresa un opción: ");
        scanf("%d", &opt); 
        int index;
        switch (opt)
        {
        case 1: agregar_alumno();
            break;
        case 2: modificar_nombre_alumno();
            break;
        case 3: menu_modicar_calificacion();
            break;
        case 4: index = imprimir_solitar_posicion_alumno();
                imprimir_alumno(index);
            break;
        case 5: pase_lista(siguiente_estudiante);
            break;
        case 6: busqueda_matricula();
            break;
        
        default:
            break;
        }
    }
}

void menu_grupo(){
    system("clear");
    imprimir_mensaje("SISTEMA DE CONTROL ESCOLAR\n");
    printf("Grupo seleccionado: %s\n", grupo_seleccionado);
    printf("------------------------------------------------------\n");
    printf("\t\tMenu de opciones. \n");
    printf("------------------------------------------------------\n");
    printf("1.- Agregar datos del alumno.\n");
    printf("2.- Modificar nombre del alumno.\n");
    printf("3.- Ingresar calificaciones del alumno.\n");
    printf("4.- Mostrar datos del alumno.\n");
    printf("5.- Pase de lista\n");
    printf("6.- Búsqueda de alumno por matrícula\n");
    printf("7.- Salir\n\n");        
}

void agregar_grupo(){
    grupo grupo_nuevo;
    system("clear");
    if (siguiente_grupo == MAX_GRUPOS) {
        printf("------------------------------------------------------\n");
        printf("Espacio insuficiente para almancenar más alumnos\n");
        printf("------------------------------------------------------\n");
    } else {
        printf("------------------------------------------------------\n");
        printf("\t\t\t... Nuevo grupo.\n");
        printf("------------------------------------------------------\n");
        printf("Ingresar id del grupo: ");
        //char id_grupo[4];
        fflush(stdin);
        fgets(grupo_nuevo.id, 4, stdin);
        //strcpy(grupo_nuevo.id, id_grupo);
        printf("Ingresar semetre: ");
        fflush(stdin);
        scanf("%d", &grupo_nuevo.semestre);
        grupo_nuevo.num_estudiantes = 0;
        puts("Datos almacenado correctamente...");
        puts("Presiona cualquier tecla para continuar...");
        fflush(stdin);
        getchar();
        lista_grupos[siguiente_grupo] = grupo_nuevo;
        siguiente_grupo++;
    } 
}

void agregar_alumno(){
    estudiante estudiante_nuevo;
    system("clear");
    if (siguiente_estudiante == 5) {
        printf("------------------------------------------------------\n");
        printf("Espacio insuficiente para almancenar más alumnos\n");
        printf("------------------------------------------------------\n");
    } else {
        printf("------------------------------------------------------\n");
        printf("\t\t\t... Nuevo alumno.\n");
        printf("------------------------------------------------------\n");
        printf("Ingresar matricula: ");
        scanf("%d", &estudiante_nuevo.matricula);
        printf("Ingresar nombre: ");
        fflush(stdin);
        fgets(estudiante_nuevo.nombre, MAX_NOM, stdin);
        inicializar_calificaciones(estudiante_nuevo.calificaciones);
        puts("Datos almacenado correctamente...");
        puts("Presiona cualquier tecla para continuar...");
        fflush(stdin);
        getchar();
        lista_estudiantes[siguiente_estudiante] = estudiante_nuevo;
        siguiente_estudiante++;
    }
}

void modificar_nombre_alumno(){
    int posicion;
    puts("Menu para modificar nombre del alumno.");
    printf("Indica la posicion [1 - %d]:", MAX_ALUMNOS);
    scanf("%d", &posicion);
    printf("Nombre actual: %s\n", lista_estudiantes[posicion - 1].nombre);
    fflush(stdin);
    puts("Ingresar nombre: ");
    fgets(lista_estudiantes[posicion - 1].nombre, MAX_NOM, stdin);
}

void imprimir_menu_modificar_calificacion(){
    system("clear");
        printf("------------------------------------------------------\n");
        printf("\t\t\t... Menu de cambio de califaciones. \n");
        printf("------------------------------------------------------\n");
        printf("1.- Modificar calificación 1:\n");
        printf("2.- Modificar calificación 2:\n");
        printf("3.- Modificar calificación 3:\n");
        printf("4.- Modificar calificación final:\n");
        printf("5.- Salir\n\n");
}

void menu_modicar_calificacion(){
    int op = 0;
    int posicion = imprimir_solitar_posicion_alumno();
    while (op != 5) {
        imprimir_menu_modificar_calificacion();
        printf("Ingresa una opción: ");
        scanf("%d", &op);  
        if (op < 5){
            printf("Ingregar calificación %d: ", op);
            scanf("%f", &lista_estudiantes[posicion].calificaciones[op-1]);
        }  
    }  
}

int imprimir_solitar_posicion_alumno(){
    int posicion;

    printf("Indicar la posición del alumno [1 - %d]:", MAX_ALUMNOS);
    scanf("%d", &posicion);
    posicion--;
    return posicion;
}

void imprimir_alumno(const int posicion){
    float m = 0;
    system("clear");
    printf("------------------------------------------------------\n");
    printf("\t\t\tDatos del alumno \n");
    printf("------------------------------------------------------\n");
    printf("Matricula: \t%d\n", lista_estudiantes[posicion].matricula);
    convertir_mayusculas(lista_estudiantes[posicion].nombre);
    printf("Nombre: \t%s\n", lista_estudiantes[posicion].nombre);
    
    printf("Asistencias: \n");
    imprimir_asistencia(posicion);
    imprimir_calificaciones(posicion);

    puts("\n\nPresiona cualquier tecla para continuar...");
    fflush(stdin);
    getchar();
}

void imprimir_calificaciones(const int posicion){
    float m = 0.0;
    for (int i = 0; i < MAX_CALIFICACIONES; i++){
        printf("Calificacion %d :\t%.2f\n", i + 1, lista_estudiantes[posicion].calificaciones[i]);
    }
    float prom = promedio(lista_estudiantes[posicion].calificaciones);
    printf("Promedio: %.2f\n", prom);
    m = minimo(lista_estudiantes[posicion].calificaciones);
    printf("La calificación mínima: %.2f\n", m);
    m = maximo(lista_estudiantes[posicion].calificaciones);
    printf("La calificación máxima: %.2f\n", m);
}

void imprimir_asistencia(const int posicion){
    int i;
    for(i = 0; i < MAX_ASISTENCIA - 1; i++){
        if (lista_estudiantes[posicion].asistencias[i] == 1)
            printf("A, ");
        else{
            if (lista_estudiantes[posicion].asistencias[i] == -1)
                printf("*, ");
            else{
                printf("F, ");
            }  
        }       
    }
    if(lista_estudiantes[posicion].asistencias[MAX_ASISTENCIA-1] == 1) 
        printf("A");
    else
        if(lista_estudiantes[posicion].asistencias[MAX_ASISTENCIA-1] == -1) 
            printf("*");
        else
            printf("F");
    printf("\n");
}

void imprimir_mensaje(const char *p_mensaje){
    //char mensajito[] = {"holi"};
    //*p_mensaje = mensajito;
    for (; *p_mensaje != '\0'; ++p_mensaje){
        printf("%c", *p_mensaje);
    }
}

float promedio(float *cal){
    float cal_total = (cal[0] + cal[1] + cal[2]) / 3.0;
    float cal_f = (cal_total + cal[3]) / DIV_2;
    return cal_f;
}

float minimo(float *c){
    float min = *(c + 0);
    for (int i = 1; i < MAX_CALIFICACIONES; i++){
        if (min > *(c + i))
            min = *(c + i);
    }
    return min;
}

float maximo(float *c){
    float max = *(c + 0);
    for (int i = 1; i < MAX_CALIFICACIONES; i++){
        if (max < *(c + i)){ 
            max = *(c + i);
        }   
    }
    return max;
}

void convertir_mayusculas(char *p_cadena){
    while(*p_cadena != '\0'){
        *p_cadena = toupper(*p_cadena);
        ++p_cadena;
    }
}

void pase_lista(int limite){
    int dia;
    printf("Día de la semana de pase lista [1 - %d]:", MAX_ASISTENCIA);
    scanf("%d", &dia);
    for (int i = 0; i < limite; i++){
        printf("%s [Asistencia = 1 o Falta = 0]", lista_estudiantes[i].nombre);
        scanf("%d", &lista_estudiantes[i].asistencias[dia - 1]);
    }
}

void inicializar_calificaciones(float *cal){
    for (int i = 0; i < MAX_CALIFICACIONES; i++){
        cal[i] = 0.0;
    }
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
        if(lista_estudiantes[i].matricula == matricula){
            return i;
        } 
    }
    return -1;
}

void menu_inicial(){
    system("clear");
    imprimir_mensaje("SISTEMA DE CONTROL ESCOLAR\n");
    printf("------------------------------------------------------\n");
    printf("\t\tMenu de opciones. \n");
    printf("------------------------------------------------------\n");
    printf("1.- Agregar datos de un grupo.\n");
    printf("2.- Modificar datos de un grupo.\n");
    printf("3.- Imprimir grupos.\n");
    printf("4.- Seleccionar un grupo\n");
    printf("5.- Salir\n\n");   
}

void seleecionar_grupo(){
    char id_grupo[4];
    system("clear");
    if (siguiente_grupo == 0) {
        printf("No existen grupos, es necesario crear al menos uno...");
        printf("Presiona cualquier tecla para continuar....");
        fflush(stdin);
        getchar();
    } else {
        while(1) {
            printf("Selecciona el id del grupo a gestionar:\n");
            fflush(stdin);
            scanf("%s", grupo_seleccionado);
            int r = buscar_grupo_id(grupo_seleccionado);
            if ( r >= 0){
                printf("Grupo %s seleccionado.\n", grupo_seleccionado);
                printf("Presiona cualquier tecla para continuar....");
                fflush(stdin);
                getchar();
                break;
            } 
        }
        
    }
}

int buscar_grupo_id(char *id[]){
    for (int i = 0; i < MAX_GRUPOS; i++) {
        printf("%s\n", lista_grupos[i].id );
        printf("%s\n", id);
        if ( !strcmp(lista_grupos[i].id, id) ){
            return i;
        } 
    }
    return -1;
}