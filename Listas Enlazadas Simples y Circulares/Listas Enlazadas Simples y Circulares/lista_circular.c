#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definicion del nodo para lista circular simple
struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

typedef struct Nodo Nodo;

// Prototipos
void mostrarCircular(Nodo *cabeza);
void insertarInicioCircular(Nodo **cabeza, Nodo **ultimo, int valor);
void eliminarCircular(Nodo **cabeza, Nodo **ultimo, int valor);
void liberarListaCircular(Nodo **cabeza, Nodo **ultimo);

// Muestra la lista circular deteniendose cuando vuelve a la cabeza
void mostrarCircular(Nodo *cabeza) {
    if (cabeza == NULL) {
        printf("Lista vacia\n");
        return;
    }
    Nodo *actual = cabeza;
    do {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    } while (actual != cabeza);
    printf("\n");
}

// Inserta un nodo al inicio manteniendo la circularidad y actualizando cabeza y ultimo
void insertarInicioCircular(Nodo **cabeza, Nodo **ultimo, int valor) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (!nuevo) {
        fprintf(stderr, "Error: no se pudo asignar memoria.\n");
        exit(EXIT_FAILURE);
    }
    nuevo->dato = valor;

    if (*cabeza == NULL) {
        // Primer nodo: se apunta a si mismo
        nuevo->siguiente = nuevo;
        *cabeza = nuevo;
        *ultimo = nuevo;
    } else {
        // Insertar al inicio: nuevo->siguiente = cabeza actual
        nuevo->siguiente = *cabeza;
        // El ultimo debe apuntar al nuevo inicio para mantener circularidad
        (*ultimo)->siguiente = nuevo;
        // Actualizar cabeza
        *cabeza = nuevo;
    }
}

// Elimina un nodo con el valor dado en una lista circular
// Reglas:
// - Busca el nodo a eliminar y su anterior.
// - Si es el primero (cabeza), actualizar el puntero del ultimo.
// - Si es intermedio, enlazar su anterior con su siguiente.
// - Liberar la memoria del nodo eliminado.
void eliminarCircular(Nodo **cabeza, Nodo **ultimo, int valor) {
    if (cabeza == NULL || *cabeza == NULL) {
        printf("La lista esta vacia, nada que eliminar.\n");
        return;
    }

    Nodo *actual = *cabeza;
    Nodo *anterior = *ultimo; // En circular, anterior de cabeza es ultimo

    // Recorremos hasta volver a la cabeza o encontrar el valor
    do {
        if (actual->dato == valor) {
            // Caso: unico nodo en la lista
            if (actual == *cabeza && actual == *ultimo) {
                *cabeza = NULL;
                *ultimo = NULL;
            } else {
                // Saltar el nodo actual
                anterior->siguiente = actual->siguiente;
                // Si eliminamos la cabeza, mover cabeza al siguiente y ajustar ultimo->siguiente
                if (actual == *cabeza) {
                    *cabeza = actual->siguiente;
                    (*ultimo)->siguiente = *cabeza;
                }
                // Si eliminamos el ultimo, mover ultimo al anterior
                if (actual == *ultimo) {
                    *ultimo = anterior;
                }
            }
            free(actual);
            printf("Valor %d eliminado.\n", valor);
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    } while (actual != *cabeza);

    printf("Valor %d no encontrado en la lista.\n", valor);
}

void liberarListaCircular(Nodo **cabeza, Nodo **ultimo) {
    if (cabeza == NULL || *cabeza == NULL) return;
    Nodo *actual = *cabeza;
    do {
        Nodo *tmp = actual;
        actual = actual->siguiente;
        free(tmp);
    } while (actual != *cabeza);
    *cabeza = NULL;
    *ultimo = NULL;
}

int main(void) {
    Nodo *cabeza = NULL;
    Nodo *ultimo = NULL;

    int n;
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
            liberarListaCircular(&cabeza, &ultimo);
            return EXIT_FAILURE;
        }
        insertarInicioCircular(&cabeza, &ultimo, valor);
        printf("Lista despues de la insercion: ");
        mostrarCircular(cabeza);
    }

    // Demostracion de recorrido circular (ya usado en mostrarCircular)
    printf("Recorrido circular completo: ");
    mostrarCircular(cabeza);

    // Probar eliminaciones
    int eliminar;
    while (1) {
        printf("Ingrese un valor a eliminar (o 'q' para salir): ");
        int c = getchar();
        if (c == '\n') c = getchar();
        if (c == 'q' || c == 'Q') {
            break;
        } else {
            ungetc(c, stdin);
            if (scanf("%d", &eliminar) == 1) {
                eliminarCircular(&cabeza, &ultimo, eliminar);
                printf("Lista actual: ");
                mostrarCircular(cabeza);
            } else {
                // limpiar buffer hasta fin de linea
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF) {}
                printf("Entrada no valida. Intente de nuevo.\n");
            }
        }
    }

    liberarListaCircular(&cabeza, &ultimo);
    return 0;
}
