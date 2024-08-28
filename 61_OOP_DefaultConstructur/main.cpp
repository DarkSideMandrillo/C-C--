/*
C++ genera automaticamente un constructor senza argomenti
Se creo un constructor con argomenti, C++ non genera il constructor
*/

// Section 13
// Default Constructors
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
    std::string get_name()
    {
        return name;
    }
    // Player() // Lo uso per non aver dati spazzatura
    // {
    //     name = "None";
    //     health = 100;
    //     xp = 3;
    // }
    Player(std::string name_val, int health_val, int xp_val)
    { // Questo constructor fa si che non si generi automaticamente il default (così è stato creato nella parte sopra)
        name = name_val;
        health = health_val;
        xp = xp_val;
    }
};

int main()
{
    Player hero; // Ritorna errore, non c'è il default constructor
    Player frank{"Frank", 100, 13};
    frank.set_name("Frank");
    cout << frank.get_name() << endl;
    return 0;
}
