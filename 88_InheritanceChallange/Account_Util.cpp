#include <iostream>
#include "Account_Util.h"
// -------------------------------Account------------------------------------
void display(const std::vector<Base_Account> &accounts)
{
    std::cout << "\n===Accounts================================================" << std::endl;
    for (const auto &acc : accounts)
        std::cout << acc << std::endl;
}
void deposit(std::vector<Base_Account> &accounts, double amount)
{
    std::cout << "\n===Depositing to Accounts================================================" << std::endl;
    for (auto &acc : accounts)
        if (acc.deposit(amount))
            std::cout << "Deposit " << amount << " to " << acc << std::endl;
        else
            std::cout << "Fail Deposit of " << amount << " to " << acc << std::endl;
}

void withdraw(std::vector<Base_Account> &accounts, double amount)
{
    std::cout << "\n===Withdraing from Accounts================================================" << std::endl;
    for (auto &acc : accounts)
        if (acc.withdraw(amount))
            std::cout << "withdraw " << amount << " from " << acc << std::endl;
        else
            std::cout << "Fail withdraw of " << amount << " from " << acc << std::endl;
}
// -------------------------------Savings_Account------------------------------------

void display(const std::vector<Savings_Account> &accounts)
{
    std::cout << "\n===Savings_Account================================================" << std::endl;
    for (const auto &acc : accounts)
        std::cout << acc << std::endl;
}
void deposit(std::vector<Savings_Account> &accounts, double amount)
{
    std::cout << "\n===Depositing to Savings_Account================================================" << std::endl;
    for (auto &acc : accounts)
        if (acc.deposit(amount))
            std::cout << "Deposit " << amount << " to " << acc << std::endl;
        else
            std::cout << "Fail Deposit of " << amount << " to " << acc << std::endl;
}

void withdraw(std::vector<Savings_Account> &accounts, double amount)
{
    std::cout << "\n===Withdraing from Savings_Account================================================" << std::endl;
    for (auto &acc : accounts)
        if (acc.withdraw(amount))
            std::cout << "withdraw " << amount << " from " << acc << std::endl;
        else
            std::cout << "Fail withdraw of " << amount << " from " << acc << std::endl;
}

// -------------------------------Checking Account------------------------------------

void display(const std::vector<Checking_Account> &accounts)
{
    std::cout << "\n===Checking_Account================================================" << std::endl;
    for (const auto &acc : accounts)
        std::cout << acc << std::endl;
}
void deposit(std::vector<Checking_Account> &accounts, double amount)
{
    std::cout << "\n===Depositing to Checking_Account================================================" << std::endl;
    for (auto &acc : accounts)
        if (acc.deposit(amount))
            std::cout << "Deposit " << amount << " to " << acc << std::endl;
        else
            std::cout << "Fail Deposit of " << amount << " to " << acc << std::endl;
}

void withdraw(std::vector<Checking_Account> &accounts, double amount)
{
    std::cout << "\n===Withdraing from Checking_Account================================================" << std::endl;
    for (auto &acc : accounts)
        if (acc.withdraw(amount))
            std::cout << "withdraw " << amount << " from " << acc << std::endl;
        else
            std::cout << "Fail withdraw of " << amount << " from " << acc << std::endl;
}

// -------------------------------Trust Account------------------------------------

void display(const std::vector<Trust_Account> &accounts)
{
    std::cout << "\n===Trust_Account================================================" << std::endl;
    for (const auto &acc : accounts)
        std::cout << acc << std::endl;
}
void deposit(std::vector<Trust_Account> &accounts, double amount)
{
    std::cout << "\n===Depositing to Trust_Account================================================" << std::endl;
    for (auto &acc : accounts)
        if (acc.deposit(amount))
            std::cout << "Deposit " << amount << " to " << acc << std::endl;
        else
            std::cout << "Fail Deposit of " << amount << " to " << acc << std::endl;
}

void withdraw(std::vector<Trust_Account> &accounts, double amount)
{
    std::cout << "\n===Withdraing from Trust_Account================================================" << std::endl;
    for (auto &acc : accounts)
        if (acc.withdraw(amount))
            std::cout << "withdraw " << amount << " from " << acc << std::endl;
        else
            std::cout << "Fail withdraw of " << amount << " from " << acc << std::endl;
}
