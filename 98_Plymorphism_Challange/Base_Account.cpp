#include "Base_Account.h"

Base_Account::Base_Account(std::string name, double balance)
    : name{name}, balance{balance}
{
}

bool Base_Account::deposit(double amount)
{
    if (amount < 0)
        return false;
    else
    {
        balance += amount;
        return true;
    }
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

void Base_Account::print(std::ostream &os) const
{
    os.precision(2);
    os << std::fixed;
    os << "[Base_Account: " << name << ": " << balance << "]";
}
