#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

struct Edge
{
    int src, dest, weight;

    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}

    bool operator<(const Edge &other) const
    {
        return weight < other.weight;
    }
};

class UnionFind
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unionSets(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
        {
            return false;
        }

        if (rank[rootX] < rank[rootY])
        {
            parent[rootX] = rootY;
        }
        else if (rank[rootX] > rank[rootY])
        {
            parent[rootY] = rootX;
        }
        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }

        return true;
    }
};

int kruskalMST(vector<vector<int>> &graph)
{
    int V = graph.size();
    vector<Edge> edges;

    for (int i = 0; i < V; ++i)
    {
        for (int j = i + 1; j < V; ++j)
        {
            if (graph[i][j] != 0)
            {
                edges.push_back(Edge(i, j, graph[i][j]));
            }
        }
    }

    sort(edges.begin(), edges.end());

    UnionFind uf(V);
    int mstWeight = 0;
    int edgeCount = 0;

    for (const Edge &edge : edges)
    {
        if (uf.unionSets(edge.src, edge.dest))
        {
            mstWeight += edge.weight;
            edgeCount++;

            if (edgeCount == V - 1)
            {
                break;
            }
        }
    }

    return mstWeight;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    ifstream inputFile(argv[1]);
    if (!inputFile.is_open())
    {
        cerr << "Error: Could not open file " << argv[1] << endl;
        return 1;
    }

    vector<vector<int>> graph;
    string line;

    while (getline(inputFile, line))
    {
        if (line.empty())
        {
            continue;
        }

        vector<int> row;
        istringstream iss(line);
        int weight;

        while (iss >> weight)
        {
            row.push_back(weight);
        }

        if (!row.empty())
        {
            graph.push_back(row);
        }
    }

    inputFile.close();

    int mstWeight = kruskalMST(graph);
    cout << mstWeight;

    return 0;
}