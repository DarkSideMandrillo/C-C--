// Section 16
// Using override
/*
 L'ovveride dice è solo una signature, se ho fatto un errore e ho ridefinito una func,
 Il compilatore darà un errore così da potermene accorgere
*/
#include <iostream>

class Base {
public:
    virtual void say_hello() const {
        std::cout << "Hello - I'm a Base class object" << std::endl;
    }
    virtual ~Base() {}
};

class Derived: public Base {
public:
    virtual void say_hello() override {             // Notice I forgot the const 
        std::cout << "Hello - I'm a Derived class object" << std::endl;
    }
    virtual ~Derived() {}
};


int main() {
    
    Base *p1 = new Base();      // Base::say_hello()
    p1->say_hello();
    
    Derived *p2 = new Derived();    // Derived::say_hello() 
    p2->say_hello();// Non da problemi, perchè ho creato un ptr di tipo Derived e non Bae
    
    Base *p3 = new Derived();   //  Base::say_hello()   ?????   I wanted Derived::say_hello()
    p3->say_hello();
    
   
    return 0;
}


