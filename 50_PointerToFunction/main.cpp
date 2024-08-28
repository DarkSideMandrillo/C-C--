#include <iostream>
#include <vector>
#include <string>

// PASSING FUNCTION ByRef with pointer
using namespace std;

void doubleData(int *intPtr)
{
    *intPtr *= 2;
}

void swap(int *a, int *b)
{
    int temp{*a};
    *a = *b;
    *b = temp;
}
void display(const vector<string> *const v)
{
    // (*v).at(0)="Funny"; // Errore perchè il valore deferenziato di v è una costante
    for (auto str : *v)
        cout << str << " ";
    cout << endl;
    //v = nullptr; // cancello il puntatore.  il *const v mi impedisce di cambiare il contenuto del puntatore
}
void display2(const int *array, const int sentinel)
{
    while (*array != sentinel)
        cout << *array++ << " ";
    cout << endl;
}

int main()
{
    int value{10};
    int *intPtr{nullptr};
    // Add
    cout << "Value: " << value << endl;
    doubleData(&value);
    cout << "Value: " << value << endl;

    cout << "\n---------------------" << endl;
    intPtr = &value;
    doubleData(intPtr);
    cout << "Value: " << value << endl;
    cout << endl;
    // SWAP
    cout << "\n---------------------" << endl;
    int x{100}, y{200};
    cout << "\nx: " << x << endl;
    cout << "y: " << y << endl;

    swap(&x, &y);
    cout << "\nx: " << x << endl;
    cout << "y: " << y << endl;

    // Dysplay Vector
    cout << "\n---------------------" << endl;
    vector<string> stooges{"Larry", "Moe", "Curly"};
    display(&stooges);
    cout << endl;

    // Display Array
    cout << "\n---------------------" << endl;
    int scores[]{100, 98, 97, 79, 58, -1};
    display2(scores, -1);

    cout << endl;
}