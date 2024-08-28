// Pass by Reference
// Al posto di fare una copia, crea solamente un alias

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void pass_by_ref1(int &num);
void pass_by_ref2(string &str);
void pass_by_ref3(vector<string> &vec);
void print_vector(const vector<string> &vec);

void pass_by_ref1(int &num)
{
    num = 1000;
}

void pass_by_ref2(string &str)
{
    str = "Changed";
}
void pass_by_ref3(vector<string> &vec)
{
    vec.clear();
}
void print_vector(const vector<string> &vec)
{
    for (auto s : vec)
        cout << s << " ";
    cout << endl;
}

int main()
{
    int num{10};
    int anotherNum{20};

    cout << "num before calling pass_by_ref1 " << num << endl;
    pass_by_ref1(num);
    cout << "num after calling pass_by_ref1 " << num << endl;

    cout << "anotherNum before calling pass_by_ref1 " << anotherNum << endl;
    pass_by_ref1(anotherNum);
    cout << "anotherNum after calling pass_by_ref1 " << anotherNum << endl;

    cout << endl;

    string name{"Frank"};
    cout << "name before calling pass_by_ref2 " << name << endl;
    pass_by_ref2(name);
    cout << "name after calling pass_by_ref2 " << name << endl;

    vector<string> stooges{"Larry", "Moe", "Curly"};
    cout << "\nstooges before calling pass_by_ref3: ";
    print_vector(stooges);
    pass_by_ref3(stooges);
    cout << "stooges after calling pass_by_ref3: ";
    print_vector(stooges);
}
