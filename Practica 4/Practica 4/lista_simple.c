#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, m;
    int error = 0; // bandera para validar errores

    // Paso 1: malloc
    printf("Cuantos enteros quieres almacenar con malloc? n = ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Entrada invalida para n.\n");
        error = 1;
    }

    int *arr = NULL;
    if (!error) 
    {
        arr = (int *)malloc(n * sizeof(int));
        if (!arr) 
        {
            printf("Error: no se pudo reservar memoria con malloc.\n");
            error = 1;
        }
    }

    if (!error) 
    {
        printf("\n[Paso 1] Valores iniciales con malloc (basura o indefinidos):\n");
        for (int i = 0; i < n; i++) 
        {
            printf("arr[%d] = %d\n", i, arr[i]);
        }
    }

    // Paso 2: calloc
    if (!error) 
    {
        printf("\nCuantos enteros quieres almacenar con calloc? n = ");
        if (scanf("%d", &n) != 1 || n <= 0) 
        {
            printf("Entrada invalida para n.\n");
            error = 1;
        }
    }

    int *arr2 = NULL;
    if (!error) 
    {
        arr2 = (int *)calloc(n, sizeof(int));
        if (!arr2) 
        {
            printf("Error: no se pudo reservar memoria con calloc.\n");
            error = 1;
        }
    }

    if (!error) 
    {
        printf("\n[Paso 2] Valores iniciales con calloc (deben ser 0):\n");
        for (int i = 0; i < n; i++) 
        {
            printf("arr2[%d] = %d\n", i, arr2[i]);
        }
    }

    // Paso 3: llenar arr2
    if (!error) 
    {
        printf("\n[Paso 3] Ingresa %d valores enteros para arr2:\n", n);
        for (int i = 0; i < n; i++) 
        {
            printf("arr2[%d] = ", i);
            if (scanf("%d", &arr2[i]) != 1)
{
                printf("Entrada invalida. Terminando.\n");
                error = 1;
                break;
            }
        }
    }

    // Paso 4: realloc
    if (!error) 
    {
        printf("\n[Paso 4] Ingresa el nuevo tamano m para arr2: m = ");
        if (scanf("%d", &m) != 1 || m <= 0) 
        {
            printf("Entrada invalida para m.\n");
            error = 1;
        }
    }

    if (!error) 
    {
        int old_n = n;
        int *tmp = (int *)realloc(arr2, m * sizeof(int));
        if (!tmp) 
        {
            printf("Error: no se pudo redimensionar con realloc.\n");
            error = 1;
        } 
        else 
        {
            arr2 = tmp;
            n = m;

            if (n > old_n) 
            {
                printf("\nEl nuevo tamano es mayor. Ingresa %d valores adicionales:\n", n - old_n);
                for (int i = old_n; i < n; i++) 
                {
                    printf("arr2[%d] = ", i);
                    if (scanf("%d", &arr2[i]) != 1) 
                    {
                        printf("Entrada invalida. Terminando.\n");
                        error = 1;
                        break;
                    }
                }
            } 
            else 
            {
                printf("\nEl nuevo tamano es menor o igual, se han descartado elementos si m < tamaño anterior.\n");
            }
        }
    }

    if (!error) 
    {
        printf("\nContenido final de arr2 (%d elementos):\n", n);
        for (int i = 0; i < n; i++) 
        {
            printf("arr2[%d] = %d\n", i, arr2[i]);
        }
    }

    // Paso 5: free
    if (arr != NULL) free(arr);
    if (arr2 != NULL) free(arr2);

    printf("\nMemoria liberada correctamente.\n");

    return 0;
}

