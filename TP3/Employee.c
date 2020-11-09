#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

int printMenuAndGetOpcion()
{
    int opcion;

    printf("MENU\n");
    printf("------------------------------------------------------------------------------\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin(modo binario).\n");
    printf("10. Salir\n");
    printf("------------------------------------------------------------------------------\n");
    printf("------------------------------------------------------------------------------\n\n");
    printf("Ingrese opcion: ");

    scanf("%d",&opcion);

    return opcion;
}

int printMenuModifAndGetOption()
{
    int opcion;

    printf("\nMODIFICAR\n");
    printf("--------------------\n");
    printf("1. Nombre\n");
    printf("2. Horas Trabajadas\n");
    printf("3. Sueldo\n");
    printf("4. Volver al Menu principal\n");
    printf("--------------------\n");
    printf("--------------------\n\n");
    printf("Ingrese opcion : ");

    fflush(stdin);
    scanf("%d",&opcion);
    system("cls");

    return opcion;
}

int printMenuSortAndGetOption()
{
    int opcion;

    printf("ORDENAR\n");
    printf("--------------------\n");
    printf("1. Por Id\n");
    printf("2. Por nombre\n");
    printf("3. Por horas Trabajadas\n");
    printf("4. Por sueldo\n");
    printf("5. Volver al Menu principal\n");
    printf("--------------------\n");
    printf("--------------------\n");
    printf("Ingrese opcion: ");

    fflush(stdin);
    scanf("%d",&opcion);
    system("cls");

    return opcion;
}

int printMenuCritOrdenamiento()
{
    int opcion;

    printf("CRITERIO DE ORDENAMIENTO\n");
    printf("-------------------------\n");
    printf("0. Descendente\n");
    printf("1. Ascendente\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    system("cls");

    return opcion;
}


Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));//retorno puntero a espacio para nuevo empleado
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* nuevoEmpleado = employee_new();//pido espacio y direccion para nuevo empleado
    if(nuevoEmpleado!=NULL)//verifico puntero
    {
        nuevoEmpleado->id=atoi(idStr);//escribo Id casteado a entero, en el nuevo empleado
        strcpy(nuevoEmpleado->nombre,nombreStr);//escribo nombre en el nuevo empleado
        nuevoEmpleado->horasTrabajadas=atoi(horasTrabajadasStr);//escribo horas trabajadas casteado a entero, en el nuevo empleado
        nuevoEmpleado->sueldo=atoi(sueldoStr);//escribo sueldo casteado a entero, en el nuevo empleado
    }

    return nuevoEmpleado;//devuelvo el puntero a nuevo empleado con los parametros cargados
}

void employee_delete(Employee* empleado)
{
    if(empleado!=NULL)
    {
        free(empleado);//libero el espacio en memoria de un empleado
    }
}

int employee_setId(Employee* this,int id)
{
    int error=0;

    if(this!=NULL && id>=0)
    {
        this->id=id;//asigno id al empleado pasado por referencia
        error=1;
    }

    return error;
}
int employee_getId(Employee* this,int* id)
{
    int error=0;

    if(this!=NULL && id!=NULL)
    {
        *id=this->id;//obtengo id del empleado pasado por referencia
        error=1;
    }

    return error;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int error=0;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);//asigno nombre al empleado pasado por referencia
        error=1;
    }

    return error;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int error=0;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);//obtengo nombre del empleado pasado por referencia
        error=1;
    }

    return error;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int error=0;

    if(this!=NULL && horasTrabajadas>=0)
    {
        this->horasTrabajadas=horasTrabajadas;//asigno hs. trabajadas al empleado pasado por referencia
        error=1;
    }

    return error;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int error=0;

    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;//obtengo hs. trabajadas del empleado pasado por referencia
        error=1;
    }

    return error;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int error=0;

    if(this!=NULL && sueldo>=0)
    {
        this->sueldo=sueldo;//asigno sueldo al empleado pasado por referencia
        error=1;
    }

    return error;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int error=0;

    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;//obtengo sueldo del empleado pasado por referencia
        error=1;
    }

    return error;
}
int mostrarEmpleadoP(Employee* empleado)
{
    int error = 0;
    if(empleado!=NULL)
    {
        error=1;
        printf("%4d %20s %10d hs.          $%6d\n",empleado->id,empleado->nombre,empleado->horasTrabajadas,empleado->sueldo);
        //imprimo los campos de un empleado pasado por referencia
    }
    return error;
}
/*int mostrarEmpleados(LinkedList* lista)
{
    int error=0;
    int tam = ll_len(lista);
    int flag=0;
    Employee* auxEmp;

    if(lista!=NULL)
    {
        error=1;
        printf("Id  Nombre  Hs. Trabajadas   Sueldo\n");
        printf("------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            auxEmp = (Employee*)ll_get(lista,i);
            if(auxEmp != NULL)
            {
                mostrarEmpleadoP(auxEmp);
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("No hay empleados\n\n");
        }
        printf("\n\n");
    }
    return error;
}*/

int compararEmpleadosPorId(void* emp1, void* emp2)
{
    int rta=1;
    Employee* empleado1;//declaro puntero tipo empleado para empleado1
    Employee* empleado2;//declaro puntero tipo empleado para empleado2

    if(emp1!=NULL && emp2!=NULL)//verifico punteros
    {
        empleado1 = (Employee*) emp1;//casteo y asigno direcc de memoria al puntero
        empleado2 = (Employee*) emp2;//casteo y asigno direcc de memoria al puntero
        if(empleado1->id == empleado2->id)//comparo parametros
        {
            rta=0;
        }
        else if(empleado1->id > empleado2->id)
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
int compararEmpleadosPorNombre(void* emp1, void* emp2)
{
    int rta;
    Employee* empleado1;//declaro puntero tipo empleado para empleado1
    Employee* empleado2;//declaro puntero tipo empleado para empleado2

    if(emp1!=NULL && emp2!=NULL)//verifico punteros
    {
        empleado1 = (Employee*) emp1;//casteo y asigno direcc de memoria al puntero
        empleado2 = (Employee*) emp2;//casteo y asigno direcc de memoria al puntero
        if(strcmp(empleado1->nombre,empleado2->nombre)==0)//comparo parametros
        {
            rta=0;
        }
        else if(strcmp(empleado1->nombre,empleado2->nombre)<0)
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

int compararEmpleadosPorHorasTrabajadas(void* emp1, void* emp2)
{
    int rta;
    Employee* empleado1;//declaro puntero tipo empleado para empleado1
    Employee* empleado2;//declaro puntero tipo empleado para empleado2

    if(emp1!=NULL && emp2!=NULL)//verifico punteros
    {
        empleado1 = (Employee*) emp1;//casteo y asigno direcc de memoria al puntero
        empleado2 = (Employee*) emp2;//casteo y asigno direcc de memoria al puntero
        if(empleado1->horasTrabajadas == empleado2->horasTrabajadas)
        {
            rta=0;
        }
        else if(empleado1->horasTrabajadas > empleado2->horasTrabajadas)
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

int compararEmpleadosPorSueldo(void* emp1, void* emp2)
{
    int rta;
    Employee* empleado1;//declaro puntero tipo empleado para empleado1
    Employee* empleado2;//declaro puntero tipo empleado para empleado2

    if(emp1!=NULL && emp2!=NULL)//verifico punteros
    {
        empleado1 = (Employee*) emp1;//casteo y asigno direcc de memoria al puntero
        empleado2 = (Employee*) emp2;//casteo y asigno direcc de memoria al puntero
        if(empleado1->sueldo == empleado2->sueldo)
        {
            rta=0;
        }
        else if(empleado1->sueldo > empleado2->sueldo)
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

int getNewId(LinkedList* lista)
{
    int auxId=0;
    int flag=0;
    Employee* auxEmp1;//declaro puntero tipo empleado

    if(ll_len(lista)!=0)//verifico que la lista no esté
    {
        for(int i=0; i<ll_len(lista); i++)//recorro la lista de empleados
        {
            auxEmp1=(Employee*)ll_get(lista,i);//obtengo empleado en indice i
            employee_getId(auxEmp1,&auxId);//tomo el id de dicho empleado

            if(flag==0)
            {
                auxId=auxEmp1->id;//al ser el primero lo asigno al auxiliar
                flag=1;
            }
            else
            {
                if(auxEmp1->id>auxId)//si es mayor al guardado en el auxiliar, se lo asigno al mismo
                {
                    auxId=auxEmp1->id;
                }
            }
        }

    }
    auxId++;//incremento el ultimo id guardado

    return auxId;//devuelvo nuevo id
}













