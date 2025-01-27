#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include <iostream>
#include <string>
#include "Base_Account.h"

class Checking_Account : public Base_Account
{

private:
    static constexpr const char *def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double per_check_fee = 1.5;

public:
    Checking_Account(std::string name = def_name, double balance = def_balance);
    virtual bool withdraw(double) override;
    // Inherits the Account::deposit method
    virtual ~Checking_Account() = default;

    virtual void print(std::ostream &os) const override;
};

#endif // _CHECKING_ACCOUNT_H_
