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
// ByRef
    Mystring &operator=(const Mystring &rhs); // Copy assignmnent
    Mystring &operator=(Mystring &&rhs);      // Move assignment
// ByVal
    Mystring operator-() const;                    // Lowercase //Ci basta la parte sinistra (L'oggetto che dobbiamo rendere minuscolo). Unary operator 0 parametri, binary operator 1 parametro
    Mystring operator+(const Mystring &rhs) const; // Concatenate
    bool operator==(const Mystring &rhs) const;    // Confrontation

    void display() const;
    int get_lenght() const;
    const char *get_str(); // char * indica una stringa (quindi questo metodo ritorna 1 stringa)
};
