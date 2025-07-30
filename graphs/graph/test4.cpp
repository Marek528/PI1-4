#include <iostream>
#include "Graph.cpp"

using namespace std;

static void test()
{

    {
        cout << "\n----- Test: Remove NonExistent Vertex -----\n";
        Graph g;
        g.addVertex("A");
        g.addVertex("B");
        cout << "Before:\n";
        g.printGraph();
        cout << "Removing vertex 'C'.\n";
        bool result = g.removeVertex("C");
        cout << "After:\n";
        g.printGraph();
        cout << "EXPECTED: false\n";
        cout << "RETURNED: " << (result ? "true" : "false") << "\n";
        cout << (result == false ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Remove Vertex With No Edges -----\n";
        Graph g;
        g.addVertex("A");
        cout << "Before:\n";
        g.printGraph();
        cout << "Removing vertex 'A'.\n";
        bool result = g.removeVertex("A");
        cout << "After:\n";
        g.printGraph();
        cout << "EXPECTED: true\n";
        cout << "RETURNED: " << (result ? "true" : "false") << "\n";
        cout << (result == true ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Remove Vertex With Multiple Edges -----\n";
        Graph g;
        g.addVertex("A");
        g.addVertex("B");
        g.addVertex("C");
        g.addEdge("A", "B");
        g.addEdge("A", "C");
        cout << "Before:\n";
        g.printGraph();
        cout << "Removing vertex 'A'.\n";
        bool result1 = g.removeVertex("A");
        bool result2 = g.removeVertex("A"); // Trying again
        cout << "After:\n";
        g.printGraph();
        cout << "EXPECTED 1st Removal: true\n";
        cout << "RETURNED 1st Removal: " << (result1 ? "true" : "false") << "\n";
        cout << "EXPECTED 2nd Removal: false\n";
        cout << "RETURNED 2nd Removal: " << (result2 ? "true" : "false") << "\n";
        cout << (result1 && !result2 ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Remove Vertex And Check Edges -----\n";
        Graph g;
        g.addVertex("A");
        g.addVertex("B");
        g.addVertex("C");
        g.addEdge("A", "B");
        g.addEdge("A", "C");
        cout << "Before:\n";
        g.printGraph();
        cout << "Removing vertex 'A'.\n";
        g.removeVertex("A");
        bool result1 = g.removeEdge("A", "B");
        bool result2 = g.removeEdge("A", "C");
        cout << "After:\n";
        g.printGraph();
        cout << "EXPECTED Edges Removal: false, false\n";
        cout << "RETURNED Edges Removal: " << (result1 ? "true" : "false") << ", " << (result2 ? "true" : "false") << "\n";
        cout << (!result1 && !result2 ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Remove Vertex And Update Graph -----\n";
        Graph g;
        g.addVertex("A");
        g.addVertex("B");
        g.addEdge("A", "B");
        cout << "Before:\n";
        g.printGraph();
        cout << "Removing vertex 'A' and re-adding it, then re-adding edge A-B.\n";
        g.removeVertex("A");
        g.addVertex("A");
        bool result = g.addEdge("A", "B");
        cout << "After:\n";
        g.printGraph();
        cout << "EXPECTED Edge Addition: true\n";
        cout << "RETURNED Edge Addition: " << (result ? "true" : "false") << "\n";
        cout << (result ? "PASS\n" : "FAIL\n");
    }
}

int main()
{
    test();
    return 0;
}