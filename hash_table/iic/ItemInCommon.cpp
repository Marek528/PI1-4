#include "ItemInCommon.h"

bool itemInCommon(vector<int> vect1, vector<int> vect2)
{
    unordered_map<int, int> myMap;
    
    for (size_t i = 0; i < vect1.size(); i++)
    {
        myMap[vect1[i]] = i;
    }

    for (size_t i = 0; i < vect2.size(); i++)
    {
        if (myMap.find(vect2[i]) != myMap.end())
        {
            return true;
        }
    }
    
    return false;
}