#include <bits/stdc++.h>
using namespace std;
int main( )
{
    int b, a, n;
    cin >> n;
    a = 1;
    b = 1;
    for ( int i = 2; i <= n; )
    {
        a += b;
        a %= 10007;
        i++;
        if ( i != n )
        {
            b += a;
            b %= 10007;
            i++;
            if ( i == n )
            {
                cout << b;
                return 0;
            }
        }
        if ( i == n )
        {
            cout << a;
            return 0;
        }
    }
    if ( n == 1 ) cout << 1;
    if ( n == 2 ) cout << 1;
    return 0;
}