#include <bits/stdc++.h>
using namespace std;
vector<int> ve[100];
vector<bool> vis;
void dfs(int u)
{
    vis[u] = true;
    cout << u << " ";
    for (int i = 0; i < ve[u].size(); i++)
        if (!vis[ve[u][i]])
            dfs(ve[u][i]);
}
int main()
{
    int n, e, a, b;
    cin >> n >> e; // 6 4
    cout << "Number of Nodes= " << n << "\nNumber of Edges= " << e;
    vis.assign(n, false);
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b; // 1-2,2-3,1-3,4-5
        ve[a].push_back(b);
        ve[b].push_back(a);
    }
    cout << "\nDFS Traversal:\n"; // 0 1 2 3 4 5 6
    for (int i = 0; i <= n; i++)
        if (!vis[i])
            dfs(i);
    return 0;
}
