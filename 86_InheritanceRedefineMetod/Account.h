#pragma once

#include <iostream>

class Base_Account
{
    friend std::ostream &operator<<(std::ostream &os, const Base_Account &account);

protected:
    double balance;

public:
    Base_Account();
    Base_Account(double balance);
    ~Base_Account();
    void deposit(double amount);
    void withdraw(double amount);
};
