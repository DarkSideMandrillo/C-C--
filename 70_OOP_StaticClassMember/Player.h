#pragma once

#include <string>

class Player
{
private:
    std::string name;
    int health;
    int xp;
    // Dichiaro la variabile static (non la inizializzo)
    static int numPlayers;

public:
    void set_name(std::string nameVal) { name = nameVal; }
    std::string get_name() { return name; }
    int get_healt() { return health; };
    int get_xp() { return xp; };

    Player(std::string nameVal = "none", int healthVal = 0, int xpVal = 0);
    Player(const Player &source);
    ~Player();
// Creo la funzione che mi restituisce la variabile static
    static int get_num_player();
};
