// Section 16
// Virtual functions

// Virtual basta metterlo nella classe base e tutte le derivate lo sono anche
// beastpractice è mettere virtual a tutte le derivate

/*
 Se si cambia il tipo della func oppure i parametri passati,
 il compilatore vede la funzione come come un override in compile time
 Quindi un polymorphism statico.
 (Ovviamente deve essere usata differentemente in questo modo, o può creare anche problemi)
 */

// Avvertenza: Non creare RawPointer nella dichiarazione di un Vector

#include <iostream>

// This class uses dynamic polymorphism for the withdraw method
class Base_Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
};

class Checking: public Base_Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Checking::withdraw" << std::endl;
    }
};

class Savings: public Base_Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Savings::withdraw" << std::endl;
    }
};

class Trust: public Base_Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Trust::withdraw" << std::endl;
    }
};

int main() {
    std::cout << "\n === Pointers ==== " << std::endl;
    Base_Account *p1 = new Base_Account();
    Base_Account *p2 = new Savings();
    Base_Account *p3 = new Checking();
    Base_Account *p4 = new Trust();
    
    p1->withdraw(1000);
    p2->withdraw(1000);
    p3->withdraw(1000);
    p4->withdraw(1000);
    

    std::cout << "\n === Clean up ==== " << std::endl;
    delete p1;
    delete p2;
    delete p3;
    delete p4;
        
    return 0;
}