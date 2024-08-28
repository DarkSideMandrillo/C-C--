#include <iostream>

using namespace std;

int main()
{
    int *intPtr{nullptr};
    intPtr = new int;
    cout << intPtr << endl;
    delete intPtr;
    cout << endl;
   
    cout << "\n---------------------\n";
   
    size_t size{0};
    double *tempPtr{};
    cout << "How many temps? ";
    cin >> size;
    // Alloco nell' Hipe lo spazio di un array di double di lunghezza size
    tempPtr = new double[size];
    cout << tempPtr << endl;

    delete[] tempPtr;

}
