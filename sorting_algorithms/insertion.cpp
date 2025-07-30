#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int curr = arr[i];
        int j = i - 1;

        while (j >= 0 && curr < arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curr;
    }
}

int main()
{
    std::vector<int> arr = {9, 5, 2, 8, 1, 4, 7, 1, 2, 3, 4};

    insertionSort(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}