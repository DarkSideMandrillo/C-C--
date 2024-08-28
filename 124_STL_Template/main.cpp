#include <iostream>
#include <string>

template <typename T>
T min(T a, T b) // Se uso integer T diventa di type integer, altrimenti cambia. Può creare problemi se utilizzo degli operatori non impostati per il tipo di dato selezionato (es il '<' per due oggetti)
{
    return (a < b) ? a : b;
}

template <typename T1, typename T2> // Avendo 2 type potrebbero esere diversi
void func(T1 a, T2 b)
{
    std::cout << a << " " << b << std::endl;
}

struct Person
{
    std::string name;
    int age;
    bool operator<(const Person &rhs) const // Override. Ridorda this è l'elemento a sx rhs è l'elemento di destra passato byRef
    {
        return this->age < rhs.age;
    }
};
std::ostream &operator<<(std::ostream &os, const Person &p)
{
    os << p.name << " " << p.age;
    return os;
}

template <typename T>
void my_swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    Person p1{"Curly", 50};
    Person p2{"Moe", 30};

    Person p3 = min(p1, p2); // Devo fare overryde del simbolo "<" nella struttura perchè possa funzionare
    std::cout << p3.name << " Is younger" << std::endl;

    func(p1, p2);

    std::cout << min<int>(2, 3) << std::endl; // Dichiaro che typename T dovrà essere INT
    std::cout << min(2, 3) << std::endl;
    std::cout << min('A', 'B') << std::endl; // T diventa un char
    std::cout << min(12.5, 9.2) << std::endl;
    std::cout << min(5 + 2 * 2, 7 + 40) << std::endl; // Una macro creerebbe problemi
    std::cout << std::endl;
    //----------------------------------------------------//

    func<int, int>(10, 200);
    func(10, 20);
    func<char, double>('A', 12.4);
    func(1000, "testing");
    func(2000, std::string{"Frank"});
    std::cout << std::endl;

    int x{100};
    int u{200};
    my_swap(x, u); // funziona con qualsiasi tipo
    std::cout << x << ", " << u << std::endl;
}