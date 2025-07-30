#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool checkSubstringOccurrences(const string &s, int len, int k, string &result)
{
    int n = s.length();
    if (len == 0 || len > n)
    {
        return false;
    }

    unordered_map<string, vector<int>> substringPositions;

    for (int i = 0; i <= n - len; i++)
    {
        string pattern = s.substr(i, len);
        substringPositions[pattern].push_back(i);

        if (substringPositions[pattern].size() >= k)
        {
            result = pattern;
            return true;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    string sequence;
    cin >> sequence;

    if (K == 1)
    {
        cout << N << endl;
        cout << sequence << endl;
        return 0;
    }

    if (N < K || K <= 0)
    {
        cout << "0" << endl;
        return 0;
    }

    int low = 0, high = N;
    string finalResult;

    while (low <= high)
    {
        int mid = low + (high - low + 1) / 2;
        string currentResult;

        if (checkSubstringOccurrences(sequence, mid, K, currentResult))
        {
            finalResult = currentResult;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (finalResult.empty())
    {
        cout << "0" << endl;
    }
    else
    {
        cout << endl << finalResult.length() << endl;
        cout << finalResult;
    }

    return 0;
}