#include "Account.h"

Base_Account::Base_Account(std::string name, double balance)
    : name{name}, balance{balance} {}

bool Base_Account::deposit(double amount)
{
    if (amount < 0)
        return false;
    else
        balance += amount;
    return true;
}

bool Base_Account::withdraw(double amount)
{
    if (balance - amount >= 0)
        balance -= amount;
    else
        return false;
    return true;
}

double Base_Account::get_balance() const { return balance; }

std::ostream &operator<<(std::ostream &os, const Base_Account &account)
{
    os << "[Account: " << account.name << ": " << account.balance << "]";
    return os;
}
