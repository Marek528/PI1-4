#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>

const std::string FILENAME = "people.txt";

bool isNameInFile(const std::string &name)
{
    std::ifstream file(FILENAME);
    if (!file)
    {
        return false;
    }

    std::string line, fileName;
    int fileAge;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        if (iss >> fileName >> fileAge)
        {
            if (fileName == name)
            {
                return true;
            }
        }
    }
    return false;
}

void addPerson()
{
    std::ofstream file(FILENAME, std::ios::app);
    if (!file)
    {
        std::cerr << "chyba pri otvarani suboru na zapis!" << std::endl;
        return;
    }

    std::string name;
    int age;

    while (true)
    {
        std::cout << "zadajte meno: ";
        std::getline(std::cin, name);

        if (isNameInFile(name))
        {
            std::cerr << "meno uz existuje! zadajte prosim ine meno" << std::endl;
        }
        else
        {
            break;
        }
    }

    while (true)
    {
        std::cout << "zadajte vek: ";
        std::cin >> age;
        if (std::cin.fail() || age <= 0)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "neplatny vstup! zadajte prosim cislo vacsie alebo rovne ako 0" << std::endl;
        }
        else
        {
            std::cin.ignore();
            break;
        }
    }

    file << name << " " << age << "\n";
    file.close();

    std::cout << "osoba '" << name << "' s vekom " << age << " bola pridana!" << std::endl;
}

void searchPerson()
{
    std::ifstream file(FILENAME);
    if (!file)
    {
        std::cerr << "chyba pri otvarani suboru na citanie!" << std::endl;
        return;
    }

    std::string name, line;
    std::cout << "zadajte meno na vyhladanie: ";
    std::getline(std::cin, name);

    bool found = false;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string fileName;
        int fileAge;

        if (!(iss >> fileName >> fileAge))
        {
            std::cerr << "nespravny format udajov v subore!" << std::endl;
            continue;
        }

        if (fileName == name)
        {
            std::cout << "najdene: " << fileName << " - vek: " << fileAge << std::endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        std::cout << "osoba s menom '" << name << "' nebola najdena" << std::endl;
    }

    file.close();
}

int main()
{
    int choice = -1;
    while (choice != 0)
    {
        std::cout << "1 - pridat osobu\n2 - vyhladat osobu\n0 - koniec\n>> ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 0)
        {
            break;
        }
        else if (choice == 1)
        {
            addPerson();
        }
        else if (choice == 2)
        {
            searchPerson();
        }
        else
        {
            std::cerr << "neplatna volba!" << std::endl;
        }
    }
    
    return 0;
}