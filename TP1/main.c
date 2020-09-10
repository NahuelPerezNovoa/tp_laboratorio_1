#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "funcionesTP1.h"


int main()
{
    int opcion;
    int num1;
    int num2;
    int suma;
    int resta;
    int multiplicacion;
    float division;
    long long int factorial1;
    long long int factorial2;
    char banderaSalida=0;
    char banderaNum1=0;
    char banderaNum2=0;
    char banderaCalculado=0;

    printf("MENU DE OPCIONES\n1. Ingresar 1er operando (A=x)\n2. Ingresar 2do operando (B=y)\n3. Calcular todas las operaciones\n    a)Calcular la suma (A+B)\n    b) Calcular la resta (A-B)\n    c) Calcular la division (A/B)\n    d) Calcular la multiplicacion (A*B)\n    e) Calcular el factorial (A!) y (B!)\n4. Informar resultados\n    a) El resultado de A+B\n    b) El resultado de A-B\n    c) El resultado de A/B\n    d) El resultado de A*B\n    e) El factorial de (A!) y (B!)\n5. Salir\n\n");
    //IMPRIMO MENU E INICIO EL BUCLE DE ENTRADA/SALIDA
    while(!banderaSalida)//EJECUTO EL BUCLE MIENTRAS QUE BANDERA DE SALIDA ESTÉ EN 0. CAMBIA DE ESTADO INGRESANDO OPCION 5
    {
        scanf("%d",&opcion);
        switch (opcion)//ANALIZO LA OPCION INGRESADA
        {
        case 1://INGRESAR PRIMER OPERANDO
            printf("\nEligio la opcion 1, ingrese el 1er operando: ");
            scanf("%d",&num1);
            banderaNum1=1; //BANDERA DE CONFIRMACION DE INGRESO EL 1ER OPERANDO
            if(!banderaNum2)//PREGUNTO SI SE INGRESO EL SEGUNDO OPERANDO PARA SABER SI REEMPLAZO UNA O DOS VARIABLES EN EL MENU
            {//REEMPLAZO SOLO X EN EL MENU
                system("cls");
                printf("MENU DE OPCIONES\n1. Ingresar 1er operando (A=%d)\n2. Ingresar 2do operando (B=y)\n3. Calcular todas las operaciones\n    a)Calcular la suma (%d+B)\n    b) Calcular la resta (%d-B)\n    c) Calcular la division (%d/B)\n    d) Calcular la multiplicacion (%d*B)\n    e) Calcular el factorial (%d!) y (B!)\n4. Informar resultados\n    a) El resultado de A+B\n    b) El resultado de A-B\n    c) El resultado de A/B\n    d) El resultado de A*B\n    e) El factorial de (A!) y (B!)\n5. Salir\n\n",num1,num1,num1,num1,num1,num1);
            }
            else
            {//REEMPLAZO X E Y EN EL MENU
                system("cls");
                printf("MENU DE OPCIONES\n1. Ingresar 1er operando (A=%d)\n2. Ingresar 2do operando (B=%d)\n3. Calcular todas las operaciones\n    a)Calcular la suma (%d+%d)\n    b) Calcular la resta (%d-%d)\n    c) Calcular la division (%d/%d)\n    d) Calcular la multiplicacion (%d*%d)\n    e) Calcular el factorial (%d!) y (%d!)\n4. Informar resultados\n    a) El resultado de A+B\n    b) El resultado de A-B\n    c) El resultado de A/B\n    d) El resultado de A*B\n    e) El factorial de (A!) y (B!)\n5. Salir\n\n",num1,num2,num1,num2,num1,num2,num1,num2,num1,num2,num1,num2);

            }
            break;
        case 2://INGRESAR SEGUNDO OPERANDO
            printf("\nEligio la opcion 2, ingrese el 2do operando: ");
            scanf("%d",&num2);
            banderaNum2=1;//BANDERA DE CONFIRMACION DE INGRESO 2DO OPERANDO
            if(banderaNum1)//PREGUNTO SI SE INGRESO EL PRIMER OPERANDO PARA SABER SI REEMPLAZO UNA O DOS VARIABLES EN EL MENU
            {//REEMPLAZO X E Y EN EL MENU
                system("cls");
                printf("MENU DE OPCIONES\n1. Ingresar 1er operando (A=%d)\n2. Ingresar 2do operando (B=%d)\n3. Calcular todas las operaciones\n    a)Calcular la suma (%d+%d)\n    b) Calcular la resta (%d-%d)\n    c) Calcular la division (%d/%d)\n    d) Calcular la multiplicacion (%d*%d)\n    e) Calcular el factorial (%d!) y (%d!)\n4. Informar resultados\n    a) El resultado de A+B\n    b) El resultado de A-B\n    c) El resultado de A/B\n    d) El resultado de A*B\n    e) El factorial de (A!) y (B!)\n5. Salir\n\n",num1,num2,num1,num2,num1,num2,num1,num2,num1,num2,num1,num2);
            }
            else
            {//REMPLAZO SOLO Y EN EL MENU
                system("cls");
                printf("MENU DE OPCIONES\n1. Ingresar 1er operando (A=x)\n2. Ingresar 2do operando (B=%d)\n3. Calcular todas las operaciones\n    a)Calcular la suma (A+%d)\n    b) Calcular la resta (A-%d)\n    c) Calcular la division (A/%d)\n    d) Calcular la multiplicacion (A*%d)\n    e) Calcular el factorial (A!) y (%d!)\n4. Informar resultados\n    a) El resultado de A+B\n    b) El resultado de A-B\n    c) El resultado de A/B\n    d) El resultado de A*B\n    e) El factorial de (A!) y (B!)\n5. Salir\n\n",num2,num2,num2,num2,num2,num2);

            }
            break;
        case 3://EJECUCION DE CALCULOS
            if(banderaNum1 && banderaNum2)//PREGUNTO SI SE INGRESARON LOS OPERANDOS
            {//LLAMO A LAS FUNCIONES DE CALCULO
                suma=sumar(num1,num2);
                resta=restar(num1,num2);
                division=dividir(num1,num2);
                multiplicacion=multiplicar(num1,num2);
                factorial1=factorialCalcular(num1);
                factorial2=factorialCalcular(num2);
                banderaCalculado=1;//BANDERA DE CONFIRMACION DE EJECUCION DE CALCULOS
                printf("Se han realizado todas las operaciones posibles\n");
            }
            else//INFORMO QUE FALTAN INGRESAR OPERANDOS
            {
                printf("Falta ingresar operandos\n");
            }
            break;
        case 4://MUESTRA DE RESULTADOS
            if(!banderaCalculado)//PREGUNTO SI SE HICIERON LOS CALCULOS
            {//INFORMO QUE FALTA CALCULAR
                printf("Aun no se han calculado los resultados. Ingrese en la opcion 3\n");
            }
            else
            {//MUESTRO LOS RESULTADOS Y EXCEPTÚO ERRORES
                system("cls");
                if(num1<0)
                {
                    if(num2<=0)
                    {
                        if(num2==0) //num1 menor a 0 y num2 == 0
                        {
                            printf("MENU DE OPCIONES\n1. Ingresar 1er operando (A=%d)\n2. Ingresar 2do operando (B=%d)\n3. Calcular todas las operaciones\n    a)Calcular la suma (%d+%d)\n   b) Calcular la resta (%d-%d)\n    c) Calcular la division (%d/%d)\n    d) Calcular la multiplicacion (%d*%d)\n    e) Calcular el factorial (%d!) y (%d!)\n4. Informar resultados\n    a) El resultado de A+B es: %d\n    b) El resultado de A-B es: %d\n    c) No es posible dividir por cero\n    d) El resultado de A*B es: %d\n    e) No es posible calcular el factorial de A. El factorial de B es: %I64u\n5. Salir\n\n",num1,num2,num1,num2,num1,num2,num1,num2,num1,num2,num1,num2,suma,resta,multiplicacion,factorial2);
                        }
                        else //num1 menor a 0 y num2 menor a 0
                        {
                            printf("MENU DE OPCIONES\n1. Ingresar 1er operando (A=%d)\n2. Ingresar 2do operando (B=%d)\n3. Calcular todas las operaciones\n    a)Calcular la suma (%d+%d)\n    b) Calcular la resta (%d-%d)\n    c) Calcular la division (%d/%d)\n    d) Calcular la multiplicacion (%d*%d)\n    e) Calcular el factorial (%d!) y (%d!)\n4. Informar resultados\n    a) El resultado de A+B es: %d\n    b) El resultado de A-B es: %d\n    c) El resultado de A/B es: %.2f\n    d) El resultado de A*B es: %d\n    e) No es posible calcular los factoriales de A y B\n5. Salir\n\n",num1,num2,num1,num2,num1,num2,num1,num2,num1,num2,num1,num2,suma,resta,division,multiplicacion);
                        }
                    }
                    else //num1 menor a 0 y num 2 mayor a 0
                    {
                        printf("MENU DE OPCIONES\n1. Ingresar 1er operando (A=%d)\n2. Ingresar 2do operando (B=%d)\n3. Calcular todas las operaciones\n    a)Calcular la suma (%d+%d)\n    b) Calcular la resta (%d-%d)\n    c) Calcular la division (%d/%d)\n    d) Calcular la multiplicacion (%d*%d)\n    e) Calcular el factorial (%d!) y (%d!)\n4. Informar resultados\n    a) El resultado de A+B es: %d\n    b) El resultado de A-B es: %d\n    c) El resultado de A/B es: %.2f\n    d) El resultado de A*B es: %d\n    e) No es posible calcular el factorial de A. El factorial de B es: %I64u\n5. Salir\n\n",num1,num2,num1,num2,num1,num2,num1,num2,num1,num2,num1,num2,suma,resta,division,multiplicacion,factorial2);
                    }
                }
                else
                {
                    if(num2<=0)
                    {
                        if(num2==0) //num1 mayor a 0 y num2 == 0
                        {
                            printf("MENU DE OPCIONES\n1. Ingresar 1er operando (A=%d)\n2. Ingresar 2do operando (B=%d)\n3. Calcular todas las operaciones\n    a)Calcular la suma (%d+%d)\n    b) Calcular la resta (%d-%d)\n    c) Calcular la division (%d/%d)\n    d) Calcular la multiplicacion (%d*%d)\n    e) Calcular el factorial (%d!) y (%d!)\n4. Informar resultados\n    a) El resultado de A+B es: %d\n    b) El resultado de A-B es: %d\n    c) No es posible dividir por cero\n    d) El resultado de A*B es: %d\n    e) El factorial de A es: %I64u y El factorial de B es: %I64u\n5. Salir\n\n",num1,num2,num1,num2,num1,num2,num1,num2,num1,num2,num1,num2,suma,resta,multiplicacion,factorial1,factorial2);
                        }
                        else //num1 mayor a 0 y num2 menor a 0
                        {
                            printf("MENU DE OPCIONES\n1. Ingresar 1er operando (A=%d)\n2. Ingresar 2do operando (B=%d)\n3. Calcular todas las operaciones\n    a)Calcular la suma (%d+%d)\n    b) Calcular la resta (%d-%d)\n    c) Calcular la division (%d/%d)\n    d) Calcular la multiplicacion (%d*%d)\n    e) Calcular el factorial (%d!) y (%d!)\n4. Informar resultados\n    a) El resultado de A+B es: %d\n    b) El resultado de A-B es: %d\n    c) El resultado de A/B es: %.2f\n    d) El resultado de A*B es: %d\n    e) El factorial de A es: %I64u. No es posible calcular el factorial de B\n5. Salir\n\n",num1,num2,num1,num2,num1,num2,num1,num2,num1,num2,num1,num2,suma,resta,division,multiplicacion,factorial1);
                        }
                    }
                    else //num1mayor a 0 y num2 mayor a 0
                    {
                        printf("MENU DE OPCIONES\n1. Ingresar 1er operando (A=%d)\n2. Ingresar 2do operando (B=%d)\n3. Calcular todas las operaciones\n    a)Calcular la suma (%d+%d)\n    b) Calcular la resta (%d-%d)\n    c) Calcular la division (%d/%d)\n    d) Calcular la multiplicacion (%d*%d)\n    e) Calcular el factorial (%d!) y (%d!)\n4. Informar resultados\n    a) El resultado de A+B es: %d\n    b) El resultado de A-B es: %d\n    c) El resultado de A/B es: %.2f\n    d) El resultado de A*B es: %d\n    e) El factorial de A es: %I64u y El factorial de B es: %I64u\n5. Salir\n\n",num1,num2,num1,num2,num1,num2,num1,num2,num1,num2,num1,num2,suma,resta,division,multiplicacion,factorial1,factorial2);

                    }
                }
            }
            break;
        case 5://SALIDA DEL PROGRAMA
            printf("El programa se cerrara.\n");
            banderaSalida=1;//HABILITO EL FIN DEL BUCLE
            system("pause");
            break;
        default://CONTEMPLO CUALQUIER INGRESO EN EL MENU QUE NO CORRESPONDA A LOS ANTERIORES CASE
            printf("La opcion ingresada no es valida. Reingrese\n");
            break;
        }

    }
}


