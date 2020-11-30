#include <iostream>
using namespace std;
int n, queen[20], col[40], d1[40], d2[40], board[8][8];
void nqueen(int at, int n)
{
    if (at == n + 1)
    {
        for (int i = 1; i <= n; i++)
            cout<<i<<" "<<queen[i]<<endl;
            //if (!board[i][queen[i] + 1] && !board[i][queen[i] - 1] && !board[i - 1][queen[i]] && !board[i + 1][queen[i]] && !board[i - 1][queen[i] - 1] && !board[i - 1][queen[i] + 1] && !board[i + 1][queen[i] - 1] && !board[i + 1][queen[i] + 1])
              //  board[i][queen[i]] = 1;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (col[i] || d1[i + at] || d2[n + i - at])
            continue;
        queen[at] = i;
        col[i] = d1[i + at] = d2[n + i - at] = 1;
        nqueen(at + 1, n);
        col[i] = d1[i + at] = d2[n + i - at] = 0;
    }
}
int main()
{
    cin >> n; //4
    nqueen(1, n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cout << board[i][j] << " \n"[j == n];
    return 0;
}
/*
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0
*/
