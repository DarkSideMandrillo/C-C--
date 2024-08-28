#include <iostream>
#include "Savings_Account.h"

Savings_Account::Savings_Account()
    : int_rate{3.0}
{
    std::cout << "Call Savings_Account constructor" << std::endl;
}
Savings_Account::~Savings_Account()
{
    std::cout << "Call Savings_Account destructor" << std::endl;
}
void Savings_Account::deposit(double amount)
{
    std::cout << "Savings_Account deposit called with" << std::endl;
}
void Savings_Account::withdraw(double amount)
{
    std::cout << "Savings_Account withdraw called with" << std::endl;
}