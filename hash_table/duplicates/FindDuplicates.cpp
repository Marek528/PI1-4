#include "FindDuplicates.h"

vector<int> findDuplicates(const vector<int> &nums)
{
    unordered_map<int, int> numCounts;
    vector<int> duplicates;

    for (size_t i = 0; i < nums.size(); i++)
    {
        numCounts[nums[i]]++;
    }

    unordered_map<int, int>::iterator it = numCounts.begin();
    while (it != numCounts.end())
    {
        if (it->second > 1)
        {
            duplicates.push_back(it->first);
        }
        it++;
    }

    return duplicates;
}