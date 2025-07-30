#include <iostream>
#include <vector>

int selectionSort(std::vector<int> arr, int k)
{
    for (int i = 0; i < k; i++)
    {
        int min = i;

        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        
        std::swap(arr[i], arr[min]);

        if (i == k - 1)
        {
            return arr[i];
        }
    }

    return -1;
}

int main()
{
    std::vector<int> arr = {10, 7, 4, 3, 20, 15};

    int kth_smallest = selectionSort(arr, 3);
    std::cout << kth_smallest;

    return 0;
}