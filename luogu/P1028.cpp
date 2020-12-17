#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long ans[1005]={0};
    int n;
    cin >> n;
    ans[1]=1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i / 2; j++)
        {
            ans[i] += ans[j];
        }
        ans[i]++;
    }
    cout << ans[n];
    return 0;
}