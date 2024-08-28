#include <iostream>
#include <iomanip>
#include <fstream>

int main()
{

    std::ifstream in_file;
    std::string line;
    int num;
    double total;
    in_file.open("test.txt");
    if (!in_file)
    {
        std::cerr << "Problem opening file" << std::endl;
        std::exit(1);
    }

    while (in_file >> line >> num >> total)
    {
        std::cout << std::setw(10) << std::left << line
                  << std::setw(10) << std::left << num
                  << std::setw(10) << std::left << total
                  << std::endl;
    }
    in_file.close();
}

//  while (!in_file.eof())