#include <bits/stdc++.h>
using namespace std;
int main( )
{
    int n;
    cin >> n;
    for ( int i = 0; i < n; i++ )
    {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << ( x2 - x1 ) * ( y2 - y1 ) + 1 << endl;
    }
    return 0;
}