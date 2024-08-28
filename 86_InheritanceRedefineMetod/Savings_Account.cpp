//#include <iostream>
#include "Savings_Account.h"


Savings_Account::Savings_Account()
    : Savings_Account(0.0, 0.0) {}
Savings_Account::Savings_Account(double balance, double intRate)
    : Base_Account(balance), intRate{intRate} {}
Savings_Account::~Savings_Account() {}

void Savings_Account::deposit(double amount)
{
    amount = amount + amount * intRate / 100;
    Base_Account::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const Savings_Account &account)
{
    os << "Savings_Account balance: " << account.balance << " interest rate " << account.intRate;
    return os;
}