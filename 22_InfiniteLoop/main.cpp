#include <iostream>
// #include <vector>
//  #include <iomanip>

using namespace std;

int main()
{
    while (true)
    {
        char again{};
        cout << "Do you want to loop again? (Y/N): ";
        cin >> again;

        if (again == 'N' || again == 'n')
            break;
    }
}