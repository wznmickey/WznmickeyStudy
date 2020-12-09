#include <bits/stdc++.h>
using namespace std;
int a[15];
int main()
{
    int h;
    int ans = 0;
    for (int i = 1; i <= 10; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &h);
    h += 30; //题目有30厘米的增高
    for (int i = 1; i <= 10; i++)
    {
        if (a[i] <= h)
            ans++;
    }
    printf("%d", ans);
    return 0;
}
