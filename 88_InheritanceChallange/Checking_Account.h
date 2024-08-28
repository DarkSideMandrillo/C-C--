#pragma once

// #include <iostream>
#include "Account.h"

class Checking_Account : public Base_Account
{
    using Base_Account::Base_Account;
    // friend std::ostream &operator<<(std::ostream &os, const Checking_Account &account); // Viene preso con  using Account::Account;

private:
    static constexpr const char *defName{"Unamed Account"};
    static constexpr double defBalance{0.0};
    static constexpr double feeAccount = 1.5;

public:

    bool withdraw(double amount);
};
