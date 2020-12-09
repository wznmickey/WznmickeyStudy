#include <bits/stdc++.h>
using namespace std;
long long a[30][30];
int n, x, y, m, i, j;
int main()
{
    scanf("%d%d%d%d", &n, &m, &x, &y);
    //全部加一防止越界
    n++;
    m++;
    x++;
    y++;
    a[0][1] = 1;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            a[i][j] = a[i - 1][j] + a[i][j - 1];
            if (x >= 2 && y >= 1)
                a[x - 2][y - 1] = 0;
            if (x >= 2)
                a[x - 2][y + 1] = 0;
            if (x >= 1 && y >= 2)
                a[x - 1][y - 2] = 0;
            if (x >= 1)
                a[x - 1][y + 2] = 0;
            if (y >= 1)
                a[x + 2][y - 1] = 0;
            a[x + 2][y + 1] = 0;
            if (y >= 2)
                a[x + 1][y - 2] = 0;
            a[x + 1][y + 2] = 0;
            a[x][y] = 0;
        }
    }
    printf("%lld", a[n][m]);
    return 0;
}