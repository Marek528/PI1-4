#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>

bool containsDigit(const std::string &str)
{
    return std::any_of(str.begin(), str.end(), ::isdigit);
}

int main()
{
    std::vector<std::string> strings;
    std::string input;

    std::cout << "zadajte retazce (ukoncite prazdnym riadkom):\n";

    while (true)
    {
        std::getline(std::cin, input);
        if (input.empty())
        {
            break;
        }
        strings.push_back(input);
    }

    std::sort(strings.begin(), strings.end(), [](const std::string &a, const std::string &b)
    {
        bool a_has_digit = containsDigit(a);
        bool b_has_digit = containsDigit(b);

        if (a_has_digit != b_has_digit)
        {
            return !a_has_digit;
        }
        
        if (a.length() == b.length())
        {
            return a < b;
        } 

        return a.length() < b.length();
    });

    std::cout << "zoradene retazce:\n";
    for (const auto &str : strings)
    {
        std::cout << str << "\n";
    }

    return 0;
}