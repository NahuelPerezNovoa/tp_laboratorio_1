#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin(modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();//Creo el linkedList

    option=printMenuAndGetOpcion();//imprimo menu principal
    do
    {
        switch(option)
        {
        case 1://     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).

            if(!controller_loadFromText("data.csv",listaEmpleados))
            {
                printf("Carga exitosa\n");
            }
            else
            {
                printf("No se pudo cargar el archivo\n");
            }
            break;

        case 2://     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).

            if(!controller_loadFromBinary("data.bin",listaEmpleados))
            {
                printf("Carga exitosa\n");
            }
            else
            {
                printf("No se pudo cargar el archivo\n");
            }
            break;

        case 3://     3. Alta de empleado

            if(!controller_addEmployee(listaEmpleados))
            {
                printf("Alta exitosa\n");
            }
            else
            {
                printf("No se pudo ejecutar el alta\n");
            }
            break;

        case 4://     4. Modificar datos de empleado

            if(ll_isEmpty(listaEmpleados)==0)//verifico que el linkedList no este vacio
            {
                if(!controller_editEmployee(listaEmpleados))
                {
                    printf("Modificacion exitosa\n");
                }
                else
                {
                    printf("No se pudo realizar la modificacion\n");
                }
            }
            else if(ll_isEmpty(listaEmpleados)==1)
            {
                printf("No hay empleados cargados\n");
            }
            break;

        case 5://     5. Baja de empleado

            if(ll_isEmpty(listaEmpleados)==0)//verifico que el linkedList no este vacio
            {
                if(controller_removeEmployee(listaEmpleados))
                {
                    printf("Baja exitosa\n");
                }
                else
                {
                    printf("No se pudo realizar la baja\n");
                }
            }
            else if(ll_isEmpty(listaEmpleados)==1)
            {
                printf("No hay empleados cargados\n");
            }
            break;

        case 6://     6. Listar empleados

            if(ll_isEmpty(listaEmpleados)==0)//verifico que el linkedList no este vacio
            {
                system("cls");
                controller_ListEmployee(listaEmpleados);
            }
            else if(ll_isEmpty(listaEmpleados)==1)
            {
                printf("No hay empleados cargados\n");
            }
            break;

        case 7://     7. Ordenar empleados

            if(ll_isEmpty(listaEmpleados)==0)//verifico que el linkedList no este vacio
            {
                if(!controller_sortEmployee(listaEmpleados))
                {
                    printf("Ordenamiento exitoso\n");
                }
                else
                {
                    printf("No se pudo realizar el ordenamiento\n");
                }
            }
            else if(ll_isEmpty(listaEmpleados)==1)
            {
                printf("No hay empleados cargados\n");
            }
            break;

        case 8://     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).

            if(controller_saveAsText("data.csv",listaEmpleados))
            {
                printf("Guardado exitoso\n");
            }
            else
            {
                printf("No se pudo guardar el archivo\n");
            }
            break;

        case 9://     9. Guardar los datos de los empleados en el archivo data.bin(modo binario).

            if(controller_saveAsBinary("data.bin",listaEmpleados))
            {
                printf("Guardado exitoso\n");
            }
            else
            {
                printf("No se pudo guardar el archivo\n");
            }
            break;
        default:
            printf("Opcion Invalida. Reingrese\n");
            break;

        }
        system("pause");
        system("cls");
        option=printMenuAndGetOpcion();//reimprimo menu principal para continuar la iteracion
    }
    while(option != 10);//    10. Salir

    ll_deleteLinkedList(listaEmpleados);//libero el linkedlist
    free(listaEmpleados);//libero el puntero a linkedlist

    return 0;
}


