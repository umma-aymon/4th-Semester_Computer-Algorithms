#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
int parent[1001], key[1001];
void make_set(int x)
{
    parent[x] = x;
    key[x] = 1;
}
int find_set(int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = find_set(parent[x]);
}
void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (key[a] < key[b])
            swap(a, b);
        parent[b] = a;
        key[a] += key[b];
    }
}
int main()
{
    int n, e, cost = 0;
    vector< pair <int, pair <int, int> > > vec;
    vector< pair<int, int> > result;
    cin >> n >> e; // 6 7
    for (int i = 0; i < n; i++)
        make_set(i);
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        u--, v--;
        cin >> u >> v >> w;
        vec.push_back(make_pair(w, make_pair(u, v)));
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < e; i++)
    {
        int x = vec[i].second.first, y = vec[i].second.second, z = vec[i].first;
        if (find_set(x) != find_set(y))
        {
            cost += z;
            result.push_back(vec[i].second);
            ans.push_back(z);
            union_set(x, y);
        }
    }
    for (int i = 0; i < result.size(); i++)
        cout << "Edge: " << result[i].first << " - " << result[i].second << " Cost: " << ans[i] << endl;
    cout << "Total minimum cost: " << cost << endl;
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
