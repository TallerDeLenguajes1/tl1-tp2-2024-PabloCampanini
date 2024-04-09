#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declaracion de constantes
#define N 20

int main()
{
    srand(time(NULL));
    // Declaracion de variables
    int i;
    double vt[N];
    for (i = 0; i < N; i++)
    {
        vt[i] = 1 + rand() % 100;
        int posicion = i + 1;
        printf("Posicion: %d\t Valor: %f\n", posicion, vt[i]);
    }
}