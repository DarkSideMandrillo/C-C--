#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(int);
void print(double);
void print(string);
void print(string, string);
void print(vector<string>);

void print(int num)
{
    cout << "Printing int: " << num << endl;
}
void print(double num)
{
    cout << "Printing double: " << num << endl;
}
void print(string str)
{
    cout << "Printing string: " << str << endl;
}
void print(string str1, string str2)
{
    cout << "Printing 2 string: " << str1 << " and " << str2 << endl;
}
void print(vector<string> vec)
{
    cout << "Printing vector of string: ";
    for (auto str : vec)
        cout
            << str + " ";
    cout << endl;
}

int main()
{
    print(100);
    print('a');

    print(12.5);
    print(12.5F); // Float is promote as double

    print("C-Style string"); // Il compilatore converte C-Style string in C++ String
    string s{"C++ string style"};
    print(s);

    print("C-Style string", s); // Converte

    vector<string> threeStoogers{"Larry", "Moe", "Curly"};
    print(threeStoogers);
}