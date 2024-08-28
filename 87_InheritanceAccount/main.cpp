// Section 15
// Challenge 
#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Account_Util.h"

using namespace std;

int main() {
    cout.precision(2);
    cout << fixed;
   
    // Accounts
    vector<Base_Account> accounts;
    accounts.push_back(Base_Account {});
    accounts.push_back(Base_Account {"Larry"});
    accounts.push_back(Base_Account {"Moe", 2000} );
    accounts.push_back(Base_Account {"Curly", 5000} );
    
    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts,2000);
    
    // Savings 

    vector<Savings_Account> sav_accounts;
    sav_accounts.push_back(Savings_Account {} );
    sav_accounts.push_back(Savings_Account {"Superman"} );
    sav_accounts.push_back(Savings_Account {"Batman", 2000} );
    sav_accounts.push_back(Savings_Account {"Wonderwoman", 5000, 5.0} );

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);
    

    return 0;
}


