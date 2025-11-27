#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

// Prototipos
void insertarFinalCircular(struct Nodo **inicio, int valor);
void recorrerCircular(struct Nodo *inicio);
void eliminarCircular(struct Nodo **inicio, int valor);
void liberarCircular(struct Nodo **inicio);

int main() {
    struct Nodo *inicio = NULL;   // Puntero al primer nodo
    int n, i, valor, valorEliminar;

    // ----- Paso B2: Inserción circular al final -----
    printf("¿Cuantos valores deseas insertar en la lista circular? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarFinalCircular(&inicio, valor);
    }

    printf("\nRecorrido circular (hacia adelante) desde el inicio:\n");
    recorrerCircular(inicio);

    // ----- Paso B4: Eliminación circular -----
    printf("\nIngresa el valor a eliminar en la lista circular: ");
    scanf("%d", &valorEliminar);

    eliminarCircular(&inicio, valorEliminar);

    printf("\nLista circular despues de la eliminacion:\n");
    recorrerCircular(inicio);

    // ----- Liberar toda la lista circular -----
    liberarCircular(&inicio);
    printf("\nMemoria liberada correctamente.\n");

    return 0;
}

// Inserta un nodo al final de la lista doblemente ligada circular
void insertarFinalCircular(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error al reservar memoria.\n");
        return;
    }

    nuevo->dato = valor;

    if (*inicio == NULL) {
        // Primer nodo: se apunta a sí mismo en anterior y siguiente
        nuevo->siguiente = nuevo;
        nuevo->anterior  = nuevo;
        *inicio = nuevo;
    } else {
        struct Nodo *ultimo = (*inicio)->anterior; // El anterior del inicio es el último

        // Enlaces del nuevo nodo
        nuevo->siguiente = *inicio;   // siguiente al primero
        nuevo->anterior  = ultimo;    // anterior al último

        // Actualizar enlaces del último y del primero
        ultimo->siguiente  = nuevo;
        (*inicio)->anterior = nuevo;
    }
}

// Recorre la lista circular desde el primer nodo hasta volver al inicio
void recorrerCircular(struct Nodo *inicio) {
    if (inicio == NULL) {
        printf("Lista vacia.\n");
        return;
    }

    struct Nodo *temp = inicio;

    do {
        printf("%d ", temp->dato);
        temp = temp->siguiente;
    } while (temp != inicio);

    printf("\n");
}

// Elimina un nodo con cierto valor en la lista circular
void eliminarCircular(struct Nodo **inicio, int valor) {
    if (*inicio == NULL) {
        printf("La lista esta vacia, no se puede eliminar.\n");
        return;
    }

    struct Nodo *actual = *inicio;
    int encontrado = 0;

    // Buscar el nodo que contenga el valor (recorrido circular)
    do {
        if (actual->dato == valor) {
            encontrado = 1;
            break;
        }
        actual = actual->siguiente;
    } while (actual != *inicio);

    if (!encontrado) {
        printf("Valor %d no encontrado en la lista circular.\n", valor);
        return;
    }

    // Caso 1: es el único nodo en la lista
    if (actual->siguiente == actual && actual->anterior == actual) {
        free(actual);
        *inicio = NULL;
        printf("Nodo con valor %d eliminado (era el unico nodo).\n", valor);
        return;
    }

    // Caso 2: es el primer nodo, pero hay más nodos
    if (actual == *inicio) {
        struct Nodo *ultimo = (*inicio)->anterior;

        *inicio = (*inicio)->siguiente;   // mover inicio al siguiente nodo

        // Ajustar punteros del nuevo inicio y del ultimo
        ultimo->siguiente  = *inicio;
        (*inicio)->anterior = ultimo;
    } else {
        // Caso 3: nodo en medio o último
        actual->anterior->siguiente = actual->siguiente;
        actual->siguiente->anterior = actual->anterior;
        // Esto funciona también si es el último nodo (porque el siguiente será inicio)
    }

    free(actual);
    printf("Nodo con valor %d eliminado.\n", valor);
}

// Libera toda la memoria de la lista circular
void liberarCircular(struct Nodo **inicio) {
    if (*inicio == NULL) {
        return;
    }

    struct Nodo *actual = (*inicio)->siguiente;
    struct Nodo *temp;

    // Liberar desde el segundo nodo hasta volver al inicio
    while (actual != *inicio) {
        temp = actual;
        actual = actual->siguiente;
        free(temp);
    }

    // Liberar el nodo de inicio
    free(*inicio);
    *inicio = NULL;
}
