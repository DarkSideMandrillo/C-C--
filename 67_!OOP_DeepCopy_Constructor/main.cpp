/*
Identico a prima, semplicemente qua nel CopyConstructor richiamo il costruttore passandogli ciò che vuole
Questo lo fa creare un nuovo spazio nell'hipe, copiando la deferenziazione del primo spazio
*/

#include <iostream>

using namespace std;

class Deep
{
private:
    int *data;

public:
    void set_data_value(int d) { *data = d; }
    int get_data_value() { return *data; }
    // Constructor
    Deep(int d);
    // Copy Constructor
    Deep(const Deep &source);
    // Destructor
    ~Deep();
};

// Costructor
Deep::Deep(int d)
{
    data = new int;
    *data = d;
}
// Copy Costructor
Deep::Deep(const Deep &source)
    : Deep{*source.data} // ***ATTENZIONE*** ORA STO RICHIAMANDO IL COSTRUTTORE PASSANDOGLI IL VALORE CONTENUTO DAL PUNTATORE, CIOE QUELLO CHE PER IL COSTRUTTORE è d
{
    cout << "Copy Constructor - Deep copy" << endl;
}

// Destructor
Deep::~Deep()
{
    delete data;
    cout << "Destructor freeing data" << endl;
}
// Metodo Display
void display_deep(Deep s)
{
    cout << s.get_data_value() << endl;
}

int main()
{

    Deep obj1{100};
    display_deep(obj1);

    Deep obj2{obj1};
    obj2.set_data_value(1000);

    return 0;
}
/* SPIEGAZIONE

creo obj1 {data= 0x00100} 0x00100 punta a hipe e assegno 100
chiamo funzione display_shallow passando obj1 ByValue
Creo una copia passando per Copy Constructor
il Copy Constructor chiama Per il Constructor passandogli la deferenziazione di obj1.data che è 100
Il Constructor crea un nuovo puntatore facendo il new che punta a un indirizzo diverso 0x00200
Quando torno allo stack faccio il free della memoria inerente al nuovo puntatore
Nessun problema



*/
