#include <iostream>

using namespace std;

int main() {
    int totalAmount {100};
    int totalNumber {8};
    double average {0.0};
    
    average = totalAmount / totalNumber;
    cout << average << endl;

    average = static_cast<double>(totalAmount)/totalNumber;
    //average = totalAmount/static_cast<double>(totalNumber); //Same, if one variable is higher in operation, the other variable in promot to high 

    cout << average << endl;
}
