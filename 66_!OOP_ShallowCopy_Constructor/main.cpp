/*
Una copia superficiale può portare enormi problemi con i puntatori grezzi usati per inizializzare memoria in hipe
Se viene fatta una copia di quell'oggetto (per esempio chiamando una func ByValue),
chiamo il copy constructor che se impostato come sotto, cioè cerca di assegnare a data il valore copiato creo un nuovo *p che chiamo *pCpy
*p oggetto originale e *pCpy oggetto copiato punteranno allo stesso blocco di memoria.
Quando esco dalla func chiamo il distruttore che fa un delete di *pCpy, quindi liberando la memoria
*p esiste ancora, ma l'hipe non ha più la memoria riservata
A fine programma viene cancellato *p, questo crea certamente un errore perchè si cerca di cancellare 2 volte la stessa porzione di memoria
*/

#include <iostream>

using namespace std;

class Shallow
{
private:
    int *data;

public:
    void set_data_value(int d) { *data = d; }
    int get_data_value() { return *data; }
    // Constructor
    Shallow(int d);
    // Copy Constructor
    Shallow(const Shallow &source);
    // Destructor
    ~Shallow();
};

// Costructor
Shallow::Shallow(int d)
{
    data = new int;
    *data = d;
}
// Copy Costructor
Shallow::Shallow(const Shallow &source)
    : data{source.data} // ***ATTENZIONE*** NON STO USANDO IL DELEGATING CONSTRUCTOR, MA STO ASSEGNANDO DIRETTAMENTE A DATA IL VALORE
{
    cout << "Copy Constructor - Shallow copy" << endl;
}

// Destructor
Shallow::~Shallow()
{
    delete data;
    cout << "Destructor freeing data" << endl;
}

void display_shallow(Shallow s)
{
    cout << s.get_data_value() << endl;
}

int main()
{

    Shallow obj1{100};
    display_shallow(obj1);

    Shallow obj2{obj1};
    obj2.set_data_value(1000);

    return 0;
}
/* SPIEGAZIONE

creo obj1 {data= 0x00100} 0x00100 punta a hipe e assegno 100
chiamo funzione display_shallow passando obj1 ByValue
Creo una copia passando per Copy Constructor
il Copy Constructor passa alla variabile data il valore 0x00100  che è la copia
Ora ho un nuovo puntatore, ma l'area dello hipe che punta (nonostante abbia fatto nuovamente il new) è sempre la stessa
Torno allo stack e chiamo il Destructor che dealloca la memoria. Ora 0x00100 non è + allocata. PROBLEMA



*/
