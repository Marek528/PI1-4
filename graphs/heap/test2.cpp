#include <iostream>
#include "MaxHeap.cpp"

using namespace std;

static void test()
{
    Heap heap;

    // Insert values into the heap
    vector<int> valuesToInsert = {10, 20, 30, 5, 15, 25, 35};
    cout << "Inserting values: ";
    for (int value : valuesToInsert)
    {
        cout << value << " ";
        heap.insert(value);
    }
    cout << "\nInitial Heap: ";
    heap.printHeap();

    // Remove values from the heap and test after each removal
    while (!heap.getHeap().empty())
    {
        int removedValue = heap.remove();
        cout << "\nRemoved Value: " << removedValue;
        cout << "\nHeap after removal: ";
        heap.printHeap();

        // Verify max heap property
        const vector<int> &currentHeap = heap.getHeap();
        bool isValidMaxHeap = true;
        for (size_t i = 0; i < currentHeap.size(); i++)
        {
            int left = 2 * i + 1;  // Calculating left child index
            int right = 2 * i + 2; // Calculating right child index
            if (left < currentHeap.size() && currentHeap[i] < currentHeap[left])
            {
                isValidMaxHeap = false;
                break;
            }
            if (right < currentHeap.size() && currentHeap[i] < currentHeap[right])
            {
                isValidMaxHeap = false;
                break;
            }
        }

        cout << "\nMax Heap Property Valid? " << (isValidMaxHeap ? "Yes" : "No") << "\n";
    }

    // Check if heap is empty at the end
    cout << "\nFinal Heap (Should be empty): ";
    heap.printHeap();
}

int main()
{
    test();
    return 0;
}