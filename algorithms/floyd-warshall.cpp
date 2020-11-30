#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j, k;
    cin >> n; //4
    int dis[n][n];
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> dis[i][j];
    for (k = 0; k < n; ++k)
        for (i = 0; i < n; ++i)
            for (j = 0; j < n; ++j)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    bool flag = false;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (dis[i][j] < 0)
            {
                flag = true;
                break;
            }
    if (flag)
        cout << "Negative Cycle Detected.\n\n";
    else
        cout << "There is No Negative Cycle Detected.\n";
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cout << dis[i][j] << " \n"[j == n - 1];
    return 0;
}
/*
  0 3 999 5
  2 0 999 4
  999 1 0 999
  999 999 2 0
OUTPUT:
 0 3 7 5
 2 0 6 4
 3 1 0 5
 5 3 2 0
 */
