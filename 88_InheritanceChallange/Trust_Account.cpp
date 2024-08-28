#include <iostream>
#include "Trust_Account.h"

int Trust_Account::numWithdraw{0};

bool Trust_Account::withdraw(double amount)
{
    if (numWithdraw < 3)
    {
        numWithdraw++;
        return Base_Account::withdraw(amount);
    }
    else
    {
        std::cout << "\nNumero massimo prelievi" << std::endl;
        return false;
    }
}