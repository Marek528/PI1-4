#include <iostream>
#include "MinHeap.cpp"

using namespace std;

static void test()
{
    MinHeap heap;

    // Insert values into the heap
    vector<int> valuesToInsert = {35, 25, 15, 5, 20, 30, 10};
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

        // Verify min heap property
        const vector<int> &currentHeap = heap.getHeap();
        bool isValidMinHeap = true;
        for (size_t i = 0; i < currentHeap.size(); i++)
        {
            int left = 2 * i + 1;  // Calculating left child index
            int right = 2 * i + 2; // Calculating right child index
            if (left < currentHeap.size() && currentHeap[i] > currentHeap[left])
            {
                isValidMinHeap = false;
                break;
            }
            if (right < currentHeap.size() && currentHeap[i] > currentHeap[right])
            {
                isValidMinHeap = false;
                break;
            }
        }

        cout << "\nMin Heap Property Valid? " << (isValidMinHeap ? "Yes" : "No") << "\n";
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