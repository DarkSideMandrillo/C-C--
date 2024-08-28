// Section 17
// Virtual destructor
// Se uso func virtuali devo creare anche i virtual destructor

#include <iostream>

// This class uses dynamic polymorphism for the withdraw method
class Base_Account
{
public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual ~Base_Account() { std::cout << "Account::destructor" << std::endl; }
};

class Checking : public Base_Account
{
public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Checking::withdraw" << std::endl;
    }
        virtual ~Checking() { std::cout << "Cheking::destructor" << std::endl; }

};

class Savings : public Base_Account
{
public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Savings::withdraw" << std::endl;
    }
        virtual ~Savings() { std::cout << "Savings::destructor" << std::endl; }

};

class Trust : public Base_Account
{
public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Trust::withdraw" << std::endl;
    }
        virtual ~Trust() { std::cout << "Trust::destructor" << std::endl; }

};

int main()
{
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