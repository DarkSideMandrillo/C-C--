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

    Player()
        : name{"none"}, health{0}, xp{0} {}
    Player(std::string nameVal)
        : name{nameVal}, health{0}, xp{0} {}
    Player(std::string nameVal, int healthVal, int xpVal)
        : name{nameVal}, health{healthVal}, xp{xpVal} {}
};

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
