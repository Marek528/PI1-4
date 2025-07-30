#include <iostream>
#include "Graph.cpp"

using namespace std;

static void test()
{

    {
        cout << "\n----- Test: Add New Vertex -----\n";
        Graph g;
        cout << "Before:\n";
        g.printGraph();
        cout << "Adding vertex 'A'.\n";
        bool result = g.addVertex("A");
        cout << "After:\n";
        g.printGraph();
        cout << "EXPECTED: true\n";
        cout << "RETURNED: " << (result ? "true" : "false") << "\n";
        cout << (result == true ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Add Duplicate Vertex -----\n";
        Graph g;
        g.addVertex("A");
        cout << "Before:\n";
        g.printGraph();
        cout << "Adding duplicate vertex 'A'.\n";
        bool result = g.addVertex("A");
        cout << "After:\n";
        g.printGraph();
        cout << "EXPECTED: false\n";
        cout << "RETURNED: " << (result ? "true" : "false") << "\n";
        cout << (result == false ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Add Multiple Vertices -----\n";
        Graph g;
        cout << "Before:\n";
        g.printGraph();
        cout << "Adding vertices 'A', 'B', duplicate 'A', and duplicate 'B'.\n";
        bool result1 = g.addVertex("A");
        bool result2 = g.addVertex("B");
        bool result3 = g.addVertex("A");
        bool result4 = g.addVertex("B");
        cout << "After:\n";
        g.printGraph();
        cout << "Adding 'A': EXPECTED: true, RETURNED: " << (result1 ? "true" : "false") << "\n";
        cout << "Adding 'B': EXPECTED: true, RETURNED: " << (result2 ? "true" : "false") << "\n";
        cout << "Adding duplicate 'A': EXPECTED: false, RETURNED: " << (result3 ? "true" : "false") << "\n";
        cout << "Adding duplicate 'B': EXPECTED: false, RETURNED: " << (result4 ? "true" : "false") << "\n";
        cout << (result1 && result2 && !result3 && !result4 ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Add Empty String Vertex -----\n";
        Graph g;
        cout << "Before:\n";
        g.printGraph();
        cout << "Adding empty string vertex.\n";
        bool result = g.addVertex("");
        cout << "After:\n";
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