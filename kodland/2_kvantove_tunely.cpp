#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct Tunnel
{
    int destination;
    int length;
};

class QuantumTunnelSolver
{
private:
    int nodes;
    vector<vector<Tunnel>> graph;
    vector<int> checkpoints;
    int start, destination;

public:
    QuantumTunnelSolver(int n, int s, int d)
    {
        nodes = n;
        start = s;
        destination = d;
        graph.resize(n + 1); // +1 because nodes are 1-indexed
    }

    void addTunnel(int from, int to, int length)
    {
        graph[from].push_back({to, length});
        graph[to].push_back({from, length});
    }

    void addCheckpoint(int checkpoint)
    {
        checkpoints.push_back(checkpoint);
    }

    pair<int, vector<int>> dijkstra(int start, int end)
    {
        vector<int> distance(nodes + 1, INT_MAX);
        vector<int> parent(nodes + 1, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        distance[start] = 0;
        pq.push({0, start});

        while (!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (dist > distance[node])
            {
                continue;
            }

            if (node == end)
            {
                break;
            }

            for (const auto &tunnel : graph[node])
            {
                int next = tunnel.destination;
                int length = tunnel.length;

                if (distance[node] + length < distance[next])
                {
                    distance[next] = distance[node] + length;
                    parent[next] = node;
                    pq.push({distance[next], next});
                }
            }
        }

        vector<int> path;
        if (distance[end] == INT_MAX)
        {
            return {INT_MAX, path}; // no path found
        }

        for (int at = end; at != -1; at = parent[at])
        {
            path.push_back(at);
        }
        reverse(path.begin(), path.end());

        return {distance[end], path};
    }

    pair<int, vector<int>> findShortestPathWithCheckpoints()
    {
        if (checkpoints.empty())
        {
            return dijkstra(start, destination);
        }

        vector<int> points = {start};
        for (int checkpoint : checkpoints)
        {
            points.push_back(checkpoint);
        }
        points.push_back(destination);

        int n = points.size();

        vector<vector<pair<int, vector<int>>>> distances(n, vector<pair<int, vector<int>>>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    distances[i][j] = dijkstra(points[i], points[j]);
                }
                else
                {
                    distances[i][j] = {0, {points[i]}};
                }
            }
        }

        vector<int> bestPath;
        int minDistance = INT_MAX;

        vector<int> indices(n - 2);
        for (int i = 0; i < n - 2; i++)
        {
            indices[i] = i + 1; // +1 because indices[0] corresponds to points[1]
        }

        do
        {
            int totalDist = 0;
            vector<int> fullPath = {0}; // start with the start point index (0)

            for (int idx : indices)
            {
                fullPath.push_back(idx);
            }
            fullPath.push_back(n - 1); // end with the destination point index

            vector<int> completePath;
            for (int i = 0; i < fullPath.size() - 1; i++)
            {
                int from = fullPath[i];
                int to = fullPath[i + 1];

                totalDist += distances[from][to].first;

                vector<int> segment = distances[from][to].second;
                if (i > 0)
                {
                    segment.erase(segment.begin()); // remove first node to avoid duplication
                }

                completePath.insert(completePath.end(), segment.begin(), segment.end());
            }

            if (totalDist < minDistance)
            {
                minDistance = totalDist;
                bestPath = completePath;
            }

        }
        while (next_permutation(indices.begin(), indices.end()));

        return {minDistance, bestPath};
    }
};

int main()
{
    int N, M, S, D;
    cin >> N >> M >> S >> D;

    QuantumTunnelSolver solver(N, S, D);

    int K;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int checkpoint;
        cin >> checkpoint;
        solver.addCheckpoint(checkpoint);
    }

    for (int i = 0; i < M; i++)
    {
        int A, B, L;
        cin >> A >> B >> L;
        solver.addTunnel(A, B, L);
    }

    auto result = solver.findShortestPathWithCheckpoints();

    cout << endl << result.first << endl;

    for (int i = 0; i < result.second.size(); i++)
    {
        cout << result.second[i];
        if (i < result.second.size() - 1)
        {
            cout << " ";
        }
    }

    return 0;
}