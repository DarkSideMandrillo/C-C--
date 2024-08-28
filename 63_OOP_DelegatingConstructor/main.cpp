// Nel metodo precedente nel constructor assegnamo il valore. Ora inizializziamo le variabili Prima del codice
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
    void set_name(std::string nameVal) { name = nameVal; }
    std::string get_name() { return name; }

    Player();
    Player(std::string nameVal);
    Player(std::string nameVal, int healthVal, int xpVal);
};

// CONSTRUCTOR
Player ::Player()
    : Player{"null", 0, 0} // Richiama il constructor Player con 3 arg
{
    cout << "\nno arg constructor" << endl;
} 

Player ::Player(std::string nameVal)
    : Player{nameVal, 0, 0}// Richiama il constructor Player con 3 arg
{
    cout << "\ntwo arg constructor" << endl;
} 

Player ::Player(std::string nameVal, int healthVal, int xpVal) // Forse è meglio metterlo all'inizio ma anche così funziona, visto che ho dichiarato nella classe tutti e 3 i metodi
    : name{nameVal}, health{healthVal}, xp{xpVal}
{
    cout << "\nthree arg constructor" << endl;  // Viene stampato ogni volta perchè è sempre lui a essere richiamato negli altri 2 constructor
}

int main()
{
    Player empty;
    Player frank{"Frank"};
    Player villain{"Villain", 100, 55};

    cout << empty.get_name() << endl;
    cout << frank.get_name() << endl;
    cout << villain.get_name() << endl;
    return 0;
}
