#include <iostream>
#include <vector>

std::vector<int> mergeSortedArrs(const std::vector<int>& v1, const std::vector<int>& v2)
{
    std::vector<int> result;
    result.reserve(v1.size() + v2.size());
    int i = 0, j = 0, k = 0;

    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] <= v2[j])
        {
            result.push_back(v1[i++]);
        }
        else
        {
            result.push_back(v2[j++]);
        }
    }

    while (i < v1.size())
    {
        result.push_back(v1[i++]);
    }

    while (j < v2.size())
    {
        result.push_back(v2[j++]);
    }

    return result;
}

int main()
{
    std::vector<int> vector1 = {1, 1, 2, 3, 3, 5};
    std::vector<int> vector2 = {2, 2, 4, 5, 6, 10};
    
    std::vector<int> merged_vectors = mergeSortedArrs(vector1, vector2);

    for (int i = 0; i < merged_vectors.size(); i++)
    {
        std::cout << merged_vectors[i] << " ";
    }

    return 0;
}