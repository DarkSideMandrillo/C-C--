#pragma once
#include <vector>
#include "Account.h"
#include "Savings_Account.h"

// Function for Account
void display(const std::vector<Base_Account> &accounts);
void deposit(std::vector<Base_Account> &accounts, double amount);
void withdraw(std::vector<Base_Account> &accounts, double amount);

// Function for Saving_Account
void display(const std::vector<Savings_Account> &accounts);
void deposit(std::vector<Savings_Account> &accounts, double amount);
void withdraw(std::vector<Savings_Account> &accounts, double amount);

