// Section 16
// Challenge
#include <iostream>
#include <vector>
#include "Account.h"
#include "Base_Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main()
{
    cout.precision(2);
    cout << fixed;

    std::vector<Account *> accounts;
    Account *p1 = new Base_Account();
    Account *p2 = new Checking_Account();
    Account *p3 = new Savings_Account();
    Account *p4 = new Trust_Account();

    p1->deposit(100);
    p2->deposit(100);
    p3->deposit(100);
    p4->deposit(100);

    accounts.push_back(p1);
    accounts.push_back(p2);
    accounts.push_back(p3);
    accounts.push_back(p4);

    display(accounts);
    deposit(accounts,50);
    withdraw(accounts,150);
    display(accounts);
    

    //     // Accounts
    //     vector<Base_Account> accounts;
    //     accounts.push_back(Base_Account {});
    //     accounts.push_back(Base_Account {"Larry"});
    //     accounts.push_back(Base_Account {"Moe", 2000} );
    //     accounts.push_back(Base_Account {"Curly", 5000} );

    //     display(accounts);
    //     deposit(accounts, 1000);
    //     withdraw(accounts,2000);

    //     // Savings

    //     vector<Savings_Account> sav_accounts;
    //     sav_accounts.push_back(Savings_Account {} );
    //     sav_accounts.push_back(Savings_Account {"Superman"} );
    //     sav_accounts.push_back(Savings_Account {"Batman", 2000} );
    //     sav_accounts.push_back(Savings_Account {"Wonderwoman", 5000, 5.0} );

    //     display(sav_accounts);
    //     deposit(sav_accounts, 1000);
    //     withdraw(sav_accounts,2000);

    //    // Checking

    //     vector<Checking_Account> check_accounts;
    //     check_accounts.push_back(Checking_Account {} );
    //     check_accounts.push_back(Checking_Account {"Kirk"} );
    //     check_accounts.push_back(Checking_Account {"Spock", 2000} );
    //     check_accounts.push_back(Checking_Account {"Bones", 5000} );

    //     display(check_accounts);
    //     deposit(check_accounts, 1000);
    //     withdraw(check_accounts, 2000);

    //     // Trust

    //     vector<Trust_Account> trust_accounts;
    //     trust_accounts.push_back(Trust_Account {} );
    //     trust_accounts.push_back(Trust_Account {"Athos", 10000, 5.0} );
    //     trust_accounts.push_back(Trust_Account {"Porthos", 20000, 4.0} );
    //     trust_accounts.push_back(Trust_Account {"Aramis", 30000} );

    //     display(trust_accounts);
    //     deposit(trust_accounts, 1000);
    //     withdraw(trust_accounts, 3000);

    //     // Withdraw 5 times from each trust account
    //     // All withdrawals should fail if there are too many withdrawals or if the withdrawl is > 20% of the balance
    //     for (int i=1; i<=5; i++)
    //         withdraw(trust_accounts, 1000);

    return 0;
}
