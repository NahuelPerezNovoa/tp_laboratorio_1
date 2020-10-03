#ifndef FUNCTP2_H_INCLUDED
#define FUNCTP2_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;

#endif // FUNCTP2_H_INCLUDED



/** \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array
 *
 * \param list Employee* Pointer to the array of employees
 * \param len int Array lenght
 * \return int Return (-1) if ERROR [Invalid lenght or NULL pointer] - (0) if ok
 *
 */
int initEmployees(Employee* list, int len);

/** \brief add in a existing list of employees the values received as parameters in the first empty position
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid lenght or NULL pointer or without free space] - (0) if ok
 *
 */
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);

/** \brief Request necessary data to add a employee in the payroll
 *
 * \param name char*
 * \param lastName char*
 * \param salary float*
 * \param sector int*
 * \return int Return (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
int requestData(char *name, char *lastName, float *salary, int *sector);

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param len int
 * \return int Return (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
int printEmployees(Employee* list, int len);

/** \brief print array of selected employee
 *
 * \param list Employee*
 * \param index int array index of selected employee
 * \return int Return (-1) if Error [NULL pointer or isEmpty==1] - (0) if Ok
 *
 */
int prtOneEmployee(Employee* list, int index);

/** \brief Find an Employee by Id and returns the index position in array
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return employee index position or (-1) if [Invalid lenght, NULL pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len, int id);

/** \brief Analyze the desired modification, and carry it out
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [NULL pointer, invalid lenght]
 *
 */
int modifEmployee(Employee* list, int len, int index);

/** \brief Find first place empty
 *
 * \param list Employee*
 * \param len int
 * \return int Return index of the 1st place empty or (-1) if Error [NULL pointer or empty place not founded]
 *
 */
int findEmpty(Employee* list, int len);

/** \brief Check the array and verify that there is almost one employee charged and active
 *
 * \param list Employee*
 * \param len int
 * \return int Return (-1) if the array have not charged an active employee
 *
 */
int verifNonEmptyPayroll(Employee* list, int len);

/** \brief Remove a Employee by Id (put isEmptyFlag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid lenght or NULL pointer or if can't find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id);

/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order);

/** \brief Run the necessary calcs for the salary report
 *
 * \param list Employee*
 * \param len int
 * \return int Return (-1) if ERROR [Invalid lenght or NULL pointer] - (0) if Ok
 *
 */
int salaryInfo(Employee* list, int len);

