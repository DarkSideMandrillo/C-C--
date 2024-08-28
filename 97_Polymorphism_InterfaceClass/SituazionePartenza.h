// Section 16
// Interfaces - start

#include <iostream>

class Base_Account  {
    friend std::ostream &operator<<(std::ostream &os, const Base_Account &acc);
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual ~Base_Account() {  }
};

std::ostream &operator<<(std::ostream &os, const Base_Account &acc) {
    os << "Account display";
    return os;
}

class Checking: public Base_Account  {
    friend std::ostream &operator<<(std::ostream &os, const Checking &acc);
public:
    virtual void withdraw(double amount) {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    virtual ~Checking() {  }
};

std::ostream &operator<<(std::ostream &os, const Checking &acc) {
    os << "Checking display";
    return os;
}

class Savings: public Base_Account {
    friend std::ostream &operator<<(std::ostream &os, const Savings &acc);
public:
    virtual void withdraw(double amount) {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual ~Savings() {  }
};

std::ostream &operator<<(std::ostream &os, const Savings &acc) {
    os << "Savings display";
    return os;
}
class Trust: public Base_Account  {
    friend std::ostream &operator<<(std::ostream &os, const Trust &acc);
public:
    virtual void withdraw(double amount) {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual ~Trust() {  }
};

std::ostream &operator<<(std::ostream &os, const Trust &acc) {
    os << "Trust display";
    return os;
}

int main() {
    Base_Account *p1 = new Base_Account();
    std::cout << *p1<< std::endl;

    Base_Account *p2 = new Checking();
    std::cout << *p2<< std::endl;
   
//    Account a;
//    std::cout << a<< std::endl;
//    
//    Checking c;
//    std::cout << c << std::endl;
//
//    Savings s;
//    std::cout << s << std::endl;
//    
//    Trust t;
//    std::cout << t << std::endl;

    delete p1;  
    delete p2;
    return 0;
}


