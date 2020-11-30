#include <bits/stdc++.h>
using namespace std;
vector< pair<int,int> >tree[10];
void Dijkstra(int source, int n)
{
    priority_queue< pair<int, int> > pq; // <dist,vertex>
    int dist[n];
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;
    pq.push(make_pair(0, source));
    dist[source] = 0;
    while (!pq.empty())
    {
        int v = pq.top().second;
        pq.pop();
        for (int x = 0; x < tree[v].size(); x++)
        {
            int weight = tree[v][x].second;
            if (dist[tree[v][x].first] > dist[v] + weight)
            {
                dist[tree[v][x].first] = dist[v] + weight;
                pq.push(make_pair(dist[v] + weight, tree[v][x].first));
            }
        }
    }
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main()
{
    int n, e, u, v, w, i;
    cin >> n >> e;
    for (i = 0; i < e; i++)
    {
        cin >> u >> v >> w;
        tree[u].push_back(make_pair(v, w));
        tree[v].push_back(make_pair(u, w));
    }
    Dijkstra(0, n);
    return 0;
}
/* 9 14
   0 1 4
   0 7 8
   1 2 8
   1 7 11
   2 3 7
   2 8 2
   2 5 4
   3 4 9
   3 5 14
   4 5 10
   5 6 2
   6 5 1
   6 8 6
   7 8 7
OUTPUT:
0 0
1 4
2 12
3 19
4 21
5 11
6 9
7 8
8 14*/
