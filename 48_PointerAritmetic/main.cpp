#include <iostream>
#include <string>

int main()
{

    int score[]{100, 95, 89, 68, -1};
    int *scorePtr{score};

    while (*scorePtr != -1)
    {
        std::cout << *scorePtr << std::endl;
        scorePtr++;
    }
    std::cout << "\n--------------------------" << std::endl
              << std::endl;

    scorePtr = score;
    while (*scorePtr != -1)
        std::cout << *scorePtr++ << std::endl; // Incremento scorePtr dopo averlo visualizzato *++scorePtr incrementerebbe prima

    std::cout << "\n--------------------------" << std::endl
              << std::endl;

    std::string s1{"Frank"};
    std::string s2{"Frank"};
    std::string s3{"James"};

    std::string *p1{&s1};
    std::string *p2{&s2};
    std::string *p3{&s1};

    std::cout << std::boolalpha;

    std::cout << p1 << "==" << p2 << ": " << (p1 == p2) << std::endl; // p2 punta a uno spazio di mem diverso
    std::cout << p1 << "==" << p3 << ": " << (p1 == p3) << std::endl; // p3 punta allo stesso spazio di memoria

    std::cout << *p1 << "==" << *p2 << ": " << (*p1 == *p2) << std::endl; // p2 deferenziato è uguale a p1
    std::cout << *p1 << "==" << *p3 << ": " << (*p1 == *p3) << std::endl; // p3 deferenziato è Diverso da p1

    p3 = &s3;                                                             // point to James
    std::cout << *p1 << "==" << *p3 << ": " << (*p1 == *p3) << std::endl; // p3 deferenziato ora è diverso da p1

    std::cout << "\n--------------------------" << std::endl
              << std::endl;

    char name[]{"Frank"};
    char *charPtr1{nullptr};
    char *charPtr2{nullptr};

    charPtr1 = &name[0]; // F
    charPtr2 = &name[3]; // n

    std::cout << "In the string " << name << ", " << *charPtr2 << " is " << (charPtr2 - charPtr1) << " character away from " << *charPtr1 << std::endl;
}