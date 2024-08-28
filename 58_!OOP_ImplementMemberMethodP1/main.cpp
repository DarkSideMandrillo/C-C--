#include <iostream>
#include <string>

using namespace std;

class Base_Account
{
    // attribute
    string name;
    double balance;

public:
    // metods
    // declared inline
    void set_balance(double bal) { balance = bal; }
    double get_balance() { return balance; }

    // methods will be declared outside the class declaration
    void set_name(string n);
    string getName();

    bool deposit(double amount);
    bool withdraw(double amount);
};

void Base_Account::set_name(string n)
{
    name = n;
}

string Base_Account::getName()
{
    return name;
}

bool Base_Account::deposit(double amount)
{
    // if verify amount
    balance += amount;
    return true;
}

bool Base_Account::withdraw(double amount)
{
    if (balance - amount >= 0)
    {
        balance -= amount;
        return true;
    }
    else
        return false;
}
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
