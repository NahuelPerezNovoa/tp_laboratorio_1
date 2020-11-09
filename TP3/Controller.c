#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int error=1;
    FILE* f;//declaro puntero a archivo

    if(path!=NULL && pArrayListEmployee!=NULL)//verifico punteros
    {
        f=fopen(path,"r");//abro archivo de texto en modo lectura
        if(f!=NULL)//verifico puntero
        {
            if(!parser_EmployeeFromText(f,pArrayListEmployee))//parseo el archivo a la lista de empleados
            {
                error=0;
            }
            fclose(f);//cierro el archivo
        }
    }

    return error;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int error=1;
    FILE* f;//declaro puntero a archivo

    if(path!=NULL && pArrayListEmployee!=NULL)//verifico punteros
    {
        f=fopen(path,"rb");//abro el archivo en modo lectura binaria
        if(f!=NULL)//verifico puntero
        {
            if(!parser_EmployeeFromBinary(f,pArrayListEmployee))//parseo el archivo a la lista de empleados
            {
                error=0;
            }
            fclose(f);//cierro el archivo
        }
    }

    return error;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int error=1;
    int auxId;
    int auxHorasTrabajadas;
    int auxSueldo;
    char auxNombre[120];
    Employee* newEmployee;

    if(pArrayListEmployee!=NULL)//verifico puntero
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(auxNombre);//leo nombre ingresado
        while(strlen(auxNombre)>120)//valido longitud del nombre
        {
            printf("Nombre fuera de rango. Reingrese : ");
            fflush(stdin);
            gets(auxNombre);
        }
        printf("Ingrese horas trabajadas: ");
        fflush(stdin);
        scanf("%d",&auxHorasTrabajadas);//leo horas ingresadas
        while(auxHorasTrabajadas<0 || auxHorasTrabajadas>300)//verifico cantidad de horas
        {
            printf("Cantidad de horas fuera de rango. Reingrese: ");
            fflush(stdin);
            scanf("%d",&auxHorasTrabajadas);
        }
        printf("Ingrese sueldo: ");
        fflush(stdin);
        scanf("%d",&auxSueldo);//leo sueldo ingresado
        while(auxSueldo<0 || auxSueldo>1000000)//verifico monto del sueldo
        {
            printf("Sueldo fuera de rango. Reingrese: ");
            fflush(stdin);
            scanf("%d",&auxSueldo);
        }
        auxId=getNewId(pArrayListEmployee);//solicito nuevo id

        newEmployee=employee_new();//pido espacio para nuevo empleado
        if(newEmployee!=NULL)//verifico puntero
        {
            if(employee_setId(newEmployee,auxId)
                    && employee_setNombre(newEmployee,auxNombre)
                    && employee_setHorasTrabajadas(newEmployee,auxHorasTrabajadas)
                    && employee_setSueldo(newEmployee,auxSueldo))
            {//verifico que la asignacion de todos los campos se realice correctamente
                ll_add(pArrayListEmployee,newEmployee);//agrego el nuevo empleado a la lista
                error=0;
            }
        }
    }
    return error;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int error=1;
    int auxId;
    int len;
    int auxLlId;
    int auxInt;
    char auxChar[120];
    int salir=0;
    Employee* auxEmployee;


    if(pArrayListEmployee!=NULL)//verifico puntero
    {
        controller_ListEmployee(pArrayListEmployee);//imprimo lista de empleados
        printf("\n\nIngrese el Id del empleado a modificar: ");
        scanf("%d",&auxId);//leo el id del empleado a modificar
        len=ll_len(pArrayListEmployee);//leo el tamaño de la lista de empleados
        for(int i=0; i<len; i++)//recorro la lista
        {
            auxEmployee=(Employee*)ll_get(pArrayListEmployee,i);//tomo el empleado en el indice i
            employee_getId(auxEmployee,&auxLlId);//tomo el id de dicho empleado
            if(auxLlId==auxId)//verifico si coincide con el id ingresado por el usuario
            {
                do
                {
                    switch(printMenuModifAndGetOption())//imprimo menu de modificacion y leo la opcion ingresada
                    {
                    case 1://MODIFICAR NOMBRE
                        printf("Ingrese nuevo nombre: ");
                        fflush(stdin);
                        gets(auxChar);//leo nuevo nombre ingresado
                        while(strlen(auxChar)>120)//valido longitud del mismo
                        {
                            printf("Nombre fuera de rango. Reingrese : ");
                            fflush(stdin);
                            gets(auxChar);
                        }
                        if(employee_setNombre(auxEmployee,auxChar)==1)//asigno el nuevo nombre al empleado y verifico el exito de la ejecucion
                        {
                            printf("Modificacion exitosa\n\n");
                            error=0;
                        }
                        break;

                    case 2://MODIFICAR HORAS TRABAJADAS
                        printf("Ingrese nuevas horas trabajadas: ");
                        fflush(stdin);
                        scanf("%d",&auxInt);//leo nuevas horas trabajadas ingresadas
                        while(auxInt<0 || auxInt>300)//valido cantidad de horas
                        {
                            printf("Cantidad de horas fuera de rango. Reingrese: ");
                            fflush(stdin);
                            scanf("%d",&auxInt);
                        }
                        if(employee_setHorasTrabajadas(auxEmployee,auxInt)==1)//asigno las nuevas hs. trabajadas al empleado y verifico el exito de la ejecucion
                        {
                            printf("Modificacion exitosa\n\n");
                            error=0;
                        }
                        break;

                    case 3://MODIFICAR SUELDO
                        printf("Ingrese nuevo sueldo: ");
                        fflush(stdin);
                        scanf("%d",&auxInt);//leo nuevo sueldo ingresado
                        while(auxInt<0 || auxInt>1000000)//valido monto del sueldo
                        {
                            printf("Sueldo fuera de rango. Reingrese: ");
                            fflush(stdin);
                            scanf("%d",&auxInt);
                        }
                        if(employee_setSueldo(auxEmployee,auxInt)==1)//asigno el nuevo sueldo al empleado y verifico el exito de la ejecucion
                        {
                            printf("Modificacion exitosa\n\n");
                            error=0;
                        }
                        break;
                    case 4://SALIDA
                        salir=1;
                        break;
                    }
                }
                while(salir==0);
            }

        }
    }
    return error;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int error=1;
    int auxId;
    int len;
    int auxLlId;
    char confirm;
    Employee* auxEmployee;
    if(pArrayListEmployee!=NULL)//verifico puntero
    {
        controller_ListEmployee(pArrayListEmployee);//imprimo lista de empleados
        printf("\n\nIngrese el Id del empleado eliminar: ");
        fflush(stdin);
        scanf("%d",&auxId);//leo el id ingresado
        len=ll_len(pArrayListEmployee);//guardo el tamaño de la lista de empleados
        for(int i=0; i<len; i++)
        {
            auxEmployee=(Employee*)ll_get(pArrayListEmployee,i);//tomo el empleado de la lista en el indice i
            employee_getId(auxEmployee,&auxLlId);//tomo el id de dicho empleado
            if(auxLlId==auxId)//verifico si coindice con el id ingresado por el usuario
            {
                mostrarEmpleadoP(auxEmployee);//muestro el empleado a eliminar
                printf("¿Remover empleado? (s/n)");//pido confirmacion
                fflush(stdin);
                confirm=getchar();
                if(confirm=='s')
                {
                    ll_remove(pArrayListEmployee,i);//elimino al empleado de la lista
                }
                else
                {
                    break;
                }
            }
        }
    }
    return error;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int error=0;
    int tam;
    int flag=0;
    Employee* auxEmp;

    if(pArrayListEmployee!=NULL)//verifico puntero
    {
        error=1;
        printf("Id            Nombre         Hs. Trabajadas        Sueldo\n");//imprimo encabezado
        printf("---------------------------------------------------------\n");
        tam = ll_len(pArrayListEmployee);
        for(int i=1; i<tam; i++)//recorro la lista salteando el encabezado del archivo
        {
            auxEmp = (Employee*)ll_get(pArrayListEmployee,i);//tomo el empleado de la lista en el indice i
            if(auxEmp != NULL)//verifico puntero
            {
                mostrarEmpleadoP(auxEmp);//muestro dicho empleado
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("No hay empleados\n\n");//informo que no hay empleados
        }
        printf("\n\n");
    }
    return error;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int error=1;
    int opcion;
    int criterioOrdenamiento;
    char confirm='n';

    if(pArrayListEmployee!=NULL)//verifico punteros
    {

        do
        {
            system("cls");
            opcion=printMenuSortAndGetOption();//imprimo menu de ordenamiento y leo la opcion ingresada
            switch(opcion)
            {
            case 1://ORDENAR POR ID
                criterioOrdenamiento=printMenuCritOrdenamiento();//imprimo menu de criterio y leo la opcion ingresada
                while(criterioOrdenamiento!=0 && criterioOrdenamiento!=1)//valido parametros de criterio
                {
                    system("cls");
                    printf("Criterio de ordenamiento invalido.\n\n");
                    criterioOrdenamiento=printMenuCritOrdenamiento();
                };
                if(ll_sort(pArrayListEmployee,compararEmpleadosPorId,criterioOrdenamiento)==1)//ordeno la lista en funcion de los criterios seleccionados
                {
                    error=0;
                }

                break;
            case 2://ORDENAR POR NOMBRE
                criterioOrdenamiento=printMenuCritOrdenamiento();//imprimo menu de criterio y leo la opcion ingresada
                while(criterioOrdenamiento!=0 && criterioOrdenamiento!=1)//valido parametros de criterio
                {
                    system("cls");
                    printf("Criterio de ordenamiento invalido.\n\n");
                    criterioOrdenamiento=printMenuCritOrdenamiento();
                }
                if(ll_sort(pArrayListEmployee,compararEmpleadosPorNombre,criterioOrdenamiento)==1)//ordeno la lista en funcion de los criterios seleccionados
                {
                    error=0;
                }
                break;
            case 3://ORDENAR POR HORAS TRABAJADAS
                criterioOrdenamiento=printMenuCritOrdenamiento();//imprimo menu de criterio y leo la opcion ingresada
                while(criterioOrdenamiento!=0 && criterioOrdenamiento!=1)//valido parametros de criterio
                {
                    system("cls");
                    printf("Criterio de ordenamiento invalido.\n\n");
                    criterioOrdenamiento=printMenuCritOrdenamiento();
                }
                if(ll_sort(pArrayListEmployee,compararEmpleadosPorHorasTrabajadas,criterioOrdenamiento)==1)//ordeno la lista en funcion de los criterios seleccionados
                {
                    error=0;
                }
                break;
            case 4://ORDENAR POR SUELDO
                criterioOrdenamiento=printMenuCritOrdenamiento();//imprimo menu de criterio y leo la opcion ingresada
                while(criterioOrdenamiento!=0 && criterioOrdenamiento!=1)//valido parametros de criterio
                {
                    system("cls");
                    printf("Criterio de ordenamiento invalido.\n\n");
                    criterioOrdenamiento=printMenuCritOrdenamiento();
                }
                if(ll_sort(pArrayListEmployee,compararEmpleadosPorSueldo,criterioOrdenamiento)==1)//ordeno la lista en funcion de los criterios seleccionados
                {
                    error=0;
                }
                break;
            case 5://SALIDA
                printf("¿Confirma que desea salir?(s/n)");
                fflush(stdin);
                confirm=getchar();
                break;
            default:
                system("cls");
                printf("Opcion Invalida.\n\n");
                break;
            }
        }
        while(confirm=='n');
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
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* f;
    Employee* auxEmp;
    int error=0;
    int len;
    int id;
    char nombre[120];
    int horasTrabajadas;
    int sueldo;

    if(path!=NULL && pArrayListEmployee!=NULL)//verifico punteros
    {
        len=ll_len(pArrayListEmployee);//guardo el tamaño de la lista
        f=fopen(path,"w");//abro el archivo en modo escritura
        if(f!=NULL )//verifico puntero
        {
            for(int i=0; i<len; i++)//recorro la lista de empleados
            {
                auxEmp=(Employee*)ll_get(pArrayListEmployee,i);//tomo el empleado de la lista en el indice i
                employee_getId(auxEmp,&id);//tomo los datos del empleado en el indice i
                employee_getNombre(auxEmp,nombre);
                employee_getHorasTrabajadas(auxEmp,&horasTrabajadas);
                employee_getSueldo(auxEmp,&sueldo);
                fprintf(f,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);//escribo el empleado en el archivo
            }
            fclose(f);//cierro el archivo
            error=1;

        }
    }
    return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* f;//declaro puntero a archivo
    int error=0;
    int len;
    Employee* auxEmp;//declaro puntero a empleado


    if(path != NULL && pArrayListEmployee!= NULL)//verifico punteros
    {
        f=fopen(path,"wb");//abro archivo en modo escritura binaria
        len= ll_len(pArrayListEmployee);//guardo el tamaño de la lista de empleados
        if(f!=NULL)//verifico puntero
        {
            for(int i=0; i<len; i++)//recorro la lista de empleados
            {
                auxEmp=ll_get(pArrayListEmployee,i);//tomo empleado en indice i
                if(auxEmp!= NULL)//verifico punteri
                {
                    fwrite(auxEmp,sizeof(Employee),1,f);//escribo en el archivo cada empleado
                }
            }

            fclose(f);//cierro el archivo
            error=1;

        }
    }

    return error;
}


