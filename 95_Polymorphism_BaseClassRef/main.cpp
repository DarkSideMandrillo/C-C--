// I riferimenti (&) con il polimorfismo puntano al metodo corretto in base a cosa riferiscono
// Using Base class references
// IMPORTANTE riga 41. Cambia dinamicamente dentro la func chiamando 2 metodi diversi

#include <iostream>

// This class uses dynamic polymorphism for the withdraw method
// We'll learn about virtual functions in the next video
class Base_Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual ~Base_Account() {  }
};

class Checking: public Base_Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    virtual ~Checking() {  }
};

class Savings: public Base_Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual ~Savings() {  }
};

class Trust: public Base_Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual ~Trust() {  }
};

void do_withdraw(Base_Account &account, double amount) {
    account.withdraw(amount);
}

int main() {

    Base_Account a;
    Base_Account &ref = a;
    ref.withdraw(1000);		    // In Account::withdraw

    Trust t;
    Base_Account &ref1 = t;
    ref1.withdraw(1000);        // In Trust::withdraw

   Base_Account a1;
   Savings a2;
   Checking a3;
   Trust a4;
   
   do_withdraw(a1, 1000);       // In Account::withdraw
   do_withdraw(a2, 2000);       // In Savings::withdraw
   do_withdraw(a3, 3000);       // In Checking::withdraw
   do_withdraw(a4,  4000);      // In Trust::withdraw


    return 0;
}

