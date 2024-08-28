// Copy constructor and operator=
/*
Non è molto complicato.
Dobbiamo creare il copy e l'overload dell'operatore anche nella classe derivata
In essa ci comportiamo nello stesso identico modo tranne che
-Nel copy, richiamiamo il copy della classe base passando l'oggetto  :Base(obj),
poi inizializiamo la nuova var (se c'è) con il nuovo oggetto nuovaVar{obj.nuovaVar}
-Nell'operator= richiamiamo l'operator= della classe base
Base::operator=(obj);
E poi assegnamo il valore non gestito dalla classe Base - nuovaVar = obj.nuovaVar;

Slicing - taglio
Possiamo passare un oggetto di una classe derivata alla classe padre. Essa lo accetta grazie allo slicing
Es il Copy Constructor della classe derivata invoca il copy contructor della classe padre passando un oggetto di tipo classeDerivata
Esso visto che è un "ampliamento" della classe padre, viene tagliato della parte aggiunta dalla derivata e viene passato 

*/

#include <iostream>

using namespace std;

class Base {
private:
    int value;
public:
   Base()
        : value {0}  { 
            cout << "Base no-args constructor" << endl; 
    }
    Base(int x) 
        : value {x} { 
            cout << "int Base constructor" << endl;
    }
    Base(const Base &other) 
        : value {other.value} {
         cout << "Base copy constructor" << endl;     
    }
        
    Base &operator=(const Base &rhs)  {
    cout << "Base operator=" << endl;
        if (this == &rhs)
            return *this;
        value = rhs.value;
        return *this;
    }
            
   ~Base(){ cout << "Base destructor" << endl; }
};

class Derived : public Base {
private:
    int doubled_value;
public:
    Derived() : 
        Base {}  {
            cout << "Derived no-args constructor " << endl; 
    }
    Derived(int x) 
        : Base{x} , doubled_value {x * 2} { 
            cout << "int Derived constructor" << endl; 
    }
    Derived(const Derived &other)
        : Base(other), doubled_value {other.doubled_value} {
         cout << "Derived copy constructor" << endl;     
    }
    
    Derived &operator=(const Derived &rhs) {
            cout << "Derived operator=" << endl;
        if (this == &rhs)
            return *this;
        Base::operator=(rhs);
        doubled_value = rhs.doubled_value;
        return *this;
    }
   ~Derived(){ cout << "Derived destructor " << endl; } 
};


int main() {
//    Base b {100};   // Overloaded constructor
//    Base b1 {b};    // Copy constructor
//    b = b1;          //   Copy assignment

    Derived d {100};    // Overloaded constructor
    Derived d1 {d};     // Copy constructor
    d = d1;                // Copy assignment
    
    return 0;
}

