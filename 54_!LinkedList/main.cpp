/*
DA CAPIRE
-Se hai -> stai lavorando da un puntatore verso un oggetto, se hai il . stai lavorando sull'oggetto
-head è una variabile puntatore che punta ad un altra variabile puntatore entrambe sullo stach
-Se passo l'indirizzo di memoria di head :&head (pass ByRef), per avere l'indirizzo del nodo che contiene devo usare *head,
per avere l'indirizzo dela struttura nell'hipe devo fare **head
-Quando passo &head la funzione che inizializza la variabile deve avere struct node **p (oppure **head) [vedi funzione insert_head]
-Quando passo solo il valore di head (byValue) sto a tutti gli effetti passando solo una variabile pointer [vedi funzione print]

*/

#include <iostream>

using namespace std;

void print_list(struct node *p);
void list_insert_head(struct node **head, int newData);
bool list_search(struct node *p, int nodeFind);
void list_delete(struct node **head, int key);

/*-----------------------CREO LA STRUTTURA --------------------------*/
struct node
{
    int data{};
    struct node *next;
};

/*---------------------MAIN()--------------------------------*/
int main()
{
    struct node *head{nullptr};
    struct node *node1{nullptr};
    struct node *node2{nullptr};
    struct node *node3{nullptr};

    // Alloco la memoria
    node1 = new struct node;
    node2 = new struct node;
    node3 = new struct node;

    // Assegno i valori
    node1->data = 17;
    node2->data = 32;
    node3->data = 54;

    // Collego i nodi
    node1->next = node2;
    node2->next = node3;
    node3->next = nullptr;

    // Salvo l'indirizzo del primo nodo come testa
    head = node1;

    print_list(head); // Stampo lista

    // INSERISCO NUOVA TESTA DAL VAORE { , N}
    list_insert_head(&head, 99); // Passo ByRef il puntatore alla testa
    print_list(head);            // Stampo lista

    // RICERCA di {N}
    int nodeToSearch{98};
    if (list_search(head, nodeToSearch))
        printf("\nNodo %d trovato!\n", nodeToSearch);
    else
        printf("\nNodo %d NON trovato!\n", nodeToSearch);

    // ELIMINAZIONE di { ,N}
    list_delete(&head, 99);
    print_list(head);
}

/*----------------------------STAMPA------------------------*/
void print_list(struct node *p)
{
    while (p != nullptr)
    {
        cout << p->data << endl;
        p = p->next;
    }
    cout << endl;
}

/*--------------------------RICERCA (restituisce T|F)-------------*/
bool list_search(struct node *p, int nodeFind)
{
    while (p != nullptr)
    {
        if (p->data == nodeFind)
            return 1;
        p = p->next;
    }
    return 0;
}

/*-----------------------INSERISCI NUOVA TESTA-------------------------*/
void list_insert_head(struct node **head, int newData) // Head è un puntatore che punta a un altro puntatore che punta a una struttura
{
    // Inserisco un nuovo nodo in testa
    struct node *newNode = new struct node;
    if (newNode == NULL)
    { // Se ci fosse un'errore non so se in effetti la new restituisce NULL, la malloc dovrebbe farlo
        printf("Errore nell'allocazione di memoria!");
        exit(0);
    }
    // Inserisco i dati nel nuovo nodo
    newNode->data = newData;
    // Inserisco nel nuovo nodo il puntatore al nodo vecchio in testa
    newNode->next = (*head);
    // Cambio la testa della lista
    (*head) = newNode; // (*head) perchè voglio il puntatore del nodo e non il puntatore del puntatore del nodo
}

/*---------------------------ELIMINA IL VAORE PASSATO---------------------------------*/
void list_delete(struct node **head, int key) // Cancella il primo nodo che trova con il valore di data passato
{
    struct node *tmp = *head;
    struct node *prev{nullptr};

    // Se Key==testa elimino la testa
    if (tmp != nullptr && tmp->data == key)
    {
        *head = tmp->next; // Cambio la testa della lista
        free(tmp);         // Sono nell'hipe, perciò anche se sono in funzione sto modificando la memoria
        return;
    }

    // Scorro la lista fino a che non trovo il valore cercato o arrivo alla fine
    while (tmp != nullptr && tmp->data != key)
    {
        prev = tmp; // Salvo il valore precedente così so come richiudere il link
        tmp = tmp->next;
    }

    // Esco dalla funzione se non ho trovato nulla
    if (tmp == nullptr)
        return;
    // Sposto il next del nodo precedente e cancello il nodo tmp che ha il valore di data uguale alla ricerca key
    prev->next = tmp->next;
    free(tmp);
    return;
}

/*
Ricerca nodo
Come implementare se passassi come riferimento

Main(){
if (list_search(&head, nodeToSearch))}

bool list_search(struct node **p, int nodeFind)
{
    struct node *corrente =*p;
    while (corrente != nullptr)
    {
        if (corrente->data == nodeFind)
            return 1;
        corrente = corrente->next;
    }
    return 0;
}
*/