#include<iostream>

using namespace std;

int main(){
//CHAR
char middle_initial {'j'};
cout<< "My middle initial is " << middle_initial<<endl;

//INTEGER
unsigned int examScore {55};
cout << "my exam score is " << examScore << endl;

int countriesRapresented {65};
cout<< "There were " << countriesRapresented<<" countries represented in my meeting"<<endl;

long peopleInFlorida {20'610'000};
cout<< "There are about " << peopleInFlorida<<" people in florida"<<endl;

long long distanceToAlphaCentauri {9'461'000'000'000};
cout<< "The distance to Alpha centauri is  " << distanceToAlphaCentauri<<"Km"<<endl;

//FLOAT

float carPayment {401.23};
cout <<"My car payment is"<<carPayment<<endl;

double pi {3.14159};
cout<<"PI is" << pi<< endl;

long double largeAmount{2.7e120};
cout << largeAmount <<"Is a very big number"<<endl;

//BOOLEAN

bool gameOver {false};
cout<< "The value of gameOver is "<<gameOver<<endl;

//Overflow example

short value1{30000};
short value2{1000};
short product {value1*value2};

cout << "\nThe sum of " << value1<<" and "<<value2<<" is " <<product<<endl;


return 0;
};