#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
#include <string>

double calcAverage(const std::vector<int> &grades)
{
    return std::accumulate(grades.begin(), grades.end(), 0.0) / grades.size();
}

double calcMedian(std::vector<int> grades)
{
    std::sort(grades.begin(), grades.end());
    size_t size = grades.size();

    if (size % 2 == 0)
    {
        return (grades[size / 2 - 1] + grades[size / 2]) / 2.0;
    }
    else
    {
        return grades[size / 2];
    }
}

bool isValidGrade(const std::string &input, int &grade)
{
    if (input.empty() || (input.length() == 1 && input[0] == '-'))
    {
        return false;
    }

    for (char c : input)
    {
        if (!isdigit(c) && c != '-')
        {
            return false;
        }
    }

    try
    {
        grade = std::stoi(input);
        return true;
    }
    catch (...)
    {
        return false;
    }
}

int main()
{
    std::map<std::string, std::vector<int>> students;
    int choice = 0;

    while (choice != 4)
    {
        std::cout << "1 - pridat studenta a znamky\n2 - odstranit studenta\n3 - zobrazit statistiky\n0 - koniec\n>> ";
        std::cin >> choice;

        if (choice == 1)
        {
            std::string name;
            std::cout << "zadajte meno studenta: ";
            std::cin >> name;

            std::vector<int> grades;
            std::string input;
            std::cout << "zadajte znamky (ukoncite -1): ";

            while (std::cin >> input)
            {
                int grade;
                if (!isValidGrade(input, grade))
                {
                    std::cout << "neplatny vstup! zadajte cislo\n";
                    continue;
                }

                if (grade == -1)
                {
                    break;
                }

                if (grade >= 1 && grade <= 5)
                {
                    grades.push_back(grade);
                }
                else
                {
                    std::cout << "neplatna znamka! zadajte hodnotu 1-5\n";
                }
            }

            if (!grades.empty())
            {
                students[name] = grades;
            }
            else
            {
                std::cout << "student musi mat aspon jednu znamku!\n";
            }
        }

        else if (choice == 2)
        {
            std::string name;
            std::cout << "zadajte meno studenta na odstranenie: ";
            std::cin >> name;

            if (students.erase(name))
            {
                std::cout << "student '" << name << "' bol odstraneny\n";
            }
            else
            {
                std::cout << "student s menom '" << name << "' neexistuje\n";
            }
        }
        else if (choice == 3)
        {
            if (students.empty())
            {
                std::cout << "ziadni studenti nie su zadani\n";
                continue;
            }

            for (const auto &[name, grades] : students)
            {
                std::cout << "\nstudent: " << name << "\n";
                std::cout << "znamky: ";
                for (int g : grades)
                {
                    std::cout << g << " ";
                }
                std::cout << "\n";

                if (grades.size() < 3)
                {
                    std::cout << "nedostatok dat pre presne statistiky!\n";
                    continue;
                }

                double avg = calcAverage(grades);
                double median = calcMedian(grades);
                auto [min, max] = std::minmax_element(grades.begin(), grades.end());

                std::cout << "priemer: " << avg << "\n";
                std::cout << "median: " << median << "\n";
                std::cout << "najlepsia znamka: " << *min << "\n";
                std::cout << "najhorsia znamka: " << *max << "\n";
            }
        }
        else if (choice == 0)
        {
            break;
        }
        else
        {
            std::cout << "neplatna volba! Skuste znova.\n";
        }
    }

    return 0;
}