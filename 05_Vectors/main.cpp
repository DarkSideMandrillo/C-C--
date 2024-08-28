/*
Fanno parte della standar librery
Sono dinamici
Sono oggetti
automaticamente inizializzati a 0
Elementi stesso tipo
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {

vector <int> testScore{100,95,99,87,88};
cout <<"First score index 0: "<<testScore[0]<<endl;
cout <<"Last score index 4: "<<testScore.at(4)<<endl; //Sintax vector. Gestisce eccezioni(bound checking)

testScore.push_back(77);
cout <<"New last score index 5: "<<testScore.at(5)<<endl;

vector <int> provaTest0 (3); //three element all inizializated to zero 
vector <int> provaTest1 (3,100); //three element all inizializated to 100
vector <int> provaTest2 {30,100,70}; //three element inizializated to {3,100,70}
cout<<provaTest2.at(0)<<endl <<"Il vettore è lungo "<<provaTest2.size()<<endl;

//Dinamic

int scoreToAdd{0};
cin >> scoreToAdd;
provaTest2.push_back(scoreToAdd);
cout << "\nProvaTest2 ora è "<< provaTest2.size() <<endl;

//Eccezione
//cout << "Questo causa un eccezione"<<provaTest2.at(10)<<endl;

//2D Vector
vector <vector<int>> movieRating{
    {1,2,3,4},
    {1,2,4,4},
    {1,3,4,5}
};


}