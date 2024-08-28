/*Questo file serve solo per dichiarare i metodi e gli attributi*/
#pragma once // Serve per controllare di non compilare + volte questo codice
#include <string>

class Base_Account
{
    // attribute
    std::string name;
    double balance;

public:
    // metods
    // declared inline
    void set_balance(double bal) { balance = bal; }
    double get_balance() { return balance; }

    // methods will be declared outside the class declaration
    void set_name(std::string n);
    std::string getName();

    bool deposit(double amount);
    bool withdraw(double amount);
};

/*
Al posto di usare #pragma once potrei usare lo Standard

#ifndef ACCOUNT_H
#define ACCOUNT_H
... contents of Account.h
#endif
*/