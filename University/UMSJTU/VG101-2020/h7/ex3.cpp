#include "assignment.h"
#include <bits/stdc++.h>
using namespace std;
void swap_int( int *x, int *y );
void ex3( )
{
    fstream x;
    x.open( "matrices.txt" );
    // FILE *      x = fopen( "matrices.txt", "r" );
    char        ch;
    static int  ma [ 5 ][ 505 ][ 505 ];
    static char temp [ 505 ] = { 0 };
    int         index_ch     = 0;
    int         i, j, z, max_i, max_j;
    bool        check = false;
    i                 = 0;
    j                 = 0;
    z                 = 0;
    while ( ( ch = ( char ) ( x.get( ) ) ) != EOF || index_ch != 0 )
    {
        if ( ( ch != ' ' ) && ( ch != '\n' ) )
        {
            temp [ index_ch ] = ch;
            index_ch++;
            check = false;
        }
        if ( ch == ' ' )
        {
            ma [ z ][ i ][ j ] = atoi( temp );
            for ( int k = 0; k <= index_ch; k++ ) temp [ k ] = '\0';
            index_ch = 0;
            j++;
            check = false;
        }
        if ( ch == '\n' || ch == EOF )
        {
            if ( check == true )
            {
                z++;
                max_i = i - 1;
                i     = 0;
                j     = 0;
            }
            else
            {
                ma [ z ][ i ][ j ] = atoi( temp );
                for ( int k = 0; k <= index_ch; k++ ) temp [ k ] = '\0';
                index_ch = 0;
                i++;
                max_j = j;
                j     = 0;
                check = true;
            }
        }
    }
    x.close( );
    x.open( "result.txt", ios::out );
    for ( i = 0; i <= max_i; i++ )
    {
        for ( j = 0; j <= max_j; j++ )
        {
            ma [ 2 ][ i ][ j ] = ma [ 0 ][ i ][ j ] + ma [ 1 ][ i ][ j ];
            x << ma [ 2 ][ i ][ j ] << ' ';
        }
        x << endl;
    }
    x << endl;
    for ( i = 0; i <= max_i; i++ )
    {
        for ( j = 0; j <= max_j; j++ )
        {
            ma [ 2 ][ i ][ j ] = 0;
            for ( int k = 0; k <= max_i; k++ ) { ma [ 2 ][ i ][ j ] += ( ma [ 0 ][ i ][ k ] * ma [ 1 ][ k ][ j ] ); }
            x << ma [ 2 ][ i ][ j ] << ' ';
        }
        x << endl;
    }
    x << endl;
    for ( i = 0; i <= max_i; i++ )
    {
        for ( j = i; j <= max_j; j++ )
        {
            swap_int( &ma [ 0 ][ i ][ j ], &ma [ 0 ][ j ][ i ] );
            swap_int( &ma [ 1 ][ i ][ j ], &ma [ 1 ][ j ][ i ] );
        }
    }
    for ( i = 0; i <= max_i; i++ )
    {
        for ( j = 0; j <= max_j; j++ )
        {
            ma [ 2 ][ i ][ j ] = 0;
            for ( int k = 0; k <= max_i; k++ ) { ma [ 2 ][ i ][ j ] += ( ma [ 0 ][ i ][ k ] * ma [ 1 ][ k ][ j ] ); }
            x << ma [ 2 ][ i ][ j ] << ' ';
        }
        x << endl;
    }
    x.close( );
    return;
}
void swap_int( int *x, int *y )
{
    int temp = *x;
    *x       = *y;
    *y       = temp;
    return;
}
