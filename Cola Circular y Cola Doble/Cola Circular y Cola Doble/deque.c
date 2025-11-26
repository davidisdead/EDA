#include <stdlib.h>
#include <stdio.h>

#define MAX 5

typedef struct {
    int datos[MAX];
    int front; // indice del primer elemento
    int size;  // cantidad de elementos
} Deque;

// rear se calcula como: (front + size - 1) % MAX cuando size > 0
static int rearIndex(const Deque *dq) {
    if (dq->size == 0) return -1;
    return (dq->front + dq->size - 1) % MAX;
}

// Utilidades
void inicializarDeque(Deque *dq) {
    dq->front = 0;
    dq->size = 0;
    printf("Deque inicializado\n");
}

int isEmptyDeque(const Deque *dq) { return dq->size == 0 ? 1 : 0; }
int isFullDeque(const Deque *dq) { return dq->size == MAX ? 1 : 0; }

int insert_front(Deque *dq, int valor) {
    if (isFullDeque(dq)) {
        printf("insert_front %d fallo: deque lleno\n", valor);
        return 0;
    }
    // mover front hacia atras circularmente y escribir
    dq->front = (dq->front - 1 + MAX) % MAX;
    dq->datos[dq->front] = valor;
    dq->size++;
    printf("insert_front: %d\n", valor);
    return 1;
}

int insert_rear(Deque *dq, int valor) {
    if (isFullDeque(dq)) {
        printf("insert_rear %d fallo: deque lleno\n", valor);
        return 0;
    }
    int idx = (dq->front + dq->size) % MAX; // posicion libre al final
    dq->datos[idx] = valor;
    dq->size++;
    printf("insert_rear: %d\n", valor);
    return 1;
}

int delete_front(Deque *dq, int *valor) {
    if (isEmptyDeque(dq)) {
        printf("delete_front fallo: deque vacio\n");
        return 0;
    }
    if (valor) *valor = dq->datos[dq->front];
    dq->front = (dq->front + 1) % MAX;
    dq->size--;
    printf("delete_front: %d\n", valor ? *valor : 0);
    return 1;
}

int delete_rear(Deque *dq, int *valor) {
    if (isEmptyDeque(dq)) {
        printf("delete_rear fallo: deque vacio\n");
        return 0;
    }
    int r = rearIndex(dq);
    if (valor) *valor = dq->datos[r];
    dq->size--; // al reducir size, el nuevo rear se actualiza implicitamente
    printf("delete_rear: %d\n", valor ? *valor : 0);
    return 1;
}

int peek_front(const Deque *dq, int *valor) {
    if (isEmptyDeque(dq)) return 0;
    if (valor) *valor = dq->datos[dq->front];
    return 1;
}

int peek_rear(const Deque *dq, int *valor) {
    if (isEmptyDeque(dq)) return 0;
    int r = rearIndex(dq);
    if (valor) *valor = dq->datos[r];
    return 1;
}

void printDeque(const Deque *dq) {
    int r = rearIndex(dq);
    printf("[Deque] size=%d, front=%d, rear=%d => ", dq->size, dq->front, r);
    printf("{");
    for (int i = 0; i < dq->size; i++) {
        int idx = (dq->front + i) % MAX;
        printf("%d", dq->datos[idx]);
        if (i < dq->size - 1) printf(", ");
    }
    printf("}\n");
}

int main(void) {
    Deque dq;
    inicializarDeque(&dq);

    // Paso B3. Pruebas
    // 1. insert_front(10)
    insert_front(&dq, 10);

    // 2. insert_rear(15), insert_rear(20)
    insert_rear(&dq, 15);
    insert_rear(&dq, 20);

    // 3. insert_front(30)
    insert_front(&dq, 30);

    // 4. insert_rear(40) -> imprime estado (indices primero y ultimo)
    insert_rear(&dq, 40);
    printDeque(&dq);

    // 5. delete_front() y delete_rear() -> imprime estado
    int val;
    delete_front(&dq, &val);
    delete_rear(&dq, &val);
    printDeque(&dq);

    // 6. Inserta nuevos valores y comprueba como se mueven los indices
    insert_rear(&dq, 50);
    insert_front(&dq, 60);
    insert_rear(&dq, 70);
    printDeque(&dq);

    // Mostrar peeks
    int pf, pr;
    if (peek_front(&dq, &pf)) printf("peek_front: %d\n", pf);
    if (peek_rear(&dq, &pr)) printf("peek_rear: %d\n", pr);

    return EXIT_SUCCESS;
}
