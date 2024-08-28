#pragma once

// #include <iostream>
#include "Savings_Account.h"
#include "Account.h"

class Trust_Account : public Savings_Account
{
    using Savings_Account::Savings_Account;

private:
    static constexpr const char *defName = "Unamed Account";
    static constexpr double defBalance = 0.0;
    static constexpr double defIntRate = 0.0;
    static int numWithdraw;

public:
    bool withdraw(double amount);
};
