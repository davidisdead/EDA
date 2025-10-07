#include <stdio.h>
#include <stdlib.h>

// Función para calcular el promedio de las calificaciones
float promedio(float *a, int n) 
{
    float suma = 0;
    int i;
    for (i = 0; i < n; i++) 
    {
        suma += a[i]; // Acumula todas las calificaciones
    }
    if (n > 0)
        return suma / n; // Retorna el promedio
    else
        return 0;
}

int main() 
{
    int n, agregar, i;
    float *cal; // Puntero para almacenar calificaciones dinámicamente

    // 1. Pedir cuántos estudiantes se desean registrar
    printf("¿Cuántos estudiantes deseas registrar? ");
    scanf("%d", &n);

    // Validar entrada
    if (n <= 0) 
    {
        printf("Cantidad no válida.\n");
        return 0;
    }

    // 2. Reservar memoria dinámicamente con malloc()
    cal = (float*)malloc(n * sizeof(float));
    if (cal == NULL) { // Verificar si malloc falló
        printf("Error de memoria.\n");
        return 0;
    }

    // 3. Capturar las calificaciones
    for (i = 0; i < n; i++) 
    {
        printf("Calificación del estudiante %d: ", i + 1);
        scanf("%f", &cal[i]);
    }

    // 4. Calcular y mostrar el promedio inicial
    printf("Promedio inicial: %.2f\n", promedio(cal, n));

    // 5. Preguntar si se desea agregar más estudiantes
    printf("¿Deseas agregar más estudiantes? (cantidad, 0 para no): ");
    scanf("%d", &agregar);

    // Si el usuario quiere agregar más estudiantes
    if (agregar > 0) 
    {
        int nuevo_tamano = n + agregar;

        // 5. Usar realloc() para ampliar el tamaño del arreglo
        float *tmp = (float*)realloc(cal, nuevo_tamano * sizeof(float));

        // Verificar si realloc falló
        if (tmp == NULL) 
        {
            printf("Error de memoria.\n");
            free(cal); // Liberar la memoria anterior antes de salir
            return 0;
        }

        cal = tmp; // Asignar el nuevo bloque de memoria

        // 6. Capturar las nuevas calificaciones
        for (i = n; i < nuevo_tamano; i++) 
        {
            printf("Calificación del estudiante %d: ", i + 1);
            scanf("%f", &cal[i]);
        }

        // Actualizar el tamaño total
        n = nuevo_tamano;
    }

    // 6. Mostrar todas las calificaciones y el promedio final
    printf("=== Calificaciones registradas ===\n");
    for (i = 0; i < n; i++) {
        printf("Estudiante %d: %.2f\n", i + 1, cal[i]);
    }

    printf("Promedio general: %.2f\n", promedio(cal, n));

    // 7. Liberar la memoria utilizada
    free(cal);
    printf("Memoria liberada correctamente\n");

    return 0;
}