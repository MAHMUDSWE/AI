#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, v;

    cin >> n >> v;

    vector<vector<int>> graph(n);

    for (int i = 0; i < v; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }

    int start = 2;

    stack<pair<int, int>> s;
    vector<bool> visited(n, false);

    visited[start] = true;
    s.push({start, 0});

    int depthLimit = 3;
    while (!s.empty())
    {
        start = s.top().first;
        int currentDepth = s.top().second;

        cout << start << " ";

        if (start == 3)
            break;
        s.pop();

        if (currentDepth < depthLimit)
        {
            for (auto adj : graph[start])
            {
                if (!visited[adj])
                {
                    visited[adj] = true;
                    s.push({adj, currentDepth + 1});
                }
            }
        }
    }

    return 0;
}