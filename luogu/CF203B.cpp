#include <bits/stdc++.h>
using namespace std;
int  n, k;
int  a [ 60 ];
bool cmp( int a, int b )
{
    return a > b;
}
int main( )
{
    cin >> n >> k;
    for ( int i = 0; i < n; i++ ) { cin >> a [ i ]; }
    sort( a, a + n ,cmp);
    if ( k == n ) cout << "0 0" << endl;
    else
    {
        if ( k <= n && a [ k - 1 ] != a [ k ] ) cout << a [ k - 1 ] << " " << 0 << endl;
        else
            cout << -1;
    }

    return 0;
}