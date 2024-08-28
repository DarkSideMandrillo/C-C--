// Section 17
// Weak Pointers

// Non contribuisce sul counter degli shared pointer

#include <iostream>
#include <memory>

using namespace std;

class B; // forward declaration

class A
{
    std::shared_ptr<B> b_ptr; // Qua usiamo B, x questo c'è la forward declaratio

public:
    void set_B(std::shared_ptr<B> &b)
    {
        b_ptr = b; // Questo chiama un copy, perciò aumenta il cont dello shared
    }
    A() { cout << "A Constructor" << endl; }
    ~A() { cout << "A Destructor" << endl; }
};

class B
{ /* Uno dei due deve essere un puntatore debole che non genera il
 conteggio dello shared. Così quando le istanze escono dallo scope,
 Il numero dello shared così non viene inclrementato nell'istruzione a_ptr = a;
 Quando uscirà dallo scope verrà cancellato e non rimarra appeso */
    std::weak_ptr<A> a_ptr;

public:
    void set_A(std::shared_ptr<A> &a)
    {
        a_ptr = a;
    }
    B() { cout << "B Constructor" << endl; }
    ~B() { cout << "B Destructor" << endl; }
};

int main()
{
    shared_ptr<A> a = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();
    a->set_B(b);
    b->set_A(a);

    return 0;
}
