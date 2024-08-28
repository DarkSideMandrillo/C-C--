// Section 8 Challenge
/*
    For this program I will be using US dollars and cents.

    Write a program that asks the user to enter the following:
    An integer representing the number of cents

    You may assume that the number of cents entered is greater than or equal to zero

    The program should then display how to provide that change to the user.

    In the US:
        1 dollar is 100 cents
        1 quarter is 25 cents
        1 dime is 10 cents
        1 nickel is 5 cents, and
        1 penny is 1 cent.

    Here is a sample run:

    Enter an amount in cents :  92

    You can provide this change as follows:
    dollars    : 0
    quarters : 3
    dimes     : 1
    nickels   : 1
    pennies  : 2

    dollar 100 cent
    quarter 25 cent
    dimes 10 cent
    nikels 5 cent
    penny 1 cent


    Feel free to use your own currency system.
    Also, think of how you might solve the problem using the modulo operator.

    Have fun and test your program!!

*/
#include <iostream>

using namespace std;

int main()
{

    int cent{};
    int dollar{};
    int quarter{};
    int dimes{};
    int nickels{};
    int penny{};

    cout << "Inserisci i centesimi: ";
    cin >> cent;

    //  ----------- MODO 1 -------------

    // dollar = cent / 100;
    // cent -= dollar * 100;
    // quarter = cent / 25;
    // cent = cent - quarter * 25;
    // dimes = cent / 10;
    // cent = cent - dimes * 10;
    // nickels = cent / 5;
    // cent = cent - nickels * 5;
    // penny = cent;

    //  ----------- MODO 2 -------------

    dollar = cent / 100;
    cent %= 100;
    quarter = cent / 25;
    cent %= 25;
    dimes = cent / 10;
    cent %= 10;
    nickels = cent / 5;
    cent %= 5;
    penny = cent;

    cout << "You can provide change for this change as follows:" << endl;
    cout << "dollars:    " << dollar << "\nquarter:    " << quarter << "\ndimes:      " << dimes << "\nnickels:    " << nickels << "\npennies:    " << penny << endl;

    cout << endl;
    return 0;
}