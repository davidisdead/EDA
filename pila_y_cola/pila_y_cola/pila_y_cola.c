#include <stdio.h>
#include <stdlib.h>

#define CAPACIDAD 5

// =========================
// Estructuras
// =========================
typedef struct {
    int datos[CAPACIDAD];
    int tope; // índice del elemento en la cima; -1 si vacía
} Pila;

typedef struct {
    int datos[CAPACIDAD];
    int frente; // índice del primer elemento
    int final;  // índice del último elemento
    int cantidad; // para manejo sencillo de estado
} Cola;

// =========================
// Prototipos Pila
// =========================
void inicializarPila(Pila *p);
int estaVaciaPila(const Pila *p);
int estaLlenaPila(const Pila *p);
int push(Pila *p, int valor);
int pop(Pila *p, int *salida);
void imprimirPila(const Pila *p);

// =========================
// Prototipos Cola
// =========================
void inicializarCola(Cola *c);
int estaVaciaCola(const Cola *c);
int estaLlenaCola(const Cola *c);
int enqueue(Cola *c, int valor);
int dequeue(Cola *c, int *salida);
void imprimirCola(const Cola *c);

// =========================
// Implementación Pila
// =========================
void inicializarPila(Pila *p) {
    p->tope = -1;
}

int estaVaciaPila(const Pila *p) {
    return p->tope == -1;
}

int estaLlenaPila(const Pila *p) {
    return p->tope == CAPACIDAD - 1;
}

int push(Pila *p, int valor) {
    if (estaLlenaPila(p)) return 0; // fallo
    p->datos[++(p->tope)] = valor;
    return 1; // éxito
}

int pop(Pila *p, int *salida) {
    if (estaVaciaPila(p)) return 0; // fallo
    *salida = p->datos[(p->tope)--];
    return 1; // éxito
}

void imprimirPila(const Pila *p) {
    printf("Pila [tope=%d]: ", p->tope);
    if (estaVaciaPila(p)) {
        printf("(vacía)\n");
        return;
    }
    for (int i = 0; i <= p->tope; ++i) {
        printf("%d", p->datos[i]);
        if (i < p->tope) printf(", ");
    }
    printf("\n");
}

// =========================
// Implementación Cola (lineal con índices y conteo)
// =========================
void inicializarCola(Cola *c) {
    c->frente = 0;
    c->final = -1;
    c->cantidad = 0;
}

int estaVaciaCola(const Cola *c) {
    return c->cantidad == 0;
}

int estaLlenaCola(const Cola *c) {
    return c->cantidad == CAPACIDAD;
}

int enqueue(Cola *c, int valor) {
    if (estaLlenaCola(c)) return 0; // fallo
    // hacer circular el índice final
    c->final = (c->final + 1) % CAPACIDAD;
    c->datos[c->final] = valor;
    c->cantidad++;
    return 1; // éxito
}

int dequeue(Cola *c, int *salida) {
    if (estaVaciaCola(c)) return 0; // fallo
    *salida = c->datos[c->frente];
    c->frente = (c->frente + 1) % CAPACIDAD;
    c->cantidad--;
    return 1; // éxito
}

void imprimirCola(const Cola *c) {
    printf("Cola [frente=%d, final=%d, cantidad=%d]: ", c->frente, c->final, c->cantidad);
    if (estaVaciaCola(c)) {
        printf("(vacía)\n");
        return;
    }
    for (int i = 0; i < c->cantidad; ++i) {
        int idx = (c->frente + i) % CAPACIDAD;
        printf("%d", c->datos[idx]);
        if (i < c->cantidad - 1) printf(", ");
    }
    printf("\n");
}

// =========================
// Utilidades de entrada
// =========================
static int leerEntero(const char *prompt) {
    int x;
    printf("%s", prompt);
    while (scanf("%d", &x) != 1) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        printf("Entrada inválida. Intenta de nuevo: ");
    }
    return x;
}

// =========================
// main
// =========================
int main(void) {
    // Paso 1: Crear una pila
    Pila pila;
    inicializarPila(&pila);
    printf("Pila inicializada vacía\n");
    imprimirPila(&pila);

    // Paso 2: Insertar elementos (PUSH)
    int nPush = leerEntero("\n¿Cuántos elementos quieres apilar? (máximo 5): ");
    if (nPush < 0) nPush = 0;
    if (nPush > CAPACIDAD) nPush = CAPACIDAD;

    for (int i = 0; i < nPush; ++i) {
        int valor = leerEntero("Valor a apilar: ");
        if (push(&pila, valor)) {
            printf("Se apiló %d. Estado de la ", valor);
            imprimirPila(&pila);
        } else {
            printf("La pila está llena. No se pudo apilar %d.\n", valor);
            break;
        }
    }

    // Paso 3: Extraer elementos (POP)
    int nPop = leerEntero("\n¿Cuántos elementos quieres desapilar?: ");
    if (nPop < 0) nPop = 0;

    for (int i = 0; i < nPop; ++i) {
        int salido;
        if (pop(&pila, &salido)) {
            printf("Salió de la pila: %d. Estado de la ", salido);
            imprimirPila(&pila);
        } else {
            printf("La pila está vacía. No hay más elementos para desapilar.\n");
            break;
        }
    }

    // Paso 4: Crear una cola
    Cola cola;
    inicializarCola(&cola);
    printf("\nCola inicializada vacía\n");
    imprimirCola(&cola);

    // Paso 5: Insertar elementos en la cola (ENQUEUE)
    int nEnq = leerEntero("\n¿Cuántos elementos quieres encolar? (máximo 5): ");
    if (nEnq < 0) nEnq = 0;
    if (nEnq > CAPACIDAD) nEnq = CAPACIDAD;

    for (int i = 0; i < nEnq; ++i) {
        int valor = leerEntero("Valor a encolar: ");
        if (enqueue(&cola, valor)) {
            printf("Se encoló %d. Estado de la ", valor);
            imprimirCola(&cola);
        } else {
            printf("La cola está llena. No se pudo encolar %d.\n", valor);
            break;
        }
    }

    // Paso 6: Extraer elementos de la cola (DEQUEUE)
    int nDeq = leerEntero("\n¿Cuántos elementos quieres desencolar?: ");
    if (nDeq < 0) nDeq = 0;

    for (int i = 0; i < nDeq; ++i) {
        int salido;
        if (dequeue(&cola, &salido)) {
            printf("Salió de la cola: %d. Estado de la ", salido);
            imprimirCola(&cola);
        } else {
            printf("La cola está vacía. No hay más elementos para desencolar.\n");
            break;
        }
    }

    // Paso 7: Comparación
    printf("\nResumen de orden de salida:\n");
    printf("- Pila → LIFO (último en entrar, primero en salir).\n");
    printf("- Cola → FIFO (primero en entrar, primero en salir).\n");

    return EXIT_SUCCESS;
}
