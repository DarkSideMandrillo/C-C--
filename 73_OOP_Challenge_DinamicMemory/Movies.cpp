#include "Movies.h"
#include <vector>
#include <iostream>
// #include <algorithm> Per usare la find

Movies::Movies()
{
    // mov = new std::vector<Movies>; //ASPETTO A USARE HIPE
    std::cout << "USO IL 1) Const di !MOVIES!" << std::endl;
}

Movies::~Movies()
{
    //  delete mov;
    std::cout << "USO IL 4) Dest di !MOVIES!" << std::endl;
}
// Copy Constructor
// Non posso usare il copy constructor normale, ma devo adattarlo. Mov non lo inizializzo nel constructor
// Qua copio nel nuovo mov(vettore) creato quello che c'è in source.mov (il vettore originale)
Movies::Movies(Movies const &source)
    : mov{source.mov}
{
}

// // Move Constructor
// DI BASE NON SERVE, perchè non passerò r-value e sarebbe uguale al copy constructor
// Movies::Movies(Movies &&source) noexcept
//     : mov{source.mov} { }

void Movies::display()
{
    if (mov.empty())
        std::cout << "Non ci sono film" << std::endl;
    else
        for (size_t i{0}; i < mov.size(); i++)
            std::cout << mov.at(i).get_name() << " - " << mov.at(i).get_rating() << " - " << mov.at(i).get_watched() << std::endl;
    // for (auto var: mov){} FUNZIONA MA FA + iterazioni. Ogni volta che creo "var" chiamo una funzione che crea una copia dell'oggetto
}

bool Movies::add_movie(std::string nameVal, std::string ratingVal, int watchedVal)
{
    for (size_t i{0}; i < mov.size(); i++)
        if (mov.at(i).get_name() == nameVal)
        {
            return false; // Se trova un titolo uguale esce
        }
    mov.push_back(Movie(nameVal, ratingVal, watchedVal)); // Altrimenti aggiunge
    return true;
}

bool Movies::increment_watched(std::string nameVal)
{
    // Movie tmp = std::find(mov.begin(), mov.end(), nameVal);            // Interessante il find, ma non riesco a usarlo, devo cercare un oggetto e non una stringa
    for (size_t i{0}; i < mov.size(); i++)
        // for (auto var: mov){} NON FUNZIONA . Ogni volta che creo "var" chiamo una funzione che crea una copia dell'oggetto, quindi incremento la copia e non l'oggetto originale
        if (mov.at(i).get_name() == nameVal)
        {
            mov.at(i).increment_watched_movie();
            return 1;
        }
    return 0;
}