#include <iostream>
#include <iomanip>
#include <fstream>

int main()
{

    std::ifstream in_file;

    in_file.open("./Poem.txt");
    if (!in_file)
    {
        std::cerr << "Problem opening file" << std::endl;
        std::exit(1);
    }
    char c;
    while (in_file.get(c))
    {
        std::cout << c;
    }

    in_file.close();
}

//  while (!in_file.eof())