#pragma once

class Mystring
{
private:
    char *str; // ptr to char[]
public:
    Mystring();
    Mystring(const char *s);
    Mystring(const Mystring &source);
    Mystring(Mystring &&source);
    ~Mystring();

    Mystring &operator=(const Mystring &rhs); // Copy assignmnent
    Mystring &operator=(Mystring &&rhs);      // Move assignment

    void display() const;
    int get_lenght() const;
    const char *get_str(); // char * indica una stringa (quindi questo metodo ritorna 1 stringa)
};
