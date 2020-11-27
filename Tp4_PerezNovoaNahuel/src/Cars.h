#ifndef CARS_H_INCLUDED
#define CARS_H_INCLUDED

typedef struct
{
    int id;
    char modelo[20];
    float valor;
    int anioFab;
    int cantPuertas;
}eCar;

eCar* car_new();
eCar* car_newParametros(char* idStr,char* modeloStr,char* valorStr,char* anioStr,char* puertasStr);
int mostrarAutoP(eCar* unAuto);
int car_ListCars(LinkedList* pArrayListCars);
int buscarMayorId (LinkedList* pArrayListCars);
int indexById (LinkedList* pArrayListCars, int id);
eCar* elementById (LinkedList* pArrayListCars, int id);
int compararAutosPorAnio(void* car1, void* car2);
int sortCriterioValor(void* car);


#endif // CARS_H_INCLUDED
