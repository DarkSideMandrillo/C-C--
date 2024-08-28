#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance)
    : Base_Account{name, balance}
{
}

bool Checking_Account::withdraw(double amount)
{
    amount += per_check_fee;
    return Base_Account::withdraw(amount);
}

void Checking_Account::print(std::ostream &os) const
{
    os.precision(2);
    os << std::fixed;
    os << "[Cheking_Account: " << name << ": " << balance << "]";
}
