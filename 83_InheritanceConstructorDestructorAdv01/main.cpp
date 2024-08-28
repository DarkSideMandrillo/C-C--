/*
Ci sono un botto di regole di derivazione dei costruttori overlodati e degli operatori
I Overide costructor NON sono ereditati in automatico
Se nella classe figlia uso un overaid constructor (es con arg) essa viene chiamata, ma poi dal padre chiamo il no arg construtor

Usa il debugger per capire cosa succede

using Base::Base; (dentro la classe derivata) - Usare con attenzione perchè passa alcuni constructor alla derivata da Base(in questo caso), ma non tutti
*/
#include <iostream>

using namespace std;

class Base
{
private:
    int value;

public:
    Base() : value{0} { cout << "Base no-args constructor" << endl; }
    Base(int x) : value{x} { cout << "Base (int) overloaded constructor" << endl; }
    ~Base() { cout << "Base destructor" << endl; }
};

class Derived : public Base
{
    using Base::Base; // Serve per ereditare i costruttori. ATTENZIONE - si occuperà di inizializzare solo valori per la classe base e non per la derivata
private:
    int doubled_value;

public:
    Derived() : doubled_value{0} { cout << "Derived no-args constructor " << endl; }
    Derived(int x) : doubled_value{x * 2} { cout << "Derived (int) overloaded constructor" << endl; } // Se c'è questa, l'inizializazione della classe padre passerà solo per il no arg constructor
    ~Derived() { cout << "Derived destructor " << endl; }
};

int main()
{ // Deccommenta per vedere in debug cosa succede
  // Base b;
  // Base b{100};
  // Derived d;
    Derived d{1000};

    return 0;
}