// Simple Account
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>

#include "I_Printable.h"

class Account : public I_Printable
{
    // friend std::ostream &operator<<(std::ostream &os, const Account &account);

private:
protected:
public:
    virtual bool deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    virtual ~Account() = default;
};
#endif