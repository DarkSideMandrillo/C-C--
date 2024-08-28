#pragma once
#include <string>

class Base_Account
{
private:
    /* data */
public:
    double balance;
    std::string name;
    void deposit(double amount);
    void withdraw(double amount);
    Base_Account();
    ~Base_Account();
};
