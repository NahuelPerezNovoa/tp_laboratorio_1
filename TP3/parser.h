/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int Retorno 1 si hay error o 0 si Ok
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int Retorno 1 si hay error o 0 si Ok
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
