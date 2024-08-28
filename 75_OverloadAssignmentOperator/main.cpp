/*
Vogliamo fare l'overloading del = operator
Cosa mi serve? 
Se copia oggetto a in b è tutto ok, ma poi devo fare
la free della memoria

Mystring s1{"Frank"};
Mystring s2 = s1; // NOT assignment - it's Inizialization

s2=s1;  // assignment
*/

#include <iostream>
#include <vector>
#include "Mystring.h"


using namespace std;

int main()
{
    Mystring a{"hello"};
    Mystring b;
    b = a;
    b = "This is a test"; 
    /* Per assegnare "This is a test" si crea una oggetto temporaneo
    Quindi fa tutto il ciclo di:
    -constructor con argomenti
    -operatore assignment overlodato
    -delete oggetto temporaneo

*/

    
    Mystring empty;                      // no-args constructor
    Mystring larry("Larry");             // overloaded constructor
    Mystring stooge {larry};            // copy constructor 
    Mystring stooges;                   // no-args constructor
    
    empty = stooge;                     // copy assignment operator
    
    empty.display();                      // Larry : 5
    larry.display();                         // Larry : 5
    stooge.display();                     // Larry : 5
    empty.display();                      // Larry : 5
    
    stooges = "Larry, Moe, and Curly";  
    stooges.display();                              // Larry, Moe, and Curly : 21
    
    vector<Mystring> stooges_vec;
    stooges_vec.push_back("Larry");
    stooges_vec.push_back("Moe");
    stooges_vec.push_back("Curly");
    
    cout << "=== Loop 1 ==================" << endl;
    for (const Mystring &s: stooges_vec) 
        s.display();                                        // Larry
                                                                // Moe
                                                                //Curly
    cout << "=== Loop 2 ==================" << endl;
    for (Mystring &s: stooges_vec)
        s = "Changed";                              // copy assignment operator (credo sia poi da usare un move assignment)
        
    cout << "=== Loop 3 ================" << endl;
    for (const Mystring &s: stooges_vec) 
        s.display();                                     // Changed
                                                            // Changed
                                                            // Changed
    
}