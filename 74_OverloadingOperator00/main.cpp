#include <iostream>
#include "Mystring.h"

using namespace std;

int main()
{
    Mystring empty{nullptr};
    Mystring larry("Larry");
    Mystring stooge{larry};
    Mystring eremo{empty};

    eremo.display();
    empty.display();
    larry.display();
    stooge.display();
}