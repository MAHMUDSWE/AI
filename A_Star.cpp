#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, v;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> v;

    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < v; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({y, w});
    }

    int start = 1;
    int goal = 9;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, INT_MAX);

    map<int, int> heuristicMap;

    for (int i = 1; i <= n; i++)
    {
        int heuristic;
        cin >> heuristic;
        heuristicMap[i] = heuristic;
    }

    dist[start] = 0;

    pq.push({dist[start] + heuristicMap[start], start});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (u == goal)
            break;

        for (auto adj : graph[u])
        {
            int v = adj.first;
            int weight = adj.second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v] + heuristicMap[v], v});
            }
        }
    }

    cout << "Minimum Distance to Goal: " << dist[goal] << endl;

    return 0;
}

/*

9 9
1 2 75
1 3 118
1 5 140
3 4 111
5 6 99
5 7 80
6 9 211
7 8 97
8 9 101

366 374 329 244 253 178 193 98 0

*/
