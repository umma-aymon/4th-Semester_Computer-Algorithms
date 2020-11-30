#include <bits/stdc++.h>
using namespace std;
vector< pair<int,int> >tree[10];
void Prims(int n)
{
    priority_queue< pair<int, int>,vector< pair<int, int> >,greater< pair<int,int> > > pq;
    int source=0,MST_cost=0;;
    vector<int>key(n,INT_MAX);
    vector<int>parent(n,-1);
    vector<bool>vis(n,false);
    pq.push(make_pair(0, source));
    key[source] = 0;
    while (!pq.empty())
    {
        int v = pq.top().second;
        pq.pop();
        vis[v]=true;
        //for(auto el:tree[v])
         for (int x = 0; x < tree[v].size(); x++)
        {
            int node=tree[v][x].first;
            int weight =tree[v][x].second;
            if (!vis[node] && key[node] > weight)
            {
                parent[node]=v;
                key[node] = weight;
                pq.push(make_pair(key[node], node));
            }
        }
    }
    cout<<"Minimum Spanning Tree:\n";
    for (int i = 1; i < n; ++i)
    {
        cout<<"Edge: "<<i<<" - "<<parent[i]<<" Cost: "<<key[i]<<endl;
        MST_cost+=key[i];
    }
    cout<<"Total minimum key: "<<MST_cost;
}
int main()
{
    int n, e, u, v, w, i;
    cin >> n >> e; // 6 7
    for (i = 0; i < e; i++)
    {
        cin >> u >> v >> w;
        tree[u].push_back(make_pair(v, w));
        tree[v].push_back(make_pair(u, w));
    }
    Prims(n);
    return 0;
}
/*
  0 1 4
  0 2 3
  1 2 1
  1 3 2
  2 3 4
  3 4 2
  4 5 6
OUTPUT:
1-2 1
2-0 3
3-1 2
4-3 2
5-4 5
min=14
*/
