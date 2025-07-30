#include <iostream>
#include <vector>
#include <algorithm>

constexpr int fibonacci(int n)
{
    return (n <= 1) ? n : fibonacci(n - 1) + fibonacci(n - 2);
}

std::vector<int> generateFibonacci(int n)
{
    if (n <= 0)
    {
        return {};
    }

    std::vector<int> fib(n);

    fib[0] = fibonacci(0);
    if (n > 1)
    {
        fib[1] = fibonacci(1);
    }

    std::transform(fib.begin(), fib.end() - 2, fib.begin() + 1, fib.begin() + 2, [](int a, int b) { return a + b; });

    return fib;
}

int main()
{
    int n;
    std::cout << "zadajte pocet Fibonacciho cisel: ";
    std::cin >> n;

    std::vector<int> fibonacciNumbers = generateFibonacci(n);

    std::cout << "parne Fibonacciho cisla: ";
    for (int num : fibonacciNumbers)
    {
        if (num % 2 == 0)
        {
            std::cout << num << " ";
        }
    }

    std::cout << std::endl;
    return 0;
}