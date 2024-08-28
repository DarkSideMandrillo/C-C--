// Section 19
// Challenge 3
// Word counter
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    std::string ricerca;
    std::fstream inFile;
    std::string word;
    int countWord{0};
    int countTotal{0};

    inFile.open("./romeoandjuliet.txt");
    if (!inFile)
    {
        std::cerr << "Problem to open a file" << std::endl;
        std::exit(1);
    }
    // ************************

    cout << "Enter the substring to search for: ";
    cin >> ricerca;
    cout << endl;

    while (inFile >> word)
    {
        countTotal++;
        size_t k{0};

        if (ricerca.length() <= word.length())
        {
            for (size_t i = 0; i < word.length(); i++)
            {
                if (std::toupper(ricerca.at(k)) == std::toupper(word.at(i)))
                    k++;
                else
                    k = 0;
                if (k == ricerca.length())
                {
                    i = word.length();
                    countWord++;
                }
            }
        }
    }

    std::cout << countTotal << " words were searched..." << std::endl;
    std::cout << "The substring " << ricerca << " was found " << countWord << " times" << std::endl;

    cout << endl;
    cout << endl;

    inFile.close();
    return 0;
}
