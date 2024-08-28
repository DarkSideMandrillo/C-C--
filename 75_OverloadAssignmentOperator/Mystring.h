#pragma once

class Mystring
{
private:
    char *str; // ptr to char[]
public:
    Mystring();
    Mystring(const char *s);
    Mystring(const Mystring &source);
    ~Mystring();
// Notare che passo ByRef, perchè se assegno significa che cambio il contenuto del valore a sx
    Mystring &operator=(const Mystring &rhs); // Copy assignmnent


    void display() const;
    int get_lenght() const;
    const char *get_str(); // char * indica una stringa (quindi questo metodo ritorna 1 stringa)
};
