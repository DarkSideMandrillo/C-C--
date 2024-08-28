#include <iostream>
#include "Account.h"
#include "Savings_Account.h"

using namespace std;

int main()
{
    // Use the Account class
    cout << "\n===Account===================" << endl;
    Base_Account acc{};
    acc.deposit(2000.0);
    acc.withdraw(500.0);

    cout << endl;

    // Con puntatore
    Base_Account *p_acc{nullptr};
    p_acc = new Base_Account();
    p_acc->deposit(1000.0);
    p_acc->withdraw(500.0);
    delete p_acc;

    // Use Saving_Account
    cout << "\n===Saving_Account===================" << endl;
    Savings_Account savAcc{};
    savAcc.deposit(2000.0);
    savAcc.withdraw(500.0);

    cout << endl;

    // Con puntatore
    Savings_Account *p_savAcc{nullptr};
    p_savAcc = new Savings_Account();
    p_savAcc->deposit(1000.0);
    p_savAcc->withdraw(500.0);
    delete p_savAcc;
    cout << "\n===END===================" << endl;
}