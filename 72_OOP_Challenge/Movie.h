#pragma once

#include <string>

class Movie
{
private:
    std::string name;
    std::string rating;
    int watched;

public:
    // All constructor and Destructor
    Movie(std::string nameVal, std::string ratingVal, int watchedVal = 1);
    Movie(Movie const &source);
    Movie(Movie &&source) noexcept;
    ~Movie();
    // Metods
    std::string get_name() { return name; } const
    std::string get_rating() { return rating; } const
    int get_watched() { return watched; } const
    void increment_watched_movie() { ++watched;}; // Qua non passo nulla
};
