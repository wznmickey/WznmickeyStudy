#include "assignment.h"
#include <bits/stdc++.h>

using namespace std;
void ex4_1( );
void ex4_2( );
int  check( unsigned long long i, unsigned long long &M, int N [] );
void ex4( )
{
    int x;
    scanf( "%d", &x );
    // cout << x << endl;
    if ( x == 1 ) { ex4_1( ); }
    else
    {
        ex4_2( );
    }
    return;
}
void ex4_1( )
{
    unsigned long long a, N;
    cin >> a;
    // cout << a << endl;
    N = 0;
    while ( a != 1 )
    {
        if ( a % 2 == 0 ) a = a >> 1;
        else
            a = a * 3 + 1;
        N++;
    }
    cout << N;
    return;
}
void ex4_2( )
{
    unsigned long long M;
    cin >> M;
    /*
    queue< int > Q;
    Q.push( 1 );
    int temp;
    int ans;
    while ( ! Q.empty( ) )
    {
        temp = Q.front( );
        if (temp<=M) ans=temp;
        //cout << temp << " ";
        Q.pop( );
        if ( temp * 2 <= 0xFFFFFFFFFFFFFFFF ) Q.push( temp * 2 );
        if ( ( ( temp - 1 ) % 3 == 0 ) && ( ( temp - 1 ) / 3 <= 0xFFFFFFFFFFFFFFFF ) && ( ( temp - 1 ) / 3 >= 2 ) && ( ( temp - 1 ) / 3 % 2 == 1 ) ) Q.push( (
    temp - 1 ) / 3 );
    }
    */
    // cout << ans << endl;
    // cout << M << endl;
    int *              N   = new int [ M + 2 ];
    unsigned long long ans = 0;
    for ( int i = 0; i <= M; i++ ) { N [ i ] = -1; }
    N [ 0 ] = 0;
    N [ 1 ] = 0;
    /*
    for ( int i = 2; i <= M; i++ )
    {
        if ( N [ i ] == -1 ) { check( i, N ); }
    }
    */
    int maxx = 0;
    for ( unsigned long long i = 2; i <= M; i++ )
    {
        int temp = check( i, M, N );
        if ( maxx < temp )
        {
            ans  = i;
            maxx = temp;
        }
        // ans = max( ans, check( i, N, M ) );
        // cout << i << " " << N [ i ] << endl;
    }
    cout << ans << endl;
    delete [] N;
    return;
}
int check( unsigned long long i, unsigned long long &M,int N[] )
{
    if ( i == 1 ) return 0;
    // if ( N [ i ] != -1 ) return;
    if ( i % 2 == 0 )
    {
        if ( i > M ) return ( check( i / 2, M, N ) + 1 );
        if ( N [ i ] == -1 ) N [ i ] = check( i / 2, M, N ) + 1;
        return N [ i ];
        // else
        //{
        //    N [ i ] = ( N [ i / 2 ] + 1 );
        //    return N [ i ];
        //    N [ i ] = N [ i / 2 ] + 1;
        //}
    }
    else
    {
        if ( i > M ) // || N [ i ] == -1 )
            return ( check( ( i ) *3 + 1, M, N ) + 1 );
        if ( N [ i ] == -1 ) N [ i ] = check( i * 3 + 1, M, N ) + 1;
        return N [ i ];
        // else
        //{
        //    N [ i ] = ( N [ i * 3 + 1 ] + 1 );
        //    return N [ i ];
        //}
        // N [ i ] = N [ i * 3 + 1 ] + 1;
    }
}
#ifdef JOJ
int main( )
{
    ex4( );
    return 0;
}
#endif