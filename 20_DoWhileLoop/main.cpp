#include <iostream>
// #include <vector>
// #include <iomanip>

using namespace std;

int main()
{
    char selection{};
    do
    {
        cout << "\n---------------------" << endl;
        cout << "1. Do this" << endl;
        cout << "2. Do that" << endl;
        cout << "3. Do something else" << endl;
        cout << "Q. Quit" << endl;
        cout << "\nEnter your selection" << endl;

        cin >> selection;

        switch (selection)
        {
        case '1':
            cout << "This" << endl;
            break;
        case '2':
            cout << "That" << endl;
            break;
        case '3':
            cout << "Bibibù" << endl;
            break;
        case 'q':
        case 'Q':
            break;
        default:
            cout << "Invalid selection" << endl;
            break;
        }

    } while (selection != 'q' && selection != 'Q');
    cout << endl;
}