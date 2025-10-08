#include <stdio.h>
int main(void) {
    int a[5] = {2, 4, 6, 8, 10};
    int *p = a; // p apunta a a[0]
    
    printf("1) a[1] = %d\n", a[1]); //imprime lo que hay en el indice a[1]
    printf("2) *(a+3) = %d\n", *(a+3)); //imprime lo que hay en el indice a[0+3], es decir, lo que hay en a[3]
    printf("3) *p++ = %d\n", *p++); //primero suma 1 al valor que esta apuntando, e imprime a a[1]
    printf("4) *++p = %d\n", *++p); //primero suma 1 al puntero, y luego imprime lo que hay en el nuevo valor del puntero, es decir, a[2]
    printf("5) p[1] = %d\n", p[1]); //Imprime el valor que está una posición después del valor actual del puntero
    printf("6) *(p+=2) = %d\n", *(p+=2)); //incrementa el puntero p en 2 posiciones y luego imprime el valor al que apunta
    printf("7) p - a = %ld\n", p - a); //Imprime la diferencia entre los punteros p y a
    
    return 0;
}