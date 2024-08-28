#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    int num{};
    cout << "Enter a positive integer to count up to: ";
    cin >> num;

    int i{1};
    while (num >= i)
    {
        cout << i << endl;
        i++;
    }
    cout << endl
         << endl;
    /*--------------------------*/

    int number{};
    cout << "Enter an integer less than 100 ";
    cin >> number;

    while (!(number < 100))
    {
        cout << "Enter an integer less than 100 ";
        cin >> number;
    }
    cout << "Thanks" << endl
         << endl;

    /*-----------------------*/

    bool done{false};
    int numb{0};

    while (!done)
    {
        cout << "Enter an integer between 1 and 5: ";
        cin >> numb;
        if (numb <= 1 || numb >= 5)
            cout << "Out of range, try again" << endl;
        else
        {
            cout << "Thanks!" << endl;
            done = true;
        }
    }
}