#include <stdlib.h>
#include <stdio.h>
#define MAX 5

typedef struct {
    int datos[MAX];
    int frente;   // indice del elemento al frente
    int final;    // indice de la proxima posicion de insercion
    int size;     // numero de elementos actuales
} ColaCircular;

// Prototipos
void inicializar(ColaCircular *cola);
int isEmpty(const ColaCircular *cola);
int isFull(const ColaCircular *cola);
int enqueue(ColaCircular *cola, int valor);
int dequeue(ColaCircular *cola, int *valor);
int peek(const ColaCircular *cola, int *valor);
void printQueue(const ColaCircular *cola);

// Implementacion
void inicializar(ColaCircular *cola) {
    cola->frente = 0;
    cola->final = 0;
    cola->size = 0;
    printf("Cola circular inicializada\n");
}

int isEmpty(const ColaCircular *cola) {
    return cola->size == 0 ? 1 : 0;
}

int isFull(const ColaCircular *cola) {
    return cola->size == MAX ? 1 : 0;
}

int enqueue(ColaCircular *cola, int valor) {
    if (isFull(cola)) {
        printf("Enqueue %d fallo: cola llena\n", valor);
        return 0;
    }
    cola->datos[cola->final] = valor;
    cola->final = (cola->final + 1) % MAX; // avanzar final
    cola->size++;
    printf("Enqueue: %d\n", valor);
    return 1;
}

int dequeue(ColaCircular *cola, int *valor) {
    if (isEmpty(cola)) {
        printf("Dequeue fallo: cola vacia\n");
        return 0;
    }
    if (valor) *valor = cola->datos[cola->frente];
    cola->frente = (cola->frente + 1) % MAX; // avanzar frente
    cola->size--;
    printf("Dequeue: %d\n", valor ? *valor : 0);
    return 1;
}

int peek(const ColaCircular *cola, int *valor) {
    if (isEmpty(cola)) return 0;
    if (valor) *valor = cola->datos[cola->frente];
    return 1;
}

void printQueue(const ColaCircular *cola) {
    printf("[Cola] size=%d, frente=%d, final=%d => ", cola->size, cola->frente, cola->final);
    printf("{");
    for (int i = 0; i < cola->size; i++) {
        int idx = (cola->frente + i) % MAX;
        printf("%d", cola->datos[idx]);
        if (i < cola->size - 1) printf(", ");
    }
    printf("}\n");
}

int main(int argc, const char * argv[]) {
    ColaCircular cola;

    // Paso A1. Inicializacion
    inicializar(&cola);

    // Paso A3. Pruebas
    // 1. Encolar: 5, 10, 15 → imprime estado.
    enqueue(&cola, 5);
    enqueue(&cola, 10);
    enqueue(&cola, 15);
    printQueue(&cola);

    // 2. Desencolar uno → imprime estado.
    int extraido = 0;
    dequeue(&cola, &extraido);
    printQueue(&cola);

    // 3. Encolar: 20, 25, 30 → imprime estado.
    enqueue(&cola, 20);
    enqueue(&cola, 25);
    enqueue(&cola, 30); // Con MAX=5, aqui deberia llenarse y reciclar indices
    printQueue(&cola);

    // 4. Observacion implicita: indices avanzan circularmente (reutilizacion de espacios)
    // Intento extra: mostrar el frente actual
    int alFrente;
    if (peek(&cola, &alFrente)) {
        printf("Peek (frente): %d\n", alFrente);
    } else {
        printf("Peek fallo: cola vacia\n");
    }

    return EXIT_SUCCESS;
}

