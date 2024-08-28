// Declare Class and Object
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*------CLASS-----*/

class Player
{
    // ATTRIBUTES
    string name{"Player"};
    int healt{0};
    int exp{3};

    // METODS
    void talk(string);
    bool is_dead();
};

class Base_Account
{
    // ATTRIBUTES
    string name{"Account"};
    double balance{0.0};

    // METODS
    bool deposit(double);
    bool withdraw(double);
};

/*------MAIN------*/

int main()
{
    //-------//
    Player frank;
    Player hero;

    Player players[]{frank, hero};

    vector<Player> playerVec{frank};
    playerVec.push_back(hero);

    Player *enemy{nullptr};
    enemy = new Player;

    delete enemy;

    //-------//
    Base_Account frankAccount;
    Base_Account JimAccount;
}