#include <stdio.h>
#include <stdlib.h>

//Funcion para calcular el promedio de las calificaciones
float promedio(float *a, int n) 
{
    float suma = 0;
    int i;
    for (i = 0; i < n; i++) 
    {
        suma += a[i]; //Acumula todas las calificaciones
    }
    if (n > 0)
        return suma / n; //Retorna el promedio
    else
        return 0;
}

int main() 
{
    int n, agregar, i;
    float *cal; //Puntero para almacenar calificaciones dinamicamente

    //Pedir cuantos estudiantes se desean registrar
    printf("¿Cuantos estudiantes deseas registrar? ");
    scanf("%d", &n);

    //Validar entrada
    if (n <= 0) 
    {
        printf("Cantidad no valida.\n");
        return 0;
    }

    //Reservar memoria dinamicamente con malloc()
    cal = (float*)malloc(n * sizeof(float));
    if (cal == NULL) { // Verificar si malloc fallo
        printf("Error de memoria.\n");
        return 0;
    }

    //Capturar las calificaciones
    for (i = 0; i < n; i++) 
    {
        printf("Calificacion del estudiante %d: ", i + 1);
        scanf("%f", &cal[i]);
    }

    //Calcular y mostrar el promedio inicial
    printf("Promedio inicial: %.2f\n", promedio(cal, n));

    //Preguntar si se desea agregar mas estudiantes
    printf("¿Deseas agregar mas estudiantes? (cantidad, 0 para no): ");
    scanf("%d", &agregar);

    //Si el usuario quiere agregar mas estudiantes
    if (agregar > 0) 
    {
        int nuevoTamano = n + agregar;

        //Usar realloc() para ampliar el tamaño del arreglo
        float *tmp = (float*)realloc(cal, nuevoTamano * sizeof(float));

        //Verificar si realloc fallo
        if (tmp == NULL) 
        {
            printf("Error de memoria.\n");
            free(cal); // Liberar la memoria anterior antes de salir
            return 0;
        }

        cal = tmp; //Asignar el nuevo bloque de memoria

        //Capturar las nuevas calificaciones
        for (i = n; i < nuevoTamano; i++) 
        {
            printf("Calificacion del estudiante %d: ", i + 1);
            scanf("%f", &cal[i]);
        }

        //Actualizar el tamaño total
        n = nuevoTamano;
    }

    //Mostrar todas las calificaciones y el promedio final
    printf("=== Calificaciones registradas ===\n");
    for (i = 0; i < n; i++) {
        printf("Estudiante %d: %.2f\n", i + 1, cal[i]);
    }

    printf("Promedio general: %.2f\n", promedio(cal, n));

    //Liberar la memoria utilizada
    free(cal);
    printf("Memoria liberada correctamente\n");

    return 0;
}