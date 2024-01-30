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

    queue<int> q;
    vector<bool> visited(n, false);

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        start = q.front();
        cout << start << " ";
        if (start == 3)
            break;
        q.pop();

        for (auto adj : graph[start])
        {
            if (!visited[adj])
            {
                visited[adj] = true;
                q.push(adj);
            }
        }
    }

    return 0;
}