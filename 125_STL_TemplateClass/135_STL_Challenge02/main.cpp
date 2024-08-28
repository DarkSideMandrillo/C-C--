// Section 20
// Challenge 2
//  Lists

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song
{
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;

public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
        : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const
    {
        return name;
    }
    std::string get_artist() const
    {
        return artist;
    }
    int get_rating() const
    {
        return rating;
    }

    bool operator<(const Song &rhs) const
    {
        return this->name < rhs.name;
    }

    bool operator==(const Song &rhs) const
    {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s)
{
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
    return os;
}

void display_menu()
{
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song)
{

    std::cout << "Stai ascoltando: " << song.get_name() << " di " << song.get_artist();

    std::cout << std::endl;
}

void display_playlist(std::list<Song> playlist)
{
    std::cout << std::endl
              << "Ecco la lista di canzoni:" << std::endl;
    std::list<Song>::iterator it = playlist.begin();
    while (it != playlist.end())
    {
        std::cout << *it << std::endl;
        it++;
    }
    std::cout << std::endl
              << std::endl;

    std::cout << "You implement this function" << std::endl;
}

int main()
{
    std::string nameSong;
    std::string nameBand;
    int ratingSong;
    char selectionMenu{};
    std::list<Song> playlist{
        {"God's Plan", "Drake", 5},
        {"Never Be The Same", "Camila Cabello", 5},
        {"Pray For Me", "The Weekend and K. Lamar", 4},
        {"The Middle", "Zedd, Maren Morris & Grey", 5},
        {"Wait", "Maroone 5", 4},
        {"Whatever It Takes", "Imagine Dragons", 3}};

    std::list<Song>::iterator current_song = playlist.begin();

    do
    {
        play_current_song(*current_song);

        display_menu();
        std::cin.clear();
        std::cin >> selectionMenu;
        selectionMenu = std::toupper(selectionMenu);
        switch (selectionMenu)
        {
        case 'F':
            current_song = playlist.begin();
            break;
        case 'N':
            if (++current_song == std::end(playlist)) // Incremento l'iterator nell'IF prima del controllo
                current_song = playlist.begin();
            break;
        case 'P':
            if (current_song-- == std::begin(playlist)) // Decremento DOPO il controllo
                current_song = playlist.begin();
            break;
        case 'A':
            std::cout << std::endl
                      << "Inserisci il nome della canzone: ";
            std::cin >> nameSong;
            std::cout << std::endl
                      << "Inserisci il nome della band: ";
            std::cin >> nameBand;
            std::cout << std::endl
                      << "Inserisci rating della canzone: ";
            std::cin >> ratingSong;

            playlist.insert(current_song, Song{nameSong, nameBand, ratingSong});
            break;
        case 'L':
            display_playlist(playlist);
            break;
        default:
            break;
        }

    } while (selectionMenu != 'Q');

    std::cout << "To be implemented" << std::endl;

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}