#include <iostream>
#include <string>
#include <vector>

/*
Template classes are typically completly contained in header file
so, we would have the template class in item.h and no item.cpp file
*/

template <typename T>
class item
{
private:
    std::string name;
    T value;

public:
    item(std::string name, T value) : name{name}, value{value} {}
    std::string get_name() const { return name; }
    T get_value() const { return value; }
};

template <typename T1, typename T2>
struct My_Payr
{
    T1 firs;
    T2 second;
};

int main()
{
    item<int> item1{"Frank", 100}; // dichiaro che tutti i typename saranno INT per quelaa classe
    std::cout << item1.get_name() << " " << item1.get_value() << std::endl;

    item<std::string> item2{"Franco", "Professor"};
    std::cout << item2.get_name() << " " << item2.get_value() << std::endl;

    item<item<std::string>> item3{"Franciesco", {"c++", "Professor"}};
    std::cout << item3.get_name() << " "
              << item3.get_value().get_name() << " "
              << item3.get_value().get_value() << std::endl;

    // ============================================================
    std::cout << "\n================================================" << std::endl;

    std::vector<item<double>> vec{};
    vec.push_back(item<double>("Larry", 100.0));
    vec.push_back(item<double>("moe", 200.0));
    vec.push_back(item<double>("Curly", 300.0));

    for (const auto &item : vec)
    {
        std::cout << item.get_name() << " " << item.get_value() << std::endl;
    }
    // ============================================================
    std::cout << "\n================================================" << std::endl;

    My_Payr<std::string, int> p1{"Frank", 100};
    My_Payr<int, double> p2{123, 13.6};

    std::cout << p1.firs << ", " << p1.second << std::endl;
    std::cout << p2.firs << ", " << p2.second << std::endl;
}
