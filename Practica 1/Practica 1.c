//Meter el condicional de menor de 0.
//Suma, Resta, Promedio, Mínimo (Con posición), Máximo (Con posición).
//Invertir el arreglo

//Práctica 1 EDA Hernández Hernández David
#include <stdio.h>

int main(void)
{
    int n;
    int a[10];
    int suma=0;
    int resta;
    int promedio=0;
    int minimo, maximo;
    int posicion;
    int b[10];
    
    
    //Empieza el condicional, sea menor a 1 o mayor que 10, no pasa.
    printf("Ingresa la cantidad máxima de espacios en el arreglo (Máximo 10):\n");
    scanf("%d", &n);
    do{
    if (n<0) {
            printf("Ese número es menor que 1, por favor ingresa la cantidad máxima de espacios en el arreglo (Máximo 10):\n");
            scanf("%d", &n);
    }
    if (n>10) {
        printf("Ese número es mayor que 10, por favor ingresa la cantidad máxima de espacios en el arreglo (Máximo 10):\n");
        scanf("%d", &n);
    }
    if (n==0) {
        printf("Ese número es igual a 0, por favor ingresa la cantidad máxima de espacios en el arreglo (Máximo 10):\n");
        scanf("%d", &n);
    }
    } while(n<1||n>10);
    //Termina el condicional
    
    //Solicitud de números
    printf("Ingrese %d numeros: \n", n);
    
        for(int i=0; i<n; i++)
        {
            printf("Elemento %d: ", i);
            scanf("%d", &a[i]);
        }
    
    //Impresión de números
        printf("\nLos elementos del array son: \n");
        for (int i=0; i<n; i++)
        {
            printf("Elemento %d: %d \n", i, a[i]);
        }
    
    //Suma de números
    for (int i=0; i<n; i++)
    {
        suma=suma+a[i];
    }
    //Impresión de Suma
    printf("\nLa suma de los números: ");
    for (int i=0; i<n; i++)
    {
        printf("%d", a[i]);
        if (i<n-1) {
            printf("+");
        }
        if (i==n-1) {
            printf("=");
        }
    }
    printf("%d\n", suma);
    
    //Resta de números
    resta = a[0];
    for (int i=1; i<n; i++)
    {
        resta=resta-a[i];
    }
    //Impresión de Resta
    printf("\nLa resta de los números: ");
    for (int i=0; i<n; i++)
    {
        printf("%d", a[i]);
        if (i<n-1) {
            printf("-");
        }
        if (i==n-1) {
            printf("=");
        }
    }
    printf("%d\n", resta);
    
    //Promedio de números
    promedio=suma/n;
    //Impresión de promedio
    printf("\nEl promedio de los números: ");
    for (int i=0; i<n; i++)
    {
        printf("%d", a[i]);
        if (i<n-1) {
            printf(", ");
        }
        if (i==n-1) {
            printf(" = ");
        }
    }
    printf("%d\n", promedio);
    
    //Mínimo con la posición
    minimo = a[0];
    posicion = 0;
    for(int i=1; i<n; i++)
    {
        if (a[i] < minimo) {
            minimo = a[i];
            posicion = i;
        }
    }
    //Impresión del mínimo
    printf("\nEl valor mínimo del array es: %d, que está en la posición: %d\n", minimo, posicion);
    
    //Máximo con la posicion
    maximo = a[0];
    posicion = 0;
    for(int i=1; i<n; i++)
    {
        if (a[i] > maximo) {
            maximo = a[i];
            posicion = i;
        }
    }
    //Impresión del máximo
    printf("\nEl valor máximo del array es: %d, que está en la posición: %d\n", maximo, posicion);
    
    //Invertir el Arreglo
    for (int i=0; i<n; i++) {
        b[i] = a[n-1-i];
    }
    for (int i=0; i<n; i++) {
        a[i] = b[i];
    }
    printf("\nEl arreglo ha sido invertido:\n");
    for (int i=0; i<n; i++) {
        printf("Elemento %d: %d\n", i, a[i]);
    }
    
    //Finaliza programa
        printf("\n");
        return 0;
}
