/*
------------EXPRESSION------------

34              // literal
favoriteNumber  // variable
1.5 + 2.8       // addition
2 * 5           // mutiplication
a > b           // relational
a = b           // assigment

------------STATEMENTS------------

int x;          // declaration
favoriteNum=12; // assignment
1.5 + 2.8;      // expression
x = 2 * 5;      // assigment
if (a > b) cout << "a>b";  // if
a = b           // assigment
;               // null statment (no action)

*/

#include <iostream>

using namespace std;

int main() {

const double usdPerEur {1.19};

cout << "Welcome to EUR to USD convertor"<<endl;
cout << "Enter the value in EUR: ";

double euros {0.0};
double dollars {0.0};

cin >> euros;
dollars = euros+usdPerEur;

cout <<"\n"<< euros << " euros is equivlent "<< dollars << " dollars" << endl;
cout << endl;


}