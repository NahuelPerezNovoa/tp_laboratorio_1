int sumar(int a, int b)
{
    int rdo;
    rdo=a+b;
    return rdo;
}

int restar(int a, int b)
{
    int rdo;
    rdo=a-b;
    return rdo;
}

float dividir(int a, int b)
{
    float rdo;
    rdo=(float)a/b;
    return rdo;
}

int multiplicar(int a, int b)
{
    int rdo;
    rdo=a*b;
    return rdo;
}


long long int factorialCalcular (int a)
{
    long long int fact=1;
    if(a>0)
    {
        fact=(long long int) a*factorialCalcular(a-1);
        a--;
    }
    return fact;
}
