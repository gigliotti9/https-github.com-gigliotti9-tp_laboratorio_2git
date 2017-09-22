#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;
/** \brief inicializa todos los estados en 0
 *
 * \param el vector
 * \param tamaño
 * \return
 *
 */

void FuncionIniciarEstado(EPersona[],int);
/** \brief agregar una persona
 *
 * \param el vector
 * \param tamaño
 * \return
 *
 */

void agregarPersona(EPersona[],int);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void mostrar(EPersona[], int);
/** \brief dar de baja una persona
 *
 * \param vector
 * \param tamaño
 * \return
 *
 */

void eliminar(EPersona[],int);
/** \brief ordenar alfabeticamente los nombres
 *
 * \param vector
 * \param tamaño
 * \return
 *
 */

void ordenar(EPersona[],int);
/** \brief mostrar un grafico
 *
 * \param vector
 * \param tamaño
 * \return
 *
 */

void funcionGrafico(EPersona[],int);








/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[],int);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni,int);

#endif // FUNCIONES_H_INCLUDED
