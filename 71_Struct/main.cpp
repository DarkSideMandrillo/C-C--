// Member of the struct public as default
// Member of the class private as default
// Questa è l'unica differenza
// Usare struct quando si hanno dati passivi e non serve creare metidi

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