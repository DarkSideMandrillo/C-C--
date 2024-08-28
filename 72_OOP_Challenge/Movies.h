#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Movie.h" // Qua devo collegare l'altra classe, visto che la uso negli attributi

class Movies
{
private:
    std::vector<Movie> mov;
    std::string owner; // Da implementare, non ne ho voglia

public:
    // All constructor and Destructor
    Movies();
    Movies(Movies const &source);
    // Movies(Movies &&source) noexcept; Non serve, sarebbe uguale al copy
    ~Movies();
    // Metods

    bool add_movie(std::string nameVal, std::string rating, int watched);
    bool increment_watched(std::string nameVal);
    void display();
};
