// Section 16
// Interfaces - start

#include <iostream>

class I_Printable
{
    friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);

public:
    virtual void print(std::ostream &os) const = 0;
};
std::ostream &operator<<(std::ostream &os, const I_Printable &obj)
{
    obj.print(os);
    return os;
}

class Base_Account : public I_Printable
{
public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual void print(std::ostream &os) const override
    {
        os << "Account display";
    }
    virtual ~Base_Account() {}
};

class Checking : public Base_Account
{
public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    virtual void print(std::ostream &os) const override
    {
        os << "Checking display";
    }
    virtual ~Checking() {}
};

class Savings : public Base_Account
{
public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual void print(std::ostream &os) const override
    {
        os << "Saving display";
    }
    virtual ~Savings() {}
};

class Trust : public Base_Account
{
public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual void print(std::ostream &os) const override
    {
        os << "Trust display";
    }
    virtual ~Trust() {}
};

int main()
{
    Base_Account *p1 = new Base_Account();
    std::cout << *p1 << std::endl;

    Base_Account *p2 = new Checking();
    std::cout << *p2 << std::endl;

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
