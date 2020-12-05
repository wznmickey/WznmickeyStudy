#include "assignment.h"

// ex. 3 function: disptach work to other functions for exercise 3
void ex3( )
{
    char  s [ 1000020 ]; // avoid potential out of memory
    char  w [ 1000020 ]; // avoid potential out of memory
    FILE *x     = fopen( "sentence.txt", "r" );
    FILE *y     = fopen( "word.txt", "r" );
    char *get_1 = fgets( s, 1000010, x );
    char *get_2 = fgets( w, 1000010, y );
    fclose( x );
    fclose( y );
    if ( get_1 == NULL || get_2 == NULL ) { return; }
    int ans     = 0;
    int index_s = 0;
    int index_w = 0;
    int ls      = ( int ) strlen( s );
    int lw      = ( int ) strlen( w );
    for ( int i = 0; i < ls; i++ )
        if ( s [ i ] >= 'A' && s [ i ] <= 'Z' ) s [ i ] = ( char ) ( s [ i ] - 'A' + 'a' );
    for ( int i = 0; i < lw; i++ )
    {
        if ( w [ i ] >= 'A' && w [ i ] <= 'Z' ) w [ i ] = ( char ) ( w [ i ] - 'A' + 'a' );
    }
    if ( ( ls >= 1 ) && ( s [ ls - 1 ] == '\n' ) )
    {
        ls--;
        s [ ls ] = '\0';
    }
    s [ ls ] = ' '; // avoid to compare with none defined data
    ls++;
    s [ ls ] = '\0';
    if ( ( lw >= 1 ) && ( w [ lw - 1 ] == '\n' ) )
    {
        lw--;
        w [ lw ] = '\0';
    }
    for ( index_s = 0; index_s < ls; index_s++ )
    {
        if ( s [ index_s ] != w [ index_w ] )
        {
            while ( ( s [ index_s ] != ' ' ) && ( index_s < ls ) ) { index_s++; }
            index_w = 0;
        }
        else
        {
            if ( ( index_w == lw - 1 ) && ( s [ index_s + 1 ] == ' ' ) )
            {
                ans++;
                index_w = 0;
            }
            else
            {
                index_w++;
            }
        }
    }
    FILE *z = fopen( "count.txt", "w+" );
    fprintf( z, "%d", ans );
    fclose( z );
    return;
}
