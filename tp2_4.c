#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct compu
{
    int velocidad;  // entre 1 y 3 GHz
    int anio;       // entre 2015 y 2023
    int cantidad;   // entre 1 y 8
    char *tipo_cpu; // valores del arreglo tipos
} compu;

void imprimir(compu almacen[]);
void masVieja(compu almacen[]);
void masVelocidad(compu almacen[]);

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

        almacen[i].tipo_cpu = strdup(tipos[indice]);
    }

    imprimir(almacen);
    masVieja(almacen);
    masVelocidad(almacen);
    for (int i = 0; i < 5; i++)
    {
        free(almacen[i].tipo_cpu);
    }
    
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
        printf("\t* Tipo CPU: %s\n\n", almacen[i].tipo_cpu);
    }
}

void masVieja(compu almacen[])
{
    int viejo = 2023, cpu;

    for (int i = 0; i < 5; i++)
    {

        if (almacen[i].anio < viejo)
        {
            viejo = almacen[i].anio;
            cpu = i + 1;
        }
    }

    printf("\n\n *------ La computadora mas vieja es: ------* \nComputadora: %d\tModelo: %d", cpu, viejo);
}

void masVelocidad(compu almacen[])
{
    int rapido = 0, cpu;

    for (int i = 0; i < 5; i++)
    {

        if (almacen[i].velocidad > rapido)
        {
            rapido = almacen[i].velocidad;
            cpu = i + 1;
        }
    }

    printf("\n\n *------ La computadora mas veloz es: ------* \nComputadora: %d\tVelocidad: %d", cpu, rapido);
}
