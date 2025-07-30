#include <iostream>
#include <map>
#include <stdexcept>
#include <limits>
#include <functional>

int main()
{
    auto add = [](double a, double b) { return a + b; };
    auto sub = [](double a, double b) { return a - b; };
    auto mult = [](double a, double b) { return a * b; };
    auto div = [](double a, double b)
    {
        if (b == 0)
        {
            throw std::runtime_error("delenie nulou nie je mozne!");
        }
        return a / b;
    };

    std::map<char, std::function<double(double, double)>> operations = {
        {'+', add},
        {'-', sub},
        {'*', mult},
        {'/', div}};

    char input = 'y';
    while (input == 'y')
    {
        double num1, num2;
        char operation;

        std::cout << "zadajte prve cislo: ";
        while (!(std::cin >> num1))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "neplatny vstup; prosim zadajte cislo: ";
        }

        std::cout << "zadajte druhe cislo: ";
        while (!(std::cin >> num2))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "neplatny vstup; prosim zadajte cislo: ";
        }

        std::cout << "zadajte operaciu (+, -, *, /): ";
        while (!(std::cin >> operation) || operations.find(operation) == operations.end())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "neplatna operacia; zadajte jednu z moznosti (+, -, *, /): ";
        }

        try
        {
            double vysledok = operations[operation](num1, num2);
            std::cout << num1 << " " << operation << " " << num2 << " = " << vysledok << std::endl;
        }
        catch (const std::runtime_error &e)
        {
            std::cout << "error: " << e.what() << std::endl;
        }
        catch (...)
        {
            std::cout << "nastala neocakavana chyba!" << std::endl;
        }

        std::cout << "\nchcete pokracovat? (y/n): ";
        std::cin >> input;
        input = tolower(input);
    }

    return 0;
}