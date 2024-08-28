#pragma once
#include "Account.h"

class Savings_Account : public Base_Account
{
private:
    /* data */
public:
    double int_rate;
    Savings_Account();
    ~Savings_Account();
    void deposit(double amount);
    void withdraw(double amount);
};
