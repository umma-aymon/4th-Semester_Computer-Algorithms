#include <bits/stdc++.h>
#define pb push_back
using namespace std;
vector<int> node[100];
vector<bool> dis;
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    dis[src] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int i = 0; i < node[u].size(); i++)
        {
            int v = node[u][i];
            // cout<<"v="<<v<<endl;
            if (!dis[v])
            {
                dis[v] = true;
                q.push(v);
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e; // 4 6
    cout << "Number of Nodes= " << n << "\nNumber of Edges= " << e;
    dis.assign(n, false);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b; // 0-1,0-2,1-2,2-0,2-3,3-3
        node[a].pb(b);
        node[b].pb(a);
    }
    cout << "\nBFS Traversal:\n"; // 0 1 2 3 4
    for (int i = 0; i <= n; i++)
        if (!dis[i])
            bfs(i);
    return 0;
}
