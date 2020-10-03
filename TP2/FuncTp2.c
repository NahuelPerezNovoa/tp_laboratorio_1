#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "FuncTp2.h"


int initEmployees(Employee* list, int len)
{
    int error=(-1);
    if(list!=NULL && len>0)//Valido los datos que trae la funcion
    {
        for(int i=0; i<len; i++)//Recorro el array
        {
            list[i].isEmpty=1;//Inicializo todos los isEmpty en 1
        }
        error=0;
    }
    return error;
}

int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
    int error=(-1);
    int i;

    if(list!=NULL)//Valido los datos que trae la funcion
    {
        i=findEmpty(list,len);//Busco el indice de la primer estructura vacia del array
        if(i!=(-1))//Verifico que la funcion anterior no acarrée un error
        {
            //Copio todos los datos que trae la funcion respectivos al empleado, en la estructura encontrada anteriormente
            list[i].id=id;
            strcpy(list[i].name,name);
            strcpy(list[i].lastName,lastName);
            list[i].salary=salary;
            list[i].sector=sector;
            list[i].isEmpty=0;
            error=0;
        }
    }
    return error;
}

int requestData(char* name, char* lastName, float* salary, int* sector)
{
    char auxChar[150];
    int error=(-1);

    if(name!=NULL && lastName!=NULL && salary!=NULL && sector!=NULL)//Valido los datos que trae la funcion
    {

        printf("Ingrese Nombre: ");//Pido que se ingrese el nombre
        fflush(stdin);
        gets(auxChar);
        while(strlen(auxChar)>51)//Verifico que este dentro del rango del char[] de su correspondiente estructura
        {
            printf("Nombre fuera de rango. Reingrese\n");
            fflush(stdin);
            gets(auxChar);
        }
        strcpy(name,auxChar);//Copio el nombre a su correspondiente char[]

        printf("Ingrese Apellido: ");//Pido que se ingrese el apellido
        fflush(stdin);
        gets(auxChar);
        while(strlen(auxChar)>51)//Verifico que este dentro del rango del char[] de su correspondiente estructura
        {
            printf("Apellido fuera de rango. Reingrese\n");
            fflush(stdin);
            gets(auxChar);
        }
        strcpy(lastName,auxChar);//Copio el apellido a su correspondiente char[]

        printf("Ingrese Salario: ");//Pido que ingrese el salario
        scanf("%f",salary);//Lo asigno dentro de la estructura correspondiente

        printf("Ingrese Sector: ");//Pido que ingrese el sector
        scanf("%d",sector);//Lo asigno dentro de la estructura correspondiente

        error=0;
    }
    return error;
}

int printEmployees(Employee* list, int len)
{
    int error=(-1);

    if(list!=NULL && len>0)//Valido los datos que trae la funcion
    {
        for(int i=0; i<len; i++)//Recorro el array de estructura
        {
            if(!list[i].isEmpty)//Imprimo los datos de cada empleado activo encontrado
            {
                prtOneEmployee(list,i);
            }
        }
        error=0;
    }
    return error;
}

int prtOneEmployee(Employee* list, int index)
{
    int error=(-1);
    if(list!=NULL && index>(-1))//Valido los datos que trae la funcion
    {
        //Imprimo los datos del empleado elegido
        printf("%5d    %20s     %20s       $%10.2f     %2d\n",list[index].id, list[index].name, list[index].lastName, list[index].salary, list[index].sector);
        error=0;
    }
    return error;
}

int findEmployeeById(Employee* list, int len, int id)
{
    int index=(-1);
    if(list!=NULL && len>0 && id<len && id>=0)//Valido los datos que trae la funcion
    {
        for(int i=0; i<len; i++)//Recorro el array de estructura
        {
            if((list[i].id==id) && (list[i].isEmpty==0))//Busco aquel empleado activo cuyo Id coincide con el ingresado en la funcion
            {
                index=i;//Guardo el indice del empleado encontrado
                break;
            }
        }
    }
    return index;
}

int modifEmployee(Employee* list, int len, int index)
{
    int error=(-1);
    int option;

    if(list!=NULL && len>0 && index>(-1))//Valido los datos que trae la funcion
    {
        printf("\nMODIFICAR\n1.Nombre\n2.Apellido\n3.Salario\n4.Sector\n\nIngrese el campo a modificar: ");//Imprimo sub-menu de modificacion
        fflush(stdin);
        scanf("%d",&option);//Escaneo la opcion elegida por el usuario
        switch(option)//Analizo la opcion elegida e ingreso al modulo correspondiente
        {
        case 1://MODIFICACION DE NOMBRE
            printf("Ingrese nombre: ");//Pido que ingrese el nuevo nombre
            fflush(stdin);
            gets(list[index].name);//Escaneo el dato ingresado y lo asigno a la estructura del empleado en modificacion
            error=0;
            break;
        case 2://MODIFICACION DE APELLIDO
            printf("Ingrese apellido: ");//Pido que ingrese el nuevo apellido
            fflush(stdin);
            gets(list[index].lastName);//Escaneo el dato ingresado y lo asigno a la estructura del empleado en modificacion
            error=0;
            break;
        case 3://MODIFICACION DE SALARIO
            printf("Ingrese nuevo salario: ");//Pido que ingrese el nuevo salario
            scanf("%f",&list[index].salary);//Escaneo el dato ingresado y lo asigno a la estructura del empleado en modificacion
            error=0;
            break;
        case 4://MODIFICACION DE SECTOR
            printf("Ingrese nuevo sector: ");//Pido que ingrese el nuevo sector
            scanf("%d",&list[index].sector);//Escaneo el dato ingresado y lo asigno a la estructura del empleado en modificacion
            error=0;
            break;
        default://VALIDO CUALQUIER PARAMETRO INGRESADO QUE NO CORRESPONDA AL MENU
            printf("Parametro inválido");
            break;

            error=0;
        }
    }
    return error;
}

int findEmpty(Employee* list, int len)
{
    int index = (-1);

    if(list!=NULL)//Valido los datos que trae la funcion
    {
        for(int i=0; i<len; i++)//Recorro el array de estructura
        {
            if(list[i].isEmpty==1)//Busco la primer estructura que figure vacia
            {
                index=i;//Guardo el indice de dicha estructura
                break;
            }
        }
    }
    return index;//Retorno el indice de la primer estructura vacia
}

int verifNonEmptyPayroll(Employee* list, int len)
{
    int error=(-1);
    if(list!=NULL)//Valido los datos que trae la funcion
    {
        for(int i=0; i<len; i++)//Recorro el array de estructura
        {
            if(list[i].isEmpty==0)//Verifico si existe algun empleado activo
            {
                error=0;
                break;
            }
        }
    }
    return error;
}

int removeEmployee(Employee* list, int len, int id)
{
    int error=(-1);
    int index;

    if(list!=NULL && len>0)//Valido los datos que trae la funcion
    {
        index=findEmployeeById(list,len,id);//Pido el indice del empleado seleccionado
        if(index!=(-1))
        {
            list[index].isEmpty=1;//Establezco su estructura correspondiente como vacia
            error=0;
        }

    }
    return error;
}

int sortEmployees(Employee* list, int len, int order)
{

    Employee auxEmployee;//Estructura auxiliar para el ordenamiento
    int error=(-1);

    if(list!=NULL && len>0 && (order=='1' || order=='0'))//Valido los datos que trae la funcion
    {
        for(int i=0; i<len-1; i++)//Comienzo interacion 1 del burbujeo
        {
            for(int j=i+1; j<len; j++)//Iteracion 2 del burbujeo
            {
                if((strcmp(list[i].lastName,list[j].lastName)<0 && order=='1') || (strcmp(list[i].lastName,list[j].lastName)>0 && order=='0'))//Ejecuto el ordenamiento en funcion del criterio seleccionado
                {
                    auxEmployee=list[i];
                    list[i]=list[j];
                    list[j]=auxEmployee;
                }
                else if(strcmp(list[i].lastName,list[j].lastName)==0)//En caso de que existan dos apellidos iguales, realizo la comparacion por sector
                {
                    if((list[i].sector>list[j].sector && order=='0') || (list[i].sector<list[j].sector && order=='1'))//Ejecuto el ordenamiento en funcion del criterio seleccionado
                    {
                        auxEmployee=list[i];
                        list[i]=list[j];
                        list[j]=auxEmployee;
                    }
                }
            }
            error=0;
        }
    }
    return error;
}

int salaryInfo(Employee* list, int len)
{
    float acumSalarios=0;//Variable en la cual se suman los salarios de todos los empleados activos
    int contadorSalarios=0;//Variable que cuenta cuantos empleados activos se encuentran en la nomina
    float promedioSalarios;//Variable que almacena el promedio de los salarios
    int contadorSalarioMayorAPromedio=0;//Variable que cuenta cuantos empleados activos superan el salario promedio
    int error=(-1);

    if(list!=NULL)//Valido los datos que trae la funcion
    {
        if(verifNonEmptyPayroll(list,len)!=0)//Verifico que la nomina no esté vacía
        {
            printf("La nomina esta vacia\n");
        }
        else
        {
            for(int i=0; i<len; i++)//Recorro el array de estructura
            {
                if(list[i].isEmpty==0)//Busco empleados activos
                {
                    acumSalarios+=list[i].salary;//Sumo el salario de cada empleado activo al acumulador
                    contadorSalarios++;//Cuento la cantidad de empleados activos encontrados
                }
            }
            promedioSalarios=(float)acumSalarios/contadorSalarios;//Realizo el calculo de salario promedio
            for(int i=0; i<len; i++)//Recorro el array de estructura
            {
                if(list[i].salary>=promedioSalarios && list[i].isEmpty==0)//Busco empleados activos que superen el salario promedio
                {
                    contadorSalarioMayorAPromedio++;//Cuento la cantidad de empleados activos que sumperan el salario promedio
                }
            }
            printf("\n\nREPORTE DE SALARIOS\nEl monto total de los salarios es $%.2f\nEl promedio de los salarios es $%.2f\n%d empleados superan el salario promedio\n",acumSalarios,promedioSalarios,contadorSalarioMayorAPromedio);
            //Imprimo el reporte de salarios
            error=0;
        }


    }
    return error;
}
