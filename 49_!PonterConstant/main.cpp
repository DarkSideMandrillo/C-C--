

int main()
{

    int highScore{100};
    int lowScore{65};

    // POINTER TO CONSTANTS
    const int *scorePtr1{&highScore};

    *scorePtr1 = 86;       // ERROR
    scorePtr1 = &lowScore; // OK

    // CONSTANT POINTER
    int const *scorePtr2{&highScore};

    *scorePtr2 = 86;       // OK
    scorePtr2 = &lowScore; // ERROR

    // CONSTANT POINTER TO CONSTANT
    int const *scorePtr3{&highScore};

    *scorePtr3 = 86;       // ERROR
    scorePtr3 = &lowScore; // ERROR
}