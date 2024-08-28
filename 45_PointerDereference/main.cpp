#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int score{100};
    int *scorePtr{&score};

    cout << "Dereferencing of scorePtr" << *scorePtr << endl;

    *scorePtr = 200;

    cout << "Dereferencing of scorePtr after mod is " << *scorePtr << endl;
    cout << "value of score is " << score << endl;

    cout << "\n----------------------------" << endl;

    double highTemp{100.7};
    double lowTemp{37.4};
    double *tempPtr{&highTemp};

    cout << "deref tempPtr " << *tempPtr << endl;
    tempPtr = &lowTemp;
    cout << "deref tempPtr " << *tempPtr << endl;

    cout << "\n----------------------------" << endl;

    string name{"Frank"};
    string *stringPtr{&name};

    cout << "\nderef stringPtr " << *stringPtr << endl;
    name = "james";
    cout << "deref stringPtr " << *stringPtr << endl;

    cout << "\n----------------------------" << endl;

    vector<string> stooges{"Larry", "Moe", "Curly"};
    vector<string> *vectorPtr{nullptr};

    vectorPtr = &stooges;

    cout << "first stooge: " << (*vectorPtr).at(0) << endl;

    cout << "\nStooges: ";
    for (auto stooge : *vectorPtr)
        cout << stooge << " ";

    cout << endl;
}