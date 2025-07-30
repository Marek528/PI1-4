#include <iostream>
#include <vector>
#include <algorithm>

bool canCompleteInTime(const std::vector<long long> &lines, const std::vector<long long> &orders, long long maxTime)
{
    int n = lines.size();
    int m = orders.size();

    std::vector<long long> capacity(n);
    for (int i = 0; i < n; i++)
    {
        capacity[i] = lines[i] * maxTime;
    }

    std::vector<long long> sortedOrders = orders;
    sort(sortedOrders.begin(), sortedOrders.end(), std::greater<long long>());

    for (int i = 0; i < m; i++)
    {
        int bestLine = -1;
        for (int j = 0; j < n; j++)
        {
            if (capacity[j] >= sortedOrders[i])
            {
                if (bestLine == -1 || capacity[j] > capacity[bestLine])
                {
                    bestLine = j;
                }
            }
        }

        if (bestLine == -1)
        {
            return false;
        }

        capacity[bestLine] -= sortedOrders[i];
    }

    return true;
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<long long> lines(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> lines[i];
    }

    std::vector<long long> orders(m);
    for (int i = 0; i < m; i++)
    {
        std::cin >> orders[i];
    }

    long long left = 0, right = 1e15, result = right;

    while (left <= right)
    {
        long long mid = left + (right - left) / 2;

        if (canCompleteInTime(lines, orders, mid))
        {
            result = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    std::cout << result << std::endl;

    return 0;
}