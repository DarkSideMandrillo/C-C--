#include <iostream>

extern int x;

int main(){
    
    int favoriteNumber;
    std::cout<<__cplusplus<<std::endl;
    std::cout<<"Enter your favorite number between 1 and 100: ";
    std::cin>>favoriteNumber;
    std::cout<<"Amazing! That's my favorite number too!"<<std::endl;
    std::cout<<"No really, "<<favoriteNumber<<" is my favorite number!";

    return 0;
}