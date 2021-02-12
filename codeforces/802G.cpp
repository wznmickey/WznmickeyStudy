#include <bits/stdc++.h>
using namespace std;
int main( )
{
    bool a [ 10 ];
    for ( int i = 0; i < 10; i++ ) a [ i ] = false;
    char c;
    while ( scanf( "%c", &c ) != EOF )
    {
        if ( ! ( c == 'h' || c == 'e' || c == 'i' || c == 'd' ) ) { continue; }
        if ( c == 'h' ) a [ 0 ] = true;
        if ( c == 'e' && a [ 0 ] == true ) a [ 1 ] = true;
        if ( c == 'i' && a [ 1 ] == true ) a [ 2 ] = true;
        if ( c == 'd' && a [ 2 ] == true ) a [ 3 ] = true;
        if ( c == 'i' && a [ 3 ] == true ) a [ 4 ] = true;
    }
    if ( a [ 4 ] == true ) printf( "YES" );
    else
        printf( "NO" );
    return 0;
}