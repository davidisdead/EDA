#include <stdio.h>

// Algoritmo Divide y Vencerás: Búsqueda Binaria Recursiva
int busquedaBinaria(int arr[], int inicio, int fin, int objetivo)
{

    // ----- CASO BASE -----
    if (inicio > fin)
    {
        return -1; // No encontrado
    }

    int medio = (inicio + fin) / 2;

    // Si el elemento está en el medio
    if (arr[medio] == objetivo)
    {
        return medio;
    }

    // ----- DIVIDIR Y VENCER -----
    // Si el objetivo es menor, buscar en la mitad izquierda
    if (objetivo < arr[medio])
    {
        return busquedaBinaria(arr, inicio, medio - 1, objetivo);
    }
    // Si es mayor, buscar en la mitad derecha
    else
    {
        return busquedaBinaria(arr, medio + 1, fin, objetivo);
    }
}

int main()
{
    int arreglo[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);

    int objetivo = 23;

    int resultado = busquedaBinaria(arreglo, 0, n - 1, objetivo);

    if (resultado != -1)
    {
        printf("Elemento %d encontrado en la posicion %d\n", objetivo, resultado);
    }
    else
    {
        printf("Elemento no encontrado\n");
    }

    return 0;
}
