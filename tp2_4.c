#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct compu
{
    int velocidad;  // entre 1 y 3 GHz
    int anio;       // entre 2015 y 2023
    int cantidad;   // entre 1 y 8
    char *tipo_cpu; // valores del arreglo tipos
} compu;

void imprimir(compu almacen[]);
// void masVieja(compu almacen[]);
// void masVelocidada(compu almacen[]);

int main()
{
    srand(time(NULL));

    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    compu almacen[5];

    for (int i = 0; i < 5; i++)
    {
        almacen[i].velocidad = 1 + rand() % 3;
        almacen[i].anio = 2015 + rand() % 9;
        almacen[i].cantidad = 1 + rand() % 8;

        // Variable aux para elegir indice de matriz
        int indice = 1 + rand() % 6;

        almacen[i].tipo_cpu = tipos[indice];
    }

    imprimir(almacen);

    return 0;
}

void imprimir(compu almacen[])
{
    for (int i = 0; i < 5; i++)
    {
        printf("Computadora: %d\n", (i + 1));
        printf("\t* Velocidad: %d\n", almacen[i].velocidad);
        printf("\t* Anio: %d\n", almacen[i].anio);
        printf("\t* Cantidad: %d\n", almacen[i].cantidad);
        printf("\t* Tipo CPU: %s\n", almacen[i].tipo_cpu);
    }
}
// void masVieja(compu almacen[]);
// void masVelocidada(compu almacen[]);