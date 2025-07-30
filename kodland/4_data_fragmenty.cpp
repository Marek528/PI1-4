#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int findOverlap(const string& a, const string& b)
{
    int maxOverlap = 0;
    int aLen = a.length();
    int bLen = b.length();
    
    for (int i = 1; i <= min(aLen, bLen); i++)
    {
        if (a.substr(aLen - i) == b.substr(0, i))
        {
            maxOverlap = i;
        }
    }

    return maxOverlap;
}

string shortestSuperstring(vector<string>& fragments)
{
    int n = fragments.size();
    
    if (n == 1)
    {
        return fragments[0];
    }
    
    vector<int> indices(n);
    for (int i = 0; i < n; i++)
    {
        indices[i] = i;
    }
    
    string bestSuperstring;
    int minLength = INT_MAX;
    
    do
    {
        string currentSuperstring = fragments[indices[0]];
        
        for (int i = 1; i < n; i++)
        {
            int overlap = findOverlap(currentSuperstring, fragments[indices[i]]);
            currentSuperstring += fragments[indices[i]].substr(overlap);
        }
        
        if (currentSuperstring.length() < minLength)
        {
            minLength = currentSuperstring.length();
            bestSuperstring = currentSuperstring;
        }
    }
    while (next_permutation(indices.begin(), indices.end()));
    
    return bestSuperstring;
}

string greedySuperstring(vector<string>& fragments)
{
    int n = fragments.size();
    vector<bool> used(n, false);
    string result = fragments[0];
    used[0] = true;
    int remainingFragments = n - 1;
    
    while (remainingFragments > 0)
    {
        int bestOverlap = -1;
        int bestIndex = -1;
        string bestMerged;
        
        for (int i = 0; i < n; i++)
        {
            if (used[i])
            {
                continue;
            }
            
            int overlapEnd = findOverlap(result, fragments[i]);
            string mergedEnd = result + fragments[i].substr(overlapEnd);
            
            int overlapStart = findOverlap(fragments[i], result);
            string mergedStart = fragments[i] + result.substr(overlapStart);
            
            if (overlapEnd > bestOverlap)
            {
                bestOverlap = overlapEnd;
                bestIndex = i;
                bestMerged = mergedEnd;
            }
            
            if (overlapStart > bestOverlap)
            {
                bestOverlap = overlapStart;
                bestIndex = i;
                bestMerged = mergedStart;
            }
        }
        
        result = bestMerged;
        used[bestIndex] = true;
        remainingFragments--;
    }
    
    return result;
}

int main()
{
    int n;
    cin >> n;
    
    vector<string> fragments(n);
    for (int i = 0; i < n; i++)
    {
        cin >> fragments[i];
    }
    
    string result;
    if (n <= 10)
    {
        result = shortestSuperstring(fragments);
    }
    else
    {
        result = greedySuperstring(fragments);
    }
    
    cout << endl << result;
    
    return 0;
}