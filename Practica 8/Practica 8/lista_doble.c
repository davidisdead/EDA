#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

// Prototipos
void insertarInicio(struct Nodo **inicio, int valor);
void insertarFinal(struct Nodo **inicio, int valor);
void recorrerAdelante(struct Nodo *inicio);
void recorrerAtras(struct Nodo *inicio);
void eliminar(struct Nodo **inicio, int valor);
void liberar(struct Nodo *inicio);

int main() {
    struct Nodo *inicio = NULL;   // Paso A1: puntero inicio inicializado en NULL
    int n, i, valor, valorEliminar;

    // ----- Paso A2: Inserción al inicio -----
    printf("¿Cuantos valores deseas insertar al inicio? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Valor %d (inicio): ", i + 1);
        scanf("%d", &valor);
        insertarInicio(&inicio, valor);
    }

    printf("\nLista recorriendo hacia adelante (despues de insertar al inicio):\n");
    recorrerAdelante(inicio);

    printf("\nLista recorriendo hacia atras:\n");
    recorrerAtras(inicio);

    // ----- Inserción al final -----
    printf("\n\n¿Cuantos valores deseas insertar al final? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Valor %d (final): ", i + 1);
        scanf("%d", &valor);
        insertarFinal(&inicio, valor);
    }

    printf("\nLista recorriendo hacia adelante (despues de insertar al final):\n");
    recorrerAdelante(inicio);

    printf("\nLista recorriendo hacia atras:\n");
    recorrerAtras(inicio);

    // ----- Paso A4: Eliminación -----
    printf("\n\nIngresa el valor a eliminar: ");
    scanf("%d", &valorEliminar);

    eliminar(&inicio, valorEliminar);

    printf("\nLista despues de la eliminacion (hacia adelante):\n");
    recorrerAdelante(inicio);

    printf("\nLista despues de la eliminacion (hacia atras):\n");
    recorrerAtras(inicio);

    // ----- Paso A5: Liberación -----
    liberar(inicio);
    printf("\nMemoria liberada correctamente.\n");

    return 0;
}

// Inserta un nodo al inicio de la lista
void insertarInicio(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error al reservar memoria.\n");
        return;
    }

    nuevo->dato = valor;
    nuevo->anterior = NULL;
    nuevo->siguiente = *inicio;

    // Si la lista no esta vacia, el antiguo inicio apunta hacia atras al nuevo
    if (*inicio != NULL) {
        (*inicio)->anterior = nuevo;
    }

    // Actualizar inicio
    *inicio = nuevo;
}

// Inserta un nodo al final de la lista
void insertarFinal(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error al reservar memoria.\n");
        return;
    }

    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;

    // Si la lista esta vacia, el nuevo es el primer nodo
    if (*inicio == NULL) {
        *inicio = nuevo;
        return;
    }

    // Buscar el ultimo nodo
    struct Nodo *temp = *inicio;
    while (temp->siguiente != NULL) {
        temp = temp->siguiente;
    }

    // Conectar al final
    temp->siguiente = nuevo;
    nuevo->anterior = temp;
}

// Recorre la lista de inicio a fin
void recorrerAdelante(struct Nodo *inicio) {
    struct Nodo *temp = inicio;

    if (temp == NULL) {
        printf("Lista vacia.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d ", temp->dato);
        temp = temp->siguiente;
    }
    printf("\n");
}

// Recorre la lista de fin a inicio
void recorrerAtras(struct Nodo *inicio) {
    if (inicio == NULL) {
        printf("Lista vacia.\n");
        return;
    }

    struct Nodo *temp = inicio;

    // Ir al ultimo nodo
    while (temp->siguiente != NULL) {
        temp = temp->siguiente;
    }

    // Recorrer hacia atras usando 'anterior'
    while (temp != NULL) {
        printf("%d ", temp->dato);
        temp = temp->anterior;
    }
    printf("\n");
}

// Elimina el primer nodo que contenga 'valor'
void eliminar(struct Nodo **inicio, int valor) {
    if (*inicio == NULL) {
        printf("La lista esta vacia, no se puede eliminar.\n");
        return;
    }

    struct Nodo *actual = *inicio;

    // Buscar el nodo con el valor
    while (actual != NULL && actual->dato != valor) {
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        printf("Valor %d no encontrado en la lista.\n", valor);
        return;
    }

    // Caso 1: nodo al inicio
    if (actual->anterior == NULL) {
        *inicio = actual->siguiente;
        if (*inicio != NULL) {
            (*inicio)->anterior = NULL;
        }
    }
    // Caso 2: nodo al final
    else if (actual->siguiente == NULL) {
        actual->anterior->siguiente = NULL;
    }
    // Caso 3: nodo en medio
    else {
        actual->anterior->siguiente = actual->siguiente;
        actual->siguiente->anterior = actual->anterior;
    }

    free(actual);
    printf("Nodo con valor %d eliminado.\n", valor);
}

// Libera toda la memoria de la lista
void liberar(struct Nodo *inicio) {
    struct Nodo *temp;
    while (inicio != NULL) {
        temp = inicio;
        inicio = inicio->siguiente;
        free(temp);
    }
}
