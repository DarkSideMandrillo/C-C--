#include "Player.h"
// Inizializzo la variabile statica
int Player::numPlayers{0};

// Principal constructor
Player ::Player(std::string nameVal, int healtVal, int xpVal)
    : name{nameVal}, health{healtVal}, xp{xpVal}
{
    ++numPlayers; // incremento la variabile static
}

Player ::Player(Player const &source)
    : Player(source.name, source.health, source.xp)
{
}

Player ::~Player()
{
    --numPlayers; // decremento la var static
}
// Creo la func che mi restituisce la variabile static
int Player::get_num_player()
{
    return numPlayers;
}
