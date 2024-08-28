#include <cstring>
#include <iostream>
#include "Mystring.h"

/*---------------Constructor----------------------*/

// No arg constructor
Mystring::Mystring()
    : str{nullptr}
{
    str = new char[1];
    *str = '\0';
}
// Overloading contructor 1 arg
Mystring::Mystring(const char *s)
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
    : Mystring(source.str) {}

// Move Constructor
Mystring::Mystring(Mystring &&source)
    : str{nullptr}
{   // Non serve fare la IF sul nullptr, perchè l'oggetto source è stato appena creato e se è nullptr viene creata una stringa "/0"
    std::cout << " Move Constructor" << std::endl;

        str = source.str;
        source.str = nullptr;
    
}

// Destructor
Mystring::~Mystring() { delete[] str; }

/*---------------Overloading Operator----------------------*/
// Copy operator assignment
Mystring &Mystring::operator=(const Mystring &rhs) // Il &Mystring significa che ritornerà un puntatore a un oggetto Mystring
{
    std::cout << "Copy assignment" << std::endl;
    if (this == &rhs) // Se i due oggetti sono uguali ritorna subito
        return *this; // Devo deferenziare visto che voglio l'oggetto e non il suo puntatore
    delete[] this->str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(this->str, rhs.str);
    return *this;
}
// Move operator assignment
Mystring &Mystring::operator=(Mystring &&rhs)
{
    std::cout << "Move assignment" << std::endl;
    if (this == &rhs)
        return *this;
    delete[] this->str;
    this->str = rhs.str; // Rubo il puntatore dall'oggetto passato (che verrà distrutto visto che è tmp essendo un R-Value)
    rhs.str = nullptr;   // Cancello il puntatore della sorgente, così che il delete non cancelli il contenuto
    return *this;
}

/*---------------Metod----------------------*/

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
