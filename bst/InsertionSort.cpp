// #include "InsertionSort.h"
#include <iostream>

void insertionSort(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = array[i];
        int j = i - 1;

        while (j >= 0 && temp < array[j])
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = temp;
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(array) / sizeof(array[0]);

    std::cout << "Original array: ";
    printArray(array, size);

    insertionSort(array, size);

    std::cout << "Sorted array: ";
    printArray(array, size);

    return 0;
}