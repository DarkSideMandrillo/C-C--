/*
Specification in .h
implementation in .cpp
*/

#include <iostream>
#include "Account.h"
using namespace std;

// --------------MAIN---------------
int main()
{
    Base_Account frankAccount;
    frankAccount.set_name("Frank's Account");
    frankAccount.set_balance(1000.0);

    if (frankAccount.deposit(200.0))
        cout << "Deposit OK" << endl;
    else
        cout << "Deposit not allowed" << endl;

    if (frankAccount.withdraw(500.0))
        cout << "Withdraw OK" << endl;
    else
        cout << "Not sufficient founds" << endl;

    if (frankAccount.withdraw(1500.0))
        cout << "Withdraw OK" << endl;
    else
        cout << "Not sufficient founds" << endl;
}
