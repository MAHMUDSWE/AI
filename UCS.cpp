#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, v;

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

    dist[start] = 0;

    pq.push({0, start});

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
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Minimum Distance to Goal: " << dist[goal] << endl;

    return 0;
}