#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1;             // Empty
    string s2{"Franck"};   // Franck
    string s3{s2};         // Franck
    string s4{"Frank", 3}; // Fra
    string s5{s3, 0, 2};   // Fr
    string s6(3, 'X');     // XXX

    string part1{"C++"};
    string part2{"Is Powerfull"};
    string sentence;

    sentence = part1 + " " + part2 + " Language";
    // sentence ="C++"+" is powerfull"; // ILLEGAL is a 2 cStye litteraly

    /*--------------------------------*/

    string ss1{"Frank"};
    for (char c : ss1)
        cout << c << endl;
    for (int c : ss1)
        cout << c << endl; // Vede il n ascii
    /*----*/

    cout << endl
         << ss1.substr(1, 2) << endl; // ra

    /*------------*/

    string ss2{"This is a test"};

    cout << ss2.find("This") << endl;  // 0
    cout << ss2.find("is") << endl;    // 2
    cout << ss2.find("test") << endl;  // 10
    cout << ss2.find("e") << endl;     // 11
    cout << ss2.find("is", 4) << endl; // 5
    cout << ss2.find("XXX") << endl;   // String::npos
    /*----------*/
    cout << ss2.length() << endl;
    ss2 += " ?";

    /*--------Input--------*/
    //Non funge
    cout << endl;

    string ss3;
    cout<<"INSERISCI ss3: "<<endl;
    cin >> ss3;          // hello there
                         // accepts up to the first space
    cout << ss3 << endl; // hello

    getline(cin, ss3); // read entire line until \n
    cout << ss3 << endl;

   getline(cin, s1, 'x');//read all until 'x'
    cout << ss3 << endl;
}