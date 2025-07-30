#include <iostream>
#include "MinHeap.cpp"

using namespace std;

static void test()
{
    MinHeap heap;

    // Insert values into the heap
    vector<int> values = {35, 25, 15, 5, 20, 30, 10};
    cout << "Inserting values: ";
    for (int value : values)
    {
        cout << value << " ";
        heap.insert(value);

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

        cout << "\nHeap after insertion: ";
        heap.printHeap();
        cout << "Min Heap Property Valid? " << (isValidMinHeap ? "Yes" : "No") << "\n";
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