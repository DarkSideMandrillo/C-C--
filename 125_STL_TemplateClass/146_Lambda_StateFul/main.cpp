/*
Le statefull hanno una variabile/valore dentro le quadre, es [x]
Questa variabile viene passata al costruttore della classe generata in compilazione
Il metodo associato all'override dell'operatore() sarà const, ovvero impossibilitato a modificare i membri della classe
*/

#include <iostream>
#include <vector>
#include <algorithm>

int global_x{1000};

// Capture by value
// The global variable global_x cannot be captured because it is not
// within the reaching scope of the lambda. It can however still be accessed
// from within the lambda using normal name lookup rules.
void test1()
{
    std::cout << "\n---Test1 --------------------------" << std::endl;

    int local_x{100};
    // Sta facendo una copia, è vyVal
    auto l = [local_x]()
    {
        std::cout << local_x << std::endl;
        std::cout << global_x << std::endl;
    };
    l();
}

// Capture by value - mutable
// The captured variable x can only be modified within the lambda by
// using the mutable keyword. Note that this modifiability only pertains to
// the captured variable within the lambda body and not the actual variable.
void test2()
{
    std::cout << "\n---Test2 --------------------------" << std::endl;

    int x{100};

    auto l = [x]() mutable
    {
        x += 100;
        std::cout << x << std::endl;
    }; // Qua viene richiamato il constructor

    l();
    std::cout << x << std::endl; // X è sempre a 100, perchè non ritorna nulla il lambda.

    l();
    std::cout << x << std::endl;
}

// Capture by reference
// Any changes made to the captured reference variable within the lambda body
// will change the actual variable.
void test3()
{
    std::cout << "\n---Test3 --------------------------" << std::endl;

    int x{100};

    auto l = [&x]() mutable
    {
        x += 100;
        std::cout << x << std::endl;
    };

    l();
    std::cout << x << std::endl; // Ora x del costruttore della "classe lambda" e la local_x sono collegate
}

// Default capture by value - mutable
// Only variables used within the lambda body are captured by value.
// The variable z is not captured by the lambda.
void test4()
{
    std::cout << "\n---Test4 --------------------------" << std::endl;

    int x{100};
    int y{200};
    int z{300}; // Note that z is not captured in the lambda since it is not used.
                // This should produce an 'unused variable' warning when compiling.

    auto l = [=]() mutable
    {
        x += 100;
        y += 100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
    };
    l();

    std::cout << "\n";
    std::cout << x << std::endl;
    std::cout << y << std::endl;
}

// Default capture by reference
// This time because all three variables - x,y,z are used within
// the lambda body, all three of them will be captured by reference.
void test5()
{
    std::cout << "\n---Test5 --------------------------" << std::endl;

    int x{100};
    int y{200};
    int z{300};

    auto l = [&]()
    {
        x += 100;
        y += 100;
        z += 100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    };
    l();

    std::cout << "\n";
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}

// Default capture by value, capture y by reference
void test6()
{
    std::cout << "\n---Test6 --------------------------" << std::endl;

    int x{100};
    int y{200};
    int z{300};

    auto l = [=, &y]() mutable
    {
        x += 100;
        y += 100;
        z += 100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    };
    l();

    std::cout << "\n";
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}

// Default capture by reference, capture x and z by value
// Equivalent to test6
void test7()
{
    std::cout << "\n---Test7 --------------------------" << std::endl;

    int x{100};
    int y{200};
    int z{300};
    // Tutto ByRef, tranne x, z
    auto l = [&, x, z]() mutable
    {
        x += 100;
        y += 100;
        z += 100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    };
    l();

    std::cout << "\n";
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}

// Used for test8
class Person
{
    friend std::ostream &operator<<(std::ostream &os, const Person &rhs);

private:
    std::string name;
    int age;

public:
    Person() = default;
    Person(std::string name, int age) : name{name}, age{age} {}
    Person(const Person &p) = default;
    ~Person() = default;
    std::string get_name() const { return name; }
    void set_name(std::string name) { this->name = name; };
    int get_age() const { return age; }
    void set_age(int age) { this->age = age; }
// Sono tutte ByRef
    auto change_person1()
    {
        return [this](std::string new_name, int new_age)
        {name = new_name; age = new_age; };
    }
    auto change_person2()
    {
        return [=](std::string new_name, int new_age)
        {name = new_name; age = new_age; };
    }
    auto change_person3()
    {
        return [&](std::string new_name, int new_age)
        {name = new_name; age = new_age; };
    }
};

std::ostream &operator<<(std::ostream &os, const Person &rhs)
{
    os << "[Person: " << rhs.name << " : " << rhs.age << "]";
    return os;
}

// Default capture by reference of the current object using [this]
// [=], [&], and [this] are equivalent when capturing an object's member variables - all are captured by reference
// Notre that capturing this with [=] has been deprecated in C++20
// Also, C++20 allows [*this], which captures by value!
void test8()
{
    std::cout << "\n---Test8 --------------------------" << std::endl;

    Person person("Larry", 18);
    std::cout << person << std::endl;

    // Default capture [this]
    // This is the preferred way
    auto change_person1 = person.change_person1();
    change_person1("Moe", 30);
    std::cout << person << std::endl;

    // Default capture [=]
    // This has been deprecated in C++20
    auto change_person2 = person.change_person2();
    change_person2("Curly", 25);
    std::cout << person << std::endl;

    // Default capture [&]
    auto change_person3 = person.change_person3();
    change_person3("Frank", 34);
    std::cout << person << std::endl;
}

// Used for test9
class Lambda
{
private:
    int y;

public:
    Lambda(int y) : y{y} {};

    void operator()(int x) const
    {
        std::cout << x + y << std::endl;
    };
};

// Lambda class equivalence example
void test9()
{
    std::cout << "\n---Test9 --------------------------" << std::endl;

    int y{100};

    Lambda lambda1(y);
    auto lambda2 = [y](int x)
    { std::cout << x + y << std::endl; };

    lambda1(200);
    lambda2(200);
}

// Class used in the test10() example
class People
{
    std::vector<Person> people;
    int max_people_display;

public:
    People(int max = 10) : max_people_display(max) {}
    People(const People &p) = default;
    void add(std::string name, int age)
    {
        people.emplace_back(name, age);
    }
    void set_max_people(int max)
    {
        max_people_display = max;
    }
    int get_max_people() const
    {
        return max_people_display;
    }

    // This method returns a vector of Person objects in
    // people whose age > max_age AND it limits the number of
    // persons returned to be <= the member variable max_people.
    // Note that the lambda in this example captures this, by reference, and by value
   // Ritorna un vettore di Person che sono più grandi di (max_age), ma il numero di persone max che vengono visualizzate è dato da max_people_display
    std::vector<Person> get_people(int max_age)
    {
        std::vector<Person> result;
        int count{0};
        std::copy_if(people.begin(),    // Inizio di cosa voglio copiare
                     people.end(),      // Fine di cosa voglio copiare
                     std::back_inserter(result),    // Dove voglio inserire la copia (Uso iterator perchè result è un vector STL)
                     [this, &count, max_age](const Person &p)
                     { return p.get_age() > max_age && ++count <= max_people_display; });   // This mi da accesso alla classe People (se stessa)
        return result;                                                                      // questo perchè devo usare max_people_display, altrimenti non avrei accesso
                                                                                            // count deve incrementare per controllarlo con max_people_display, quindi è ref
                                                                                            // This non passerebbe anche count e max_age, in quanto rappresenta solo la classe Person
    }
};

void test10()
{
    std::cout << "\n---Test10 --------------------------" << std::endl;

    People friends;
    friends.add("Larry", 18);
    friends.add("Curly", 25);
    friends.add("Moe", 35);
    friends.add("Frank", 28);
    friends.add("James", 65);

    auto result = friends.get_people(17);

    std::cout << std::endl;
    for (const auto &p : result)
        std::cout << p << std::endl;

    friends.set_max_people(3);  //Cambio il display del maxPeople

    result = friends.get_people(17);

    std::cout << std::endl;
    for (const auto &p : result)
        std::cout << p << std::endl;

    result = friends.get_people(50);

    std::cout << std::endl;
    for (const auto &p : result)
        std::cout << p << std::endl;
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();

    std::cout << "\n";
}