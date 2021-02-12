#include <bits/stdc++.h>
using namespace std;
string st;
int    l, i;
int    getnumber( )
{
    int n = 1;
    if ( st [ i ] >= '0' && st [ i ] <= '9' )
    {
        n = st [ i ] - '0';
        i++;
        if ( ( st [ i ] >= '0' ) && ( st [ i ] <= '9' ) )
        {
            n = n * 10 + st [ i ] - '0';
            i++;
        }
    }
    return n;
}
string check( )
{
    string temp;
    while ( st [ i ] != ']' )
    {
        if ( st [ i ] == '[' )
        {
            i++;
            int    n  = getnumber( );
            string te = check( );
            for ( int j = 0; j < n; j++ ) { temp += te; }
        }
        else
        {
            temp += st [ i ];
            i++;
        }
    }
    if ( st [ i ] == ']' ) i++;
    return temp;
}
int main( )
{
    cin >> st;
    l = st.length( );
    for ( i = 0; i < l; )
    {
        if ( ( st [ i ] >= 'A' ) && ( st [ i ] <= 'Z' ) )
        {
            printf( "%c", st [ i ] );
            i++;
        }
        else
        {
            if ( st [ i ] == '[' )
            {
                i++;
                int    n    = getnumber( );
                string temp = check( );
                for ( int j = 0; j < n; j++ ) { cout << temp; }
            }
        }
    }
    return 0;
}