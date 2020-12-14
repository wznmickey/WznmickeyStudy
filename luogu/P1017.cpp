#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, r;
    int ans[500];
    int i = 0;
    cin >> n >> r;
    cout << n << "=";
    while (n != 0)
    {
        i++;
        ans[i] = n % r;

        if (ans[i] < 0)
        {
            ans[i] -= r;
            n += r;
        }
        n = n / r;
    }
    for (; i > 0; i--)
    {
        if (ans[i] >= 10)
            cout << (char)(ans[i] + 'A' - 10);
        else
            cout << ans[i];
    }
    cout << "(base" << r << ")" << endl;
    return 0;
}