#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

void findSubsets(const std::vector<int> &numbers, int target, int index, int currentSum, int &count)
{
    if (currentSum == target)
    {
        count++;
        return;
    }

    if (currentSum > target || index >= numbers.size())
    {
        return;
    }

    findSubsets(numbers, target, index + 1, currentSum + numbers[index], count);
    findSubsets(numbers, target, index + 1, currentSum, count);
}

std::vector<int> parseInputFile(const std::string &filename)
{
    std::vector<int> numbers;
    std::ifstream inputFile(filename);

    if (!inputFile.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return numbers;
    }

    std::string line;
    if (std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        int num;
        while (iss >> num)
        {
            if (num > 0)
            {
                numbers.push_back(num);
            }
            else
            {
                std::cerr << "Warning: Ignoring non-positive number: " << num << std::endl;
            }
        }
    }

    inputFile.close();
    return numbers;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <input_file> <target_sum>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    int targetSum;

    try
    {
        targetSum = std::stoi(argv[2]);
        if (targetSum <= 0)
        {
            std::cerr << "Error: Target sum must be a positive integer" << std::endl;
            return 1;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: Invalid target sum" << std::endl;
        return 1;
    }

    std::vector<int> numbers = parseInputFile(filename);

    if (numbers.empty())
    {
        std::cerr << "Error: No valid numbers found in the input file" << std::endl;
        return 1;
    }

    int count = 0;
    findSubsets(numbers, targetSum, 0, 0, count);
    std::cout << count;

    return 0;
}