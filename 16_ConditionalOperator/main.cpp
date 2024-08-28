#include <iostream>

using namespace std;

int main()
{
    int num{};

    cout << "Enter an integer: ";
    cin >> num;

    if (num % 2 == 0)
        cout << num << " is even" << endl;
    else
        cout << num << " is odd" << endl;

    cout << num << " is " << ((num % 2 == 0) ? "even" : "odd") << endl
         << endl;

    /*-------------------------------------------*/

    int num1{}, num2{};

    cout << "Enter 2 integer separate by space" << endl;
    cin >> num1 >> num2;

    if (num1 != num2)
    {
        cout << "Largest: " << ((num1 > num2) ? num1 : num2) << endl;
        cout << "Smallest: " << ((num1 < num2) ? num1 : num2) << endl;
    }
    else
        cout << "The numbers are the same" << endl
             << endl;
    /* -------------------------------------------------- */
    int a{10}, b{5};
    int score{92};
    int result{};
    // 1
    result = (a > b) ? a : b;
    cout << "- 1) " << result << endl;
    // 2
    result = (a < b) ? (b - a) : (a - b);
    cout << "- 2) " << result << endl;
    // 3
    result = (b != 0) ? (a / b) : 0;
    cout << "- 3) " << result << endl;
    // 4
    cout << ((score > 90) ? "Excellent" : "Good") << endl;
}