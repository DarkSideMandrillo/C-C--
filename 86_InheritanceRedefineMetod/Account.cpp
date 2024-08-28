//#include <iostream>
#include "Account.h"

Base_Account::Base_Account()
    : Base_Account(0.0) {} // Chiamo il mio arg constructor
Base_Account::Base_Account(double balance)
    : balance{balance} {}
Base_Account::~Base_Account() {}
void Base_Account::deposit(double amount) { balance += amount; }
void Base_Account::withdraw(double amount)
{
    if (balance - amount >= 0)
        balance -= amount;
    else
        std::cout << "Insufficient founds" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Base_Account &account)
{
    os << "Account balance: " << account.balance;
    return os;
}
