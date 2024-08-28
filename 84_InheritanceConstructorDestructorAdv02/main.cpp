// Section 15
// Base class initialization
#include <iostream>

using namespace std;

class Base
{
private:
    int value;

public:
    Base()
        : value{0}
    {
        cout << "Base no-args constructor" << endl;
    }
    Base(int x)
        : value{x}
    {
        cout << "Base (int) overloaded constructor" << endl;
    }
    ~Base()
    {
        cout << "Base destructor" << endl;
    }
};

class Derived : public Base
{
private:
    int doubled_value;

public:
    Derived()
        : Base{}, doubled_value{0} // Richiama il costruttore no arg (public), "inutile" perchè verrebbe chiamato cmq 
    {
        cout << "Derived no-args constructor " << endl;
    }
    Derived(int x)
        : Base{x}, doubled_value{x * 2} // Richiama il costruttore con 1 arg e passa l'argomento
    {
        cout << "Derived (int) constructor" << endl;
    }
    ~Derived()
    {
        cout << "Derived destructor " << endl;
    }
};

int main()
{
    //  Derived d;
    Derived d{1000};
    return 0;
}