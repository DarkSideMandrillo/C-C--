/*
Gli array sono fissi. Un blocco contiguo di memoria.
*/

#include <iostream>

using namespace std;

int main() {
    int test_score[5]{100,95,99,87,88};
    int highScorPerLevel[10]{3,5}; //remaining to 0

    const int dayInYear{365};
    double hiTemperatures[dayInYear]{0}; //init all to zero

    int anotherArray []{1,2,3,4,5}; //size automaticaly calculated

    int multiArray[][5]{{1,2,3},{0,1,2}};
}