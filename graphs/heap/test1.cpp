#include <iostream>
#include "MaxHeap.cpp"

using namespace std;

static void test()
{
    Heap heap;

    // Insert values into the heap
    vector<int> values = {10, 20, 30, 5, 15, 25, 35};
    cout << "Inserting values: ";
    for (int value : values)
    {
        cout << value << " ";
        heap.insert(value);

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

        cout << "\nHeap after insertion: ";
        heap.printHeap();
        cout << "Max Heap Property Valid? " << (isValidMaxHeap ? "Yes" : "No") << "\n";
    }

    // Final Heap structure
    cout << "\nFinal Heap Structure: ";
    heap.printHeap();
}

int main()
{
    test();
    return 0;
}