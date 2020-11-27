#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "Files.h"
#include "Cars.h"



/** \brief Parsea los datos los datos de los autps desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListCars LinkedList*
 * \return int
 *
 */
int parser_CarsFromText(FILE* pFile, LinkedList* pArrayListCars)
{
    int error=1;
    char auxCar[5][120];//declaro array bidimensional para guardar cada campo de un auto
    int cant;
    eCar* newCar;

    if(pFile!=NULL && pArrayListCars!=NULL)//verifico punteros
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n],\n",auxCar[0],auxCar[1],auxCar[2],auxCar[3],auxCar[4]);//leo y guardo cada campo de cada empleado que en el archivo esta separado por comas

        while(!feof(pFile))//itero hasta llegar al final del archivo
        {
            cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n],\n",auxCar[0],auxCar[1],auxCar[2],auxCar[3],auxCar[4]);//leo y guardo cada campo de cada empleado que en el archivo esta separado por comas
            if(cant==5)//verifico que se hayan escrito 4 campos
            {
                newCar=car_newParametros(auxCar[0],auxCar[1],auxCar[2],auxCar[3],auxCar[4]);//creo un nuevo empleado y le asigno los datos previamente guardados
                if(newCar!=NULL)//verifico puntero
                {
                    ll_add(pArrayListCars,newCar);//agrego el nuevo empleado a la lista de empelados
                    error=0;
                }
            }
            else
            {
                break;
            }
        }
    }

    return error;
}

/** \brief Carga los datos de los autos desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListCars LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListCars)
{
    int error=1;
    FILE* f;//declaro puntero a archivo

    if(path!=NULL && pArrayListCars!=NULL)//verifico punteros
    {
        f=fopen(path,"r");//abro archivo de texto en modo lectura
        if(f!=NULL)//verifico puntero
        {
            if(!parser_CarsFromText(f,pArrayListCars))//parseo el archivo a la lista de empleados
            {
                error=0;
            }
            fclose(f);//cierro el archivo
        }
    }

    return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListCars)
{
    FILE* f;
    eCar* auxCar;
    int error=0;
    int len;
    int id;
    char modelo[20];
    float valor;
    int anioFab;
    int cantPuertas;
    int flag=0;

    if(path!=NULL && pArrayListCars!=NULL)//verifico punteros
    {
        len=ll_len(pArrayListCars);//guardo el tamaño de la lista
        f=fopen(path,"w");//abro el archivo en modo escritura
        if(f!=NULL )//verifico puntero
        {
            for(int i=0; i<len; i++)//recorro la lista de empleados
            {
                auxCar=(eCar*)ll_get(pArrayListCars,i);//tomo el empleado de la lista en el indice i
                id = auxCar->id;//tomo los datos del empleado en el indice i
                strcpy(modelo,auxCar->modelo);
                valor = auxCar->valor;
                anioFab = auxCar->anioFab;
                cantPuertas = auxCar->cantPuertas;
                if(!flag)
                {
                    fprintf(f,"id,modelo,valor,anioFab,cantPuertas");
                    flag=1;
                }
                else
                {
                    fprintf(f,"%d,%s,%.2f,%d,%d\n",id,modelo,valor,anioFab,cantPuertas);//escribo el empleado en el archivo
                }
            }
            fclose(f);//cierro el archivo
            error=1;

        }
    }
    return error;
}
