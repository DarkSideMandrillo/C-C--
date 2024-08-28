#include <iostream>
#include <vector>
// #include <iomanip>

using namespace std;

int main()
{
    vector<vector<int>> vector2D{
        {1, 2, 3},
        {10, 20, 30},
        {100, 200, 300}};

    for (auto d1 : vector2D)
    {
        for (auto d2 : d1)
        {
            cout << d2 << " ";
        }
        cout << endl;
    }
    for (vector d1 : vector2D)
    {
        for (int d2 : d1)
        {
            cout << d2 << " ";
        }
        cout << endl;
    }
    cout << endl;

    /*--------------------------*/

    for (int num1{1}; num1 <= 10; num1++)
    {
        for (int num2{1}; num2 <= 10; num2++)
        {
            cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
        }
        cout << "-----------------" << endl;
    }
    cout << endl;

    /*------------------*/

    int numItems{};

    cout << "How many data items do you have? ";
    cin >> numItems;

    vector<int> data{};

    for (int i{1}; i <= numItems; ++i)
    {
        int dataItem{};
        cout << "Enter a data item " << i << ": ";
        cin >> dataItem;
        data.push_back(dataItem);
    }
    cout << "\nDisplay Histogram" << endl;
    for (auto val : data)
    {
        for (int i{1}; i <= val; i++)
            if (i % 5 == 0)
                cout << "*";
            else
                cout << "-";
        cout << endl;
    }

    cout << endl;
}