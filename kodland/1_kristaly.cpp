#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

long long sortDigits(long long num)
{
    string numStr = to_string(num);
    sort(numStr.begin(), numStr.end());
    return stoll(numStr);
}

int main()
{
    int N, K;
    cin >> N >> K;
    
    vector<long long> signatures(N);
    for (int i = 0; i < N; i++)
    {
        cin >> signatures[i];
    }
    
    int realCrystalsCount = 0;
    long long sumOfRealCrystals = 0;
    
    for (int i = 0; i < N; i++)
    {
        long long originalSignature = signatures[i];
        long long sortedSignature = sortDigits(originalSignature);
        long long difference = sortedSignature - originalSignature;
        
        if (difference % K == 0)
        {
            realCrystalsCount++;
            sumOfRealCrystals += originalSignature;
        }
    }
    
    cout << endl << realCrystalsCount << endl;
    cout << sumOfRealCrystals;
    
    return 0;
}