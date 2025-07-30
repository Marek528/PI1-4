#include <iostream>
#include <vector>

int partition(std::vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            std::swap(arr[i], arr[j]);
            i++;
        }
    }

    std::swap(arr[i], arr[high]);

    return i;
}

void quickSort(std::vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main()
{
    std::vector<int> arr = {8, 4, 7, 3, 1, 9, 10, 2, 1};

    quickSort(arr, 0, arr.size() - 1);

    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}