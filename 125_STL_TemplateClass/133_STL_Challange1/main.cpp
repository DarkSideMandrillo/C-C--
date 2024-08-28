// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

bool is_palindrome(const std::string &s)
{
    std::deque<char> d;
    size_t size{0};
    for (auto c : s)
    {
        if (std::isalpha(c))
            d.push_back(std::toupper(c));
    }
    size = d.size();
    for (size_t i = 0; i < (size / 2 + 1); i++)
    {
        if (d.at(i) != d.at(size - 1 - i))
            return 0;
    }
    return 1;
}

bool is_palindrome2(const std::string &s) // Soluzione del prof
{
    std::deque<char> d;
    for (auto c : s)
    {
        if (std::isalpha(c))
            d.push_back(std::toupper(c));
    }
    char c1{};
    char c2{};
    while (d.size() > 1)
    {
        c1 = d.front();
        c2 = d.back();
        d.pop_back();
        d.pop_front();
        if (c1 != c2)
            return false;
    }
    return 1;
}

int main()
{
    std::vector<std::string> test_strings{"a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
                                          "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
                                          "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome"};

    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result"
              << "String" << std::endl;
    for (const auto &s : test_strings)
    {
        std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}