#include <iostream>

using namespace std;

int main() {

int counter {10};
int resultA {0};
int resultB {0};

resultA = ++counter; // ++ PRIMA (prima fa l'espressione, poi assegna)

cout << "resultA is "<< resultA<< endl;
cout << "counter is "<< counter<< endl;

counter =10;
resultB = counter++; // ++ DOPO (prima assegna, poi fa l'espressione)
cout << "\nresultB is "<< resultB<< endl;
cout << "counter is "<< counter<< endl;

}