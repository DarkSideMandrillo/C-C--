#include <iostream>

using namespace std;

int main() {
    //cout <<boolalpha;
    auto a= 3 <=> 4 ;
    if (a < 0){
        cout << "cacchio"<< endl;
        cout << sizeof(a) << endl;
    }

}