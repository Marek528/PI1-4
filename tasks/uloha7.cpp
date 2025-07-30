#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>
#include <limits>

template <class T>
class Stack
{
private:
    std::stack<T> data;

public:
    void push(const T &value)
    {
        data.push(value);
    }

    void pop()
    {
        if (data.empty())
        {
            throw std::out_of_range("chyba: zasobnik je prazdny!");
        }
        data.pop();
    }

    T top() const
    {
        if (data.empty())
        {
            throw std::out_of_range("chyba: zasobnik je prazdny!");
        }
        return data.top();
    }

    bool empty() const
    {
        return data.empty();
    }

    void printStack() const
    {
        std::stack<T> temp = data;
        std::cout << "obsah zasobnika (vrchol dolu): ";
        while (!temp.empty())
        {
            std::cout << temp.top() << " ";
            temp.pop();
        }
        std::cout << "\n";
    }
};

template <typename T>
bool getValidInput(T &value)
{
    if (std::cin >> value)
    {
        return true;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "neplatny vstup pre tento datovy typ!\n";
    return false;
}

template <>
bool getValidInput<int>(int &value)
{
    double temp;
    if (std::cin >> temp)
    {
        if (temp == static_cast<int>(temp))
        {
            value = static_cast<int>(temp);
            return true;
        }
        std::cout << "neplatny vstup: cislo musi byt cele!\n";
        return false;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "neplatny vstup pre tento datovy typ!\n";
    return false;
}

template <typename T>
void stackOperations()
{
    Stack<T> stack;
    T value;
    int choice;

    while (true)
    {
        std::cout << "\n1 - push\n2 - pop\n3 - top\n4 - empty\n5 - vypis\n0 - koniec\n>> ";
        if (!getValidInput(choice))
        {
            continue;
        }

        try
        {
            switch (choice)
            {
                case 1:
                    std::cout << "zadajte hodnotu: ";
                    if (getValidInput(value))
                    {
                        stack.push(value);
                    }
                    break;
                case 2:
                    stack.pop();
                    break;
                case 3:
                    std::cout << "vrchol zasobnika: " << stack.top() << "\n";
                    break;
                case 4:
                    std::cout << (stack.empty() ? "zasobnik je prazdny\n" : "zasobnik nie je prazdny\n");
                    break;
                case 5:
                    stack.printStack();
                    break;
                case 0:
                    return;
                default:
                    std::cout << "neplatna volba!\n";
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

int main()
{
    int choice;
    std::cout << "vyberte typ dat:\n1 - int\n2 - double\n3 - string\n0 - koniec\n>> ";
    if (!getValidInput(choice))
    {
        return 1;
    }

    switch (choice)
    {
        case 1:
            stackOperations<int>();
            break;
        case 2:
            stackOperations<double>();
            break;
        case 3:
            stackOperations<std::string>();
            break;
        case 0:
            break;
        default:
            std::cout << "neplatna volba!\n";
    }

    return 0;
}