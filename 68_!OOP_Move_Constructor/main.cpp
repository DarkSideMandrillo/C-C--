/*
Il && in declaration indica il passaggio di un riferimento R-Value, passaggio che non si potrebbe fare (forse solo se lo si passa come const)
Questo perchè il numero che passo nel metodo del vettore è un oggetto che verrà copiato,
ma prima si genera
Poi al posto di copiarlo (creando una copia che chiama nuovamente il costruttore) chiamiamo il move passando per && l'oggetto r-value
l'oggetto && non è nientaltro che il valore temporaneo dell'oggetto stesso che viene generato dalla funzione, perciò gli assegno il 10 e poi chiudo


Come si può intuire non ho capito benissimo

riproiviamo
Move{30} - genera l'oggetto che chiameremo obj - esso è un r-value, non ha indirizzo di memoria, ma solo DOPO l'assegnazione sarà contenuto nel vettore
vec.push_back(obj) - è una funzione con per parametro un oggetto r-value, perciò di base dovrebbe fare il CopyConstructor
Ma il Move Constructor lo intercetta perchè ha && che richiede gli R-Value (overload del constructor)
Al richiamo di questo Move Constructor viene generato un altro oggetto this che dovrà essere inserito nel vettore dalla func chiamata (pushback).
Si prende (ruba) il valore della sorgente del campo interessato. La sorgente è l'oggetto R-Value
Si fa puntare la sorgente a nullptr, così nel delete non si va a cancellare il dato

Si evitano le copie


*/

// Move Constructor
#include <iostream>
#include <vector>

using namespace std;

class Move
{
private:
    int *data;

public:
    void set_data_value(int d) { *data = d; }
    int get_data_value() { return *data; }
    // Constructor
    Move(int d);
    // Copy Constructor
    Move(const Move &source);
    // Move Constructor
    Move(Move &&source) noexcept;
    // Destructor
    ~Move();
};
// Constructor
Move::Move(int d)
{
    data = new int;
    *data = d;
    cout << "Constructor for: " << d << endl;
}

// Copy Costructor
Move::Move(const Move &source)
    : Move{*source.data}
{
    cout << "Copy constructor  - deep copy for: " << *data << endl;
}

//!!!!!!!!!!!!!!!!!!!!  Move Constructor  !!!!!!!!!!!!!!!!!!!!!!!!
Move::Move(Move &&source) noexcept
    : data{source.data}
{                          // Inserisco nella variabile puntatore creata nel nuovo oggetto il riferimento al valore inirente all'oggetto da copiare
    source.data = nullptr; // Dopo che la copia dell'oggeto è stata
    cout << "Move constructor - moving resource: " << *data << endl;
}

Move::~Move()
{
    if (data != nullptr)
    {
        cout << "Destructor freeing data for: " << *data << endl;
    }
    else
    {
        cout << "Destructor freeing data for nullptr" << endl;
    }
    delete data;
}

// Metodo Display
void display_deep(Move s)
{
    cout << s.get_data_value() << endl;
}

int main()
{
    vector<Move> vec;

    Move a = Move{10};
    vec.push_back(a); // Non uso il Move constructor perchè in questo caso passo un L-Value
    display_deep(vec.at(0));

    vec.push_back(Move{10});

    display_deep(vec.at(0));

    vec.push_back(Move{20});
    vec.push_back(Move{30});
    vec.push_back(Move{40});
    vec.push_back(Move{50});
    vec.push_back(Move{60});
    vec.push_back(Move{70});
    vec.push_back(Move{80});

    return 0;
}
