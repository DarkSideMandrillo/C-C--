#pragma once

//#include <iostream>
#include "Account.h"

// Deposit method increment by int_rate percentage

class Savings_Account : public Base_Account
{
    friend std::ostream &operator<<(std::ostream &os, const Savings_Account &account);

protected:
    double intRate;

public:
    Savings_Account();
    Savings_Account(double balance, double intRate);
    ~Savings_Account();
    void deposit(double amount);
    //Withdrow is inherited(ereditato) Lo scarico non cambia
};


