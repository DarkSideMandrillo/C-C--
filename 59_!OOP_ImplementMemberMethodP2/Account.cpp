#include "Account.h"


void Base_Account::set_name(std::string n)
{
    name = n;
}

std::string Base_Account::getName()
{
    return name;
}

bool Base_Account::deposit(double amount)
{
    // if verify amount
    balance += amount;
    return true;
}

bool Base_Account::withdraw(double amount)
{
    if (balance - amount >= 0)
    {
        balance -= amount;
        return true;
    }
    else
        return false;
}