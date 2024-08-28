/*
ITERATOR: Gli Iterator sono delle variabili che funzionano come PUNTATORI per i container
(I container sono le strutture di contenimento dati della STL [vector,map,ecc.])

begin() = Punta al primo oggetto dentro
end()= punta al successivo oggetto dopo l'ultimo (essenzialmente punta fuori)
*/

/*
std::vector<int> vec{1,2,3};

for (auto it = vec.begin();it != vec.end(); it++) //Scorro il vettore usando l'Iterator che dichiaro dentro il FOR
    { std::cout<<*it<< " ";}
    /// 1 2 3
*/

/*
std::vector<int> vec {1,2,3};
std::vector<int>::reverse_iterator it = vec.begin();
while (it != vec.end()){
    std::cout<<*it<<" ";
    it++;
}
*/
// In questo caso non uso AUTO perchè creo un reverse_iterator che
// automaticamente va al contrario. Funziona UGUALE a il classico iterator e lo scrivo come se fosse crescente

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

// Display a vector of integer use a range base loop
void display(const std::vector<int> &vec)
{
    std::cout << "[ ";
    for (auto const &i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << " ]" << std::endl;
}

void test1() // TEST 1
{
    std::cout << "\n=====================================" << std::endl;
    std::vector<int> num1{1, 2, 3, 4, 5};
    std::vector<int>::iterator it = num1.begin(); // auto it=num1.begin();
    std::cout << *it << std::endl;                // point to 1

    it++; // point to 2
    std::cout << *it << std::endl;

    it += 2; // point to 4
    std::cout << *it << std::endl;

    it -= 2; // point to 2
    std::cout << *it << std::endl;

    it = num1.end() - 1; // point to 5 (attenzione che end punta a il successivo all'ultimo)
    std::cout << *it << std::endl;
}

void test2() // TEST 2
{
    std::cout << "\n=====================================" << std::endl;
    std::vector<int> num1{1, 2, 3, 4, 5};
    auto it = num1.begin();

    while (it != num1.end())
    {
        std::cout << *it << std::endl; // Incrementa iterator
        it++;
    }

    it = num1.begin(); // Attenzione il "puntatore" deve tornare all'inizio

    while (it != num1.end())
    {
        *it = 0;
        it++;
    }
    display(num1);
}

void test3() // TEST 3
{
    std::cout << "\n=====================================" << std::endl;
    std::vector<int> num1{1, 2, 3, 4, 5};

    std::vector<int>::const_iterator it1 = num1.begin(); // auto it1=num.cbegin();

    while (it1 != num1.end())
    {
        std::cout << *it1 << std::endl; // Incrementa iterator
        it1++;
    }

    it1 = num1.begin();

    while (it1 != num1.end())
    {
        //  *it1 = 0; // compile error - read only
        it1++;
    }
    display(num1);
}

void test4() // TEST 4
{
    std::cout << "\n=====================================" << std::endl;
    // Reverse iterator on vector
    std::vector<int> vec{1, 2, 3, 4};
    auto it1 = vec.rbegin();

    while (it1 != vec.rend())
    {
        std::cout << *it1 << std::endl;
        it1++; // Incrementa iterator (che in realtà lo sta decrementando)
    }
    // const reverse iterator over list
    std::list<std::string> name{"Larry", "Moe", "Curly"};
    auto it2 = name.crbegin(); // Punta a Curly
    std::cout << *it2 << std::endl;
    it2++; // Punta a Moe
    std::cout << *it2 << std::endl;
    // name.crend() // Punterebbe fuori dalla lista prima dell'inizio

    // iterator over map
    std::map<std::string, std::string> favorites{
        {"Frank", "C++"},
        {"Bill", "Java"},
        {"James", "Haskell"}};
    auto it3 = favorites.begin();
    while (it3 != favorites.end())
    {
        std::cout << it3->first << " : " << it3->second << std::endl;
        it3++;
    }
}

void test5() // TEST 5
{
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto start = vec.begin() + 2; // Parte dalla terza posizione e non dalla prima
    auto finish = vec.end() - 3; // Punta alla posizione dell'8

    while (start != finish)
    {
        std::cout << *start << std::endl;
        start++;
    }
}

int main()
{
    // test1();
    // test2();
    // test3();
    // test4();
    test5();
}