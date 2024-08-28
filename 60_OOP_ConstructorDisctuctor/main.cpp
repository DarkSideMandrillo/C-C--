// Section 13
// Constructors and Destructors
//Posso creare Overloading di constructor (Stesso nome) ma non ha senso farlo con i distructor

#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
    std::string name;
    int health;
    int xp;

public:
    void set_name(std::string name_val)
    {
        name = name_val;
    }
    // Overloaded Constructors
    Player()
    {
        cout << "No args constructor called" << endl;
    }
    Player(std::string name)
    {
        cout << "String arg constructor called" << endl;
    }
    Player(std::string name, int health, int xp)
    {
        cout << "Three args constructor called" << endl;
    }
    ~Player() // Il distructor viene chiamato alla fine di una funzione } automaticamente
    {
        cout << "Destructor called for " << name << endl;
    }
};

int main()
{

    { // Sono funzioni + piccole solo per far vedere che il destructor parte automaticamente
        Player slayer;
        slayer.set_name("Slayer");
    }

    {
        Player frank;
        frank.set_name("Frank");
        Player hero("Hero");
        hero.set_name("Hero");
        Player villain("Villain", 100, 12);
        villain.set_name("Villain");
    } // Il distructor viene chiamato 3 volte

    Player *enemy = new Player;
    enemy->set_name("Enemy");

    Player *level_boss = new Player("Level Boss", 1000, 300);
    level_boss->set_name("Level Boss");

    delete enemy; //Cancellando il puntatore viene chiamato automaticamente il distructor
    delete level_boss;

    return 0;
}
