// #include <iostream>
#include "Savings_Account.h"

Savings_Account::Savings_Account(std::string name, double balance, double intRate)
    : Base_Account(name, balance), intRate{intRate} {}

bool Savings_Account::deposit(double amount)
{
    amount += amount * (intRate / 100);
    return Base_Account::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const Savings_Account &account)
{
    os << "[Savings_Account: " << account.name << ": " << account.balance << ", " << account.intRate << "%]";
    return os;
}