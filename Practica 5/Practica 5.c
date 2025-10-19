#include <stdio.h>

#define MAX 5

/*Estructuras*/
typedef struct
{
    int datos[MAX];
    int tope;
} Pila;

typedef struct 
{
    int datos[MAX];
    int frente;
    int final;
} Cola;

void pila_init(Pila *p)
{
    p->tope = -1;
    printf("Pila inicializada vacía\n");
}

void imprimir_pila(Pila *p) 
{
    printf("Estado de la pila: ");
    if (p->tope == -1) 
    {
        printf("[vacía]\n");
        return;
    }
    printf("[");
    for (int i = 0; i <= p->tope; i++) 
    {
        printf("%d", p->datos[i]);
        if (i < p->tope) printf(", ");
    }
    printf("] (tope=%d)\n", p->tope);
}

void cola_init(Cola *c) 
{
    c->frente = 0;
    c->final = -1;
    printf("Cola inicializada vacía\n");
}

void imprimir_cola(Cola *c) 
{
    printf("Estado de la cola: ");
    if (c->final < c->frente) 
    {
        printf("[vacía]\n");
        return;
    }
    printf("[");
    for (int i = c->frente; i <= c->final; i++) 
    {
        printf("%d", c->datos[i]);
        if (i < c->final) printf(", ");
    }
    printf("] (frente=%d, final=%d)\n", c->frente, c->final);
}

/*Programa principal*/
int main(void) 
{
    Pila pila;
    Cola cola;
    int n, valor;
    int popped[MAX], dequeued[MAX];
    int pop_count = 0, deq_count = 0;

    /* ----- Paso 1: Crear pila ----- */
    pila_init(&pila);

    /* ----- Paso 2: PUSH ----- */
    printf("¿Cuántos elementos quieres apilar? (máximo 5): ");
    scanf("%d", &n);
    if (n > MAX) n = MAX;
    if (n < 0) n = 0;

    for (int i = 0; i < n; i++) 
    {
        printf("Ingresa un valor para PUSH: ");
        scanf("%d", &valor);
        if (pila.tope == MAX - 1) 
        {
            printf("Pila llena, no se puede insertar más.\n");
            break;
        }
        pila.tope++;
        pila.datos[pila.tope] = valor;
        imprimir_pila(&pila);
    }

    /* ----- Paso 3: POP ----- */
    printf("¿Cuántos elementos quieres desapilar (POP)?: ");
    scanf("%d", &n);
    if (n < 0) n = 0;

    for (int i = 0; i < n; i++) 
    {
        if (pila.tope == -1) 
        {
            printf("Pila vacía, no hay más elementos que sacar.\n");
            break;
        }
        int salido = pila.datos[pila.tope];
        pila.tope--;
        popped[pop_count++] = salido;
        printf("Salió (POP): %d\n", salido);
        imprimir_pila(&pila);
    }

    /* ----- Paso 4: Crear cola ----- */
    cola_init(&cola);

    /* ----- Paso 5: ENQUEUE ----- */
    printf("¿Cuántos elementos quieres encolar? (máximo 5): ");
    scanf("%d", &n);
    if (n > MAX) n = MAX;
    if (n < 0) n = 0;

    for (int i = 0; i < n; i++) 
    {
        printf("Ingresa un valor para ENQUEUE: ");
        scanf("%d", &valor);
        if (cola.final - cola.frente + 1 == MAX) 
        {
            printf("Cola llena, no se puede insertar más.\n");
            break;
        }
        cola.final++;
        cola.datos[cola.final] = valor;
        imprimir_cola(&cola);
    }

    /* ----- Paso 6: DEQUEUE ----- */
    printf("¿Cuántos elementos quieres desencolar (DEQUEUE)?: ");
    scanf("%d", &n);
    if (n < 0) n = 0;

    for (int i = 0; i < n; i++) 
    {
        if (cola.final < cola.frente) 
        {
            printf("Cola vacía, no hay más elementos que sacar.\n");
            break;
        }
        int salido = cola.datos[cola.frente];
        cola.frente++;
        dequeued[deq_count++] = salido;
        printf("Salió (DEQUEUE): %d\n", salido);
        imprimir_cola(&cola);
    }

    /* ----- Paso 7: Comparación ----- */
    printf("\n=========== RESUMEN ===========\n");
    printf("Pila → LIFO (último en entrar, primero en salir)\n");
    printf("Orden de salida en Pila (POP): ");
    if (pop_count == 0) 
    {
        printf("[sin extracciones]\n");
    } 
    else 
    {
        printf("[");
        for (int i = 0; i < pop_count; i++) 
        {
            printf("%d", popped[i]);
            if (i < pop_count - 1) printf(", ");
        }
        printf("]\n");
    }

    printf("Cola → FIFO (primero en entrar, primero en salir)\n");
    printf("Orden de salida en Cola (DEQUEUE): ");
    if (deq_count == 0) 
    {
        printf("[sin extracciones]\n");
    } 
    else 
    {
        printf("[");
        for (int i = 0; i < deq_count; i++) 
        {
            printf("%d", dequeued[i]);
            if (i < deq_count - 1) printf(", ");
        }
        printf("]\n");
    }
    printf("================================\n");

    return 0;
}