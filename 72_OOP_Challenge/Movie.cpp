#include <iostream>
#include <string>
#include "Movie.h"

// Constructor
Movie::Movie(std::string nameVal, std::string ratingVal, int watchedVal)
    : name{nameVal}, rating{ratingVal}, watched{watchedVal}
{
        std::cout << "USO IL 1) Const di MOVIE" << std::endl;
}
// Destructor
Movie::~Movie()
{
        std::cout << "USO IL 4) Dest di MOVIE" << std::endl;
}
// Copy Constructor
Movie::Movie(Movie const &source)
    : Movie(source.name, source.rating, source.watched)
{
    std::cout << "USO IL 2) CopyConst di MOVIE" << std::endl;
}
// Move Constructor
Movie::Movie(Movie &&source) noexcept
    : name{source.name}, rating{source.rating}, watched{source.watched}
{
      std::cout << "USO IL 3) Move Const di MOVIE" << std::endl;
     // Non devo cancellare nulla perchè non sto usando i puntatori
     // Ma in ogni caso usando il move constructor non richiamo il metodo constructor, guadagno una call
}