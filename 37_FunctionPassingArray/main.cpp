#include <iostream>

using namespace std;

/*IMPORTANTE: Gli array sono solo puntatori a memoria, perciò anche un byVal modifica l'array*/

void print_array(const int arr[], size_t size);
void set_array(int arr[], size_t size, int value);

void print_array(const int arr[], size_t size)
{
    for (size_t i{0}; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Set each element array to value
void set_array(int arr[], size_t size, int value)
{
    for (size_t i{0}; i < size; i++)
        arr[i] = value;
}

int main()
{
    int myScore[]{100, 98, 90, 86, 84};

    print_array(myScore, 5);
    set_array(myScore, 5, 80);
    print_array(myScore, 5);
}