// Section 19
// Copy File 1
// File copy using getline
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main()
{
    std::ifstream inFile{"./romeoandjuliet"};
    std::ofstream outFile{"./romeoandjuliet_out"};
    int numLine{0};
    if (!inFile)
    {
        std::cerr << "Error opening input file" << std::endl;
        return 1;
    }
    if (!outFile)
    {
        std::cerr << "Error opening output file" << std::endl;
        return 1;
    }

    std::string line{};
    while (std::getline(inFile, line))
    {
        numLine++;
        outFile << std::setw(7) << std::left << numLine
                << line << std::endl;
    }

    std::cout << "File copied" << std::endl;
    inFile.close();
    outFile.close();
    return 0;
}
