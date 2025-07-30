#include <iostream>
#include "Graph.cpp"

using namespace std;

static void test()
{

    {
        cout << "\n----- Test: Add Edge To Empty Graph -----\n";
        Graph g;
        cout << "Before:\n";
        g.printGraph();
        cout << "Adding edge between 'A' and 'B'.\n";
        bool result = g.addEdge("A", "B");
        cout << "After:\n";
        g.printGraph();
        cout << "EXPECTED: false\n";
        cout << "RETURNED: " << (result ? "true" : "false") << "\n";
        cout << (result == false ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n---- Test: Add Edge Between Nonexistent Vertices (C & D) ----\n";
        Graph g;
        g.addVertex("A");
        g.addVertex("B");
        cout << "Before:\n";
        g.printGraph();
        cout << "Adding edge between 'C' and 'D'.\n";
        bool result = g.addEdge("C", "D");
        cout << "After:\n";
        g.printGraph();
        cout << "EXPECTED: false\n";
        cout << "RETURNED: " << (result ? "true" : "false") << "\n";
        cout << (result == false ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Add Edge Between One Nonexistent Vertex (B) -----\n";
        Graph g;
        g.addVertex("A");
        cout << "Before:\n";
        g.printGraph();
        cout << "Adding edge between 'A' and 'B'.\n";
        bool result = g.addEdge("A", "B");
        cout << "After:\n";
        g.printGraph();
        cout << "EXPECTED: false\n";
        cout << "RETURNED: " << (result ? "true" : "false") << "\n";
        cout << (result == false ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Add Edge Between Existing Vertices (A & B) -----\n";
        Graph g;
        g.addVertex("A");
        g.addVertex("B");
        cout << "Before:\n";
        g.printGraph();
        cout << "Adding edge between 'A' and 'B'.\n";
        bool result = g.addEdge("A", "B");
        cout << "After:\n";
        g.printGraph();
        cout << "EXPECTED: true\n";
        cout << "RETURNED: " << (result ? "true" : "false") << "\n";
        cout << (result == true ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Add Duplicate Edge (A & B) -----\n";
        Graph g;
        g.addVertex("A");
        g.addVertex("B");
        g.addEdge("A", "B");
        cout << "Before:\n";
        g.printGraph();
        cout << "Adding edge again between 'A' and 'B'.\n";
        bool result = g.addEdge("A", "B");
        cout << "After:\n";
        g.printGraph();
        cout << "EXPECTED: true\n"; // Adjusted based on your tests. If duplicates are not allowed, this should be "false"
        cout << "RETURNED: " << (result ? "true" : "false") << "\n";
        cout << (result == true ? "PASS\n" : "FAIL\n");
    }
}

int main()
{
    test();
    return 0;
}