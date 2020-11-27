#ifndef Files_H_INCLUDED
#define Files_H_INCLUDED


int parser_CarsFromText(FILE* pFile, LinkedList* pArrayListCars);
int controller_loadFromText(char* path, LinkedList* pArrayListCars);
int controller_saveAsText(char* path, LinkedList* pArrayListCars);

#endif // Files_H_INCLUDED
