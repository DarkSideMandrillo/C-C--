/*
Una classe padre può avere 3 parti *Public *Protected *Private
Una classe figlia può essere di tre TIPI *Public *Protected *Private (essa avrà anche le tre parti *Public *Protected *Private)
--------------------------------------------------
Una sottoClasse PUBLIC si comporta in questo modo rispetto alle tre parti della classe padre:
Base class public: a    - Derived class PUBLIC: a
Base class protected: a - Derived class protected: a
Base class private: a   - Derived class: NO ACCESS [ATTENZIONE: si crea ugualmente nell'oggetto figlio il metodo/variabile, ma non è accessibile]
--------------------------------------------------
Una sottoClasse PROTECTED si comporta in questo modo rispetto alle tre parti della classe padre:
Base class public: a    - Derived class PROTECTED: a
Base class protected: a - Derived class protected: a
Base class private: a   - Derived class: NO ACCESS
--------------------------------------------------
Una sottoClasse PRIVATE si comporta in questo modo rispetto alle tre parti della classe padre:
Base class public: a    - Derived class PRIVATE: a
Base class protected: a - Derived class PRIVATE: a
Base class private: a   - Derived class: NO ACCESS
--------------------------------------------------

*/

#include <iostream>

using namespace std;

/*  ===DICHIARAZIONE CLASSE PADRE===    */
class Base
{
    // Note: the friends of Base have access to all (*Public *Protected *Private - di questa classe)
public:
    int a{0};
    void display() { cout << a << ", " << b << ", " << c << endl; } // metodo accessibile da tutti
protected:
    int b{0};

private:
    int c{0};
};

/*  ===DICHIARAZIONE CLASSE DERIVATA===    */
class Derived : public Base
{
    // Note: the friends of Derived have access to only what Derived has access to

    // a will be public
    // b will be protected
    // c will NOT be accessible
public:
    void access_base_members()
    {
        a = 100; // Ok - Public, quindi ho accesso
        b = 200; // Ok - protected, quindi ho accesso, visto che sto accedendo da DENTRO la classe
        // c = 300; // not accessible
    }
};

int main()
{

    cout << "==Base member access from base objects===" << endl;
    Base base;
    base.a = 100; // OK - is public
    // base.b = 200; // Compile error - is protected (si comporta come private)
    // base.c = 300; // Compile error - is private

    cout << "==Base member access from derived objects===" << endl;
    Derived derv;
    derv.a = 100; // Ok
    // derv.b = 200; // Compile error - is protected
    // derv.c = 300; // Compile error - not accessible
}