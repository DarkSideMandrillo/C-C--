#include <iostream>

using namespace std;

long long func_factorial(long long);
long long func_finbonacci(long long);

//FATTORIALE
long long func_factorial(long long x)
{
    if (x != 0)
        return x * func_factorial(x - 1);
    return 1;
}
//FINBONACCI
long long func_finbonacci(long long x)
{
    if (x > 1)
        return func_finbonacci(x - 1) + func_finbonacci(x - 2);
    return x;
}

int main()
{
    int x{};
    long long factorial{};
    long long finbonacci{};

    cin >> x;

    // FATTORIALE
    factorial = func_factorial(x);
    cout << "\nIl fattoriale di " << x << " è " << factorial << endl;

    // FINBONACCI
    finbonacci = func_finbonacci(x);
    cout << "\nIl n° Finbonacci di " << x << " è " << finbonacci << endl
         << endl;
}

// Esempio fattoriale 3

/*
-------1---------------------------
    if (3 != 0)
        return 3 * func_factorial(3 - 1); (torna 2) (esegue 3*2)
    return 1;

-------2---------------------------
    if (2 != 0)
        return 2 * func_factorial(2 - 1); (torna 1) (esegue 2*1)
    return 1;

-------3---------------------------
    if (1 != 0)
        return 1 * func_factorial(1 - 1); (torna 1) (esegue 1*1)
    return 1;

------- 4 ---------------------------
    if (0 != 0)
        (non esegue) return x * func_factorial(x - 1);
    return 1;







*/