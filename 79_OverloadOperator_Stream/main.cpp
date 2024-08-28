// Section 14
// Overloaded insertion and extraction operators
/*
Praticamente creiamo un overload operator con cout<<obj, in modo che venga
chiamato ogni volta che si presenta questa struttura
Non creiamo un overload function operator, perchè altrimenti l'oggetto
dovrebbe essere messo x primo obj<<cout
*/

#include <iostream>
#include "Mystring.h"

using namespace std;

int main()
{

    Mystring larry{"Larry"};
    Mystring moe{"Moe"};
    Mystring curly;
    

    cout << "Enter the third stooge's first name: ";
    cin >> curly;

    cout << "The three stooges are " << larry << ", " << moe << ", and " << curly << endl;

    cout << "\nEnter the three stooges names: ";
    cin >> larry >> moe >> curly;

    cout << "The three stooges are " << larry << ", " << moe << ", and " << curly << endl;

    return 0;
}
