// [] - Empty capture list - is statless Lambda

#include <iostream>
#include <string>
#include <vector>
#include <functional> //std::function (vedere se con C++20 serve ancora) - serve per stooges function
#include <algorithm>

void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();

class Person
{
    friend std::ostream &operator<<(std::ostream &os, const Person &rhs);

private:
    std::string name;
    int age;

public:
    Person(std::string name, int age) : name{name}, age{age} {};
    Person(const Person &p) : name{p.name}, age{p.age} {};
    ~Person() = default;
    std::string get_Name() const { return name; };
    void set_Name(std::string name) { this->name = name; };
    int get_Age() const { return age; }
    void set_Age(int age) { this->age = age; };
};

std::ostream &operator<<(std::ostream &os, const Person &rhs)
{
    os << "[Person: " << rhs.name << " : " << rhs.age << " ]";
    return os;
}

//----------MAIN-----------------
int main()
{
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
    test7();

    std::cout << std::endl;
}

//-----------FUNC 01-----------------
void test1()
{
    std::cout << "\n---Test1------------------------" << std::endl;

    []()
    { std::cout << "Hi" << std::endl; }();

    [](int x)
    { std::cout << x << std::endl; }(100);

    [](int x, int y)
    { std::cout << x + y << std::endl; }(100, 200);
}

//-----------FUNC 02-----------------
// Using values and referances as lambda parameter
void test2()
{
    std::cout << "\n---Test2------------------------" << std::endl;

    auto l1 = []()
    { std::cout << "Hi" << std::endl; };
    l1();

    int num1{100};
    int num2{100};

    auto l2 = [](int x, int y)
    { std::cout << x + y << std::endl; };
    l2(10, 20);
    l2(num1, num2);

    auto l3 = [](int &x, int y)
    {
        std::cout << "x: " << x << " y: " << y << std::endl;
        x = 1000; // è byRef, perciò cambia num1
        y = 2000; // è byVal perciò non serve a nulla
    };

    l3(num1, num2);
    std::cout << "num1: " << num1 << " num2: " << num2 << std::endl;
}

//-----------FUNC 03-----------------
void test3()
{
    std::cout << "\n---Test3------------------------" << std::endl;

    Person stooge{"Larry", 18};
    std::cout << stooge << std::endl;
    auto l4 = [](Person p)
    { std::cout << p << std::endl; };
    l4(stooge);

    auto l5 = [](const Person &p)
    { std::cout << p << std::endl; };
    l5(stooge);

    auto l6 = [](Person &p)
    {
        p.set_Name("Frank");
        p.set_Age(25);
        std::cout << p << std::endl;
    };
    l6(stooge);

    std::cout << stooge << std::endl;
}

//-----------FUNC 04-----------------
// Dichiaro prima una funzione filter_vector
// void filter_vector(const std::vector<int> &vec, std::function<bool(int)> func)    //C++ 14
void filter_vector(const std::vector<int> &vec, auto func) // C++ 20
{
    std::cout << "[ ";
    for (int i : vec)
        if (func(i)) // Qua controllo la funzione che ho passato (restituisce un bool)
            std::cout << i << " ";
    std::cout << "]" << std::endl;
}
void test4()
{
    std::cout << "\n---Test4------------------------" << std::endl;

    std::vector<int> nums{10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    filter_vector(nums, [](int x)
                  { return x > 50; }); // Questa è la Lambda che passo dentro la funzione

    filter_vector(nums, [](int x)
                  { return x <= 30; }); // Questa è la Lambda che passo dentro la funzione

    filter_vector(nums, [](int x)
                  { return x >= 30 && x <= 60; }); // Questa è la Lambda che passo dentro la funzione
}

//-----------FUNC 05-----------------
// Func to test5
auto make_lambda()
{
    return []()
    { std::cout << "This Lambda was made using the make_Lambda function!"; };
}
void test5()
{
    std::cout << "\n---Test5------------------------" << std::endl;

    auto l5 = make_lambda();
    l5();
}

//-----------FUNC 06-----------------
void test6()
{
    std::cout << "\n---Test6------------------------" << std::endl;

    auto l6 = [](auto x, auto y)
    {
        std::cout << "x: " << x << " y: " << y << std::endl;
    };
    l6(10, 20);
    l6(10.7, 27.25);
    l6(4.7, 300);

    l6(Person("Larry", 16), Person("Moe", 42));
}

//-----------FUNC 07-----------------
void test7()
{
    std::cout << "\n---Test7------------------------" << std::endl;

    std::vector<Person> stooges{{"Larry", 40}, {"Moe", 30}, {"Curly", 36}};

    // Ordina per nome
    std::sort(std::begin(stooges), std::end(stooges), [](const Person &p1, const Person &p2)
              { return p1.get_Name() < p2.get_Name(); }); // return a boolean.
    // Stamp
    std::for_each(std::begin(stooges), std::end(stooges), [](const Person &p)
                  { std::cout << p << std::endl; });
    std::cout << std::endl;

    // Ordina per Anno
    std::sort(std::begin(stooges), std::end(stooges), [](const Person &p1, const Person &p2)
              { return p1.get_Age() < p2.get_Age(); }); // return a boolean.
    // Stamp
    std::for_each(std::begin(stooges), std::end(stooges), [](const Person &p)
                  { std::cout << p << std::endl; });
    std::cout << std::endl;
}
