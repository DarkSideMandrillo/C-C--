#pragma once
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"

// Function for Account
void display(const std::vector<Base_Account> &accounts);
void deposit(std::vector<Base_Account> &accounts, double amount);
void withdraw(std::vector<Base_Account> &accounts, double amount);

// Function for Saving_Account
void display(const std::vector<Savings_Account> &accounts);
void deposit(std::vector<Savings_Account> &accounts, double amount);
void withdraw(std::vector<Savings_Account> &accounts, double amount);

// Function for Checking_Account
void display(const std::vector<Checking_Account> &accounts);
void deposit(std::vector<Checking_Account> &accounts, double amount);
void withdraw(std::vector<Checking_Account> &accounts, double amount);

// Function for Trust_Account
void display(const std::vector<Trust_Account> &accounts);
void deposit(std::vector<Trust_Account> &accounts, double amount);
void withdraw(std::vector<Trust_Account> &accounts, double amount);

