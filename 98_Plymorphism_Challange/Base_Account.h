// Simple Account
#ifndef _BASE_ACCOUNT_H_
#define _BASE_ACCOUNT_H_

#include "Account.h"

class Base_Account : public Account
{
  private:
    static constexpr const char *def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;

protected:
    std::string name;
    double balance;

public:
    Base_Account(std::string name = def_name, double balance = def_balance);
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual ~Base_Account() = default;

    virtual void print(std::ostream &os) const override;
};
#endif