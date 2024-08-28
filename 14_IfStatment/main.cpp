#include <iostream>

using namespace std;

int main()
{
    int num{};
    const int min{10};
    const int max{100};

    cout << "Enter a number between " << min << " and " << max << ": ";
    cin >> num;

    if (num >= min)
    {
        cout << "\n======================if statment 1=====================" << endl;
        cout << num << " is greter than or equal to " << min << endl;

        int diff{num - min}; // Variabile che esiste SOLO nell'if
        cout << num << " is " << diff << " greter then " << min << endl;
    }
    if (num <= max)
    {
        cout << "\n======================if statment 2=====================" << endl;
        cout << num << " is less than or equal to " << max << endl;

        int diff{max - num}; // Variabile che esiste SOLO nell'if
        cout << num << " is " << diff << " less then " << max << endl;
    }
    if (num <= max && num >= min)
    {
        cout << "\n======================if statment 3=====================" << endl;
        cout << num << " is in range " << endl;

        int diff{num}; // Variabile che esiste SOLO nell'if
        cout << num << " is " << max - diff << " less then " << max << endl;
        cout << num << " is " << diff - min << " greter then " << min << endl;
    }
    if (num == max || num == min)
    {
        cout << "\n======================if statment 4=====================" << endl;
        cout << "Is on a boundary" << endl;
    }

    //--------------------------------------------------------------------

    int score{};
    cout << "\n\nInserisci lo score" << endl;
    cin >> score;
    if (score > 90)
    {
        cout << "A" << endl;
    }
    else if (score > 80)
    {
        cout << "B" << endl;
    }
    else if (score > 70)
    {
        cout << "C" << endl;
    }
    else if (score > 60)
    {
        cout << "D" << endl;
    }
    else
    {
        cout << "F" << endl;
    }
}