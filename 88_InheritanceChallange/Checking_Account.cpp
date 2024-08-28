#include "Checking_Account.h"

bool Checking_Account::withdraw(double amount)
{
        return Base_Account::withdraw(amount+feeAccount);
}
