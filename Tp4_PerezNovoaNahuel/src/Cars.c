#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "Files.h"
#include "Cars.h"

/** \brief Pide espacio en memoria para una estructura de tipo eCar
 *
 * \return eCar* Retorna el puntero a la estructura
 *
 */
eCar* car_new()
{
    return (eCar*) malloc(sizeof(eCar));//retorno puntero a espacio para nuevo auto
}

/** \brief Pide espacio en memoria para una estructura eCar y la parametriza
 *
 * \param idStr char*
 * \param modeloStr char*
 * \param valorStr char*
 * \param anioStr char*
 * \param puertasStr char*
 * \return eCar* Devuelve el puntero a la estructura
 *
 */
eCar* car_newParametros(char* idStr,char* modeloStr,char* valorStr,char* anioStr,char* puertasStr)
{
    eCar* nuevoAuto = car_new();//pido espacio y direccion para nuevo auto
    if(nuevoAuto!=NULL)//verifico puntero
    {
        nuevoAuto->id=atoi(idStr);//escribo Id casteado a entero, en el nuevo auto
        strcpy(nuevoAuto->modelo,modeloStr);//escribo modelo en el nuevo auto
        nuevoAuto->valor=atof(valorStr);//escribo valor casteado a flotante, en el nuevo auto
        nuevoAuto->anioFab=atoi(anioStr);//escribo anio de fabricacion casteado a entero, en el nuevo auto
        nuevoAuto->cantPuertas=atoi(puertasStr);//escribo cant. de puertas casteado a entero, en el nuevo auto

    }

    return nuevoAuto;//devuelvo el puntero a nuevo auto con los parametros cargados
}

/** \brief Muestra una estructura eCar
 *
 * \param unAuto eCar*
 * \return int Devuelve 0 si hay ERROR o 1 si Ok
 *
 */
int mostrarAutoP(eCar* unAuto)
{
    int error = 0;
    if(unAuto!=NULL)
    {
        error=1;
        printf("%4d%16s     $%13.2f     %4d         %1d\n",unAuto->id,unAuto->modelo,unAuto->valor,unAuto->anioFab,unAuto->cantPuertas);
        //imprimo los campos de un empleado pasado por referencia
    }
    return error;
}

/** \brief Muestra todo un listado de estructuras eCar
 *
 * \param pArrayListCars LinkedList*
 * \return int Devuelve 0 si hay ERROR o 1 si Ok
 *
 */
int car_ListCars(LinkedList* pArrayListCars)
{
    int error=0;
    int tam;
    int flag=0;
    eCar* auxCar;

    if(pArrayListCars!=NULL)//verifico puntero
    {
        error=1;
        printf("  Id       Modelo              Valor        Anio   Cant. Puertas\n");//imprimo encabezado
        printf("----------------------------------------------------------------\n");
        tam = ll_len(pArrayListCars);
        for(int i=0; i<tam; i++)//recorro la lista salteando el encabezado del archivo
        {
            auxCar = (eCar*)ll_get(pArrayListCars,i);//tomo el empleado de la lista en el indice i
            if(auxCar != NULL)//verifico puntero
            {
                mostrarAutoP(auxCar);//muestro dicho empleado
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("No hay autos\n\n");//informo que no hay empleados
        }
        printf("\n\n");
    }
    return error;
}

/** \brief Busca el mayor ID dentro de un array de estructuras eCar
 *
 * \param
 * \param
 * \return Devuelve el valor del mayor ID
 *
 */
int buscarMayorId (LinkedList* pArrayListCars)
{
    int mayorId;
    int flag=0;
    int len = ll_len(pArrayListCars);
    eCar* auxCar;
    if(pArrayListCars!=NULL)
    {
        for(int i=0; i<len; i++)
        {
            auxCar = (eCar*)ll_get(pArrayListCars,i);
            if(!flag)
            {
                mayorId = auxCar->id;
            }
            else
            {
                if(auxCar->id > mayorId)
                {
                    mayorId = auxCar->id;
                }
            }
        }
    }
    return mayorId;
}

/** \brief Devuelve el indice de la estructura correspondiente al ID pasado como parametro
 *
 * \param
 * \param
 * \return Devuelve el indice buscado
 *
 */
int indexById (LinkedList* pArrayListCars, int id)
{
    eCar* auxCar;
    int index;
    int len = ll_len(pArrayListCars);
    if(pArrayListCars!=NULL && id>0)
    {
        for(int i=0; i<len; i++)
        {
            auxCar = (eCar*)ll_get(pArrayListCars,i);
            if(auxCar->id==id)
            {
                index=i;
                break;
            }
            else
            {
                continue;
            }
        }
    }
    return index;
}

/** \brief Devuelve un puntero a la estructura correspondiente al ID pasado como parametro
 *
 * \param
 * \param
 * \return Devuelve un puntero a la estructura buscada
 *
 */
eCar* elementById (LinkedList* pArrayListCars, int id)
{
    eCar* auxCar;
    int len = ll_len(pArrayListCars);
    if(pArrayListCars!=NULL && id>0)
    {
        for(int i=0; i<len; i++)
        {
            auxCar = (eCar*)ll_get(pArrayListCars,i);
            if(auxCar->id==id)
            {
                break;
            }
            else
            {
                continue;
            }
        }
    }
    return auxCar;
}

/** \brief Compara dos estructuras pasadas por referencia en base a su anio de fabricacion
 *
 * \param car1 void*
 * \param car2 void*
 * \return int Devuelve 0 si son iguales, 1 si (car1<car2) o -1 si (car1>car2)
 *
 */
int compararAutosPorAnio(void* car1, void* car2)
{
    int rta;
    eCar* auxCar1;//declaro puntero tipo eCar para car1
    eCar* auxCar2;//declaro puntero tipo eCar para car1

    if(car1!=NULL && car2!=NULL)//verifico punteros
    {
        auxCar1 = (eCar*) car1;//casteo y asigno direcc de memoria al puntero
        auxCar2 = (eCar*) car2;//casteo y asigno direcc de memoria al puntero
        if(auxCar1->anioFab == auxCar2->anioFab)
        {
            rta=0;
        }
        else if(auxCar1->anioFab > auxCar2->anioFab)
        {
            rta=-1;
        }
        else
        {
            rta=1;
        }
    }

    return rta;
}

/** \brief Determina si el valor de la estructura pasada como parametro es mayor a 1500000
 *
 * \param car void*
 * \return int Devuelve 1 si es mayor a 1500000 o 0 si es menor o igual a 1500000
 *
 */
int sortCriterioValor(void* car)
{
    int rta = 0;
    eCar* auxCar = car;
    if(auxCar!=NULL)
    {
        if(auxCar->valor>1500000)
        {
            rta = 1;
        }
    }
    return rta;
}
