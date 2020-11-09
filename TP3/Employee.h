#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;




/** \brief Imprime el menu principal
 *
 * \return int Retorna la opcion ingresada
 *
 */
int printMenuAndGetOpcion();



/** \brief Imprime el menu de modificacion
 *
 * \return int Retorna la opcion ingresada
 *
 */
int printMenuModifAndGetOption();



/** \brief Imprime el menu de ordenamiento
 *
 * \return int Retorna la opcion ingresada
 *
 */
int printMenuSortAndGetOption();



/** \brief  Imprime el menu de criterio de ordenamiento
 *
 * \return int Retorna la opcion ingresada
 *
 */
int printMenuCritOrdenamiento();
//-------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------


/** \brief Pide espacio en memoria para un empleado
 *
 * \return Employee* Retorna el puntero a dicho espacio de memoria
 *
 */
Employee* employee_new();



/** \brief Pido espacio para nuevo empleado y le asigno los parametros
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param salarioStr char*
 * \return Employee* Retorna el puntero a dicho espacio de memoria
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* salarioStr);



/** \brief Elimina un empleado
 *
 * \param empleado Employee*
 * \return void
 *
 */
void employee_delete(Employee* empleado);
//-------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------



/** \brief Asigna Id a un empleado
 *
 * \param this Employee*
 * \param id int
 * \return int Devuelve 0 si hay error o = si Ok
 *
 */
int employee_setId(Employee* this,int id);



/** \brief //toma el id de un empleado
 *
 * \param this Employee*
 * \param id int*
 * \return int Devuelve 0 si hay error o = si Ok
 *
 */
int employee_getId(Employee* this,int* id);
//-------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------




/** \brief Asigno nombre a un empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int Devuelve 0 si hay error o = si Ok
 *
 */
int employee_setNombre(Employee* this,char* nombre);



/** \brief toma el nombre de un empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int Devuelve 0 si hay error o = si Ok
 *
 */
int employee_getNombre(Employee* this,char* nombre);
//-------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------

/** \brief Asgina hs trabajadas a un empleado
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int Devuelve 0 si hay error o = si Ok
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);



/** \brief tomo las horas trabajadas de un empleado
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int Devuelve 0 si hay error o = si Ok
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
//-------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------

/** \brief Asigno sueldo a un empleado
 *
 * \param this Employee*
 * \param sueldo int
 * \return int Devuelve 0 si hay error o = si Ok
 *
 */
int employee_setSueldo(Employee* this,int sueldo);



/** \brief toma el sueldo de un empleado
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int Devuelve 0 si hay error o = si Ok
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);
//-------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------

/** \brief Muestra en pantalla un empleado
 *
 * \param empleado Employee*
 * \return int Devuelve 0 si hay error o = si Ok
 *
 */
int mostrarEmpleadoP(Employee* empleado);
//int mostrarEmpleados(LinkedList* lista);
//-------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------

/** \brief compara dos empleados por su id
 *
 * \param emp1 void*
 * \param emp2 void*
 * \return int Devuelve 0 si los parametros son iguales, -1 si emp1<emp2 o 1 si emp1>emp2
 *
 */
int compararEmpleadosPorId(void* emp1, void* emp2);



/** \brief compara dos empleados por su nombre
 *
 * \param emp1 void*
 * \param emp2 void*
 * \return int Devuelve 0 si los parametros son iguales, -1 si emp1<emp2 o 1 si emp1>emp2
 *
 */
int compararEmpleadosPorNombre(void* emp1, void* emp2);



/** \brief compara dos empleados porsus horas trabajadas
 *
 * \param emp1 void*
 * \param emp2 void*
 * \return int Devuelve 0 si los parametros son iguales, -1 si emp1<emp2 o 1 si emp1>emp2
 *
 */
int compararEmpleadosPorHorasTrabajadas(void* emp1, void* emp2);



/** \brief compara dos empleados por su sueldo
 *
 * \param emp1 void*
 * \param emp2 void*
 * \return int Devuelve 0 si los parametros son iguales, -1 si emp1<emp2 o 1 si emp1>emp2
 *
 */
int compararEmpleadosPorSueldo(void* emp1, void* emp2);
//-------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------



/** \brief crea un nuevo id
 *
 * \param lista LinkedList*
 * \return int Devuelve nuevo id
 *
 */
int getNewId(LinkedList* lista);



#endif // employee_H_INCLUDED
