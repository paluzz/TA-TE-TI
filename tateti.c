#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FILAS 3
#define COLUMNAS 3
#define VICTORIA 1
#define EMPATE 2
#define CONTINUAR -1

char *matrizCrear(int filas, int columnas)
{
    char *p;
    p = (char *)malloc(sizeof(char) * (filas * columnas));
    if (p == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            *(p + (i * columnas) + j) = '-';
        }
    }
    return p;
}

void matrizImprimir(char *p, int filas, int columnas)
{
    if (p != NULL)
    {
        for (int i = filas - 1; i >= 0; i--)
        {
            for (int j = 0; j < columnas; j++)
            {
                printf("%c\t", *(p + (i * columnas) + j));
            }
            printf("\n");
        }
    }
}

void jugada(char *p, int casilla, char c)
{
    *(p + (casilla - 1)) = c;
}

int victoria(char *p, int filas, int columnas)
{
    int i, j;
    char c = '-';
    char x[] = "XXX";
    char y[] = "000";
    char linea[4];
    char *q;

    // busqueda horizontal
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            linea[j] = *(p + (i * columnas) + j);
        }
        linea[j] = '\0';
        if (strcmp(linea, x) == 0 || strcmp(linea, y) == 0)
        {
            return VICTORIA;
        }
    }

    // busqueda vertical
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            linea[j] = *(p + (j * filas) + i);
        }
        linea[j] = '\0';

        if (strcmp(linea, x) == 0 || strcmp(linea, y) == 0)
        {
            return VICTORIA;
        }
    }
    // busqueda diagonal

    linea[0] = *(p + 0);
    linea[1] = *(p + 4);
    linea[2] = *(p + 8);
    linea[3] = '\0';

    if (strcmp(linea, x) == 0 || strcmp(linea, y) == 0)
    {
        return VICTORIA;
    }

    linea[0] = *(p + 2);
    linea[1] = *(p + 4);
    linea[2] = *(p + 6);
    linea[3] = '\0';

    if (strcmp(linea, x) == 0 || strcmp(linea, y) == 0)
    {
        return VICTORIA;
    }

    return CONTINUAR;

    q = strchr(p, c);
    if (q != NULL)
    {
        return EMPATE;
    }
}

int main(void)
{

    int game = 0, i = 0, resultado, casilla;
    char c;
    char player[] = "X0";
    char jugadas[] = "789456123";
    char *p = NULL, *q = NULL;
    p = matrizCrear(FILAS, COLUMNAS);

    while (!game)
    {

        printf("-------------------------------\n");
        printf("turno player: '%c'\n", player[i]);
        printf("Ingrese posicion:\n\n");
        printf("7\t8\t9\n4\t5\t6\n1\t2\t3\n");
        printf("\nPosicion: ");
        scanf("%d", &casilla);
        printf("\n\n-------------------------\n\n");

        // transformamos a Char
        c = casilla + '0';
        // comprobar casilla jugada
        q = strchr(jugadas, c);
        if (q == NULL)
        {
            printf("jugada incorrecta\n");
            matrizImprimir(p, FILAS, COLUMNAS);
        }
        else
        {
            // limpiamos esa casilla
            *q = '.';
            // escribimos jugada
            jugada(p, casilla, player[i]);
            // imprimir matriz
            matrizImprimir(p, FILAS, COLUMNAS);

            // comprobar victoria
            resultado = victoria(p, FILAS, COLUMNAS);
            if (resultado == VICTORIA)
            {
                game = 1;
                printf("\n-------------------------------\n\n");
                printf("FELICIDADES!!!!!!!!!!!\n");
                printf("Ganador jugador %c\n\n", player[i]);
            }
            else if (resultado == EMPATE)
            {
                game = 1;
                printf("\n-------------------------------\n\n");
                printf("Empate\n\n");
            }
            else
            {
                // cambiar player
                if (i == 0)
                {
                    i = 1;
                }
                else
                {
                    i = 0;
                }
            }
        }
    }

    free(p);
    return 0;
}