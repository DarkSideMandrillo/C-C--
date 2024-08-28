#pragma once

#include <iostream>

class Mystring
{ // Input Oputput
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);
    friend std::ostream &operator<<(std::ostream &ou, const Mystring &rhs);

private:
    char *str;

public:
    Mystring();                       // Const no arg
    Mystring(const char *s);          // Const arg
    Mystring(const Mystring &source); // Copy Const
    Mystring(Mystring &&source);      // Move Const
    ~Mystring();                      // Destr

    /*----Operator Overload----*/
    Mystring &operator=(const Mystring &rhd); // Constr
    Mystring &operator=(Mystring &&rhd);      // Move

    bool operator==(const Mystring &rhd) const;
    bool operator!=(const Mystring &rhd) const;
    bool operator>(const Mystring &rhd) const;
    bool operator<(const Mystring &rhd) const;

    Mystring operator-() const;

    Mystring operator+(const Mystring &rhd) const;
    Mystring &operator+=(const Mystring &rhd);

    Mystring operator*(const size_t &rhd) const;
    Mystring &operator*=(const size_t &rhd);

    Mystring &operator++();
    Mystring operator++(int);

    /*----Metod----*/
    // Forse non servono
};
