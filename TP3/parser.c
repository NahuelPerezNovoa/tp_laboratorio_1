#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int error=1;
    char auxEmp[4][120];//declaro array bidimensional para guardar cada campo de un empleado
    int cant;
    Employee* newEmployee;

    if(pFile!=NULL && pArrayListEmployee!=NULL)//verifico punteros
    {
        while(!feof(pFile))//itero hasta llegar al final del archivo
        {
            cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n],\n",auxEmp[0],auxEmp[1],auxEmp[2],auxEmp[3]);//leo y guardo cada campo de cada empleado que en el archivo esta separado por comas
            if(cant==4)//verifico que se hayan escrito 4 campos
            {
                newEmployee=employee_newParametros(auxEmp[0],auxEmp[1],auxEmp[2],auxEmp[3]);//creo un nuevo empleado y le asigno los datos previamente guardados
                if(newEmployee!=NULL)//verifico puntero
                {
                    ll_add(pArrayListEmployee,newEmployee);//agrego el nuevo empleado a la lista de empelados
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

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int error=1;
    int cant;
    Employee* newEmployee;

    if(pFile!=NULL && pArrayListEmployee!=NULL)//verifico punteros
    {
        while(!feof(pFile))//itero hasta llegar al final del archivo
        {
            newEmployee = employee_new();//pido espacio para un nuevo empleado
            cant = fread(newEmployee,sizeof(Employee),1,pFile);//leo empleado en modo binario
            if(newEmployee!=NULL && cant==1)//verifico punteros y cantidad de lecturas
            {
                ll_add(pArrayListEmployee,newEmployee);//agrego el nuevo empleado a la lista de empelados
                error=0;
            }
            else
            {
                employee_delete(newEmployee);//elimino el empleado en caso de que falle la carga
                break;
            }
        }
    }
    return error;
}
