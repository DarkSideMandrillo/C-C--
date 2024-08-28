
#include <iostream>

inline int add_numbers(int a, int b)
{
    return a + b;
}

int main()
{
    int result{};
    result = add_numbers(100, 200);
    std::cout << result << std::endl;
}

/*
Le funzioni inline usano il codice assembly per non usare lo stack(?)
I compilatori + evoluti riconoscono le funzioni semplici e le gestiscono automaticamente inline
*/