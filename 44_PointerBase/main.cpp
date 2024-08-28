#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{

    int num{10};
    cout << "value of num is: " << num << endl;
    cout << "size of num is: " << sizeof num << endl;
    cout << "address of num is: " << &num << endl;

    int *p;
    cout << "\nvalue of p is: " << p << endl;
    cout << "size of p is: " << sizeof p << endl;
    cout << "address of p is: " << &p << endl;

    p = nullptr;
    cout << "\nvalue of p is: " << p << endl;

    int *p1{nullptr};
    double *p2{nullptr};
    unsigned long long *p3{nullptr};
    vector<string> *p4{nullptr};
    string *p5{nullptr};

    cout << "\nsize of p1 is: " << sizeof p1 << endl;
    cout << "size of p2 is: " << sizeof p2 << endl;
    cout << "size of p3 is: " << sizeof p3 << endl;
    cout << "size of p4 is: " << sizeof p4 << endl;
    cout << "size of p5 is: " << sizeof p5 << endl;

    int score{10};
    double highTemp{12.5};

    int *scorePtr{nullptr};

    scorePtr = &score;
    cout << "\nvalue of score is: " << score << endl;
    cout << "address of score is: " << &score << endl;
    cout << "value of scorePtr is: " << scorePtr << endl;

    // scorePtr = &highTemp;  //Compiler error

    cout << endl;
}