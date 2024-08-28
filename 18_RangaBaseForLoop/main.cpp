#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{

    cout << fixed << setprecision(1);
    // int scores[]{10, 20, 30};
    // for (auto score : scores) //auto capisce ce score deve essere int
    //     cout << score << endl;

    vector<double> temperatures{87.9, 77.9, 80.0, 72.5};
    double averageTemp{};
    double total{};

    for (auto temp : temperatures)
        total += temp;

    if (temperatures.size() != 0)
        averageTemp = total / temperatures.size();
    // L'operatore ? : funziona solo se entrambi i rami sono dello stesso tipo (int, char,string, ecc.)
    cout << "Average temperature is " << ((temperatures.size() != 0) ? (averageTemp = total / temperatures.size()) : 0) << endl;

    /*---------------------------------------------*/

    for (auto val : {1, 2, 3, 4, 5})
        cout << val << endl;

    for (auto c : "This is a test")
        if (c == ' ')
            cout << "\t";
        else
            cout << c;

    cout << endl;
}