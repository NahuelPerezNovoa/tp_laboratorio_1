#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "FuncTp2.h"

#define TAM 1000

int main()
{
    Employee payroll[TAM];//Declaro el array de estructuras a utilizar
    char flagExit=0;//Bandera de fin del programa
    char exitConfirm;//Variable de confirmacion de salida
    int option;//Variable que almacena la opcion elegida del menu principal
    int id=1;//Variable tipo contador que indica el proximo Id a utilizar
    char name[51];//Auxiliar de nombre para el ingreso de empleado
    char lastName[51];//Auxiliar de apellido para el ingreso de empleado
    float salary;//Auxiliar de salario para el ingreso de empleado
    int sector;//Auxiliar de sector para el ingreso de empleado
    int idToFind;//Variable que almacena el Id a buscar
    int index;//Variable que almacena el indice del empleado buscado
    char bajaConfirm;//Variable de confirmacion de baja
    char criterioOrdenamiento;//Variable que almacena el criterio de ordenamiento del array elegido por el ususario


    if (initEmployees(payroll,TAM)==(-1))//INICIALIZO IsEmpty Y VERIFICO ERROR
    {
        printf("ERROR. No se pudo inicializar la nomina\n");
        flagExit=1;
        system("pause");
    }

    while(!flagExit)//INICIO ITERACION DE MENÚ
    {

        printf("--------------------\n---MENU PRINCIPAL---\n--------------------\n1_Alta\n2_Modificacion\n3_Baja\n4_Informar\n5_Salir\n--------------------\n");
        fflush(stdin);
        scanf("%d",&option);//Escaneo la opcion elegida por el usuario del menu principal
        switch(option)//Ingreso en el modulo de la funcion elegida
        {
        case 1://DAR DE ALTA
            if(requestData(name,lastName,&salary,&sector)==0)//Realizo la toma de datos por funcion y verifico Error
            {
                if(addEmployee(payroll, TAM, id, name, lastName, salary, sector)==(-1))
                {
                    printf("La nomina está completa.\n");
                }
                else
                {
                    printf("\nAlta exitosa\n\n");
                    id++;//Si el alta fue exitosa, incremento el numero Id asi esta listo para el proximo ingreso
                }
            }
            break;

        case 2://MODIFICAR
            if(verifNonEmptyPayroll(payroll,TAM)==0)//Verifico que haya al menos un empleado ingresado en la nomina
            {
                printf("    ID                 NOMBRE                 APELLIDO          SALARIO    SECTOR\n");//Imprimo encabezado
                printEmployees(payroll,TAM);//Imprimo la nomina de empleados activos
                printf("\nIngrese el ID del empleado que desea modificar: ");
                scanf("%d",&idToFind);//Escaneo el Id elegido por el usuario
                while(findEmployeeById(payroll,TAM,idToFind)==(-1))//Verifico que el Id ingresado exista en la nomina y que esté activo
                {
                    printf("Id invalido. Reingrese: ");
                    fflush(stdin);
                    scanf("%d",&idToFind);
                }
                index=findEmployeeById(payroll,TAM,idToFind);//Guardo el indice del empleado a modificar
                printf("\n\nEmpleado a modificar:\n");
                printf("    ID                 NOMBRE                 APELLIDO          SALARIO    SECTOR\n");
                prtOneEmployee(payroll,index);//Muestro al empleado a modificar
                while(modifEmployee(payroll,TAM,index)==(-1))//Ejecuto funcion de modificacion de datos y verifico Error
                {
                    printf("\nReingrese\n");
                }
                printf("Modificacion exitosa\n");
            }

            else
            {
                printf("No hay empleados activos en la nomina\n");
            }

            break;

        case 3://DAR DE BAJA
            if(verifNonEmptyPayroll(payroll,TAM)==0)//Verifico que haya al menos un empleado ingresado en la nomina
            {
                printf("    ID                 NOMBRE                 APELLIDO          SALARIO    SECTOR\n");//Imprimo encabezado
                printEmployees(payroll,TAM);//Imprimo la nomina de empleados activos
                printf("\nIngrese el ID del empleado que desea dar de baja: ");
                scanf("%d",&idToFind);//Escaneo el Id elegido por el usuario
                while(findEmployeeById(payroll,TAM,idToFind)==(-1))//Verifico que el Id ingresado exista en la nomina y que esté activo
                {
                    printf("Id invalido. Reingrese: ");
                    fflush(stdin);
                    scanf("%d",&idToFind);
                }
                index=findEmployeeById(payroll,TAM,idToFind);//Guardo el indice del empleado a modificar
                printf("\n\nEmpleado a elminar de la nomina:\n");
                printf("    ID                 NOMBRE                 APELLIDO          SALARIO    SECTOR\n");
                prtOneEmployee(payroll,index);//Muestro al empleado a modificar
                printf("Confirma la baja? (y/n)");//Pido confirmacion de baja
                fflush(stdin);
                bajaConfirm=getche();
                bajaConfirm=tolower(exitConfirm);
                if(bajaConfirm=='y')//Si confirma la baja, ejecuto la funcion de remocion de empleado
                {
                    removeEmployee(payroll,TAM,index);
                    printf("\nBaja exitosa\n");
                }
                else//Informo que decidió cancelar la baja
                {
                    printf("\nBaja cancelada\n");
                }
            }
            else
            {
                printf("No hay empleados activos en la nomina\n");
            }
            break;

        case 4://INFORMAR
            if(verifNonEmptyPayroll(payroll,TAM)==0)//Verifico que haya al menos un empleado ingresado en la nomina
            {
                printf("\nINFORMAR:\n1.Lista de empleados\n2.Info salarios\n\nIngrese la opcion deseada: ");//Sub-menu de informe
                fflush(stdin);
                switch(getchar())//Tomo la opcion elegida por el usuario e ingreso al modulo correspondiente
                {
                case '1'://Informar lista de empleados
                    printf("\n\nORDEN:\n0. A-Z / Ascendente\n1. Z-A / Descendente\n\nIngrese la opcion deseada: ");//Sub-sub-menu de informe
                    fflush(stdin);
                    criterioOrdenamiento=getchar();//Escaneo el criterio de ordenamiento elegido por el usuario
                    sortEmployees(payroll,TAM,criterioOrdenamiento);//Ejecuto la funcion de ordenado del array en funcion del criterio elegido
                    printf("\n    ID                 NOMBRE                 APELLIDO          SALARIO    SECTOR\n");//Imprimo encabezado
                    printEmployees(payroll,TAM);//Imprimo la nomina de empleados activos, ya ordenada
                    break;
                case '2':
                    salaryInfo(payroll,TAM);//Ejecuto la funcion de informe de salarios
                }
            }
            else
            {
                printf("No hay empleados activos en la nomina\n");
            }
            break;

        case 5://SALIDA DEL PROGRAMA
            printf("Confirma que desea salir?(y/n)\n");//Pido confirmacion de salida
            fflush(stdin);
            exitConfirm=getchar();
            exitConfirm=tolower(exitConfirm);
            if(exitConfirm=='y')
            {
                flagExit=1;
            }
            break;

        default://VALIDO CUALQUIER INGRESO QUE NO CORRESPONDA AL MENU PRINCIPAL
            printf("Parametro invalido. Reingrese\n");
            break;
        }
        system("pause");
        system("cls");

    }



    return 0;
}

