#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a, b, ans;
    long long c;
    cin >> a >> b >> c;
    if (a < b)
        swap(a, b);
    c -= (a - b);
    if (c >= 0)
    {
        a += (c / 2);
    }
    else
    {
        a += c;
    }
    double delta = (double)a * 8 + 1;
    ans = (sqrt(delta) - 1) / 2;
    cout << ans << endl;
    return 0;
}