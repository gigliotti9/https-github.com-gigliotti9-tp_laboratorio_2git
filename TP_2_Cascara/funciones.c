#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"
#include <string.h>
#define TAM 20



void agregarPersona(EPersona lista[],int tam)
{

    int auxInt;

    auxInt=obtenerEspacioLibre(lista,tam);



    if(lista[auxInt].estado != -1)
    {
        lista[auxInt].estado=1;

        printf("ingrese un nombre ");
        fflush(stdin);
        gets( lista[auxInt].nombre);

        printf("ingrese una edad ");
        fflush(stdin);
        scanf("%d",&lista[auxInt].edad);

        while(lista[auxInt].edad<0 || lista[auxInt].edad>100 || isdigit(lista[auxInt].edad!=0))
        {
            printf("ERROR,ingrese una edad ");
            fflush(stdin);
            scanf("%d",&lista[auxInt].edad);
        }

        printf("ingrese un dni ");

        fflush(stdin);

        scanf("%d",&lista[auxInt].dni);

    }
    else
    {

        printf("no hay mas espacio");
    }




}


void FuncionIniciarEstado(EPersona lista[],int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        lista[i].estado=0;
    lista[i].dni=0;
    }


}



int obtenerEspacioLibre(EPersona lista[],int tam)
{
    int i;
    int aux;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==0)
        {
            aux=i;
            break;

        }
        else
        {
            aux=-1;

        }

    }
    return aux;

}




int buscarPorDni(EPersona lista[],int dni,int tam)
{
    int i;
    int auxDni;


    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==1 && lista[i].dni==dni)
        {
            auxDni=i;
            break;
        }
        else
        {
            auxDni=-1;
        }


    }

    return auxDni;

}




void eliminar(EPersona lista[],int tam)
{

    int AuxInt;
    int retorno;
    char rta;
    printf("ingrese el dni ");
    scanf("%d", &AuxInt);

    retorno=buscarPorDni(lista,AuxInt,tam);


    if(retorno == -1)
    {


        printf("El dni ingresado no se ha encontrado\n");


    }
    else
    {
        printf("\n¿Desea realizar eliminar al alumno? (s/n): ");

        rta = getche();

        if(rta == 's')
        {
            lista[AuxInt].dni = 0;
            printf("\nfue eliminado\n");
        }
        else

        {
            printf("\nLa opcion fue cancelada");
        }

    }

}


void ordenar(EPersona lista[],int tam)
{
    int i, j;
    EPersona auxPersona;


    for(i=0; i<tam-1; i++)
    {

        if(lista[i].estado==1)
        {
            for(j=i+1; j<tam; j++)
            {
                if(lista[j].estado==1)
                {
                    if(strcmp(lista[i].nombre, lista[j].nombre) > 0)
                    {

                        auxPersona=lista[i];
                        lista[i]=lista[j];
                        lista[j]=auxPersona;



                    }

                }

            }


        }
    }
}






void mostrar(EPersona lista[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {

        if(lista[i].estado==1)
        {

            printf("\nNumero %d\n", i+1);

            printf("\nnombre %s-- edad %d--dni %d\n", lista[i].nombre,lista[i].edad,lista[i].dni);


        }
    }
}


void funcionGrafico(EPersona lista[],int tam)
{
    int i;
    int j;
    int max;
    int menores=0,de19a35=0,mayores=0;
    int flag=0;


    for(i=0; i<tam; i++)
    {

        if(lista[i].edad<18)
        {
            menores++;
        }

        else if(lista[i].edad>18&&lista[i].edad<35)
        {
            de19a35++;
        }
        else if(lista[i].edad>18)
        {
            mayores++;
        }
    }
    if(menores >= de19a35 && menores >= mayores)
    {

        max=menores;

    }
    else
    {

        if(de19a35 >= menores && de19a35 >= mayores)
        {
            max = de19a35;
        }
        else
        {
            max = mayores;

        }
    }

    for(j=max; i<0; j--)
    {

        if(j<=menores)
        {
            printf("*");
            flag=1;
        }
        if(j<=de19a35)
        {
            printf("\t*");
            flag=1;

        }
        if(j<=mayores)
        {
            if(flag==0)
            {
                printf("\t\t*");
            }
            else if(flag==0)
            {
                printf("\t*");
            }
        }
        printf("\n");

    }

    printf("<18\t19-35\t>35\n");

    printf("\n%d\t%d\t%d\n", menores,de19a35,mayores);
}

