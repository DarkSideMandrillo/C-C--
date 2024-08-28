#include <cstring>
#include <iostream>
#include "Mystring.h"

// No arg constructor
Mystring::Mystring()
    : str{nullptr}
{
    str = new char[1];
    *str = '\0';
}
// Overloading contructor 1 arg
Mystring::Mystring(const char *s) //*s è un c-style string - quindi es: "hello/0"
                                  /* C++ treats arrays of characters and char *  as strings. So when we display
                                  an array of characters or a char *  pointer name, C++ will assume it is a string
                                  and display every character until it sees the NULL character.
                                  A char * is a C-style string. It is the address of the first character of a null-terminated string.*/
    : str{nullptr}
{
    if (s == nullptr)
    {
        str = new char[1]; // Mystring(); //  Non posso, perchè se chiamo il constructor così, lui crea un nuovo oggetto, inizializza
        *str = '\0';       // str, poi chiama il delete quando finisce il metodo constructor
    }
    else
    {
        str = new char[std::strlen(s) + 1]; // Creo lo spazio nell'hipe alla lunghezza corretta
        std::strcpy(str, s);
    } // Assegno il valore di s (es. "hello") a str
}
// Copy Constructor
Mystring::Mystring(const Mystring &source)
    : Mystring(source.str)
{
}
// Destructor
Mystring::~Mystring()
{
    delete[] str;
}

// Display method
void Mystring::display() const
{
    std::cout << str << " : " << get_lenght() << std::endl;
}
// Lenght getter
int Mystring::get_lenght() const
{
    return std::strlen(str);
}

const char *Mystring::get_str() // Stessa cosa di sopra un char * è una stringa
{
    return str;
}
