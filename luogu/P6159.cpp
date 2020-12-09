#include <bits/stdc++.h>
using namespace std;
long long n, p, k, now, temp;
int main()
{
    scanf("%lld%lld%lld", &n, &p, &k);
    /*
    now = 0;
    for (int i = 0; i < k; i++)
    {
        temp = ((p + n - now) % n + p) % n;
        now = p;
        p = temp;
    }
    printf("%d", now);
    */
    printf("%d",p*k%n);
    return 0;
}