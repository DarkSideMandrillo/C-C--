#pragma once

#include <iostream>
#include <string>

class Base_Account
{
    friend std::ostream &operator<<(std::ostream &os, const Base_Account &account);

private:
    static constexpr const char *defName = "Unamed Account";
    static constexpr double defBalance = 0.0;

protected:
    std::string name;
    double balance;

public:
    Base_Account(std::string name = defName, double balance = defBalance);

    bool deposit(double amount);
    bool withdraw(double amount);
    double get_balance() const;
};
