// Section 14
// Overloading operators as non-member (global) methods
/*
Creiamo effettivamente delle funzioni
Attenzione, possiamo usare solo uno dei due metodi
Ora dobbiamo passare 1 argomento x le func unarie
due per le funzioni binarie Il primo argomento si riferisce all'oggetto a sx, l'altra quello a dx operator+(obj1,obj2)

Ora è possibile inserire come primo argomento qualcosa che non sia un oggetto
*/
#include <iostream>
#include <vector>
#include "Mystring.h"

using namespace std;

int main() {
    
    Mystring larry {"Larry"};
    larry.display();                                        // Larry
    
    larry = -larry;
    larry.display();                                        // larry
    
    cout << boolalpha << endl;
    Mystring moe{"Moe"};
    Mystring stooge = larry;
    
    cout << (larry == moe) << endl;             // false
    cout << (larry == stooge) << endl;          // true
        
  //  Mystring stooges = larry + "Moe";   
    Mystring stooges = "Larry" + moe;           // Now OK with non-member function
    stooges.display();                                      // LarryMoe
    
    Mystring two_stooges = moe + " " + "Larry";     
    two_stooges.display();                               // Moe Larry
    Mystring three_stooges = moe + " " + larry + " " +  "Curly";
    three_stooges.display();                            // Moe larry Curly             

    return 0;
}

