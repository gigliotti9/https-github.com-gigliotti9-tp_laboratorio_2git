#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"
#include <string.h>
#define TAM 20



int main()
{
    char seguir='s';
    int opcion=0;

    EPersona lista[TAM];
    FuncionIniciarEstado (lista,TAM);
    while(seguir=='s')
    {

        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:

            agregarPersona(lista,TAM);

            mostrar( lista, TAM);
            break;
        case 2:
            eliminar(lista,TAM);
            mostrar( lista, TAM);
            break;
        case 3:
            ordenar(lista,TAM);
            mostrar( lista, TAM);
            break;
        case 4:
           funcionGrafico(lista,TAM);
            break;
        case 5:
            seguir = 'n';
            break;
                    default:
            {
                printf("error, ingrese una opcion entre 1 y 5");
                system("pause");
            }
        }

    }

    return 0;
}













