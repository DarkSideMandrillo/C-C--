// Se abbiamo un oggetto possiamo usare dot operator
// Se abbiamo un pointer per un oggetto allora possiamo dereferenziarlo o usare -> (*oggettoPtr).metodo || oggettoPtr->metodo

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*------CLASS-----*/

class Player
{
public:
    // ATTRIBUTES
    string name{"Player"};
    int healt{0};
    int exp{3};

    // METODS
    void talk(string textToSay) { cout << name << " says " << textToSay << endl; }
    bool is_dead();
};

class Base_Account
{
public:
    // ATTRIBUTES
    string name{"Account"};
    double balance{0.0};

    // METODS
    bool deposit(double bal)
    {
        balance += bal;
        cout << "In deposit" << endl;
    }
    bool withdraw(double bal)
    {
        balance -= bal;
        cout << "in withdraw" << endl;
    }
};

/*------MAIN------*/

int main()
{
    //-------//
    Player frank;
    frank.name = "Frank";
    frank.healt = 100;
    frank.exp = 12;

    frank.talk("Hi there");

    //-------//

    Player *enemy{nullptr};
    enemy = new Player;
    (*enemy).name = "Enemy";
    enemy->exp = 50;
    enemy->healt = 150;
    (*enemy).talk("I will destroy you!");

    //-------//
    Base_Account frankAccount;
    frankAccount.name = "Frank's Account";
    frankAccount.balance = 5000.00;

    (&frankAccount)->deposit(1000); // Non ha senso ma funziona!
    frankAccount.withdraw(500.0);
}