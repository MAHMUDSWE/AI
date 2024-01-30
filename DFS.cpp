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
    stack<int> s;
    vector<bool> visited(n, false);

    visited[start] = true;
    s.push(start);

    while (!s.empty())
    {
        start = s.top();
        cout << start << " ";
        if (start == 3)
            break;
        s.pop();

        for (auto adj : graph[start])
        {
            if (!visited[adj])
            {
                visited[adj] = true;
                s.push(adj);
            }
        }
    }

    return 0;
}