#pragma once

// #include <iostream>
#include "Account.h"

// Deposit method increment by int_rate percentage

class Savings_Account : public Base_Account
{
    friend std::ostream &operator<<(std::ostream &os, const Savings_Account &account);

private:
    static constexpr const char *defName = "Unamed Account";
    static constexpr double defBalance = 0.0;
    static constexpr double defIntRate = 0.0;

protected:
    double intRate;

public:

    Savings_Account(std::string name = defName, double balance = defBalance, double intRate =defIntRate);
    bool deposit(double amount);
    // Withdrow is inherited(ereditato) Lo scarico non cambia
};
