#include <iostream>
#include <cstring>
#include "Mystring.h"

/*-----------------CONSTRUCTOR---------------------*/
Mystring::Mystring() // Const no arg
    : str{nullptr}
{
    str = new char[1];
    *str = '\0';
    std::cout << "Constr No Arg" << std::endl;
}

Mystring::Mystring(const char *s) // Const arg
    : str{nullptr}
{
    if (s != nullptr)
    {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
    }
    else
    {
        str = new char[1];
        *str = '\0';
    }
    std::cout << "Constr with Arg" << std::endl;
}
Mystring::Mystring(const Mystring &source) // Copy Const
    : Mystring(source.str)
{
    std::cout << "Constr Copy" << std::endl;
}
Mystring::Mystring(Mystring &&source) // Move Const
    : str{source.str}
{
    source.str = nullptr;
    std::cout << "Constr Move" << std::endl;
}
Mystring::~Mystring() // Destr
{
    delete[] str;
    std::cout << "Destr" << std::endl;
}
/*-----------------OPERATOR---------------------*/
// Equality
Mystring &Mystring::operator=(const Mystring &rhd)
{
    std::cout << "Equal op" << std::endl;
    if (str == rhd.str)
        return *this;
    delete[] str;
    str = new char[std::strlen(rhd.str) + 1];
    std::strcpy(str, rhd.str);
    return *this;
}
// Equality Move
Mystring &Mystring::operator=(Mystring &&rhd)
{
    std::cout << "Equal op Move" << std::endl;
    if (str == rhd.str)
        return *this;
    delete[] str;
    str = rhd.str;
    rhd.str = nullptr;
    return *this;
}
// Confrontation equal
bool Mystring::operator==(const Mystring &rhd) const { return std::strcmp(str, rhd.str) == 0; }
// Confrontation Non equal
bool Mystring::operator!=(const Mystring &rhd) const { return std::strcmp(str, rhd.str) != 0; }
// Confrontation 1° letter of sring - Major
bool Mystring::operator>(const Mystring &rhd) const { return std::strcmp(str, rhd.str) > 0; }
// Confrontation 1° letter of sring - Minor
bool Mystring::operator<(const Mystring &rhd) const { return std::strcmp(str, rhd.str) < 0; }

// Lowercase
Mystring Mystring::operator-() const // Non cancella l'oggetto originale
{
    char *buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);
    for (size_t i{0}; i < std::strlen(buff); i++)
        buff[i] = std::tolower(buff[i]);
    Mystring tmp{buff};
    delete[] buff;
    return tmp;
}
// Concatenate
Mystring Mystring::operator+(const Mystring &rhd) const
{
    char *buff = new char[std::strlen(str) + std::strlen(rhd.str) + 1];
    std::strcpy(buff, str);
    std::strcat(buff, rhd.str);
    Mystring tmp{buff};
    delete[] buff;
    return tmp;
}
// Concatenate self +=
Mystring &Mystring::operator+=(const Mystring &rhd)
{
    char *buff = new char[std::strlen(str) + std::strlen(rhd.str) + 1];
    std::strcpy(buff, str);
    std::strcat(buff, rhd.str);
    delete[] str;
    str = buff;
    buff = nullptr;
    delete[] buff;
    return *this;
}
// Repeat (es b="ci"; a=b*3; a="cicici" )
Mystring Mystring::operator*(const size_t &rhd) const
{
    char *buff = new char[std::strlen(str) * rhd + 1];
    std::strcpy(buff, "");
    for (size_t i{0}; i < rhd; i++)
        std::strcat(buff, str);
    Mystring tmp{buff};
    delete[] buff;
    return tmp;
}
// Repeat self (es b="ci; b*3; b="cicici")
Mystring &Mystring::operator*=(const size_t &rhd)
{
    char *buff = new char[std::strlen(str) * rhd + 1];
    for (size_t i{0}; i < rhd; i++)
        std::strcat(buff, str);
    delete[] str;
    // str = new char[std::strlen(buff)]; //Non mi serve creare un nuovo punto di memoria, perchè rubo quello creato da buff
    str = buff;
    buff = nullptr;
    delete[] buff;
    return *this;
}
// ++ Uppercase pre //++a
Mystring &Mystring::operator++()
{
    for (size_t i{0}; i < std::strlen(str); i++)
        str[i] = std::toupper(str[i]);
    return *this;
}
// Uppercase post //a++
Mystring Mystring::operator++(int)
{
    Mystring temp(*this); // make a copy
    operator++();         // call pre-increment - make sure you call preincrement!
    return temp;          // return the old value
}
/*-----------------Friends---------------------*/
// Input
std::istream &operator>>(std::istream &in, Mystring &rhs)
{
    char *buff = new char[1000];
    char c{};
    int i{0};
    while (in.get(c) && c != '\n') // Prende lettera per lettera fino ad un acapo "\n"
    {
        buff[i++] = c;
    }
    buff[i] = '\0'; // Poi inserisce la fine della stringa
    rhs = Mystring{buff};
    delete[] buff;
    return in;
}

// Output
std::ostream &operator<<(std::ostream &ou, const Mystring &rhs)
{
    ou << rhs.str;
    return ou;
}


/* Another version of repeter

// repeat
Mystring Mystring::operator*(int n) const {
    Mystring temp;
    for (int i=1; i<= n; i++)
        temp = temp + *this;
    return temp;
}

// repeat and assign
Mystring &Mystring::operator*=(int n) {
    *this = *this * n;
    return *this;
}
*/