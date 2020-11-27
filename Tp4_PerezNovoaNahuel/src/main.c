#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "Cars.h"
#include "Files.h"



int main()
{
    LinkedList* listaAutos;
    LinkedList* auxLista;
    LinkedList* auxLista2;
    int auxInt;
    eCar auxCar;
    eCar* pAux;
    eCar* pAux2;
    int index;
    int len;

    printf("***************************************************************\n");
    printf("-----------------UTILIZACION LL_NEWLINKEDLIST------------------\n" );
    printf("***************************************************************\n");
    listaAutos = ll_newLinkedList();//Creo el linkedList
    if(listaAutos!=NULL)
    {
        printf("LinkeList creada con exito en la siguiente direccion de\nmemoria: %p\n\n\n",&listaAutos);
    }
    else
    {
        printf("Falla al crear LinkedList\n\n");
    }
    system("pause");
    system("cls");


    printf("***************************************************************\n");
    printf("--------------------UTILIZACION LL_ISEMPTY---------------------\n" );
    printf("***************************************************************\n");

    if(ll_isEmpty(listaAutos))
    {
        printf("LinkedList Vacia (ll_isEmpty = 1)\n\n");
    }
    else
    {
        printf("LinkedList Cargada (ll_isEmpty = 0)\n\n");
        car_ListCars(listaAutos);
    }

    if(!controller_loadFromText("data.csv",listaAutos))
    {
        printf("Carga de Archivo realizada correctamente\n\n");
    }
    else
    {
        printf("No se pudo realizar la carga del archivo\n\n");
    }
    if(ll_isEmpty(listaAutos))
    {
        printf("LinkedList Vacia (ll_isEmpty = 1)\n\n");
    }
    else
    {
        printf("LinkedList Cargada (ll_isEmpty = 0)\n\n");
        car_ListCars(listaAutos);
    }

    system("pause");
    system("cls");

    printf("***************************************************************\n");
    printf("----------------------UTILIZACION LL_LEN-----------------------\n" );
    printf("***************************************************************\n");

    if(ll_isEmpty(listaAutos))
    {
        printf("Lista Vacia\n\n");
    }
    else
    {
        printf("La cantidad de elementos cargados en la lista es: %d\n\n",ll_len(listaAutos));
    }
    system("pause");
    system("cls");

    printf("***************************************************************\n");
    printf("----------------------UTILIZACION LL_GET-----------------------\n" );
    printf("***************************************************************\n");

    car_ListCars(listaAutos);
    printf("\n\n");
    printf("Ingrese el id del auto que desea obtener y mostrar: ");
    fflush(stdin);
    scanf("%d",&auxInt);
    while(auxInt<=0 || auxInt>buscarMayorId(listaAutos))
    {
        printf("\nID invalido, reingrese: ");
        scanf("%d",&auxInt);
        printf("\n");
    }
    auxInt=indexById(listaAutos,auxInt);
    pAux =(eCar*) ll_get(listaAutos,auxInt);
    printf("\n");
    mostrarAutoP(pAux);
    printf("\n");

    system("pause");
    system("cls");

    printf("***************************************************************\n");
    printf("---------------------UTILIZACION LL_INDEXOF--------------------\n" );
    printf("***************************************************************\n");

    car_ListCars(listaAutos);
    printf("\n\n");
    printf("Ingrese el id del auto del cual desea conocer su indice en la\nLinkedList: ");
    fflush(stdin);
    scanf("%d",&auxInt);
    while(auxInt<=0 || auxInt>buscarMayorId(listaAutos))
    {
        printf("\nID invalido, reingrese: ");
        scanf("%d",&auxInt);
        printf("\n");
    }
    index= ll_indexOf(listaAutos,elementById(listaAutos,auxInt));
    printf("\nEl indice del auto selecconado es: %d\n\n",index);


    system("pause");
    system("cls");

    printf("***************************************************************\n");
    printf("----------------------UTILIZACION LL_SET-----------------------\n" );
    printf("***************************************************************\n");

    auxCar.id = (buscarMayorId(listaAutos)+1);
    strcpy(auxCar.modelo,"Virtus");
    auxCar.valor = 670000;
    auxCar.anioFab = 2019;
    auxCar.cantPuertas = 4;
    pAux = &auxCar;

    printf("Modificaremos el un auto de la LinkedList reemplazandolo por el siguiente elemento: \n\n");
    mostrarAutoP(pAux);
    printf("\n\nSeleccione el ID del auto que desea reemplazar\n");
    car_ListCars(listaAutos);
    printf("\nID seleccionado: ");
    fflush(stdin);
    scanf("%d",&auxInt);
    while(auxInt<=0 || auxInt>buscarMayorId(listaAutos))
    {
        printf("\nID invalido, reingrese: ");
        scanf("%d",&auxInt);
        printf("\n");
    }
    index = ll_indexOf(listaAutos,ll_get(listaAutos,auxInt));
    pAux = car_new();
    pAux->id = auxCar.id;
    strcpy(pAux->modelo,auxCar.modelo);
    pAux->valor = auxCar.valor;
    pAux->anioFab=auxCar.anioFab;
    pAux->cantPuertas = auxCar.cantPuertas;
    if(!ll_set(listaAutos,index-1,pAux))
    {
        printf("Reemplazo exitoso\n\n");
        car_ListCars(listaAutos);
    }
    else
    {
        printf("Error al reemplazar elemento\n\n");
    }

    system("pause");
    system("cls");

    printf("***************************************************************\n");
    printf("--------------------UTILIZACION LL_REMOVE----------------------\n" );
    printf("***************************************************************\n");

    printf("Removeremos el elemento agregado anteriormente mediante la funcion ll_remove\n\n");
    if(!ll_remove(listaAutos,index-1))
    {
        printf("Remocion exitosa\n\n");
        car_ListCars(listaAutos);
    }
    else
    {
        printf("Falló la remocion del elemento");
    }

    system("pause");
    system("cls");

    printf("***************************************************************\n");
    printf("----------------------UTILIZACION LL_ADD-----------------------\n" );
    printf("***************************************************************\n");

    printf("Agregaremos al final de la lista el mismo elemento utilizado\nanteriormente, mediante la funcion ll_add.\n\n");
    if(!ll_add(listaAutos,pAux))
    {
        printf("Elemento agregado de forma exitosa\n\n");
        car_ListCars(listaAutos);
    }
    else
    {
        printf("Error al agregar el elemento\n\n");
    }

    system("pause");
    system("cls");

    printf("***************************************************************\n");
    printf("----------------------UTILIZACION LL_PUSH----------------------\n" );
    printf("***************************************************************\n");

    auxCar.id = (buscarMayorId(listaAutos)+1);
    strcpy(auxCar.modelo,"Camaro");
    auxCar.valor = 1350000;
    auxCar.anioFab = 2016;
    auxCar.cantPuertas = 2;
    len = ll_len(listaAutos);

    printf("Insertaremos el siguiente elemento en la posicion deseada\n\n");
    printf("\n\nIngrese el indice donde quiere insertar el elemento(Entre 0 y %d): ",len-1);
    scanf("%d",&auxInt);
    while(auxInt<0 || auxInt>=len)
    {
        printf("\nIndice invalido, reingrese: ");
        scanf("%d",&auxInt);
        printf("\n");
    }
    pAux = car_new();
    pAux->id = auxCar.id;
    strcpy(pAux->modelo,auxCar.modelo);
    pAux->valor = auxCar.valor;
    pAux->anioFab=auxCar.anioFab;
    pAux->cantPuertas = auxCar.cantPuertas;

    if(!ll_push(listaAutos,auxInt,pAux))
    {
        printf("\n\nElemento agregado de forma exitosa\n\n");
        car_ListCars(listaAutos);
    }
    else
    {
        printf("Error al agregar el elemento\n\n");
    }


    system("pause");
    system("cls");

    printf("***************************************************************\n");
    printf("----------------------UTILIZACION LL_POP-----------------------\n");
    printf("***************************************************************\n");

    printf("Removeremos el elemento deseado mediante la funcion ll_pop\n\n");

    printf("\nSeleccione el ID del auto que desea eliminar\n\n");
    car_ListCars(listaAutos);
    printf("\nID seleccionado: ");
    fflush(stdin);
    scanf("%d",&auxInt);
    while(auxInt<=0 || auxInt>buscarMayorId(listaAutos))
    {
        printf("\nID invalido, reingrese: ");
        scanf("%d",&auxInt);
        printf("\n");
    }
    index = ll_indexOf(listaAutos,ll_get(listaAutos,auxInt));
    printf("\nSe ha eliminado el siguiente elemento:\n");
    mostrarAutoP(ll_pop(listaAutos,index-1));
    printf("\n\nLa lista queda conformada de la siguiente manera:\n\n");
    car_ListCars(listaAutos);


    system("pause");
    system("cls");


    printf("***************************************************************\n");
    printf("--------------------UTILIZACION LL_CONTAINS--------------------\n" );
    printf("***************************************************************\n");

    pAux =(eCar*) ll_get(listaAutos,5);

    auxCar.id = 17;
    strcpy(auxCar.modelo,"C350");
    auxCar.valor = 1800000;
    auxCar.anioFab = 2013;
    auxCar.cantPuertas = 4;
    pAux2 = &auxCar;

    printf("Le pasaremos dos elementos a la funcion ll_contains a fin de\ndeterminar si los mismos se encuentran en la lista.\n\n");
    printf("ELEMENTO 1\n");
    mostrarAutoP(pAux);
    printf("\nELEMENTO 2\n");
    mostrarAutoP(pAux2);
    printf("\n\n\n");
    if(ll_contains(listaAutos,pAux) ==1 )
    {
        index = ll_indexOf(listaAutos,pAux);
        if(index!=-1)
        {
            printf("El elemento 1 se encuentra en la lista en el indice %d\n",index);
        }
    }
    else
    {
        printf("El elemento 1 no se encuentra en la lista\n");
    }

    if(ll_contains(listaAutos,pAux2) == 1)
    {
        index = ll_indexOf(listaAutos,pAux2);
        if(index!=-1)
        {
            printf("El elemento 2 se encuentra en la lista en el indice %d\n",index);
        }
    }
    else
    {
        printf("El elemento 2 no se encuentra en la lista\n");
    }

    printf("\n\n");

    system("pause");
    system("cls");

    printf("***************************************************************\n");
    printf("--------------------UTILIZACION LL_SUBLIST---------------------\n" );
    printf("***************************************************************\n");

    printf("Crearemos una sublista desde el indice 3 (inclusive) al indice\n7 con lafuncion ll_sublist.\n\n");
    auxLista = ll_subList(listaAutos,3,7);
    if(auxLista!=NULL)
    {
        printf("Sublista creada con exito\n\n");
        car_ListCars(auxLista);
    }
    else
    {
        printf("Error al crear la sublista\n\n");
    }

    system("pause");
    system("cls");

    printf("***************************************************************\n");
    printf("------------------UTILIZACION LL_CONTAINSALL-------------------\n" );
    printf("***************************************************************\n");

    printf("Confirmaremos mediante la funcion ll_containsAll, si todos los\nelementos de la sublista creada anteriormente estan incluidos\nen la lista original.\n\n");
    printf("LISTA ORIGINAL\n");
    car_ListCars(listaAutos);
    printf("\n\n");
    printf("SUBLISTA\n");
    car_ListCars(auxLista);
    printf("\n\n");

    auxInt = ll_containsAll(listaAutos,auxLista);
    if(auxInt==1)
    {
        printf("CONFIRMADO\nTodos los elementos de la sublista se encuentran tambien\ndentro de la lista original.\n\n");
    }
    else if(auxInt==0)
    {
        printf("Uno o mas de los elementos de la sublista no se encuentran en\nla lista original.\n\n");
    }
    else
    {
        printf("Error al ejecutar la funcion.\n\n");
    }

    system("pause");
    system("cls");

    printf("***************************************************************\n");
    printf("---------------------UTILIZACION LL_CLONE----------------------\n" );
    printf("***************************************************************\n");

    printf("Crearemos una lista identica a la original, pero en una direcc.\nde memoria diferente.\n\n");
    auxLista = ll_clone(listaAutos);

    if(auxLista!=NULL)
    {
        printf("LISTA ORIGINAL (%p)\n",listaAutos);
        car_ListCars(listaAutos);
        printf("\n\n");
        printf("LISTA CLONADA (%p)\n",auxLista);
        car_ListCars(auxLista);
        printf("\n\n");
    }
    else
    {
        printf("Error al crear la lista clon\n\n");
    }

    system("pause");
    system("cls");

    printf("***************************************************************\n");
    printf("---------------------UTILIZACION LL_SORT-----------------------\n" );
    printf("***************************************************************\n");

    printf("Realizaremos un ordenamiento sobre la lista clonada en base al\nanio de fabricacion de cada auto, con la funcion ll_sort.\n\n");
    if(!ll_sort(auxLista,compararAutosPorAnio,0))
    {
        printf("LISTA ORIGINAL (%p)\n",listaAutos);
        car_ListCars(listaAutos);
        printf("\n\n");
        printf("LISTA CLONADA ORDENADA (%p)\n",auxLista);
        car_ListCars(auxLista);
        printf("\n\n");
    }
    else
    {
        printf("Error al realizar el ordenamiento\n\n");
    }


    system("pause");
    system("cls");

    printf("***************************************************************\n");
    printf("--------------------UTILIZACION LL_FILTER----------------------\n" );
    printf("***************************************************************\n");

    printf("Utilizaremos la funcion ll_filter para crear una sublista con\nlos autos cuyos valores cumplen con el criterio.\nEn este caso el criterio sera que superen los $1.500.000\n\n");
    auxLista2 = ll_filter(listaAutos,sortCriterioValor);
    if(auxLista2 != NULL)
    {
        printf("Lista creada con exito.\n\n");
        printf("LISTA ORIGINAL (%p)\n",listaAutos);
        car_ListCars(listaAutos);
        printf("\n\n");
        printf("LISTA CLONADA (%p)\n",auxLista);
        car_ListCars(auxLista);
        printf("\n\n");
        printf("LISTA FILTRADA (%p)\n",auxLista2);
        car_ListCars(auxLista2);
        printf("\n\n");
    }
    else
    {
        printf("Error al crear la lista filtrada");
    }

    system("pause");
    system("cls");

    printf("***************************************************************\n");
    printf("---------------------UTILIZACION LL_CLEAR----------------------\n" );
    printf("***************************************************************\n");

    printf("Borraremos todos los elementos de la lista filtrada mediante la\nfuncion ll_clear\n\n");
    if(!ll_clear(auxLista2))
    {
        printf("Cantidad de elementos en lista filtrada: %d\n",ll_len(auxLista2));
        printf("La lista filtrada de la direccion %p no contiene ningun elemento.\n\n",auxLista2);
    }
    else
    {
        printf("Error al borrar los elementos de la lista filtrada\n\n");
    }
    free(auxLista2);

    system("pause");
    system("cls");


    printf("***************************************************************\n");
    printf("---------------UTILIZACION LL_DELETELINKEDLIST-----------------\n" );
    printf("***************************************************************\n");

    printf("Eliminaremos mediante la funcion ll_deletelinkedist la lista\nclonada creada anteriormente en la direccion %p.\n\n",auxLista);

    if(!ll_deleteLinkedList(auxLista))
    {
        printf("Lista clonada eliminada con exito\n\n");
    }
    else
    {
        printf("Error al eliminar la lista clonada\n\n");
    }

    system("pause");
    system("cls");

    printf("***************************************************************\n");
    printf("---------------------------SAVE FILE---------------------------\n" );
    printf("***************************************************************\n");

    if(controller_saveAsText("data.csv",listaAutos))
    {
        printf("Archivo guardado con exito\n\n");
    }
    else
    {
        printf("Error al guardar el archivo\n\n");
    }

    system("pause");
    system("cls");

    printf("***************************************************************\n");
    printf("-----------------------FIN DEL PROGRAMA------------------------\n" );
    printf("***************************************************************\n");




    return 0;
}
