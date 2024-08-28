#include <iostream>
#include "Movies.h"

// Incremento il numero di volte in cui un film è stato guardato

void increment_watched(Movies &movies, std::string name)
{
    if (movies.increment_watched(name))
        std::cout << name << " watch incremented" << std::endl;
    else
        std::cout << name << " not found" << std::endl;
}

// Aggiungo un film
void add_movie(Movies &movies, std::string name, std::string rating, int watched)
{
    if (movies.add_movie(name, rating, watched))
        std::cout << name << " added" << std::endl;
    else
        std::cout << name << " already exists" << std::endl;
}

int main()
{

    Movies my_movies;
    std::cout << "\n--------- 1°Display ------------" << std::endl;
    my_movies.display();

    std::cout << "\n--------- Aggiunta 'Star Wars' ------------" << std::endl;
    add_movie(my_movies, "Star Wars", "PG", 5); // OK
    std::cout << "\n--------- Aggiunta ' Cinderella' ------------" << std::endl;
    add_movie(my_movies, "Cinderella", "PG", 7); // OK
    std::cout << "\n--------- 2°Display ------------" << std::endl;
    my_movies.display();
    std::cout << "\n--------- Incremento 'Cinderella' ------------" << std::endl;
    increment_watched(my_movies, "Cinderella");
    std::cout << "\n--------- 3°Display ------------" << std::endl;
    my_movies.display(); // Big, Star Wars, Cinderella

    add_movie(my_movies, "Cinderella", "PG", 7); // Already exists
    add_movie(my_movies, "Ice Age", "PG", 12);   // OK

    my_movies.display(); // Big, Star Wars, Cinderella, Ice Age

    increment_watched(my_movies, "Big");     // OK
    increment_watched(my_movies, "Ice Age"); // OK
    std::cout << "\n--------- 4°Display ------------" << std::endl;
    my_movies.display(); // Big and Ice Age watched count incremented by 1

    increment_watched(my_movies, "XXX"); // XXX not found

    return 0;
}