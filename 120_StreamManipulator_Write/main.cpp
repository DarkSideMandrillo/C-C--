#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ofstream outFile{"./output.txt", std::ios::app};
    if (!outFile)
    {
        std::cerr << "Error creating file" << std::endl;
        std::exit(1);
    }
    std::string line;
    std::cout << "Enter something to write to the text file ";
    std::getline(std::cin, line);
    outFile << line << std::endl;

    outFile.close();
}