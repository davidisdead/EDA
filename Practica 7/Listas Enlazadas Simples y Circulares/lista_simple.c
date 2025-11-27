#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Estructura del nodo para lista simple
struct Nodo {
    int dato;
    struct Nodo *siguiente;
};
// Inserta un nuevo nodo al inicio de la lista
void insertarInicio(struct Nodo **cabeza, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        fprintf(stderr, "Error: no se pudo asignar memoria para el nuevo nodo.\n");
        exit(EXIT_FAILURE);
    }
    nuevo->dato = valor;
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

// Recorre la lista e imprime sus valores
void recorrer(struct Nodo *cabeza) {
    struct Nodo *actual = cabeza;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

// Elimina la primera ocurrencia de 'valor' en la lista
bool eliminar(struct Nodo **cabeza, int valor) {
    if (cabeza == NULL || *cabeza == NULL) {
        return false;
    }

    // Caso: el valor está en la cabeza
    if ((*cabeza)->dato == valor) {
        struct Nodo *temp = *cabeza;
        *cabeza = (*cabeza)->siguiente;
        free(temp);
        return true;
    }

    // Buscar en el resto de la lista manteniendo referencia al anterior
    struct Nodo *anterior = *cabeza;
    struct Nodo *actual = (*cabeza)->siguiente;

    while (actual != NULL && actual->dato != valor) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        // No se encontro el valor
        return false;
    }

    // Desenganchar el nodo encontrado y liberarlo
    anterior->siguiente = actual->siguiente;
    free(actual);
    return true;
}

// Libera toda la memoria de la lista
void liberar(struct Nodo *cabeza) {
    struct Nodo *actual = cabeza;
    while (actual != NULL) {
        struct Nodo *temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
}

int main(void) {
    // Paso 1: creacion de la estructura y puntero cabeza inicializado en NULL
    struct Nodo *cabeza = NULL;

    // Paso 2: Insercion
    int n = 0;
    printf("Cuantos valores desea insertar? ");
    if (scanf("%d", &n) != 1 || n < 0) {
        fprintf(stderr, "Entrada invalida.\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < n; ++i) {
        int valor;
        printf("Inserte el valor %d: ", i + 1);
        if (scanf("%d", &valor) != 1) {
            fprintf(stderr, "Entrada invalida.\n");
            liberar(cabeza);
            return EXIT_FAILURE;
        }
        insertarInicio(&cabeza, valor);
        printf("Lista despues de la insercion %d: ", i + 1);
        recorrer(cabeza);
    }

    // Paso 3: Recorrido y eliminacion
    printf("\nRecorrido final de la lista: ");
    recorrer(cabeza);

    int aEliminar;
    printf("Ingrese el valor a eliminar: ");
    if (scanf("%d", &aEliminar) != 1) {
        fprintf(stderr, "Entrada invalida.\n");
        liberar(cabeza);
        return EXIT_FAILURE;
    }

    bool eliminado = eliminar(&cabeza, aEliminar);
    if (eliminado) {
        printf("Valor %d eliminado. Lista actualizada: ", aEliminar);
    } else {
        printf("Valor %d no encontrado. Lista sin cambios: ", aEliminar);
    }
    recorrer(cabeza);

    // Paso 4: Liberacion de memoria
    liberar(cabeza);
    printf("Memoria liberada correctamente\n");

    return 0;
}


