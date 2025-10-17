// lista_circular.c
// Misma práctica: malloc, calloc, realloc y free con enteros (interfaz idéntica)

#include <stdio.h>
#include <stdlib.h>

/*int main(void) {
    int n, m;

    // Paso 1: malloc
    printf("¿Cuántos enteros quieres almacenar con malloc? n = ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Entrada inválida para n.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        fprintf(stderr, "Error: no se pudo reservar memoria con malloc.\n");
        return 1;
    }

    printf("\n[Paso 1] Valores iniciales con malloc (basura/indefinidos):\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // Paso 2: calloc
    printf("\n¿Cuántos enteros quieres almacenar con calloc? n = ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Entrada inválida para n.\n");
        free(arr);
        return 1;
    }

    int *arr2 = (int *)calloc(n, sizeof(int));
    if (!arr2) {
        fprintf(stderr, "Error: no se pudo reservar memoria con calloc.\n");
        free(arr);
        return 1;
    }

    printf("\n[Paso 2] Valores iniciales con calloc (deben ser 0):\n");
    for (int i = 0; i < n; i++) {
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }

    // Paso 3: llenar arr2
    printf("\n[Paso 3] Ingresa %d valores enteros para arr2:\n", n);
    for (int i = 0; i < n; i++) {
        printf("arr2[%d] = ", i);
        if (scanf("%d", &arr2[i]) != 1) {
            fprintf(stderr, "Entrada inválida. Terminando.\n");
            free(arr);
            free(arr2);
            return 1;
        }
    }

    // Paso 4: realloc
    printf("\n[Paso 4] Ingresa el nuevo tamaño m para arr2: m = ");
    if (scanf("%d", &m) != 1 || m <= 0) {
        fprintf(stderr, "Entrada inválida para m.\n");
        free(arr);
        free(arr2);
        return 1;
    }

    int old_n = n;
    int *tmp = (int *)realloc(arr2, m * sizeof(int));
    if (!tmp) {
        fprintf(stderr, "Error: no se pudo redimensionar con realloc.\n");
        free(arr);
        free(arr2);
        return 1;
    }
    arr2 = tmp;
    n = m;

    if (n > old_n) {
        printf("\nEl nuevo tamaño es mayor. Ingresa %d valores adicionales:\n", n - old_n);
        for (int i = old_n; i < n; i++) {
            printf("arr2[%d] = ", i);
            if (scanf("%d", &arr2[i]) != 1) {
                fprintf(stderr, "Entrada inválida. Terminando.\n");
                free(arr);
                free(arr2);
                return 1;
            }
        }
    } else {
        printf("\nEl nuevo tamaño es menor o igual, se han descartado elementos si m < tamaño anterior.\n");
    }

    printf("\nContenido final de arr2 (%d elementos):\n", n);
    for (int i = 0; i < n; i++) {
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }

    // Paso 5: free
    free(arr);
    free(arr2);
    printf("\nMemoria liberada correctamente.\n");

    return 0;
}
*/
