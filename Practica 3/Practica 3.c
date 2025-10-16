#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_LEN   80
#define GEN_LEN    40
#define DIR_LEN    60
#define MAX_DIR    5
#define MAX_PELIS  100

struct pelicula
{
    char nombre[NAME_LEN];
    char genero[GEN_LEN];
    int  anio;
    int  numDirectores;
    char directores[MAX_DIR][DIR_LEN];
};

//Ayuda a borrar espacios después de las lineas
void leer_linea(char *buf, int tam)
{
    char *p = NULL;
    if (fgets(buf, tam, stdin) != NULL) 
    {
        p = strchr(buf, '\n');
        if (p != NULL) 
        {
            *p = '\0';
        }
    } 
    else 
    {
        if (tam > 0) buf[0] = '\0';
    }
}

int leer_entero(const char *mensaje) 
{
    char linea[64];
    int valor = 0;
    int ok = 0;
    while (ok == 0) 
    {
        printf("%s", mensaje);
        leer_linea(linea, sizeof(linea));
        if (sscanf(linea, "%d", &valor) == 1) 
        {
            ok = 1;
        } 
        else 
        {
            printf("Entrada invalida. Intenta de nuevo.\n");
        }
    }
    return valor;
}

//Imprime las peliculas
void imprimir_pelicula(struct pelicula *p) 
{
    int j = 0;
    printf("Pelicula: %s\n", p->nombre);
    printf("Genero: %s\n", p->genero);
    printf("Anio: %d\n", p->anio);
    printf("Directores (%d):\n", p->numDirectores);
    while (j < p->numDirectores) 
    {
        printf("  - %s\n", p->directores[j]);
        j = j + 1;
    }
}

int main(void) 
{
    struct pelicula videoteca[MAX_PELIS];
    int n = 0;
    int i = 0;

    //Validacion de numero
    n = leer_entero("¿Cuantas peliculas deseas registrar? (1..100): ");
    if (n < 1) 
    {
        printf("Cantidad invalida. Debe ser >= 1.\n");
    }
    if (n > MAX_PELIS) 
    {
        n = MAX_PELIS;
        printf("Se limitara a %d peliculas.\n", MAX_PELIS);
    }
    if (n >= 1) 
    {
        i = 0;
        while (i < n) 
        {
            int okDir = 0;
            int j = 0;
            char linea[64];

            printf("\n--- Pelicula %d ---\n", i + 1);

            printf("Nombre: ");
            leer_linea(videoteca[i].nombre, NAME_LEN);

            printf("Genero: ");
            leer_linea(videoteca[i].genero, GEN_LEN);

            videoteca[i].anio = leer_entero("Anio: ");

            okDir = 0;
            while (okDir == 0) 
            {
                printf("Numero de directores (1..%d): ", MAX_DIR);
                leer_linea(linea, sizeof(linea));
                if (sscanf(linea, "%d", &videoteca[i].numDirectores) == 1) 
                {
                    if (videoteca[i].numDirectores >= 1 && videoteca[i].numDirectores <= MAX_DIR) 
                    {
                        okDir = 1;
                    } 
                    else 
                    {
                        printf("Valor invalido. Debe ser 1..%d.\n", MAX_DIR);
                    }
                } 
                else 
                {
                    printf("Entrada invalida. Intenta de nuevo.\n");
                }
            }

            j = 0;
            while (j < videoteca[i].numDirectores) 
            {
                printf("Director %d: ", j + 1);
                leer_linea(videoteca[i].directores[j], DIR_LEN);
                j = j + 1;
            }
            i = i + 1;
        }

        //Para imprimir en orden inverso
        printf("\n####### Contenido de la videoteca (orden inverso) #######\n");
        i = n - 1;
        while (i >= 0) 
        {
            imprimir_pelicula(&videoteca[i]);
            printf("\n");
            i = i - 1;
        }

        /* --------- Búsquedas ---------- */
        {
            int seguir = 1;
            while (seguir == 1) {
                int op = 0;
                char linea[64];
                printf("Busqueda: 1) nombre  2) anio  3) director  0) salir: ");
                leer_linea(linea, sizeof(linea));
                if (sscanf(linea, "%d", &op) != 1) 
                {
                    printf("Opcion invalida.\n");
                    op = -1;
                }

                if (op == 0) 
                {
                    seguir = 0;
                } 
                else 
                {
                    if (op == 1) 
                    {
                        char buscado[NAME_LEN];
                        int hallados = 0;
                        int k = 0;
                        printf("Nombre a buscar: ");
                        leer_linea(buscado, NAME_LEN);
                        while (k < n) 
                        {
                            if (strcmp(videoteca[k].nombre, buscado) == 0) 
                            {
                                imprimir_pelicula(&videoteca[k]);
                                printf("\n");
                                hallados = hallados + 1;
                            }
                            else 
                            {
                                /* no hacer nada */
                            }
                            k = k + 1;
                        }
                        if (hallados == 0) 
                        {
                            printf("Sin coincidencias.\n");
                        }
                    } 
                    else 
                    {
                        if (op == 2) 
                        {
                            int anioBuscado = 0;
                            int hallados = 0;
                            int k = 0;
                            char ln[64];
                            printf("Anio a buscar: ");
                            leer_linea(ln, sizeof(ln));
                            if (sscanf(ln, "%d", &anioBuscado) != 1) 
                            {
                                printf("Entrada invalida.\n");
                            } else {
                                while (k < n) 
                                {
                                    if (videoteca[k].anio == anioBuscado) 
                                    {
                                        imprimir_pelicula(&videoteca[k]);
                                        printf("\n");
                                        hallados = hallados + 1;
                                    } 
                                    else 
                                    {
                                        /* no hacer nada */
                                    }
                                    k = k + 1;
                                }
                                if (hallados == 0) 
                                {
                                    printf("Sin coincidencias.\n");
                                }
                            }
                        }
                        else 
                        {
                            if (op == 3) 
                            {
                                char dirBuscado[DIR_LEN];
                                int hallados = 0;
                                int k = 0;
                                printf("Director a buscar: ");
                                leer_linea(dirBuscado, DIR_LEN);
                                while (k < n) 
                                {
                                    int j = 0;
                                    int impresa = 0; // evita imprimir la misma película varias veces
                                    while (j < videoteca[k].numDirectores) 
                                    {
                                        if (impresa == 0) 
                                        {
                                            if (strcmp(videoteca[k].directores[j], dirBuscado) == 0) 
                                            {
                                                imprimir_pelicula(&videoteca[k]);
                                                printf("\n");
                                                hallados = hallados + 1;
                                                impresa = 1;
                                            } 
                                            else 
                                            {
                                                /* no hacer nada */
                                            }
                                        } 
                                        else 
                                        {
                                            /* ya impresa, pero seguimos sin break */
                                        }
                                        j = j + 1;
                                    }
                                    k = k + 1;
                                }
                                if (hallados == 0) 
                                {
                                    printf("Sin coincidencias.\n");
                                }
                            } 
                            else 
                            {
                                printf("Opcion invalida.\n");
                            }
                        }
                    }
                }
            }
        }

        /* --------- Conteo por género ---------- */
        {
            int contado[MAX_PELIS];
            int a = 0;
            while (a < n) { contado[a] = 0; a = a + 1; }

            printf("\n--- Conteo por genero ---\n");
            i = 0;
            while (i < n) 
            {
                if (contado[i] == 0) 
                {
                    int c = 1;
                    int k = i + 1;
                    while (k < n) 
                    {
                        if (contado[k] == 0) 
                        {
                            if (strcmp(videoteca[i].genero, videoteca[k].genero) == 0) {
                                c = c + 1;
                                contado[k] = 1;
                            } 
                            else 
                            {
                                /* no hacer nada */
                            }
                        } 
                        else 
                        {
                            /* ya contado */
                        }
                        k = k + 1;
                    }
                    printf("%s: %d\n", videoteca[i].genero, c);
                } 
                else 
                {
                    /* ya reportado */
                }
                i = i + 1;
            }
        }

    } 
    else 
    {
        /* n < 1 ya notificado arriba */
    }
    return 0;
}