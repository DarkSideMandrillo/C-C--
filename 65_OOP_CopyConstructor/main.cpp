// CopyConstructor - Si presenta quando:
//  -passiamo ByVal un oggetto come parametro di una func
//  -Ritorniamo un oggetto da una func
//  -Costruiamo un oggetto basato su un altro della stessa classe
// Se non fornito ne fornirà uno di Default
// Il metodo si scrive -Player::Player(const Player &source)-

// Section 13
// Copy Constructor
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
    std::string get_name() { return name; }
    int get_health() { return health; }
    int get_xp() { return xp; }
    Player(std::string name_val = "None", int health_val = 0, int xp_val = 0);
    // Copy constructor
    Player(const Player &source);
    // Destructor
    ~Player() { cout << "Destructor called for: " << name << endl; } // Scrive il nome dell'oggetto distrutto
};

Player::Player(std::string nameVal, int healthVal, int xpVal)
    : name{nameVal}, health{healthVal}, xp{xpVal}
{
    cout << "Three-args constructor for " + name << endl;
}

Player::Player(const Player &source)
    // : name(source.name), health(source.health), xp{source.xp} //*** Uso il delegating constructor che è + chiaro (chiamo Player con 3 arg)
    : Player{source.name, source.health, source.xp} // Source è la classe che ho passato, cioè se stessa
{
    cout << "Copy constructor - made copy of: " << source.name << endl;
}

void display_player(Player p)
{
    cout << "Name: " << p.get_name() << endl;
    cout << "Health: " << p.get_health() << endl;
    cout << "XP: " << p.get_xp() << endl;
}

int main()
{
    Player empty{"XXXXXX", 100, 50};

    Player my_new_object{empty};

    display_player(my_new_object); // Passeremo l'oggetto ByValue, perciò verrà fatta una copia e usato il CopyConstructor

    Player frank{"Frank"};
    Player hero{"Hero", 100};
    Player villain{"Villain", 100, 55};

    return 0;
}