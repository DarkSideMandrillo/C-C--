#include <iostream>
#include <vector>
#include <string>

using namespace std;

int *largest_int(int *a, int *b)
{
    if (*a < *b)
        return b;
    else
        return a;
}

int *create_array(size_t size, int intitValue = 0)
{
    int *newStorage{new int[size]};
    for (size_t i{0}; i < size; i++)
        *(newStorage + 1) = intitValue;
    return newStorage;
}

int *create_array_prof(size_t size, int init_value = 0)
{
    int *new_storage{nullptr};
    new_storage = new int[size];
    for (size_t i{0}; i < size; ++i)
        *(new_storage + i) = init_value;
    return new_storage;
}

void display(const int *const array, size_t size)
{
    for (size_t i{0}; i < size; ++i)
        cout << array[i] << " ";
    cout << endl;
}

int main()
{
    int a{100}, b{200};
    int *largestPtr{largest_int(&a, &b)};
    cout << *largestPtr << endl;

    int *myArray{create_array(100, 5)};

    delete[] myArray;
//------------------- del prof --------------
    int *my_array{nullptr};
    size_t size;
    int init_value{};

    cout << "\nHow many integers would you like to allocate? ";
    cin >> size;
    cout << "What value would you like them initialized to? ";
    cin >> init_value;

    my_array = create_array_prof(size, init_value);
    cout << "\n--------------------------------------" << endl;

    display(my_array, size);
    delete[] my_array;
    return 0;
}
