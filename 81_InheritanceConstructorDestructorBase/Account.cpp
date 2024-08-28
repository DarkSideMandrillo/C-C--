#include <iostream>
#include "Account.h"

Base_Account::Base_Account()
    : balance{0.0}, name{"An Account"}
{
    std::cout << "Call Account constructor" << std::endl;
}

Base_Account::~Base_Account() {
        std::cout << "Call Account destructor" << std::endl;

}

void Base_Account::deposit(double amount)
{
    std::cout << "Account deposit called with" << std::endl;
}
void Base_Account::withdraw(double amount)
{
    std::cout << "Account withdraw called with" << std::endl;
}