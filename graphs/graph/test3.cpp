#include <iostream>
#include "Graph.cpp"

using namespace std;

static void test()
{

    {
        cout << "\n----- Test: Remove Edge From Empty Graph -----\n";
        Graph g;
        cout << "Before:\n";
        g.printGraph();
        cout << "Removing edge between 'A' and 'B'.\n";
        bool result = g.removeEdge("A", "B");
        cout << "After:\n";
        g.printGraph();
        cout << "EXPECTED: false\n";
        cout << "RETURNED: " << (result ? "true" : "false") << "\n";
        cout << (result == false ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Remove Edge Between Nonexistent Vertices -----\n";
        Graph g;
        g.addVertex("A");
        g.addVertex("B");
        cout << "Before:\n";
        g.printGraph();
        cout << "Removing edge between 'C' and 'D'.\n";
        bool result = g.removeEdge("C", "D");
        cout << "After:\n";
        g.printGraph();
        cout << "EXPECTED: false\n";
        cout << "RETURNED: " << (result ? "true" : "false") << "\n";
        cout << (result == false ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Remove NonExistent Edge Between Existing Vertices -----\n";
        Graph g;
        g.addVertex("A");
        g.addVertex("B");
        cout << "Before:\n";
        g.printGraph();
        cout << "Removing edge between 'A' and 'B'.\n";
        bool result = g.removeEdge("A", "B");
        cout << "After:\n";
        g.printGraph();
        cout << "EXPECTED: true\n";
        cout << "RETURNED: " << (result ? "true" : "false") << "\n";
        cout << (result == true ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Remove Existing Edge -----\n";
        Graph g;
        g.addVertex("A");
        g.addVertex("B");
        g.addEdge("A", "B");
        cout << "Before first removal:\n";
        g.printGraph();
        cout << "Removing edge between 'A' and 'B'.\n";
        bool result1 = g.removeEdge("A", "B");
        cout << "After first removal:\n";
        g.printGraph();
        cout << "Removing edge again between 'A' and 'B'.\n";
        bool result2 = g.removeEdge("A", "B");
        cout << "After second removal:\n";
        g.printGraph();
        cout << "First removal: EXPECTED: true, RETURNED: " << (result1 ? "true" : "false") << "\n";
        cout << "Second removal: EXPECTED: true, RETURNED: " << (result2 ? "true" : "false") << "\n";
        cout << ((result1 && result2) == true ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Remove Edge After Vertex Removal -----\n";
        Graph g;
        g.addVertex("A");
        g.addVertex("B");
        g.addEdge("A", "B");
        g.removeEdge("A", "B");
        cout << "Before second removal:\n";
        g.printGraph();
        cout << "Removing edge again between 'A' and 'B'.\n";
        bool result = g.removeEdge("A", "B");
        cout << "After second removal:\n";
        g.printGraph();
        cout << "EXPECTED: true\n";
        cout << "RETURNED: " << (result ? "true" : "false") << "\n";
        cout << (result == true ? "PASS\n" : "FAIL\n");
    }
}

int main()
{
    test();
    return 0;
}