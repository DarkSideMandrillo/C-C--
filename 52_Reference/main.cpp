#include <iostream>
#include <vector>
#include <string>

using namespace std;

void display(const vector<string> &vec)
{
    for (auto const &chr : vec) //Uso il const con un referance così diventa un alias senza possibilità di cambio. 
        cout << chr << " ";
    cout << endl;
}

int main()
{
    vector<string> stooges{"Larry", "Moe", "Curly"};
//////////////////////////////////// str è una COPIA
    for (auto str : stooges)
        str = "Funny";
    display(stooges);
//////////////////////////////////// str è un ALIAS(reference)
        for (auto &str : stooges)
        str = "Funny";
    display(stooges);
}
