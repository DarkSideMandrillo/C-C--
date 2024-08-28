// Non sempre si riesce a implementare, ma semplifica
// Attenzione in questo caso creare un constructor senza argomenti si crea un ambiguità
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

    Player(std::string nameVal = "None", int healthVal = 0, int xpVal = 0);
};

// CONSTRUCTOR with default value

Player ::Player(std::string nameVal, int healthVal, int xpVal) // Forse è meglio metterlo all'inizio ma anche così funziona, visto che ho dichiarato nella classe tutti e 3 i metodi
    : name{nameVal}, health{healthVal}, xp{xpVal}
{
}

int main()
{
    Player empty; //Sto chiamando il costruttore con 3 argomenti, perchè sono settati in default anche se non li inserisco
    Player frank{"Frank"};
    Player villain{"Villain", 100, 55};

    cout << empty.get_name() << endl;
    cout << frank.get_name() << endl;
    cout << villain.get_name() << endl;
    return 0;
}
